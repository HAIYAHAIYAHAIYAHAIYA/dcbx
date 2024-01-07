#ifndef _TYPE_H_
#define _TYPE_H_

#define ntohs(x)     (((x & 0xff) << 8) | ((x) >> 8) & 0xff)
#define ntohl(x)     (((x & 0xff) << 24) | ((((x) >> 8) & 0xff) << 16) | ((((x) >> 16) & 0xff) << 8) | (((x) >> 24) & 0xff))
#define htons(x)     (((x & 0xff) << 8) | ((x) >> 8) & 0xff)
#define htonl(x)     (((x & 0xff) << 24) | ((((x) >> 8) & 0xff) << 16) | ((((x) >> 16) & 0xff) << 8) | (((x) >> 24) & 0xff))

typedef unsigned char 			u8;
typedef unsigned short			u16;
typedef unsigned int			u32;
typedef unsigned long long		u64;

typedef signed char 			s8;
typedef signed short			s16;
typedef signed int				s32;
typedef signed long long 		s64;

typedef unsigned long long		u47;
typedef unsigned long long		u128;
typedef unsigned long long		u192;
#endif