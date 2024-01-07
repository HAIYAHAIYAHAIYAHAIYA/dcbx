#ifndef _DCBX_TEST_IEEE_H_
#define _DCBX_TEST_IEEE_H_
#include "type.h"
#include "DCBX_Test_CEE.h"

#pragma pack(1)

typedef struct _ETS_Configuration_TLV{
    tlv_type_t           TL;
    u8 OUC[3];
    u8 Subtype;

    u8 MaxTCS   :3;
    u8 Reserved :3;
    u8 CBS      :1;
    u8 Willing  :1;
    u8 Pgid_1   :4; /* PGID of priority 1 */
    u8 Pgid_0   :4; /* PGID of priority 0 */  
    u8 Pgid_3   :4; /* PGID of priority 3 */  
    u8 Pgid_2   :4; /* PGID of priority 2 */ 
    u8 Pgid_5   :4; /* PGID of priority 5 */ 
    u8 Pgid_4   :4; /* PGID of priority 4 */ 
    u8 Pgid_7   :4; /* PGID of priority 7 */
    u8 Pgid_6   :4; /* PGID of priority 6 */ 
    u8 BW_PGID[8];
    u8 TSA_FOR_TC[8];
} __attribute__((packed)) ETS_Configuration_TLV;
typedef struct _ETS_Recommendation_TLV{
    tlv_type_t           TL;
    u8               OUC[3];
    u8              Subtype;
    union 
    {
        struct {
            
            u8  None     :1;
            u8  Reserved :7;
        };
        u8 RN;
    }R_RN;
    union R_PGID_0_3_UNION
    {
        struct 
        {
            u16 Pgid_1    :4; /* PGID of priority 1 */ 
            u16 Pgid_0    :4; /* PGID of priority 0 */ 
            u16 Pgid_3    :4; /* PGID of priority 3 */  
            u16 Pgid_2    :4; /* PGID of priority 2 */ 
        };
        u16 PGID;
    }PGIDS_0_3;
    union R_PGID_4_7_UNION
    {
        struct
        {
            
            u16 Pgid_5    :4; /* PGID of priority 5 */ 
            u16 Pgid_4    :4; /* PGID of priority 4 */ 
            u16 Pgid_7    :4; /* PGID of priority 7 */
            u16 Pgid_6    :4; /* PGID of priority 6 */ 
        };
        u16 PGID;
    }PGIDS_4_7;
    u8 BW_PGID[8];
    u8 TSA_FOR_TC[8];
} ETS_Recommendation_TLV;

typedef struct _ETS_PFC_TLV{
    tlv_type_t           TL;
    u8 OUC[3];
    u8  Subtype;
    union 
    {
        struct {
            u8  PFCCab   :4;
            u8  Reserved :2;
            u8  MBC      :1;
            u8  Willing  :1;
        };
        u8 VCRM;
    }PFC_VCRM;
    union PEC_P_UNION{
        struct 
        {
            u8  PECP0    :1;
            u8  PECP1    :1;
            u8  PECP2    :1;
            u8  PECP3    :1;
            u8  PECP4    :1;
            u8  PECP5    :1;
            u8  PECP6    :1;
            u8  PECP7    :1;
        };
        u8 PECP;
    }PECPs;
} ETS_PFC_TLV;
struct _APP_Sub{
    union
    {
        struct{
            u8  Sel      :3;
            u8  Reserved :2;
            u8  Prio     :3;
        } ;
        u8  P_Sel;
    }APP_P_Sel;
    u16 Id;         
};
typedef struct _ETS_APP_TLV{
    tlv_type_t           TL;
    u8 OUC[3];
    u8  Subtype;
    u8  Reserved;
    struct _APP_Sub APP_Sub[0];
} ETS_APP_TLV;

#pragma pack()

// typedef struct IEEE_corporate_Struct
// {
//     tlv_chassis_id   chassis_id;
//     tlv_port_id      port_id;
//     tlv_ttl          TTL;                   //Time To Live 段
//     tlv_sys_name     sys_name;              

//     ETS_Configuration_TLV     C_TLV;        //IEEE - ETS Configuration Struct
//     ETS_Recommendation_TLV    R_TLV;        //IEEE - ETS Recommendation Struct
//     ETS_PFC_TLV               PFC_TLV;      //IEEE - Priority Flow Control Configuration Struct
//     ETS_APP_TLV               APP_TLV;      //IEEE - Application Protocol Struct

//     tlv_end          end;
// }IEEE_corporate;

// void DCBX_Test_IEEE(int argc, char * argv []);

void printf_ETS_Application_Protocol(tlv_type_t *ptr);
void printf_ETS_Priority_Flow_Control_Configuration(tlv_type_t *ptr);
void printf_ETS_Recommendation(tlv_type_t *ptr);
void printf_ETS_Configuration(tlv_type_t *ptr);
#endif