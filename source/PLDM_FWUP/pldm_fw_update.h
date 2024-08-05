#ifndef __PLDM_FW_UPDATE_H__
#define __PLDM_FW_UPDATE_H__
#include "type.h"

typedef enum {
    PLDM_UD_TYPE_UNKNOW = 0,
    PLDM_UD_TYPE_ASCII,
    PLDM_UD_TYPE_UTF_8,
    PLDM_UD_TYPE_UTF_16,
    PLDM_UD_TYPE_UTF_16LE,
    PLDM_UD_TYPE_UTF_16BE
} pldm_fwup_str_type_val_t;

#pragma pack(1)
typedef struct {
    u16 utc_offset;
    u8 microsecond[3];
    u8 sec;
    u8 min;
    u8 hour;
    u8 day;
    u8 mon;
    u16 year;
    u8 time_resolution      : 4;
    u8 utc_resolution       : 4;
} pldm_fwup_timestamp104_t;

typedef struct {
    u8 uuid[16];
    u8 pkt_hdr_fmt_reversion;
    u16 pkt_hdr_size;
    pldm_fwup_timestamp104_t pkt_release_datetime;
    u16 comp_bitmap_bitlen;
    u8 pkt_ver_str_type;
    u8 pkt_ver_str_len;
    u8 pkt_ver_str[0];
}pldm_fwup_pkt_hdr_t;

typedef struct {
    u16 record_len;
    u8 descriptor_cnt;
    u32 dev_up_op_flgs;
    u8 comp_img_set_ver_str_type;
    u8 comp_img_set_ver_str_len;
    u16 fw_dev_pkt_data_len;
    u8 applicable_comps;
    u8 comp_img_set_ver_str[0];
} pldm_fwup_fw_dev_id_records_first_part_t;

typedef struct {
    u16 add_type;
    u16 add_len;
    u8 add_data[0];
} pldm_add_descriptor_t;

typedef struct {
    pldm_add_descriptor_t descriptor;
} pldm_fwup_fw_dev_id_records_middle_part_t;

typedef struct {
    u8 fw_dev_pkt_data[0];
} pldm_fwup_fw_dev_id_records_end_part_t;

typedef struct {
    u8 dev_id_record_cnt;
    u8 fw_dev_id_records[0];
} pldm_fwup_fw_dev_indentification_area_t;

typedef struct {
    u16 comp_classification;
    u16 comp_identifier;
    u32 comp_comparison_stamp;
    u16 comp_options;
    u16 req_comp_acti_method;
    u32 comp_local_offset;
    u32 comp_size;
    u8 comp_ver_str_type;
    u8 comp_ver_str_len;
    u8 comp_ver_str[0];
} pldm_fwup_comp_img_info_first_part_t;

typedef struct {
    u32 pkt_hdr_crc32;
} pldm_fwup_comp_img_info_end_part_t;

// typedef struct {
//     u32 comp_opaque_data_len;
//     u8 comp_opaque_data[0];
// } pldm_fwup_comp_img_info_end_part_t;

typedef struct {
    u16 comp_img_cnt;
    u8 comp_img_info[0];
} pldm_fwup_comp_img_info_area_t;

typedef struct {
    u8 comp_img_set_ver_str_type;
    u8 comp_img_set_ver_str_len;
    u8 val[0];
} pldm_comp_img_set_ver_str_type_and_len_t;

typedef struct {
    u16 comp_classification;
    u16 comp_identifier;
    u8 comp_classification_idx;         /* not used */
    u16 methon;
    pldm_comp_img_set_ver_str_type_and_len_t info;
} pldm_fwup_comp_info_t;

typedef struct {
    u32 active_img_state;
    pldm_comp_img_set_ver_str_type_and_len_t fw_img_info;
} pldm_fw_img_info_t;

#pragma pack()

void pldm_fwup_verify_pkt_data_test(void);

#endif /* __PLDM_FW_UPDATE_H__ */