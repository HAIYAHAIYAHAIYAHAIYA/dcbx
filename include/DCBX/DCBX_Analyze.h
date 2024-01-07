#ifndef _DCBX_ANALYZE_H_
#define _DCBX_ANALYZE_H_
#include "type.h"

#pragma pack(1)

typedef struct _tlv_judgement_Protocol {
    u16     type_length;
    u8      OUC[3];
    u8      Subtype;
} tlv_judgement_Protocol;

#pragma pack()

typedef enum {
    NONE = 0,
    IEEE,
    CEE
}Protocol_type;

void DCBX_ANALYZE(u8 *buf);

#endif