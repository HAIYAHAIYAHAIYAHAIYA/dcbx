#ifndef _MAIN_H_
#define _MAIN_H_

#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#if 1
    #define LOG(...)               printf(__VA_ARGS__)
#else 
    #define LOG(...)
#endif
#endif