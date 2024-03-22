#ifndef __PLDM_REDFISH_H__
#define __PLDM_REDFISH_H__

#include "main.h"

#pragma pack(1)

typedef struct {
    u16 len;
    u32 dict_sign;
    u8 data[0];
} pldm_redfish_dict_fmt_t;
typedef struct {
    u32 resource_id;
    u16 schema_class;
    u16 offset;
} dict_off_id_t;

typedef struct {
    u16 total_len;
    u16 num_of_dict;
    dict_off_id_t dict[0];
} dict_hdr_t;

#pragma pack()

void pldm_redfish_dict_test(void);

#endif /* __PLDM_REDFISH_H__ */