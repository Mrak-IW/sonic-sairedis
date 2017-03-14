#include "sai_vs.h"
#include "sai_vs_state.h"

ObjectHash g_objectHash;

uint64_t real_ids[SAI_OBJECT_TYPE_MAX];

void reset_id_counter()
{
    SWSS_LOG_ENTER();

    memset(real_ids, 0, sizeof(real_ids));
}

// TODO support switch_id

sai_object_id_t vs_create_real_object_id(
        _In_ sai_object_type_t object_type)
{
    SWSS_LOG_ENTER();

    if (object_type <= SAI_OBJECT_TYPE_NULL ||
        object_type >= SAI_OBJECT_TYPE_MAX)
    {
        SWSS_LOG_ERROR("invalid object type %d for createing real id", object_type);

        return SAI_NULL_OBJECT_ID;
    }

    // count from zero for each type separetly
    uint64_t real_id = real_ids[object_type]++;

    sai_object_id_t object_id = (((sai_object_id_t)object_type) << 32) | real_id;

    SWSS_LOG_DEBUG("created RID 0x%lx", object_id);

    return object_id;
}

sai_object_type_t sai_object_type_query(
        _In_ sai_object_id_t object_id)
{
    sai_object_type_t object_type = (sai_object_type_t)(object_id >> 32);

    if (object_type <= SAI_OBJECT_TYPE_NULL ||
        object_type >= SAI_OBJECT_TYPE_MAX)
    {
        SWSS_LOG_ERROR("invalid object type %d for createing real id", object_type);

        return SAI_OBJECT_TYPE_NULL;
    }

    return object_type;
}

sai_status_t internal_vs_generic_create(
        _In_ sai_object_type_t object_type,
        _In_ const std::string &serialized_object_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    auto it = g_objectHash.find(serialized_object_id);

    if (it != g_objectHash.end())
    {
        SWSS_LOG_ERROR("Create failed, object already exists, object type: %d: id: %s", object_type, serialized_object_id.c_str());

        return SAI_STATUS_ITEM_ALREADY_EXISTS;
    }

    std::vector<swss::FieldValueTuple> values = SaiAttributeList::serialize_attr_list(
            object_type,
            attr_count,
            attr_list,
            false);

    // we can have multiple attributes when creating object, we need to set each one
    // in hash per object, since get can request multiple attributes

    AttrHash attrHash;

    for (uint32_t i = 0; i < attr_count; ++i)
    {
        const std::string &str_attr_id = fvField(values[i]);
        const std::string &str_attr_value = fvValue(values[i]);

        attrHash[str_attr_id] = str_attr_value;
    }

    g_objectHash[serialized_object_id] = attrHash; // set attributes to object id

    SWSS_LOG_DEBUG("Create succeeded, object type: %d, id: %s", object_type, serialized_object_id.c_str());

    return SAI_STATUS_SUCCESS;
}

sai_status_t vs_generic_create(
        _In_ sai_object_type_t object_type,
        _Out_ sai_object_id_t* object_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    // TODO support switch_id

    // create new real object ID
    *object_id = vs_create_real_object_id(object_type);

    std::string str_object_id = sai_serialize_object_id(*object_id);

    return internal_vs_generic_create(
            object_type,
            str_object_id,
            attr_count,
            attr_list);
}

sai_status_t vs_generic_create_fdb_entry(
        _In_ const sai_fdb_entry_t *fdb_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    std::string str_fdb_entry = sai_serialize_fdb_entry(*fdb_entry);

    return internal_vs_generic_create(
            SAI_OBJECT_TYPE_FDB_ENTRY,
            str_fdb_entry,
            attr_count,
            attr_list);
}

sai_status_t vs_generic_create_neighbor_entry(
        _In_ const sai_neighbor_entry_t* neighbor_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    std::string str_neighbor_entry = sai_serialize_neighbor_entry(*neighbor_entry);

    return internal_vs_generic_create(
            SAI_OBJECT_TYPE_NEIGHBOR_ENTRY,
            str_neighbor_entry,
            attr_count,
            attr_list);
}

sai_status_t vs_generic_create_route_entry(
        _In_ const sai_route_entry_t* route_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    std::string str_route_entry = sai_serialize_route_entry(*route_entry);

    return internal_vs_generic_create(
            SAI_OBJECT_TYPE_ROUTE_ENTRY,
            str_route_entry,
            attr_count,
            attr_list);
}
