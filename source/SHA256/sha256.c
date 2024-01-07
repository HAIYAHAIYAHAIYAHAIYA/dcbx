
// sha256.c

#include "sha256.h"
#include "main.h"
 
#define rightrotate(w, n) ((w >> n) | (w) << (32-(n)))
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define copy_uint32(p, val) *((u32 *)p) = __builtin_bswap32((val))//gcc 内建函数__builtin_bswap32，
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define copy_uint32(p, val) *((u32 *)p) = (val)
#else
#error "Unsupported target architecture endianess!"
#endif

u8 crc8_pldm(u8 *data, u16 len)
{
    u8 crc8 = 0;
    while(len--){
        crc8 ^= (u8)*data++;
        for (u8 i = 0; i < 8; i++) {
            crc8 = ( crc8 & 0x80 ) ? ((crc8 << 1) ^ 0x07) : (crc8 << 1);
        }
    }
    return crc8;
}

// u32 crc32_pldm(u8 *data, u32 len)   /* CRC-32-MPEG-2 */
// {
//     u32 crc = 0xFFFFFFFF;

//     while (len--) {
//         crc ^= (unsigned int)(*data++) << 24;
//         for (int i = 0; i < 8; ++i)
//         {
//             if (crc & 0x80000000)
//                 crc = (crc << 1) ^ 0x04C11DB7;
//             else
//                 crc <<= 1;
//         }
//     }
//     return crc;
// }

u32 crc32_pldm(u8 *data, u32 len)    /* IEEE 802.3 */
{
    u32 crc = 0xFFFFFFFF;

    while (len--) {
        crc ^= (unsigned int)(*data++);
        for (int i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320UL;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}

//方法一 
u8 reverse8(u8 data) {
    u8 i;
    u8 temp = 0;
    for (i = 0; i < 8; i++)	    				// 8 bit反转
        temp |= ((data >> i) & 0x01) << (7 - i);
    return temp;
}
u32 reverse32(u32 data) {
    u8 i;
    u32 temp = 0;
    for (i = 0; i < 32; i++)					// 32 bit反转
        temp |= ((data >> i) & 0x01) << (31 - i);
    return temp;
}
//正向计算
u32 crc32(u8* addr, int num) {
    u8 data;
    u32 crc = 0xffffffff;						//初始值
    int i;
    for (; num > 0; num--) {
        data = *addr++;
        data = reverse8(data);					//字节反转
        crc = crc ^ (data << 24);				//与crc初始值高8位异或 
        for (i = 0; i < 8; i++) {				//循环8位
            if (crc & 0x80000000)				//左移移出的位为1，左移后与多项式异或
                crc = (crc << 1) ^ 0x04c11db7;
            else {
                crc <<= 1;						//否则直接左移
            }
        }
    }
    crc = reverse32(crc);						//字节反转
    crc = crc ^ 0xffffffff;	                	//最后返与结果异或值异或
    return crc;                                 //返回最终校验值
}

u8 crc16_i2c_smbus(u8 crc, u8 *p, u16 count)
{
    u16 data = 0;
    for (int i = 0; i < count; i++) {
        data = (crc ^ p[i]) << 8;

        for (int j = 0; j < 8; j++) {
            if (data & 0x8000)
                data = data ^ (0x1070U << 3);
            data = data << 1;
        }

        crc  = (u8)(data >> 8);
    }

    return crc;
}

void str_to_acsii(char *str_in, u8 s_len, char *acsii_out)
{

    u8 size1 = 0, i = 0;
    for (size1 = 0; size1 < s_len; size1++) {
        if (str_in[size1] >= '0' && str_in[size1] <= '9') {
            acsii_out[size1] = str_in[size1] - 0x30;
        } else if (str_in[size1] >= 'A' && str_in[size1] <= 'F') {
            acsii_out[size1] = str_in[size1] - 'A'+10;
        } else if (str_in[size1] >= 'a' && str_in[size1] <= 'f') {
            acsii_out[size1] = str_in[size1] - 'a' + 10;
        }
    }
    for (size1 = 0, i = 0; size1 <= s_len; size1++, i++) {
        acsii_out[i] = (acsii_out[size1] << 4) | acsii_out[++size1];
    }
    acsii_out[i] = '\0'; 
}

static const u32 k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256(const unsigned char *data, u64 len, unsigned char *out) {
    u32 h0 = 0x6a09e667;
    u32 h1 = 0xbb67ae85;
    u32 h2 = 0x3c6ef372;
    u32 h3 = 0xa54ff53a;
    u32 h4 = 0x510e527f;
    u32 h5 = 0x9b05688c;
    u32 h6 = 0x1f83d9ab;
    u32 h7 = 0x5be0cd19;
    int r = (int)(len * 8 % 512);
    int append = ((r < 448) ? (448 - r) : (448 + 512 - r)) / 8;
    u64 new_len = len + append + 8;// 原始数据+填充+64bit位数
    unsigned char buf[new_len];
    memset(buf + len, 0, append); //将内存（字符串）前n个字节清零<string.h>
    if (len > 0) {
        memcpy(buf, data, len);
    }
    buf[len] = (unsigned char)0x80;
    u64 bits_len = len * 8;
    for (int i = 0; i < 8; i++) {
        buf[len + append + i] = (bits_len >> ((7 - i) * 8)) & 0xff;
    }
    u32 w[64];
    memset(w, 0, 64);
    u64 chunk_len = new_len / 64; //分512bit区块
    for (int idx = 0; idx < chunk_len; idx++) {
        u32 val = 0;
        for (int i = 0; i < 64; i++) {//将块分解为16个32-bit的big-endian的字，记为w[0], …, w[15]
            val =  val | (*(buf + idx * 64 + i) << (8 * (3 - i)));
            if (i % 4 == 3) {
                w[i / 4] = val;
                val = 0;
            }
        }
        for (int i = 16; i < 64; i++) {//前16个字直接由以上消息的第i个块分解得到，其余的字由如下迭代公式得到：
            u32 s0 = rightrotate(w[i - 15], 7) ^ rightrotate(w[i - 15], 18) ^ (w[i - 15] >> 3);
            u32 s1 = rightrotate(w[i - 2], 17) ^ rightrotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        u32 a = h0;
        u32 b = h1;
        u32 c = h2;
        u32 d = h3;
        u32 e = h4;
        u32 f = h5;
        u32 g = h6;
        u32 h = h7;
        for (int i = 0; i < 64; i++) {//
            u32 s_1 = rightrotate(e, 6) ^ rightrotate(e, 11) ^ rightrotate(e, 25);
            u32 ch = (e & f) ^ (~e & g);
            u32 temp1 = h + s_1 + ch + k[i] + w[i];
            u32 s_0 = rightrotate(a, 2) ^ rightrotate(a, 13) ^ rightrotate(a, 22);
            u32 maj = (a & b) ^ (a & c) ^ (b & c);
            u32 temp2 = s_0 + maj;
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }
	//printf("The ho is %x\n",h0);
    copy_uint32(out, h0);
    copy_uint32(out + 1, h1);
    copy_uint32(out + 2, h2);
    copy_uint32(out + 3, h3);
    copy_uint32(out + 4, h4);
    copy_uint32(out + 5, h5);
    copy_uint32(out + 6, h6);
    copy_uint32(out + 7, h7);
	
    /*for(int i=0;i<32;i++)
	{
		printf("%x",out[i]);	
	}*/
}