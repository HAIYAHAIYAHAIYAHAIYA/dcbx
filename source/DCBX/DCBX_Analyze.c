#include "DCBX_Analyze.h"
#include "DCBX_Test_CEE.h"
#include "DCBX_Test_IEEE.h"
#include "main.h"

/**
* @Description:		判断是IEEE协议还是CEE协议
* @param1:		    tlv_type_t *ptr指针
* @return:		    协议代号
*/
static Protocol_type judgement_Protocol(tlv_type_t *ptr)
{
    tlv_judgement_Protocol *judge_ptr = (tlv_judgement_Protocol *)ptr;
    if(judge_ptr->OUC[0] == 0x00 && judge_ptr->OUC[1] == 0x80 && judge_ptr->OUC[2] == 0xc2) {
        return IEEE;
    }else if(judge_ptr->OUC[0] == 0x00 && judge_ptr->OUC[1] == 0x1b && judge_ptr->OUC[2] == 0x21) {
        return CEE;
    }
    return NONE;
}
static void printf_IEEE_TLV(tlv_type_t *ptr)
{
    tlv_judgement_Protocol *ieee_ptr = (tlv_judgement_Protocol *)ptr;

    switch(ieee_ptr->Subtype) {
        case 0x09:
        {
            printf_ETS_Configuration(ptr);
        }
        break;
        case 0x0a:
        {
            printf_ETS_Recommendation(ptr);
        }
        break;
        case 0x0b:
        {
            printf_ETS_Priority_Flow_Control_Configuration(ptr);
        }
        break;
        case 0x0c:
        {
            printf_ETS_Application_Protocol(ptr);
        }
        break;
    }
}
static void printf_CEE_TLV(tlv_type_t *ptr)
{
    ptr = (tlv_type_t *)((u8 *)ptr + 6);

    for(int j = 0; j < 4; j++)
    {
        ptr->val = ntohs(ptr->val);
        switch(ptr->type) {
            case 0x01:
            {
                printf_C_TLV(ptr);
                
            }
            break;
            case 0x02:
            {
                printf_PG_TLV(ptr);
                
            }
            break;
            case 0x03:
            {
                printf_PFC_TLV(ptr);
                
            }
            break;
            case 0x04:
            {
                printf_APP_TLV(ptr);
            }
            break;
        }
        ptr = (tlv_type_t *)((u8 *)ptr + ptr->length + 2);
    }
}

static void dcbx_protocol(tlv_type_t *ptr)
{
    switch (judgement_Protocol(ptr)) 
    {
        case IEEE:
        {
            printf_IEEE_TLV(ptr);
        }
        break;
        case CEE:
        {
            printf_CEE_TLV(ptr);
        }
        break;
    }
}

/**
* @Description:		解析DCBX下IEEE和CEE协议
* @param1:		    以太网数据帧 u8 数组
* @return:		    无
*/
void DCBX_ANALYZE(u8 *buf)
{
    tlv_type_t *ptr;

    ptr = (tlv_type_t *)buf;

    if(0x8100 == (buf[12] << 8 | buf[13])){           //跳过VLAN头:type == 0x8100(vlan), type == 0x88cc(lldp)
        ptr = (tlv_type_t *)((u8 *)ptr + 4);
    }

    ptr = (tlv_type_t *)((u8 *)ptr + 14);

    while(ptr->type != 0) {
        ptr->val = ntohs(ptr->val);
        // if(((&buf[100]) < ((u8 *)ptr + ptr->length + 2))){
        //     return ;
        // }
        // LOG("%x", ptr->val);
        switch (ptr->type) {
            case 0x01:
            {
                printf_classix_id(ptr);
            }
            break;
            case 0x02:
            {
                printf_port_id(ptr);
            }
            break;
            case 0x03:
            {
                printf_ttl(ptr);
            }
            break;
            case 0x05:
            {
                printf_sys_name(ptr);
            }
            break;
            case 0x7f:
            {
                dcbx_protocol(ptr);
            }
            break;
        }
        ptr = (tlv_type_t *)((u8 *)ptr + ptr->length + 2);
        // LOG("%p %p", &buf[261], ((u8 *)ptr));
    }
}