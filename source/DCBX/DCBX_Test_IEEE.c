#include "DCBX_Test_IEEE.h"
#include "DCBX_Test_CEE.h"
#include "main.h"

// IEEE_corporate DCBX_IEEE;                   //IEEE_TLV

// u8 buf_IEEE[] = { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x84, 0x18, 0x88, 0xd6, 0x39, 0x71, 0x88, 0xcc, 0x02, 0x07,           //ieee.pcap
//                 0x04, 0x84, 0x18, 0x88, 0xd6, 0x39, 0x48, 0x04, 0x04, 0x07, 0x35, 0x32, 0x36, 0x06, 0x02, 0x00,
//                 0x28, 0xfe, 0x19, 0x00, 0x80, 0xc2, 0x09, 0x03, 0x77, 0x77, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00,
//                 0x00, 0x00, 0x00, 0x64, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xfe, 0x19, 0x00, 0x80,
//                 0xc2, 0x0a, 0x03, 0x77, 0x77, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02,
//                 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xfe, 0x06, 0x00, 0x80, 0xc2, 0x0b, 0x08, 0x00, 0xfe,
//                 0x0b, 0x00, 0x80, 0xc2, 0x0c, 0x00, 0x24, 0xc3, 0x51, 0x44, 0xc3, 0x50, 0x0c, 0x58, 0x4a, 0x75,
//                 0x6e, 0x69, 0x70, 0x65, 0x72, 0x20, 0x4e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x73, 0x2c, 0x20,
//                 0x49, 0x6e, 0x63, 0x2e, 0x20, 0x71, 0x66, 0x78, 0x33, 0x35, 0x30, 0x30, 0x73, 0x20, 0x2c, 0x20,
//                 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x31, 0x32, 0x2e, 0x33, 0x58, 0x35, 0x30, 0x2e,
//                 0x31, 0x20, 0x42, 0x75, 0x69, 0x6c, 0x64, 0x20, 0x64, 0x61, 0x74, 0x65, 0x3a, 0x20, 0x32, 0x30,
//                 0x31, 0x33, 0x2d, 0x30, 0x33, 0x2d, 0x30, 0x35, 0x20, 0x30, 0x30, 0x3a, 0x33, 0x32, 0x3a, 0x30,
//                 0x36, 0x20, 0x55, 0x54, 0x43, 0x20, 0x0e, 0x04, 0x00, 0x14, 0x00, 0x14, 0x08, 0x0b, 0x78, 0x65,
//                 0x2d, 0x30, 0x2f, 0x30, 0x2f, 0x33, 0x38, 0x2e, 0x30, 0xfe, 0x09, 0x00, 0x12, 0x0f, 0x01, 0x01,
//                 0x6c, 0x1d, 0x00, 0x00, 0xfe, 0x09, 0x00, 0x12, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0xfe,
//                 0x06, 0x00, 0x12, 0x0f, 0x04, 0x05, 0xea, 0xfe, 0x06, 0x00, 0x80, 0xc2, 0x01, 0x00, 0x00, 0xfe,
//                 0x0e, 0x00, 0x80, 0xc2, 0x03, 0x00, 0x00, 0x07, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x00,
//                 0x00
//                 };

void printf_ETS_Configuration(tlv_type_t *ptr)
{
    printf("*******************************IEEE - ETS Configuration*******************************\n");
    ETS_Configuration_TLV *C_TLV = (ETS_Configuration_TLV *)ptr;
    printf("type:%d\n", C_TLV->TL.type);
    printf("length:%d\n", C_TLV->TL.length);
    printf("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        printf("%x ", C_TLV->OUC[j]);
    }
    printf("\n");
    printf("Subtype:0x%x\n", C_TLV->Subtype);
    printf("Willing:%d\n", C_TLV->Willing);
    printf("Credit-Based Shaper: %d\n", C_TLV->CBS);
    printf("Maximum Number of Traffic Classes: %d\n", C_TLV->MaxTCS);
    printf("PFC FOR Prio 0 :%d\n", C_TLV->Pgid_0);
    printf("PFC FOR Prio 1 :%d\n", C_TLV->Pgid_1);
    printf("PFC FOR Prio 2 :%d\n", C_TLV->Pgid_2);
    printf("PFC FOR Prio 3 :%d\n", C_TLV->Pgid_3);
    printf("PFC FOR Prio 4 :%d\n", C_TLV->Pgid_4);
    printf("PFC FOR Prio 5 :%d\n", C_TLV->Pgid_5);
    printf("PFC FOR Prio 6 :%d\n", C_TLV->Pgid_6);
    printf("PFC FOR Prio 7 :%d\n", C_TLV->Pgid_7);
    for(int j = 0; j < 8; j++){
            printf("BW FOR PGID %d :%d\n", j, C_TLV->BW_PGID[j]);
    }
    for(int j = 0; j < 8; j++){
            printf("TSA for Traffic Class %d: %d\n", j, C_TLV->TSA_FOR_TC[j]);
    }
    printf("***********************************************************************");
    printf("\n");
}
void printf_ETS_Recommendation(tlv_type_t *ptr)
{
    printf("*******************************IEEE - ETS Recommendation*******************************\n");
    ETS_Recommendation_TLV *R_TLV = (ETS_Recommendation_TLV *)ptr;
    printf("type:%d\n", R_TLV->TL.type);
    printf("length:%d\n", R_TLV->TL.length);
    printf("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        printf("%x ", R_TLV->OUC[j]);
    }
    printf("\n");
    printf("Subtype:0x%x\n", R_TLV->Subtype);
    printf("Reserved:%d\n", R_TLV->R_RN.Reserved);
    printf("PFC FOR Prio 0 :%d\n", R_TLV->PGIDS_0_3.Pgid_0);
    printf("PFC FOR Prio 1 :%d\n", R_TLV->PGIDS_0_3.Pgid_1);
    printf("PFC FOR Prio 2 :%d\n", R_TLV->PGIDS_0_3.Pgid_2);
    printf("PFC FOR Prio 3 :%d\n", R_TLV->PGIDS_0_3.Pgid_3);
    printf("PFC FOR Prio 4 :%d\n", R_TLV->PGIDS_4_7.Pgid_4);
    printf("PFC FOR Prio 5 :%d\n", R_TLV->PGIDS_4_7.Pgid_5);
    printf("PFC FOR Prio 6 :%d\n", R_TLV->PGIDS_4_7.Pgid_6);
    printf("PFC FOR Prio 7 :%d\n", R_TLV->PGIDS_4_7.Pgid_7);
    for(int j = 0; j < 8; j++){
            printf("BW FOR PGID %d :%d\n", j, R_TLV->BW_PGID[j]);
    }
    for(int j = 0; j < 8; j++){
            printf("TSA for Traffic Class %d: %d\n", j, R_TLV->TSA_FOR_TC[j]);
    }
    printf("***********************************************************************");
    printf("\n");
}
void printf_ETS_Priority_Flow_Control_Configuration(tlv_type_t *ptr)
{
    printf("*******************************IEEE - Priority Flow Control Configuration*******************************\n");
    ETS_PFC_TLV *PFC_TLV = (ETS_PFC_TLV *)ptr;
    printf("type:%d\n", PFC_TLV->TL.type);
    printf("length:%d\n", PFC_TLV->TL.length);
    printf("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        printf("%x ", PFC_TLV->OUC[j]);
    }
    printf("\n");
    printf("Subtype:0x%x\n", PFC_TLV->Subtype);
    printf("Willing:%d\n", PFC_TLV->PFC_VCRM.Willing);
    printf("MACsec Bypass Capability: %d\n", PFC_TLV->PFC_VCRM.MBC);
    printf("Max PFC Enabled Traffic Classes: %d\n", PFC_TLV->PFC_VCRM.PFCCab);
    printf("PFC FOR Prio 0 :%d\n", PFC_TLV->PECPs.PECP0);
    printf("PFC FOR Prio 1 :%d\n", PFC_TLV->PECPs.PECP1);
    printf("PFC FOR Prio 2 :%d\n", PFC_TLV->PECPs.PECP2);
    printf("PFC FOR Prio 3 :%d\n", PFC_TLV->PECPs.PECP3);
    printf("PFC FOR Prio 4 :%d\n", PFC_TLV->PECPs.PECP4);
    printf("PFC FOR Prio 5 :%d\n", PFC_TLV->PECPs.PECP5);
    printf("PFC FOR Prio 6 :%d\n", PFC_TLV->PECPs.PECP6);
    printf("PFC FOR Prio 7 :%d\n", PFC_TLV->PECPs.PECP7);
    printf("***********************************************************************");
    printf("\n");
}
void printf_ETS_Application_Protocol(tlv_type_t *ptr)
{
    printf("*******************************IEEE - Application Protocol*******************************\n");
    ETS_APP_TLV *APP_TLV = (ETS_APP_TLV *)ptr;
    printf("type:%d\n", APP_TLV->TL.type);
    printf("length:%d\n", APP_TLV->TL.length);
    printf("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        printf("%x ", APP_TLV->OUC[j]);
    }
    printf("\n");
    printf("Subtype:0x%x\n", APP_TLV->Subtype);
    printf("Reserved:%d\n", APP_TLV->Reserved);
    for (int j = 0; j < (APP_TLV->TL.length - 5)/3; j++)
    {
        printf("Sub APP %d\n", j);
        printf(" Application Priority: %d\n", APP_TLV->APP_Sub[j].APP_P_Sel.Prio);
        printf(" Application Selector: %d\n", APP_TLV->APP_Sub[j].APP_P_Sel.Sel);
        printf(" Application Protocol Id: 0x%x\n", ntohs(APP_TLV->APP_Sub[j].Id));
    }
    printf("***********************************************************************");
    printf("\n");
}
// void DCBX_Test_IEEE(int argc, char * argv [])
// {
//     int i = 14;
//     int count = 0;
//     tlv_type_t *ptr;

//     ptr = &buf_IEEE[i];
//     while(ptr->type != 0) {
//         ptr->val = ntohs(ptr->val);
//         // printf("%d %d %d\n", ptr->val, ptr->type, ptr->length);
//         // printf("%d\n", ptr->type);
//         switch(ptr->type) {
//             case 1:
//             {
//                 printf("*****************************chassis_id********************************\n");
//                 tlv_chassis_id *chassis_id = (tlv_chassis_id *)ptr;
//                 printf("type_length: 0x%x\n", (chassis_id->type_length));
//                 printf("subtype: 0x%x\n", (chassis_id->subtype));
//                 for(int j = 0; j < 6; j++){
//                     printf("%x ", chassis_id->mac[j]);
//                 }
//                 printf("\n");
//                 printf("***********************************************************************\n");
//             }
//             break;
//             case 2:
//             {
//                 printf("*****************************port_id********************************\n");
//                 tlv_port_id *port_id = (tlv_port_id *)ptr;
//                 printf("type_length: 0x%x\n", (port_id->type_length));
//                 printf("subtype: 0x%x\n", (port_id->subtype));
//                 printf("Port Id: ");
//                 for(int j = 0; j < (ptr->length - 1); j++){
//                     printf("%d", port_id->mac[j] & 0xf);
//                 }
//                 printf("\n");
//                 printf("***********************************************************************\n");
//             }
//             break;
//             case 3:
//             {
//                 printf("*****************************TTL********************************\n");
//                 tlv_ttl *TTL = (tlv_ttl *)ptr;
//                 printf("type_length: 0x%x\n", (TTL->type_length));
//                 printf("seconds: %d\n", ntohs(TTL->seconds));
//                 printf("***********************************************************************\n");
//             }
//             break;
//             case 127:
//             {
//                 if(count < 4){
//                     switch(buf_IEEE[i + 5]){
//                         case 0x09:
//                         {
//                             printf("*******************************IEEE - ETS Configuration*******************************\n");
//                             ETS_Configuration_TLV *C_TLV = (ETS_Configuration_TLV *)ptr;
//                             printf("type:%d\n", C_TLV->TL.type);
//                             printf("length:%d\n", C_TLV->TL.length);
//                             printf("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 printf("%x ", C_TLV->OUC[j]);
//                             }
//                             printf("\n");
//                             printf("Subtype:0x%x\n", C_TLV->Subtype);
//                             printf("Willing:%d\n", C_TLV->C_VCRM.Willing);
//                             printf("Credit-Based Shaper: %d\n", C_TLV->C_VCRM.CBS);
//                             printf("Maximum Number of Traffic Classes: %d\n", C_TLV->C_VCRM.MaxTCS);
//                             printf("PFC FOR Prio 0 :%d\n", C_TLV->PGIDS_0_3.Pgid_0);
//                             printf("PFC FOR Prio 1 :%d\n", C_TLV->PGIDS_0_3.Pgid_1);
//                             printf("PFC FOR Prio 2 :%d\n", C_TLV->PGIDS_0_3.Pgid_2);
//                             printf("PFC FOR Prio 3 :%d\n", C_TLV->PGIDS_0_3.Pgid_3);
//                             printf("PFC FOR Prio 4 :%d\n", C_TLV->PGIDS_4_7.Pgid_4);
//                             printf("PFC FOR Prio 5 :%d\n", C_TLV->PGIDS_4_7.Pgid_5);
//                             printf("PFC FOR Prio 6 :%d\n", C_TLV->PGIDS_4_7.Pgid_6);
//                             printf("PFC FOR Prio 7 :%d\n", C_TLV->PGIDS_4_7.Pgid_7);
//                             for(int j = 0; j < 8; j++){
//                                     printf("BW FOR PGID %d :%d\n", j, C_TLV->BW_PGID[j]);
//                             }
//                             for(int j = 0; j < 8; j++){
//                                     printf("TSA for Traffic Class %d: %d\n", j, C_TLV->TSA_FOR_TC[j]);
//                             }
//                             printf("***********************************************************************");
//                             printf("\n");
//                         }
//                         break;
//                         case 0x0a:
//                         {
//                             printf("*******************************IEEE - ETS Recommendation*******************************\n");
//                             ETS_Recommendation_TLV *R_TLV = (ETS_Recommendation_TLV *)ptr;
//                             printf("type:%d\n", R_TLV->TL.type);
//                             printf("length:%d\n", R_TLV->TL.length);
//                             printf("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 printf("%x ", R_TLV->OUC[j]);
//                             }
//                             printf("\n");
//                             printf("Subtype:0x%x\n", R_TLV->Subtype);
//                             printf("Reserved:%d\n", R_TLV->R_RN.Reserved);
//                             printf("PFC FOR Prio 0 :%d\n", R_TLV->PGIDS_0_3.Pgid_0);
//                             printf("PFC FOR Prio 1 :%d\n", R_TLV->PGIDS_0_3.Pgid_1);
//                             printf("PFC FOR Prio 2 :%d\n", R_TLV->PGIDS_0_3.Pgid_2);
//                             printf("PFC FOR Prio 3 :%d\n", R_TLV->PGIDS_0_3.Pgid_3);
//                             printf("PFC FOR Prio 4 :%d\n", R_TLV->PGIDS_4_7.Pgid_4);
//                             printf("PFC FOR Prio 5 :%d\n", R_TLV->PGIDS_4_7.Pgid_5);
//                             printf("PFC FOR Prio 6 :%d\n", R_TLV->PGIDS_4_7.Pgid_6);
//                             printf("PFC FOR Prio 7 :%d\n", R_TLV->PGIDS_4_7.Pgid_7);
//                             for(int j = 0; j < 8; j++){
//                                     printf("BW FOR PGID %d :%d\n", j, R_TLV->BW_PGID[j]);
//                             }
//                             for(int j = 0; j < 8; j++){
//                                     printf("TSA for Traffic Class %d: %d\n", j, R_TLV->TSA_FOR_TC[j]);
//                             }
//                             printf("***********************************************************************");
//                             printf("\n");
//                         }
//                         break;
//                         case 0x0b:
//                         {
//                             printf("*******************************IEEE - Priority Flow Control Configuration*******************************\n");
//                             ETS_PFC_TLV *PFC_TLV = (ETS_PFC_TLV *)ptr;
//                             printf("type:%d\n", PFC_TLV->TL.type);
//                             printf("length:%d\n", PFC_TLV->TL.length);
//                             printf("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 printf("%x ", PFC_TLV->OUC[j]);
//                             }
//                             printf("\n");
//                             printf("Subtype:0x%x\n", PFC_TLV->Subtype);
//                             printf("Willing:%d\n", PFC_TLV->PFC_VCRM.Willing);
//                             printf("MACsec Bypass Capability: %d\n", PFC_TLV->PFC_VCRM.MBC);
//                             printf("Max PFC Enabled Traffic Classes: %d\n", PFC_TLV->PFC_VCRM.PFCCab);
//                             printf("PFC FOR Prio 0 :%d\n", PFC_TLV->PECPs.PECP0);
//                             printf("PFC FOR Prio 1 :%d\n", PFC_TLV->PECPs.PECP1);
//                             printf("PFC FOR Prio 2 :%d\n", PFC_TLV->PECPs.PECP2);
//                             printf("PFC FOR Prio 3 :%d\n", PFC_TLV->PECPs.PECP3);
//                             printf("PFC FOR Prio 4 :%d\n", PFC_TLV->PECPs.PECP4);
//                             printf("PFC FOR Prio 5 :%d\n", PFC_TLV->PECPs.PECP5);
//                             printf("PFC FOR Prio 6 :%d\n", PFC_TLV->PECPs.PECP6);
//                             printf("PFC FOR Prio 7 :%d\n", PFC_TLV->PECPs.PECP7);
//                             printf("***********************************************************************");
//                             printf("\n");
//                         }
//                         break;
//                         case 0x0c:
//                         {
//                             printf("*******************************IEEE - Application Protocol*******************************\n");
//                             ETS_APP_TLV *APP_TLV = (ETS_APP_TLV *)ptr;
//                             printf("type:%d\n", APP_TLV->TL.type);
//                             printf("length:%d\n", APP_TLV->TL.length);
//                             printf("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 printf("%x ", APP_TLV->OUC[j]);
//                             }
//                             printf("\n");
//                             printf("Subtype:0x%x\n", APP_TLV->Subtype);
//                             printf("Reserved:%d\n", APP_TLV->Reserved);
//                             for (int j = 0; j < (APP_TLV->TL.length - 5)/3; j++)
//                             {
//                                 printf("Sub APP %d\n", j);
//                                 printf(" Application Priority: %d\n", APP_TLV->APP_Sub[j].APP_P_Sel.Prio);
//                                 printf(" Application Selector: %d\n", APP_TLV->APP_Sub[j].APP_P_Sel.Sel);
//                                 printf(" Application Protocol Id: 0x%x\n", ntohs(APP_TLV->APP_Sub[j].Id));
//                             }
//                             printf("***********************************************************************");
//                             printf("\n");
//                         }
//                         break;
//                     }
//                     count++;
//                 }
//             }
//             break;
//         }
//         ptr = &buf_IEEE[i += ptr->length + 2]; 
//     }
// }
