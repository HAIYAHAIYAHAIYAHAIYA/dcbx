#ifndef __PLDM_DATA_H__
#define __PLDM_DATA_H__

#include "type.h"

#define PLDM_STATIC_DATA_MAX_LEN                (10 * 1024)
#define PLDM_DATA_PATH                          "pldm_data.bin"

#pragma pack(1)

typedef struct {
    u32 pldm_pdr_off;
    u32 pldm_pdr_size;

    u32 pldm_fwup_info_off;
    u32 pldm_fwup_info_size;

    u32 pldm_redfish_dict_off;
    u32 pldm_redfish_dict_size;

    u32 pldm_redfish_schema_off;
    u32 pldm_redfish_schema_size;
} pldm_data_hdr_t;

typedef struct {
    u16 total_size;
    u16 cnt;
} pldm_pdr_data_hdr_t, pldm_redfish_schema_data_hdr_t;

#pragma pack()

void pldm_data_analyze(void);

#endif /* __PLDM_DATA_H__ */