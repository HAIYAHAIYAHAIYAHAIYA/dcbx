#ifndef __MCTP_H__
#define __MCTP_H__

#include "type.h"

#define MAX_SEQ                  (3)
#define QWORDSIZE                (8)

#define SPLIT_MIN_PKT_LEN        (72)     //(msg len)64 + 8(qw0)
#define UP_PROTOCOL_HDR_LEN      (24)     //qw0,1,2
#define COPY_LEN                 (48)     //(msg len)64 - 16(hdr)

#pragma pack(1)
typedef struct {
    u8 ver      : 4;
    u8 rsvd     : 4;
    u8 dest_eid;
    u8 src_eid;
    u8 msg_tag  : 3;
    u8 to       : 1;
    u8 pkt_seq  : 2;
    u8 eom      : 1;
    u8 som      : 1;
} mctp_hdr_t;

#pragma pack()

typedef enum {
    S1E0 = 0,
    S0EX,
    S1E1,
    TAG_ERR,
    SEQ_ERR,
    BLEN_ERR,
    NULL_PTR_ERR,
    S1E1_SUC,
    S0E1_SUC,
    INVAILD_DATA
} mctp_pkt_type;


void printf_mctp_merge_pkt(void);
void printf_mctp_split_pkt(void);
u8 get_mctp_error(void);
int get_mctp_msg_tag(void);

#endif