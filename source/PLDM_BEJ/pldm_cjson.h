#ifndef __PLDM_CJSON_H__
#define __PLDM_CJSON_H__

#include "type.h"

#define MY_CJSON_POLL_SIZE   (2 * 1024)

#define ALIGN(dat, align)    (((dat) + (align) - 1) & (~((align) - 1)))

#pragma pack(1)

typedef struct {
    u8 seq;
    u8 fmt;
    u16 len;
    u8 val[0];
} pldm_bej_sflv_dat_t;

typedef struct pldm_cjson {
    struct pldm_cjson *next;
    struct pldm_cjson *child;
    u8 *name;
    pldm_bej_sflv_dat_t sflv;
} pldm_cjson_t;

#pragma pack()

void pldm_cjson_test(void);

pldm_cjson_t *pldm_cjson_create_obj(void);
void pldm_cjson_delete_node(pldm_cjson_t *node);
u16 pldm_cjson_cal_len_to_root1(pldm_cjson_t *root, u8 op_type);

pldm_cjson_t *pldm_cjson_add_item_to_obj(pldm_cjson_t *obj, pldm_bej_sflv_dat_t *sflv, char *name, char *val, u8 len);
void pldm_cjson_add_enum_to_obj(pldm_cjson_t *obj, u8 *dictionary, pldm_bej_sflv_dat_t *sflv, char *enum_name, char *enum_val);

#endif /* __PLDM_CJSON_H__ */