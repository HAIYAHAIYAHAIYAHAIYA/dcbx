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

#endif /* __PLDM_CJSON_H__ */