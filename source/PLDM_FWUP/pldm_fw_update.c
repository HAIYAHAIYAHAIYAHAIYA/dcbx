#include "pldm_fw_update.h"
#include "sha256.h"
#include "main.h"

void pldm_fwup_verify_pkt_data_test(void)
{
    FILE *pd = NULL;
    u8 b[9000];
    pd = fopen("fwup.img", "rb");
    fread(&b, sizeof(u8), 1024, pd);
    fclose(pd);
    pldm_fwup_pkt_hdr_t *pkt_hdr = (pldm_fwup_pkt_hdr_t *)b;
    for (u8 i = 0; i < 16; i++) {
        printf("%02x", pkt_hdr->uuid[i]);
    }
    printf("\n");
    printf("pkt_hdr_fmt_reversion : %d\n", pkt_hdr->pkt_hdr_fmt_reversion);
    printf("pkt_hdr_size : %d\n", pkt_hdr->pkt_hdr_size);
    printf("year : %d\n", pkt_hdr->pkt_release_datetime.year);
    printf("mon : %d\n", pkt_hdr->pkt_release_datetime.mon);
    printf("day : %d\n", pkt_hdr->pkt_release_datetime.day);
    printf("hour : %d\n", pkt_hdr->pkt_release_datetime.hour);
    printf("min : %d\n", pkt_hdr->pkt_release_datetime.min);
    printf("sec : %d\n", pkt_hdr->pkt_release_datetime.sec);
    printf("offset : %d\n", pkt_hdr->pkt_release_datetime.utc_offset);
    printf("comp_bitmap_bitlen : %d\n", pkt_hdr->comp_bitmap_bitlen);
    printf("pkt_ver_str_type : %d\n", pkt_hdr->pkt_ver_str_type);
    printf("pkt_ver_str_len : %d\n", pkt_hdr->pkt_ver_str_len);
    for (u8 i = 0; i < pkt_hdr->pkt_ver_str_len; i++) {
        printf("%c", pkt_hdr->pkt_ver_str[i]);
    }
    printf("\n");

    pldm_fwup_fw_dev_indentification_area_t *fw_dev_area = (pldm_fwup_fw_dev_indentification_area_t *)&(pkt_hdr->pkt_ver_str[pkt_hdr->pkt_ver_str_len]);
    printf("dev_id_record_cnt : %d\n", fw_dev_area->dev_id_record_cnt);
    pldm_fwup_fw_dev_id_records_first_part_t *fw_records_first_ptr = (pldm_fwup_fw_dev_id_records_first_part_t *)fw_dev_area->fw_dev_id_records;
    printf("record_len : %d\n", fw_records_first_ptr->record_len);
    printf("descriptor_cnt : %d\n", fw_records_first_ptr->descriptor_cnt);
    printf("dev_up_op_flgs : %d\n", fw_records_first_ptr->dev_up_op_flgs);
    printf("comp_img_set_ver_str_type : %d\n", fw_records_first_ptr->comp_img_set_ver_str_type);
    printf("comp_img_set_ver_str_len : %d\n", fw_records_first_ptr->comp_img_set_ver_str_len);
    printf("fw_dev_pkt_data_len : %d\n", fw_records_first_ptr->fw_dev_pkt_data_len);
    printf("applicable_comps : %d\n", fw_records_first_ptr->applicable_comps);
    printf("comp_img_set_ver_str : %s\n", fw_records_first_ptr->comp_img_set_ver_str);
    pldm_fwup_fw_dev_id_records_middle_part_t *fw_records_middle_ptr = (pldm_fwup_fw_dev_id_records_middle_part_t *)&(fw_records_first_ptr->comp_img_set_ver_str[fw_records_first_ptr->comp_img_set_ver_str_len]);
    pldm_add_descriptor_t *ptr = &(fw_records_middle_ptr->descriptor);
    for (u8 i = 0; i < fw_records_first_ptr->descriptor_cnt; i++) {
        printf("add_type : %d\n", ptr->add_type);
        printf("add_len : %d\n", ptr->add_len);
        for (u8 j = 0; j < ptr->add_len; j++) {
            printf("%x ", ptr->add_data[j]);
        }
        printf("\n");
        ptr = (pldm_add_descriptor_t *)&(ptr->add_data[ptr->add_len]);
    }
    pldm_fwup_fw_dev_id_records_end_part_t *fw_records_end_ptr = (pldm_fwup_fw_dev_id_records_end_part_t *)ptr;
    for (u8 i = 0; i < fw_records_first_ptr->fw_dev_pkt_data_len; i++) {
        printf("%#x ", fw_records_end_ptr->fw_dev_pkt_data[i]);
    }
    printf("\n");

    pldm_fwup_comp_img_info_area_t *comp_img_area = (pldm_fwup_comp_img_info_area_t *)&(fw_records_end_ptr->fw_dev_pkt_data[fw_records_first_ptr->fw_dev_pkt_data_len]);
    printf("comp_img_cnt : %d\n", comp_img_area->comp_img_cnt);
    pldm_fwup_comp_img_info_first_part_t *comp_first_part = (pldm_fwup_comp_img_info_first_part_t *)comp_img_area->comp_img_info;
    for (u8 i = 0; i < comp_img_area->comp_img_cnt; i++) {
        printf("comp_classification : %d\n", comp_first_part->comp_classification);
        printf("comp_identifier : %d\n", comp_first_part->comp_identifier);
        printf("comp_comparison_stamp : %#x\n", comp_first_part->comp_comparison_stamp);
        printf("comp_options : %d\n", comp_first_part->comp_options);
        printf("req_comp_acti_method : %d\n", comp_first_part->req_comp_acti_method);
        printf("comp_local_offset : %d\n", comp_first_part->comp_local_offset);
        printf("comp_size : %d\n", comp_first_part->comp_size);
        printf("comp_ver_str_type : %d\n", comp_first_part->comp_ver_str_type);
        printf("comp_ver_str_len : %d\n", comp_first_part->comp_ver_str_len);
        for (u8 j = 0; j < comp_first_part->comp_ver_str_len; j++) {
            printf("%x ", comp_first_part->comp_ver_str[j] - '0');            /* ascii */
        }
        printf("\n");
        // pldm_fwup_comp_img_info_end_part_t *comp_end_part = (pldm_fwup_comp_img_info_end_part_t *)&(comp_first_part->comp_ver_str[comp_first_part->comp_ver_str_len]);
        // printf("comp_opaque_data_len : %d\n", comp_end_part->comp_opaque_data_len);
        comp_first_part = (pldm_fwup_comp_img_info_first_part_t *)&(comp_first_part->comp_ver_str[comp_first_part->comp_ver_str_len]);
    }
    pldm_fwup_comp_img_info_end_part_t *crc32 = (pldm_fwup_comp_img_info_end_part_t *)comp_first_part;
    u32 cal_crc32 = crc32_pldm(b, pkt_hdr->pkt_hdr_size - sizeof(u32));
    printf("pkt_hdr_crc32 : %#x\n", crc32->pkt_hdr_crc32);
    printf("check result : %s\n", cal_crc32 == crc32->pkt_hdr_crc32 ? "success" : "false");
    printf("%s\n", (u8 *)comp_first_part + sizeof(u32));
}
