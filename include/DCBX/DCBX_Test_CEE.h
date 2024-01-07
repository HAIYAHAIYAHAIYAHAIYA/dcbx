#ifndef _DCBX_TEST_CEE_H_
#define _DCBX_TEST_CEE_H_
#include "type.h"

#pragma pack(1)

typedef struct _tlv_chassis_id {
    u16     type_length;
    u8      subtype;
    u8      mac[6];
}  tlv_chassis_id;

typedef struct _tlv_port_id {
    u16     type_length;
    u8      subtype;
    u8      mac[6];
}  tlv_port_id;

typedef struct _tlv_sys_name {
    u16     type_length;
    u8      name[20];
}  tlv_sys_name;

typedef struct _tlv_ttl {
    u16     type_length;
    u16     seconds;
}  tlv_ttl;

typedef union {
    struct {
        u16     length  : 9;
        u16     type    : 7;
    };
    u16 val;
}  tlv_type_t;

typedef struct _DCBX_Control_Tlv{
    tlv_type_t           TL;
    u8  Oper_Ver           ;
    u8  Max_Ver            ;
    u32 SeqNo;
    u32 AckNo;
}  DCBX_Control_Tlv;
typedef struct _DCBX_PFC_Tlv{
    tlv_type_t           TL;
    u8  Oper_Ver           ;
    u8  Max_Ver            ;
    union EWER_UNION
    {
        struct
        {
            u8  Reserved :5;
            u8  Error    :1;
            u8  Willing  :1;
            u8  Enable   :1;
        };
        u8 EWER_Byte;
    }PFC_EWER;
    u8  Sub_Type           ;
    union PEC_UNION{
        struct 
        {
            u8  PFC0     :1;
            u8  PFC1     :1;
            u8  PFC2     :1;
            u8  PFC3     :1;
            u8  PFC4     :1;
            u8  PFC5     :1;
            u8  PFC6     :1;
            u8  PFC7     :1;
        };
        u8 PFC;
    }PFCs;
    u8  N_TCPFCs_S         ;
}  DCBX_PFC_Tlv;

typedef struct _APP_Tlv_Sub{
    u16 App_Id;
    union 
    {
        struct{
            u8  SF               :2;
            u8  OUI_23_18_Bits   :6;
        };
        u8  OUI_23_16_Bits;
    }U_OUI_23_16_Bits;
    union APP_Tlv_Sub_UNION
    {
        struct{
            u16  OUI_7_0_Bits     :8;
            u16  OUI_15_8_Bits    :8;
        };
        u16 OUI_15_0_Bits;
    }U_OUI_15_0_Bits;
    u8  Up_Map           :8;
}  APP_Tlv_Sub;

typedef struct _DCBX_APP_Tlv{
    tlv_type_t           TL;
    u8  Oper_Ver           ;
    u8  Max_Ver            ;
    union APP_EWER_UNION
    {
        struct
        {
            u8  Reserved :5;
            u8  Error    :1;
            u8  Willing  :1;
            u8  Enable   :1;
        };
        u8 EWER_Byte;
    }APP_EWER;
    u8  Sub_Type           ;
    APP_Tlv_Sub APP_Tlv_Sub[0];
}  DCBX_APP_Tlv;
typedef struct _DCBX_PG_Tlv{
    tlv_type_t           TL;
    u8  Oper_Ver           ;
    u8  Max_Ver            ;
    union PG_EWER_UNION
    {
        struct
        {
            u8  Reserved :5;
            u8  Error    :1;
            u8  Willing  :1;
            u8  Enable   :1;
        };
        u8 EWER_Byte;
    }PG_EWER;
    u8  Sub_Type           ;
    union PG_PGID_0_3_UNION
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
    union PG_PGID_4_7_UNION
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
    u8 Pg_Percentage[8]     ;     /* Index is PGID */ 
    u8 Num_Tcs_Supported    ; 
}  DCBX_PG_Tlv;

// typedef struct _tlv_end {
//     u16     type_length;
// }  tlv_end;

typedef struct _Intel_corporate
{
    u16 type_length         ;
    u8  OUI[3]              ;
    u8  DCBx_Protocol       ;
    u8  CEE_tlv_start       ;
}  Intel_corporate;

#pragma pack()

// typedef struct _Intel_corporate
// {
//     u16               type_length;
//     u8                OUI[3];
//     u8                DCBx_Protocol;
//     DCBX_Control_Tlv  C_TLV;             //DCBx Control TLV    
//     DCBX_PFC_Tlv      PFC_TLV;           //Priority-Based Flow Control TLV
//     DCBX_APP_Tlv      APP_TLV;           //Application Protocol TLV
//     DCBX_PG_Tlv       PG_TLV;            //Priority Groups TLV
// }  Intel_corporate;

// void DCBX_Test_CEE(int argc, char * argv []);

void printf_classix_id(tlv_type_t *ptr);
void printf_port_id(tlv_type_t *ptr);
void printf_ttl(tlv_type_t *ptr);
void printf_sys_name(tlv_type_t *ptr);

void printf_APP_TLV(tlv_type_t *ptr);
void printf_PG_TLV(tlv_type_t *ptr);
void printf_PFC_TLV(tlv_type_t *ptr);
void printf_C_TLV(tlv_type_t *ptr);

#endif