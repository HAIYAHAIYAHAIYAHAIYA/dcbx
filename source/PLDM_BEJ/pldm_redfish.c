#include "pldm_redfish.h"
#include "pldm_monitor.h"

u8 g_dict_info[PLDM_REDFISH_DICT_INFO_LEN];
u8 g_anno_dict[PLDM_REDFISH_ANNO_DICT_LEN];
u8 g_needed_dict[PLDM_REDFISH_PORT_DICT_LEN];

pldm_redfish_schema_info_t schema_info[ALL_SCHEMA_IDENTIFY] = {
    [EVENT]                             = {SCHEMACLASS_EVENT,                               BIT(READ),                                          {"Event.json"}},
    [REDFISH_PAYLOAD_ANNOTATIONS]       = {SCHEMACLASS_ANNOTATION,                          BIT(READ),                                          {"redfish-payload-annotations.v1_0_2.json"}},
    [REDFISH_ERROR]                     = {SCHEMACLASS_ERROR,                               BIT(READ),                                          {"v1/redfish-error.v1_0_0.json"}},
    [REGISTRY]                          = {SCHEMACLASS_REGISTRY,                            BIT(READ),                                          {"Registry.v1_5_0.json"}},
    [NETWORK_ADAPTER]                   = {SCHEMA_CLASS(NETWORK_ADAPTER),                   SCHEMA_ALLOWED_OP(NETWORK_ADAPTER),                 {"NetworkAdapter.v1_5_0.json"}},
    [NETWORK_INTERFACE]                 = {SCHEMA_CLASS(NETWORK_INTERFACE),                 SCHEMA_ALLOWED_OP(NETWORK_INTERFACE),               {"NetWorkInterface.v1_2_0.json"}},
    [PCIE_DEVICE]                       = {SCHEMA_CLASS(PCIE_DEVICE),                       SCHEMA_ALLOWED_OP(PCIE_DEVICE),                     {"PCIeDevice.v1_4_0.json"}},
    [PORT_COLLECTION]                   = {SCHEMA_CLASS(PORT_COLLECTION),                   SCHEMA_ALLOWED_OP(PORT_COLLECTION),                 {"PortCollection.json", "Port.json"}},
    [NETWORK_DEVICE_FUNC_COLLECTION]    = {SCHEMA_CLASS(NETWORK_DEVICE_FUNC_COLLECTION),    SCHEMA_ALLOWED_OP(NETWORK_DEVICE_FUNC_COLLECTION),  {"NetWorkDeviceFunctionCollection.json", "NetWorkDeviceFunction.json"}},
    [PCIE_FUNC_COLLECTION]              = {SCHEMA_CLASS(PCIE_FUNC_COLLECTION),              SCHEMA_ALLOWED_OP(PCIE_FUNC_COLLECTION),            {"PCIeFunctionCollection.json", "PCIeFunction.json"}},
    [PORT_IDENTIFY]                     = {SCHEMA_CLASS(PORT_IDENTIFY),                     SCHEMA_ALLOWED_OP(PORT_IDENTIFY),                   {"NetworkPort.v1_3_1.json"}},
    [NETWORK_DEVICE_FUNC]               = {SCHEMA_CLASS(NETWORK_DEVICE_FUNC),               SCHEMA_ALLOWED_OP(NETWORK_DEVICE_FUNC),             {"NetWorkDeviceFunction.v1_3_3.json"}},
    [PCI_FUNC]                          = {SCHEMA_CLASS(PCI_FUNC),                          SCHEMA_ALLOWED_OP(PCI_FUNC),                        {"PCIeFunction.v1_2_3.json"}},
    [ETH_INTERFACE]                     = {SCHEMA_CLASS(ETH_INTERFACE),                     SCHEMA_ALLOWED_OP(ETH_INTERFACE),                   {"EthernetInterface.v1_5_1.json"}},
    [ETH_INTERFACE_COLLECTION]          = {SCHEMA_CLASS(ETH_INTERFACE_COLLECTION),          SCHEMA_ALLOWED_OP(ETH_INTERFACE_COLLECTION),        {"EthernetInterfaceCollection.json", "EthernetInterface.json"}},
    // [ALL_SCHEMA]                        = {SCHEMA_CLASS(ALL_SCHEMA),                        SCHEMA_ALLOWED_OP(PCIE_FUNC_COLLECTION),            {"Event.json", "redfish-payload-annotations.v1_0_2.json", "v1/redfish-error.v1_0_0.json"}}
};

static u32 pldm_redfish_resource_id_to_base(u32 resource_id)
{
    if (resource_id >= PLDM_BASE_PORT_RESOURCE_ID && resource_id <= PLDM_MAX_ETH_INTERFACE_RESOURCE_ID_1) {
        if (((resource_id <= PLDM_MAX_PORT_RESOURCE_ID) && (resource_id >= PLDM_BASE_PORT_RESOURCE_ID)) || \
            ((resource_id <= PLDM_MAX_PORT_RESOURCE_ID_1) && (resource_id >= PLDM_BASE_PORT_RESOURCE_ID_1))) {
            resource_id = PLDM_BASE_PORT_RESOURCE_ID;
        } else if (((resource_id <= PLDM_MAX_NETWORK_DEV_FUNC_RESOURCE_ID) && (resource_id >= PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID)) || \
            ((resource_id <= PLDM_MAX_NETWORK_DEV_FUNC_RESOURCE_ID_1) && (resource_id >= PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID_1))) {
            resource_id = PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID;
        } else if ((resource_id <= PLDM_MAX_PCIE_FUNC_RESOURCE_ID) && (resource_id >= PLDM_BASE_PCIE_FUNC_RESOURCE_ID)) {
            resource_id = PLDM_BASE_PCIE_FUNC_RESOURCE_ID;
        } else if (((resource_id <= PLDM_MAX_ETH_INTERFACE_RESOURCE_ID) && (resource_id >= PLDM_BASE_ETH_INTERFACE_RESOURCE_ID)) || \
            ((resource_id <= PLDM_MAX_ETH_INTERFACE_RESOURCE_ID_1) && (resource_id >= PLDM_BASE_ETH_INTERFACE_RESOURCE_ID_1))) {
            resource_id = PLDM_BASE_ETH_INTERFACE_RESOURCE_ID;
        }
    }
    return resource_id;
}

u16 pldm_redfish_get_dict_len(u32 resource_id)
{
    u16 len = 0;
    resource_id = pldm_redfish_resource_id_to_base(resource_id);
    u32 dict_resource_id[] = {
        PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID,
        PLDM_BASE_PCIE_DEV_RESOURCE_ID,
        PLDM_BASE_NETWORK_INTERFACE_RESOURCE_ID,
        PLDM_BASE_PORTS_RESOURCE_ID,
        PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID,
        PLDM_BASE_PCIE_FUNCS_RESOURCE_ID,
        PLDM_BASE_ETH_INTERFACE_COLLECTION_RESOURCE_ID,
        PLDM_BASE_PORT_RESOURCE_ID,
        PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID,
        PLDM_BASE_PCIE_FUNC_RESOURCE_ID,
        PLDM_BASE_ETH_INTERFACE_RESOURCE_ID,
        PLDM_BASE_ANNOTATION_DICT_RESOURCE_ID,
    };
    u32 dict_len[] = {
        PLDM_REDFISH_NETWORK_ADAPTER_DICT_LEN,
        PLDM_REDFISH_PCIE_DEV_DICT_LEN,
        PLDM_REDFISH_NETWORK_INTERFACE_DICT_LEN,
        PLDM_REDFISH_PORTS_DICT_LEN,
        PLDM_REDFISH_NETWORK_DEV_FUNCS_DICT_LEN,
        PLDM_REDFISH_PCIE_FUNCS_DICT_LEN,
        PLDM_REDFISH_ETH_INTERFACE_COLLECTION_DICT_LEN,
        PLDM_REDFISH_PORT_DICT_LEN,
        PLDM_REDFISH_NETWORK_DEV_FUNC_DICT_LEN,
        PLDM_REDFISH_PCIE_FUNC_DICT_LEN,
        PLDM_REDFISH_ETH_INTERFACE_DICT_LEN,
        PLDM_REDFISH_ANNO_DICT_LEN,
    };
    u8 left = 0;
    u8 right = sizeof(dict_resource_id) / sizeof(u32) - 1;
    while (left <= right) {
        u8 mid = (left + right) / 2;
        if (dict_resource_id[mid] < resource_id) {
            left = mid + 1;
        } else if (dict_resource_id[mid] > resource_id) {
            right = mid - 1;
        } else {
            len = dict_len[mid];
            break;
        }
    }
    return len;
}

void CM_FLASH_READ(u32 offset, u32 *buf, u32 size)
{
    FILE *fp = fopen("./build/pldm_redfish_dicts.bin", "r+b");
    if (!fp) {
        LOG("CM_FLASH_READ open file err!");
        return;
    }
    fseek(fp, offset, SEEK_SET);
    fread(buf, sizeof(u32), size, fp);
    fclose(fp);
}

u8 pldm_redfish_get_dict_data(u32 resource_id, u8 requested_schemaclass, u8 *dict, u16 len)
{
    u32 dict_addr = 0;
    resource_id = pldm_redfish_resource_id_to_base(resource_id);
    pldm_redfish_dict_hdr_t *dict_info  = (pldm_redfish_dict_hdr_t *)g_dict_info;
    for (u8 i = 0; i < dict_info->num_of_dict; i++) {
        if (resource_id == dict_info->dict_info[i].resource_id && (BIT(requested_schemaclass) & dict_info->dict_info[i].schema_class)) {
            dict_addr = dict_info->dict_info[i].offset;
            break;
        }
    }
    if (dict_addr) {
        CM_FLASH_READ(PLDM_REDFISH_DICT_BASE_ADDR + dict_addr, (u32 *)dict, len / sizeof(u32));
    } else {
        LOG("not found dict data");
        return false;
    }
    return true;
}

void pldm_redfish_dict_test(void)
{
    FILE *pd = NULL;
    u8 b[9000];
    // 读取二进制文件
    // 文件名："test.bin",  访问方式："rb"
    pd = fopen("pldm_redfish_dicts.bin", "rb");
    // 数据块首地址: "&b", 元素大小: "sizeof(unsigned __int8)",  元素个数: "10",  文件指针："pd"
    fread(&b, sizeof(u8), 1024, pd);
    fclose(pd);
    pldm_redfish_dict_hdr_t *dicts = (pldm_redfish_dict_hdr_t *)b;
    LOG("total : %d", dicts->total_len);
    LOG("num : %d", dicts->num_of_dict);
    pldm_redfish_dict_fmt_t *dict_fmt = (pldm_redfish_dict_fmt_t *)&b[dicts->dict_info[0].offset];
    LOG("%#x", dict_fmt->dict_sign);
    LOG("%d", dict_fmt->len);
    for (u8 i = 0; i < dicts->num_of_dict; i++) {
        LOG("id : %lld", dicts->dict_info[i].resource_id);
        LOG("off : %d", dicts->dict_info[i].offset);
    }
}