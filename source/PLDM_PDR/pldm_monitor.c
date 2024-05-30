#include "pldm_monitor.h"
#include "pldm_monitor_event_rbuf.h"
#include "pdr.h"
#include "sha256.h"
#include "main.h"
#include <time.h>
#include  "utlist.h"

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
    pldm_monitor_base_info->event_receiver_eid = 0x66;
    pldm_monitor_base_info->terminus_mode = PLDM_ENABLE_ASYNC;
    pldm_monitor_base_info->terminus_max_buffersize = PLDM_TERMINUS_DEFAULT_BUFFERSIZE;     /* default size. */
    pldm_monitor_base_info->pldm_event_rbuf = pldm_event_rbuf_init();
    pdrs_pool_init((u32 *)gs_pdrs_buf);
    pldm_pdr_init(&(pldm_monitor_base_info->pldm_repo));
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
    LOG("repo_signature : %d", repo->repo_signature);
    u16 sum_size = 0;
    u8 cnt = 0;
    pldm_pdr_record_t *pdr = NULL;
#if MY_LIST
    pdr = repo->first;
#else
    pdr = repo->head;
#endif
    while (pdr) {
        cnt++;
        pldm_pdr_hdr_t *hdr = (pldm_pdr_hdr_t *)(pdr->data);
        LOG("pdr size : %04d, record handle : %04d, type : %d", pdr->size, pdr->record_handle, hdr->type);
        repo->repo_signature = 0;
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

#define __TO_STR(__str)     (#__str)
#define TO_STR(str)         __TO_STR(str)

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
    LOG("present_reading : %d", sensor_dat->present_reading);
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

void pldm_monitor_printf_event_rbuf(void *p)
{
    u16 event_cnt = g_event_id;
    u8 event_data_info[sizeof(pldm_event_data_t)] = {0};
    u8 payload[64];
    while (!pldm_event_rbuf_is_empty(p)) {
        pldm_event_rbuf_try_read(p, event_data_info, sizeof(pldm_event_data_t), 0);
        pldm_event_data_t *pldm_event_data = (pldm_event_data_t *)event_data_info;                       /* the oldest event */
        // u8 event_cnt = g_event_id - pldm_event_data->event_id;
        LOG("event id : %d, class : %d, size : %d", pldm_event_data->event_id, pldm_event_data->event_class, pldm_event_data->event_data_size);
        pldm_event_rbuf_try_read(g_pldm_monitor_info.pldm_event_rbuf, payload, pldm_event_data->event_data_size, sizeof(pldm_event_data_t));
        switch (pldm_event_data->event_class) {
            case SENSOR_EVENT:
                // pldm_monitor_printf_sensor_event(payload);
                break;
            case PLDM_PDR_REPO_CHG_EVENT:
                // pldm_monitor_printf_repo_chg_event(payload);
                break;
            default :
                LOG("err class : %d", pldm_event_data->event_class);
                break;
        }
        pldm_event_rbuf_read_done(p);
    }
    g_event_id = 1;
    LOG("event cnt : %d", event_cnt);
}

void pldm_monitor_init(void)
{
    pldm_monitor_base_info_init(&g_pldm_monitor_info);
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
    LOG("\nORI REPO");
    pldm_monitor_printf_repo(&(g_pldm_monitor_info.pldm_repo));
    LOG("\nRD REPO");
    pldm_monitor_gen_static_pdr_data(&(g_pldm_monitor_info.pldm_repo));
    pdrs_pool_reinit();
    pldm_monitor_create_static_pdr(&(g_pldm_monitor_info.pldm_repo));

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
    // end = clock();
    // cost = end - start;
    // LOG("time diff %f",cost);   /* uint is ms */

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