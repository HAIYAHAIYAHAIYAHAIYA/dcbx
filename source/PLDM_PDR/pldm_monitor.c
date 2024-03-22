#include "pldm_monitor.h"
#include "pldm_monitor_event_rbuf.h"
#include "pdr.h"
#include "main.h"

static u8 gs_pdrs_buf[PDR_POOL_SIZE];
extern u16 g_event_id;

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
    pldm_monitor_base_info->event_receiver_eid = 0;
    pldm_monitor_base_info->terminus_mode = PLDM_DISABLE;
    pldm_monitor_base_info->terminus_max_buffersize = PLDM_TERMINUS_DEFAULT_BUFFERSIZE;     /* default size. */
    pldm_monitor_base_info->pldm_event_rbuf = pldm_event_rbuf_init();
    pdrs_pool_init((u32 *)gs_pdrs_buf);
    pldm_pdr_init(&(pldm_monitor_base_info->pldm_repo));
}

void pldm_monitor_printf_repo(pldm_pdr_t *repo)
{
    printf("record_count : %d\n", repo->record_count);
    printf("size : %d\n", repo->size);
    printf("update_time : %d\n", repo->update_time);
    printf("repo_signature : %d\n", repo->repo_signature);
    u16 sum_size = 0;
    u8 cnt = 0;
    pldm_pdr_record_t *pdr = repo->first;
    while (pdr) {
        cnt++;
        printf("pdr size : %d, record handle : %d\n", pdr->size, pdr->record_handle);
        sum_size += pdr->size;
        pdr = pdr->next;
    }
    printf("sum size : %d, cnt : %d\n", sum_size, cnt);
    pldm_pdr_record_t *delete_pdr = repo->is_deleted;
    while (delete_pdr) {
        printf("deleted pdr size : %d, record handle : %d\n", delete_pdr->size, delete_pdr->record_handle);
        delete_pdr = delete_pdr->next;
    }
}

#define __TO_STR(__str)     (#__str)
#define TO_STR(str)         __TO_STR(str)

void pldm_monitor_printf_sensor_detail(u8 *ev_data)
{
    printf("start %s\n", __FUNCTION__);
    printf("sensor class : %s\n", TO_STR(PLDM_SENSOR_OP_STATE));
    pldm_field_per_sensor_op_state_format_t *sensor_dat = (pldm_field_per_sensor_op_state_format_t *)ev_data;
    printf("present_op_state : %d\n", sensor_dat->present_op_state);
    printf("previous_op_state : %d\n", sensor_dat->previous_op_state);
    printf("end %s\n", __FUNCTION__);
}

void pldm_monitor_printf_state_sensor_detail(u8 *ev_data)
{
    printf("start %s\n", __FUNCTION__);
    printf("sensor class : %s\n", TO_STR(PLDM_STATE_SENSOR_STATE));
    pldm_field_per_state_sensor_state_format_t *sensor_dat = (pldm_field_per_state_sensor_state_format_t *)ev_data;
    printf("event_state : %d\n", sensor_dat->event_state);
    printf("previous_event_state : %d\n", sensor_dat->previous_event_state);
    printf("sensor_offset : %d\n", sensor_dat->sensor_offset);
    printf("end %s\n", __FUNCTION__);
}

void pldm_monitor_printf_numeric_sensor_detail(u8 *ev_data)
{
    printf("start %s\n", __FUNCTION__);
    printf("sensor class : %s\n", TO_STR(PLDM_NUMERIC_SENSOR_STATE));
    pldm_field_per_numeric_sensor_state_format_t *sensor_dat = (pldm_field_per_numeric_sensor_state_format_t *)ev_data;
    printf("event_state : %d\n", sensor_dat->event_state);
    printf("previous_event_state : %d\n", sensor_dat->previous_event_state);
    printf("present_reading : %d\n", sensor_dat->present_reading);
    printf("sensor_datasize : %d\n", sensor_dat->sensor_datasize);
    printf("end %s\n", __FUNCTION__);
}

void pldm_monitor_printf_sensor_event(u8 *data)
{
    pldm_sensor_event_class_event_data_format_t *sensor_event = (pldm_sensor_event_class_event_data_format_t *)data;
    printf("\nsensor id : %d\n", sensor_event->sensor_id);
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
            printf("err sensor_event_class!\n");
            break;
    }
}

void pldm_monitor_printf_repo_chg_event(u8 *data)
{
    printf("\nstart %s\n", __FUNCTION__);
    pldm_pdr_repo_chg_event_data_format_t *pdr_chg_dat = (pldm_pdr_repo_chg_event_data_format_t *)data;
    printf("event_data_format %d\n", pdr_chg_dat->event_data_format);
    printf("num_of_chg_records %d\n", pdr_chg_dat->num_of_chg_records);
    for (u8 i = 0; i < pdr_chg_dat->num_of_chg_records; i++) {
        printf("chg_entry %d\n", pdr_chg_dat->chg_record[i].chg_entry[0]);
        printf("event_data_op %d\n", pdr_chg_dat->chg_record[i].event_data_op);
        printf("num_of_chg_entries %d\n", pdr_chg_dat->chg_record[i].num_of_chg_entries);
    }
    printf("end %s\n", __FUNCTION__);
}

void pldm_monitor_printf_event_rbuf(void *p)
{
    u16 event_cnt = g_event_id;
    u8 event_data_info[sizeof(pldm_event_data_t)] = {0};
    u8 payload[64];
    while (!pldm_event_rbuf_is_empty(p)) {
        pldm_event_rbuf_try_read(p, event_data_info, sizeof(pldm_event_data_t), 0);
        pldm_event_data_t *pldm_event_data = (pldm_event_data_t *)event_data_info;                       /* the oldest event */
        // u8 event_cnt = g_event_id - pldm_event_data->event_id;
        printf("event id : %d, class : %d, size : %d\n", pldm_event_data->event_id, pldm_event_data->event_class, pldm_event_data->event_data_size);
        pldm_event_rbuf_try_read(g_pldm_monitor_info.pldm_event_rbuf, payload, pldm_event_data->event_data_size, sizeof(pldm_event_data_t));
        switch (pldm_event_data->event_class) {
            case SENSOR_EVENT:
                // pldm_monitor_printf_sensor_event(payload);
                break;
            case PLDM_PDR_REPO_CHG_EVENT:
                // pldm_monitor_printf_repo_chg_event(payload);
                break;
            default :
                printf("err class : %d\n", pldm_event_data->event_class);
                break;
        }
        pldm_event_rbuf_read_done(p);
    }
    g_event_id = 1;
    printf("event cnt : %d\n", event_cnt);
}

void pldm_monitor_init(void)
{
    pldm_monitor_base_info_init(&g_pldm_monitor_info);
}

typedef void (*pdr_init_func)(void);

void pldm_monitor_test(void)
{
    pldm_monitor_init();

    pdr_init_func pdr_init[] = {
        pldm_assoc_pdr_init,
        pldm_terminus_locator_pdr_init,
        pldm_numeric_sensor_pdr_init,
        pldm_state_sensor_pdr_init,
        pldm_redfish_pdr_init,
    };

    for (u8 i = 0; i < sizeof(pdr_init) / sizeof(pdr_init_func); i++) {
        pdr_init[i]();
        pldm_pde_get_used();
    }
    g_pldm_monitor_info.terminus_mode = PLDM_ENABLE_ASYNC;
    for (u8 i = 0; i < MAX_LAN_NUM; i++) {
        pldm_link_handle(i, 1);
        pldm_pde_get_used();
    }
    for (u8 i = 0; i < MAX_LAN_NUM; i++) {
        pldm_link_handle(i, 0);
        pldm_pde_get_used();
    }
    // pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));
    // for (u8 i = 0; i < MAX_LAN_NUM; i++) {
    //     pldm_link_handle(i, 1);
    //     pldm_pde_get_used();
    // }
    pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));
    pldm_monitor_printf_event_rbuf(g_pldm_monitor_info.pldm_event_rbuf);
    // SENSOR_EVENT = 0x00,
    // REDFISH_TASK_EXCUTE_EVENT = 0x02,
    // REDFISH_MSG_EVENT = 0x03,
    // PLDM_PDR_REPO_CHG_EVENT = 0x04,
    // PLDM_MSG_POLL_EVENT = 0x05
}