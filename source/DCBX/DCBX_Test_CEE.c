#include "DCBX_Test_CEE.h"
#include "main.h"



// u8 buf_CEE[] = { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x00, 0x05, 0x73, 0xf3, 0x4d, 0x4a, 0x81, 0x00, 0xe0, 0x09,        //dcbx-intel.pcap
//                 0x88, 0xcc, 0x02, 0x07, 0x04, 0x00, 0x05, 0x73, 0xf3, 0x4d, 0x4a, 0x04, 0x07, 0x07, 0x45, 0x74,
//                 0x68, 0x31, 0x2f, 0x33, 0x06, 0x02, 0x00, 0x78, 0x08, 0x0b, 0x45, 0x74, 0x68, 0x65, 0x72, 0x6e,
//                 0x65, 0x74, 0x31, 0x2f, 0x33, 0x0a, 0x0c, 0x4e, 0x35, 0x4b, 0x2d, 0x35, 0x2d, 0x4c, 0x61, 0x62,
//                 0x33, 0x2d, 0x33, 0x0c, 0x95, 0x43, 0x69, 0x73, 0x63, 0x6f, 0x20, 0x4e, 0x65, 0x78, 0x75, 0x73,
//                 0x20, 0x4f, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65,
//                 0x6d, 0x20, 0x28, 0x4e, 0x58, 0x2d, 0x4f, 0x53, 0x29, 0x20, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61,
//                 0x72, 0x65, 0x0a, 0x54, 0x41, 0x43, 0x20, 0x73, 0x75, 0x70, 0x70, 0x6f, 0x72, 0x74, 0x3a, 0x20,
//                 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x63, 0x69, 0x73, 0x63, 0x6f,
//                 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x74, 0x61, 0x63, 0x0a, 0x43, 0x6f, 0x70, 0x79, 0x72, 0x69, 0x67,
//                 0x68, 0x74, 0x20, 0x28, 0x63, 0x29, 0x20, 0x32, 0x30, 0x30, 0x32, 0x2d, 0x32, 0x30, 0x31, 0x32,
//                 0x2c, 0x20, 0x43, 0x69, 0x73, 0x63, 0x6f, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x73, 0x2c,
//                 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x20, 0x41, 0x6c, 0x6c, 0x20, 0x72, 0x69, 0x67, 0x68, 0x74, 0x73,
//                 0x20, 0x72, 0x65, 0x73, 0x65, 0x72, 0x76, 0x65, 0x64, 0x2e, 0x0e, 0x04, 0x00, 0x04, 0x00, 0x04,
//                 0x10, 0x0c, 0x05, 0x01, 0xc0, 0xa8, 0x00, 0x3a, 0x02, 0x05, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x37,
//                 0x00, 0x1b, 0x21, 0x02, 0x02, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
//                 0x06, 0x06, 0x00, 0x00, 0x80, 0x00, 0x08, 0x08, 0x08, 0x0a, 0x00, 0x00, 0x80, 0x00, 0x89, 0x06,
//                 0x00, 0x1b, 0x21, 0x08, 0x04, 0x11, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x32, 0x32,
//                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xfe, 0x05, 0x00, 0x01, 0x42, 0x01, 0x01, 0xfe, 0x14,
//                 0x00, 0x01, 0x42, 0x02, 0x05, 0xdc, 0x05, 0xdc, 0x05, 0xdc, 0x08, 0x6e, 0x05, 0xdc, 0x05, 0xdc,
//                 0x05, 0xdc, 0x05, 0xdc, 0xfe, 0x06, 0x00, 0x80, 0xc2, 0x01, 0x00, 0x32, 0x00, 0x00
//                 };            
// u8 buf_CEE[] = { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x84, 0x18, 0x88, 0xd6, 0x39, 0x71, 0x88, 0xcc, 0x02, 0x07,     //dcbx_sample_capture_1.pcap
//             0x04, 0x84, 0x18, 0x88, 0xd6, 0x39, 0x48, 0x04, 0x04, 0x07, 0x35, 0x32, 0x36, 0x06, 0x02, 0x00,
//             0x28, 0xfe, 0x3d, 0x00, 0x1b, 0x21, 0x02, 0x02, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
//             0x00, 0x00, 0x03, 0x04, 0x11, 0x00, 0x00, 0x80, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 0x00, 0x00,
//             0x00, 0x00, 0x00, 0x00, 0x64, 0x03, 0x06, 0x06, 0x00, 0x00, 0x80, 0x00, 0x00, 0x08, 0x08, 0x10,
//             0x00, 0x00, 0x80, 0x00, 0xc3, 0x51, 0x01, 0x1b, 0x21, 0x02, 0xc3, 0x50, 0x01, 0x1b, 0x21, 0x04,
//             0x0c, 0x58, 0x4a, 0x75, 0x6e, 0x69, 0x70, 0x65, 0x72, 0x20, 0x4e, 0x65, 0x74, 0x77, 0x6f, 0x72,
//             0x6b, 0x73, 0x2c, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x20, 0x71, 0x66, 0x78, 0x33, 0x35, 0x30, 0x30,
//             0x73, 0x20, 0x2c, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x31, 0x32, 0x2e, 0x33,
//             0x58, 0x35, 0x30, 0x2e, 0x31, 0x20, 0x42, 0x75, 0x69, 0x6c, 0x64, 0x20, 0x64, 0x61, 0x74, 0x65,
//             0x3a, 0x20, 0x32, 0x30, 0x31, 0x33, 0x2d, 0x30, 0x33, 0x2d, 0x30, 0x35, 0x20, 0x30, 0x30, 0x3a,
//             0x33, 0x32, 0x3a, 0x30, 0x36, 0x20, 0x55, 0x54, 0x43, 0x20, 0x0e, 0x04, 0x00, 0x14, 0x00, 0x14,
//             0x08, 0x0b, 0x78, 0x65, 0x2d, 0x30, 0x2f, 0x30, 0x2f, 0x33, 0x38, 0x2e, 0x30, 0xfe, 0x09, 0x00,
//             0x12, 0x0f, 0x01, 0x01, 0x6c, 0x1d, 0x00, 0x00, 0xfe, 0x09, 0x00, 0x12, 0x0f, 0x03, 0x01, 0x00,
//             0x00, 0x00, 0x00, 0xfe, 0x06, 0x00, 0x12, 0x0f, 0x04, 0x05, 0xea, 0xfe, 0x06, 0x00, 0x80, 0xc2,
//             0x01, 0x00, 0x00, 0xfe, 0x0e, 0x00, 0x80, 0xc2, 0x03, 0x00, 0x00, 0x07, 0x64, 0x65, 0x66, 0x61,
//             0x75, 0x6c, 0x74, 0x00, 0x00
//             };        
// u8 buf_CEE[] = { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x00, 0x07, 0x43, 0x10, 0x53, 0xd0, 0x88, 0xcc, 0x02, 0x07,     //dcbx_sample_capture_2.pcap      
//                 0x04, 0x00, 0x07, 0x43, 0x10, 0x53, 0xd0, 0x04, 0x07, 0x03, 0x00, 0x07, 0x43, 0x10, 0x53, 0xd0,
//                 0x06, 0x02, 0x00, 0x78, 0xfe, 0x43, 0x00, 0x1b, 0x21, 0x02, 0x02, 0x0a, 0x00, 0x00, 0x00, 0x00,
//                 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x04, 0x11, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x11, 0x1f,
//                 0x19, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x06, 0x06, 0x00, 0x00, 0xc0, 0x00, 0x08,
//                 0x08, 0x08, 0x16, 0x00, 0x00, 0xe0, 0x00, 0x89, 0x06, 0x00, 0x1b, 0x21, 0x08, 0x0c, 0xbc, 0x01,
//                 0x1b, 0x21, 0x08, 0x89, 0x14, 0x00, 0x1b, 0x21, 0x08, 0x00, 0x00
//                 };  
void printf_classix_id(tlv_type_t *ptr)
{
    LOG("*****************************chassis_id********************************\n");
    tlv_chassis_id *chassis_id = (tlv_chassis_id *)ptr;
    LOG("type_length: 0x%x\n", (chassis_id->type_length));
    LOG("subtype: %d\n", (chassis_id->subtype));
    for(int j = 0; j < 6; j++){
        LOG("%x ", chassis_id->mac[j]);
    }
    LOG("\n");
    LOG("***********************************************************************\n");
}
void printf_port_id(tlv_type_t *ptr)
{
    LOG("*****************************port_id********************************\n");
    tlv_port_id *port_id = (tlv_port_id *)ptr;
    LOG("type_length: 0x%x\n", (port_id->type_length));
    LOG("subtype: %d\n", (port_id->subtype));
    for(int j = 0; j < (ptr->length - 1); j++){
        LOG("%x ", port_id->mac[j]);
    }
    LOG("\n");
    LOG("***********************************************************************\n");
}
void printf_ttl(tlv_type_t *ptr)
{
    LOG("*****************************TTL********************************\n");
    tlv_ttl *TTL = (tlv_ttl *)ptr;
    LOG("type_length: 0x%x\n", (TTL->type_length));
    LOG("seconds: %d\n", ntohs(TTL->seconds));
    LOG("***********************************************************************\n");
}
void printf_sys_name(tlv_type_t *ptr)
{
    LOG("*****************************sys_name********************************\n");
    tlv_sys_name *sys_name = (tlv_sys_name *)ptr;
    LOG("type_length: 0x%x\n", (sys_name->type_length));
    LOG("System Name: ");
    for(int k = 0; k < ptr->length; k++){
        LOG("%c", sys_name->name[k]);
    }
    LOG("\n");
    LOG("***********************************************************************\n");
}
void printf_C_TLV(tlv_type_t *ptr)
{
    LOG("*******************************C_TLV*******************************\n");
    DCBX_Control_Tlv *C_TLV = (DCBX_Control_Tlv *)ptr;
    LOG("type: %d\n", (C_TLV->TL.type));
    LOG("length: %d\n", (C_TLV->TL.length));
    LOG("Oper_Ver: %d\n", (C_TLV->Oper_Ver));
    LOG("Max_Ver: %d\n", (C_TLV->Max_Ver));
    LOG("SeqNo: %d\n", ntohl(C_TLV->SeqNo));
    LOG("AckNo: %d\n", ntohl(C_TLV->AckNo));
}
void printf_PFC_TLV(tlv_type_t *ptr)
{
    LOG("*******************************PFC_TLV*******************************\n");
    DCBX_PFC_Tlv *PFC_TLV = (DCBX_PFC_Tlv *)ptr;
    LOG("type: %d\n", (PFC_TLV->TL.type));
    LOG("length: %d\n", (PFC_TLV->TL.length));
    LOG("Oper_Ver: %d\n", (PFC_TLV->Oper_Ver));
    LOG("Max_Ver: %d\n", (PFC_TLV->Max_Ver));
    LOG("Enabled:%d\n", (PFC_TLV->PFC_EWER.Enable));
    LOG("Willing:%d\n", (PFC_TLV->PFC_EWER.Willing));
    LOG("Error:%d\n"  , (PFC_TLV->PFC_EWER.Error));
    LOG("Subtype:%d\n", (PFC_TLV->Sub_Type));
    LOG("PFC FOR Prio 0 :%d\n", (PFC_TLV->PFCs.PFC0));
    LOG("PFC FOR Prio 1 :%d\n", (PFC_TLV->PFCs.PFC1));
    LOG("PFC FOR Prio 2 :%d\n", (PFC_TLV->PFCs.PFC2));
    LOG("PFC FOR Prio 3 :%d\n", (PFC_TLV->PFCs.PFC3));
    LOG("PFC FOR Prio 4 :%d\n", (PFC_TLV->PFCs.PFC4));
    LOG("PFC FOR Prio 5 :%d\n", (PFC_TLV->PFCs.PFC5));
    LOG("PFC FOR Prio 6 :%d\n", (PFC_TLV->PFCs.PFC6));
    LOG("PFC FOR Prio 7 :%d\n", (PFC_TLV->PFCs.PFC7));
    LOG("Number of Traffic Classes Supported: %d\n", (PFC_TLV->N_TCPFCs_S));
}
void printf_PG_TLV(tlv_type_t *ptr)
{
    LOG("*******************************PG_TLV*******************************\n");
    DCBX_PG_Tlv *PG_TLV = (DCBX_PG_Tlv *)ptr;
    LOG("type: %d\n", (PG_TLV->TL.type));
    LOG("length: %d\n", (PG_TLV->TL.length));
    LOG("Oper_Ver: %d\n", (PG_TLV->Oper_Ver));
    LOG("Max_Ver: %d\n", (PG_TLV->Max_Ver));
    LOG("Enabled:%d\n", (PG_TLV->PG_EWER.Enable));
    LOG("Willing:%d\n", (PG_TLV->PG_EWER.Willing));
    LOG("Error:%d\n"  , (PG_TLV->PG_EWER.Error));
    LOG("Subtype:%d\n", (PG_TLV->Sub_Type));
    LOG("PFC FOR Prio 0 :%d\n", PG_TLV->PGIDS_0_3.Pgid_0);
    LOG("PFC FOR Prio 1 :%d\n", PG_TLV->PGIDS_0_3.Pgid_1);
    LOG("PFC FOR Prio 2 :%d\n", PG_TLV->PGIDS_0_3.Pgid_2);
    LOG("PFC FOR Prio 3 :%d\n", PG_TLV->PGIDS_0_3.Pgid_3);
    LOG("PFC FOR Prio 4 :%d\n", PG_TLV->PGIDS_4_7.Pgid_4);
    LOG("PFC FOR Prio 5 :%d\n", PG_TLV->PGIDS_4_7.Pgid_5);
    LOG("PFC FOR Prio 6 :%d\n", PG_TLV->PGIDS_4_7.Pgid_6);
    LOG("PFC FOR Prio 7 :%d\n", PG_TLV->PGIDS_4_7.Pgid_7);
    for(int k = 0; k < 8; k++){
        LOG("BW FOR PGID %d :%d\n", k, PG_TLV->Pg_Percentage[k]);
    }
    LOG("Number of Traffic Classes Supported: %d\n", PG_TLV->Num_Tcs_Supported);
}
void printf_APP_TLV(tlv_type_t *ptr)
{
    LOG("*******************************APP_TLV*******************************\n");
    DCBX_APP_Tlv *APP_TLV = (DCBX_APP_Tlv *)ptr;
    LOG("type: %d\n", (APP_TLV->TL.type));
    LOG("length: %d\n", (APP_TLV->TL.length));
    LOG("Oper_Ver: %d\n", (APP_TLV->Oper_Ver));
    LOG("Max_Ver: %d\n", (APP_TLV->Max_Ver));
    LOG("Enabled:%d\n", (APP_TLV->APP_EWER.Enable));
    LOG("Willing:%d\n", (APP_TLV->APP_EWER.Willing));
    LOG("Error:%d\n"  , (APP_TLV->APP_EWER.Error));
    LOG("Subtype:%d\n", (APP_TLV->Sub_Type));
    for (int k = 0; k < (APP_TLV->TL.length - 4)/6; k++){
        LOG("APP_Tlv_Sub%d : \n App_Id : 0x%x\n", k + 1, ntohs(APP_TLV->APP_Tlv_Sub[k].App_Id));
        LOG(" SF :%d\n", APP_TLV->APP_Tlv_Sub[k].U_OUI_23_16_Bits.SF);
        LOG(" OUI :0x%x\n", ntohs((APP_TLV->APP_Tlv_Sub[k].U_OUI_23_16_Bits.OUI_23_18_Bits << 24) | (APP_TLV->APP_Tlv_Sub[k].U_OUI_15_0_Bits.OUI_15_0_Bits)));
        LOG(" Application Priority: %d\n", APP_TLV->APP_Tlv_Sub[k].Up_Map);
    }
}

// void DCBX_Test_CEE(int argc, char * argv [])
// {
//     int i = 14;
//     if(0x8100 == (buf_CEE[12] << 8 | buf_CEE[13])){
//         i += 4;
//     }
//     tlv_type_t *ptr;

//     ptr = &buf_CEE[i];
//     while(ptr->type != 0) {
//         ptr->val = ntohs(ptr->val);
//         switch(ptr->type) {
//             case 1:
//             {
//                 LOG("*****************************chassis_id********************************\n");
//                 tlv_chassis_id *chassis_id = (tlv_chassis_id *)ptr;
//                 LOG("type_length: 0x%x\n", (chassis_id->type_length));
//                 LOG("subtype: %d\n", (chassis_id->subtype));
//                 for(int j = 0; j < 6; j++){
//                     LOG("%x ", chassis_id->mac[j]);
//                 }
//                 LOG("\n");
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 2:
//             {
//                 LOG("*****************************port_id********************************\n");
//                 tlv_port_id *port_id = (tlv_port_id *)ptr;
//                 LOG("type_length: 0x%x\n", (port_id->type_length));
//                 LOG("subtype: %d\n", (port_id->subtype));
//                 for(int j = 0; j < (ptr->length - 1); j++){
//                     LOG("%x ", port_id->mac[j]);
//                 }
//                 LOG("\n");
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 3:
//             {
//                 LOG("*****************************TTL********************************\n");
//                 tlv_ttl *TTL = (tlv_ttl *)ptr;
//                 LOG("type_length: 0x%x\n", (TTL->type_length));
//                 LOG("seconds: %d\n", ntohs(TTL->seconds));
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 5:
//             {
//                 LOG("*****************************sys_name********************************\n");
//                 tlv_sys_name *sys_name = (tlv_sys_name *)ptr;
//                 LOG("type_length: 0x%x\n", (sys_name->type_length));
//                 LOG("System Name: ");
//                 for(int k = 0; k < ptr->length; k++){
//                     LOG("%c", sys_name->name[k]);
//                 }
//                 LOG("\n");
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 127:
//             {
//                 if(ptr->length < 45){
//                     break;
//                 }
//                 LOG("*****************************Intel Corporate - 1.01 CEE********************************\n");
//                 ptr = &buf_CEE[i += 6];
//                 ptr->val = ntohs(ptr->val);
//                 // LOG("%d %d %d\n", (ptr->val), ptr->length, ptr->type);
//                 for (int j = 0; j < 4; j++)
//                 {
//                     if(ptr->type == 1){
//                         LOG("*******************************C_TLV*******************************\n");
//                         DCBX_Control_Tlv *C_TLV = (DCBX_Control_Tlv *)ptr;
//                         LOG("type: %d\n", (C_TLV->TL.type));
//                         LOG("length: %d\n", (C_TLV->TL.length));
//                         LOG("Oper_Ver: %d\n", (C_TLV->Oper_Ver));
//                         LOG("Max_Ver: %d\n", (C_TLV->Max_Ver));
//                         LOG("SeqNo: %d\n", ntohl(C_TLV->SeqNo));
//                         LOG("AckNo: %d\n", ntohl(C_TLV->AckNo));
//                         ptr = &buf_CEE[i += ptr->length + 2];
//                         ptr->val = ntohs(ptr->val);
//                     }
//                     if(ptr->type == 2){
//                         LOG("*******************************PG_TLV*******************************\n");
//                         DCBX_PG_Tlv *PG_TLV = (DCBX_PG_Tlv *)ptr;
//                         LOG("type: %d\n", (PG_TLV->TL.type));
//                         LOG("length: %d\n", (PG_TLV->TL.length));
//                         LOG("Oper_Ver: %d\n", (PG_TLV->Oper_Ver));
//                         LOG("Max_Ver: %d\n", (PG_TLV->Max_Ver));
//                         LOG("Enabled:%d\n", (PG_TLV->PG_EWER.Enable));
//                         LOG("Willing:%d\n", (PG_TLV->PG_EWER.Willing));
//                         LOG("Error:%d\n"  , (PG_TLV->PG_EWER.Error));
//                         LOG("Subtype:%d\n", (PG_TLV->Sub_Type));
//                         LOG("PFC FOR Prio 0 :%d\n", PG_TLV->PGIDS_0_3.Pgid_0);
//                         LOG("PFC FOR Prio 1 :%d\n", PG_TLV->PGIDS_0_3.Pgid_1);
//                         LOG("PFC FOR Prio 2 :%d\n", PG_TLV->PGIDS_0_3.Pgid_2);
//                         LOG("PFC FOR Prio 3 :%d\n", PG_TLV->PGIDS_0_3.Pgid_3);
//                         LOG("PFC FOR Prio 4 :%d\n", PG_TLV->PGIDS_4_7.Pgid_4);
//                         LOG("PFC FOR Prio 5 :%d\n", PG_TLV->PGIDS_4_7.Pgid_5);
//                         LOG("PFC FOR Prio 6 :%d\n", PG_TLV->PGIDS_4_7.Pgid_6);
//                         LOG("PFC FOR Prio 7 :%d\n", PG_TLV->PGIDS_4_7.Pgid_7);
//                         for(int k = 0; k < 8; k++){
//                             LOG("BW FOR PGID %d :%d\n", k, PG_TLV->Pg_Percentage[k]);
//                         }
//                         LOG("Number of Traffic Classes Supported: %d\n", PG_TLV->Num_Tcs_Supported);
//                         ptr = &buf_CEE[i += ptr->length + 2]; 
//                         ptr->val = ntohs(ptr->val);
//                     }
//                     if(ptr->type == 3){
//                         LOG("*******************************PFC_TLV*******************************\n");
//                         DCBX_PFC_Tlv *PFC_TLV = (DCBX_PFC_Tlv *)ptr;
//                         LOG("type: %d\n", (PFC_TLV->TL.type));
//                         LOG("length: %d\n", (PFC_TLV->TL.length));
//                         LOG("Oper_Ver: %d\n", (PFC_TLV->Oper_Ver));
//                         LOG("Max_Ver: %d\n", (PFC_TLV->Max_Ver));
//                         LOG("Enabled:%d\n", (PFC_TLV->PFC_EWER.Enable));
//                         LOG("Willing:%d\n", (PFC_TLV->PFC_EWER.Willing));
//                         LOG("Error:%d\n"  , (PFC_TLV->PFC_EWER.Error));
//                         LOG("Subtype:%d\n", (PFC_TLV->Sub_Type));
//                         LOG("PFC FOR Prio 0 :%d\n", (PFC_TLV->PFCs.PFC0));
//                         LOG("PFC FOR Prio 1 :%d\n", (PFC_TLV->PFCs.PFC1));
//                         LOG("PFC FOR Prio 2 :%d\n", (PFC_TLV->PFCs.PFC2));
//                         LOG("PFC FOR Prio 3 :%d\n", (PFC_TLV->PFCs.PFC3));
//                         LOG("PFC FOR Prio 4 :%d\n", (PFC_TLV->PFCs.PFC4));
//                         LOG("PFC FOR Prio 5 :%d\n", (PFC_TLV->PFCs.PFC5));
//                         LOG("PFC FOR Prio 6 :%d\n", (PFC_TLV->PFCs.PFC6));
//                         LOG("PFC FOR Prio 7 :%d\n", (PFC_TLV->PFCs.PFC7));
//                         LOG("Number of Traffic Classes Supported: %d\n", (PFC_TLV->N_TCPFCs_S));
//                         ptr = &buf_CEE[i += ptr->length + 2]; 
//                         ptr->val = ntohs(ptr->val);
//                     }
//                     if(ptr->type == 4){
//                         LOG("*******************************APP_TLV*******************************\n");
//                         DCBX_APP_Tlv *APP_TLV = (DCBX_APP_Tlv *)ptr;
//                         LOG("type: %d\n", (APP_TLV->TL.type));
//                         LOG("length: %d\n", (APP_TLV->TL.length));
//                         LOG("Oper_Ver: %d\n", (APP_TLV->Oper_Ver));
//                         LOG("Max_Ver: %d\n", (APP_TLV->Max_Ver));
//                         LOG("Enabled:%d\n", (APP_TLV->APP_EWER.Enable));
//                         LOG("Willing:%d\n", (APP_TLV->APP_EWER.Willing));
//                         LOG("Error:%d\n"  , (APP_TLV->APP_EWER.Error));
//                         LOG("Subtype:%d\n", (APP_TLV->Sub_Type));
//                         for (int k = 0; k < (APP_TLV->TL.length - 4)/6; k++){
//                             LOG("APP_Tlv_Sub%d : \n App_Id : 0x%x\n", k + 1, ntohs(APP_TLV->APP_Tlv_Sub[k].App_Id));
//                             LOG(" SF :%d\n", APP_TLV->APP_Tlv_Sub[k].U_OUI_23_16_Bits.SF);
//                             LOG(" OUI :0x%x\n", ntohs(APP_TLV->APP_Tlv_Sub[k].U_OUI_15_0_Bits.OUI_15_0_Bits));
//                             LOG(" Application Priority: %d\n", APP_TLV->APP_Tlv_Sub[k].Up_Map);
//                         }
//                         ptr = &buf_CEE[i += ptr->length + 2]; 
//                         ptr->val = ntohs(ptr->val);
//                     }
//                 }
//                 LOG("***********************************************************************\n");
//             }
//             break;
//         }
//         ptr = &buf_CEE[i += (ptr->length) + 2]; 
//     }
// }      