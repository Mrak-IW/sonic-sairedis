#include "sai_redis.h"

/**
 * Routine Description:
 *    @brief Create tunnel map
 *
 * Arguments:
 *    @param[out] tunnel_map_id - tunnel map id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_create_tunnel_map(
        _Out_ sai_object_id_t* tunnel_map_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP,
            tunnel_map_id,
            switch_id,
            attr_count,
            attr_list,
            &redis_generic_create);
}

/**
 * Routine Description:
 *    @brief Remove tunnel map
 *
 * Arguments:
 *    @param[out] tunnel_map_id - tunnel map id
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_remove_tunnel_map(
        _In_ sai_object_id_t tunnel_map_id)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP,
            tunnel_map_id,
            &redis_generic_remove);
}

/**
 * Routine Description:
 *    @brief Set tunnel map attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_map_id - tunnel map id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_set_tunnel_map_attribute(
        _In_ sai_object_id_t tunnel_map_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP,
            tunnel_map_id,
            attr,
            &redis_generic_set);
}

/**
 * Routine Description:
 *    @brief Get tunnel map attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_map_id - tunnel map id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_get_tunnel_map_attribute(
        _In_ sai_object_id_t   tunnel_map_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP,
            tunnel_map_id,
            attr_count,
            attr_list,
            &redis_generic_get);
}

/**
 * Routine Description:
 *    @brief Create tunnel
 *
 * Arguments:
 *    @param[out] tunnel_id - tunnel id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_create_tunnel(
        _Out_ sai_object_id_t* tunnel_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_TUNNEL,
            tunnel_id,
            switch_id,
            attr_count,
            attr_list,
            &redis_generic_create);
}

/**
 * Routine Description:
 *    @brief Remove tunnel
 *
 * Arguments:
 *    @param[out] tunnel_id - tunnel map
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_remove_tunnel(
        _In_ sai_object_id_t tunnel_id)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_TUNNEL,
            tunnel_id,
            &redis_generic_remove);
}

/**
 * Routine Description:
 *    @brief Set tunnel attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_id - tunnel id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_set_tunnel_attribute(
        _In_ sai_object_id_t tunnel_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_TUNNEL,
            tunnel_id,
            attr,
            &redis_generic_set);
}

/**
 * Routine Description:
 *    @brief Get tunnel attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_id - tunnel id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_get_tunnel_attribute(
        _In_ sai_object_id_t tunnel_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_TUNNEL,
            tunnel_id,
            attr_count,
            attr_list,
            &redis_generic_get);
}

/**
 * Routine Description:
 *    @brief Create tunnel term table
 *
 * Arguments:
 *    @param[out] tunnel_term_table_entry_id - tunnel term table entry id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_create_tunnel_term_table_entry (
        _Out_ sai_object_id_t* tunnel_term_table_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY,
            tunnel_term_table_entry_id,
            switch_id,
            attr_count,
            attr_list,
            &redis_generic_create);
}

/**
 * Routine Description:
 *    @brief Remove tunnel term table
 *
 * Arguments:
 *    @param[out] tunnel_term_table_entry_id - tunnel term table entry id
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 *
 */
sai_status_t redis_remove_tunnel_term_table_entry (
        _In_ sai_object_id_t tunnel_term_table_entry_id)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY,
            tunnel_term_table_entry_id,
            &redis_generic_remove);
}

/**
 * Routine Description:
 *    @brief Set tunnel term table attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_term_table_entry_id, - tunnel term table id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_set_tunnel_term_table_entry_attribute(
        _In_ sai_object_id_t tunnel_term_table_entry_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY,
            tunnel_term_table_entry_id,
            attr,
            &redis_generic_set);
}

/**
 * Routine Description:
 *    @brief Get tunnel term table attribute Value
 *
 * Arguments:
 *    @param[in] tunnel_term_table_entry_id, - tunnel term table id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @return SAI_STATUS_SUCCESS on success
 *            Failure status code on error
 */
sai_status_t redis_get_tunnel_term_table_entry_attribute(
        _In_ sai_object_id_t tunnel_term_table_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_TUNNEL_TERM_TABLE_ENTRY,
            tunnel_term_table_entry_id,
            attr_count,
            attr_list,
            &redis_generic_get);
}

/**
 * @brief Create tunnel map item
 *
 * @param[out] tunnel_map_entry_id Tunnel map item id
 * @param[in] switch_id Switch Id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t redis_create_tunnel_map_entry(
        _Out_ sai_object_id_t *tunnel_map_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_create_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY,
            tunnel_map_entry_id,
            switch_id,
            attr_count,
            attr_list,
            &redis_generic_create);
}

/**
 * @brief Remove tunnel map item
 *
 * @param[in] tunnel_map_entry_id Tunnel map item id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t redis_remove_tunnel_map_entry(
        _In_ sai_object_id_t tunnel_map_entry_id)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_remove_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY,
            tunnel_map_entry_id,
            &redis_generic_remove);
}

/**
 * @brief Set tunnel map item attribute
 *
 * @param[in] tunnel_map_entry_id Tunnel map item id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t redis_set_tunnel_map_entry_attribute(
        _In_ sai_object_id_t tunnel_map_entry_id,
        _In_ const sai_attribute_t *attr)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_set_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY,
            tunnel_map_entry_id,
            attr,
            &redis_generic_set);
}

/**
 * @brief Get tunnel map item attributes
 *
 * @param[in] tunnel_map_entry_id Tunnel map item id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t redis_get_tunnel_map_entry_attribute(
        _In_ sai_object_id_t tunnel_map_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    std::lock_guard<std::mutex> lock(g_apimutex);

    SWSS_LOG_ENTER();

    return meta_sai_get_oid(
            SAI_OBJECT_TYPE_TUNNEL_MAP_ENTRY,
            tunnel_map_entry_id,
            attr_count,
            attr_list,
            &redis_generic_get);
}

/**
 * @brief tunnel table methods, retrieved via sai_api_query()
 */
const sai_tunnel_api_t redis_tunnel_api = {
    redis_create_tunnel_map,
    redis_remove_tunnel_map,
    redis_set_tunnel_map_attribute,
    redis_get_tunnel_map_attribute,
    redis_create_tunnel,
    redis_remove_tunnel,
    redis_set_tunnel_attribute,
    redis_get_tunnel_attribute,
    redis_create_tunnel_term_table_entry,
    redis_remove_tunnel_term_table_entry,
    redis_set_tunnel_term_table_entry_attribute,
    redis_get_tunnel_term_table_entry_attribute,
    redis_create_tunnel_map_entry,
    redis_remove_tunnel_map_entry,
    redis_set_tunnel_map_entry_attribute,
    redis_get_tunnel_map_entry_attribute,
};
