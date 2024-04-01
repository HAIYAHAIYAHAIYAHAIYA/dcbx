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
    LOG("*******************************IEEE - ETS Configuration*******************************\n");
    ETS_Configuration_TLV *C_TLV = (ETS_Configuration_TLV *)ptr;
    LOG("type:%d", C_TLV->TL.type);
    LOG("length:%d", C_TLV->TL.length);
    LOG("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        LOG("%x ", C_TLV->OUC[j]);
    }
    LOG("\n");
    LOG("Subtype:0x%x", C_TLV->Subtype);
    LOG("Willing:%d", C_TLV->Willing);
    LOG("Credit-Based Shaper: %d", C_TLV->CBS);
    LOG("Maximum Number of Traffic Classes: %d", C_TLV->MaxTCS);
    LOG("PFC FOR Prio 0 :%d", C_TLV->Pgid_0);
    LOG("PFC FOR Prio 1 :%d", C_TLV->Pgid_1);
    LOG("PFC FOR Prio 2 :%d", C_TLV->Pgid_2);
    LOG("PFC FOR Prio 3 :%d", C_TLV->Pgid_3);
    LOG("PFC FOR Prio 4 :%d", C_TLV->Pgid_4);
    LOG("PFC FOR Prio 5 :%d", C_TLV->Pgid_5);
    LOG("PFC FOR Prio 6 :%d", C_TLV->Pgid_6);
    LOG("PFC FOR Prio 7 :%d", C_TLV->Pgid_7);
    for(int j = 0; j < 8; j++){
            LOG("BW FOR PGID %d :%d", j, C_TLV->BW_PGID[j]);
    }
    for(int j = 0; j < 8; j++){
            LOG("TSA for Traffic Class %d: %d", j, C_TLV->TSA_FOR_TC[j]);
    }
    LOG("***********************************************************************");
    LOG("\n");
}
void printf_ETS_Recommendation(tlv_type_t *ptr)
{
    LOG("*******************************IEEE - ETS Recommendation*******************************\n");
    ETS_Recommendation_TLV *R_TLV = (ETS_Recommendation_TLV *)ptr;
    LOG("type:%d", R_TLV->TL.type);
    LOG("length:%d", R_TLV->TL.length);
    LOG("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        LOG("%x ", R_TLV->OUC[j]);
    }
    LOG("\n");
    LOG("Subtype:0x%x", R_TLV->Subtype);
    LOG("Reserved:%d", R_TLV->R_RN.Reserved);
    LOG("PFC FOR Prio 0 :%d", R_TLV->PGIDS_0_3.Pgid_0);
    LOG("PFC FOR Prio 1 :%d", R_TLV->PGIDS_0_3.Pgid_1);
    LOG("PFC FOR Prio 2 :%d", R_TLV->PGIDS_0_3.Pgid_2);
    LOG("PFC FOR Prio 3 :%d", R_TLV->PGIDS_0_3.Pgid_3);
    LOG("PFC FOR Prio 4 :%d", R_TLV->PGIDS_4_7.Pgid_4);
    LOG("PFC FOR Prio 5 :%d", R_TLV->PGIDS_4_7.Pgid_5);
    LOG("PFC FOR Prio 6 :%d", R_TLV->PGIDS_4_7.Pgid_6);
    LOG("PFC FOR Prio 7 :%d", R_TLV->PGIDS_4_7.Pgid_7);
    for(int j = 0; j < 8; j++){
            LOG("BW FOR PGID %d :%d", j, R_TLV->BW_PGID[j]);
    }
    for(int j = 0; j < 8; j++){
            LOG("TSA for Traffic Class %d: %d", j, R_TLV->TSA_FOR_TC[j]);
    }
    LOG("***********************************************************************");
    LOG("\n");
}
void printf_ETS_Priority_Flow_Control_Configuration(tlv_type_t *ptr)
{
    LOG("*******************************IEEE - Priority Flow Control Configuration*******************************\n");
    ETS_PFC_TLV *PFC_TLV = (ETS_PFC_TLV *)ptr;
    LOG("type:%d", PFC_TLV->TL.type);
    LOG("length:%d", PFC_TLV->TL.length);
    LOG("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        LOG("%x ", PFC_TLV->OUC[j]);
    }
    LOG("\n");
    LOG("Subtype:0x%x", PFC_TLV->Subtype);
    LOG("Willing:%d", PFC_TLV->PFC_VCRM.Willing);
    LOG("MACsec Bypass Capability: %d", PFC_TLV->PFC_VCRM.MBC);
    LOG("Max PFC Enabled Traffic Classes: %d", PFC_TLV->PFC_VCRM.PFCCab);
    LOG("PFC FOR Prio 0 :%d", PFC_TLV->PECPs.PECP0);
    LOG("PFC FOR Prio 1 :%d", PFC_TLV->PECPs.PECP1);
    LOG("PFC FOR Prio 2 :%d", PFC_TLV->PECPs.PECP2);
    LOG("PFC FOR Prio 3 :%d", PFC_TLV->PECPs.PECP3);
    LOG("PFC FOR Prio 4 :%d", PFC_TLV->PECPs.PECP4);
    LOG("PFC FOR Prio 5 :%d", PFC_TLV->PECPs.PECP5);
    LOG("PFC FOR Prio 6 :%d", PFC_TLV->PECPs.PECP6);
    LOG("PFC FOR Prio 7 :%d", PFC_TLV->PECPs.PECP7);
    LOG("***********************************************************************");
    LOG("\n");
}
void printf_ETS_Application_Protocol(tlv_type_t *ptr)
{
    LOG("*******************************IEEE - Application Protocol*******************************\n");
    ETS_APP_TLV *APP_TLV = (ETS_APP_TLV *)ptr;
    LOG("type:%d", APP_TLV->TL.type);
    LOG("length:%d", APP_TLV->TL.length);
    LOG("Organization Unique Code:(IEEE)");
    for (int j = 0; j < 3; j++)
    {
        LOG("%x ", APP_TLV->OUC[j]);
    }
    LOG("\n");
    LOG("Subtype:0x%x", APP_TLV->Subtype);
    LOG("Reserved:%d", APP_TLV->Reserved);
    for (int j = 0; j < (APP_TLV->TL.length - 5)/3; j++)
    {
        LOG("Sub APP %d", j);
        LOG(" Application Priority: %d", APP_TLV->APP_Sub[j].APP_P_Sel.Prio);
        LOG(" Application Selector: %d", APP_TLV->APP_Sub[j].APP_P_Sel.Sel);
        LOG(" Application Protocol Id: 0x%x", ntohs(APP_TLV->APP_Sub[j].Id));
    }
    LOG("***********************************************************************");
    LOG("\n");
}
// void DCBX_Test_IEEE(int argc, char * argv [])
// {
//     int i = 14;
//     int count = 0;
//     tlv_type_t *ptr;

//     ptr = &buf_IEEE[i];
//     while(ptr->type != 0) {
//         ptr->val = ntohs(ptr->val);
//         // LOG("%d %d %d", ptr->val, ptr->type, ptr->length);
//         // LOG("%d", ptr->type);
//         switch(ptr->type) {
//             case 1:
//             {
//                 LOG("*****************************chassis_id********************************\n");
//                 tlv_chassis_id *chassis_id = (tlv_chassis_id *)ptr;
//                 LOG("type_length: 0x%x", (chassis_id->type_length));
//                 LOG("subtype: 0x%x", (chassis_id->subtype));
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
//                 LOG("type_length: 0x%x", (port_id->type_length));
//                 LOG("subtype: 0x%x", (port_id->subtype));
//                 LOG("Port Id: ");
//                 for(int j = 0; j < (ptr->length - 1); j++){
//                     LOG("%d", port_id->mac[j] & 0xf);
//                 }
//                 LOG("\n");
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 3:
//             {
//                 LOG("*****************************TTL********************************\n");
//                 tlv_ttl *TTL = (tlv_ttl *)ptr;
//                 LOG("type_length: 0x%x", (TTL->type_length));
//                 LOG("seconds: %d", ntohs(TTL->seconds));
//                 LOG("***********************************************************************\n");
//             }
//             break;
//             case 127:
//             {
//                 if(count < 4){
//                     switch(buf_IEEE[i + 5]){
//                         case 0x09:
//                         {
//                             LOG("*******************************IEEE - ETS Configuration*******************************\n");
//                             ETS_Configuration_TLV *C_TLV = (ETS_Configuration_TLV *)ptr;
//                             LOG("type:%d", C_TLV->TL.type);
//                             LOG("length:%d", C_TLV->TL.length);
//                             LOG("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 LOG("%x ", C_TLV->OUC[j]);
//                             }
//                             LOG("\n");
//                             LOG("Subtype:0x%x", C_TLV->Subtype);
//                             LOG("Willing:%d", C_TLV->C_VCRM.Willing);
//                             LOG("Credit-Based Shaper: %d", C_TLV->C_VCRM.CBS);
//                             LOG("Maximum Number of Traffic Classes: %d", C_TLV->C_VCRM.MaxTCS);
//                             LOG("PFC FOR Prio 0 :%d", C_TLV->PGIDS_0_3.Pgid_0);
//                             LOG("PFC FOR Prio 1 :%d", C_TLV->PGIDS_0_3.Pgid_1);
//                             LOG("PFC FOR Prio 2 :%d", C_TLV->PGIDS_0_3.Pgid_2);
//                             LOG("PFC FOR Prio 3 :%d", C_TLV->PGIDS_0_3.Pgid_3);
//                             LOG("PFC FOR Prio 4 :%d", C_TLV->PGIDS_4_7.Pgid_4);
//                             LOG("PFC FOR Prio 5 :%d", C_TLV->PGIDS_4_7.Pgid_5);
//                             LOG("PFC FOR Prio 6 :%d", C_TLV->PGIDS_4_7.Pgid_6);
//                             LOG("PFC FOR Prio 7 :%d", C_TLV->PGIDS_4_7.Pgid_7);
//                             for(int j = 0; j < 8; j++){
//                                     LOG("BW FOR PGID %d :%d", j, C_TLV->BW_PGID[j]);
//                             }
//                             for(int j = 0; j < 8; j++){
//                                     LOG("TSA for Traffic Class %d: %d", j, C_TLV->TSA_FOR_TC[j]);
//                             }
//                             LOG("***********************************************************************");
//                             LOG("\n");
//                         }
//                         break;
//                         case 0x0a:
//                         {
//                             LOG("*******************************IEEE - ETS Recommendation*******************************\n");
//                             ETS_Recommendation_TLV *R_TLV = (ETS_Recommendation_TLV *)ptr;
//                             LOG("type:%d", R_TLV->TL.type);
//                             LOG("length:%d", R_TLV->TL.length);
//                             LOG("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 LOG("%x ", R_TLV->OUC[j]);
//                             }
//                             LOG("\n");
//                             LOG("Subtype:0x%x", R_TLV->Subtype);
//                             LOG("Reserved:%d", R_TLV->R_RN.Reserved);
//                             LOG("PFC FOR Prio 0 :%d", R_TLV->PGIDS_0_3.Pgid_0);
//                             LOG("PFC FOR Prio 1 :%d", R_TLV->PGIDS_0_3.Pgid_1);
//                             LOG("PFC FOR Prio 2 :%d", R_TLV->PGIDS_0_3.Pgid_2);
//                             LOG("PFC FOR Prio 3 :%d", R_TLV->PGIDS_0_3.Pgid_3);
//                             LOG("PFC FOR Prio 4 :%d", R_TLV->PGIDS_4_7.Pgid_4);
//                             LOG("PFC FOR Prio 5 :%d", R_TLV->PGIDS_4_7.Pgid_5);
//                             LOG("PFC FOR Prio 6 :%d", R_TLV->PGIDS_4_7.Pgid_6);
//                             LOG("PFC FOR Prio 7 :%d", R_TLV->PGIDS_4_7.Pgid_7);
//                             for(int j = 0; j < 8; j++){
//                                     LOG("BW FOR PGID %d :%d", j, R_TLV->BW_PGID[j]);
//                             }
//                             for(int j = 0; j < 8; j++){
//                                     LOG("TSA for Traffic Class %d: %d", j, R_TLV->TSA_FOR_TC[j]);
//                             }
//                             LOG("***********************************************************************");
//                             LOG("\n");
//                         }
//                         break;
//                         case 0x0b:
//                         {
//                             LOG("*******************************IEEE - Priority Flow Control Configuration*******************************\n");
//                             ETS_PFC_TLV *PFC_TLV = (ETS_PFC_TLV *)ptr;
//                             LOG("type:%d", PFC_TLV->TL.type);
//                             LOG("length:%d", PFC_TLV->TL.length);
//                             LOG("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 LOG("%x ", PFC_TLV->OUC[j]);
//                             }
//                             LOG("\n");
//                             LOG("Subtype:0x%x", PFC_TLV->Subtype);
//                             LOG("Willing:%d", PFC_TLV->PFC_VCRM.Willing);
//                             LOG("MACsec Bypass Capability: %d", PFC_TLV->PFC_VCRM.MBC);
//                             LOG("Max PFC Enabled Traffic Classes: %d", PFC_TLV->PFC_VCRM.PFCCab);
//                             LOG("PFC FOR Prio 0 :%d", PFC_TLV->PECPs.PECP0);
//                             LOG("PFC FOR Prio 1 :%d", PFC_TLV->PECPs.PECP1);
//                             LOG("PFC FOR Prio 2 :%d", PFC_TLV->PECPs.PECP2);
//                             LOG("PFC FOR Prio 3 :%d", PFC_TLV->PECPs.PECP3);
//                             LOG("PFC FOR Prio 4 :%d", PFC_TLV->PECPs.PECP4);
//                             LOG("PFC FOR Prio 5 :%d", PFC_TLV->PECPs.PECP5);
//                             LOG("PFC FOR Prio 6 :%d", PFC_TLV->PECPs.PECP6);
//                             LOG("PFC FOR Prio 7 :%d", PFC_TLV->PECPs.PECP7);
//                             LOG("***********************************************************************");
//                             LOG("\n");
//                         }
//                         break;
//                         case 0x0c:
//                         {
//                             LOG("*******************************IEEE - Application Protocol*******************************\n");
//                             ETS_APP_TLV *APP_TLV = (ETS_APP_TLV *)ptr;
//                             LOG("type:%d", APP_TLV->TL.type);
//                             LOG("length:%d", APP_TLV->TL.length);
//                             LOG("Organization Unique Code:(IEEE)");
//                             for (int j = 0; j < 3; j++)
//                             {
//                                 LOG("%x ", APP_TLV->OUC[j]);
//                             }
//                             LOG("\n");
//                             LOG("Subtype:0x%x", APP_TLV->Subtype);
//                             LOG("Reserved:%d", APP_TLV->Reserved);
//                             for (int j = 0; j < (APP_TLV->TL.length - 5)/3; j++)
//                             {
//                                 LOG("Sub APP %d", j);
//                                 LOG(" Application Priority: %d", APP_TLV->APP_Sub[j].APP_P_Sel.Prio);
//                                 LOG(" Application Selector: %d", APP_TLV->APP_Sub[j].APP_P_Sel.Sel);
//                                 LOG(" Application Protocol Id: 0x%x", ntohs(APP_TLV->APP_Sub[j].Id));
//                             }
//                             LOG("***********************************************************************");
//                             LOG("\n");
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
