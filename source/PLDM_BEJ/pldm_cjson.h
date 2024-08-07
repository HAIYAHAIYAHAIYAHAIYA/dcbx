#ifndef __PLDM_CJSON_H__
#define __PLDM_CJSON_H__

#include "type.h"

#define MY_CJSON_POLL_SIZE   (6000)              /* max 5798 */

#define ALIGN(dat, align)    (((dat) + (align) - 1) & (~((align) - 1)))

#define MAX_LAN_NUM         4

/* resource id */
#define PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID         (1)
#define PLDM_BASE_NETWORK_INTERFACE_RESOURCE_ID       (5)
#define PLDM_BASE_PORTS_RESOURCE_ID                   (10)
#define PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID       (20)
#define PLDM_BASE_PORT_RESOURCE_ID                    (100)
#define PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID        (200)
#define PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID_1      (210)
#define PLDM_BASE_PCIE_FUNCS_RESOURCE_ID              (30)
#define PLDM_BASE_PCIE_FUNC_RESOURCE_ID               (300)
#define PLDM_BASE_ETH_INTERFACE_COLLECTION_RESOURCE_ID (40)
#define PLDM_BASE_ETH_INTERFACE_RESOURCE_ID           (400)
#define PLDM_BASE_ETH_INTERFACE_RESOURCE_ID_1         (410)
#define PLDM_BASE_RESET_SET2DEFAULE_RESOURCE_ID       (2001)
#define PLDM_BASE_PORT_RESET_RESOURCE_ID              (2002)  /* ? E810 */

#pragma pack(1)

typedef struct {
    u8 seq;
    u8 fmt;
    u16 len;
    char *val;
}  pldm_bej_sflv_dat_t;

typedef struct pldm_cjson {
    struct pldm_cjson *next;
    struct pldm_cjson *child;
    char *name;
    pldm_bej_sflv_dat_t sflv;
} pldm_cjson_t;

typedef struct {
    u8 schema_type;     /* is anno : 1, is major : 0 */
    u8 fmt;
    u8 child_cnt;
    char *key;
    char *val;
} pldm_cjson_schema_fmt_t;

#pragma pack()

typedef enum {
    HEAD = 0,
    READ,
    CREATE,
    DELETE,
    UPDATE,
    REPLACE,
    ACTION,
    EVENTS,
    OTHER_TYPE
} pldm_redfish_dev_feature_support_t;

typedef pldm_cjson_t *(*schema_create)(u32 resource_id);

void pldm_cjson_test(void);

pldm_cjson_t *pldm_cjson_create_obj(void);
void pldm_cjson_delete_node(pldm_cjson_t *node);
u16 pldm_cjson_cal_len_to_root1(pldm_cjson_t *root, u8 op_type);
u16 pldm_cjson_cal_len_to_root2(pldm_cjson_t *root, u8 op_type);

void pldm_cjson_printf_dict(u8 *dictionary);

pldm_cjson_t *pldm_cjson_add_item_to_obj(pldm_cjson_t *obj, pldm_bej_sflv_dat_t *sflv, char *name, char *val, u8 len);
void pldm_cjson_add_enum_to_obj(pldm_cjson_t *obj, u8 *dictionary, pldm_bej_sflv_dat_t *sflv, char *enum_name, char *enum_val);

void pldm_cjson_printf_root2(pldm_cjson_t *root);

pldm_cjson_t *pldm_cjson_create_event_schema(u32 resource_id, u8 link_state);
void pldm_cjson_pool_init(void);
void pldm_cjson_pool_reinit(void);
void pldm_cjson_cal_sf_to_root(pldm_cjson_t *root, u8 *anno_dict, u8 *dict);
void pldm_cjson_update_etag(pldm_cjson_t *root);

#endif /* __PLDM_CJSON_H__ */