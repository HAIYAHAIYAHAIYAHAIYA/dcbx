#include "pldm_monitor.h"
#include "pldm_redfish.h"
#include "pldm_cjson.h"
#include "pldm_bej_resolve.h"
#include "pldm_monitor_event_rbuf.h"
#include "pdr.h"
#include "sha256.h"
#include "main.h"
#include <time.h>
#include  "utlist.h"

static u8 gs_pdrs_buf[PDR_POOL_SIZE];
extern u16 g_event_id;
extern u8 g_dict_info[PLDM_REDFISH_DICT_INFO_LEN];
extern u8 g_anno_dict[PLDM_REDFISH_ANNO_DICT_LEN];
extern u8 g_needed_dict[PLDM_REDFISH_ANNO_DICT_LEN];

pldm_monitor_base_info_t g_pldm_monitor_info;

int is_temp_sensor(u16 sensor_id)
{
    if (sensor_id >= PLDM_BASE_NIC_TEMP_SENSOR_ID && sensor_id <= PLDM_MAX_NIC_TEMP_SENSOR_ID) {
        return NIC_TEMP_SENSOR;
    }
    if (sensor_id >= PLDM_BASE_NC_TEMP_SENSOR_ID && sensor_id <= PLDM_MAX_NC_TEMP_SENSOR_ID) {
        return NC_TEMP_SENSOR;
    }
    if (sensor_id >= PLDM_BASE_PLUG_TEMP_SENSOR_ID && sensor_id <= PLDM_MAX_PLUG_TEMP_SENSOR_ID) {
        return PLUG_TEMP_SENSOR;
    }
    return -1;
}

u8 is_link_speed_sensor(u16 sensor_id)
{
    if (sensor_id >= PLDM_BASE_LINK_SPEED_SENSOR_ID && sensor_id <= PLDM_MAX_LINK_SPEED_SENSOR_ID) {
        return TRUE;
    }
    return FALSE;
}

u8 is_plug_power_comsumption_sensor(u16 sensor_id)
{
    if (sensor_id >= PLDM_BASE_PLUG_POWER_SENSOR_ID && sensor_id <= PLDM_MAX_PLUG_POWER_SENSOR_ID) {
        return TRUE;
    }
    return FALSE;
}

u32 sensor_id_convert_to_record_handle(u16 sensor_id)
{
    u32 record_handle = PLDM_ERR_RECORD_HANDLE;
    u32 max_record_handle = 0;
    if (sensor_id == PLDM_BASE_CARD_COMPOSITE_STATE_SENSOR_ID) {
        record_handle = PLDM_BASE_CARD_COMPOSITE_STATE_SENSOR_HANDLE;
        max_record_handle = PLDM_MAX_CARD_COMPOSITE_STATE_SENSOR_HANDLE;
    } else {
        switch (sensor_id / 10)
        {
            case PLDM_BASE_NIC_TEMP_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_NIC_TEMP_SENSOR_HANDLE + sensor_id - PLDM_BASE_NIC_TEMP_SENSOR_ID;
                max_record_handle = PLDM_MAX_NIC_TEMP_SENSOR_HANDLE;
                break;
            case PLDM_BASE_NC_STATE_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_NC_STATE_SENSOR_HANDLE + sensor_id - PLDM_BASE_NC_STATE_SENSOR_ID;
                max_record_handle = PLDM_MAX_NC_STATE_SENSOR_HANDLE;
                break;
            case PLDM_BASE_LINK_SPEED_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_LINK_SPEED_SENSOR_HANDLE + sensor_id - PLDM_BASE_LINK_SPEED_SENSOR_ID;
                max_record_handle = PLDM_MAX_LINK_SPEED_SENSOR_HANDLE;
                break;
            case PLDM_BASE_LINK_STATE_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_LINK_STATE_SENSOR_HANDLE + sensor_id - PLDM_BASE_LINK_STATE_SENSOR_ID;
                max_record_handle = PLDM_MAX_LINK_STATE_SENSOR_HANDLE;
                break;
            case PLDM_BASE_NC_TEMP_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_NC_TEMP_SENSOR_HANDLE + sensor_id - PLDM_BASE_NC_TEMP_SENSOR_ID;
                max_record_handle = PLDM_MAX_NC_TEMP_SENSOR_HANDLE;
                break;
            case PLDM_BASE_PLUG_POWER_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_PLUG_POWER_SENSOR_HANDLE + sensor_id - PLDM_BASE_PLUG_POWER_SENSOR_ID;
                max_record_handle = PLDM_MAX_PLUG_POWER_SENSOR_HANDLE;
                break;
            case PLDM_BASE_PLUG_TEMP_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_PLUG_TEMP_SENSOR_HANDLE + sensor_id - PLDM_BASE_PLUG_TEMP_SENSOR_ID;
                max_record_handle = PLDM_MAX_PLUG_TEMP_SENSOR_HANDLE;
                break;
            case PLDM_BASE_PLUG_COMPOSITE_SENSOR_ID / 10 :
                record_handle = PLDM_BASE_PLUG_COMPOSITE_SENSOR_HANDLE + sensor_id - PLDM_BASE_PLUG_COMPOSITE_SENSOR_ID;
                max_record_handle = PLDM_MAX_PLUG_COMPOSITE_SENSOR_HANDLE;
                break;
            default :
                break;
        }
    }
    if (record_handle > max_record_handle) {
        record_handle = PLDM_ERR_RECORD_HANDLE;
    }
    return record_handle;
}

static void pldm_monitor_base_info_init(pldm_monitor_base_info_t *pldm_monitor_base_info)
{
    pldm_monitor_base_info->tid = 0;
    pldm_monitor_base_info->phy_addr.val = 0;
    pldm_monitor_base_info->repo_state = PLDM_REPO_AVAILABLE;
    pldm_monitor_base_info->event_receiver_eid = 0x66;
    pldm_monitor_base_info->terminus_mode = PLDM_ENABLE_ASYNC;
    pldm_monitor_base_info->terminus_max_buffersize = PLDM_TERMINUS_DEFAULT_BUFFERSIZE;     /* default size. */
    pldm_monitor_base_info->pldm_event_rbuf = pldm_event_rbuf_init();
    pdrs_pool_init((u32 *)gs_pdrs_buf);
    pldm_pdr_init(&(pldm_monitor_base_info->pldm_repo));
}

void pldm_pool_init(void)
{
    pdrs_pool_init((u32 *)gs_pdrs_buf);
}

void pldm_monitor_printf_pdr_hdr(pldm_pdr_hdr_t *hdr)
{
    LOG("record_handle : %d", hdr->record_handle);
    LOG("version : %d", hdr->version);
    LOG("type : %d", hdr->type);
    LOG("record_change_num : %d", hdr->record_change_num);
    LOG("length : %d", hdr->length);
}

void pldm_monitor_printf_terminus_locator_pdr_detail(u8 *data)
{
    pldm_terminus_locator_pdr_t *ctx = (pldm_terminus_locator_pdr_t *)data;
    pldm_monitor_printf_pdr_hdr(&(ctx->hdr));
    LOG("terminus_handle : %d", ctx->terminus_handle);
    LOG("validity : %d", ctx->validity);
    LOG("tid : %#x", ctx->tid);
    LOG("container_id : %d", ctx->container_id);
    LOG("terminus_locator_type : %d", ctx->terminus_locator_type);
    LOG("terminus_locator_value_size : %d", ctx->terminus_locator_value_size);
    LOG("eid : %#x", ctx->eid);
}

void pldm_monitor_printf_fru_pdr_detail(u8 *data)
{
    pldm_fru_record_set_pdr_t *ctx = (pldm_fru_record_set_pdr_t *)data;
    pldm_monitor_printf_pdr_hdr(&(ctx->hdr));
    LOG("pldm_terminus_handle : %d", ctx->pldm_terminus_handle);
    LOG("fru_record_terminus_identifier : %d", ctx->fru_record_terminus_identifier);
    LOG("entity_type : %#x", ctx->entity_type);
    LOG("entity_instance_num : %d", ctx->entity_instance_num);
    LOG("container_id : %d", ctx->container_id);
}

void pldm_monitor_printf_numeric_pdr_comm_hdr(pldm_numeric_sensor_pdr_comm_part_t *comm_part)
{
    pldm_monitor_printf_pdr_hdr(&(comm_part->hdr));
    LOG("terminus_handle : %d", comm_part->terminus_handle);
    LOG("sensor_id : %d", comm_part->sensor_id);
    LOG("entity_type : %d", comm_part->container.entity_type);
    LOG("entity_instance_num : %d", comm_part->container.entity_instance_num);
    LOG("entity_container_id : %d", comm_part->container.entity_container_id);
    LOG("sensor_init : %d", comm_part->sensor_init);
    LOG("sensor_auxiliary_names_pdr : %d", comm_part->sensor_auxiliary_names_pdr);
    LOG("base_unit : %d", comm_part->base_unit);
    LOG("unit_modifier : %d", comm_part->unit_modifier);
    LOG("rate_unit : %d", comm_part->rate_unit);
    LOG("base_oem_unit_handle : %d", comm_part->base_oem_unit_handle);
    LOG("aux_unit : %d", comm_part->aux_unit);
    LOG("aux_unit_modifier : %d", comm_part->aux_unit_modifier);
    LOG("aux_rate_unit : %d", comm_part->aux_rate_unit);
    LOG("rel : %d", comm_part->rel);
    LOG("aux_oem_unit_handle : %d", comm_part->aux_oem_unit_handle);
    LOG("is_linear : %d", comm_part->is_linear);
    LOG("sensor_data_size : %d", comm_part->sensor_data_size);
    LOG("resolution : %#x", comm_part->resolution);
    LOG("offset : %#x", comm_part->offset);
    LOG("accuracy : %#x", comm_part->accuracy);
    LOG("plus_tolerace : %#x", comm_part->plus_tolerace);
    LOG("minus_tolerance : %#x", comm_part->minus_tolerance);
}

void pldm_monitor_printf_link_data(u8 *data)
{
    pldm_link_speed_sensor_pdr_t *link_pdr = (pldm_link_speed_sensor_pdr_t *)data;
    LOG("hysteresis : %d", link_pdr->hysteresis);
    LOG("supported_thresholds : %d", link_pdr->supported_thresholds);
    LOG("threshold_and_hysteresis_volatility : 0x%x", link_pdr->threshold_and_hysteresis_volatility);
    LOG("state_transition_interval : 0x%x", link_pdr->state_transition_interval.val);
    LOG("update_interval : 0x%x", link_pdr->update_interval.val);
    LOG("max_readable : %d", link_pdr->max_readable);
    LOG("min_readable : %d", link_pdr->min_readable);
    LOG("range_field_format : %d", link_pdr->range_field_format);
    LOG("range_field_support : 0x%x", link_pdr->range_field_support);
    LOG("nominal_value : %d", link_pdr->nominal_value);
    LOG("normal_max : %d", link_pdr->normal_max);
    LOG("normal_min : %d", link_pdr->normal_min);
}

void pldm_monitor_printf_plug_data(u8 *data)
{
    pldm_pluggable_module_power_sensor_pdr_t *plug_pdr = (pldm_pluggable_module_power_sensor_pdr_t *)(data + sizeof(pldm_numeric_sensor_pdr_comm_part_t));
    LOG("hysteresis : %d", plug_pdr->hysteresis);
    LOG("supported_thresholds : %d", plug_pdr->supported_thresholds);
    LOG("threshold_and_hysteresis_volatility : 0x%x", plug_pdr->threshold_and_hysteresis_volatility);
    LOG("state_transition_interval : 0x%x", plug_pdr->state_transition_interval.val);
    LOG("update_interval : 0x%x", plug_pdr->update_interval.val);
    LOG("max_readable : %d", plug_pdr->max_readable);
    LOG("min_readable : %d", plug_pdr->min_readable);
    LOG("range_field_format : %d", plug_pdr->range_field_format);
    LOG("range_field_support : 0x%x", plug_pdr->range_field_support);
    LOG("nominal_value : %d", plug_pdr->nominal_value);
    LOG("normal_max : %d", plug_pdr->normal_max);
    LOG("normal_min : %d", plug_pdr->normal_min);
    LOG("warning_high : %d", plug_pdr->warning_high);
    LOG("warning_low : %d", plug_pdr->warning_low);
    LOG("critical_high : %d", plug_pdr->critical_high);
    LOG("critical_low : %d", plug_pdr->critical_low);
    LOG("fatal_high : %d", plug_pdr->fatal_high);
    LOG("fatal_low : %d", plug_pdr->fatal_low);
}

void pldm_monitor_printf_temp_data(u8 *data)
{
    pldm_thermal_sensor_pdr_t *temp_pdr = (pldm_thermal_sensor_pdr_t *)(data + sizeof(pldm_numeric_sensor_pdr_comm_part_t));
    LOG("hysteresis : %d", temp_pdr->hysteresis);
    LOG("supported_thresholds : %d", temp_pdr->supported_thresholds);
    LOG("threshold_and_hysteresis_volatility : 0x%x", temp_pdr->threshold_and_hysteresis_volatility);
    LOG("state_transition_interval : 0x%x", temp_pdr->state_transition_interval.val);
    LOG("update_interval : 0x%x", temp_pdr->update_interval.val);
    LOG("max_readable : %d", temp_pdr->max_readable);
    LOG("min_readable : %d", temp_pdr->min_readable);
    LOG("range_field_format : %d", temp_pdr->range_field_format);
    LOG("range_field_support : 0x%x", temp_pdr->range_field_support);
    LOG("nominal_value : %d", temp_pdr->nominal_value);
    LOG("normal_max : %d", temp_pdr->normal_max);
    LOG("normal_min : %d", temp_pdr->normal_min);
    LOG("warning_high : %d", temp_pdr->warning_high);
    LOG("warning_low : %d", temp_pdr->warning_low);
    LOG("critical_high : %d", temp_pdr->critical_high);
    LOG("critical_low : %d", temp_pdr->critical_low);
    LOG("fatal_high : %d", temp_pdr->fatal_high);
    LOG("fatal_low : %d", temp_pdr->fatal_low);
}

void pldm_monitor_printf_numeric_pdr_detail(u8 *data)
{
    pldm_numeric_sensor_pdr_comm_part_t *ctx = (pldm_numeric_sensor_pdr_comm_part_t *)data;
    pldm_monitor_printf_numeric_pdr_comm_hdr(ctx);
    u16 sensor_id = ctx->sensor_id;
    if (is_link_speed_sensor(sensor_id)) {
        pldm_monitor_printf_link_data(data);
        LOG("IS_LINK_SPEED_SENSOR");
    } else if (is_plug_power_comsumption_sensor(sensor_id)) {
        pldm_monitor_printf_plug_data(data);
        LOG("IS_PLUG_POWER_COMSUMPTION_SENSOR");
    } else {
        pldm_monitor_printf_temp_data(data);
        LOG("IS_TEMP_SENSOR");
    }

}

void pldm_monitor_printf_state_pdr_detail(u8 *data)
{
    pldm_composite_state_sensor_pdr_t *ctx = (pldm_composite_state_sensor_pdr_t *)data;
    pldm_monitor_printf_pdr_hdr(&(ctx->hdr));
    LOG("terminus_handle : %d", ctx->terminus_handle);
    LOG("sensor_id : %d", ctx->sensor_id);
    LOG("entity_type : %d", ctx->container.entity_type);
    LOG("entity_instance_num : %d", ctx->container.entity_instance_num);
    LOG("entity_container_id : %d", ctx->container.entity_container_id);
    LOG("sensor_init : %d", ctx->sensor_init);
    LOG("sensor_auxi_names_pdr : %d", ctx->sensor_auxi_names_pdr);
    LOG("composite_sensor_cnt : %d", ctx->composite_sensor_cnt);

    for (u8 i = 0; i < ctx->composite_sensor_cnt; i++) {
        LOG("state_setid : %d", ctx->sensors[i].state_setid);
        LOG("possible_states_size : %d", ctx->sensors[i].possible_states_size);
        LOG("possible_states : %d", ctx->sensors[i].possible_states);
    }
}

void pldm_monitor_printf_assoc_pdr_detail(u8 *data)
{
    pldm_pdr_entity_assoc_t *ctx = (pldm_pdr_entity_assoc_t *)data;
    pldm_monitor_printf_pdr_hdr(&(ctx->hdr));
    LOG("container_id : %d", ctx->container_id);
    LOG("assoc_type : %d", ctx->assoc_type);
    LOG("entity_type : %d", ctx->container.entity_type);
    LOG("entity_instance_num : %d", ctx->container.entity_instance_num);
    LOG("entity_container_id : %d", ctx->container.entity_container_id);
    LOG("contained_entity_cnt : %d", ctx->contained_entity_cnt);

    for (u8 i = 0; i < ctx->contained_entity_cnt; i++) {
        LOG("d entity_type : %d", ctx->contained[i].entity_type);
        LOG("d entity_instance_num : %d", ctx->contained[i].entity_instance_num);
        LOG("d entity_container_id : %d", ctx->contained[i].entity_container_id);
    }
}

u8 *pldm_monitor_printf_redfish_resource_pdr_first_part(u8 *data)
{
    if (!data) return NULL;
    pldm_redfish_resource_pdr_first_part_t *first_part = (pldm_redfish_resource_pdr_first_part_t *)data;
    pldm_monitor_printf_pdr_hdr(&(first_part->hdr));
    LOG("resource_id : %d", first_part->resource_id);
    LOG("resource_flg : %d", first_part->resource_flg);
    LOG("containing_resource_id : %d", first_part->containing_resource_id);
    LOG("proposed_containing_resource_byte_len : %d", first_part->proposed_containing_resource_byte_len);
    // for (u16 i = 0; i < first_part->proposed_containing_resource_byte_len; i++) {
    //     printf("%c", first_part->proposed_containing_resource_name[i]);
    // }
    // LOG("");
    LOG("%s", first_part->proposed_containing_resource_name);
    return &(first_part->proposed_containing_resource_name[first_part->proposed_containing_resource_byte_len]);
}

u8 *pldm_monitor_printf_redfish_resource_pdr_middle0_part(u8 *data)
{
    if (!data) return NULL;
    pldm_redfish_resource_pdr_middle0_part_t *middle0_part = (pldm_redfish_resource_pdr_middle0_part_t *)data;
    LOG("suburi_byte_len : %d", middle0_part->suburi_byte_len);

    LOG("%s", middle0_part->suburi);
    return (u8 *)&(middle0_part->suburi[middle0_part->suburi_byte_len]);
}

u8 *pldm_monitor_printf_redfish_resource_pdr_middle1_part(u8 *data)
{
    if (!data) return NULL;
    pldm_redfish_resource_pdr_middle1_part_t *middle1_part = (pldm_redfish_resource_pdr_middle1_part_t *)data;
    LOG("add_resource_id_cnt : %d", middle1_part->add_resource_id_cnt);
    pldm_redfish_add_resource_info_t *resource_info = (pldm_redfish_add_resource_info_t *)(middle1_part->add_resource_info);

    for (u16 i = 0; i < middle1_part->add_resource_id_cnt; i++) {
        LOG("add_resource_id : %d", resource_info->add_resource_id);
        LOG("add_suburi_byte_len : %d", resource_info->add_suburi_byte_len);
        LOG("add_suburi : %s", resource_info->add_suburi);
        resource_info = (pldm_redfish_add_resource_info_t *)&(resource_info->add_suburi[resource_info->add_suburi_byte_len]);
    }
    return (u8 *)resource_info;
}

u8 *pldm_monitor_printf_redfish_resource_pdr_middle2_part(u8 *data)
{
    if (!data) return NULL;
    pldm_redfish_resource_pdr_middle2_part_t *middle2 = (pldm_redfish_resource_pdr_middle2_part_t *)data;
    LOG("major_schema_ver : 0x%x", middle2->major_schema_ver);
    LOG("major_schema_dict_byte_len : %d", middle2->major_schema_dict_byte_len);
    LOG("major_schema_dict_sign : 0x%x", middle2->major_schema_dict_sign);
    LOG("major_schema_name_len : %d", middle2->major_schema_name_len);
    LOG("major_schema_name : %s", middle2->major_schema_name);
    return &(middle2->major_schema_name[middle2->major_schema_name_len]);
}

u8 *pldm_monitor_printf_redfish_resource_pdr_end_part(u8 *data)
{
    if (!data) return NULL;
    pldm_redfish_resource_pdr_end_part_t *end_part = (pldm_redfish_resource_pdr_end_part_t *)data;
    LOG("oem_cnt : %d", end_part->oem_cnt);
}

void pldm_monitor_printf_redfish_resource_pdr_detail(u8 *data)
{
    u8 *next_part = pldm_monitor_printf_redfish_resource_pdr_first_part(data);
    next_part = pldm_monitor_printf_redfish_resource_pdr_middle0_part(next_part);
    next_part = pldm_monitor_printf_redfish_resource_pdr_middle1_part(next_part);
    next_part = pldm_monitor_printf_redfish_resource_pdr_middle2_part(next_part);
    next_part = pldm_monitor_printf_redfish_resource_pdr_end_part(next_part);
}

void pldm_monitor_printf_pdr(pldm_pdr_record_t *pdr)
{
    if (!pdr || !pdr->data) return;
    pldm_pdr_hdr_t *hdr = (pldm_pdr_hdr_t *)(pdr->data);
    switch (hdr->type) {
        case TERMINUS_LOCATOR_PDR:
            LOG("%s", TO_STR(TERMINUS_LOCATOR_PDR));
            // pldm_monitor_printf_terminus_locator_pdr_detail(pdr->data);
            break;
        case NUMERIC_SENSOR_PDR:
            LOG("%s", TO_STR(NUMERIC_SENSOR_PDR));
            // pldm_monitor_printf_numeric_pdr_detail(pdr->data);
            break;
        case STATE_SENSOR_PDR:
            LOG("%s", TO_STR(STATE_SENSOR_PDR));
            // pldm_monitor_printf_state_pdr_detail(pdr->data);
            break;
        case ENTITY_ASSOC_PDR:
            LOG("%s", TO_STR(ENTITY_ASSOC_PDR));
            // pldm_monitor_printf_assoc_pdr_detail(pdr->data);
            break;
        case FRU_RECORD_SET_PDR:
            LOG("%s", TO_STR(FRU_RECORD_SET_PDR));
            // pldm_monitor_printf_fru_pdr_detail(pdr->data);
            break;
        case REDFISH_RESOURCE_PDR:
            LOG("%s", TO_STR(REDFISH_RESOURCE_PDR));
            // pldm_monitor_printf_redfish_resource_pdr_detail(pdr->data);
            break;
        case REDFISH_ACTION_PDR:
            LOG("%s", TO_STR(REDFISH_ACTION_PDR));
            break;
    }
}

void pldm_monitor_printf_repo(pldm_pdr_t *repo)
{
    LOG("record_count : %d", repo->record_count);
    LOG("size : %d", repo->size);
    char *str = "2019-05-04-18";
    cm_memcpy(&(repo->update_time), str, 13);
    LOG("largest pdr size : %d", repo->largest_pdr_size);
    LOG("time : %s", __TIME__);
    LOG("update_time : %s", &(repo->update_time));
    LOG("repo_signature : 0x%x", repo->repo_signature);
    u16 sum_size = 0;
    u8 cnt = 0;
    pldm_pdr_record_t *pdr = NULL;
#if MY_LIST
    pdr = repo->first;
#else
    pdr = repo->head;
#endif
    repo->repo_signature = 0;
    while (pdr) {
        cnt++;
        pldm_pdr_hdr_t *hdr = (pldm_pdr_hdr_t *)(pdr->data);
        LOG("pdr size : %04d, record handle : %04d, type : %d", pdr->size, pdr->record_handle, hdr->type);
        pldm_monitor_printf_pdr(pdr);
        repo->repo_signature = crc32_pldm_1(repo->repo_signature ^ 0xFFFFFFFFUL, pdr->data, pdr->size);
        sum_size += pdr->size;
        pdr = pdr->next;
    }
    LOG("sum size : %d, cnt : %d, signature : %#x", sum_size, cnt, repo->repo_signature);
    pldm_pdr_record_t *delete_pdr = NULL;
#if MY_LIST
    delete_pdr = repo->is_deleted;
#else
    delete_pdr = repo->is_deleted_head;
#endif
    while (delete_pdr) {
        LOG("deleted pdr size : %d, record handle : %d", delete_pdr->size, delete_pdr->record_handle);
        delete_pdr = delete_pdr->next;
    }
}

void pldm_monitor_printf_sensor_detail(u8 *ev_data)
{
    LOG("start %s", __FUNCTION__);
    LOG("sensor class : %s", TO_STR(PLDM_SENSOR_OP_STATE));
    pldm_field_per_sensor_op_state_format_t *sensor_dat = (pldm_field_per_sensor_op_state_format_t *)ev_data;
    LOG("present_op_state : %d", sensor_dat->present_op_state);
    LOG("previous_op_state : %d", sensor_dat->previous_op_state);
    LOG("end %s", __FUNCTION__);
}

void pldm_monitor_printf_state_sensor_detail(u8 *ev_data)
{
    LOG("start %s", __FUNCTION__);
    LOG("sensor class : %s", TO_STR(PLDM_STATE_SENSOR_STATE));
    pldm_field_per_state_sensor_state_format_t *sensor_dat = (pldm_field_per_state_sensor_state_format_t *)ev_data;
    LOG("event_state : %d", sensor_dat->event_state);
    LOG("previous_event_state : %d", sensor_dat->previous_event_state);
    LOG("sensor_offset : %d", sensor_dat->sensor_offset);
    LOG("end %s", __FUNCTION__);
}

void pldm_monitor_printf_numeric_sensor_detail(u8 *ev_data)
{
    LOG("start %s", __FUNCTION__);
    LOG("sensor class : %s", TO_STR(PLDM_NUMERIC_SENSOR_STATE));
    pldm_field_per_numeric_sensor_state_format_t *sensor_dat = (pldm_field_per_numeric_sensor_state_format_t *)ev_data;
    LOG("event_state : %d", sensor_dat->event_state);
    LOG("previous_event_state : %d", sensor_dat->previous_event_state);
    u8 len = sensor_dat->sensor_datasize == PLDM_DATASIZE_UINT8 ? 1 : 4;
    u32 read_data = 0;
    cm_memcpy(&read_data, sensor_dat->present_reading, len);
    LOG("present_reading : 0x%x", read_data);
    LOG("sensor_datasize : %d", sensor_dat->sensor_datasize);
    LOG("end %s", __FUNCTION__);
}

void pldm_monitor_printf_sensor_event(u8 *data)
{
    pldm_sensor_event_class_event_data_format_t *sensor_event = (pldm_sensor_event_class_event_data_format_t *)data;
    LOG("\nsensor id : %d", sensor_event->sensor_id);
    switch (sensor_event->sensor_event_class) {
        case PLDM_SENSOR_OP_STATE:
            pldm_monitor_printf_sensor_detail(sensor_event->field_per_event_class);
            break;
        case PLDM_STATE_SENSOR_STATE:
            pldm_monitor_printf_state_sensor_detail(sensor_event->field_per_event_class);
            break;
        case PLDM_NUMERIC_SENSOR_STATE:
            pldm_monitor_printf_numeric_sensor_detail(sensor_event->field_per_event_class);
            break;
        default :
            LOG("err sensor_event_class!\n");
            break;
    }
}

void pldm_monitor_printf_repo_chg_event(u8 *data)
{
    LOG("\nstart %s", __FUNCTION__);
    pldm_pdr_repo_chg_event_data_format_t *pdr_chg_dat = (pldm_pdr_repo_chg_event_data_format_t *)data;
    LOG("event_data_format %d", pdr_chg_dat->event_data_format);
    LOG("num_of_chg_records %d", pdr_chg_dat->num_of_chg_records);
    for (u8 i = 0; i < pdr_chg_dat->num_of_chg_records; i++) {
        LOG("chg_entry %d", pdr_chg_dat->chg_record[i].chg_entry[0]);
        LOG("event_data_op %d", pdr_chg_dat->chg_record[i].event_data_op);
        LOG("num_of_chg_entries %d", pdr_chg_dat->chg_record[i].num_of_chg_entries);
    }
    LOG("end %s", __FUNCTION__);
}

void pldm_monitor_printf_repo_redfish_event(u8 *data)
{
    pldm_cjson_t *root = NULL;
    pldm_redfish_msg_event_data_format_t *event_data = (pldm_redfish_msg_event_data_format_t *)data;

    u8 *anno_dict = &g_anno_dict[DICT_FMT_HDR_LEN];
    u8 *dict = &g_needed_dict[DICT_FMT_HDR_LEN];

    u8 ret = pldm_redfish_get_dict_data(PLDM_BASE_EVENT_DICT_RESOURCE_ID, SCHEMACLASS_EVENT, g_needed_dict, PLDM_REDFISH_EVENT_DICT_LEN);
    if (ret == false) return;
    LOG("bej_len : %d", event_data->event_data_len - sizeof(bejencoding_t));
    u8 *bej_data = (((u8 *)&(event_data->id_and_severity[1])) + sizeof(bejencoding_t));
    // for (u16 i = 0; i < event_data->event_data_len - sizeof(bejencoding_t); i++) {
    //     printf("0x%02x, ", bej_data[i]);
    //     if (!((i + 1) % 8)) {
    //         printf("\n");
    //     }
    // }
    root = pldm_bej_decode(bej_data, event_data->event_data_len - sizeof(bejencoding_t), anno_dict, dict, root, 1);
    // pldm_cjson_printf_root2(root);
    pldm_cjson_pool_reinit();
}

void pldm_monitor_printf_event_rbuf(void *p)
{
    u16 event_cnt = g_event_id;
    u8 event_data_info[sizeof(pldm_event_data_t)] = {0};
    u8 payload[256];
    u16 sum_size = 0;
    while (!pldm_event_rbuf_is_empty(p)) {
        pldm_event_rbuf_try_read(p, event_data_info, sizeof(pldm_event_data_t), 0);
        pldm_event_data_t *pldm_event_data = (pldm_event_data_t *)event_data_info;                       /* the oldest event */
        // u8 event_cnt = g_event_id - pldm_event_data->event_id;
        LOG("event id : %02d, class : %02d, size : %d", pldm_event_data->event_id, pldm_event_data->event_class, pldm_event_data->event_data_size);
        pldm_event_rbuf_try_read(p, payload, pldm_event_data->event_data_size, sizeof(pldm_event_data_t));
        sum_size += pldm_event_data->event_data_size + sizeof(pldm_event_data_t);
        switch (pldm_event_data->event_class) {
            case SENSOR_EVENT:
                // pldm_monitor_printf_sensor_event(payload);
                break;
            case PLDM_PDR_REPO_CHG_EVENT:
                // pldm_monitor_printf_repo_chg_event(payload);
                break;
            case REDFISH_MSG_EVENT:
                // pldm_monitor_printf_repo_redfish_event(payload);
                break;
            default :
                LOG("err class : %d", pldm_event_data->event_class);
                break;
        }
        pldm_event_rbuf_read_done(p);
    }
    g_event_id = 1;
    LOG("event cnt : %d, sum_size : %d", event_cnt, sum_size);
    sum_size = 0;
}

void pldm_monitor_update_repo_signature(pldm_pdr_t *repo)
{
    if (!repo) return;
    pldm_pdr_record_t *pdr = NULL;
    pdr = repo->head;
    repo->repo_signature = 0;
    while (pdr) {
        if (pdr->data)
            repo->repo_signature = crc32_pldm_1(repo->repo_signature ^ 0xFFFFFFFFUL, pdr->data, pdr->size);
        pdr = pdr->next;
    }
}

void pldm_monitor_init(void)
{
    pldm_monitor_base_info_init(&g_pldm_monitor_info);
    pldm_cjson_pool_init();
    CM_FLASH_READ("./build/truncated_pldm_redfish_dicts.bin", PLDM_REDFISH_DICT_BASE_ADDR, (u32 *)g_dict_info, PLDM_REDFISH_DICT_INFO_LEN / sizeof(u32));
    pldm_redfish_get_dict_data(PLDM_BASE_ANNOTATION_DICT_RESOURCE_ID, SCHEMACLASS_ANNOTATION, g_anno_dict, sizeof(g_anno_dict));
}

typedef void (*pdr_init_func)(void);

void pldm_monitor_gen_static_pdr_data(pldm_pdr_t *repo)
{
    pldm_pdr_record_t *pdr = NULL;
    FILE *fp = NULL;
    u16 sum_size = 0;
    u8 cnt = 0;
    fp = fopen("static_pdr_resource.bin", "w+");
    fseek(fp, sizeof(u16) + sizeof(u8), SEEK_SET);
    #if MY_LIST
    pdr = repo->first;
#else
    pdr = repo->head;
#endif
    while (pdr) {
        cnt++;
        fwrite(pdr->data, pdr->size, sizeof(u8), fp);
        sum_size += pdr->size;
        pdr = pdr->next;
    }
    LOG("sum size : %d, %d", sum_size, cnt);
    fseek(fp, 0, SEEK_SET);
    fwrite(&sum_size, sizeof(u16), sizeof(u8), fp);
    fwrite(&cnt, sizeof(u8), sizeof(u8), fp);
    fclose(fp);
}

void pldm_monitor_create_static_pdr(pldm_pdr_t *repo)
{
    pldm_pdr_record_t *pdr = NULL;
    FILE *fp = NULL;
    fp = fopen("static_pdr_resource.bin", "r+");
    u16 sum_size = 0;
    u8 cnt = 0;
    fread(&sum_size, sizeof(u16), sizeof(u8), fp);
    fread(&cnt, sizeof(u8), sizeof(u8), fp);
    LOG("sum size : %d, %d", sum_size, cnt);
    fclose(fp);
}

void pldm_monitor_test(void)
{
    pldm_monitor_init();
    double start,end,cost;

    pdr_init_func pdr_init[] = {
        pldm_terminus_locator_pdr_init,
        pldm_assoc_pdr_init,
        pldm_numeric_sensor_pdr_init,
        pldm_state_sensor_pdr_init,
        pldm_redfish_pdr_init,
        pldm_fru_pdr_init,
    };
    start = clock();
    for (u8 i = 0; i < sizeof(pdr_init) / sizeof(pdr_init_func); i++) {
        pdr_init[i]();
        // pldm_pdr_get_used();
    }
    for (u8 i = 0; i < 2; i++) {
        pldm_link_handle(i, 1);
    }

    LOG("\nORI REPO");
    pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));
    pldm_pdr_get_used();
    // LOG("\nRD REPO");
    // pldm_monitor_gen_static_pdr_data(&(g_pldm_monitor_info.pldm_repo));
    // pdrs_pool_reinit();
    // pldm_monitor_create_static_pdr(&(g_pldm_monitor_info.pldm_repo));

    // g_pldm_monitor_info.terminus_mode = PLDM_ENABLE_ASYNC;
    // for (u32 j = 0; j < 5; j++) {
    //     for (u8 i = 0; i < MAX_LAN_NUM; i++) {
    //         pldm_link_handle(i, 1);
    //         // pldm_pdr_get_used();
    //     }
    //     // LOG("g_event_id : %d", g_event_id);
    //     for (u8 i = 0; i < MAX_LAN_NUM; i++) {
    //         pldm_link_handle(i, 0);
    //         // pldm_pdr_get_used();
    //     }
    //     // LOG("g_event_id : %d", g_event_id);
    // }
    end = clock();
    cost = end - start;
    LOG("time diff %f",cost);   /* uint is ms */

    // pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));

    // pldm_pdr_record_t *del_elt = NULL;

    // LL_FOREACH(g_pldm_monitor_info.pldm_repo.head, del_elt) {
    //     pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), del_elt->record_handle);
    //     del_elt = g_pldm_monitor_info.pldm_repo.head;
    // }
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 2);

    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 1);
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 3);
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 2);
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 4400);
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 4200);
    // pldm_pdr_delete(&(g_pldm_monitor_info.pldm_repo), 4300);

    // pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));

    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 2);
    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 4400);
    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 4200);
    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 4300);
    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 1);
    // pldm_pdr_is_exist(&(g_pldm_monitor_info.pldm_repo), 3);

    // pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));
    // LOG("last : %d", g_pldm_monitor_info.pldm_repo.last->record_handle);
    // LOG("first : %d", g_pldm_monitor_info.pldm_repo.first->record_handle);
    // pldm_monitor_printf_event_rbuf(g_pldm_monitor_info.pldm_event_rbuf);
    // SENSOR_EVENT = 0x00,
    // REDFISH_TASK_EXCUTE_EVENT = 0x02,
    // REDFISH_MSG_EVENT = 0x03,
    // PLDM_PDR_REPO_CHG_EVENT = 0x04,
    // PLDM_MSG_POLL_EVENT = 0x05
}