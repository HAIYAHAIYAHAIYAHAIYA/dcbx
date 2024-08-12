#include "pldm_data.h"
#include "main.h"
#include "pdr.h"
#include "pldm_fw_update.h"
#include "pldm_redfish.h"

static u8 pldm_static_data[PLDM_STATIC_DATA_MAX_LEN];

extern void CM_FLASH_READ(char *file_name, u32 offset, u32 *buf, u32 size);
extern void pldm_monitor_printf_repo(pldm_pdr_t *repo);
extern void pldm_pool_init(void);
extern u32 pldm_pdr_get_used(void);

static void pldm_pdr_selftest(pldm_data_hdr_t *hdr)
{
    pldm_pdr_data_hdr_t pdr_data_hdr;
    u8 pdr_hdr_len = sizeof(pldm_pdr_data_hdr_t);

    u8 *buf = pdr_malloc(hdr->pldm_pdr_size - pdr_hdr_len);
    CM_FLASH_READ(PLDM_DATA_PATH, (hdr->pldm_pdr_off + pdr_hdr_len), (u32 *)buf, (hdr->pldm_pdr_size - pdr_hdr_len) / 4);

    pldm_pdr_t repo;

    CM_FLASH_READ(PLDM_DATA_PATH, hdr->pldm_pdr_off , (u32 *)&pdr_data_hdr, 1);

    u16 pdr_data_len = pdr_data_hdr.total_size - sizeof(pldm_pdr_data_hdr_t);

    LOG("[%s], total len : %d, cnt : %d", __FUNCTION__, pdr_data_hdr.total_size, pdr_data_hdr.cnt);

    u8 *ptr = buf;

    pldm_pdr_init(&repo);

    for (u8 i = 0; i < pdr_data_hdr.cnt; i++) {
        pldm_pdr_hdr_t *pdr_hdr = (pldm_pdr_hdr_t *)ptr;
        u16 pdr_size = pdr_hdr->length + sizeof(pldm_pdr_hdr_t);
        pldm_pdr_add(&repo, ptr, pdr_size, pdr_hdr->record_handle);
        ptr += pdr_size;
    }
    pldm_monitor_printf_repo(&repo);
    pldm_pdr_get_used();
    pdrs_pool_reinit();
}

static void pldm_fwup_info_selftest(pldm_data_hdr_t *hdr)
{
    CM_FLASH_READ(PLDM_DATA_PATH, hdr->pldm_fwup_info_off, (u32 *)pldm_static_data, hdr->pldm_fwup_info_size / 4);

    pldm_fw_img_info_t *fw_img_info = (pldm_fw_img_info_t *)pldm_static_data;
    LOG("active_img_state : %d", fw_img_info->active_img_state);

    LOG("comp_img_set_ver_str_type : %d", fw_img_info->fw_img_info.comp_img_set_ver_str_type);
    LOG("comp_img_set_ver_str_len : %d", fw_img_info->fw_img_info.comp_img_set_ver_str_len);
    for (u8 j = 0; j < fw_img_info->fw_img_info.comp_img_set_ver_str_len; j++) {
        printf("%c", fw_img_info->fw_img_info.val[j]);
    }
    printf("\n");

    pldm_fwup_comp_info_t *comp_info = (pldm_fwup_comp_info_t *)&(fw_img_info->fw_img_info.val[34]);

    for (u8 i = 0; i < 3; i++) {
        LOG("comp_classification : %d", comp_info->comp_classification);
        LOG("comp_identifier : %d", comp_info->comp_identifier);
        LOG("comp_classification_idx : %d", comp_info->comp_classification_idx);
        LOG("methon : %#x", comp_info->methon);
        LOG("comp_img_set_ver_str_type : %d", comp_info->info.comp_img_set_ver_str_type);
        LOG("comp_img_set_ver_str_len : %d", comp_info->info.comp_img_set_ver_str_len);
        for (u8 j = 0; j < comp_info->info.comp_img_set_ver_str_len; j++) {
            printf("%c", comp_info->info.val[j]);
        }
        printf("\n");
        comp_info = (pldm_fwup_comp_info_t *)&(comp_info->info.val[comp_info->info.comp_img_set_ver_str_len]);
    }
}

static void pldm_redfish_schema_selftest(pldm_data_hdr_t *hdr)
{
    CM_FLASH_READ(PLDM_DATA_PATH, hdr->pldm_redfish_schema_off, (u32 *)pldm_static_data, hdr->pldm_redfish_schema_size / 4);

    pldm_redfish_schema_data_hdr_t *redfish_schema_data_hdr = (pldm_redfish_schema_data_hdr_t *)pldm_static_data;

    pldm_redfish_bej_t *bej_ptr = (pldm_redfish_bej_t *)&pldm_static_data[sizeof(pldm_redfish_schema_data_hdr_t)];

    LOG("[%s], total len : %d, cnt : %d", __FUNCTION__, redfish_schema_data_hdr->total_size, redfish_schema_data_hdr->cnt);

    for (u8 i = 0; i < redfish_schema_data_hdr->cnt; ++i) {
        LOG("etag : %s, len : %d", bej_ptr->etag, bej_ptr->len);
        bej_ptr = (pldm_redfish_bej_t *)((u8 *)bej_ptr + sizeof(pldm_redfish_bej_t));
    }
}

void pldm_data_analyze(void)
{
    LOG("HELLO WORLD!");
    FILE *fp = NULL;

    fp = fopen(PLDM_DATA_PATH, "rb+");
    if (!fp) {
        LOG("[%s], can not open file!", __FUNCTION__);
        return;
    }

    pldm_data_hdr_t pldm_data_hdr;
    // fseek(fp, 0xFF000, SEEK_SET);
    fread(&pldm_data_hdr, sizeof(u8), sizeof(pldm_data_hdr_t), fp);
    LOG("pldm_pdr            -> off : %05d, size : %d", pldm_data_hdr.pldm_pdr_off, pldm_data_hdr.pldm_pdr_size);
    LOG("pldm_fwup_info      -> off : %05d, size : %d", pldm_data_hdr.pldm_fwup_info_off, pldm_data_hdr.pldm_fwup_info_size);
    LOG("pldm_redfish_dict   -> off : %05d, size : %d", pldm_data_hdr.pldm_redfish_dict_off, pldm_data_hdr.pldm_redfish_dict_size);
    LOG("pldm_redfish_schema -> off : %05d, size : %d", pldm_data_hdr.pldm_redfish_schema_off, pldm_data_hdr.pldm_redfish_schema_size);

    pldm_pool_init();

    pldm_pdr_selftest(&pldm_data_hdr);
    pldm_fwup_info_selftest(&pldm_data_hdr);
    // pldm_redfish_schema_selftest(&pldm_data_hdr);

}