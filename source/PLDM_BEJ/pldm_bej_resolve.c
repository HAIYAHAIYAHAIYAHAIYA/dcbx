#include "pldm_bej_resolve.h"

pldm_bej_key_t key, enum_key;
u8 *fmt_err = "fmt_err";

u8 bej_buf[] = {
    0x01, 0x00, 0x00, 0x01, 0x4a, 0x01, 0x04, 0x01,
    0x21, 0x51, 0x01, 0x04, 0x25, 0x4C, 0x31, 0x30,
    0x01, 0x00, 0x10, 0x01, 0x24, 0x01, 0x02, 0x01,
    0x00, 0x00, 0x01, 0x0F, 0x01, 0x02, 0x01, 0x00,
    0x70, 0x01, 0x01, 0xFF, 0x01, 0x02, 0x40, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x01, 0x09,
    0x01, 0x01, 0x01, 0x02, 0x40, 0x01, 0x02, 0x01,
    0x00, 0x01, 0x02, 0x50, 0x01, 0x09, 0x44, 0x75,
    0x6D, 0x6D, 0x79, 0x20, 0x49, 0x44, 0x00, 0x01,
    0x06, 0x30, 0x01, 0x03, 0x0C, 0xc, 0xc
};

u8 bej_buf1[] = {
    0x01, 0x00, 0x00, 0x01, 0x48, 0x01, 0x04, 0x01,
    0x21, 0x51, 0x01, 0x04, 0x25, 0x4c, 0x31, 0x30,
    0x01, 0x00, 0x10, 0x01, 0x24, 0x01, 0x02, 0x01,
    0x00, 0x00, 0x01, 0x0f, 0x01, 0x02, 0x01, 0x00,
    0x70, 0x01, 0x01, 0xff, 0x01, 0x02, 0x40, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x01, 0x09, 
    0x01, 0x01, 0x01, 0x02, 0x40, 0x01, 0x02, 0x01,
    0x00, 0x01, 0x02, 0x50, 0x01, 0x09, 0x44, 0x75,
    0x6d, 0x6d, 0x79, 0x20, 0x49, 0x44, 0x00, 0x01,
    0x06, 0x30, 0x01, 0x01, 0x0c,
};

u8 dict0[] = {
    0x00, 0x00, 0x0B, 0x00, 0x00, 0xF0, 0xF0, 0xF1,
    0x12, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16,
    0x00, 0x04, 0x00, 0x0C, 0x7A, 0x00, 0x14, 0x00,
    0x00, 0x3E, 0x00, 0x01, 0x00, 0x13, 0x86, 0x00,
    0x56, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x99, 0x00, 0x74, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x16, 0x9C, 0x00, 0x34, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x16, 0xB2, 0x00, 0x00, 0x00,
    0x00, 0x48, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
    0xC8, 0x00, 0x46, 0x01, 0x00, 0x5C, 0x00, 0x03,
    0x00, 0x0B, 0xD7, 0x00, 0x50, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x09, 0xE2, 0x00, 0x50, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xEB, 0x00,
    0x50, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0xF2, 0x00, 0x44, 0x75, 0x6D, 0x6D, 0x79, 0x53,
    0x69, 0x6D, 0x70, 0x6C, 0x65, 0x00, 0x43, 0x68,
    0x69, 0x6C, 0x64, 0x41, 0x72, 0x72, 0x61, 0x79,
    0x50, 0x72, 0x6F, 0x70, 0x65, 0x72, 0x74, 0x79,
    0x00, 0x49, 0x64, 0x00, 0x53, 0x61, 0x6D, 0x70,
    0x6C, 0x65, 0x45, 0x6E, 0x61, 0x62, 0x6C, 0x65,
    0x64, 0x50, 0x72, 0x6F, 0x70, 0x65, 0x72, 0x74,
    0x79, 0x00, 0x53, 0x61, 0x6D, 0x70, 0x6C, 0x65,
    0x49, 0x6E, 0x74, 0x65, 0x67, 0x65, 0x72, 0x50,
    0x72, 0x6F, 0x70, 0x65, 0x72, 0x74, 0x79, 0x00,
    0x41, 0x6E, 0x6F, 0x74, 0x68, 0x65, 0x72, 0x42,
    0x6F, 0x6F, 0x6C, 0x65, 0x61, 0x6E, 0x00, 0x4C,
    0x69, 0x6E, 0x6B, 0x53, 0x74, 0x61, 0x74, 0x75,
    0x73, 0x00, 0x4C, 0x69, 0x6E, 0x6B, 0x44, 0x6F,
    0x77, 0x6E, 0x00, 0x4C, 0x69, 0x6E, 0x6B, 0x55,
    0x70, 0x00, 0x4E, 0x6F, 0x4C, 0x69, 0x6E, 0x6B,
    0x00, 0x18, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
    0x67, 0x68, 0x74, 0x20, 0x28, 0x63, 0x29, 0x20,
    0x32, 0x30, 0x31, 0x38, 0x20, 0x44, 0x4D, 0x54,
    0x46, 0x00
};

u8 dict1[] = {
    0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16,
    0x00, 0x04, 0x00, 0x0b, 0x7a, 0x00, 0x10, 0x00,
    0x00, 0x3e, 0x00, 0x01, 0x00, 0x12, 0x86, 0x00,
    0x50, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x99, 0x00, 0x70, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x15, 0x9c, 0x00, 0x30, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x15, 0xb2, 0x00, 0x00, 0x00,
    0x00, 0x48, 0x00, 0x02, 0x00, 0x00, 0xc8, 0x00,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
    0xc9, 0x00, 0x40, 0x01, 0x00, 0x5c, 0x00, 0x03,
    0x00, 0x0a, 0xd8, 0x00, 0x50, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0xe3, 0x00, 0x50, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xec, 0x00,
    0x50, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
    0xf3, 0x00, 0x44, 0x75, 0x6d, 0x6d, 0x79, 0x53,
    0x69, 0x6d, 0x70, 0x6c, 0x65, 0x00, 0x43, 0x68,
    0x69, 0x6c, 0x64, 0x41, 0x72, 0x72, 0x61, 0x79, 
    0x50, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74, 0x79,
    0x00, 0x49, 0x64, 0x00, 0x53, 0x61, 0x6d, 0x70,
    0x6c, 0x65, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65,
    0x64, 0x50, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74,
    0x79, 0x00, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65,
    0x49, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x50,
    0x72, 0x6f, 0x70, 0x65, 0x72, 0x74, 0x79, 0x00,
    0x00, 0x41, 0x6e, 0x6f, 0x74, 0x68, 0x65, 0x72,
    0x42, 0x6f, 0x6f, 0x6c, 0x65, 0x61, 0x6e, 0x00,
    0x4c, 0x69, 0x6e, 0x6b, 0x53, 0x74, 0x61, 0x74,
    0x75, 0x73, 0x00, 0x4c, 0x69, 0x6e, 0x6b, 0x44,
    0x6f, 0x77, 0x6e, 0x00, 0x4c, 0x69, 0x6e, 0x6b,
    0x55, 0x70, 0x00, 0x4e, 0x6f, 0x4c, 0x69, 0x6e,
    0x6b, 0x00, 0x0e, 0x6d, 0x61, 0x64, 0x65, 0x20,
    0x69, 0x6e, 0x20, 0x63, 0x68, 0x69, 0x6e, 0x61,
    0x00
};

// u8 *json_buf =                                                        \
//     "{                                                                \
//         \"DummySimple\" : {                                           \
//             \"@odata.id\" : \"/redfish/v1/systems/1/DummySimples/1\", \
//             \"ChildArrayProperty\" : [                                \
//                 {                                                     \
//                     \"AnotherBoolean\" : true,                        \
//                     \"LinkStatus\" : \"NoLink\"                       \
//                 },                                                    \
//                 {                                                     \
//                     \"LinkStatus\" : \"LinkDown\"                     \
//                 }                                                     \
//             ],                                                        \
//             \"Id\" : \"Dummy ID\",                                    \
//             \"SampleIntegerProperty\" : 12                            \
//         }                                                             \
//     }";

u8 *json_buf = "{\"DummySimple\":{\"@odata.id\":\"/redfish/v1/systems/1/DummySimples/1\",\"ChildArrayProperty\":[{\"AnotherBoolean\":true,\"LinkStatus\":\"NoLink\"},{\"LinkStatus\":\"LinkDown\"}],\"Id\":\"DummyID\",\"SampleIntegerProperty\":12}}";

static u16 pldm_bej_get_len(u8 *buf)
{
    u16 len = 0;
    if (buf[0] == 1) {
        len = buf[1];
    } else {
        len = buf[1];
        len <<= 8;
        len |= buf[2];
    }
    return len;
}

static u8 *pldm_bej_seq_to_nnint(u8 *buf, u8 seq)
{
    u8 *tmp = buf;
    tmp[0] = 0x01;
    tmp[1] = seq;
    tmp += 2;
    return tmp;
}

static u8 *pldm_bej_len_to_nnint(u8 *buf, u16 len)
{
    u8 *tmp = buf;
    if (len <= 0xFF) {
        tmp[0] = 0x01;
    } else {
        tmp[0] = 0x02;
    }
    memcpy(&tmp[1], &len, tmp[0]);
    tmp += tmp[0] + 1;
    return tmp;
}

static u8 *pldm_bej_sfl_to_bej(u8 *buf, pldm_cjson_t *node)
{
    u8 *tmp = buf;
    tmp = pldm_bej_seq_to_nnint(tmp, node->sflv.seq);
    tmp[0] = node->sflv.fmt;
    tmp += 1;
    tmp = pldm_bej_len_to_nnint(tmp, node->sflv.len);
    u8 fmt = node->sflv.fmt >> 4;
    if (fmt == BEJ_ARRAY || fmt == BEJ_SET) {
        u8 cnt = 0;
        tmp[0] = 0x01;
        for (pldm_cjson_t *i = node->child; i; i = i->next) {
            cnt++;
        }
        tmp[1] = cnt;
        tmp += 2;
    }
    return tmp;
}

static u8 *pldm_bej_jsonval_to_bej(u8 *buf, pldm_cjson_t *node)
{
    u8 *tmp = buf;
    u8 fmt = node->sflv.fmt >> 4;
        switch (fmt) {
            case BEJ_BOOLEAN:
                if (strcmp(node->sflv.val, "t") == 0)
                    tmp[0] = 0xFF;
                else
                    tmp[0] = 0x00;
                break;
            case BEJ_ENUM:
                memcpy(tmp, node->sflv.val, node->sflv.len);
                if (node->sflv.val[1] == 0xFF) {
                    tmp[1] = 0x00;
                }
                break;
            default:
                memcpy(tmp, node->sflv.val, node->sflv.len);
                break;
        }
        tmp += node->sflv.len;
    return tmp;
}

void pldm_bej_get_sflv(u8 *buf, pldm_bej_sflv_t *sflv)
{
    if (buf == NULL) return;
    pldm_bej_nnint_t *nnint = (pldm_bej_nnint_t *)buf;
    u8 seq_len = nnint->len;        /* always 1 */
    sflv->seq = nnint->data[0];
    nnint = (pldm_bej_nnint_t *)&nnint->data[seq_len];

    sflv->fmt = nnint->len;
    nnint = (pldm_bej_nnint_t *)nnint->data;

    sflv->len = pldm_bej_get_len((u8 *)nnint);
    nnint = (pldm_bej_nnint_t *)&nnint->data[nnint->len];

    sflv->val = (u8 *)nnint;

    sflv->sflv_len = (u8 *)nnint - buf + sflv->len;
}

static void pldm_bej_val_search(pldm_bej_sflv_t *sflv, cJSON *ptr)
{
    u8 fmt = sflv->fmt >> 4;
    // for (u8 j = 0; j < sflv->len; j++) {
    //     switch (fmt) {
    //         case BEJ_INT:
    //         printf("%d", sflv->val[0]);
    //         break;
    //         case BEJ_ENUM:
    //         // printf("0x%x ", sflv->val[j]);
    //         break;
    //         case BEJ_BOOLEAN:
    //         if (sflv->val[0] != 0) printf("true");
    //         break;
    //         default :
    //         printf("%c", sflv->val[j]);
    //         break;
    //     }
    // }
    // printf("\n");
    switch (fmt) {
        case BEJ_INT:
            cJSON_AddNumberToObject(ptr, key.val, sflv->val[0]);
            break;
        case BEJ_ENUM:
            cJSON_AddStringToObject(ptr, key.val, enum_key.val);
            break;
        case BEJ_BOOLEAN:
            if (sflv->val[0] != 0) cJSON_AddStringToObject(ptr, key.val, "true");
            else cJSON_AddStringToObject(ptr, key.val, "false");
            break;
        default :
            cJSON_AddStringToObject(ptr, key.val, sflv->val);
            // for (u8 i = 0; i < sflv->len; i++) {
            //     printf("%d %c\n", i, sflv->val[i]);
            // }
            // printf("%d %s\n", sflv->len, sflv->val);
            break;
    }
}

static void pldm_bej_val_search1(pldm_bej_sflv_t *sflv, cJSON *ptr)
{
    u8 fmt = sflv->fmt >> 4;

    switch (fmt) {
        case BEJ_INT:
        printf("%d", sflv->val[0]);
        break;
        case BEJ_ENUM:
        // printf("0x%x ", sflv->val[j]);
        break;
        case BEJ_BOOLEAN:
        if (sflv->val[0] != 0) printf("true");
        break;
        default :
        printf("%s", sflv->val);
        break;
    }
    printf("\n");
}

void pldm_bej_dict_search(pldm_bej_sflv_t *sflv, u8 *dict, pldm_redfish_dictionary_entry_t *entry, u8 entry_cnt)
{
    pldm_redfish_dictionary_entry_t *tmp = entry;
    u8 is_find = 0;
    key.len = 0;
    key.val = NULL;
    enum_key.len = 0;
    enum_key.val = NULL;
    // printf("need 0x%x, 0x%x, 0x%02x\n", sflv->fmt >> 4, sflv->seq >> 1, sflv->len);

    for (u8 k = 0; k < entry_cnt; k++) {
        u8 dict_fmt = tmp->format >> 4;
        // printf("0x%x, 0x%x\n", dict_fmt, tmp->sequence_num);
        if (dict_fmt == sflv->fmt >> 4 && tmp->sequence_num == sflv->seq >> 1) {
            key.val = &dict[tmp->name_off];
            key.len = tmp->name_len;
            // printf("%s: ", key.val);
            is_find = 1;

            if (dict_fmt == BEJ_ENUM) {
                pldm_redfish_dictionary_entry_t *enum_ptr = (pldm_redfish_dictionary_entry_t *)&dict[tmp->childpoint_off];
                enum_ptr += sflv->val[1];
                enum_key.len = enum_ptr->name_len;
                enum_key.val = &dict[enum_ptr->name_off];
                // printf("%s ", enum_key.val);
            }
            break;
        }
        tmp += 1;
    }
    if (!is_find) {
        // printf("fmt err: ");
        key.len = strlen(fmt_err);
        key.val = fmt_err;
    }
}

void pldm_bej_dict_search1(pldm_bej_sflv_t *sflv, u8 *dict)
{
    u8 is_find = 0;
    key.val = NULL;
    enum_key.val = NULL;
    pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict;
    for (u8 k = 0; k < dict_ptr->entry_cnt; k++) {
        u8 dict_fmt = dict_ptr->entry[k].format >> 4;
        if (dict_fmt == sflv->fmt >> 4 && dict_ptr->entry[k].sequence_num == sflv->seq >> 1) {
            key.val = &dict[dict_ptr->entry[k].name_off];
            key.len = dict_ptr->entry[k].name_len;
            printf("%s", key.val);
            printf(": ");
            is_find = 1;
            if (dict_fmt == BEJ_ENUM) {
                pldm_redfish_dictionary_entry_t *enum_ptr = (pldm_redfish_dictionary_entry_t *)&dict[dict_ptr->entry[k].childpoint_off];
                enum_ptr += sflv->val[1];
                enum_key.len = enum_ptr->name_len;
                enum_key.val = &dict[enum_ptr->name_off];
                printf("%s", enum_key.val);

            }
            break;
        }
    }
    if (!is_find) {
        key.len = strlen(fmt_err);
        key.val = fmt_err;
    }
}

cJSON *cjson_test = NULL;
void pldm_bej_init(void)
{
    /* 创建一个JSON数据对象(链表头结点) */
    cjson_test = cJSON_CreateObject();
    if (!cjson_test) cJSON_Delete(cjson_test);
}

u8 *pldm_bej_encode(pldm_cjson_t *root, u8 *bej_buf)
{
    if (!root || !bej_buf) return bej_buf;
    pldm_cjson_t *tmp = root;
    u8 *buf = bej_buf;
    while (tmp) {
        buf = pldm_bej_sfl_to_bej(buf, tmp);
        buf = pldm_bej_encode(tmp->child, buf);
        if (!tmp->child) {
            buf = pldm_bej_jsonval_to_bej(buf, tmp);
        }
        tmp = tmp->next;
    }
    return buf;
}

u16 pldm_bej_decode(u8 *buf, u8 *dict, pldm_redfish_dictionary_entry_t *entry, u8 entry_cnt, cJSON *root)
{
    if (!buf || !entry || !root) return 0;
    pldm_bej_sflv_t sflv = {0, 0, 0, 0, NULL};
    u8 cnt = 0;
    cJSON *ptr = root;
    cJSON *add_ptr = NULL;
    pldm_bej_get_sflv(buf, &sflv);
    pldm_bej_dict_search(&sflv, dict, entry, entry_cnt);
    u8 child_cnt = entry->child_cnt;
    u8 fmt = sflv.fmt >> 4;
    if (fmt == BEJ_SET || fmt == BEJ_ARRAY) {
        cnt = sflv.val[1];
        sflv.val = &(sflv.val[2]);
        entry = (pldm_redfish_dictionary_entry_t *)&dict[entry->childpoint_off];
        if (fmt == BEJ_SET) {
            add_ptr = cJSON_CreateObject();
        } else {
            add_ptr = cJSON_CreateArray();
        }
        if (!add_ptr) return 0;
        if (key.len)
            cJSON_AddItemToObject(ptr, key.val, add_ptr);
        else
            cJSON_AddItemToArray(ptr, add_ptr);
    }
    // printf("seq : 0x%x, fmt : 0x%x, len : 0x%x, val : %x\n", sflv.seq, fmt, sflv.len, sflv.val[0]);
    for (u8 i = 0; i < cnt; i++) {
        u16 len = pldm_bej_decode(sflv.val, dict, entry, child_cnt, add_ptr);
        sflv.val += len;
    }
    if (!cnt) {
        pldm_bej_val_search(&sflv, ptr);
    }
    return sflv.sflv_len;
}