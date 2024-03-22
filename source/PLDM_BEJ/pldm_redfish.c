#include "pldm_redfish.h"

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
    dict_hdr_t *dicts = (dict_hdr_t *)b;
    printf("total : %d\n", dicts->total_len);
    printf("num : %d\n", dicts->num_of_dict);
    pldm_redfish_dict_fmt_t *dict_fmt = (pldm_redfish_dict_fmt_t *)&b[dicts->dict[0].offset];
    printf("%#x\n", dict_fmt->dict_sign);
    printf("%d\n", dict_fmt->len);
    for (u8 i = 0; i < dicts->num_of_dict; i++) {
        printf("id : %lld\n", dicts->dict[i].resource_id);
        printf("off : %d\n", dicts->dict[i].offset);
    }
}