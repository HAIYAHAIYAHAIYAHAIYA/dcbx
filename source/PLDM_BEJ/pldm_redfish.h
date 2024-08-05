#ifndef __PLDM_REDFISH_H__
#define __PLDM_REDFISH_H__

#include "main.h"
#include "pldm_cjson.h"

#define PLDM_REDFISH_DICT_NUM                               (14)
#define PLDM_REDFISH_RESOURCE_NUM                           (4 * MAX_LAN_NUM + 7)   /* refer to pldm redfish resource id cnt */
#define PLDM_REDFISH_DICT_INFO_LEN                          ALIGN((sizeof(pldm_redfish_dict_hdr_t) + PLDM_REDFISH_DICT_NUM * sizeof(pldm_redfish_dict_info_t)), 4)
#define PLDM_REDFISH_DEV_MAXIMUM_XFER_CHUNKSIZE_BYTES       (2048)

#define PLDM_REDFISH_DICT_BASE_ADDR                         (0)

#define NETWORK_ADAPTER_SCHEMACLASS                         (BIT(SCHEMACLASS_MAJOR))
#define NETWORK_INTERFACE_SCHEMACLASS                       (BIT(SCHEMACLASS_MAJOR))
#define PCIE_DEVICE_SCHEMACLASS                             (BIT(SCHEMACLASS_MAJOR))
#define PORT_COLLECTION_SCHEMACLASS                         (BIT(SCHEMACLASS_MAJOR) | BIT(SCHEMACLASS_COLLECTION_MEMBER_TYPE))
#define NETWORK_DEVICE_FUNC_COLLECTION_SCHEMACLASS          (BIT(SCHEMACLASS_MAJOR) | BIT(SCHEMACLASS_COLLECTION_MEMBER_TYPE))
#define PCIE_FUNC_COLLECTION_SCHEMACLASS                    (BIT(SCHEMACLASS_MAJOR) | BIT(SCHEMACLASS_COLLECTION_MEMBER_TYPE))
#define PORT_IDENTIFY_SCHEMACLASS                           (BIT(SCHEMACLASS_MAJOR))
#define NETWORK_DEVICE_FUNC_SCHEMACLASS                     (BIT(SCHEMACLASS_MAJOR))
#define PCI_FUNC_SCHEMACLASS                                (BIT(SCHEMACLASS_MAJOR))
#define ETH_INTERFACE_SCHEMACLASS                           (BIT(SCHEMACLASS_MAJOR))
#define ETH_INTERFACE_COLLECTION_SCHEMACLASS                (BIT(SCHEMACLASS_MAJOR) | BIT(SCHEMACLASS_COLLECTION_MEMBER_TYPE))
#define ALL_SCHEMA_SCHEMACLASS                              (BIT(SCHEMACLASS_EVENT) | BIT(SCHEMACLASS_ANNOTATION) | BIT(SCHEMACLASS_ERROR))

#define SCHEMA_CLASS(schema_name)                           schema_name##_SCHEMACLASS

#define NETWORK_ADAPTER_ALLOWED_OP                          (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE)) | BIT(ACTION)
#define NETWORK_INTERFACE_ALLOWED_OP                        (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE))
#define PCIE_DEVICE_ALLOWED_OP                              (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE))
#define PORT_COLLECTION_ALLOWED_OP                          (BIT(READ) | BIT(HEAD))
#define NETWORK_DEVICE_FUNC_COLLECTION_ALLOWED_OP           (BIT(READ) | BIT(HEAD))
#define PCIE_FUNC_COLLECTION_ALLOWED_OP                     (0)
#define PORT_IDENTIFY_ALLOWED_OP                            (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE)) | BIT(ACTION)
#define NETWORK_DEVICE_FUNC_ALLOWED_OP                      (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE))
#define PCI_FUNC_ALLOWED_OP                                 (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE))
#define ETH_INTERFACE_ALLOWED_OP                            (BIT(READ) | BIT(HEAD) | BIT(UPDATE) | BIT(REPLACE))
#define ETH_INTERFACE_COLLECTION_ALLOWED_OP                 (BIT(READ) | BIT(HEAD))

#define SCHEMA_ALLOWED_OP(schema_name)                      schema_name##_ALLOWED_OP

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
#define PLDM_REDFISH_ETH_INTERFACE_COLLECTION_DICT_LEN      (128)
#define PLDM_REDFISH_ETH_INTERFACE_DICT_LEN                 (544)
#define PLDM_REDFISH_EVENT_DICT_LEN                         (1084)
#define PLDM_REDFISH_MSG_REGISTER_DICT_LEN                  (276)
#define PLDM_REDFISH_NETWORK_ADAPTER_DICT_LEN               (1156)
#define PLDM_REDFISH_NETWORK_DEV_FUNCS_DICT_LEN             (132)
#define PLDM_REDFISH_NETWORK_DEV_FUNC_DICT_LEN              (944)
#define PLDM_REDFISH_NETWORK_INTERFACE_DICT_LEN             (420)
#define PLDM_REDFISH_PCIE_FUNCS_DICT_LEN                    (124)
#define PLDM_REDFISH_PCIE_DEV_DICT_LEN                      (740)
#define PLDM_REDFISH_PCIE_FUNC_DICT_LEN                     (544)
#define PLDM_REDFISH_PORTS_DICT_LEN                         (116)
#define PLDM_REDFISH_PORT_DICT_LEN                          (1144)

typedef u8                                                  schemaclass;

typedef enum {
    EVENT = 0,
    REDFISH_PAYLOAD_ANNOTATIONS,
    REDFISH_ERROR,
    REGISTRY,

    NETWORK_ADAPTER,
    PCIE_DEVICE,
    NETWORK_INTERFACE,
    PORT_COLLECTION,
    PCIE_FUNC_COLLECTION,
    NETWORK_DEVICE_FUNC_COLLECTION,
    NETWORK_DEVICE_FUNC,
    PORT_IDENTIFY,
    PCI_FUNC,
    ETH_INTERFACE,
    ETH_INTERFACE_COLLECTION,
    ALL_SCHEMA,
    ALL_SCHEMA_IDENTIFY
} pldm_redfish_schema_identify_t;

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
    u8 schema_class;
    u8 allowed_op;
    char uri[2][39];
} pldm_redfish_schema_info_t;

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

typedef struct {
    u8 is_bej;
    u8 is_etag;
    u16 len;
    u8 etag[8];
    u8 data[520];           /* max 522 bytes */
} pldm_redfish_bej_t;

typedef struct {
    u16 len;
    u8 data[PLDM_REDFISH_DEV_MAXIMUM_XFER_CHUNKSIZE_BYTES];
} pldm_payload_dat_t;


#pragma pack()

void pldm_redfish_dict_test(void);
void CM_FLASH_READ(char *file_name, u32 offset, u32 *buf, u32 size);
u8 pldm_redfish_get_dict_data(u32 resource_id, u8 requested_schemaclass, u8 *dict, u16 len);
u16 pldm_redfish_get_dict_len(u32 resource_id);
void pldm_redfsih_dict_signature_test(void);

#endif /* __PLDM_REDFISH_H__ */