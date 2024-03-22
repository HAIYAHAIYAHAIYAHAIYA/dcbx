#ifndef __PLDM_REDFISH_H__
#define __PLDM_REDFISH_H__

#include "main.h"

#define PLDM_REDFISH_DICT_NUM                               (14)
#define PLDM_REDFISH_DICT_INFO_LEN                          ALIGN((sizeof(pldm_redfish_dict_hdr_t) + PLDM_REDFISH_DICT_NUM * sizeof(pldm_redfish_dict_info_t)), 4)

/*  annotation.bin                          2560
    EthernetInterfaceCollection_v1.bin      164
    EthernetInterface_v1.bin                3068
    Event_v1.bin                            1084
    MessageRegistry_v1.bin                  276
    NetworkAdapter_v1.bin                   4072
    NetworkDeviceFunctionCollection_v1.bin  168
    NetworkDeviceFunction_v1.bin            3432
    NetworkInterface_v1.bin                 872
    PCIeDeviceCollection_v1.bin             156
    PCIeDevice_v1.bin                       4244
    PCIeFunction_v1.bin                     1944
    PortCollection_v1.bin                   148
    Port_v1.bin                             8076
 */

#define DICT_FMT_HDR_LEN                                    (sizeof(pldm_redfish_dict_fmt_t))

#define PLDM_REDFISH_ANNO_DICT_LEN                          (2560)
#define PLDM_REDFISH_ETH_INTERFACE_COLLECTION_DICT_LEN      (164)
#define PLDM_REDFISH_ETH_INTERFACE_DICT_LEN                 (3068)
#define PLDM_REDFISH_EVENT_DICT_LEN                         (1084)
#define PLDM_REDFISH_MSG_REGISTER_DICT_LEN                  (276)
#define PLDM_REDFISH_NETWORK_ADAPTER_DICT_LEN               (4072)
#define PLDM_REDFISH_NETWORK_DEV_FUNCS_DICT_LEN             (168)
#define PLDM_REDFISH_NETWORK_DEV_FUNC_DICT_LEN              (3432)
#define PLDM_REDFISH_NETWORK_INTERFACE_DICT_LEN             (872)
#define PLDM_REDFISH_PCIE_FUNCS_DICT_LEN                    (156)
#define PLDM_REDFISH_PCIE_DEV_DICT_LEN                      (4244)
#define PLDM_REDFISH_PCIE_FUNC_DICT_LEN                     (1944)
#define PLDM_REDFISH_PORTS_DICT_LEN                         (148)
#define PLDM_REDFISH_PORT_DICT_LEN                          (8076)

typedef u8                                                  schemaclass;

typedef enum {
    SCHEMACLASS_MAJOR = 0,
    SCHEMACLASS_EVENT,
    SCHEMACLASS_ANNOTATION,
    SCHEMACLASS_COLLECTION_MEMBER_TYPE,
    SCHEMACLASS_ERROR,
    SCHEMACLASS_REGISTRY
} pldm_redfish_schemaclass_t;

#pragma pack(1)

typedef struct {
    u32 ver;
    u16 rsvd;
    schemaclass schema_class;
    u8 bejtuple[0];
    /* bejtuple_t */
} bejencoding_t;

typedef struct {
    u16 len;
    u32 dict_sign;
    u8 data[0];
} pldm_redfish_dict_fmt_t;

typedef struct {
    u32 resource_id;
    u16 schema_class;
    u16 offset;
} pldm_redfish_dict_info_t;

typedef struct {
    u16 total_len;
    u16 num_of_dict;
    pldm_redfish_dict_info_t dict_info[0];
} pldm_redfish_dict_hdr_t;

#pragma pack()

void pldm_redfish_dict_test(void);

#endif /* __PLDM_REDFISH_H__ */