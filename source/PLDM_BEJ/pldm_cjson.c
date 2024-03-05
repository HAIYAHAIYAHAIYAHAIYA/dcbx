#include "pldm_cjson.h"
#include "pldm_bej_resolve.h"

static u8 gs_pldm_cjson_buf[MY_CJSON_POLL_SIZE];
static u8 *gs_pldm_cjson_pool;
static u16 gs_pldm_cjson_wt;
u8 dict_test[1024];
u8 anno_dict_test[1024];
u8 bej_test[1024];

void pldm_cjson_pool_init(void)
{
    gs_pldm_cjson_pool = gs_pldm_cjson_buf;
    gs_pldm_cjson_wt = 0;
}

void *pldm_cjson_malloc(u16 size)
{
    // size = ALIGN(size, 1);
    // if (gs_pldm_cjson_wt + size >= MY_CJSON_POLL_SIZE) {
    //     printf("no more space\n");
    //     return NULL;
    // }
    // u8 *pt = gs_pldm_cjson_pool + gs_pldm_cjson_wt;
    gs_pldm_cjson_wt += size;
    u8 *pt = malloc(size);
    memset((void *)pt, 0, size);
    return pt;
}

static void pldm_cjson_free(u8 *addr)
{
    if (!addr) return;
    free(addr);
}

void pldm_cjson_delete_node(pldm_cjson_t *node)
{
    if (!node) return;
    pldm_cjson_delete_node(node->next);
    pldm_cjson_delete_node(node->child);
    // printf("\nseq : %d, fmt : 0x%02x, len : %d, name : %s : ", node->sflv.seq >> 1, node->sflv.fmt, node->sflv.len, node->name);
    pldm_cjson_free((u8 *)node->name);
    node->name = NULL;
    if (node->next) node->next = NULL;
    if (node->child) node->child = NULL;
    pldm_cjson_free((u8 *)node);
    node = NULL;
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

static pldm_cjson_t *pldm_cjson_add_sflv_attr(pldm_cjson_t *leaf, pldm_bej_sflv_dat_t *sflv, char *name, char *val, u8 len)
{
    if (!leaf || !sflv || !val || !name) return NULL;
    leaf->sflv = *sflv;
    memcpy(leaf->sflv.val, val, len);
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
            if (!tmp->child) {
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
        // printf("seq : 0x%x, fmt : 0x%x, len : %d\n", tmp->sflv.seq, tmp->sflv.fmt, tmp->sflv.len);
        if (tmp->name) printf("\nseq : %d, fmt : 0x%02x, len : %d, name : %s : ", tmp->sflv.seq >> 1, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
        u8 fmt = tmp->sflv.fmt >> 4;
        if (fmt != BEJ_ENUM) pldm_cjson_printf_root1(tmp->child);
        if (!tmp->child && tmp->name) {
            u8 fmt = tmp->sflv.fmt >> 4;
            for (u8 i = 0; i < tmp->sflv.len; i++) {
                switch (fmt) {
                    case BEJ_INT:
                        printf("0x%02x ", tmp->sflv.val[i]);
                    break;
                    case BEJ_ENUM:
                        printf("0x%x ", tmp->sflv.val[i]);
                    break;
                    default:
                        printf("%c", tmp->sflv.val[i]);
                    break;
                }
            }
        } else {
            if (fmt == BEJ_ENUM) {
                for (u8 i = 0; i < tmp->sflv.len; i++) {
                    printf("0x%x ", tmp->sflv.val[i]);
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
	printf("\nseq : %d, fmt : 0x%02x, len : %d, name : %s :", tmp->sflv.seq >> 1, tmp->sflv.fmt, tmp->sflv.len, tmp->name);
    u8 fmt = tmp->sflv.fmt >> 4;
	if (fmt != BEJ_ENUM) pldm_cjson_printf_root(tmp->child);
    if (!tmp->child) {
        u8 fmt = tmp->sflv.fmt >> 4;
        for (u8 i = 0; i < tmp->sflv.len; i++) {
            switch (fmt) {
                case BEJ_INT:
                    printf("%d", tmp->sflv.val[i]);
                break;
                default:
                    printf("%c", tmp->sflv.val[i]);
                break;
            }
        }
    } else {
        if (fmt == BEJ_ENUM) {
            for (u8 i = 0; i < tmp->sflv.len; i++) {
                printf("0x%x ", tmp->sflv.val[i]);
            }
        }
    }
	pldm_cjson_printf_root(tmp->next);
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
                    str[1] = 0xFF;
                } else {
                    str[1] = idx;
                }
                pldm_cjson_replace_val(root, sflv, str);
                pldm_cjson_cal_len_to_root1(root, 0xFF);
                break;
            }
            idx++;
        }
    }
}

pldm_cjson_t *pldm_cjson_read(pldm_cjson_t *root, u16 collection_skip, u16 collection_top)
{
    if (!root) return NULL;
    return root;
}

pldm_cjson_t *pldm_cjson_update(pldm_cjson_t *root, pldm_cjson_t *update_node)
{
    if (!root || !update_node) return NULL;
    is_find = NULL;
    pldm_cjson_find_name(root, update_node->name);
    if (is_find) {
        pldm_cjson_delete_node(is_find->child);
        is_find->sflv = update_node->sflv;
        is_find->child = update_node->child;
        update_node->child = NULL;
        pldm_cjson_delete_node(update_node);
    }
    return root;
}

pldm_cjson_t *pldm_cjson_replace(pldm_cjson_t *root, pldm_cjson_t *replace_node)
{
    if (!root || !replace_node) return NULL;
    pldm_cjson_delete_node(root);
    return replace_node;
}

/* to be determind */
pldm_cjson_t *pldm_cjson_action(pldm_cjson_t *root)
{
    if (!root) return NULL;
    return root;
}

pldm_cjson_t *pldm_cjson_head(pldm_cjson_t *root)
{
    if (!root) return NULL;
    return root;
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
        // if (num <= 0xFF) {
        //     str[0] = num;
        // } else {
        //     str[0] = num & 0xFF;
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
                            str[1] = 0xFF;
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

void pldm_cjson_fill_dict_hdr(pldm_cjson_t *root, u8 *dictionary)
{
    if (!root || !dictionary) return;
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
        // printf("seq : %d, fmt : %d, len : %d, name : %s\n", q->sflv.seq, q->sflv.fmt, q->sflv.len, q->name);
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
                    memcpy(dict_name + offset, name, strlen(name) + 1);   /* terminal is '\0' */
                    dict->entry[entry_cnt].name_off = (dict_name - dictionary) + offset;
                    offset += strlen(name) + 1;
                }
                entry_cnt++;
                // printf("\n%s %d", name, entry_cnt);
            }
        }

        if (front == rear) {
            u8 cnt = rear - have_child;
            // printf("cnt : %d\n", cnt);
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

    for (; root; root = root->next) {
        queue[++rear] = root;
    }
    have_child = front;
	while (front != rear)
	{
		q = queue[++front];
		// printf("seq : %d, fmt : %d, len : %d, name : %s\n", q->sflv.seq >> 1, q->sflv.fmt, q->sflv.len, q->name);
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
            // printf("cnt : %d\n", cnt);
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
    // printf("entry cnt : %d\n", entry_cnt);
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
        // printf("%d, %s\n", queue[front]->sflv.seq >> 1, queue[front]->name);
		// printf("seq : %d, fmt : %d, len : %d, name : %s\n", queue[front]->sflv.seq, queue[front]->sflv.fmt, queue[front]->sflv.len, queue[front]->name);
        if (front == rear) {
            u8 cnt = rear - have_child;
            // CM_LOG_INFO("cnt : %d", cnt);
            for (u8 k = 0; k < cnt; k++) {
                pldm_cjson_t *tmp = queue[have_child + k + 1];
                if (tmp->child) {
                    for (; i < dict->entry_cnt; i++) {
                        if (strcmp((char *)&dictionary[dict->entry[i].name_off], tmp->name) == 0) {
                            break;
                        }
                    }
                    for (u16 j = i; j < dict->entry_cnt; j++) {
                        // printf("\nname : %s %s", &dictionary[dict->entry[j].name_off], tmp->child->name);
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
    //     printf("child_cnt : %d, child_off : %s, name : %s\n", dict->entry[k].child_cnt, &dictionary[entry->name_off], &dictionary[dict->entry[k].name_off]);
    // }
}

void pldm_cjson_fill_dict_copyright(pldm_cjson_t *root, u8 *dictionary, char *copyright_name)
{
    if (!root || !dictionary) return;
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    u16 offset = 0;
    if (dict->entry_cnt)
        offset = dict->entry[dict->entry_cnt - 1].name_off + dict->entry[dict->entry_cnt - 1].name_len + 1;
    else
        offset = 12;
    pldm_redfish_dictionary_copyright_t *copyright = (pldm_redfish_dictionary_copyright_t *)&(dictionary[offset]);
    copyright->copyright_len = strlen(copyright_name) + 1;
    memcpy(copyright->copyright, copyright_name, copyright->copyright_len);
    dict->dictionary_size = copyright->copyright + copyright->copyright_len - dictionary;
    // printf("entry_cnt : %d\n", dict->entry_cnt);
}

void pldm_cjson_printf_dict(u8 *dictionary)
{
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    printf("\nversion_tag : %d\n", dict->version_tag);
    printf("schema_version : %d\n", dict->schema_version);
    printf("entry_cnt : %d\n", dict->entry_cnt);
    printf("dictionay_flags : %d\n", dict->dictionay_flags);
    printf("dictionary_size : %d\n", dict->dictionary_size);
    for (u16 i = 0; i < dict->entry_cnt; i++) {
        printf("child_cnt : %d, seq : %d, fmt : %d name : ", dict->entry[i].child_cnt, dict->entry[i].sequence_num, dict->entry[i].format >> 4);
        for (u16 j = 0; j < dict->entry[i].name_len; j++) {
            u8 *name = &dictionary[dict->entry[i].name_off];
            printf("%c", name[j]);
        }
        printf(" name off : %d, child off : %d, offset : %d" , dict->entry[i].name_off, dict->entry[i].childpoint_off, (u8 *)&(dict->entry[i]) - dictionary);
        printf("\n");
    }
    u16 offset = dict->entry[dict->entry_cnt - 1].name_off + dict->entry[dict->entry_cnt - 1].name_len;
    pldm_redfish_dictionary_copyright_t *copyright = (pldm_redfish_dictionary_copyright_t *)&(dictionary[offset]);
    printf("offset : %d, copyright len : %d, copyright : %s\n", offset, copyright->copyright_len, copyright->copyright);
    // for (u16 i = 0; i < dict->dictionary_size; i++) {
    //     printf("0x%02x, ", dictionary[i]);
    //     if (!((i + 1) % 8)) {
    //         printf("\n");
    //     }
    // }
}

void pldm_cjson_create_dict(pldm_cjson_t *root, u8 *dictionary, u8 is_anno_dict)
{
    if (!root || !dictionary) return;
    pldm_redfish_dictionary_format_t *dict = (pldm_redfish_dictionary_format_t *)dictionary;
    pldm_cjson_fill_dict_hdr(root, dictionary);
    pldm_cjson_fill_dict_entry_data(root, dictionary, is_anno_dict);
    pldm_cjson_fill_dict_str(root, dictionary, is_anno_dict);
    pldm_cjson_fill_dict_child(root, dictionary);
    pldm_cjson_fill_dict_copyright(root, dictionary, "Copyright (c) 2018 DMTF");
    // pldm_cjson_fill_dict_copyright(root, dictionary, "made in china");
    pldm_cjson_printf_dict(dictionary);
}

extern u8 dict0[];
extern u8 dict1[];
extern u8 *json_buf;
extern u8 bej_buf[];
extern u8 bej_buf1[];

void fill_comm_field_in_schema(pldm_cjson_t *root, char *schema_name, u8 is_collection, u32 id, char *type, char *etag, char *context, char *healthrollupdescription, char *healthrollup)
{
    char str[16];
    char name[64];
    // memset(str, 0, strlen(str));
    pldm_bej_sflv_dat_t sflv;
    sprintf(str, "%d", id);

    u8 name_len = strlen(schema_name);
    memcpy(name, schema_name, name_len);

    char *key[6] = {
        "@odata.id",
        "@odata.type",
        "@odata.etag",
        "@odata.context",
        "Status.health/Status.healthRollupDescription",
        "Status.health/Status.healthRollup"
    };
    char *val[6] = {str, type, etag, context, healthrollupdescription, healthrollup};
    u8 cnt = is_collection ? 4 : 6;
    for (u8 i = 0; i < cnt; i++) {
        sflv.fmt = BEJ_STR << 4;
        if (i <= 3) {
            sflv.seq = 1;
            memcpy(&name[name_len], key[i], strlen(key[i]));
            name[name_len + strlen(key[i])] = '\0';
            pldm_cjson_add_item_to_obj(root, &sflv, name, val[i], strlen(val[i]));
        }else {
            sflv.seq = 0;
            pldm_cjson_add_item_to_obj(root, &sflv, key[i], val[i], strlen(val[i]));
        }
    }
}

pldm_cjson_t *create_port_v1_3_1_schema(u32 resource_id)
{
    pldm_bej_sflv_dat_t sflv;
    char str[16] = {0x01, 0x01, 0x00};
    pldm_cjson_t *root = NULL;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_add_sflv_attr(root, &sflv, "Action", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_t *obj = pldm_cjson_add_item_to_obj(root, &sflv, "Reset", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "target", "\%T12.0", strlen("\%T12.0"));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "title", "#Port.Reset", strlen("#Port.Reset"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "CurrentSpeedGbps", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj1 = pldm_cjson_add_item_to_obj(root, &sflv, "Ethernet", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj3 = pldm_cjson_add_item_to_obj(obj1, &sflv, "FlowControlStatus", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj3, &sflv, "None", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj3, &sflv, "TX", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj3, &sflv, "RX", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj3, &sflv, "TX_RX", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj2 = pldm_cjson_add_item_to_obj(obj1, &sflv, "FlowControlConfiguration", str, strlen(str));

    pldm_cjson_add_child(obj2, obj3->child);                    /* same enum */

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj4 = pldm_cjson_add_item_to_obj(obj1, &sflv, "SupportedEthernetCapabilities", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj4, &sflv, "EEE", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj4, &sflv, "WakeOnLAN", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "Id", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_BOOLEAN << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "InterfaceEnabled", "f", strlen("f"));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj5 = pldm_cjson_add_item_to_obj(root, &sflv, "LinkConfiguration", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_BOOLEAN << 4;
    pldm_cjson_add_item_to_obj(obj5, &sflv, "AutoSpeedNegotiationCapable", "f", strlen("f"));

    sflv.seq = 0;
    sflv.fmt = BEJ_BOOLEAN << 4;
    pldm_cjson_add_item_to_obj(obj5, &sflv, "AutoSpeedNegotiationEnable", "f", strlen("f"));

    sflv.seq = 0;
    sflv.fmt = BEJ_ARRAY << 4;
    pldm_cjson_t *obj6 = pldm_cjson_add_item_to_obj(obj5, &sflv, "CapableLinkSpeedGbps", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj6, &sflv, "", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj6, &sflv, "", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj6, &sflv, "", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj6, &sflv, "", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj7 = pldm_cjson_add_item_to_obj(root, &sflv, "LinkNetworkTechnology", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj7, &sflv, "Ethernet", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj7, &sflv, "InfiniBand", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj7, &sflv, "FibreChannel", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj7, &sflv, "GenZ", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj8 = pldm_cjson_add_item_to_obj(root, &sflv, "LinkState", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj8, &sflv, "Enabled", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj8, &sflv, "Disabled", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj9 = pldm_cjson_add_item_to_obj(root, &sflv, "LinkStatus", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj9, &sflv, "LinkUp", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj9, &sflv, "Starting", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj9, &sflv, "Training", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj9, &sflv, "LinkDown", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj9, &sflv, "NoLink", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "LinkTransitionIndicator", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_ARRAY << 4;
    pldm_cjson_t *obj10 = pldm_cjson_add_item_to_obj(root, &sflv, "MaxFrameSize", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj10, &sflv, "", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "MaxSpeedGbps", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "Name", "AM_Port", strlen("AM_Port"));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "Oem", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "Status", "Enabled", strlen("Enabled"));

    fill_comm_field_in_schema(root, "Port", 0, resource_id, "Port.1_3_1.Port", "etag", "", "Normal", "Normal");

    return root;
}

pldm_cjson_t *create_port_collection_schema(u32 resource_id)
{
    pldm_bej_sflv_dat_t sflv;
    char str[16] = {0x01, 0x01, 0x00};
    memset(str, 0, sizeof(str));
    pldm_cjson_t *root = NULL;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj = pldm_cjson_add_sflv_attr(root, &sflv, "", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Name", "Ports", strlen("Ports"));

    sflv.seq = 1;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Member@odata.count", "1", strlen("1"));

    sflv.seq = 0;
    sflv.fmt = BEJ_ARRAY << 4;
    pldm_cjson_t *obj1 = pldm_cjson_add_item_to_obj(obj, &sflv, "Member", "", strlen(""));

    sprintf(&str[1], "%d", 1234);

    sflv.seq = 0;
    sflv.fmt = BEJ_RESOURCE_LINK << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "", &str[1], strlen(&str[1]));

    fill_comm_field_in_schema(obj, "PortCollection", 1, resource_id, "PortCollection.1_3_1.PortCollection", "etag", "", "Normal", "Normal");

    return root;
}

pldm_cjson_t *create_networkinterface_v1_2_0_schema(u32 resource_id)
{
    pldm_bej_sflv_dat_t sflv;
    char str[16] = {0x01, 0x01, 0x00};
    memset(str, 0, sizeof(str));
    pldm_cjson_t *root = NULL;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj = pldm_cjson_add_sflv_attr(root, &sflv, "", "", strlen(""));

    sprintf(&str[1], "%d", 1234);

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Links.NetworkAdapter", &str[1], strlen(&str[1]));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Name", "AM Network Interface", strlen("AM Network Interface"));

    sflv.seq = 0;
    sflv.fmt = BEJ_RESOURCE_LINK << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "NetworkDeviceFunctions", &str[1], strlen(&str[1]));

    sflv.seq = 0;
    sflv.fmt = BEJ_RESOURCE_LINK << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Ports", &str[1], strlen(&str[1]));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj1 = pldm_cjson_add_item_to_obj(obj, &sflv, "Status", "", strlen(""));

    str[0] = 0x01;
    str[1] = 0x01;
    str[2] = 0;

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj2 = pldm_cjson_add_item_to_obj(obj1, &sflv, "State", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj2, &sflv, "StandbyOffline", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj2, &sflv, "Starting", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj2, &sflv, "Updating", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj2, &sflv, "Enabled", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "ID", "%I5", strlen("%I5"));

    fill_comm_field_in_schema(obj, "NetworkInterface", 0, resource_id, "NetworkInterface.1_2_1.NetworkInterface", "etag", "", "Normal", "Normal");

    return root;
}

pldm_cjson_t *create_networkadapter_v1_5_0_schema(u32 resource_id)
{
    pldm_bej_sflv_dat_t sflv;
    char str[16] = {0x01, 0x01, 0x00};
    memset(str, 0, sizeof(str));
    pldm_cjson_t *root = NULL;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj = pldm_cjson_add_sflv_attr(root, &sflv, "", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Actions", "ResetSettingsToDefault", strlen("ResetSettingsToDefault"));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj1 = pldm_cjson_add_item_to_obj(obj, &sflv, "Controllers", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj2 = pldm_cjson_add_item_to_obj(obj1, &sflv, "ControllerCapabilities", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj3 = pldm_cjson_add_item_to_obj(obj2, &sflv, "DataCenterBridging", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_BOOLEAN << 4;
    pldm_cjson_add_item_to_obj(obj3, &sflv, "Capable", "t", strlen("t"));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "Actions", "ResetSettingsToDefault", strlen("ResetSettingsToDefault"));

    return root;
}

pldm_cjson_t *create_anno_dict(void)
{
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_t *root = NULL;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_add_sflv_attr(root, &sflv, "Annotation", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_INT << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "Events@odata.count", "", strlen(""));

    return root;
}

pldm_cjson_t *create_event_dict(u32 resource_id)
{
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_t *root = NULL;
    char str[16] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x00};

    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_add_sflv_attr(root, &sflv, "", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ARRAY << 4;
    pldm_cjson_t *obj = pldm_cjson_add_item_to_obj(root, &sflv, "Events", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_ENUM << 4;
    pldm_cjson_t *obj1 = pldm_cjson_add_item_to_obj(obj, &sflv, "EventType", str, strlen(str));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "StatusChange", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "ResourceUpdated", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "ResourceAdded", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "ResourceRemoved", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj1, &sflv, "Alert", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "MemberId", "Alert", strlen("Alert"));

    sflv.seq = 0;
    sflv.fmt = BEJ_ARRAY << 4;
    pldm_cjson_t *obj2 = pldm_cjson_add_item_to_obj(obj, &sflv, "MessageArgs", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj2, &sflv, "", "Alert", strlen("Alert"));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(obj, &sflv, "MessageId", "NetworkDevice.1.0.CableInserted", strlen("NetworkDevice.1.0.CableInserted"));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_t *obj3 = pldm_cjson_add_item_to_obj(obj, &sflv, "OriginOfCondition", "", strlen(""));

    sprintf(&str[1], "%d", resource_id);

    sflv.seq = 1;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_t *obj4 = pldm_cjson_add_item_to_obj(obj3, &sflv, "@odata.id", &str[1], strlen(&str[1]));

    sflv.seq = 1;
    sflv.fmt = BEJ_INT << 4;
    str[1] = 1;
    str[2] = 1;
    str[3] = 1;
    str[4] = 0;
    pldm_cjson_add_item_to_obj(root, &sflv, "Events@odata.count", &str[1], strlen(&str[1]));

    sflv.seq = 0;
    sflv.fmt = BEJ_STR << 4;
    pldm_cjson_add_item_to_obj(root, &sflv, "ID", "1", strlen("1"));

    fill_comm_field_in_schema(root, "Events", 0, resource_id, "Event.1_0_2.Event", "etag", "", "Normal", "Normal");

    return root;
}

void create_networkdevice_registry_v1_0_1_schema(u8 trriger_cond, u8 *registry_bejbuf, u8 *registry_dict)
{
    pldm_cjson_t *root = NULL;
    pldm_cjson_t *obj = NULL;
    pldm_cjson_t *obj1 = NULL;
    pldm_cjson_t *obj2 = NULL;
    pldm_bej_sflv_dat_t sflv;
    pldm_bej_sflv_dat_t sflv1;
    root = pldm_cjson_create_obj();
    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4;
    pldm_cjson_add_sflv_attr(root, &sflv, "registry", "", strlen(""));

    sflv.seq = 0;
    sflv.fmt = BEJ_SET << 4 | 0x02;              /* read only */

    sflv1.seq = 0;
    sflv1.fmt = BEJ_STR << 4 | 0x02;              /* read only */

    // if (trriger_cond & REGISTRY_CONNECTIONDROPPED) 
        obj = pldm_cjson_add_item_to_obj(root, &sflv, "ConnectionDropped", "", strlen(""));
    // if (trriger_cond & REGISTRY_CONNECTIONESTABLISHED) 
        obj1 = pldm_cjson_add_item_to_obj(root, &sflv, "ConnectionEstablished", "", strlen(""));
    // if (trriger_cond & REGISTRY_LINKFLAPDETECTED) 
        obj2 = pldm_cjson_add_item_to_obj(root, &sflv, "LinkFlapDetected", "", strlen(""));

    pldm_cjson_t *objs[] = {obj, obj1, obj2};
    /* PLDM_BASE_PORT_RESOURCE_ID = 100 */
    /* PLDM_BASE_NETWORK_DEV_FUNC_RESOURCE_ID = 200 */
    /* PLDM_BASE_NETWORK_ADAPTER_RESOURCE_ID = 1 */
    char *ids[] = {"1", "100", "200",};
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 3; j++) {
            pldm_cjson_add_item_to_obj(objs[i], &sflv1, "Id", ids[j], strlen(ids[j]));
        }
    }

    sflv1.seq = 0;
    sflv1.fmt = BEJ_INT << 4 | 0x02;              /* read only */
    /* to be determind */
    /* The number of times the link has flapped. */
    /* The number of minutes over which the link has flapped. */
    pldm_cjson_add_item_to_obj(obj2, &sflv1, "", (char [2]){0x01, 0x00}, 1);
    pldm_cjson_add_item_to_obj(obj2, &sflv1, "", (char [2]){0x01, 0x00}, 1);

    pldm_cjson_cal_len_to_root1(root, 0xFF);
    pldm_cjson_printf_root1(root);
    pldm_bej_encode(root, registry_bejbuf);
    pldm_cjson_create_dict(root, registry_dict, 0);
    pldm_cjson_delete_node(root);
    root = NULL;
    // pldm_cjson_pool_reinit();
}

void pldm_cjson_test(void)
{
    pldm_bej_sflv_dat_t sflv;
    pldm_cjson_t *root = NULL;
    pldm_cjson_t *obj = NULL;
    pldm_cjson_t *obj1 = NULL;
    pldm_cjson_t *obj2 = NULL;
    pldm_cjson_t *obj3 = NULL;

    pldm_cjson_pool_init();
    root = create_networkinterface_v1_2_0_schema(1234);

    // root = pldm_cjson_create_obj();

    // sflv.seq = 0;
    // sflv.fmt = BEJ_SET << 4;
    // pldm_cjson_add_sflv_attr(root, &sflv, "DummySimple", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_ARRAY << 4;
    // obj2 = pldm_cjson_add_item_to_obj(root, &sflv, "ChildArrayProperty", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_SET << 4;
    // obj1 = pldm_cjson_add_item_to_obj(obj2, &sflv, "", "", strlen(""));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_BOOLEAN << 4;
    // // obj = pldm_cjson_add_obj(obj, &sflv, "AnotherBoolean");
    // pldm_cjson_add_item_to_obj(obj1, &sflv, "AnotherBoolean", "true", strlen("true"));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_ENUM << 4;
    // obj = pldm_cjson_add_item_to_obj(obj1, &sflv, "LinkStatus", "LinkUp", strlen("LinkUp"));

    // sflv.seq = 0;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "LinkDown", "", strlen(""));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "LinkUp", "", strlen(""));

    // sflv.seq = 2;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(obj, &sflv, "NoLink", "", strlen(""));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_STR << 4;
    // pldm_cjson_add_item_to_obj(root, &sflv, "Id", "Dummy ID", strlen("Dummy ID"));

    // sflv.seq = 2;
    // sflv.fmt = BEJ_BOOLEAN << 4;
    // pldm_cjson_add_item_to_obj(root, &sflv, "SampleEnabledProperty", "false", strlen("false"));

    // sflv.seq = 3;
    // sflv.fmt = BEJ_INT << 4;
    // char str[2] = {0xc, 0x0};
    // pldm_cjson_add_item_to_obj(root, &sflv, "SampleIntegerProperty", str, strlen(str));

    // sflv.seq = 1;
    // sflv.fmt = BEJ_ENUM << 4;
    // pldm_cjson_replace_enum_val(root, &sflv, "LinkStatus", "LinkUp");

    pldm_cjson_cal_len_to_root1(root, 0xFF);
    pldm_cjson_create_dict(root, dict_test, 0);
    pldm_cjson_create_dict(root, anno_dict_test, 1);
    pldm_cjson_printf_root1(root);

    // FILE *fp;
    // fp = fopen( "dict.txt" , "a" );
    // for (u8 i = 0; i < 2; i++) {
    //     pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict_test;
    //     fwrite(dict_test, sizeof(u8) , dict_ptr->dictionary_size, fp );
    // }

    // fclose(fp);

    printf("\nmy_json_json_to_bej\n");
    u8 *ptr = pldm_bej_encode(root, bej_test);
    pldm_cjson_t *tmp = NULL;
    tmp = pldm_bej_decode1(bej_test, anno_dict_test, dict_test, tmp);
    u8 bej_test_len = ptr - bej_test;
    printf("%p, %p, %d\n", bej_test, ptr, bej_test_len);

    pldm_cjson_cal_len_to_root1(tmp, 0xFF);
    pldm_cjson_printf_root1(tmp);

    // create_networkdevice_registry_v1_0_1_schema(0xff, bej_test, dict_test);

    // pldm_cjson_t *tmp1 = NULL;
    // tmp1 = pldm_bej_decode1(bej_buf1, dict0, tmp1);
    // u8 bej_test_len = ptr - bej_test;
    // printf("%p, %p, %d\n", bej_test, ptr, bej_test_len);

    // tmp1 = pldm_cjson_update(tmp1, tmp);
    // pldm_cjson_cal_len_to_root1(tmp, 0xFF);
    // pldm_cjson_printf_root1(tmp);

    // pldm_cjson_create_dict(root, dict_test);

    // u8 *ptr = pldm_bej_encode(root, bej_test);
    // u8 bej_test_len = ptr - bej_test;

    // for (u16 i = 0; i < bej_test_len; i++) {
    //     printf("0x%02x, ", bej_test[i]);
    //     if (!((i + 1) % 8)) {
    //         printf("\n");
    //     }
    // }

    // pldm_cjson_t *root1 = NULL;
    // root1 = pldm_cjson_create_obj();

    // printf("\ntotal len : %d\n", pldm_bej_decode1(bej_buf1, dict0, &(dict_ptr->entry[0]), dict_ptr->entry_cnt, root1));

    // root1 = root1->child;
    // pldm_cjson_cal_len_to_root1(root1);
    // pldm_cjson_printf_root1(root1);

    // printf("\nmy_json_json_to_bej\n");
    // u8 *ptr = my_json_json_to_bej(root, bej_test);
    // u8 bej_test_len = ptr - bej_test;
    // printf("%p, %p, %d\n", bej_test, ptr, bej_test_len);
    // pldm_redfish_dictionary_format_t *dict_ptr = (pldm_redfish_dictionary_format_t *)dict0;
    // printf("total len : %d\n", pldm_bej_decode1(bej_buf, dict0, &(dict_ptr->entry[0]), dict_ptr->entry_cnt, root));
    printf("\nused space : %d, max_space : %d\n", pldm_cjson_get_used_space(), MY_CJSON_POLL_SIZE);

    // pldm_bej_encode(root, dictionary);
}