#ifndef __PLDM_BEJ_RESOLVE_H__
#define __PLDM_BEJ_RESOLVE_H__

#include "main.h"
#include "type.h"
#include "CJSON.h"
#include "pldm_cjson.h"

#pragma pack(1)

typedef struct {
    u8 seq;
    u8 fmt;
    u16 len;
    u8 sflv_len;
    u8 *val;
} pldm_bej_sflv_t;

typedef struct {
    u8 len;         /* max len is 0xFF */
    u8 data[0];     /* LSB -> MSB */
} pldm_bej_nnint_t;

typedef struct {
    u8 format;
    u16 sequence_num;
    u16 childpoint_off;
    u16 child_cnt;
    u8 name_len;
    u16 name_off;
} pldm_redfish_dictionary_entry_t;

typedef struct {
    u8 version_tag;
    u8 dictionay_flags;
    u16 entry_cnt;  // name count
    u32 schema_version;
    u32 dictionary_size;
    pldm_redfish_dictionary_entry_t entry[0];
    // u8 name[0];
    // u8 copyright_len;
    // u8 copyright[0];
} pldm_redfish_dictionary_format_t;

typedef struct {
    u8 copyright_len;
    u8 copyright[0];
} pldm_redfish_dictionary_copyright_t;

typedef struct {
    u8 len;
    u8 *val;
} pldm_bej_key_t;

#pragma pack()

typedef enum {
    BEJ_SET = 0,
    BEJ_ARRAY,
    BEJ_NULL,
    BEJ_INT,
    BEJ_ENUM,
    BEJ_STR,
    BEJ_REAL,
    BEJ_BOOLEAN,
    BEJ_BYTE_STR,
    BEJ_CHOICE,
    BEJ_PROPERTY_ANNO,
    BEJ_REGISTRY_ITEM,
    BEJ_RESOURCE_LINK = 0xE,
    BEJ_RESOURCE_LINK_EXPANSION = 0xF,
} pldm_bej_fmt_t;

// void pldm_bej_encode(pldm_cjson_t *root, u8 *dict);
u16 pldm_bej_decode(u8 *buf, u8 *dict, pldm_redfish_dictionary_entry_t *entry, u8 entry_cnt, cJSON *root);
pldm_cjson_t *pldm_bej_decode1(u8 *buf, u8 *anno_dict, u8 *dict, pldm_cjson_t *root);
u8 *pldm_bej_encode(pldm_cjson_t *root, u8 *bej_buf);
void pldm_bej_init(void);
void pldm_bej_get_sflv(u8 *buf, pldm_bej_sflv_t *sflv);
void pldm_bej_dict_search1(pldm_bej_sflv_t *sflv, u8 *dict);

#endif /* __PLDM_BEJ_RESOLVE_H__ */