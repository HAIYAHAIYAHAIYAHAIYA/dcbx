#include "pldm_cjson.h"
#include "pldm_bej_resolve.h"

#include "pldm_redfish.h"
#include "pldm_monitor.h"

static u8 gs_pldm_cjson_buf[MY_CJSON_POLL_SIZE];
static u8 *gs_pldm_cjson_pool;
static u16 gs_pldm_cjson_wt = 0;
u8 dict_test[1024];
u8 anno_dict_test[1024];
u8 bej_test[1024];

extern pldm_nic_composite_state_sensor_data_struct_t nic_composite_state_sensors[4];
extern pldm_controller_composite_state_sensor_data_struct_t controller_composite_state_sensors[5];
extern pldm_redfish_schema_info_t schema_info[ALL_SCHEMA_IDENTIFY];

void pldm_cjson_cal_sf_to_root(pldm_cjson_t *root, u8 *anno_dict, u8 *dict);

void pldm_cjson_pool_init(void)
{
    gs_pldm_cjson_pool = gs_pldm_cjson_buf;
    gs_pldm_cjson_wt = 0;
}

void *pldm_cjson_malloc(u16 size)
{
    size = ALIGN(size, 1);
    if (gs_pldm_cjson_wt + size >= MY_CJSON_POLL_SIZE) {
        LOG("no more space : %d", size);
        return NULL;
    }
    u8 *pt = gs_pldm_cjson_pool + gs_pldm_cjson_wt;
    gs_pldm_cjson_wt += size;
    // u8 *pt = malloc(size);
    memset((void *)pt, 0, size);
    return pt;
}

static void pldm_cjson_free(u8 *addr)
{
    if (!addr) return;
    // free(addr);
}

void pldm_cjson_delete_node(pldm_cjson_t *node)
{
    if (!node) return;
    // pldm_cjson_delete_node(node->next);
    // pldm_cjson_delete_node(node->child);
    // // LOG("\nseq : %d, fmt : 0x%02x, len : %d, name : %s : ", node->sflv.seq >> 1, node->sflv.fmt, node->sflv.len, node->name);
    // pldm_cjson_free((u8 *)node->name);
    // node->name = NULL;
    // if (node->next) node->next = NULL;
    // if (node->child) node->child = NULL;
    // pldm_cjson_free((u8 *)node);
    // node = NULL;
}

u16 pldm_cjson_get_used_space(void)
{
    return gs_pldm_cjson_wt;
}

pldm_cjson_t *pldm_cjson_create_obj(void)
{
    pldm_cjson_t *root = (pldm_cjson_t *)pldm_cjson_malloc(sizeof(pldm_cjson_t));
    if (!root) return NULL;
    return root;
}

pldm_cjson_t *pldm_cjson_create_leaf(u8 val_size)
{
    pldm_cjson_t *leaf = (pldm_cjson_t *)pldm_cjson_malloc(sizeof(pldm_cjson_t) + val_size);
    if (!leaf) return NULL;
    return leaf;
}

static pldm_cjson_t *pldm_cjson_add_child(pldm_cjson_t *parent, pldm_cjson_t *child)
{
    if (!parent || !child) return NULL;
    parent->child = child;
    return child;
}

static pldm_cjson_t *pldm_cjson_add_next(pldm_cjson_t *parent, pldm_cjson_t *next)
{
    if (!parent || !next) return NULL;
    pldm_cjson_t *tmp = parent;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = next;
    return next;
}

static pldm_cjson_t *pldm_cjson_add_sflv_attr(pldm_cjson_t *leaf, pldm_bej_sflv_dat_t *sflv, char *name, char *val, u8 val_len)
{
    if (!leaf || !sflv || !val || !name) return NULL;
    leaf->sflv = *sflv;
    leaf->sflv.val = (char *)pldm_cjson_malloc(val_len + 1);
    memcpy(leaf->sflv.val, val, val_len);
    leaf->name = (u8 *)pldm_cjson_malloc(strlen(name) + 1);
    memcpy(leaf->name, name, strlen(name));
    return leaf;
}

u16 pldm_cjson_cal_len_to_root1(pldm_cjson_t *root, u8 op_type)
{
    u16 len = 0;
    u8 seq = 0;
    pldm_cjson_t *tmp = root;
    while (tmp) {
        u8 fmt = tmp->sflv.fmt >> 4;
        tmp->sflv.seq = (seq++) << 1 | tmp->sflv.seq & 1;
        tmp->sflv.len = 0;
        if (fmt == BEJ_SET || fmt == BEJ_ARRAY)
        {
            tmp->sflv.len += 2;
        }
        if (fmt != BEJ_ENUM) tmp->sflv.len += pldm_cjson_cal_len_to_root1(tmp->child, op_type);
        if (op_type != 0) {
            if (!tmp->child && fmt != BEJ_SET && fmt != BEJ_ARRAY) {
                tmp->sflv.len = strlen(tmp->sflv.val);
                if (!(tmp->sflv.seq & 1) && fmt == BEJ_STR) tmp->sflv.len += 1;     /* major schema */
            } else {
                if (fmt == BEJ_ENUM) {
                    tmp->sflv.len = strlen(tmp->sflv.val);
                }
            }
        }
        len += tmp->sflv.len + 5;      /* sfl len */
        tmp = tmp->next;
    }
    return len;
}

void pldm_cjson_printf_root1(pldm_cjson_t *root)
{
    pldm_cjson_t *tmp = root;
    while (tmp) {
        // LOG("seq : 0x%x, fmt : 0x%x, len : %d", tmp->sflv.seq, tmp->sflv.fmt, tmp->sflv.len);
        LOG("seq : %#x, fmt : 0x%02x, len : %d, name : %s : ", tmp->sflv.seq, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
        u8 fmt = tmp->sflv.fmt >> 4;
        if (fmt != BEJ_ENUM) pldm_cjson_printf_root1(tmp->child);
        if (!tmp->child && tmp->name) {
            u8 fmt = tmp->sflv.fmt >> 4;
            for (u8 i = 0; i < tmp->sflv.len; i++) {
                switch (fmt) {
                    case BEJ_INT:
                        // LOG("0x%02x ", tmp->sflv.val[i]);
                    break;
                    case BEJ_ENUM:
                        // LOG("0x%x ", tmp->sflv.val[i]);
                    break;
                    default:
                        // LOG("%c", tmp->sflv.val[i]);
                    break;
                }
            }
        } else {
            if (fmt == BEJ_ENUM) {
                for (u8 i = 0; i < tmp->sflv.len; i++) {
                    LOG("0x%x ", tmp->sflv.val[i]);
                }
            }
        }
        tmp = tmp->next;
    }
}

u16 pldm_cjson_cal_len_to_root(pldm_cjson_t *root)
{
	if (!root) return 0;
    u16 len = 0;
    pldm_cjson_t *tmp = root;
    u8 fmt = tmp->sflv.fmt >> 4;
    tmp->sflv.len = 0;
    if (fmt == BEJ_SET || fmt == BEJ_ARRAY)
    {
        tmp->sflv.len += 2;
    }
	if (fmt != BEJ_ENUM) tmp->sflv.len += pldm_cjson_cal_len_to_root(tmp->child);
    if (!tmp->child) {
        tmp->sflv.len = strlen(tmp->sflv.val);
    } else {
        if (fmt == BEJ_ENUM) {
            tmp->sflv.len = strlen(tmp->sflv.val);
        }
    }
	len += pldm_cjson_cal_len_to_root(tmp->next) + 5 + tmp->sflv.len;
    return len;
}

void pldm_cjson_printf_root(pldm_cjson_t *root)
{
	if (!root) return;
    pldm_cjson_t *tmp = root;
	LOG("\nseq : %d, fmt : 0x%02x, len : %d, name : %s :", tmp->sflv.seq >> 1, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
    u8 fmt = tmp->sflv.fmt >> 4;
	if (fmt != BEJ_ENUM) pldm_cjson_printf_root(tmp->child);
    if (!tmp->child) {
        u8 fmt = tmp->sflv.fmt >> 4;
        for (u8 i = 0; i < tmp->sflv.len; i++) {
            switch (fmt) {
                case BEJ_INT:
                    LOG("%d", tmp->sflv.val[i]);
                break;
                default:
                    LOG("%c", tmp->sflv.val[i]);
                break;
            }
        }
    } else {
        if (fmt == BEJ_ENUM) {
            for (u8 i = 0; i < tmp->sflv.len; i++) {
                LOG("0x%x ", tmp->sflv.val[i]);
            }
        }
    }
	pldm_cjson_printf_root(tmp->next);
}

void pldm_cjson_printf_root2(pldm_cjson_t *root)
{
    pldm_cjson_t *tmp = root;
    while (tmp) {
        LOG("seq : 0x%02x, fmt : 0x%02x, len : %4d, name : %s : ", tmp->sflv.seq, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
        pldm_cjson_printf_root2(tmp->child);
        u8 fmt = tmp->sflv.fmt >> 4;
        if (!tmp->child && tmp->sflv.val && fmt != BEJ_SET && fmt != BEJ_ARRAY) {
            u8 fmt = tmp->sflv.fmt >> 4;
            for (u8 i = 0; i < tmp->sflv.len; i++) {
                switch (fmt) {
                    case BEJ_INT:
                        // printf("%d ", (u8)(tmp->sflv.val[i]));
                        break;
                    case BEJ_ENUM:
                        // printf("0x%02x ", tmp->sflv.val[i]);
                        break;
                    default:
                        // printf("%c", tmp->sflv.val[i]);
                        break;
                }
            }
            printf("\n");
        }
        tmp = tmp->next;
    }
}

u16 pldm_cjson_cal_len_to_root2(pldm_cjson_t *root, u8 op_type)
{
    u16 len = 0;
    pldm_cjson_t *tmp = root;
    while (tmp) {
        u8 fmt = tmp->sflv.fmt >> 4;
        tmp->sflv.len = 0;
        if (fmt == BEJ_SET || fmt == BEJ_ARRAY)
        {
            tmp->sflv.len += 2;
        }
        tmp->sflv.len += pldm_cjson_cal_len_to_root2(tmp->child, op_type);
        if (op_type != HEAD) {
            if (!(tmp->child) && fmt != BEJ_SET && fmt != BEJ_ARRAY) {
                // if (tmp->name) LOG("seq : %#x, fmt : 0x%02x, len : %d, name : %s : ", tmp->sflv.seq, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
                tmp->sflv.len = cm_strlen(tmp->sflv.val);
                if (!(tmp->sflv.seq & 1) && fmt == BEJ_STR) tmp->sflv.len += 1;     /* major schema */
            }
        }
        len += tmp->sflv.len + 5;      /* sfl len */
        if (tmp->sflv.len > 0xFF)
            len += 1;
        tmp = tmp->next;
    }
    return len;
}

u8 is_replace = 0;
void pldm_cjson_replace_val(pldm_cjson_t *root, pldm_bej_sflv_dat_t *sflv, char *replace_val)
{
    is_replace = 0;
    if (!root || !sflv || !replace_val) return;
    pldm_cjson_t *tmp = root;
    while (tmp) {
        u8 fmt = tmp->sflv.fmt >> 4;
        if (tmp->child) {
            if (fmt == BEJ_ENUM) {
                if (tmp->sflv.fmt == sflv->fmt && tmp->sflv.seq == sflv->seq) {
                    u8 len = strlen(replace_val);
                    memcpy(tmp->sflv.val, replace_val, len);
                    tmp->sflv.val[len] = '\0';
                    is_replace = 1;
                }
            } else {
                pldm_cjson_replace_val(tmp->child, sflv, replace_val);
            }
        } else {
            if (tmp->sflv.fmt == sflv->fmt && tmp->sflv.seq == sflv->seq) {
                u8 len = strlen(replace_val);
                memcpy(tmp->sflv.val, replace_val, len);
                tmp->sflv.val[len] = '\0';
                is_replace = 1;
            }
        }
        if (is_replace) {
            break;
        }
        tmp = tmp->next;
    }
}

pldm_cjson_t *is_find = NULL;
void pldm_cjson_find_name(pldm_cjson_t *root, char *name)
{
    if (!root || !name) return;
    pldm_cjson_t *tmp = root;
    while (tmp) {
        if (strcmp(tmp->name, name) == 0) {
            is_find = tmp;
            return;
        }
        if (tmp->child) {
            pldm_cjson_find_name(tmp->child, name);
        }
        if (is_find) {
            break;
        }
        tmp = tmp->next;
    }
}

void pldm_cjson_replace_enum_val(pldm_cjson_t *root, pldm_bej_sflv_dat_t *sflv, char *enum_name, char *enum_val)
{
    if (!root || !sflv || !enum_name || !enum_val) return;
    is_find = NULL;
    pldm_cjson_find_name(root, enum_name);
    if (is_find) {
        u8 idx = 0;
        for (is_find = is_find->child; is_find; is_find = is_find->next) {
            if (strcmp(is_find->name, enum_val) == 0) {
                char str[] = {0x01, 0x00, 0x00};
                if (!idx) {
                    str[1] = 'U';
                } else {
                    str[1] = idx;
                }
                pldm_cjson_replace_val(root, sflv, str);
                pldm_cjson_cal_len_to_root1(root, 'U');
                break;
            }
            idx++;
        }
    }
}

/* skip and top param only for collection schema */
int pldm_cjson_read(pldm_cjson_t *root, u16 collection_skip, u16 collection_top)
{
    if (!root) return -1;
    if (collection_skip == 0 && collection_top == 0xFFFF) return 0;
    is_find = NULL;
    pldm_cjson_find_name(root, "Members");
    if (is_find) {
        if (collection_top == 0 || collection_skip >= MAX_LAN_NUM) {
            /* empty list */
            is_find->child = NULL;
            return 0;
        }
        pldm_cjson_t *start_member = is_find->child;
        pldm_cjson_t *end_member = NULL;
        is_find->child = NULL;
        for (u8 i = 0; i < collection_skip; i++) {
            if (start_member->next)
                start_member = start_member->next;
        }
        is_find->child = start_member;
        end_member = start_member;

        /* If the parameter for $top  exceeds the remaining number of members in a resource collection, the number returned shall be 
            truncated to those remaining. */
        u8 cnt = MIN((MAX_LAN_NUM - collection_skip), collection_top);

        for (u8 i = 0; i < cnt; i++) {
            if ( i != (cnt - 1)) {
                if (end_member->next)
                    end_member = end_member->next;
            } else {
                end_member->next = NULL;
            }

        }
    }
    return 0;
}

void pldm_cjson_update_op(pldm_cjson_t *start_node, pldm_cjson_t *update_node)
{
    pldm_cjson_t *ori_node = start_node;
    pldm_cjson_t *new_node = update_node;
    while (ori_node && new_node) {
        pldm_cjson_update_op(ori_node->child, new_node->child);
        if (cm_strcmp(ori_node->name, new_node->name) == 0) {
            u8 ori_val_len = cm_strlen(ori_node->sflv.val);
            u8 new_val_len = cm_strlen(new_node->sflv.val);
            if (ori_val_len >= new_val_len)
                ori_node->sflv.val[new_val_len] = '\0';
            else
                ori_node->sflv.val = pldm_cjson_malloc(new_val_len + 1);
            cm_memcpy(ori_node->sflv.val, new_node->sflv.val, new_val_len);
        }
        if (ori_node->next)
            ori_node = ori_node->next;
        if (new_node->next)
            new_node = new_node->next;
        else
            break;
    }
}

int pldm_cjson_update(pldm_cjson_t *root, pldm_cjson_t *update_node)
{
    if (!root || !update_node) return -1;
    is_find = NULL;
    pldm_cjson_find_name(root, "Members");
    if (is_find)
        return -1;
    is_find = NULL;
    pldm_cjson_find_name(root, update_node->name);
    if (is_find) {
        pldm_cjson_update_op(is_find, update_node);
        return 0;
    }
    return -1;
}

int pldm_cjson_replace(pldm_cjson_t *root, pldm_cjson_t *replace_node)
{
    if (!root || !replace_node) return -1;
    cm_memcpy(root, replace_node, sizeof(pldm_cjson_t));
    // pldm_cjson_delete_node(root);
    return 0;
}

/* to be determind */
int pldm_cjson_action(pldm_cjson_t *root)
{
    if (!root) return -1;
    is_find = NULL;
    pldm_cjson_find_name(root, "Actions");
    if (is_find) {
        /* Do action */
        return 0;
    }
    return -1;
}

/* to be determind */
int pldm_cjson_head(pldm_cjson_t *root)
{
    if (!root) return -1;
    return 0;
}

static pldm_cjson_t *pldm_cjson_add_obj_attr(pldm_cjson_t *leaf, pldm_bej_sflv_dat_t *sflv, char *name)
{
    if (!leaf || !sflv || !name) return NULL;
    leaf->sflv = *sflv;
    leaf->name = (u8 *)pldm_cjson_malloc(strlen(name) + 1);
    memcpy(leaf->name, name, strlen(name));
    return leaf;
}

pldm_cjson_t *pldm_cjson_add_obj(pldm_cjson_t *parent, pldm_bej_sflv_dat_t *sflv, char *name)
{
    if (!parent || !sflv) return NULL;
    pldm_cjson_t *obj = NULL;
    u8 fmt = sflv->fmt >> 4;
    if (fmt == BEJ_SET || fmt == BEJ_ARRAY) obj = pldm_cjson_create_leaf(1);
    else obj = pldm_cjson_create_leaf(32);

    pldm_cjson_add_obj_attr(obj, sflv, name);
    pldm_cjson_add_child(parent, obj);
    return obj;
}

pldm_cjson_t *pldm_cjson_add_item_to_obj(pldm_cjson_t *obj, pldm_bej_sflv_dat_t *sflv, char *name, char *val, u8 len)
{
    if (!obj || !sflv || !name || !val) return NULL;
    // char str[3] = {0, 0, 0};
    // u16 num = 0;
    // u8 fmt = sflv->fmt >> 4;
    // switch (fmt) {
    //     case BEJ_BOOLEAN:
    //     if (strcmp(val, "true") == 0) {
    //         str[0] = 0x74;      /* 't' */
    //     } else {
    //         str[0] = 0x66;      /* 'f' */
    //     }
    //     val = str;
    //     break;
        // case BEJ_INT:
        // num = atoi(val);
        // if (num <= 'U') {
        //     str[0] = num;
        // } else {
        //     str[0] = num & 'U';
        //     str[1] = num >> 8;
        // }
        // val = str;
        // break;
    // }

    pldm_cjson_t *item = pldm_cjson_create_leaf(len + 1);
    pldm_cjson_add_sflv_attr(item, sflv, name, val, len);
    if (!(obj->child)) {
        pldm_cjson_add_child(obj, item);
    } else {
        pldm_cjson_add_next(obj->child, item);
    }
    return item;
}

void pldm_cjson_add_enum_to_obj(pldm_cjson_t *obj, u8 *dictionary, pldm_bej_sflv_dat_t *sflv, char *enum_name, char *enum_val)
{
    if (!obj || !sflv || !enum_name || !enum_val) return;
    if ((strcmp("", enum_val) == 0)) {
        pldm_cjson_add_item_to_obj(obj, sflv, enum_name, "", 0);
        return;
    }
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    for (u8 i = 0; i < dict->entry_cnt; i++) {
        u8 *name = &dictionary[dict->entry[i].name_off];
        if (strcmp(name, enum_name) == 0) {
            pldm_redfish_dictionary_entry_t *entry = (pldm_redfish_dictionary_entry_t *)&dictionary[dict->entry[i].childpoint_off];
            for (u8 j = 0; j < dict->entry[i].child_cnt; j++) {
                name = &dictionary[entry->name_off];
                if (strcmp(name, enum_val) == 0) {
                    char str[] = {0x01, 0x00, 0x00};
                    if (!j) {
                        str[1] = 'U';
                    } else {
                        str[1] = j;
                    }
                    pldm_cjson_add_item_to_obj(obj, sflv, enum_name, str, strlen(str));
                    break;
                }
                entry++;
            }
            break;
        }
    }
}

void pldm_cjson_fill_dict_hdr(u8 *dictionary)
{
    if (!dictionary) return;
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    dict->version_tag = 0;       /* 0x00 for DSP0218 v1.0.0, v1.1.0, v1.1.1 */
    /* bit0 : truncation_flag; if 1b, the dictionary is truncated and provides entries for a subset of the full Redfish schema */
    dict->dictionay_flags = 0;
    // dict->schema_version = 0;
}

void pldm_cjson_fill_dict_str(pldm_cjson_t *root, u8 *dictionary, u8 is_anno_dict)
{
	if (!root || !dictionary) return;

	pldm_cjson_t *queue[64];
    pldm_cjson_t *q = NULL;

    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    u8 *dict_name = (u8 *)&(dict->entry[dict->entry_cnt]);
	//front作为输出索引，rear作为存储索引
	int front = -1, rear = -1;
    int have_child = -1;
    u16 offset = 0;
    u8 entry_cnt = 0;
    u8 is_same = 0;

    for (; root; root = root->next) {
        queue[++rear] = root;
    }
    have_child = front;
	while (front != rear)
	{
		q = queue[++front];
        // LOG("seq : %d, fmt : %d, len : %d, name : %s", q->sflv.seq, q->sflv.fmt, q->sflv.len, q->name);
        u8 state = (is_anno_dict && q->sflv.seq & 1) || (!is_anno_dict && !(q->sflv.seq & 1));
        if (state) {
            u8 fmt = dict->entry[entry_cnt].format >> 4;
            if (fmt == q->sflv.fmt >> 4 && dict->entry[entry_cnt].sequence_num == q->sflv.seq >> 1) {
                is_same = 0;
                for (u8 i = 0; i < entry_cnt; i++) {
                    if (strcmp(&dictionary[dict->entry[i].name_off], q->name) == 0) {
                        dict->entry[entry_cnt].name_off = dict->entry[i].name_off;
                        is_same = 1;
                        break;
                    }
                }
                if (!is_same) {
                    u8 *name = q->name;
                    if (strlen(name)) {
                        memcpy(dict_name + offset, name, strlen(name) + 1);   /* terminal is '\0' */
                        dict->entry[entry_cnt].name_off = (dict_name - dictionary) + offset;
                        offset += strlen(name) + 1;
                    } else {
                        dict->entry[entry_cnt].name_off = 0;
                    }
                }
                entry_cnt++;
                // LOG("\n%s %d", name, entry_cnt);
            }
        }

        if (front == rear) {
            u8 cnt = rear - have_child;
            // LOG("cnt : %d", cnt);
            for (u8 i = 0; i < cnt; i++) {
                pldm_cjson_t *tmp = queue[have_child + i + 1];
                if (tmp->child) {
                    for (pldm_cjson_t *tmp1 = tmp->child; tmp1; tmp1 = tmp1->next) {
                        queue[++rear] = tmp1;
                    }
                }
            }
            have_child = front;
        }
	}
}

void pldm_cjson_fill_dict_entry_data(pldm_cjson_t *root, u8 *dictionary, u8 is_anno_dict)
{
	if (!root || !dictionary) return;

	pldm_cjson_t *queue[64];
    pldm_cjson_t *q = NULL;
	//front作为输出索引，rear作为存储索引
	int front = -1, rear = -1;
    int have_child = -1;
    u8 entry_cnt = 0;
    u8 is_same = 0;

    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;

    // if (is_anno_dict) entry_cnt = dict->entry_cnt;

    for (; root; root = root->next) {
        queue[++rear] = root;
    }
    have_child = front;
	while (front != rear)
	{
		q = queue[++front];
		// LOG("seq : %d, fmt : %d, len : %d, name : %s", q->sflv.seq >> 1, q->sflv.fmt, q->sflv.len, q->name);
        u8 state = (is_anno_dict && q->sflv.seq & 1) || (!is_anno_dict && !(q->sflv.seq & 1));
        if (state) {
            is_same = 0;
            for (u8 i = 0; i < front; i++) {
                u8 fmt = queue[i]->sflv.fmt >> 4;
                if ((strcmp(queue[i]->name, q->name) == 0) && (fmt == q->sflv.fmt >> 4) && (queue[i]->sflv.seq == q->sflv.seq)) {
                    is_same = 1;
                    break;
                }
            }
            if (!is_same) {
                u8 *name = q->name;
                dict->entry[entry_cnt].format = q->sflv.fmt;
                dict->entry[entry_cnt].sequence_num = (q->sflv.seq >> 1);
                dict->entry[entry_cnt].name_len = strlen(name);
                entry_cnt++;
            }
        }
        if (front == rear) {
            u8 cnt = rear - have_child;
            // LOG("cnt : %d", cnt);
            for (u8 i = 0; i < cnt; i++) {
                pldm_cjson_t *tmp = queue[have_child + i + 1];
                if (tmp->child) {
                    for (pldm_cjson_t *tmp1 = tmp->child; tmp1; tmp1 = tmp1->next) {
                        queue[++rear] = tmp1;
                    }
                }
            }
            have_child = front;
        }
	}
    dict->entry_cnt = entry_cnt;
    // LOG("entry cnt : %d", entry_cnt);
}

void pldm_cjson_fill_dict_child(pldm_cjson_t *root, u8 *dictionary)
{
	if (!root || !dictionary) return;
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    pldm_cjson_t *queue[64];
	//front作为输出索引，rear作为存储索引
	int front = -1, rear = -1;
    int have_child = -1;
    u8 child_cnt = 0;
    u8 i = 0;

    for (; root; root = root->next) {
        queue[++rear] = root;
    }
    have_child = front;
	while (front != rear)
	{
		++front;
        // LOG("%d, %s", queue[front]->sflv.seq >> 1, queue[front]->name);
		// LOG("seq : %d, fmt : %d, len : %d, name : %s", queue[front]->sflv.seq, queue[front]->sflv.fmt, queue[front]->sflv.len, queue[front]->name);
        if (front == rear) {
            u8 cnt = rear - have_child;
            // LOG("cnt : %d", cnt);
            for (u8 k = 0; k < cnt; k++) {
                pldm_cjson_t *tmp = queue[have_child + k + 1];
                if (tmp->child) {
                    for (; i < dict->entry_cnt; i++) {
                        if (strcmp((char *)&dictionary[dict->entry[i].name_off], tmp->name) == 0) {
                            break;
                        }
                    }
                    for (u16 j = i; j < dict->entry_cnt; j++) {
                        // LOG("\nname : %s %s", &dictionary[dict->entry[j].name_off], tmp->child->name);
                        if (strcmp((char *)&dictionary[dict->entry[j].name_off], tmp->child->name) == 0) {
                            dict->entry[i].childpoint_off = (u8 *)&(dict->entry[j]) - dictionary;
                            break;
                        }
                    }
                    child_cnt = 0;
                    for (pldm_cjson_t *tmp1 = tmp->child; tmp1; tmp1 = tmp1->next) {
                        queue[++rear] = tmp1;
                        child_cnt++;
                    }
                    if (i < dict->entry_cnt) {
                        dict->entry[i].child_cnt = child_cnt;
                        i++;
                    }
                }
            }
            have_child = front;
        }
	}
    // for (u8 k = 0; k < dict->entry_cnt; k++) {
    //     pldm_redfish_dictionary_entry_t *entry = (pldm_redfish_dictionary_entry_t *)&dictionary[dict->entry[k].childpoint_off];
    //     LOG("child_cnt : %d, child_off : %s, name : %s", dict->entry[k].child_cnt, &dictionary[entry->name_off], &dictionary[dict->entry[k].name_off]);
    // }
}

void pldm_cjson_fill_dict_copyright(u8 *dictionary, char *copyright_name)
{
    if (!dictionary || !copyright_name) return;
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    pldm_redfish_dictionary_copyright_t *copyright;
    if (dict->entry_cnt) {
        u16 name_total_len = 0;
        for (u16 i = 0; i < dict->entry_cnt; i++) {
            name_total_len += dict->entry[i].name_len + 1;
        }
        copyright = (pldm_redfish_dictionary_copyright_t *)(((u8 *)&(dict->entry[dict->entry_cnt])) + name_total_len);
    } else {
        copyright = (pldm_redfish_dictionary_copyright_t *)&(dictionary[sizeof(pldm_redfish_dictionary_format_t)]);
    }

    copyright->copyright_len = strlen(copyright_name) + 1;
    memcpy(copyright->copyright, copyright_name, copyright->copyright_len);
    dict->dictionary_size = copyright->copyright + copyright->copyright_len - dictionary;
    // LOG("entry_cnt : %d", dict->entry_cnt);
}

void pldm_cjson_printf_dict(u8 *dictionary)
{
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    LOG("\nversion_tag : %d", dict->version_tag);
    LOG("schema_version : %x", dict->schema_version);
    LOG("entry_cnt : %d", dict->entry_cnt);
    LOG("dictionay_flags : %d", dict->dictionay_flags);
    LOG("dictionary_size : %d", dict->dictionary_size);
    for (u16 i = 0; i < dict->entry_cnt; i++) {
        printf("child_cnt : %d, seq : %d, fmt : %d name : ", dict->entry[i].child_cnt, dict->entry[i].sequence_num, dict->entry[i].format >> 4);
        for (u16 j = 0; j < dict->entry[i].name_len; j++) {
            u8 *name = &dictionary[dict->entry[i].name_off];
            printf("%c", name[j]);
        }
        printf(" name off : %d, child off : %d, offset : %d" , dict->entry[i].name_off, dict->entry[i].childpoint_off, (u8 *)&(dict->entry[i]) - dictionary);
        printf("\n");
    }
    pldm_redfish_dictionary_copyright_t *copyright;
    u16 name_total_len = 0;
    if (dict->entry_cnt) {
        for (u16 i = 0; i < dict->entry_cnt; i++) {
            name_total_len += dict->entry[i].name_len + 1;
        }
        copyright = (pldm_redfish_dictionary_copyright_t *)(((u8 *)&(dict->entry[dict->entry_cnt])) + name_total_len);
    } else {
        copyright = (pldm_redfish_dictionary_copyright_t *)&(dictionary[sizeof(pldm_redfish_dictionary_format_t)]);
    }
    printf("name_total_len : %d, copyright len : %d, copyright : %s", name_total_len, copyright->copyright_len, copyright->copyright);
    // for (u16 i = 0; i < dict->dictionary_size; i++) {
    //     LOG("0x%02x, ", dictionary[i]);
    //     if (!((i + 1) % 8)) {
    //         LOG("\n");
    //     }
    // }
}

void pldm_cjson_create_dict(pldm_cjson_t *root, u8 *dictionary, u8 is_anno_dict)
{
    if (!root || !dictionary) return;
    // pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    pldm_cjson_fill_dict_hdr(dictionary);
    pldm_cjson_fill_dict_entry_data(root, dictionary, is_anno_dict);
    pldm_cjson_fill_dict_str(root, dictionary, is_anno_dict);
    pldm_cjson_fill_dict_child(root, dictionary);
    pldm_cjson_fill_dict_copyright(dictionary, "Copyright 2014-2023 DMTF");
    // pldm_cjson_fill_dict_copyright(root, dictionary, "made in china");
    pldm_cjson_printf_dict(dictionary);
}

void pldm_cjson_fill_anno_dict_entry_data(pldm_cjson_t *root, u8 *dictionary, u8 *name_buf, u16 *name_off)
{
	if (!root || !dictionary) return;

	pldm_cjson_t *queue[64];
    pldm_cjson_t *q = NULL;
	//front作为输出索引，rear作为存储索引
	int front = -1, rear = -1;
    int have_child = -1;
    u8 entry_cnt = 0;

    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;

    entry_cnt = dict->entry_cnt;

    for (; root; root = root->next) {
        queue[++rear] = root;
    }
    have_child = front;
	while (front != rear)
	{
		q = queue[++front];
		// LOG("seq : %d, fmt : %d, len : %d, name : %s", q->sflv.seq >> 1, q->sflv.fmt, q->sflv.len, q->name);
        if (q->sflv.seq & 1) {
            u8 is_same = 0;
            u8 used_name_idx = 0;
            for (u8 i = 0; i < strlen(q->name); i++) {
                if (q->name[i] == '@') {
                    used_name_idx = i;
                    break;
                }
            }
            for (u8 i = 0; i < entry_cnt; i++) {
                if ((strcmp(&name_buf[dict->entry[i].name_off], &(q->name[used_name_idx])) == 0)) {
                    is_same = 1;
                    break;
                }
            }
            if (!is_same) {
                u8 *name = &(q->name[used_name_idx]);
                dict->entry[entry_cnt].format = q->sflv.fmt;
                dict->entry[entry_cnt].sequence_num = (q->sflv.seq >> 1);
                dict->entry[entry_cnt].name_len = strlen(name);
                memcpy(name_buf + *name_off, name, dict->entry[entry_cnt].name_len + 1);
                dict->entry[entry_cnt].name_off = *name_off;
                *name_off += dict->entry[entry_cnt].name_len + 1;
                entry_cnt++;
            }
        }

        if (front == rear) {
            u8 cnt = rear - have_child;
            // LOG("cnt : %d", cnt);
            for (u8 i = 0; i < cnt; i++) {
                pldm_cjson_t *tmp = queue[have_child + i + 1];
                if (tmp->child) {
                    for (pldm_cjson_t *tmp1 = tmp->child; tmp1; tmp1 = tmp1->next) {
                        queue[++rear] = tmp1;
                    }
                }
            }
            have_child = front;
        }
	}
    dict->entry_cnt = entry_cnt;
    // LOG("entry cnt : %d", entry_cnt);
}

void pldm_cjson_create_anno_dict(pldm_cjson_t *root, u8 *dictionary, u8 root_cnt, u8 step)
{
    if (!root || !dictionary) return;
    u8 name_buf[1024];
    u16 name_off = 0;

    pldm_cjson_fill_dict_hdr(dictionary);

    pldm_cjson_fill_anno_dict_entry_data(root, dictionary, name_buf, &name_off);
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    u8 *dict_name = (u8 *)&(dict->entry[dict->entry_cnt]);
    u16 offset = dict_name - dictionary;
    for (u8 i= 0; i < dict->entry_cnt; i++) {
        dict->entry[i].name_off += offset;
        dict->entry[i].sequence_num = i;
    }
    memcpy(dict_name, name_buf, name_off);
    pldm_cjson_printf_dict(dictionary);
}

extern u8 dict0[];
extern u8 dict1[];
extern u8 *json_buf;
extern u8 bej_buf[];
extern u8 bej_buf1[];

extern u32 crc32_pldm_section(u32 init_crc, u8 *data, u32 len);
static void pldm_cjson_update_etag_op(pldm_cjson_t *root, u32 *etag)
{
    pldm_cjson_t *tmp = root;
    while (tmp) {
        u8 fmt = tmp->sflv.fmt >> 4;
        char *val = tmp->sflv.val;
        if (cm_strcmp(tmp->name, "@odata.etag") == 0) val = "etag";
        *etag = crc32_pldm_section(*etag ^ 0xFFFFFFFFUL, (u8 *)tmp->name, strlen(tmp->name));
        pldm_cjson_update_etag_op(tmp->child, etag);
        if (!(tmp->child) && fmt != BEJ_SET && fmt != BEJ_ARRAY) {
            *etag = crc32_pldm_section(*etag ^ 0xFFFFFFFFUL, (u8 *)val, strlen(val));
        }
        tmp = tmp->next;
    }
}

void pldm_cjson_update_etag(pldm_cjson_t *root)
{
    u32 etag = 0;
    char etag_str[12];
    pldm_cjson_t *tmp = root;
    pldm_cjson_update_etag_op(tmp, &etag);
    cm_snprintf(etag_str, 12, "%x", etag);
    tmp = root->child;
    while (tmp) {
        if (cm_strcmp(tmp->name, "@odata.etag") == 0) {
            cm_memcpy(tmp->sflv.val, etag_str, 8);
            LOG("etag : %s", tmp->sflv.val);
            break;
        }
        tmp = tmp->next;
    }
    LOG("etag : %#x", etag);
}

void pldm_cjson_fill_comm_field_in_schema(pldm_cjson_t *root, u8 is_collection, u32 id, char *type, u8 resource_identify)
{
    char str[16];
    char uri[128];
    char *schema_uri_prefix = "https://redfish.dmtf.org/schemas/";
    // memset(str, 0, cm_strlen(str));
    pldm_bej_sflv_dat_t sflv;
    str[0] = '%';
    str[1] = 'I';
    cm_snprintf(&str[2], 14, "%d", id);

    u8 uri_prefix_len = cm_strlen(schema_uri_prefix);
    u8 uri_suffix_len = cm_strlen(schema_info[resource_identify].uri[SCHEMACLASS_MAJOR]);
    cm_memcpy(uri, schema_uri_prefix, uri_prefix_len);
    cm_memcpy(&(uri[uri_prefix_len]), &(schema_info[resource_identify].uri[SCHEMACLASS_MAJOR]), uri_suffix_len);
    uri[uri_prefix_len + uri_suffix_len] = '\0';

    char *key[6] = {
        "@odata.id",                        /* Returns bejResourceLink encoded resource ID. */
        "@odata.type",
        "@odata.etag",
        "@odata.context",
        "Status",
        "Status"
    };

    /* Normal = “OK” */
    char *healthrollupdescription = "OK";
    char *healthrollup = "OK";

    /* If the Card Composite State Sensor (sensorID = 5) is 
    uninitialized, Network Controller State sensor
    (sensorID = 50) shall be used instead. If this sensor 
    too is uninitialized, the operation fails. */

    pldm_state_data_struct_t *state_data = NULL;
    if (nic_composite_state_sensors[0].op_state == PLDM_OP_ENABLE) {
        state_data = &nic_composite_state_sensors[0];
    } else if (controller_composite_state_sensors[0].op_state == PLDM_OP_ENABLE) {
        state_data = &controller_composite_state_sensors[0];
    } else {
        LOG("all state sensor uninitialized, the operation fails.");
    }
    char enum_str[3];
    enum_str[0] = 0x01;
    enum_str[1] = 0x01;
    enum_str[2] = 0x00;
    if (state_data) {
        switch (state_data->present_state) {
            case UPPER_NON_CRITICAL:
                enum_str[1] = 0x02;
                break;
            case UPPER_CRITICAL:
                enum_str[1] = 'U';
                break;
            case FATAL:
                enum_str[1] = 'U';
                break;
            default :
            break;
        }
    }
    healthrollupdescription = enum_str;
    healthrollup = enum_str;

    char *val[6] = {str, type, "etagetag", uri, healthrollupdescription, healthrollup};
    u8 cnt = is_collection ? 4 : 6;
    for (u8 i = 0; i < cnt; i++) {
        if (i < 4) {
            sflv.seq = 1;
            sflv.fmt = BEJ_STR << 4;
            pldm_cjson_add_item_to_obj(root, &sflv, key[i], val[i], cm_strlen(val[i]));
        } else {
            sflv.seq = 0;
            sflv.fmt = BEJ_SET << 4;
            pldm_cjson_t *tmp = pldm_cjson_add_item_to_obj(root, &sflv, key[i], "", 0);
            sflv.fmt = BEJ_ENUM << 4;
            pldm_cjson_add_item_to_obj(tmp, &sflv, "HealthRollup", val[i], 2);
        }
    }
}

/* recursion */
static pldm_cjson_schema_fmt_t *pldm_cjson_create_schema_recursion(pldm_cjson_t *obj, pldm_cjson_schema_fmt_t *fmt)
{
    if (!obj || !fmt)  return NULL;
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_t *tmp = obj;
    pldm_cjson_t *tmp1 = NULL;
    pldm_cjson_schema_fmt_t *buf = fmt;
    u8 cnt = 0;
    sflv.seq = buf[0].schema_type;
    sflv.fmt = buf[0].fmt << 4;
    // LOG("fmt : %d, cnt : %d\n", buf[0].fmt, buf[0].child_cnt);
    if (buf[0].fmt == BEJ_SET || buf[0].fmt == BEJ_ARRAY) {
        cnt = buf[0].child_cnt;
        // LOG("name : %s\n", tmp->name);
        tmp1 = pldm_cjson_add_item_to_obj(tmp, &sflv, buf->key, "", 0);
        buf += 1;
    }
    for (u8 i = 0; i < cnt; i++) {
        buf = pldm_cjson_create_schema_recursion(tmp1, buf);
        // LOG("cnt %d\n", len);
    }
    if (!cnt && BEJ_SET != sflv.fmt >> 4 && BEJ_ARRAY != sflv.fmt >> 4) {
        pldm_cjson_add_item_to_obj(tmp, &sflv, buf->key, buf->val, cm_strlen(buf->val));
        buf += 1;
    }
    return buf;
}

typedef struct {
    u8 child_cnt;
    pldm_cjson_t *node;
} pldm_cjson_create_schema_1_t;

static void pldm_cjson_create_schema(pldm_cjson_t *obj, pldm_cjson_schema_fmt_t *fmt, u8 len)
{
    if (!obj || !fmt)  return;
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_schema_fmt_t *buf = fmt;
    pldm_cjson_t *tmp = obj;
    pldm_cjson_create_schema_1_t schemas[8];
    int idx = -1;
    schemas[0].node = tmp;

    for (u8 i = 0; i < len; ++i) {
        sflv.seq = buf[i].schema_type;
        sflv.fmt = buf[i].fmt << 4;
        if (buf[i].fmt == BEJ_SET || buf[i].fmt == BEJ_ARRAY) {
            idx++;
            schemas[idx].child_cnt = buf[i].child_cnt;
            schemas[idx].node = pldm_cjson_add_item_to_obj(schemas[idx ? idx - 1 : idx].node, &sflv, buf[i].key, "", 0);
            schemas[idx ? idx - 1 : idx].child_cnt--;
        } else {
            pldm_cjson_add_item_to_obj(schemas[idx].node, &sflv, buf[i].key, buf[i].val, cm_strlen(buf[i].val));
            schemas[idx].child_cnt--;
        }
        if (idx > 0) {
            if (schemas[idx].child_cnt == 0) {
                for (u8 j = idx - 1; j > 0; j--) {
                    if (schemas[idx - 1].child_cnt == 0) {
                        idx--;
                    }
                }
                idx--;
            }
        }
    }
}

pldm_cjson_t *pldm_cjson_create_event_schema(u32 resource_id, u8 link_state)
{
    char str[8];
    cm_snprintf(str, 8, "%d", resource_id);
    u8 strlen_len = cm_strlen(str);
    str[strlen_len] = '\0';
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 4, "Event", ""},
            {0, BEJ_ARRAY, 1, "Events", ""},
                {0, BEJ_SET, 5, "", ""},
                    {0, BEJ_ENUM, 0, "EventType", (char [3]){0x01, 0x04, 0x00}},
                        // {0, BEJ_STR, 0, "StatusChange", ""},
                        // {0, BEJ_STR, 0, "ResourceUpdated", ""},
                        // {0, BEJ_STR, 0, "ResourceAdded", ""},
                        // {0, BEJ_STR, 0, "ResourceRemoved", ""},
                        // {0, BEJ_STR, 0, "Alert", ""},
                    {0, BEJ_STR, 0, "MemberId", "0"},                   /* Event member element ID within the Events array. */
                    {0, BEJ_ARRAY, 1, "MessageArgs", ""},               /* Array of strings containing the arguments needed for the Registry message */
                        {0, BEJ_STR, 0, "", ""},
                    {0, BEJ_STR, 0, "MessageId", "NetworkDevice.1.0.1."},
                    {0, BEJ_SET, 1, "OriginOfCondition", ""},
                        {1, BEJ_STR, 0, "@odata.id", str},                     /* Reference to related triggering resource. */
            {1, BEJ_INT, 0, "Events@odata.count", (char [2]){0x01, 0x00}},
            {0, BEJ_STR, 0, "Id", "1"},
            {0, BEJ_STR, 0, "Name", "Event"},
    };

    if (link_state) {
        fmt[7].val = "NetworkDevice.1.0.1.ConnectionEstablished";
    } else {
        fmt[7].val = "NetworkDevice.1.0.1.ConnectionDropped";
    }

    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root, 0, resource_id, "Event.1_0_2.Event", EVENT);
    // pldm_cjson_cal_sf_to_root(new_root, anno_dict, dict);
    return new_root;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_port_v1_3_1_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 14, "Port", ""},
                {0, BEJ_SET, 2, "Actions", ""},
                    {0, BEJ_SET, 2, "#Port.Reset", ""},
                        {0, BEJ_STR, 0, "target", "%T10.0"},
                        {0, BEJ_STR, 0, "title", "#Port.Reset"},
                    {0, BEJ_SET, 1, "#Port.ResetPPB", ""},
                        {0, BEJ_STR, 0, "title", "#Port.Reset"},
                {0, BEJ_INT, 0, "CurrentSpeedGbps", (char [3]){0x01, 0x20, 0x00}},
                {0, BEJ_SET, 3, "Ethernet", ""},
                    {0, BEJ_ENUM, 0, "FlowControlConfiguration", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "TX", ""},
                        // {0, BEJ_STR, 0, "RX", ""},
                        // {0, BEJ_STR, 0, "TX_RX", ""},
                    {0, BEJ_ENUM, 0, "FlowControlStatus", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "TX", ""},
                        // {0, BEJ_STR, 0, "RX", ""},
                        // {0, BEJ_STR, 0, "TX_RX", ""},
                    {0, BEJ_ARRAY, 1, "SupportedEthernetCapabilities", ""},
                        {0, BEJ_ENUM, 0, "", (char [3]){0x01, 0x01, 0x00}},
                            // {0, BEJ_STR, 0, "WakeOnLAN", ""},
                            // {0, BEJ_STR, 0, "EEE", ""},
                {0, BEJ_STR, 0, "Id", "Resource offset"},
                {0, BEJ_BOOLEAN, 0, "InterfaceEnabled", "t"},
                {0, BEJ_ARRAY, 1, "LinkConfiguration", ""},
                    {0, BEJ_SET, 3, "", ""},
                        {0, BEJ_BOOLEAN, 0, "AutoSpeedNegotiationCapable", "t"},
                        {0, BEJ_BOOLEAN, 0, "AutoSpeedNegotiationEnabled", "t"},
                        {0, BEJ_ARRAY, 2, "CapableLinkSpeedGbps", (char [3]){0x01, 0x20, 0x00}},
                            {0, BEJ_REAL, 0, "", "Gbs"},
                            {0, BEJ_REAL, 0, "", "Gbs"},
                {0, BEJ_ENUM, 0, "LinkNetworkTechnology", (char [3]){0x01, 'U', 0x00}},
                    // {0, BEJ_STR, 0, "Ethernet", ""},
                    // {0, BEJ_STR, 0, "InfiniBand", ""},
                    // {0, BEJ_STR, 0, "FibreChannel", ""},
                    // {0, BEJ_STR, 0, "GenZ", ""},
                {0, BEJ_ENUM, 0, "LinkState", (char [3]){0x01, 'U', 0x00}},
                    // {0, BEJ_STR, 0, "Enabled", ""},
                    // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_ENUM, 0, "LinkStatus", (char [3]){0x01, 0x01, 0x00}},
                    // {0, BEJ_STR, 0, "LinkUp", ""},
                    // {0, BEJ_STR, 0, "Starting", ""},
                    // {0, BEJ_STR, 0, "Training", ""},
                    // {0, BEJ_STR, 0, "LinkDown", ""},
                    // {0, BEJ_STR, 0, "NoLink", ""},
                {0, BEJ_INT, 0, "LinkTransitionIndicator", (char [3]){0x01, 0x01, 0x00}},
                {0, BEJ_INT, 0, "MaxFrameSize", "?"},
                {0, BEJ_INT, 0, "MaxSpeedGbps", (char [3]){0x01, 50, 0x00}},
                {0, BEJ_STR, 0, "Name", "AM_Port"},
                {0, BEJ_ENUM, 0, "Status", (char [3]){0x01, 0x01, 0x00}},
                    // {0, BEJ_STR, 0, "Enabled", ""},
                    // {0, BEJ_STR, 0, "Disabled", ""},
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_PORT_RESOURCE_ID, "Port.1_3_1.Port", PORT_IDENTIFY);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    // pldm_cjson_cal_len_to_root2(new_root->child, OTHER_TYPE);
    // pldm_cjson_printf_root1(new_root->child);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_portcollection_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 3, "PortCollection", ""},
                {0, BEJ_STR, 0, "Name", "Ports"},
                {1, BEJ_INT, 0, "Members@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
                {0, BEJ_ARRAY, 2, "Members", ""},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "100"},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "101"}
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 1, PLDM_BASE_PORTS_RESOURCE_ID, "PortCollection.PortCollection", PORT_COLLECTION);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_networkinterface_v1_2_0_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 7, "NetworkInterface", ""},
                {0, BEJ_SET, 1, "Links", ""},
                    {0, BEJ_SET, 0, "NetworkAdapter", ""},
                        // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID, 0x00}},
                {0, BEJ_STR, 0, "Name", "AM_Network_Interface"},
                {0, BEJ_SET, 0, "NetworkDeviceFunctions", "Ports"},
                {0, BEJ_SET, 0, "NetworkPorts", ""},
                    // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID, 0x00}},
                {0, BEJ_SET, 0, "Ports", ""},
                    // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_PORTS_RESOURCE_ID, 0x00}},
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 0, "State", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_STR, 0, "Id", "%I5"}                        /* PLDM_BASE_NETWORK_INTERFACE_RESOURCE_ID */
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_NETWORK_INTERFACE_RESOURCE_ID, "NetworkInterface.1_2_1.NetworkInterface", NETWORK_INTERFACE);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_networkadapter_v1_5_0_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 12, "NetworkAdapter", ""},
                {0, BEJ_SET, 1, "Actions", ""},
                    {0, BEJ_SET, 1, "#NetworkAdapter.ResetSettingsToDefault", ""},
                        {0, BEJ_STR, 0, "target", "?"},
                {0, BEJ_ARRAY, 1, "Controllers", ""},
                    {0, BEJ_SET, 4, "", ""},
                        {0, BEJ_SET, 4, "ControllerCapabilities", ""},
                            {0, BEJ_SET, 1, "DataCenterBridging", ""},
                                {0, BEJ_BOOLEAN, 0, "Capable", "t"},
                            {0, BEJ_INT, 0, "NetworkDeviceFunctionCount", (char [2]){MAX_LAN_NUM, 0x00}},
                            {0, BEJ_INT, 0, "NetworkPortCount", (char [2]){MAX_LAN_NUM, 0x00}},
                            {0, BEJ_SET, 2, "VirtualizationOffload", ""},
                                {0, BEJ_SET, 1, "SRIOV", ""},
                                    {0, BEJ_BOOLEAN, 0, "SRIOVVEPACapable", "t"},
                                {0, BEJ_SET, 3, "VirtualFunction", ""},
                                    {0, BEJ_INT, 0, "DeviceMaxCount", (char [3]){0x00, 0x1, 0x00}},
                                    {0, BEJ_INT, 0, "MinAssignmentGroupSize", (char [2]){0x01, 0x00}},
                                    {0, BEJ_INT, 0, "NetworkPortMaxCount", (char [3]){0x00, 0x1, 0x00}},
                        {0, BEJ_STR, 0, "FirmwarePackageVersion", "1.1.1?"},
                        {0, BEJ_SET, 1, "Links", ""},
                            {0, BEJ_ARRAY, 1, "NetworkDeviceFunctions", ""},
                                {0, BEJ_SET, 0, "", (char [2]){PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID, 0x00}},
                        {0, BEJ_SET, 4, "PCIeInterface", ""},
                            {0, BEJ_INT, 0, "LanesInUse", "?"},
                            {0, BEJ_INT, 0, "MaxLanes", ""},
                            {0, BEJ_ENUM, 0, "MaxPCIeType", (char [3]){0x01, 0x01, 0x00}},  /* Maximum Link Speed? */
                            {0, BEJ_ENUM, 0, "PCIeType", (char [3]){0x01, 0x01, 0x00}},
                                // {0, BEJ_STR, 0, "Gen1", ""},
                                // {0, BEJ_STR, 0, "Gen2", ""},
                                // {0, BEJ_STR, 0, "Gen3", ""},
                                // {0, BEJ_STR, 0, "Gen4", ""},
                {0, BEJ_STR, 0, "Manufacturer", "WXKJ"},
                {0, BEJ_STR, 0, "Model", "AMBER"},
                {0, BEJ_STR, 0, "Name", "AM Network Adapter"},
                {0, BEJ_SET, 0, "NetworkDeviceFunctions", "NetworkDeviceFunctionCollection"},
                {0, BEJ_SET, 0, "NetworkPorts", "NetworkPortCollection"},
                {0, BEJ_INT, 0, "PartNumber", "Part Number (PN) is 11 byte value maintained in VPD.?"},
                {0, BEJ_STR, 0, "SKU", "AMBER"},
                {0, BEJ_INT, 0, "SerialNumber", "Read from GLPCI_SERH/L.?"},
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 5, "State", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_STR, 0, "Id", "%I1"},                   /* PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID */
                // {0, BEJ_ARRAY, 1, "ControllerLinks", ""},
                //     {1, BEJ_INT, 0, "PCIeDevices@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID, "NetworkAdapter.1_5_0.NetworkAdapter", NETWORK_ADAPTER);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_networkdevicefunction_v1_3_3_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 14, "NetworkDeviceFunction", ""},
                {0, BEJ_ARRAY, 1, "AssignablePhysicalPorts", ""},
                    {0, BEJ_SET, 0, "", ""},
                        // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_PORT_RESOURCE_ID, 0x00}},
                        // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_PORT_RESOURCE_ID + 1, 0x00}},
                {1, BEJ_INT, 0, "AssignablePhysicalPorts@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
                {0, BEJ_ENUM, 0, "BootMode", (char [3]){0x01, 0x01, 0x00}},
                    // {0, BEJ_STR, 0, "Disabled", ""},
                    // {0, BEJ_STR, 0, "PXE", ""},
                    // {0, BEJ_STR, 0, "iSCSI", ""},
                    // {0, BEJ_STR, 0, "FibreChannel", ""},
                    // {0, BEJ_STR, 0, "FibreChannelOverEthernet", ""},
                {0, BEJ_BOOLEAN, 0, "DeviceEnabled", "t"},
                {0, BEJ_SET, 5, "Ethernet", ""},
                    {0, BEJ_STR, 0, "MACAddress", "11:22:33:44:55:66"},
                    {0, BEJ_INT, 0, "MTUSize", (char [4]){0x02, 0xEE, 0x25, 0x00}},
                    {0, BEJ_STR, 0, "PermanentMACAddress", "11:22:33:44:55:66"},
                    {0, BEJ_ARRAY, 0, "VLAN", ""},
                    {0, BEJ_SET, 0, "VLANs", ""},
                {0, BEJ_INT, 0, "MaxVirtualFunctions", ""},
                {0, BEJ_STR, 0, "Name", "NetworkDeviceFunction Current Settings?"},
                {0, BEJ_ARRAY, 1, "NetDevFuncCapabilities", ""},
                    {0, BEJ_ENUM, 0, "", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                        // {0, BEJ_STR, 0, "Ethernet", ""},
                        // {0, BEJ_STR, 0, "FibreChannel", ""},
                        // {0, BEJ_STR, 0, "iSCSI", ""},
                        // {0, BEJ_STR, 0, "FibreChannelOverEthernet", ""},
                {0, BEJ_ENUM, 0, "NetDevFuncType", (char [3]){0x01, 0x01, 0x00}},
                    // {0, BEJ_STR, 0, "Disabled", ""},
                    // {0, BEJ_STR, 0, "Ethernet", ""},
                    // {0, BEJ_STR, 0, "FibreChannel", ""},
                    // {0, BEJ_STR, 0, "iSCSI", ""},
                    // {0, BEJ_STR, 0, "FibreChannelOverEthernet", ""},
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 0, "State", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_BOOLEAN, 0, "VirtualFunctionsEnabled", "f"},
                {1, BEJ_SET, 2, "@Redfish.Settings", ""},
                    {1, BEJ_STR, 0, "SettingsObject", "Points to the next setting = Resource ID +10"},
                    {1, BEJ_ARRAY, 1, "SupportedApplyTimes", ""},
                        {1, BEJ_ENUM, 0, "", (char [3]){0x01, 0x03, 0x00}},
                        // {0, BEJ_STR, 0, "AtMaintenanceWindowStart", ""},
                        // {0, BEJ_STR, 0, "Immediate", ""},
                        // {0, BEJ_STR, 0, "InMaintenanceWindowOnReset", ""},
                        // {0, BEJ_STR, 0, "OnReset", ""},
                {0, BEJ_STR, 0, "Id", "Resource Offset"},
                {0, BEJ_SET, 2, "Links", ""},
                    {0, BEJ_SET, 0, "PCIeFunction", ""},
                        // {0, BEJ_STR, 0, "", (char [3]){0x0c, 0x12, 0x00}},
                    {0, BEJ_SET, 0, "PhysicalPortAssignment", ""},
                        // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_PORT_RESOURCE_ID, 0x00}},
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_PORTS_RESOURCE_ID, "PortCollection.1_3_1.PortCollection", NETWORK_DEVICE_FUNC);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_networkdevicefunctioncollection_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 3, "NetworkDeviceFunctionCollection", ""},
                {0, BEJ_STR, 0, "Name", "NetworkDeviceFunctions"},
                {1, BEJ_INT, 0, "Members@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
                {0, BEJ_ARRAY, 2, "Members", ""},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "200"},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "201"}
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 1, PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID, "NetworkDeviceFunctionCollection.NetworkDeviceFunctionCollection", NETWORK_DEVICE_FUNC_COLLECTION);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_pciedevice_v1_4_0_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 13, "PCIeDevice", ""},
                {0, BEJ_STR, 0, "AssetTag", ""},
                {0, BEJ_ENUM, 0, "DeviceType", (char [3]){0x01, 0x01, 0x00}},  /* Config space of function 0 - Header type register */
                    // {0, BEJ_STR, 0, "SingleFunction", ""},
                    // {0, BEJ_STR, 0, "MultiFunction", ""},
                    // {0, BEJ_STR, 0, "Simulated", ""},
                {0, BEJ_STR, 0, "FirmwareVersion", "1.1.1?"},
                {0, BEJ_STR, 0, "Manufacturer", "WXKJ"},
                {0, BEJ_STR, 0, "Model", "AMBER"},
                {0, BEJ_STR, 0, "Name", "AMBER"},
                {0, BEJ_SET, 4, "PCIeInterface", ""},
                    {0, BEJ_INT, 0, "LanesInUse", ""},                         /* Negotiated Link Width */
                    {0, BEJ_INT, 0, "MaxLanes", ""},                           /* Maximum Link Width */
                    {0, BEJ_ENUM, 0, "MaxPCIeType", (char [3]){0x01, 0x01, 0x00}}, /* Maximum Link Speed */
                        // {0, BEJ_STR, 0, "Gen1", ""},
                        // {0, BEJ_STR, 0, "Gen2", ""},
                        // {0, BEJ_STR, 0, "Gen3", ""},
                        // {0, BEJ_STR, 0, "Gen4", ""},
                        // {0, BEJ_STR, 0, "Gen5", ""},
                    {0, BEJ_ENUM, 0, "PCIeType", (char [3]){0x01, 0x01, 0x00}},    /* Current Link Speed */
                        // {0, BEJ_STR, 0, "Gen1", ""},
                        // {0, BEJ_STR, 0, "Gen2", ""},
                        // {0, BEJ_STR, 0, "Gen3", ""},
                        // {0, BEJ_STR, 0, "Gen4", ""},
                        // {0, BEJ_STR, 0, "Gen5", ""},
                {0, BEJ_STR, 0, "PartNumber", ""},
                {0, BEJ_STR, 0, "SKU", "AMBER"},
                {0, BEJ_STR, 0, "SerialNumber", "11:22:33:FF:FF:44:55:66"},
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 0, "State", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_SET, 0, "PCIeFunctions", ""},
                    // {0, BEJ_STR, 0, "", (char [2]){PLDM_BASE_PCIE_FUNCS_RESOURCE_ID, 0x00}},
                {0, BEJ_STR, 0, "Id", ""},
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_PCIE_FUNC_RESOURCE_ID, "PCIeDevice.1_4_0.PCIeDevice", PCIE_DEVICE);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_pciefunctioncollection_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 3, "PCIeDeviceCollection", ""},
                {0, BEJ_STR, 0, "Name", "PCIeFunctions"},
                {1, BEJ_INT, 0, "Members@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
                {0, BEJ_ARRAY, 2, "Members", ""},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "300"},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "301"}
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 1, PLDM_BASE_PCIE_FUNCS_RESOURCE_ID, "PCIeFunctionCollection.PCIeFunctionCollection", PCIE_FUNC_COLLECTION);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_pciefunction_v1_2_3_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 11, "PCIeFunction", ""},
                {0, BEJ_STR, 0, "ClassCode", "0x020000"},                  /* EthernetController */
                {0, BEJ_ENUM, 0, "DeviceClass", (char [3]){0x01, 'U', 0x00}},
                    // {0, BEJ_STR, 0, "NetworkController", ""},
                {0, BEJ_STR, 0, "DeviceId", ""},
                {0, BEJ_ENUM, 0, "FunctionType", (char [3]){0x01, 'U', 0x00}},
                    // {0, BEJ_STR, 0, "Physical", ""},
                    // {0, BEJ_STR, 0, "Virtual", ""},
                {0, BEJ_STR, 0, "Name", "AMBER"},
                {0, BEJ_STR, 0, "RevisionId", ""},                         /* GLPCI_DREVID XOR GLPCI_REVID */
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 0, "State", (char [3]){0x01, 0x01, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {0, BEJ_STR, 0, "SubsystemId", ""},                        /* PFPCI_SUBSYSID.PF_SUBSYS_ID */
                {0, BEJ_STR, 0, "SubsystemVendorId", ""},                  /* GLPCI_SUBVENID */
                {0, BEJ_STR, 0, "VendorId", ""},                           /* GLPCI_VENDORID.VENDOR_D */
                {0, BEJ_STR, 0, "Id", ""},                                 /* Resource Offset */
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_PCIE_FUNC_RESOURCE_ID, "PCIeFunction.1_2_3.PCIeFunction", PCI_FUNC);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_ethernetinterface_v1_5_1_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 12, "EthernetInterface", ""},
                {0, BEJ_BOOLEAN, 0, "FullDuplex", "t"},
                {0, BEJ_BOOLEAN, 0, "InterfaceEnabled", ""},               /* PRTGEN_STATUS.PORT_VALID */
                {0, BEJ_ENUM, 0, "LinkStatus", ""},
                    // {0, BEJ_STR, 0, "LinkDown", ""},
                    // {0, BEJ_STR, 0, "LinkUp", ""},
                    // {0, BEJ_STR, 0, "NoLink", ""},
                {0, BEJ_STR, 0, "MACAddress", "11:22:33:44:55:66"},
                {0, BEJ_INT, 0, "MTUSize", (char [3]){0xEE, 0x25, 0x00}},
                {0, BEJ_STR, 0, "Name", "AM Ethernet Interface Current Settings"},
                {0, BEJ_STR, 0, "NameServers", ""},
                {0, BEJ_STR, 0, "PermanentMACAddress", ""},
                {0, BEJ_INT, 0, "SpeedMbps", ""},
                {0, BEJ_SET, 1, "Status", ""},
                    {0, BEJ_ENUM, 0, "State", (char [3]){0x01, 0x03, 0x00}},
                        // {0, BEJ_STR, 0, "StandbyOffline", ""},
                        // {0, BEJ_STR, 0, "Starting", ""},
                        // {0, BEJ_STR, 0, "Updating", ""},
                        // {0, BEJ_STR, 0, "Enabled", ""},
                        // {0, BEJ_STR, 0, "Disabled", ""},
                {1, BEJ_SET, 2, "@Redfish.Settings", ""},
                    {1, BEJ_STR, 0, "SettingsObject", "Points to the next setting = Resource ID +10"},
                    {1, BEJ_ARRAY, 1, "SupportedApplyTimes", ""},
                        {1, BEJ_ENUM, 0, "", (char [3]){0x01, 0x03, 0x00}},
                        // {0, BEJ_STR, 0, "AtMaintenanceWindowStart", ""},
                        // {0, BEJ_STR, 0, "Immediate", ""},
                        // {0, BEJ_STR, 0, "InMaintenanceWindowOnReset", ""},
                        // {0, BEJ_STR, 0, "OnReset", ""},
                {0, BEJ_STR, 0, "Id", "Resource Offset"},
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 0, PLDM_BASE_ETH_INTERFACE_RESOURCE_ID, "EthernetInterface.1_5_1.EthernetInterface", ETH_INTERFACE);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_create_ethernetinterfacecollection_schema(void)
{
    pldm_cjson_t *root = pldm_cjson_create_obj();
    pldm_cjson_schema_fmt_t fmt[] = {
        /* schema_type | fmt | child_cnt | name | val */
        {0, BEJ_SET, 1, "", ""},
            {0, BEJ_SET, 3, "EthernetInterfaceCollection", ""},
                {0, BEJ_STR, 0, "Name", "NetworkDeviceFunctions"},
                {1, BEJ_INT, 0, "Members@odata.count", (char [2]){MAX_LAN_NUM, 0x00}},
                {0, BEJ_ARRAY, 2, "Members", ""},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "400"},
                    {0, BEJ_SET, 1, "", ""},
                        {1, BEJ_STR, 0, "@odata.id", "401"}
    };
    // pldm_cjson_create_schema(root, fmt, sizeof(fmt) / sizeof(pldm_cjson_schema_fmt_t));
    pldm_cjson_create_schema_recursion(root, fmt);
    pldm_cjson_t *new_root = NULL;
    new_root = root->child;
    root->child = NULL;
    // pldm_cjson_delete_node(root);
    root = NULL;
    pldm_cjson_fill_comm_field_in_schema(new_root->child, 1, PLDM_BASE_ETH_INTERFACE_COLLECTION_RESOURCE_ID, "EthernetInterfaceCollection.EthernetInterfaceCollection", ETH_INTERFACE_COLLECTION);
    // pldm_cjson_cal_sf_to_root(new_root->child, anno_dict, dict);
    return new_root->child;
}

static pldm_redfish_dictionary_entry_t *pldm_cjson_dict_fill_sf(u8 *dict, pldm_redfish_dictionary_entry_t *entry, u16 entry_cnt, pldm_cjson_t *root, u8 name_idx)
{
    if (!dict || !entry) return NULL;
    pldm_redfish_dictionary_entry_t *tmp = entry;

    for (u16 k = 0; k < entry_cnt; k++) {
        char *name = "";
        if (tmp->name_off) {
            name = (char *)&dict[tmp->name_off];
        }
        if (cm_strcmp(name, &(root->name[name_idx])) == 0) {
            root->sflv.seq |= (tmp->sequence_num << 1);
            root->sflv.fmt = tmp->format;
            return tmp;
        }
        tmp += 1;
    }
    LOG("fmt err: %s, %d", &(root->name[name_idx]), cm_strlen(&(root->name[name_idx])));
    return entry;
}

static void pldm_cjson_cal_sf_to_root_op(pldm_cjson_t *root, u8 *anno_dict, u8 *dict, pldm_redfish_dictionary_entry_t *entry, u16 entry_cnt, pldm_redfish_dictionary_entry_t *anno_entry, u16 anno_entry_cnt)
{
    if (!anno_dict || !dict || !entry || !anno_entry) return;
    pldm_cjson_t *tmp = root;
    while (tmp) {
        u8 fmt = tmp->sflv.fmt >> 4;
        u8 child_cnt = entry_cnt;
        u8 anno_child_cnt = anno_entry_cnt;
        pldm_redfish_dictionary_entry_t *new_entry = entry;
        pldm_redfish_dictionary_entry_t *new_anno_entry = anno_entry;

        if (tmp->sflv.seq & 1) {
            u8 name_len = cm_strlen(tmp->name) + 1;
            u8 is_find = 0;
            for (u8 j = 0; j < name_len; j++) {
                if (tmp->name[j] == '@') {
                    new_anno_entry = pldm_cjson_dict_fill_sf(anno_dict, anno_entry, anno_entry_cnt, tmp, j);
                    is_find = 1;
                    break;
                }
            }
            if (!is_find)
                new_anno_entry = pldm_cjson_dict_fill_sf(anno_dict, anno_entry, anno_entry_cnt, tmp, 0);
        } else {
            new_entry = pldm_cjson_dict_fill_sf(dict, entry, entry_cnt, tmp, 0);
        }
        if (fmt == BEJ_SET || fmt == BEJ_ARRAY) {
            child_cnt = new_entry->child_cnt;
            new_entry = (pldm_redfish_dictionary_entry_t *)&dict[new_entry->childpoint_off];

            if (new_anno_entry->childpoint_off && tmp->sflv.seq & 1) {
            // LOG("seq : 0x%02x, fmt : 0x%02x", sflv.seq >> 1, sflv.fmt >> 4);
            anno_child_cnt = new_anno_entry->child_cnt;
            new_anno_entry = (pldm_redfish_dictionary_entry_t *)&anno_dict[new_anno_entry->childpoint_off];
        }
        }
        pldm_cjson_cal_sf_to_root_op(tmp->child, anno_dict, dict, new_entry, child_cnt, new_anno_entry, anno_child_cnt);
        tmp = tmp->next;
    }
}

void pldm_cjson_cal_sf_to_root(pldm_cjson_t *root, u8 *anno_dict, u8 *dict)
{
    if (!root || !anno_dict || !dict) return;
    pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict;
    pldm_redfish_dictionary_format_t *anno_dict_ptr = (pldm_redfish_dictionary_format_t *)anno_dict;
    pldm_cjson_cal_sf_to_root_op(root, anno_dict, dict, &(dict_ptr->entry[0]), dict_ptr->entry_cnt, &(anno_dict_ptr->entry[0]), anno_dict_ptr->entry_cnt);
}

schema_create g_schemas[] = {
    pldm_cjson_create_networkadapter_v1_5_0_schema,             /* Actions */
    pldm_cjson_create_pciedevice_v1_4_0_schema,
    pldm_cjson_create_networkinterface_v1_2_0_schema,
    pldm_cjson_create_portcollection_schema,
    pldm_cjson_create_pciefunctioncollection_schema,
    pldm_cjson_create_networkdevicefunctioncollection_schema,
    pldm_cjson_create_networkdevicefunction_v1_3_3_schema,
    pldm_cjson_create_port_v1_3_1_schema,                       /* Actions */
    pldm_cjson_create_pciefunction_v1_2_3_schema,
    pldm_cjson_create_ethernetinterface_v1_5_1_schema,
    pldm_cjson_create_ethernetinterfacecollection_schema
};

u32 g_resource_id[] = {
    PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID,
    PLDM_BASE_PCIE_DEV_RESOURCE_ID,
    PLDM_BASE_NETWORK_INTERFACE_RESOURCE_ID,
    PLDM_BASE_PORTS_RESOURCE_ID,
    PLDM_BASE_PCIE_FUNCS_RESOURCE_ID,
    PLDM_BASE_NETWORK_DEV_FUNCS_RESOURCE_ID,
    PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID,
    PLDM_BASE_PORT_RESOURCE_ID,
    PLDM_BASE_PCIE_FUNC_RESOURCE_ID,
    PLDM_BASE_ETH_INTERFACE_RESOURCE_ID,
    PLDM_BASE_ETH_INTERFACE_COLLECTION_RESOURCE_ID,
};

extern u8 g_dict_info[PLDM_REDFISH_DICT_INFO_LEN];
extern u8 g_anno_dict[PLDM_REDFISH_ANNO_DICT_LEN];
extern u8 g_needed_dict[PLDM_REDFISH_PORT_DICT_LEN];

static void pldm_cjson_schema_test(void)
{
    pldm_cjson_t *root = NULL;
    u8 *anno_dict = &g_anno_dict[DICT_FMT_HDR_LEN];
    u8 *dict = &g_needed_dict[DICT_FMT_HDR_LEN];
    u8 bej_data[1024];

    pldm_cjson_pool_init();

    for (u8 i = 0; i < sizeof(g_schemas) / sizeof(schema_create); i++) {
        if (g_resource_id[i] != PLDM_BASE_PORT_RESOURCE_ID) continue;
        u8 ret = pldm_redfish_get_dict_data(g_resource_id[i], SCHEMACLASS_MAJOR, \
        g_needed_dict, pldm_redfish_get_dict_len(g_resource_id[i]));
        if (ret == false) return;
        root = g_schemas[i]();
        if (!root) LOG("ERRR");
        // pldm_cjson_cal_len_to_root2(root, OTHER_TYPE);
        // pldm_cjson_printf_root1(root);
        u8 *end_ptr = pldm_bej_encode(root, bej_data);
        LOG("\nused space : %d, max_space : %d", pldm_cjson_get_used_space(), MY_CJSON_POLL_SIZE);
        LOG("len : %d", end_ptr - bej_data);
        pldm_cjson_update_etag(root);
        pldm_cjson_pool_init();
    }
}

static void pldm_cjson_bej_test(void)
{
    pldm_cjson_t *root = NULL;
    pldm_cjson_t *bej_root = NULL;
    u8 *annc_dict = &g_anno_dict[DICT_FMT_HDR_LEN];
    u8 *dict = &g_needed_dict[DICT_FMT_HDR_LEN];
    u8 buf[1024];

    for (u8 i = 0; i < sizeof(g_resource_id) / sizeof(u32); i++) {
        // if (g_resource_id[i] != PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID) continue;
        // pldm_cjson_pool_init();
        u8 ret = pldm_redfish_get_dict_data(g_resource_id[i], SCHEMACLASS_MAJOR, \
        g_needed_dict, pldm_redfish_get_dict_len(g_resource_id[i]));
        if (ret == false) return;

        root = g_schemas[i]();
        if (root) {
            pldm_cjson_cal_sf_to_root(root, annc_dict, dict);
            pldm_cjson_cal_len_to_root2(root, OTHER_TYPE);
            // pldm_cjson_printf_root2(root);
            LOG("\nencode cnt : %d", i);
        }

        u8 *ptr = pldm_bej_encode(root, buf);
        // for (u16 i = 0; i < (ptr - buf); i++) {
        //     printf("0x%02x, ", buf[i]);
        //     if (!((i + 1) % 8)) {
        //         printf("\n");
        //     }
        // }
        LOG("encode len : %d", ptr - buf);
        pldm_cjson_pool_init();

        bej_root = pldm_bej_decode(buf, ptr - buf, annc_dict, dict, bej_root);
        if (bej_root) {
            LOG("decode cnt : %d\n", i);
            pldm_cjson_cal_len_to_root2(bej_root, OTHER_TYPE);
            // pldm_cjson_printf_root2(bej_root);
            pldm_cjson_cal_sf_to_root(bej_root, annc_dict, dict);
        }
        pldm_cjson_pool_init();
    }
}

extern pldm_redfish_bej_t g_resourse_bej[PLDM_REDFISH_RESOURCE_NUM];

extern u32 pldm_redfish_resource_id_to_base(u32 resource_id);
extern u8 resource_id_to_resource_identity(u32 resource_id);

void pldm_cjson_redfish_op_test(void)
{
    pldm_cjson_t *bej_root = NULL;
    pldm_cjson_t *root = NULL;

    pldm_payload_dat_t bej_buf;

    u8 *anno_dict = &g_anno_dict[DICT_FMT_HDR_LEN];
    u8 *dict = &g_needed_dict[DICT_FMT_HDR_LEN];

    u8 op_type = UPDATE;
    u8 resource_id = g_resource_id[0];
    u8 offset = resource_id - pldm_redfish_resource_id_to_base(resource_id);

    u8 resourse_indenty = resource_id_to_resource_identity(resource_id);
    if (resourse_indenty > ETH_INTERFACE_COLLECTION) LOG("resource_id_to_resource_identity err");

    resourse_indenty -= NETWORK_ADAPTER;

    u8 ret = pldm_redfish_get_dict_data(resource_id, SCHEMACLASS_MAJOR,\
    g_needed_dict, pldm_redfish_get_dict_len(resource_id));
    if (ret == false) LOG("pldm_redfish_get_dict_data err!");

    if (g_resourse_bej[resourse_indenty + offset].is_bej)
        root = pldm_bej_decode(g_resourse_bej[resourse_indenty + offset].data, g_resourse_bej[resourse_indenty + offset].len, anno_dict, dict, root);
    else root = g_schemas[resourse_indenty]();

    bej_buf.len = sizeof(bejencoding_t);
    u8 test_buf[] = {0x01, 0x00, 0x00, 0x01, 0x08, 0x01, 0x01, 0x01, 0x00, 0x76, 0x01, 0x01, 'f'};
    cm_memcpy(&(bej_buf.data[sizeof(bejencoding_t)]), test_buf, sizeof(test_buf));
    bej_buf.len += sizeof(test_buf);
    if (bej_buf.len && op_type != READ && op_type != HEAD && op_type != ACTION) {
        bej_root = pldm_bej_decode(&(bej_buf.data[sizeof(bejencoding_t)]), bej_buf.len - sizeof(bejencoding_t), anno_dict, dict, bej_root);
        if (!bej_root) LOG("pldm_bej_decode err!");
    }

    pldm_cjson_printf_root2(bej_root);

    pldm_cjson_cal_sf_to_root(root, anno_dict, dict);
    pldm_cjson_cal_len_to_root2(root, op_type);
    // pldm_cjson_printf_root2(root);
    int state = -1;

    switch (op_type) {
        case READ:
            state = pldm_cjson_read(root, 0, 1);
            break;
        case UPDATE:
            state = pldm_cjson_update(root, bej_root);
            break;
        case REPLACE:
            state = pldm_cjson_replace(root, bej_root);
            break;
        case ACTION:
            state = pldm_cjson_action(root);
            break;
        case HEAD:
            state = pldm_cjson_head(root);                   /*  not return message body information. */
            break;
        default :
            LOG("err op type : %d", op_type);
            break;
    }
    if (state != 0) LOG("pldm_cjson_read process err!, op_type : %d, resource id : %d", op_type, resource_id);
    LOG("---------------------------------------------------");
    pldm_cjson_cal_len_to_root2(root, op_type);
    pldm_cjson_printf_root2(root);
}

static void pldm_cjson_oem_dict_test(void)
{
    pldm_cjson_t *root = NULL;
    u8 dict[1024];
    u8 anno_dict[1024];
    root = pldm_cjson_create_networkdevicefunctioncollection_schema();
    pldm_cjson_printf_root2(root);
    pldm_cjson_create_dict(root, dict, 0);
}

#include <time.h>
void pldm_cjson_test(void)
{
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_t *root = NULL;
    pldm_cjson_t *tmp1 = NULL;
    pldm_cjson_t *obj = NULL;
    pldm_cjson_t *obj1 = NULL;
    pldm_cjson_t *obj2 = NULL;
    pldm_cjson_t *obj3 = NULL;

    CM_FLASH_READ(PLDM_REDFISH_DICT_BASE_ADDR, (u32 *)g_dict_info, PLDM_REDFISH_DICT_INFO_LEN / sizeof(u32));

    pldm_redfish_get_dict_data(PLDM_BASE_ANNOTATION_DICT_RESOURCE_ID, SCHEMACLASS_ANNOTATION, g_anno_dict, sizeof(g_anno_dict));

    pldm_cjson_pool_init();
    double start,end,cost;
    start = clock();
    pldm_cjson_redfish_op_test();
    // pldm_cjson_bej_test();
    // pldm_cjson_schema_test();
    // pldm_cjson_oem_dict_test();
    end = clock();
    cost = end - start;
    LOG("time diff %f",cost);   /* uint is ms */
    // tmp1 = create_event_schema(1234, dict, dict);

    // root = pldm_cjson_create_obj();

    // sflv.seq = 1;
    // sflv.fmt = BEJ_SET << 4;
    // pldm_cjson_add_sflv_attr(root, &sflv, "DummySimple", "", strlen(""));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_ARRAY << 4;
    // obj2 = pldm_cjson_add_item_to_obj(root, &sflv, "ChildArrayProperty", "", strlen(""));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_SET << 4;
    // obj1 = pldm_cjson_add_item_to_obj(obj2, &sflv, "", "", strlen(""));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_BOOLEAN << 4;
    // // obj = pldm_cjson_add_obj(obj, &sflv, "AnotherBoolean");
    // pldm_cjson_add_item_to_obj(obj1, &sflv, "AnotherBoolean", "true", strlen("true"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_ENUM << 4;
    // obj = pldm_cjson_add_item_to_obj(obj1, &sflv, "LinkStatus", "LinkUp", strlen("LinkUp"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "LinkDown", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "LinkUp", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "NoLink", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_ENUM << 4;
    // obj = pldm_cjson_add_item_to_obj(obj1, &sflv, "LinkStatus", "LinkUp", strlen("LinkUp"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "LinkDown", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "NoLink", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(root, &sflv, "Id", "Dummy Id", strlen("Dummy ID"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_BOOLEAN << 4;
    // pldm_cjson_add_item_to_obj(root, &sflv, "SampleEnabledProperty", "false", strlen("false"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_INT << 4;
    // char str[2] = {0xc, 0x0};
    // pldm_cjson_add_item_to_obj(root, &sflv, "SampleIntegerProperty", str, strlen(str));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_ENUM << 4;
    // pldm_cjson_replace_enum_val(root, &sflv, "LinkStatus", "LinkUp");

    // pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dict0;
    // pldm_cjson_cal_len_to_root1(root, 'U');
    // pldm_cjson_cal_sf_to_root2(root, dict0, dict0, &(dict->entry[0]), dict->entry_cnt);
    // pldm_cjson_printf_root1(root);
    // for (u8 i = 0; i < dict->entry_cnt; i++) {
    //     LOG("seq : %d, len : %d, name off : %d, name : %s", dict->entry[i].sequence_num, dict->entry[i].name_len, dict->entry[i].name_off, &dict0[dict->entry[i].name_off]);
    // }
    // pldm_cjson_create_dict(root, dict_test, 0);
    // // pldm_cjson_create_dict(root, anno_dict_test, 1);
    // u8 name_buf[1024];
    // u16 name_off = 0;

    // // pldm_cjson_fill_dict_hdr(anno_dict_test);

    // pldm_cjson_fill_anno_dict_entry_data(root, anno_dict_test, name_buf, &name_off);
    // pldm_cjson_fill_anno_dict_entry_data(tmp1, anno_dict_test, name_buf, &name_off);
    // pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)anno_dict_test;
    // u8 *dict_name = (u8 *)&(dict->entry[dict->entry_cnt]);
    // u16 offset = dict_name - anno_dict_test;
    // for (u8 i= 0; i < dict->entry_cnt; i++) {
    //     dict->entry[i].name_off += offset;
    //     dict->entry[i].sequence_num = i;
    // }
    // memcpy(dict_name, name_buf, name_off);
    // pldm_cjson_fill_dict_copyright(anno_dict_test, "Copyright (c) 2018 DMTF");
    // pldm_cjson_printf_dict(anno_dict_test);
    // pldm_cjson_cal_len_to_root1(root, 'U');
    // pldm_cjson_printf_root1(root);

    // FILE *fp;
    // fp = fopen( "dict.txt" , "a" );
    // for (u8 i = 0; i < 2; i++) {
    //     // pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict_test;
    //     fwrite(dict_test, sizeof(u8) , dict_ptr->dictionary_size, fp );
    // }

    // fclose(fp);

    // LOG("\nmy_json_json_to_bej\n");
    // u8 *ptr = pldm_bej_encode(root, anno_dict_test, bej_test);
    // pldm_cjson_t *tmp = NULL;
    // tmp = pldm_bej_decode(bej_test, anno_dict_test, dict_test, tmp);
    // u8 bej_test_len = ptr - bej_test;
    // LOG("%p, %p, %d", bej_test, ptr, bej_test_len);

    // pldm_cjson_cal_len_to_root1(tmp, 'U');
    // pldm_cjson_printf_root1(tmp);

    // create_networkdevice_registry_v1_0_1_schema('U', bej_test, dict_test);

    // pldm_cjson_t *tmp1 = NULL;
    // tmp1 = pldm_bej_decode(bej_buf1, dict0, tmp1);
    // u8 bej_test_len = ptr - bej_test;
    // LOG("%p, %p, %d", bej_test, ptr, bej_test_len);

    // tmp1 = pldm_cjson_update(tmp1, tmp);
    // pldm_cjson_cal_len_to_root1(tmp, 'U');
    // pldm_cjson_printf_root1(tmp);

    // pldm_cjson_create_dict(root, dict_test);

    // u8 *ptr = pldm_bej_encode(root, bej_test);
    // u8 bej_test_len = ptr - bej_test;

    // for (u16 i = 0; i < bej_test_len; i++) {
    //     LOG("0x%02x, ", bej_test[i]);
    //     if (!((i + 1) % 8)) {
    //         LOG("\n");
    //     }
    // }

    // pldm_cjson_t *root1 = NULL;
    // root1 = pldm_cjson_create_obj();

    // LOG("\ntotal len : %d", pldm_bej_decode(bej_buf1, dict0, &(dict_ptr->entry[0]), dict_ptr->entry_cnt, root1));

    // root1 = root1->child;
    // pldm_cjson_cal_len_to_root1(root1);
    // pldm_cjson_printf_root1(root1);

    // LOG("\nmy_json_json_to_bej\n");
    // u8 *ptr = my_json_json_to_bej(root, bej_test);
    // u8 bej_test_len = ptr - bej_test;
    // LOG("%p, %p, %d", bej_test, ptr, bej_test_len);
    // // pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict0;
    // LOG("total len : %d", pldm_bej_decode(bej_buf, dict0, &(dict_ptr->entry[0]), dict_ptr->entry_cnt, root));
    // root = create_event_schema(1234, dict, anno_dict);
    // u8 *ptr = pldm_bej_encode(root, bej_buf);
    // LOG("encode len : %d", ptr - bej_buf);
    // LOG("\nused space : %d, max_space : %d", pldm_cjson_get_used_space(), MY_CJSON_POLL_SIZE);

    // pldm_bej_encode(root, dictionary);
}