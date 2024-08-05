#ifndef _MAIN_H_
#define _MAIN_H_

#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

extern FILE *g_fp;

#ifndef MAX_LAN_NUM
#define MAX_LAN_NUM 4
#endif

#define cm_memcpy                       memcpy
#define cm_memset                       memset
#define cm_memcmp                       memcmp
#define cm_strncpy                      strncpy
#define cm_strlen                       strlen
#define cm_strcmp                       strcmp
#define cm_snprintf                     snprintf
#define cm_memset64                     memset64

#if 1
    #define LOG(...)               \
    do { \
        printf(__VA_ARGS__);\
        printf("\r\n");\
        if (!g_fp) {\
            g_fp = fopen("log.txt", "w+"); \
        }\
        fprintf(g_fp, "[%20s][%06d]", __FUNCTION__, __LINE__);\
        fprintf(g_fp, __VA_ARGS__);\
        fprintf(g_fp, "\r\n"); \
    }while(0)
#else 
    #define LOG(...)
#endif
#endif