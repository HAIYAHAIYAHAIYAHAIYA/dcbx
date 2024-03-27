#ifndef __SHA256_H__
#define __SHA256_H__
 
#include "type.h"

void sha256(const unsigned char *data, u64 len, unsigned char *out);
int rsa_test(void);
u8 crc8_pldm(u8 *data, u16 len);
u8 crc8_pldm_1(u8 crc8, u8 *data, u16 len);
u32 crc32_pldm(u8 *data, u32 len);
u32 crc32_pldm_1(u32 crc, u8 *data, u32 len);    /* IEEE 802.3 */
u32 crc32(u8* addr, int num);
u8 crc16_i2c_smbus(u8 crc, u8 *p, u16 count);
void str_to_acsii(char *str_in, u8 s_len, char *acsii_out);

#endif /* __SHA256_H__ */