#ifndef __SYNCD_H__
#define __SYNCD_H__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <mutex>
#include <thread>
#include <set>

#include <unistd.h>
#include <execinfo.h>
#include <signal.h>
#include <getopt.h>

#ifdef SAITHRIFT
#include <utility>
#include <algorithm>
#include <switch_sai_rpc_server.h>
#endif // SAITHRIFT

#include "string.h"
extern "C" {
#include "sai.h"
}

#include "meta/saiserialize.h"
#include "meta/saiattributelist.h"
#include "swss/redisclient.h"
#include "swss/dbconnector.h"
#include "swss/producertable.h"
#include "swss/consumertable.h"
#include "swss/notificationconsumer.h"
#include "swss/notificationproducer.h"
#include "swss/selectableevent.h"
#include "swss/select.h"
#include "swss/logger.h"
#include "swss/table.h"

#define UNREFERENCED_PARAMETER(X)

#define DEFAULT_VLAN_NUMBER         1

#define VIDTORID                    "VIDTORID"
#define RIDTOVID                    "RIDTOVID"
#define VIDCOUNTER                  "VIDCOUNTER"
#define LANES                       "LANES"
#define HIDDEN                      "HIDDEN"
#define DEFAULT_VIRTUAL_ROUTER_ID   "DEFAULT_VIRTUAL_ROUTER_ID"
#define DEFAULT_TRAP_GROUP_ID       "DEFAULT_TRAP_GROUP_ID"
#define DEFAULT_STP_INSTANCE_ID     "DEFAULT_STP_INSTANCE_ID"
#define CPU_PORT_ID                 "CPU_PORT_ID"

#define SAI_COLD_BOOT               0
#define SAI_WARM_BOOT               1
#define SAI_FAST_BOOT               2

#ifdef SAITHRIFT
#define SWITCH_SAI_THRIFT_RPC_SERVER_PORT 9092
#endif // SAITHRIFT

extern void exit_and_notify(int status) __attribute__ ((__noreturn__));

extern std::mutex g_mutex;
extern std::set<sai_object_id_t> g_defaultPriorityGroupsRids;
extern std::set<sai_object_id_t> g_defaultSchedulerGroupsRids;
extern std::set<sai_object_id_t> g_defaultQueuesRids;
extern std::set<sai_object_id_t> g_defaultPortsRids;

void onSyncdStart(bool warmStart);
void hardReinit();

sai_object_id_t replaceVidToRid(const sai_object_id_t &virtual_object_id);
std::unordered_map<sai_object_id_t, sai_object_id_t> redisGetVidToRidMap();
std::unordered_map<sai_object_id_t, sai_object_id_t> redisGetRidToVidMap();
std::vector<std::string> redisGetAsicStateKeys();
sai_object_id_t redisGetDefaultVirtualRouterId();
sai_object_id_t redisGetDefaultTrapGroupId();
sai_object_id_t redisGetDefaultStpInstanceId();
sai_object_id_t redisGetCpuId();
void redisClearVidToRidMap();
void redisClearRidToVidMap();

extern swss::ProducerTable         *getResponse;
extern swss::NotificationProducer  *notifications;

extern swss::RedisClient   *g_redisClient;

sai_object_id_t redis_create_virtual_object_id(
        _In_ sai_object_type_t object_type);

sai_object_id_t translate_rid_to_vid(
        _In_ sai_object_id_t rid);

void translate_rid_to_vid_list(
        _In_ sai_object_type_t object_type,
        _In_ uint32_t attr_count,
        _In_ sai_attribute_t *attr_list);

typedef sai_status_t (*create_fn)(
        _Out_ sai_object_id_t *stp_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*remove_fn)(
        _In_ sai_object_id_t stp_id);

typedef sai_status_t (*set_attribute_fn)(
        _In_ sai_object_id_t object_id,
        _In_ const sai_attribute_t *attr);

typedef sai_status_t (*get_attribute_fn)(
        _In_ sai_object_id_t stp_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

extern create_fn           common_create[SAI_OBJECT_TYPE_MAX];
extern remove_fn           common_remove[SAI_OBJECT_TYPE_MAX];
extern set_attribute_fn    common_set_attribute[SAI_OBJECT_TYPE_MAX];
extern get_attribute_fn    common_get_attribute[SAI_OBJECT_TYPE_MAX];

extern sai_acl_api_t                *sai_acl_api;
extern sai_buffer_api_t             *sai_buffer_api;
extern sai_fdb_api_t                *sai_fdb_api;
extern sai_hash_api_t               *sai_hash_api;
extern sai_hostif_api_t             *sai_hostif_api;
extern sai_lag_api_t                *sai_lag_api;
extern sai_mirror_api_t             *sai_mirror_api;
extern sai_neighbor_api_t           *sai_neighbor_api;
extern sai_next_hop_api_t           *sai_next_hop_api;
extern sai_next_hop_group_api_t     *sai_next_hop_group_api;
extern sai_policer_api_t            *sai_policer_api;
extern sai_port_api_t               *sai_port_api;
extern sai_qos_map_api_t            *sai_qos_map_api;
extern sai_queue_api_t              *sai_queue_api;
extern sai_route_api_t              *sai_route_api;
extern sai_router_interface_api_t   *sai_router_interface_api;
extern sai_samplepacket_api_t       *sai_samplepacket_api;
extern sai_scheduler_api_t          *sai_scheduler_api;
extern sai_scheduler_group_api_t    *sai_scheduler_group_api;
extern sai_stp_api_t                *sai_stp_api;
extern sai_switch_api_t             *sai_switch_api;
extern sai_tunnel_api_t             *sai_tunnel_api;
extern sai_udf_api_t                *sai_udf_api;
extern sai_virtual_router_api_t     *sai_router_api;
extern sai_vlan_api_t               *sai_vlan_api;
extern sai_wred_api_t               *sai_wred_api;

void initialize_common_api_pointers();
void populate_sai_apis();

void startCountersThread(int intervalInSeconds);
void endCountersThread();

std::unordered_map<sai_uint32_t, sai_object_id_t> redisGetLaneMap();

std::vector<sai_object_id_t> saiGetPortList();

sai_object_type_t getObjectTypeFromVid(sai_object_id_t sai_object_id);

void start_cli();
void stop_cli();

sai_status_t applyViewTransition();
sai_status_t syncdApplyView();

void check_notifications_pointers(
        _In_ uint32_t attr_count,
        _In_ sai_attribute_t *attr_list);

#endif // __SYNCD_H__
