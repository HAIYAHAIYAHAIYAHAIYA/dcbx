#include "pldm_fw_update.h"
#include "sha256.h"
#include "main.h"

u8 str_to_acsll(u8 *s_inchar, u8 s_len, u8 *a_outtxt)
{

    u8 size1 = 0, i = 0;
    for (size1 = 0; size1 < s_len; size1++) {
        if (s_inchar[size1] >= '0' && s_inchar[size1] <= '9') {
            a_outtxt[size1] = s_inchar[size1] - 0x30;
        } else if (s_inchar[size1] >= 'A' && s_inchar[size1] <= 'F') {
            a_outtxt[size1] = s_inchar[size1] - 'A' + 10;
        } else if (s_inchar[size1] >= 'a' && s_inchar[size1] <= 'f') {
            a_outtxt[size1] = s_inchar[size1] - 'a' + 10;
        }
    }
    for (size1 = 0, i = 0; size1 <= s_len; size1++, i++) {
        a_outtxt[i] = (a_outtxt[size1] << 4) | a_outtxt[++size1];
    }
    a_outtxt[i] = '\0';
    return i;
}

void pldm_fwup_analyze_pkg(void)
{
    FILE *pd = NULL;
    u8 b[9000];
    // pd = fopen("upgrade_pldm_fwup_slot.img", "rb");
    pd = fopen("upgrade_pldm_fwup_slot.bin", "rb");
    fread(&b, sizeof(u8), 1024, pd);
    fclose(pd);
    pldm_fwup_pkt_hdr_t *pkt_hdr = (pldm_fwup_pkt_hdr_t *)b;
    for (u8 i = 0; i < 16; i++) {
        LOG("%02x", pkt_hdr->uuid[i]);
    }
    LOG("\n");
    LOG("pkt_hdr_fmt_reversion : %d", pkt_hdr->pkt_hdr_fmt_reversion);
    LOG("pkt_hdr_size : %d", pkt_hdr->pkt_hdr_size);
    LOG("year : %d", pkt_hdr->pkt_release_datetime.year);
    LOG("mon : %d", pkt_hdr->pkt_release_datetime.mon);
    LOG("day : %d", pkt_hdr->pkt_release_datetime.day);
    LOG("hour : %d", pkt_hdr->pkt_release_datetime.hour);
    LOG("min : %d", pkt_hdr->pkt_release_datetime.min);
    LOG("sec : %d", pkt_hdr->pkt_release_datetime.sec);
    LOG("offset : %d", pkt_hdr->pkt_release_datetime.utc_offset);
    LOG("time_resolution : %d", pkt_hdr->pkt_release_datetime.time_resolution);
    LOG("utc_resolution : %d", pkt_hdr->pkt_release_datetime.utc_resolution);
    LOG("comp_bitmap_bitlen : %d", pkt_hdr->comp_bitmap_bitlen);
    LOG("pkt_ver_str_type : %d", pkt_hdr->pkt_ver_str_type);
    LOG("pkt_ver_str_len : %d", pkt_hdr->pkt_ver_str_len);
    for (u8 i = 0; i < pkt_hdr->pkt_ver_str_len; i++) {
        LOG("%c", pkt_hdr->pkt_ver_str[i]);
    }
    LOG("\n");

    pldm_fwup_fw_dev_indentification_area_t *fw_dev_area = (pldm_fwup_fw_dev_indentification_area_t *)&(pkt_hdr->pkt_ver_str[pkt_hdr->pkt_ver_str_len]);
    LOG("dev_id_record_cnt : %d", fw_dev_area->dev_id_record_cnt);
    pldm_fwup_fw_dev_id_records_first_part_t *fw_records_first_ptr = (pldm_fwup_fw_dev_id_records_first_part_t *)fw_dev_area->fw_dev_id_records;
    LOG("record_len : %d", fw_records_first_ptr->record_len);
    LOG("descriptor_cnt : %d", fw_records_first_ptr->descriptor_cnt);
    LOG("dev_up_op_flgs : %d", fw_records_first_ptr->dev_up_op_flgs);
    LOG("comp_img_set_ver_str_type : %d", fw_records_first_ptr->comp_img_set_ver_str_type);
    LOG("comp_img_set_ver_str_len : %d", fw_records_first_ptr->comp_img_set_ver_str_len);
    LOG("fw_dev_pkt_data_len : %d", fw_records_first_ptr->fw_dev_pkt_data_len);
    LOG("applicable_comps : %d", fw_records_first_ptr->applicable_comps);
    LOG("comp_img_set_ver_str : %s", fw_records_first_ptr->comp_img_set_ver_str);
    pldm_fwup_fw_dev_id_records_middle_part_t *fw_records_middle_ptr = (pldm_fwup_fw_dev_id_records_middle_part_t *)&(fw_records_first_ptr->comp_img_set_ver_str[fw_records_first_ptr->comp_img_set_ver_str_len]);
    pldm_add_descriptor_t *ptr = &(fw_records_middle_ptr->descriptor);
    for (u8 i = 0; i < fw_records_first_ptr->descriptor_cnt; i++) {
        LOG("add_type : %d", ptr->add_type);
        LOG("add_len : %d", ptr->add_len);
        for (u8 j = 0; j < ptr->add_len; j++) {
            LOG("%x ", ptr->add_data[j]);
        }
        LOG("\n");
        ptr = (pldm_add_descriptor_t *)&(ptr->add_data[ptr->add_len]);
    }
    pldm_fwup_fw_dev_id_records_end_part_t *fw_records_end_ptr = (pldm_fwup_fw_dev_id_records_end_part_t *)ptr;
    for (u8 i = 0; i < fw_records_first_ptr->fw_dev_pkt_data_len; i++) {
        LOG("%#x ", fw_records_end_ptr->fw_dev_pkt_data[i]);
    }
    LOG("\n");

    pldm_fwup_comp_img_info_area_t *comp_img_area = (pldm_fwup_comp_img_info_area_t *)&(fw_records_end_ptr->fw_dev_pkt_data[fw_records_first_ptr->fw_dev_pkt_data_len]);
    LOG("comp_img_cnt : %d", comp_img_area->comp_img_cnt);
    pldm_fwup_comp_img_info_first_part_t *comp_first_part = (pldm_fwup_comp_img_info_first_part_t *)comp_img_area->comp_img_info;
    for (u8 i = 0; i < comp_img_area->comp_img_cnt; i++) {
        LOG("comp_classification : %d", comp_first_part->comp_classification);
        LOG("comp_identifier : %d", comp_first_part->comp_identifier);
        LOG("comp_comparison_stamp : %#x", comp_first_part->comp_comparison_stamp);
        LOG("comp_options : %d", comp_first_part->comp_options);
        LOG("req_comp_acti_method : %d", comp_first_part->req_comp_acti_method);
        LOG("comp_local_offset : %d", comp_first_part->comp_local_offset);
        LOG("comp_size : %d", comp_first_part->comp_size);
        LOG("comp_ver_str_type : %d", comp_first_part->comp_ver_str_type);
        LOG("comp_ver_str_len : %d", comp_first_part->comp_ver_str_len);
        for (u8 j = 0; j < comp_first_part->comp_ver_str_len; j++) {
            LOG("%x ", comp_first_part->comp_ver_str[j] - '0');            /* ascii */
        }
        LOG("\n");
        // pldm_fwup_comp_img_info_end_part_t *comp_end_part = (pldm_fwup_comp_img_info_end_part_t *)&(comp_first_part->comp_ver_str[comp_first_part->comp_ver_str_len]);
        // LOG("comp_opaque_data_len : %d", comp_end_part->comp_opaque_data_len);
        comp_first_part = (pldm_fwup_comp_img_info_first_part_t *)&(comp_first_part->comp_ver_str[comp_first_part->comp_ver_str_len]);
    }
    pldm_fwup_comp_img_info_end_part_t *crc32 = (pldm_fwup_comp_img_info_end_part_t *)comp_first_part;
    u32 cal_crc32 = crc32_pldm(b, pkt_hdr->pkt_hdr_size - sizeof(u32));
    LOG("pkt_hdr_crc32 : %#x", crc32->pkt_hdr_crc32);
    LOG("check result : %s", cal_crc32 == crc32->pkt_hdr_crc32 ? "success" : "false");
    // LOG("%s", (u8 *)comp_first_part + sizeof(u32));
}

void pldm_fwup_verify_pkt_data_test(void)
{
    // u8 *str = "amber_vxx.xx.xx.xx";
    // u8 ascii[256];
    // LOG("str_to_acsll : %s", str);
    // for (u8 i = 0; i < strlen(str); i++) {
    //     LOG("%02x ", str[i]);
    // }
    // LOG("\n");
    // u8 len = str_to_acsll(str, strlen(str), ascii);
    // for (u8 i = 0; i < len; i++) {
    //     LOG("%02x ", ascii[i]);
    // }
    pldm_fwup_analyze_pkg();
}
