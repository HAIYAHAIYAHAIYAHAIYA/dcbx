#include "pldm_fru_data.h"
#include "pldm_fw_update.h"
#include "pldm_cjson.h"
#include "main.h"

static u8 gs_pldm_fru_table[PLDM_FRU_TABLE_BUF_LEN];

u8 *pldm_fru_fill_general_part(u8 *buf)
{
    char serial_num[2] = {MAX_LAN_NUM, 0x00};
    char *vals[] = {
        "",
        "",
        "Amber",
        serial_num,
        "WXKJ",
        "2024-04-22-18",
        "WXKJ",
        "Amber",
        "",
        "ver.xx.xx.xx",
        "",
        "Amber xx xx xx xx",
        "",
        "for WXKJ use",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

u8 *pldm_fru_fill_chip_part(u8 *buf)
{
    char *vals[] = {
        "WXKJ",
        "FW Version:",
        "PCIe Link Speed: XXX",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

u8 *pldm_fru_fill_port0_part(u8 *buf)
{
    char *vals[] = {
        "WXKJ",
        "Port Name: 0",
        "Link Type: FC",
        "WWNN: 20000000C9142356",
        "WWPN: 10000000C9142356",
        "Factory WWNN: 20000000C9142356",
        "Factory WWPN: 10000000C9142356",
        "FC Link Speed Capabilities: XXX",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

u8 *pldm_fru_fill_port1_part(u8 *buf)
{
    char *vals[] = {
        "WXKJ",
        "Port Name: 1",
        "Link Type: FC",
        "WWNN: 20000000C9142356",
        "WWPN: 10000000C9142356",
        "Factory WWNN: 20000000C9142356",
        "Factory WWPN: 10000000C9142356",
        "FC Link Speed Capabilities: XXX",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

u8 *pldm_fru_fill_port2_part(u8 *buf)
{
    char *vals[] = {
        "WXKJ",
        "Port Name: 2",
        "Link Type: FC",
        "WWNN: 20000000C9142356",
        "WWPN: 10000000C9142356",
        "Factory WWNN: 20000000C9142356",
        "Factory WWPN: 10000000C9142356",
        "FC Link Speed Capabilities: XXX",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

u8 *pldm_fru_fill_port3_part(u8 *buf)
{
    char *vals[] = {
        "WXKJ",
        "Port Name: 3",
        "Link Type: FC",
        "WWNN: 20000000C9142356",
        "WWPN: 10000000C9142356",
        "Factory WWNN: 20000000C9142356",
        "Factory WWPN: 10000000C9142356",
        "FC Link Speed Capabilities: XXX",
    };
    pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)buf;
    for (u8 i = 0; i < sizeof(vals) / sizeof(char *); i++) {
        tlv->type = i + 1;
        tlv->len = cm_strlen(vals[i]);
        cm_memcpy(tlv->val, vals[i], tlv->len);
        tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
    }
    return (u8 *)tlv;
}

void pldm_fru_init(void)
{
    pldm_fru_record_table_field_fmt_t fields[] = {
        [0] = {FRU_GENERAL_SET_ID, RECORD_GENERAL_FRU_RECORD_TYPE, 0, PLDM_UD_TYPE_ASCII},
        [1] = {FRU_CHIP_SET_ID   , RECORD_OEM_FRU_RECORD_TYPE,     0, PLDM_UD_TYPE_ASCII},
        [2] = {FRU_PORT0_SET_ID  , RECORD_OEM_FRU_RECORD_TYPE,     0, PLDM_UD_TYPE_ASCII},
        [3] = {FRU_PORT1_SET_ID  , RECORD_OEM_FRU_RECORD_TYPE,     0, PLDM_UD_TYPE_ASCII},
        [4] = {FRU_PORT2_SET_ID  , RECORD_OEM_FRU_RECORD_TYPE,     0, PLDM_UD_TYPE_ASCII},
        [5] = {FRU_PORT3_SET_ID  , RECORD_OEM_FRU_RECORD_TYPE,     0, PLDM_UD_TYPE_ASCII},
    };

    u8 num_of_fru_fields[] = {
        14,
        3,
        8,
        8,
        8,
        8,
    };

    pldm_fru_fill_table *fill_func[] = {
        pldm_fru_fill_general_part,
        pldm_fru_fill_chip_part,
        pldm_fru_fill_port0_part,
        pldm_fru_fill_port1_part,
        pldm_fru_fill_port2_part,
        pldm_fru_fill_port3_part,
    };

    pldm_fru_record_table_fmt_t *table = (pldm_fru_record_table_fmt_t *)gs_pldm_fru_table;
    table->head.fru_data_major_ver = 0x01;
    table->head.fru_data_minor_ver = 0;
    table->head.fru_table_maxi_size = 0;                                /* means that SetFRURecordTable command is not supported. */
    table->head.num_of_records_set_identifiers = 2 + MAX_LAN_NUM;
    table->head.num_of_records = 1;
    u8 *next_part = NULL;
    pldm_fru_record_table_field_fmt_t *record_data = (pldm_fru_record_table_field_fmt_t *)&(table->field);
    for (u8 i = 0; i < table->head.num_of_records_set_identifiers; i++) {
        *record_data = fields[i];
        record_data->num_of_fru_fields = num_of_fru_fields[i];
        next_part = record_data->tlv;
        next_part = fill_func[i](next_part);
        record_data = (pldm_fru_record_table_field_fmt_t *)next_part;
    }
    table->head.fru_table_len = next_part - gs_pldm_fru_table - sizeof(pldm_fru_get_fru_record_table_metadata_rsp_dat_t);
}

void pldm_fru_table_printf(void)
{
    pldm_fru_record_table_fmt_t *table = (pldm_fru_record_table_fmt_t *)gs_pldm_fru_table;
    LOG("fru_data_major_ver : %d", table->head.fru_data_major_ver);
    LOG("fru_data_minor_ver : %d", table->head.fru_data_minor_ver);
    LOG("fru_table_len : %d", table->head.fru_table_len);
    LOG("fru_table_maxi_size : %d", table->head.fru_table_maxi_size);
    LOG("num_of_records : %d", table->head.num_of_records);
    LOG("num_of_records_set_identifiers : %d", table->head.num_of_records_set_identifiers);

    pldm_fru_record_table_field_fmt_t *record_data = (pldm_fru_record_table_field_fmt_t *)&(table->field);
    for (u8 i = 0; i < table->head.num_of_records_set_identifiers; i++) {
        LOG("fru_record_set_identifier : %d", record_data->fru_record_set_identifier);
        LOG("num_of_fru_fields : %d", record_data->num_of_fru_fields);
        LOG("fru_record_type : %d", record_data->fru_record_type);
        LOG("encode_type_of_fru_field : %d", record_data->encode_type_of_fru_field);
        pldm_fru_tlv_fmt_t *tlv = (pldm_fru_tlv_fmt_t *)record_data->tlv;
        for (u8 j = 0; j < record_data->num_of_fru_fields; j++) {
            LOG("type : %d", tlv->type);
            LOG("len : %d", tlv->len);
            for (u8 k = 0; k < tlv->len; k++) {
                printf("%c", tlv->val[k]);
            }
            LOG("");
            tlv = (pldm_fru_tlv_fmt_t *)&(tlv->val[tlv->len]);
        }
        record_data = (pldm_fru_record_table_field_fmt_t *)tlv;
    }
}

void pldm_fru_data_test(void)
{
    pldm_fru_init();
    pldm_fru_table_printf();
}