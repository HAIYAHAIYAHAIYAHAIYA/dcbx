#ifndef MESSAGE_H_
#define MESSAGE_H_
#include "type.h"

typedef enum {
  //CKL=0: Means request for lock; CKL=1: Release lock. 
  HDMAFUNC__NOP           = 0x0,
  //Copy data from src addr to dest addr.
  HDMAFUNC__COPY          = 0x1,
  //Compare data from src with dest.
  HDMAFUNC__COMPARE       = 0x2,
  //Get minmum 32bit dw from source data with paramter and result
  //        in min_max_func regs.
  HDMAFUNC__MIN           = 0x3,
  //Get maxmum 32bit dw from source data with paramter and result 
  //        in min_max_func regs.
  HDMAFUNC__MAX           = 0x4,
  //Get checksum of src data, result in response message.
  HDMAFUNC__CHECKSUM      = 0x5,
  //Get CRC of src data, result in response message.
  HDMAFUNC__CRC           = 0x6,
  //DEST = SRC ^ DEST
  HDMAFUNC__XOR           = 0x7,
  //Send src data to secure engien with src.addr+len, then put secure data to dst.addr+len
  HDMAFUNC__SECURE        = 0x8,
  //Send src data to secure engien with src.addr+len, but no secure response data
  HDMAFUNC__SECURE_NO_RSP = 0x9
} HdmaFunc;

//-----MACRO defines for  Message Group MESSAGE_RDL: 0x0
//-----MACRO defines for  Message Group HMC_MMU_REQ_MSG: 0x0
#define HMC_MMU_REQ_MSG_MSG_ID                                             0x0
//-----Access structure typedef for Message:HMC_MMU_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_MMU_REQ_MSG_QW0;
//-----MACRO defines for Message:HMC_MMU_REQ_MSG_QW0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__FPM
#define HMC_MMU_REQ_MSG_QW0__FPM__MSB                                       58
#define HMC_MMU_REQ_MSG_QW0__FPM__LSB                                       49
#define HMC_MMU_REQ_MSG_QW0__FPM__WIDTH                                     10
#define HMC_MMU_REQ_MSG_QW0__FPM__MASK                       0x7fe000000000000
#define HMC_MMU_REQ_MSG_QW0__FPM__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__QPN
#define HMC_MMU_REQ_MSG_QW0__QPN__MSB                                       48
#define HMC_MMU_REQ_MSG_QW0__QPN__LSB                                       32
#define HMC_MMU_REQ_MSG_QW0__QPN__WIDTH                                     17
#define HMC_MMU_REQ_MSG_QW0__QPN__MASK                         0x1ffff00000000
#define HMC_MMU_REQ_MSG_QW0__QPN__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__MSG_ID
#define HMC_MMU_REQ_MSG_QW0__MSG_ID__MSB                                    31
#define HMC_MMU_REQ_MSG_QW0__MSG_ID__LSB                                    24
#define HMC_MMU_REQ_MSG_QW0__MSG_ID__WIDTH                                   8
#define HMC_MMU_REQ_MSG_QW0__MSG_ID__MASK                           0xff000000
#define HMC_MMU_REQ_MSG_QW0__MSG_ID__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__REQ_TAG
#define HMC_MMU_REQ_MSG_QW0__REQ_TAG__MSB                                   23
#define HMC_MMU_REQ_MSG_QW0__REQ_TAG__LSB                                   16
#define HMC_MMU_REQ_MSG_QW0__REQ_TAG__WIDTH                                  8
#define HMC_MMU_REQ_MSG_QW0__REQ_TAG__MASK                            0xff0000
#define HMC_MMU_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__SRC
#define HMC_MMU_REQ_MSG_QW0__SRC__MSB                                       15
#define HMC_MMU_REQ_MSG_QW0__SRC__LSB                                       12
#define HMC_MMU_REQ_MSG_QW0__SRC__WIDTH                                      4
#define HMC_MMU_REQ_MSG_QW0__SRC__MASK                                  0xf000
#define HMC_MMU_REQ_MSG_QW0__SRC__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__DST
#define HMC_MMU_REQ_MSG_QW0__DST__MSB                                       11
#define HMC_MMU_REQ_MSG_QW0__DST__LSB                                       10
#define HMC_MMU_REQ_MSG_QW0__DST__WIDTH                                      2
#define HMC_MMU_REQ_MSG_QW0__DST__MASK                                   0xc00
#define HMC_MMU_REQ_MSG_QW0__DST__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__DSTFIFO
#define HMC_MMU_REQ_MSG_QW0__DSTFIFO__MSB                                    9
#define HMC_MMU_REQ_MSG_QW0__DSTFIFO__LSB                                    6
#define HMC_MMU_REQ_MSG_QW0__DSTFIFO__WIDTH                                  4
#define HMC_MMU_REQ_MSG_QW0__DSTFIFO__MASK                               0x3c0
#define HMC_MMU_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                          0x0

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW0__CNT
#define HMC_MMU_REQ_MSG_QW0__CNT__MSB                                        5
#define HMC_MMU_REQ_MSG_QW0__CNT__LSB                                        0
#define HMC_MMU_REQ_MSG_QW0__CNT__WIDTH                                      6
#define HMC_MMU_REQ_MSG_QW0__CNT__MASK                                    0x3f
#define HMC_MMU_REQ_MSG_QW0__CNT__RESET_VALUE                              0x0

//-----Access structure typedef for Message:HMC_MMU_REQ_MSG_QW1
typedef union {
  struct {
    u64 rsvd0  : 12;
    u64 hmc_va : 24;
    u64 rsvd1  : 28;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_MMU_REQ_MSG_QW1;
//-----MACRO defines for Message:HMC_MMU_REQ_MSG_QW1

//-----MACRO defines for fields:HMC_MMU_REQ_MSG_QW1__HMC_VA
#define HMC_MMU_REQ_MSG_QW1__HMC_VA__MSB                                    35
#define HMC_MMU_REQ_MSG_QW1__HMC_VA__LSB                                    12
#define HMC_MMU_REQ_MSG_QW1__HMC_VA__WIDTH                                  24
#define HMC_MMU_REQ_MSG_QW1__HMC_VA__MASK                          0xffffff000
#define HMC_MMU_REQ_MSG_QW1__HMC_VA__RESET_VALUE                           0x0

typedef struct {
  HMC_MMU_REQ_MSG_QW0  qw0;
  HMC_MMU_REQ_MSG_QW1  qw1;
} HMC_MMU_REQ_MSG;
//QW_CNT is actual number - 1
#define HMC_MMU_REQ_MSG_QW_CNT                                               1
//-----MACRO defines for  Message Group HMC_MMU_RSP_MSG: 0x10000
#define HMC_MMU_RSP_MSG_MSG_ID                                             0x1
//-----Access structure typedef for Message:HMC_MMU_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_MMU_RSP_MSG_QW0;
//-----MACRO defines for Message:HMC_MMU_RSP_MSG_QW0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__STA
#define HMC_MMU_RSP_MSG_QW0__STA__MSB                                       63
#define HMC_MMU_RSP_MSG_QW0__STA__LSB                                       60
#define HMC_MMU_RSP_MSG_QW0__STA__WIDTH                                      4
#define HMC_MMU_RSP_MSG_QW0__STA__MASK                      0xf000000000000000
#define HMC_MMU_RSP_MSG_QW0__STA__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__MSG_ID
#define HMC_MMU_RSP_MSG_QW0__MSG_ID__MSB                                    31
#define HMC_MMU_RSP_MSG_QW0__MSG_ID__LSB                                    24
#define HMC_MMU_RSP_MSG_QW0__MSG_ID__WIDTH                                   8
#define HMC_MMU_RSP_MSG_QW0__MSG_ID__MASK                           0xff000000
#define HMC_MMU_RSP_MSG_QW0__MSG_ID__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__REQ_TAG
#define HMC_MMU_RSP_MSG_QW0__REQ_TAG__MSB                                   23
#define HMC_MMU_RSP_MSG_QW0__REQ_TAG__LSB                                   16
#define HMC_MMU_RSP_MSG_QW0__REQ_TAG__WIDTH                                  8
#define HMC_MMU_RSP_MSG_QW0__REQ_TAG__MASK                            0xff0000
#define HMC_MMU_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__SRC
#define HMC_MMU_RSP_MSG_QW0__SRC__MSB                                       15
#define HMC_MMU_RSP_MSG_QW0__SRC__LSB                                       12
#define HMC_MMU_RSP_MSG_QW0__SRC__WIDTH                                      4
#define HMC_MMU_RSP_MSG_QW0__SRC__MASK                                  0xf000
#define HMC_MMU_RSP_MSG_QW0__SRC__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__DST
#define HMC_MMU_RSP_MSG_QW0__DST__MSB                                       11
#define HMC_MMU_RSP_MSG_QW0__DST__LSB                                       10
#define HMC_MMU_RSP_MSG_QW0__DST__WIDTH                                      2
#define HMC_MMU_RSP_MSG_QW0__DST__MASK                                   0xc00
#define HMC_MMU_RSP_MSG_QW0__DST__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__DSTFIFO
#define HMC_MMU_RSP_MSG_QW0__DSTFIFO__MSB                                    9
#define HMC_MMU_RSP_MSG_QW0__DSTFIFO__LSB                                    6
#define HMC_MMU_RSP_MSG_QW0__DSTFIFO__WIDTH                                  4
#define HMC_MMU_RSP_MSG_QW0__DSTFIFO__MASK                               0x3c0
#define HMC_MMU_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                          0x0

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW0__CNT
#define HMC_MMU_RSP_MSG_QW0__CNT__MSB                                        5
#define HMC_MMU_RSP_MSG_QW0__CNT__LSB                                        0
#define HMC_MMU_RSP_MSG_QW0__CNT__WIDTH                                      6
#define HMC_MMU_RSP_MSG_QW0__CNT__MASK                                    0x3f
#define HMC_MMU_RSP_MSG_QW0__CNT__RESET_VALUE                              0x0

//-----Access structure typedef for Message:HMC_MMU_RSP_MSG_QW1
typedef union {
  struct {
    u64 rsvd0    : 12;
    u64 phy_addr : 52;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_MMU_RSP_MSG_QW1;
//-----MACRO defines for Message:HMC_MMU_RSP_MSG_QW1

//-----MACRO defines for fields:HMC_MMU_RSP_MSG_QW1__PHY_ADDR
#define HMC_MMU_RSP_MSG_QW1__PHY_ADDR__MSB                                  63
#define HMC_MMU_RSP_MSG_QW1__PHY_ADDR__LSB                                  12
#define HMC_MMU_RSP_MSG_QW1__PHY_ADDR__WIDTH                                52
#define HMC_MMU_RSP_MSG_QW1__PHY_ADDR__MASK                 0xfffffffffffff000
#define HMC_MMU_RSP_MSG_QW1__PHY_ADDR__RESET_VALUE                         0x0

typedef struct {
  HMC_MMU_RSP_MSG_QW0  qw0;
  HMC_MMU_RSP_MSG_QW1  qw1;
} HMC_MMU_RSP_MSG;
//QW_CNT is actual number - 1
#define HMC_MMU_RSP_MSG_QW_CNT                                               1
//-----MACRO defines for  Message Group MR_MMU_REQ_MSG: 0x20000
#define MR_MMU_REQ_MSG_MSG_ID                                              0x2
//-----Access structure typedef for Message:MR_MMU_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt       : 6;
    u64 dstfifo   : 4;
    u64 dst       : 2;
    u64 src       : 4;
    u64 req_tag   : 8;
    u64 msg_id    : 8;
    u64 qpn       : 17;
    u64 fpm       : 10;
    u64 rsvd0     : 3;
    u64 last_frag : 1;
    u64 mr_chk_en : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_REQ_MSG_QW0;
//-----MACRO defines for Message:MR_MMU_REQ_MSG_QW0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__MR_CHK_EN
#define MR_MMU_REQ_MSG_QW0__MR_CHK_EN__MSB                                  63
#define MR_MMU_REQ_MSG_QW0__MR_CHK_EN__LSB                                  63
#define MR_MMU_REQ_MSG_QW0__MR_CHK_EN__WIDTH                                 1
#define MR_MMU_REQ_MSG_QW0__MR_CHK_EN__MASK                 0x8000000000000000
#define MR_MMU_REQ_MSG_QW0__MR_CHK_EN__RESET_VALUE                         0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__LAST_FRAG
#define MR_MMU_REQ_MSG_QW0__LAST_FRAG__MSB                                  62
#define MR_MMU_REQ_MSG_QW0__LAST_FRAG__LSB                                  62
#define MR_MMU_REQ_MSG_QW0__LAST_FRAG__WIDTH                                 1
#define MR_MMU_REQ_MSG_QW0__LAST_FRAG__MASK                 0x4000000000000000
#define MR_MMU_REQ_MSG_QW0__LAST_FRAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__FPM
#define MR_MMU_REQ_MSG_QW0__FPM__MSB                                        58
#define MR_MMU_REQ_MSG_QW0__FPM__LSB                                        49
#define MR_MMU_REQ_MSG_QW0__FPM__WIDTH                                      10
#define MR_MMU_REQ_MSG_QW0__FPM__MASK                        0x7fe000000000000
#define MR_MMU_REQ_MSG_QW0__FPM__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__QPN
#define MR_MMU_REQ_MSG_QW0__QPN__MSB                                        48
#define MR_MMU_REQ_MSG_QW0__QPN__LSB                                        32
#define MR_MMU_REQ_MSG_QW0__QPN__WIDTH                                      17
#define MR_MMU_REQ_MSG_QW0__QPN__MASK                          0x1ffff00000000
#define MR_MMU_REQ_MSG_QW0__QPN__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__MSG_ID
#define MR_MMU_REQ_MSG_QW0__MSG_ID__MSB                                     31
#define MR_MMU_REQ_MSG_QW0__MSG_ID__LSB                                     24
#define MR_MMU_REQ_MSG_QW0__MSG_ID__WIDTH                                    8
#define MR_MMU_REQ_MSG_QW0__MSG_ID__MASK                            0xff000000
#define MR_MMU_REQ_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__REQ_TAG
#define MR_MMU_REQ_MSG_QW0__REQ_TAG__MSB                                    23
#define MR_MMU_REQ_MSG_QW0__REQ_TAG__LSB                                    16
#define MR_MMU_REQ_MSG_QW0__REQ_TAG__WIDTH                                   8
#define MR_MMU_REQ_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define MR_MMU_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__SRC
#define MR_MMU_REQ_MSG_QW0__SRC__MSB                                        15
#define MR_MMU_REQ_MSG_QW0__SRC__LSB                                        12
#define MR_MMU_REQ_MSG_QW0__SRC__WIDTH                                       4
#define MR_MMU_REQ_MSG_QW0__SRC__MASK                                   0xf000
#define MR_MMU_REQ_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__DST
#define MR_MMU_REQ_MSG_QW0__DST__MSB                                        11
#define MR_MMU_REQ_MSG_QW0__DST__LSB                                        10
#define MR_MMU_REQ_MSG_QW0__DST__WIDTH                                       2
#define MR_MMU_REQ_MSG_QW0__DST__MASK                                    0xc00
#define MR_MMU_REQ_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__DSTFIFO
#define MR_MMU_REQ_MSG_QW0__DSTFIFO__MSB                                     9
#define MR_MMU_REQ_MSG_QW0__DSTFIFO__LSB                                     6
#define MR_MMU_REQ_MSG_QW0__DSTFIFO__WIDTH                                   4
#define MR_MMU_REQ_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define MR_MMU_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW0__CNT
#define MR_MMU_REQ_MSG_QW0__CNT__MSB                                         5
#define MR_MMU_REQ_MSG_QW0__CNT__LSB                                         0
#define MR_MMU_REQ_MSG_QW0__CNT__WIDTH                                       6
#define MR_MMU_REQ_MSG_QW0__CNT__MASK                                     0x3f
#define MR_MMU_REQ_MSG_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:MR_MMU_REQ_MSG_QW1
typedef union {
  struct {
    u64 pd          : 18;
    u64 access_type : 5;
    u64 rsvd0       : 9;
    u64 key         : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_REQ_MSG_QW1;
//-----MACRO defines for Message:MR_MMU_REQ_MSG_QW1

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW1__KEY
#define MR_MMU_REQ_MSG_QW1__KEY__MSB                                        63
#define MR_MMU_REQ_MSG_QW1__KEY__LSB                                        32
#define MR_MMU_REQ_MSG_QW1__KEY__WIDTH                                      32
#define MR_MMU_REQ_MSG_QW1__KEY__MASK                       0xffffffff00000000
#define MR_MMU_REQ_MSG_QW1__KEY__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW1__ACCESS_TYPE
#define MR_MMU_REQ_MSG_QW1__ACCESS_TYPE__MSB                                22
#define MR_MMU_REQ_MSG_QW1__ACCESS_TYPE__LSB                                18
#define MR_MMU_REQ_MSG_QW1__ACCESS_TYPE__WIDTH                               5
#define MR_MMU_REQ_MSG_QW1__ACCESS_TYPE__MASK                         0x7c0000
#define MR_MMU_REQ_MSG_QW1__ACCESS_TYPE__RESET_VALUE                       0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW1__PD
#define MR_MMU_REQ_MSG_QW1__PD__MSB                                         17
#define MR_MMU_REQ_MSG_QW1__PD__LSB                                          0
#define MR_MMU_REQ_MSG_QW1__PD__WIDTH                                       18
#define MR_MMU_REQ_MSG_QW1__PD__MASK                                   0x3ffff
#define MR_MMU_REQ_MSG_QW1__PD__RESET_VALUE                                0x0

//-----Access structure typedef for Message:MR_MMU_REQ_MSG_QW2
typedef union {
  struct {
    u64 va    : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_REQ_MSG_QW2;
//-----MACRO defines for Message:MR_MMU_REQ_MSG_QW2

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW2__VA
#define MR_MMU_REQ_MSG_QW2__VA__MSB                                         63
#define MR_MMU_REQ_MSG_QW2__VA__LSB                                          0
#define MR_MMU_REQ_MSG_QW2__VA__WIDTH                                       64
#define MR_MMU_REQ_MSG_QW2__VA__MASK                        0xffffffffffffffff
#define MR_MMU_REQ_MSG_QW2__VA__RESET_VALUE                                0x0

//-----Access structure typedef for Message:MR_MMU_REQ_MSG_QW3
typedef union {
  struct {
    u64 chk_len : 32;
    u64 req_len : 14;
    u64 rsvd0   : 18;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_REQ_MSG_QW3;
//-----MACRO defines for Message:MR_MMU_REQ_MSG_QW3

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW3__REQ_LEN
#define MR_MMU_REQ_MSG_QW3__REQ_LEN__MSB                                    45
#define MR_MMU_REQ_MSG_QW3__REQ_LEN__LSB                                    32
#define MR_MMU_REQ_MSG_QW3__REQ_LEN__WIDTH                                  14
#define MR_MMU_REQ_MSG_QW3__REQ_LEN__MASK                       0x3fff00000000
#define MR_MMU_REQ_MSG_QW3__REQ_LEN__RESET_VALUE                           0x0

//-----MACRO defines for fields:MR_MMU_REQ_MSG_QW3__CHK_LEN
#define MR_MMU_REQ_MSG_QW3__CHK_LEN__MSB                                    31
#define MR_MMU_REQ_MSG_QW3__CHK_LEN__LSB                                     0
#define MR_MMU_REQ_MSG_QW3__CHK_LEN__WIDTH                                  32
#define MR_MMU_REQ_MSG_QW3__CHK_LEN__MASK                           0xffffffff
#define MR_MMU_REQ_MSG_QW3__CHK_LEN__RESET_VALUE                           0x0

typedef struct {
  MR_MMU_REQ_MSG_QW0  qw0;
  MR_MMU_REQ_MSG_QW1  qw1;
  MR_MMU_REQ_MSG_QW2  qw2;
  MR_MMU_REQ_MSG_QW3  qw3;
} MR_MMU_REQ_MSG;
//QW_CNT is actual number - 1
#define MR_MMU_REQ_MSG_QW_CNT                                                3
//-----MACRO defines for  Message Group MR_MMU_RSP_MSG: 0x30000
#define MR_MMU_RSP_MSG_MSG_ID                                              0x3
//-----Access structure typedef for Message:MR_MMU_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt       : 6;
    u64 dstfifo   : 4;
    u64 dst       : 2;
    u64 src       : 4;
    u64 req_tag   : 8;
    u64 msg_id    : 8;
    u64 last_frag : 1;
    u64 rsvd0     : 23;
    u64 sta       : 7;
    u64 mr_chk_en : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_RSP_MSG_QW0;
//-----MACRO defines for Message:MR_MMU_RSP_MSG_QW0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__MR_CHK_EN
#define MR_MMU_RSP_MSG_QW0__MR_CHK_EN__MSB                                  63
#define MR_MMU_RSP_MSG_QW0__MR_CHK_EN__LSB                                  63
#define MR_MMU_RSP_MSG_QW0__MR_CHK_EN__WIDTH                                 1
#define MR_MMU_RSP_MSG_QW0__MR_CHK_EN__MASK                 0x8000000000000000
#define MR_MMU_RSP_MSG_QW0__MR_CHK_EN__RESET_VALUE                         0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__STA
#define MR_MMU_RSP_MSG_QW0__STA__MSB                                        62
#define MR_MMU_RSP_MSG_QW0__STA__LSB                                        56
#define MR_MMU_RSP_MSG_QW0__STA__WIDTH                                       7
#define MR_MMU_RSP_MSG_QW0__STA__MASK                       0x7f00000000000000
#define MR_MMU_RSP_MSG_QW0__STA__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__LAST_FRAG
#define MR_MMU_RSP_MSG_QW0__LAST_FRAG__MSB                                  32
#define MR_MMU_RSP_MSG_QW0__LAST_FRAG__LSB                                  32
#define MR_MMU_RSP_MSG_QW0__LAST_FRAG__WIDTH                                 1
#define MR_MMU_RSP_MSG_QW0__LAST_FRAG__MASK                        0x100000000
#define MR_MMU_RSP_MSG_QW0__LAST_FRAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__MSG_ID
#define MR_MMU_RSP_MSG_QW0__MSG_ID__MSB                                     31
#define MR_MMU_RSP_MSG_QW0__MSG_ID__LSB                                     24
#define MR_MMU_RSP_MSG_QW0__MSG_ID__WIDTH                                    8
#define MR_MMU_RSP_MSG_QW0__MSG_ID__MASK                            0xff000000
#define MR_MMU_RSP_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__REQ_TAG
#define MR_MMU_RSP_MSG_QW0__REQ_TAG__MSB                                    23
#define MR_MMU_RSP_MSG_QW0__REQ_TAG__LSB                                    16
#define MR_MMU_RSP_MSG_QW0__REQ_TAG__WIDTH                                   8
#define MR_MMU_RSP_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define MR_MMU_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__SRC
#define MR_MMU_RSP_MSG_QW0__SRC__MSB                                        15
#define MR_MMU_RSP_MSG_QW0__SRC__LSB                                        12
#define MR_MMU_RSP_MSG_QW0__SRC__WIDTH                                       4
#define MR_MMU_RSP_MSG_QW0__SRC__MASK                                   0xf000
#define MR_MMU_RSP_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__DST
#define MR_MMU_RSP_MSG_QW0__DST__MSB                                        11
#define MR_MMU_RSP_MSG_QW0__DST__LSB                                        10
#define MR_MMU_RSP_MSG_QW0__DST__WIDTH                                       2
#define MR_MMU_RSP_MSG_QW0__DST__MASK                                    0xc00
#define MR_MMU_RSP_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__DSTFIFO
#define MR_MMU_RSP_MSG_QW0__DSTFIFO__MSB                                     9
#define MR_MMU_RSP_MSG_QW0__DSTFIFO__LSB                                     6
#define MR_MMU_RSP_MSG_QW0__DSTFIFO__WIDTH                                   4
#define MR_MMU_RSP_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define MR_MMU_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW0__CNT
#define MR_MMU_RSP_MSG_QW0__CNT__MSB                                         5
#define MR_MMU_RSP_MSG_QW0__CNT__LSB                                         0
#define MR_MMU_RSP_MSG_QW0__CNT__WIDTH                                       6
#define MR_MMU_RSP_MSG_QW0__CNT__MASK                                     0x3f
#define MR_MMU_RSP_MSG_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:MR_MMU_RSP_MSG_QW1
typedef union {
  struct {
    u64 pble_len0 : 13;
    u64 pble_len1 : 13;
    u64 pble_cnt  : 2;
    u64 rsvd0     : 36;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_RSP_MSG_QW1;
//-----MACRO defines for Message:MR_MMU_RSP_MSG_QW1

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW1__PBLE_CNT
#define MR_MMU_RSP_MSG_QW1__PBLE_CNT__MSB                                   27
#define MR_MMU_RSP_MSG_QW1__PBLE_CNT__LSB                                   26
#define MR_MMU_RSP_MSG_QW1__PBLE_CNT__WIDTH                                  2
#define MR_MMU_RSP_MSG_QW1__PBLE_CNT__MASK                           0xc000000
#define MR_MMU_RSP_MSG_QW1__PBLE_CNT__RESET_VALUE                          0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW1__PBLE_LEN1
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN1__MSB                                  25
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN1__LSB                                  13
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN1__WIDTH                                13
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN1__MASK                          0x3ffe000
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN1__RESET_VALUE                         0x0

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW1__PBLE_LEN0
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN0__MSB                                  12
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN0__LSB                                   0
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN0__WIDTH                                13
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN0__MASK                             0x1fff
#define MR_MMU_RSP_MSG_QW1__PBLE_LEN0__RESET_VALUE                         0x0

//-----Access structure typedef for Message:MR_MMU_RSP_MSG_QW2
typedef union {
  struct {
    u64 pble_pa0 : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_RSP_MSG_QW2;
//-----MACRO defines for Message:MR_MMU_RSP_MSG_QW2

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW2__PBLE_PA0
#define MR_MMU_RSP_MSG_QW2__PBLE_PA0__MSB                                   63
#define MR_MMU_RSP_MSG_QW2__PBLE_PA0__LSB                                    0
#define MR_MMU_RSP_MSG_QW2__PBLE_PA0__WIDTH                                 64
#define MR_MMU_RSP_MSG_QW2__PBLE_PA0__MASK                  0xffffffffffffffff
#define MR_MMU_RSP_MSG_QW2__PBLE_PA0__RESET_VALUE                          0x0

//-----Access structure typedef for Message:MR_MMU_RSP_MSG_QW3
typedef union {
  struct {
    u64 pble_pa1 : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MR_MMU_RSP_MSG_QW3;
//-----MACRO defines for Message:MR_MMU_RSP_MSG_QW3

//-----MACRO defines for fields:MR_MMU_RSP_MSG_QW3__PBLE_PA1
#define MR_MMU_RSP_MSG_QW3__PBLE_PA1__MSB                                   63
#define MR_MMU_RSP_MSG_QW3__PBLE_PA1__LSB                                    0
#define MR_MMU_RSP_MSG_QW3__PBLE_PA1__WIDTH                                 64
#define MR_MMU_RSP_MSG_QW3__PBLE_PA1__MASK                  0xffffffffffffffff
#define MR_MMU_RSP_MSG_QW3__PBLE_PA1__RESET_VALUE                          0x0

typedef struct {
  MR_MMU_RSP_MSG_QW0  qw0;
  MR_MMU_RSP_MSG_QW1  qw1;
  MR_MMU_RSP_MSG_QW2  qw2;
  MR_MMU_RSP_MSG_QW3  qw3;
} MR_MMU_RSP_MSG;
//QW_CNT is actual number - 1
#define MR_MMU_RSP_MSG_QW_CNT                                                3
//-----MACRO defines for  Message Group HMC_SD_REQ_MSG: 0x40000
#define HMC_SD_REQ_MSG_MSG_ID                                              0x4
//-----Access structure typedef for Message:HMC_SD_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 sd_idx  : 11;
    u64 sd_cnt  : 2;
    u64 pf_idx  : 2;
    u64 rsvd0   : 17;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_SD_REQ_MSG_QW0;
//-----MACRO defines for Message:HMC_SD_REQ_MSG_QW0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__PF_IDX
#define HMC_SD_REQ_MSG_QW0__PF_IDX__MSB                                     46
#define HMC_SD_REQ_MSG_QW0__PF_IDX__LSB                                     45
#define HMC_SD_REQ_MSG_QW0__PF_IDX__WIDTH                                    2
#define HMC_SD_REQ_MSG_QW0__PF_IDX__MASK                        0x600000000000
#define HMC_SD_REQ_MSG_QW0__PF_IDX__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__SD_CNT
#define HMC_SD_REQ_MSG_QW0__SD_CNT__MSB                                     44
#define HMC_SD_REQ_MSG_QW0__SD_CNT__LSB                                     43
#define HMC_SD_REQ_MSG_QW0__SD_CNT__WIDTH                                    2
#define HMC_SD_REQ_MSG_QW0__SD_CNT__MASK                        0x180000000000
#define HMC_SD_REQ_MSG_QW0__SD_CNT__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__SD_IDX
#define HMC_SD_REQ_MSG_QW0__SD_IDX__MSB                                     42
#define HMC_SD_REQ_MSG_QW0__SD_IDX__LSB                                     32
#define HMC_SD_REQ_MSG_QW0__SD_IDX__WIDTH                                   11
#define HMC_SD_REQ_MSG_QW0__SD_IDX__MASK                         0x7ff00000000
#define HMC_SD_REQ_MSG_QW0__SD_IDX__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__MSG_ID
#define HMC_SD_REQ_MSG_QW0__MSG_ID__MSB                                     31
#define HMC_SD_REQ_MSG_QW0__MSG_ID__LSB                                     24
#define HMC_SD_REQ_MSG_QW0__MSG_ID__WIDTH                                    8
#define HMC_SD_REQ_MSG_QW0__MSG_ID__MASK                            0xff000000
#define HMC_SD_REQ_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__REQ_TAG
#define HMC_SD_REQ_MSG_QW0__REQ_TAG__MSB                                    23
#define HMC_SD_REQ_MSG_QW0__REQ_TAG__LSB                                    16
#define HMC_SD_REQ_MSG_QW0__REQ_TAG__WIDTH                                   8
#define HMC_SD_REQ_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define HMC_SD_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__SRC
#define HMC_SD_REQ_MSG_QW0__SRC__MSB                                        15
#define HMC_SD_REQ_MSG_QW0__SRC__LSB                                        12
#define HMC_SD_REQ_MSG_QW0__SRC__WIDTH                                       4
#define HMC_SD_REQ_MSG_QW0__SRC__MASK                                   0xf000
#define HMC_SD_REQ_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__DST
#define HMC_SD_REQ_MSG_QW0__DST__MSB                                        11
#define HMC_SD_REQ_MSG_QW0__DST__LSB                                        10
#define HMC_SD_REQ_MSG_QW0__DST__WIDTH                                       2
#define HMC_SD_REQ_MSG_QW0__DST__MASK                                    0xc00
#define HMC_SD_REQ_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__DSTFIFO
#define HMC_SD_REQ_MSG_QW0__DSTFIFO__MSB                                     9
#define HMC_SD_REQ_MSG_QW0__DSTFIFO__LSB                                     6
#define HMC_SD_REQ_MSG_QW0__DSTFIFO__WIDTH                                   4
#define HMC_SD_REQ_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define HMC_SD_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW0__CNT
#define HMC_SD_REQ_MSG_QW0__CNT__MSB                                         5
#define HMC_SD_REQ_MSG_QW0__CNT__LSB                                         0
#define HMC_SD_REQ_MSG_QW0__CNT__WIDTH                                       6
#define HMC_SD_REQ_MSG_QW0__CNT__MASK                                     0x3f
#define HMC_SD_REQ_MSG_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:HMC_SD_REQ_MSG_QW1
typedef union {
  struct {
    u64 sd_vld  : 1;
    u64 sd_type : 1;
    u64 bp_cnt  : 10;
    u64 sd_data : 52;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_SD_REQ_MSG_QW1;
//-----MACRO defines for Message:HMC_SD_REQ_MSG_QW1

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW1__SD_DATA
#define HMC_SD_REQ_MSG_QW1__SD_DATA__MSB                                    63
#define HMC_SD_REQ_MSG_QW1__SD_DATA__LSB                                    12
#define HMC_SD_REQ_MSG_QW1__SD_DATA__WIDTH                                  52
#define HMC_SD_REQ_MSG_QW1__SD_DATA__MASK                   0xfffffffffffff000
#define HMC_SD_REQ_MSG_QW1__SD_DATA__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW1__BP_CNT
#define HMC_SD_REQ_MSG_QW1__BP_CNT__MSB                                     11
#define HMC_SD_REQ_MSG_QW1__BP_CNT__LSB                                      2
#define HMC_SD_REQ_MSG_QW1__BP_CNT__WIDTH                                   10
#define HMC_SD_REQ_MSG_QW1__BP_CNT__MASK                                 0xffc
#define HMC_SD_REQ_MSG_QW1__BP_CNT__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW1__SD_TYPE
#define HMC_SD_REQ_MSG_QW1__SD_TYPE__MSB                                     1
#define HMC_SD_REQ_MSG_QW1__SD_TYPE__LSB                                     1
#define HMC_SD_REQ_MSG_QW1__SD_TYPE__WIDTH                                   1
#define HMC_SD_REQ_MSG_QW1__SD_TYPE__MASK                                  0x2
#define HMC_SD_REQ_MSG_QW1__SD_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW1__SD_VLD
#define HMC_SD_REQ_MSG_QW1__SD_VLD__MSB                                      0
#define HMC_SD_REQ_MSG_QW1__SD_VLD__LSB                                      0
#define HMC_SD_REQ_MSG_QW1__SD_VLD__WIDTH                                    1
#define HMC_SD_REQ_MSG_QW1__SD_VLD__MASK                                   0x1
#define HMC_SD_REQ_MSG_QW1__SD_VLD__RESET_VALUE                            0x0

//-----Access structure typedef for Message:HMC_SD_REQ_MSG_QW2
typedef union {
  struct {
    u64 sd_vld  : 1;
    u64 sd_type : 1;
    u64 bp_cnt  : 10;
    u64 sd_data : 52;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_SD_REQ_MSG_QW2;
//-----MACRO defines for Message:HMC_SD_REQ_MSG_QW2

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW2__SD_DATA
#define HMC_SD_REQ_MSG_QW2__SD_DATA__MSB                                    63
#define HMC_SD_REQ_MSG_QW2__SD_DATA__LSB                                    12
#define HMC_SD_REQ_MSG_QW2__SD_DATA__WIDTH                                  52
#define HMC_SD_REQ_MSG_QW2__SD_DATA__MASK                   0xfffffffffffff000
#define HMC_SD_REQ_MSG_QW2__SD_DATA__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW2__BP_CNT
#define HMC_SD_REQ_MSG_QW2__BP_CNT__MSB                                     11
#define HMC_SD_REQ_MSG_QW2__BP_CNT__LSB                                      2
#define HMC_SD_REQ_MSG_QW2__BP_CNT__WIDTH                                   10
#define HMC_SD_REQ_MSG_QW2__BP_CNT__MASK                                 0xffc
#define HMC_SD_REQ_MSG_QW2__BP_CNT__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW2__SD_TYPE
#define HMC_SD_REQ_MSG_QW2__SD_TYPE__MSB                                     1
#define HMC_SD_REQ_MSG_QW2__SD_TYPE__LSB                                     1
#define HMC_SD_REQ_MSG_QW2__SD_TYPE__WIDTH                                   1
#define HMC_SD_REQ_MSG_QW2__SD_TYPE__MASK                                  0x2
#define HMC_SD_REQ_MSG_QW2__SD_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW2__SD_VLD
#define HMC_SD_REQ_MSG_QW2__SD_VLD__MSB                                      0
#define HMC_SD_REQ_MSG_QW2__SD_VLD__LSB                                      0
#define HMC_SD_REQ_MSG_QW2__SD_VLD__WIDTH                                    1
#define HMC_SD_REQ_MSG_QW2__SD_VLD__MASK                                   0x1
#define HMC_SD_REQ_MSG_QW2__SD_VLD__RESET_VALUE                            0x0

//-----Access structure typedef for Message:HMC_SD_REQ_MSG_QW3
typedef union {
  struct {
    u64 sd_vld  : 1;
    u64 sd_type : 1;
    u64 bp_cnt  : 10;
    u64 sd_data : 52;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_SD_REQ_MSG_QW3;
//-----MACRO defines for Message:HMC_SD_REQ_MSG_QW3

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW3__SD_DATA
#define HMC_SD_REQ_MSG_QW3__SD_DATA__MSB                                    63
#define HMC_SD_REQ_MSG_QW3__SD_DATA__LSB                                    12
#define HMC_SD_REQ_MSG_QW3__SD_DATA__WIDTH                                  52
#define HMC_SD_REQ_MSG_QW3__SD_DATA__MASK                   0xfffffffffffff000
#define HMC_SD_REQ_MSG_QW3__SD_DATA__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW3__BP_CNT
#define HMC_SD_REQ_MSG_QW3__BP_CNT__MSB                                     11
#define HMC_SD_REQ_MSG_QW3__BP_CNT__LSB                                      2
#define HMC_SD_REQ_MSG_QW3__BP_CNT__WIDTH                                   10
#define HMC_SD_REQ_MSG_QW3__BP_CNT__MASK                                 0xffc
#define HMC_SD_REQ_MSG_QW3__BP_CNT__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW3__SD_TYPE
#define HMC_SD_REQ_MSG_QW3__SD_TYPE__MSB                                     1
#define HMC_SD_REQ_MSG_QW3__SD_TYPE__LSB                                     1
#define HMC_SD_REQ_MSG_QW3__SD_TYPE__WIDTH                                   1
#define HMC_SD_REQ_MSG_QW3__SD_TYPE__MASK                                  0x2
#define HMC_SD_REQ_MSG_QW3__SD_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_REQ_MSG_QW3__SD_VLD
#define HMC_SD_REQ_MSG_QW3__SD_VLD__MSB                                      0
#define HMC_SD_REQ_MSG_QW3__SD_VLD__LSB                                      0
#define HMC_SD_REQ_MSG_QW3__SD_VLD__WIDTH                                    1
#define HMC_SD_REQ_MSG_QW3__SD_VLD__MASK                                   0x1
#define HMC_SD_REQ_MSG_QW3__SD_VLD__RESET_VALUE                            0x0

typedef struct {
  HMC_SD_REQ_MSG_QW0  qw0;
  HMC_SD_REQ_MSG_QW1  qw1;
  HMC_SD_REQ_MSG_QW2  qw2;
  HMC_SD_REQ_MSG_QW3  qw3;
} HMC_SD_REQ_MSG;
//QW_CNT is actual number - 1
#define HMC_SD_REQ_MSG_QW_CNT                                                3
//-----MACRO defines for  Message Group HMC_SD_RSP_MSG: 0x50000
#define HMC_SD_RSP_MSG_MSG_ID                                              0x5
//-----Access structure typedef for Message:HMC_SD_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 sd_idx  : 11;
    u64 rsvd0   : 17;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_SD_RSP_MSG_QW0;
//-----MACRO defines for Message:HMC_SD_RSP_MSG_QW0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__STA
#define HMC_SD_RSP_MSG_QW0__STA__MSB                                        63
#define HMC_SD_RSP_MSG_QW0__STA__LSB                                        60
#define HMC_SD_RSP_MSG_QW0__STA__WIDTH                                       4
#define HMC_SD_RSP_MSG_QW0__STA__MASK                       0xf000000000000000
#define HMC_SD_RSP_MSG_QW0__STA__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__SD_IDX
#define HMC_SD_RSP_MSG_QW0__SD_IDX__MSB                                     42
#define HMC_SD_RSP_MSG_QW0__SD_IDX__LSB                                     32
#define HMC_SD_RSP_MSG_QW0__SD_IDX__WIDTH                                   11
#define HMC_SD_RSP_MSG_QW0__SD_IDX__MASK                         0x7ff00000000
#define HMC_SD_RSP_MSG_QW0__SD_IDX__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__MSG_ID
#define HMC_SD_RSP_MSG_QW0__MSG_ID__MSB                                     31
#define HMC_SD_RSP_MSG_QW0__MSG_ID__LSB                                     24
#define HMC_SD_RSP_MSG_QW0__MSG_ID__WIDTH                                    8
#define HMC_SD_RSP_MSG_QW0__MSG_ID__MASK                            0xff000000
#define HMC_SD_RSP_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__REQ_TAG
#define HMC_SD_RSP_MSG_QW0__REQ_TAG__MSB                                    23
#define HMC_SD_RSP_MSG_QW0__REQ_TAG__LSB                                    16
#define HMC_SD_RSP_MSG_QW0__REQ_TAG__WIDTH                                   8
#define HMC_SD_RSP_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define HMC_SD_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__SRC
#define HMC_SD_RSP_MSG_QW0__SRC__MSB                                        15
#define HMC_SD_RSP_MSG_QW0__SRC__LSB                                        12
#define HMC_SD_RSP_MSG_QW0__SRC__WIDTH                                       4
#define HMC_SD_RSP_MSG_QW0__SRC__MASK                                   0xf000
#define HMC_SD_RSP_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__DST
#define HMC_SD_RSP_MSG_QW0__DST__MSB                                        11
#define HMC_SD_RSP_MSG_QW0__DST__LSB                                        10
#define HMC_SD_RSP_MSG_QW0__DST__WIDTH                                       2
#define HMC_SD_RSP_MSG_QW0__DST__MASK                                    0xc00
#define HMC_SD_RSP_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__DSTFIFO
#define HMC_SD_RSP_MSG_QW0__DSTFIFO__MSB                                     9
#define HMC_SD_RSP_MSG_QW0__DSTFIFO__LSB                                     6
#define HMC_SD_RSP_MSG_QW0__DSTFIFO__WIDTH                                   4
#define HMC_SD_RSP_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define HMC_SD_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:HMC_SD_RSP_MSG_QW0__CNT
#define HMC_SD_RSP_MSG_QW0__CNT__MSB                                         5
#define HMC_SD_RSP_MSG_QW0__CNT__LSB                                         0
#define HMC_SD_RSP_MSG_QW0__CNT__WIDTH                                       6
#define HMC_SD_RSP_MSG_QW0__CNT__MASK                                     0x3f
#define HMC_SD_RSP_MSG_QW0__CNT__RESET_VALUE                               0x0

typedef struct {
  HMC_SD_RSP_MSG_QW0  qw0;
} HMC_SD_RSP_MSG;
//QW_CNT is actual number - 1
#define HMC_SD_RSP_MSG_QW_CNT                                                0
//-----MACRO defines for  Message Group HMC_REQ_MSG: 0x60000
#define HMC_REQ_MSG_MSG_ID                                                 0x6
//-----Access structure typedef for Message:HMC_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 1;
    u64 opcode  : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_REQ_MSG_QW0;
//-----MACRO defines for Message:HMC_REQ_MSG_QW0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__OPCODE
#define HMC_REQ_MSG_QW0__OPCODE__MSB                                        63
#define HMC_REQ_MSG_QW0__OPCODE__LSB                                        60
#define HMC_REQ_MSG_QW0__OPCODE__WIDTH                                       4
#define HMC_REQ_MSG_QW0__OPCODE__MASK                       0xf000000000000000
#define HMC_REQ_MSG_QW0__OPCODE__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__FPM
#define HMC_REQ_MSG_QW0__FPM__MSB                                           58
#define HMC_REQ_MSG_QW0__FPM__LSB                                           49
#define HMC_REQ_MSG_QW0__FPM__WIDTH                                         10
#define HMC_REQ_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define HMC_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__QPN
#define HMC_REQ_MSG_QW0__QPN__MSB                                           48
#define HMC_REQ_MSG_QW0__QPN__LSB                                           32
#define HMC_REQ_MSG_QW0__QPN__WIDTH                                         17
#define HMC_REQ_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define HMC_REQ_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__MSG_ID
#define HMC_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define HMC_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define HMC_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define HMC_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define HMC_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__REQ_TAG
#define HMC_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define HMC_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define HMC_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define HMC_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define HMC_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__SRC
#define HMC_REQ_MSG_QW0__SRC__MSB                                           15
#define HMC_REQ_MSG_QW0__SRC__LSB                                           12
#define HMC_REQ_MSG_QW0__SRC__WIDTH                                          4
#define HMC_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define HMC_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__DST
#define HMC_REQ_MSG_QW0__DST__MSB                                           11
#define HMC_REQ_MSG_QW0__DST__LSB                                           10
#define HMC_REQ_MSG_QW0__DST__WIDTH                                          2
#define HMC_REQ_MSG_QW0__DST__MASK                                       0xc00
#define HMC_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__DSTFIFO
#define HMC_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define HMC_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define HMC_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define HMC_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define HMC_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW0__CNT
#define HMC_REQ_MSG_QW0__CNT__MSB                                            5
#define HMC_REQ_MSG_QW0__CNT__LSB                                            0
#define HMC_REQ_MSG_QW0__CNT__WIDTH                                          6
#define HMC_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define HMC_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:HMC_REQ_MSG_QW1
typedef union {
  struct {
    u64 obj_index     : 32;
    u64 obj_type      : 5;
    u64 qw_ofst       : 5;
    u64 cbuf_addr_vld : 1;
    u64 rsvd0         : 16;
    u64 qw_cnt        : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_REQ_MSG_QW1;
//-----MACRO defines for Message:HMC_REQ_MSG_QW1

//-----MACRO defines for fields:HMC_REQ_MSG_QW1__QW_CNT
#define HMC_REQ_MSG_QW1__QW_CNT__MSB                                        63
#define HMC_REQ_MSG_QW1__QW_CNT__LSB                                        59
#define HMC_REQ_MSG_QW1__QW_CNT__WIDTH                                       5
#define HMC_REQ_MSG_QW1__QW_CNT__MASK                       0xf800000000000000
#define HMC_REQ_MSG_QW1__QW_CNT__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW1__CBUF_ADDR_VLD
#define HMC_REQ_MSG_QW1__CBUF_ADDR_VLD__MSB                                 42
#define HMC_REQ_MSG_QW1__CBUF_ADDR_VLD__LSB                                 42
#define HMC_REQ_MSG_QW1__CBUF_ADDR_VLD__WIDTH                                1
#define HMC_REQ_MSG_QW1__CBUF_ADDR_VLD__MASK                     0x40000000000
#define HMC_REQ_MSG_QW1__CBUF_ADDR_VLD__RESET_VALUE                        0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW1__QW_OFST
#define HMC_REQ_MSG_QW1__QW_OFST__MSB                                       41
#define HMC_REQ_MSG_QW1__QW_OFST__LSB                                       37
#define HMC_REQ_MSG_QW1__QW_OFST__WIDTH                                      5
#define HMC_REQ_MSG_QW1__QW_OFST__MASK                           0x3e000000000
#define HMC_REQ_MSG_QW1__QW_OFST__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW1__OBJ_TYPE
#define HMC_REQ_MSG_QW1__OBJ_TYPE__MSB                                      36
#define HMC_REQ_MSG_QW1__OBJ_TYPE__LSB                                      32
#define HMC_REQ_MSG_QW1__OBJ_TYPE__WIDTH                                     5
#define HMC_REQ_MSG_QW1__OBJ_TYPE__MASK                           0x1f00000000
#define HMC_REQ_MSG_QW1__OBJ_TYPE__RESET_VALUE                             0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW1__OBJ_INDEX
#define HMC_REQ_MSG_QW1__OBJ_INDEX__MSB                                     31
#define HMC_REQ_MSG_QW1__OBJ_INDEX__LSB                                      0
#define HMC_REQ_MSG_QW1__OBJ_INDEX__WIDTH                                   32
#define HMC_REQ_MSG_QW1__OBJ_INDEX__MASK                            0xffffffff
#define HMC_REQ_MSG_QW1__OBJ_INDEX__RESET_VALUE                            0x0

//-----Access structure typedef for Message:HMC_REQ_MSG_QW2
typedef union {
  struct {
    u64 cbuf_addr : 32;
    u64 rsvd0     : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_REQ_MSG_QW2;
//-----MACRO defines for Message:HMC_REQ_MSG_QW2

//-----MACRO defines for fields:HMC_REQ_MSG_QW2__CBUF_ADDR
#define HMC_REQ_MSG_QW2__CBUF_ADDR__MSB                                     31
#define HMC_REQ_MSG_QW2__CBUF_ADDR__LSB                                      0
#define HMC_REQ_MSG_QW2__CBUF_ADDR__WIDTH                                   32
#define HMC_REQ_MSG_QW2__CBUF_ADDR__MASK                            0xffffffff
#define HMC_REQ_MSG_QW2__CBUF_ADDR__RESET_VALUE                            0x0

//-----Access structure typedef for Message:HMC_REQ_MSG_QW3
typedef union {
  struct {
    u128 wr_qw_op0      : 4;
    u128 wr_qw_ofset0   : 5;
    u128 wr_unmask_lsb0 : 6;
    u128 wr_unmask_msb0 : 6;
    u128 rsvd0          : 43;
    u128 wdata_0        : 64;
  };
  u128 reg;
} HMC_REQ_MSG_QW3;
//-----MACRO defines for Message:HMC_REQ_MSG_QW3

//-----MACRO defines for fields:HMC_REQ_MSG_QW3__WR_UNMASK_MSB0
#define HMC_REQ_MSG_QW3__WR_UNMASK_MSB0__MSB                                20
#define HMC_REQ_MSG_QW3__WR_UNMASK_MSB0__LSB                                15
#define HMC_REQ_MSG_QW3__WR_UNMASK_MSB0__WIDTH                               6
#define HMC_REQ_MSG_QW3__WR_UNMASK_MSB0__MASK                         0x1f8000
#define HMC_REQ_MSG_QW3__WR_UNMASK_MSB0__RESET_VALUE                       0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW3__WR_UNMASK_LSB0
#define HMC_REQ_MSG_QW3__WR_UNMASK_LSB0__MSB                                14
#define HMC_REQ_MSG_QW3__WR_UNMASK_LSB0__LSB                                 9
#define HMC_REQ_MSG_QW3__WR_UNMASK_LSB0__WIDTH                               6
#define HMC_REQ_MSG_QW3__WR_UNMASK_LSB0__MASK                           0x7e00
#define HMC_REQ_MSG_QW3__WR_UNMASK_LSB0__RESET_VALUE                       0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW3__WR_QW_OFSET0
#define HMC_REQ_MSG_QW3__WR_QW_OFSET0__MSB                                   8
#define HMC_REQ_MSG_QW3__WR_QW_OFSET0__LSB                                   4
#define HMC_REQ_MSG_QW3__WR_QW_OFSET0__WIDTH                                 5
#define HMC_REQ_MSG_QW3__WR_QW_OFSET0__MASK                              0x1f0
#define HMC_REQ_MSG_QW3__WR_QW_OFSET0__RESET_VALUE                         0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW3__WR_QW_OP0
#define HMC_REQ_MSG_QW3__WR_QW_OP0__MSB                                      3
#define HMC_REQ_MSG_QW3__WR_QW_OP0__LSB                                      0
#define HMC_REQ_MSG_QW3__WR_QW_OP0__WIDTH                                    4
#define HMC_REQ_MSG_QW3__WR_QW_OP0__MASK                                   0xf
#define HMC_REQ_MSG_QW3__WR_QW_OP0__RESET_VALUE                            0x0

//-----MACRO defines for fields:HMC_REQ_MSG_QW3__WDATA_0
#define HMC_REQ_MSG_QW3__WDATA_0__MSB                                      127
#define HMC_REQ_MSG_QW3__WDATA_0__LSB                                       64
#define HMC_REQ_MSG_QW3__WDATA_0__WIDTH                                     64
#define HMC_REQ_MSG_QW3__WDATA_0__MASK      0xffffffffffffffff0000000000000000
#define HMC_REQ_MSG_QW3__WDATA_0__RESET_VALUE                              0x0

//-----Access structure typedef for Message:HMC_REQ_MSG_QW4
typedef union {
  struct {
    u64 create_data : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_REQ_MSG_QW4;
//-----MACRO defines for Message:HMC_REQ_MSG_QW4

//-----MACRO defines for fields:HMC_REQ_MSG_QW4__CREATE_DATA
#define HMC_REQ_MSG_QW4__CREATE_DATA__MSB                                   63
#define HMC_REQ_MSG_QW4__CREATE_DATA__LSB                                    0
#define HMC_REQ_MSG_QW4__CREATE_DATA__WIDTH                                 64
#define HMC_REQ_MSG_QW4__CREATE_DATA__MASK                  0xffffffffffffffff
#define HMC_REQ_MSG_QW4__CREATE_DATA__RESET_VALUE                          0x0

typedef struct {
  HMC_REQ_MSG_QW0  qw0;
  HMC_REQ_MSG_QW1  qw1;
  HMC_REQ_MSG_QW2  qw2;
  HMC_REQ_MSG_QW3  qw3;
  HMC_REQ_MSG_QW4  qw4;
} HMC_REQ_MSG;
//QW_CNT is actual number - 1
#define HMC_REQ_MSG_QW_CNT                                                   4
//-----MACRO defines for  Message Group HMC_RSP_MSG: 0x70000
#define HMC_RSP_MSG_MSG_ID                                                 0x7
//-----Access structure typedef for Message:HMC_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_RSP_MSG_QW0;
//-----MACRO defines for Message:HMC_RSP_MSG_QW0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__STA
#define HMC_RSP_MSG_QW0__STA__MSB                                           63
#define HMC_RSP_MSG_QW0__STA__LSB                                           60
#define HMC_RSP_MSG_QW0__STA__WIDTH                                          4
#define HMC_RSP_MSG_QW0__STA__MASK                          0xf000000000000000
#define HMC_RSP_MSG_QW0__STA__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__MSG_ID
#define HMC_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define HMC_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define HMC_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define HMC_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define HMC_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__REQ_TAG
#define HMC_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define HMC_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define HMC_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define HMC_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define HMC_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__SRC
#define HMC_RSP_MSG_QW0__SRC__MSB                                           15
#define HMC_RSP_MSG_QW0__SRC__LSB                                           12
#define HMC_RSP_MSG_QW0__SRC__WIDTH                                          4
#define HMC_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define HMC_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__DST
#define HMC_RSP_MSG_QW0__DST__MSB                                           11
#define HMC_RSP_MSG_QW0__DST__LSB                                           10
#define HMC_RSP_MSG_QW0__DST__WIDTH                                          2
#define HMC_RSP_MSG_QW0__DST__MASK                                       0xc00
#define HMC_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__DSTFIFO
#define HMC_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define HMC_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define HMC_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define HMC_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define HMC_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:HMC_RSP_MSG_QW0__CNT
#define HMC_RSP_MSG_QW0__CNT__MSB                                            5
#define HMC_RSP_MSG_QW0__CNT__LSB                                            0
#define HMC_RSP_MSG_QW0__CNT__WIDTH                                          6
#define HMC_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define HMC_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:HMC_RSP_MSG_QW1
typedef union {
  struct {
    u64 rdata : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} HMC_RSP_MSG_QW1;
//-----MACRO defines for Message:HMC_RSP_MSG_QW1

//-----MACRO defines for fields:HMC_RSP_MSG_QW1__RDATA
#define HMC_RSP_MSG_QW1__RDATA__MSB                                         63
#define HMC_RSP_MSG_QW1__RDATA__LSB                                          0
#define HMC_RSP_MSG_QW1__RDATA__WIDTH                                       64
#define HMC_RSP_MSG_QW1__RDATA__MASK                        0xffffffffffffffff
#define HMC_RSP_MSG_QW1__RDATA__RESET_VALUE                                0x0

typedef struct {
  HMC_RSP_MSG_QW0  qw0;
  HMC_RSP_MSG_QW1  qw1;
} HMC_RSP_MSG;
//QW_CNT is actual number - 1
#define HMC_RSP_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group FRDMA_REQ_MSG: 0x80000
#define FRDMA_REQ_MSG_MSG_ID                                               0x8
//-----Access structure typedef for Message:FRDMA_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt      : 6;
    u64 dstfifo  : 4;
    u64 dst      : 2;
    u64 rsvd0    : 4;
    u64 req_tag  : 8;
    u64 msg_id   : 8;
    u64 rsvd1    : 17;
    u64 vsi      : 10;
    u64 force_pf : 1;
    u64 pf_idx   : 2;
    u64 cbuf     : 1;
    u64 err      : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FRDMA_REQ_MSG_QW0;
//-----MACRO defines for Message:FRDMA_REQ_MSG_QW0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__ERR
#define FRDMA_REQ_MSG_QW0__ERR__MSB                                         63
#define FRDMA_REQ_MSG_QW0__ERR__LSB                                         63
#define FRDMA_REQ_MSG_QW0__ERR__WIDTH                                        1
#define FRDMA_REQ_MSG_QW0__ERR__MASK                        0x8000000000000000
#define FRDMA_REQ_MSG_QW0__ERR__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__CBUF
#define FRDMA_REQ_MSG_QW0__CBUF__MSB                                        62
#define FRDMA_REQ_MSG_QW0__CBUF__LSB                                        62
#define FRDMA_REQ_MSG_QW0__CBUF__WIDTH                                       1
#define FRDMA_REQ_MSG_QW0__CBUF__MASK                       0x4000000000000000
#define FRDMA_REQ_MSG_QW0__CBUF__RESET_VALUE                               0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__PF_IDX
#define FRDMA_REQ_MSG_QW0__PF_IDX__MSB                                      61
#define FRDMA_REQ_MSG_QW0__PF_IDX__LSB                                      60
#define FRDMA_REQ_MSG_QW0__PF_IDX__WIDTH                                     2
#define FRDMA_REQ_MSG_QW0__PF_IDX__MASK                     0x3000000000000000
#define FRDMA_REQ_MSG_QW0__PF_IDX__RESET_VALUE                             0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__FORCE_PF
#define FRDMA_REQ_MSG_QW0__FORCE_PF__MSB                                    59
#define FRDMA_REQ_MSG_QW0__FORCE_PF__LSB                                    59
#define FRDMA_REQ_MSG_QW0__FORCE_PF__WIDTH                                   1
#define FRDMA_REQ_MSG_QW0__FORCE_PF__MASK                    0x800000000000000
#define FRDMA_REQ_MSG_QW0__FORCE_PF__RESET_VALUE                           0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__VSI
#define FRDMA_REQ_MSG_QW0__VSI__MSB                                         58
#define FRDMA_REQ_MSG_QW0__VSI__LSB                                         49
#define FRDMA_REQ_MSG_QW0__VSI__WIDTH                                       10
#define FRDMA_REQ_MSG_QW0__VSI__MASK                         0x7fe000000000000
#define FRDMA_REQ_MSG_QW0__VSI__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__MSG_ID
#define FRDMA_REQ_MSG_QW0__MSG_ID__MSB                                      31
#define FRDMA_REQ_MSG_QW0__MSG_ID__LSB                                      24
#define FRDMA_REQ_MSG_QW0__MSG_ID__WIDTH                                     8
#define FRDMA_REQ_MSG_QW0__MSG_ID__MASK                             0xff000000
#define FRDMA_REQ_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__REQ_TAG
#define FRDMA_REQ_MSG_QW0__REQ_TAG__MSB                                     23
#define FRDMA_REQ_MSG_QW0__REQ_TAG__LSB                                     16
#define FRDMA_REQ_MSG_QW0__REQ_TAG__WIDTH                                    8
#define FRDMA_REQ_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define FRDMA_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__DST
#define FRDMA_REQ_MSG_QW0__DST__MSB                                         11
#define FRDMA_REQ_MSG_QW0__DST__LSB                                         10
#define FRDMA_REQ_MSG_QW0__DST__WIDTH                                        2
#define FRDMA_REQ_MSG_QW0__DST__MASK                                     0xc00
#define FRDMA_REQ_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__DSTFIFO
#define FRDMA_REQ_MSG_QW0__DSTFIFO__MSB                                      9
#define FRDMA_REQ_MSG_QW0__DSTFIFO__LSB                                      6
#define FRDMA_REQ_MSG_QW0__DSTFIFO__WIDTH                                    4
#define FRDMA_REQ_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define FRDMA_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW0__CNT
#define FRDMA_REQ_MSG_QW0__CNT__MSB                                          5
#define FRDMA_REQ_MSG_QW0__CNT__LSB                                          0
#define FRDMA_REQ_MSG_QW0__CNT__WIDTH                                        6
#define FRDMA_REQ_MSG_QW0__CNT__MASK                                      0x3f
#define FRDMA_REQ_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:FRDMA_REQ_MSG_QW1
typedef union {
  struct {
    u64 cbuf_addr : 26;
    u64 rsvd0     : 6;
    u64 bcnt      : 13;
    u64 rsvd1     : 4;
    u64 req_type  : 5;
    u64 rsvd2     : 1;
    u64 tph_en    : 1;
    u64 tph_val   : 8;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FRDMA_REQ_MSG_QW1;
//-----MACRO defines for Message:FRDMA_REQ_MSG_QW1

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW1__TPH_VAL
#define FRDMA_REQ_MSG_QW1__TPH_VAL__MSB                                     63
#define FRDMA_REQ_MSG_QW1__TPH_VAL__LSB                                     56
#define FRDMA_REQ_MSG_QW1__TPH_VAL__WIDTH                                    8
#define FRDMA_REQ_MSG_QW1__TPH_VAL__MASK                    0xff00000000000000
#define FRDMA_REQ_MSG_QW1__TPH_VAL__RESET_VALUE                            0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW1__TPH_EN
#define FRDMA_REQ_MSG_QW1__TPH_EN__MSB                                      55
#define FRDMA_REQ_MSG_QW1__TPH_EN__LSB                                      55
#define FRDMA_REQ_MSG_QW1__TPH_EN__WIDTH                                     1
#define FRDMA_REQ_MSG_QW1__TPH_EN__MASK                       0x80000000000000
#define FRDMA_REQ_MSG_QW1__TPH_EN__RESET_VALUE                             0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW1__REQ_TYPE
#define FRDMA_REQ_MSG_QW1__REQ_TYPE__MSB                                    53
#define FRDMA_REQ_MSG_QW1__REQ_TYPE__LSB                                    49
#define FRDMA_REQ_MSG_QW1__REQ_TYPE__WIDTH                                   5
#define FRDMA_REQ_MSG_QW1__REQ_TYPE__MASK                     0x3e000000000000
#define FRDMA_REQ_MSG_QW1__REQ_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW1__BCNT
#define FRDMA_REQ_MSG_QW1__BCNT__MSB                                        44
#define FRDMA_REQ_MSG_QW1__BCNT__LSB                                        32
#define FRDMA_REQ_MSG_QW1__BCNT__WIDTH                                      13
#define FRDMA_REQ_MSG_QW1__BCNT__MASK                           0x1fff00000000
#define FRDMA_REQ_MSG_QW1__BCNT__RESET_VALUE                               0x0

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW1__CBUF_ADDR
#define FRDMA_REQ_MSG_QW1__CBUF_ADDR__MSB                                   25
#define FRDMA_REQ_MSG_QW1__CBUF_ADDR__LSB                                    0
#define FRDMA_REQ_MSG_QW1__CBUF_ADDR__WIDTH                                 26
#define FRDMA_REQ_MSG_QW1__CBUF_ADDR__MASK                           0x3ffffff
#define FRDMA_REQ_MSG_QW1__CBUF_ADDR__RESET_VALUE                          0x0

//-----Access structure typedef for Message:FRDMA_REQ_MSG_QW2
typedef union {
  struct {
    u64 pa    : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FRDMA_REQ_MSG_QW2;
//-----MACRO defines for Message:FRDMA_REQ_MSG_QW2

//-----MACRO defines for fields:FRDMA_REQ_MSG_QW2__PA
#define FRDMA_REQ_MSG_QW2__PA__MSB                                          63
#define FRDMA_REQ_MSG_QW2__PA__LSB                                           0
#define FRDMA_REQ_MSG_QW2__PA__WIDTH                                        64
#define FRDMA_REQ_MSG_QW2__PA__MASK                         0xffffffffffffffff
#define FRDMA_REQ_MSG_QW2__PA__RESET_VALUE                                 0x0

typedef struct {
  FRDMA_REQ_MSG_QW0  qw0;
  FRDMA_REQ_MSG_QW1  qw1;
  FRDMA_REQ_MSG_QW2  qw2;
} FRDMA_REQ_MSG;
//QW_CNT is actual number - 1
#define FRDMA_REQ_MSG_QW_CNT                                                 2
//-----MACRO defines for  Message Group FRDMA_RSP_MSG: 0x90000
#define FRDMA_RSP_MSG_MSG_ID                                               0x9
//-----Access structure typedef for Message:FRDMA_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FRDMA_RSP_MSG_QW0;
//-----MACRO defines for Message:FRDMA_RSP_MSG_QW0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__STA
#define FRDMA_RSP_MSG_QW0__STA__MSB                                         63
#define FRDMA_RSP_MSG_QW0__STA__LSB                                         60
#define FRDMA_RSP_MSG_QW0__STA__WIDTH                                        4
#define FRDMA_RSP_MSG_QW0__STA__MASK                        0xf000000000000000
#define FRDMA_RSP_MSG_QW0__STA__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__MSG_ID
#define FRDMA_RSP_MSG_QW0__MSG_ID__MSB                                      31
#define FRDMA_RSP_MSG_QW0__MSG_ID__LSB                                      24
#define FRDMA_RSP_MSG_QW0__MSG_ID__WIDTH                                     8
#define FRDMA_RSP_MSG_QW0__MSG_ID__MASK                             0xff000000
#define FRDMA_RSP_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__REQ_TAG
#define FRDMA_RSP_MSG_QW0__REQ_TAG__MSB                                     23
#define FRDMA_RSP_MSG_QW0__REQ_TAG__LSB                                     16
#define FRDMA_RSP_MSG_QW0__REQ_TAG__WIDTH                                    8
#define FRDMA_RSP_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define FRDMA_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__SRC
#define FRDMA_RSP_MSG_QW0__SRC__MSB                                         15
#define FRDMA_RSP_MSG_QW0__SRC__LSB                                         12
#define FRDMA_RSP_MSG_QW0__SRC__WIDTH                                        4
#define FRDMA_RSP_MSG_QW0__SRC__MASK                                    0xf000
#define FRDMA_RSP_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__DST
#define FRDMA_RSP_MSG_QW0__DST__MSB                                         11
#define FRDMA_RSP_MSG_QW0__DST__LSB                                         10
#define FRDMA_RSP_MSG_QW0__DST__WIDTH                                        2
#define FRDMA_RSP_MSG_QW0__DST__MASK                                     0xc00
#define FRDMA_RSP_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__DSTFIFO
#define FRDMA_RSP_MSG_QW0__DSTFIFO__MSB                                      9
#define FRDMA_RSP_MSG_QW0__DSTFIFO__LSB                                      6
#define FRDMA_RSP_MSG_QW0__DSTFIFO__WIDTH                                    4
#define FRDMA_RSP_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define FRDMA_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:FRDMA_RSP_MSG_QW0__CNT
#define FRDMA_RSP_MSG_QW0__CNT__MSB                                          5
#define FRDMA_RSP_MSG_QW0__CNT__LSB                                          0
#define FRDMA_RSP_MSG_QW0__CNT__WIDTH                                        6
#define FRDMA_RSP_MSG_QW0__CNT__MASK                                      0x3f
#define FRDMA_RSP_MSG_QW0__CNT__RESET_VALUE                                0x0

typedef struct {
  FRDMA_RSP_MSG_QW0  qw0;
} FRDMA_RSP_MSG;
//QW_CNT is actual number - 1
#define FRDMA_RSP_MSG_QW_CNT                                                 0
//-----MACRO defines for  Message Group FWDMA_REQ_MSG: 0xa0000
#define FWDMA_REQ_MSG_MSG_ID                                               0xa
//-----Access structure typedef for Message:FWDMA_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt        : 6;
    u64 dstfifo    : 4;
    u64 dst        : 2;
    u64 src        : 4;
    u64 req_tag    : 8;
    u64 msg_id     : 8;
    u64 lli        : 1;
    u64 int_vec    : 10;
    u64 int_en     : 1;
    u64 req_tyte   : 5;
    u64 vsi        : 10;
    u64 force_pf   : 1;
    u64 pf_idx     : 2;
    u64 coalesc_en : 1;
    u64 err        : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FWDMA_REQ_MSG_QW0;
//-----MACRO defines for Message:FWDMA_REQ_MSG_QW0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__ERR
#define FWDMA_REQ_MSG_QW0__ERR__MSB                                         63
#define FWDMA_REQ_MSG_QW0__ERR__LSB                                         63
#define FWDMA_REQ_MSG_QW0__ERR__WIDTH                                        1
#define FWDMA_REQ_MSG_QW0__ERR__MASK                        0x8000000000000000
#define FWDMA_REQ_MSG_QW0__ERR__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__COALESC_EN
#define FWDMA_REQ_MSG_QW0__COALESC_EN__MSB                                  62
#define FWDMA_REQ_MSG_QW0__COALESC_EN__LSB                                  62
#define FWDMA_REQ_MSG_QW0__COALESC_EN__WIDTH                                 1
#define FWDMA_REQ_MSG_QW0__COALESC_EN__MASK                 0x4000000000000000
#define FWDMA_REQ_MSG_QW0__COALESC_EN__RESET_VALUE                         0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__PF_IDX
#define FWDMA_REQ_MSG_QW0__PF_IDX__MSB                                      61
#define FWDMA_REQ_MSG_QW0__PF_IDX__LSB                                      60
#define FWDMA_REQ_MSG_QW0__PF_IDX__WIDTH                                     2
#define FWDMA_REQ_MSG_QW0__PF_IDX__MASK                     0x3000000000000000
#define FWDMA_REQ_MSG_QW0__PF_IDX__RESET_VALUE                             0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__FORCE_PF
#define FWDMA_REQ_MSG_QW0__FORCE_PF__MSB                                    59
#define FWDMA_REQ_MSG_QW0__FORCE_PF__LSB                                    59
#define FWDMA_REQ_MSG_QW0__FORCE_PF__WIDTH                                   1
#define FWDMA_REQ_MSG_QW0__FORCE_PF__MASK                    0x800000000000000
#define FWDMA_REQ_MSG_QW0__FORCE_PF__RESET_VALUE                           0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__VSI
#define FWDMA_REQ_MSG_QW0__VSI__MSB                                         58
#define FWDMA_REQ_MSG_QW0__VSI__LSB                                         49
#define FWDMA_REQ_MSG_QW0__VSI__WIDTH                                       10
#define FWDMA_REQ_MSG_QW0__VSI__MASK                         0x7fe000000000000
#define FWDMA_REQ_MSG_QW0__VSI__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__REQ_TYTE
#define FWDMA_REQ_MSG_QW0__REQ_TYTE__MSB                                    48
#define FWDMA_REQ_MSG_QW0__REQ_TYTE__LSB                                    44
#define FWDMA_REQ_MSG_QW0__REQ_TYTE__WIDTH                                   5
#define FWDMA_REQ_MSG_QW0__REQ_TYTE__MASK                      0x1f00000000000
#define FWDMA_REQ_MSG_QW0__REQ_TYTE__RESET_VALUE                           0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__INT_EN
#define FWDMA_REQ_MSG_QW0__INT_EN__MSB                                      43
#define FWDMA_REQ_MSG_QW0__INT_EN__LSB                                      43
#define FWDMA_REQ_MSG_QW0__INT_EN__WIDTH                                     1
#define FWDMA_REQ_MSG_QW0__INT_EN__MASK                          0x80000000000
#define FWDMA_REQ_MSG_QW0__INT_EN__RESET_VALUE                             0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__INT_VEC
#define FWDMA_REQ_MSG_QW0__INT_VEC__MSB                                     42
#define FWDMA_REQ_MSG_QW0__INT_VEC__LSB                                     33
#define FWDMA_REQ_MSG_QW0__INT_VEC__WIDTH                                   10
#define FWDMA_REQ_MSG_QW0__INT_VEC__MASK                         0x7fe00000000
#define FWDMA_REQ_MSG_QW0__INT_VEC__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__LLI
#define FWDMA_REQ_MSG_QW0__LLI__MSB                                         32
#define FWDMA_REQ_MSG_QW0__LLI__LSB                                         32
#define FWDMA_REQ_MSG_QW0__LLI__WIDTH                                        1
#define FWDMA_REQ_MSG_QW0__LLI__MASK                               0x100000000
#define FWDMA_REQ_MSG_QW0__LLI__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__MSG_ID
#define FWDMA_REQ_MSG_QW0__MSG_ID__MSB                                      31
#define FWDMA_REQ_MSG_QW0__MSG_ID__LSB                                      24
#define FWDMA_REQ_MSG_QW0__MSG_ID__WIDTH                                     8
#define FWDMA_REQ_MSG_QW0__MSG_ID__MASK                             0xff000000
#define FWDMA_REQ_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__REQ_TAG
#define FWDMA_REQ_MSG_QW0__REQ_TAG__MSB                                     23
#define FWDMA_REQ_MSG_QW0__REQ_TAG__LSB                                     16
#define FWDMA_REQ_MSG_QW0__REQ_TAG__WIDTH                                    8
#define FWDMA_REQ_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define FWDMA_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__SRC
#define FWDMA_REQ_MSG_QW0__SRC__MSB                                         15
#define FWDMA_REQ_MSG_QW0__SRC__LSB                                         12
#define FWDMA_REQ_MSG_QW0__SRC__WIDTH                                        4
#define FWDMA_REQ_MSG_QW0__SRC__MASK                                    0xf000
#define FWDMA_REQ_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__DST
#define FWDMA_REQ_MSG_QW0__DST__MSB                                         11
#define FWDMA_REQ_MSG_QW0__DST__LSB                                         10
#define FWDMA_REQ_MSG_QW0__DST__WIDTH                                        2
#define FWDMA_REQ_MSG_QW0__DST__MASK                                     0xc00
#define FWDMA_REQ_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__DSTFIFO
#define FWDMA_REQ_MSG_QW0__DSTFIFO__MSB                                      9
#define FWDMA_REQ_MSG_QW0__DSTFIFO__LSB                                      6
#define FWDMA_REQ_MSG_QW0__DSTFIFO__WIDTH                                    4
#define FWDMA_REQ_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define FWDMA_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW0__CNT
#define FWDMA_REQ_MSG_QW0__CNT__MSB                                          5
#define FWDMA_REQ_MSG_QW0__CNT__LSB                                          0
#define FWDMA_REQ_MSG_QW0__CNT__WIDTH                                        6
#define FWDMA_REQ_MSG_QW0__CNT__MASK                                      0x3f
#define FWDMA_REQ_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:FWDMA_REQ_MSG_QW1
typedef union {
  struct {
    u64 cbuf_addr  : 26;
    u64 bcnt       : 13;
    u64 rsvd0      : 4;
    u64 queue_idx  : 10;
    u64 coalesc_en : 1;
    u64 mrw_commit : 1;
    u64 tph_en     : 1;
    u64 tph_val    : 8;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FWDMA_REQ_MSG_QW1;
//-----MACRO defines for Message:FWDMA_REQ_MSG_QW1

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__TPH_VAL
#define FWDMA_REQ_MSG_QW1__TPH_VAL__MSB                                     63
#define FWDMA_REQ_MSG_QW1__TPH_VAL__LSB                                     56
#define FWDMA_REQ_MSG_QW1__TPH_VAL__WIDTH                                    8
#define FWDMA_REQ_MSG_QW1__TPH_VAL__MASK                    0xff00000000000000
#define FWDMA_REQ_MSG_QW1__TPH_VAL__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__TPH_EN
#define FWDMA_REQ_MSG_QW1__TPH_EN__MSB                                      55
#define FWDMA_REQ_MSG_QW1__TPH_EN__LSB                                      55
#define FWDMA_REQ_MSG_QW1__TPH_EN__WIDTH                                     1
#define FWDMA_REQ_MSG_QW1__TPH_EN__MASK                       0x80000000000000
#define FWDMA_REQ_MSG_QW1__TPH_EN__RESET_VALUE                             0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__MRW_COMMIT
#define FWDMA_REQ_MSG_QW1__MRW_COMMIT__MSB                                  54
#define FWDMA_REQ_MSG_QW1__MRW_COMMIT__LSB                                  54
#define FWDMA_REQ_MSG_QW1__MRW_COMMIT__WIDTH                                 1
#define FWDMA_REQ_MSG_QW1__MRW_COMMIT__MASK                   0x40000000000000
#define FWDMA_REQ_MSG_QW1__MRW_COMMIT__RESET_VALUE                         0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__COALESC_EN
#define FWDMA_REQ_MSG_QW1__COALESC_EN__MSB                                  53
#define FWDMA_REQ_MSG_QW1__COALESC_EN__LSB                                  53
#define FWDMA_REQ_MSG_QW1__COALESC_EN__WIDTH                                 1
#define FWDMA_REQ_MSG_QW1__COALESC_EN__MASK                   0x20000000000000
#define FWDMA_REQ_MSG_QW1__COALESC_EN__RESET_VALUE                         0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__QUEUE_IDX
#define FWDMA_REQ_MSG_QW1__QUEUE_IDX__MSB                                   52
#define FWDMA_REQ_MSG_QW1__QUEUE_IDX__LSB                                   43
#define FWDMA_REQ_MSG_QW1__QUEUE_IDX__WIDTH                                 10
#define FWDMA_REQ_MSG_QW1__QUEUE_IDX__MASK                    0x1ff80000000000
#define FWDMA_REQ_MSG_QW1__QUEUE_IDX__RESET_VALUE                          0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__BCNT
#define FWDMA_REQ_MSG_QW1__BCNT__MSB                                        38
#define FWDMA_REQ_MSG_QW1__BCNT__LSB                                        26
#define FWDMA_REQ_MSG_QW1__BCNT__WIDTH                                      13
#define FWDMA_REQ_MSG_QW1__BCNT__MASK                             0x7ffc000000
#define FWDMA_REQ_MSG_QW1__BCNT__RESET_VALUE                               0x0

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW1__CBUF_ADDR
#define FWDMA_REQ_MSG_QW1__CBUF_ADDR__MSB                                   25
#define FWDMA_REQ_MSG_QW1__CBUF_ADDR__LSB                                    0
#define FWDMA_REQ_MSG_QW1__CBUF_ADDR__WIDTH                                 26
#define FWDMA_REQ_MSG_QW1__CBUF_ADDR__MASK                           0x3ffffff
#define FWDMA_REQ_MSG_QW1__CBUF_ADDR__RESET_VALUE                          0x0

//-----Access structure typedef for Message:FWDMA_REQ_MSG_QW2
typedef union {
  struct {
    u64 pa    : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FWDMA_REQ_MSG_QW2;
//-----MACRO defines for Message:FWDMA_REQ_MSG_QW2

//-----MACRO defines for fields:FWDMA_REQ_MSG_QW2__PA
#define FWDMA_REQ_MSG_QW2__PA__MSB                                          63
#define FWDMA_REQ_MSG_QW2__PA__LSB                                           0
#define FWDMA_REQ_MSG_QW2__PA__WIDTH                                        64
#define FWDMA_REQ_MSG_QW2__PA__MASK                         0xffffffffffffffff
#define FWDMA_REQ_MSG_QW2__PA__RESET_VALUE                                 0x0

typedef struct {
  FWDMA_REQ_MSG_QW0  qw0;
  FWDMA_REQ_MSG_QW1  qw1;
  FWDMA_REQ_MSG_QW2  qw2;
} FWDMA_REQ_MSG;
//QW_CNT is actual number - 1
#define FWDMA_REQ_MSG_QW_CNT                                                 2
//-----MACRO defines for  Message Group FWDMA_RSP_MSG: 0xb0000
#define FWDMA_RSP_MSG_MSG_ID                                               0xb
//-----Access structure typedef for Message:FWDMA_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FWDMA_RSP_MSG_QW0;
//-----MACRO defines for Message:FWDMA_RSP_MSG_QW0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__STA
#define FWDMA_RSP_MSG_QW0__STA__MSB                                         63
#define FWDMA_RSP_MSG_QW0__STA__LSB                                         60
#define FWDMA_RSP_MSG_QW0__STA__WIDTH                                        4
#define FWDMA_RSP_MSG_QW0__STA__MASK                        0xf000000000000000
#define FWDMA_RSP_MSG_QW0__STA__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__MSG_ID
#define FWDMA_RSP_MSG_QW0__MSG_ID__MSB                                      31
#define FWDMA_RSP_MSG_QW0__MSG_ID__LSB                                      24
#define FWDMA_RSP_MSG_QW0__MSG_ID__WIDTH                                     8
#define FWDMA_RSP_MSG_QW0__MSG_ID__MASK                             0xff000000
#define FWDMA_RSP_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__REQ_TAG
#define FWDMA_RSP_MSG_QW0__REQ_TAG__MSB                                     23
#define FWDMA_RSP_MSG_QW0__REQ_TAG__LSB                                     16
#define FWDMA_RSP_MSG_QW0__REQ_TAG__WIDTH                                    8
#define FWDMA_RSP_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define FWDMA_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__SRC
#define FWDMA_RSP_MSG_QW0__SRC__MSB                                         15
#define FWDMA_RSP_MSG_QW0__SRC__LSB                                         12
#define FWDMA_RSP_MSG_QW0__SRC__WIDTH                                        4
#define FWDMA_RSP_MSG_QW0__SRC__MASK                                    0xf000
#define FWDMA_RSP_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__DST
#define FWDMA_RSP_MSG_QW0__DST__MSB                                         11
#define FWDMA_RSP_MSG_QW0__DST__LSB                                         10
#define FWDMA_RSP_MSG_QW0__DST__WIDTH                                        2
#define FWDMA_RSP_MSG_QW0__DST__MASK                                     0xc00
#define FWDMA_RSP_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__DSTFIFO
#define FWDMA_RSP_MSG_QW0__DSTFIFO__MSB                                      9
#define FWDMA_RSP_MSG_QW0__DSTFIFO__LSB                                      6
#define FWDMA_RSP_MSG_QW0__DSTFIFO__WIDTH                                    4
#define FWDMA_RSP_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define FWDMA_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:FWDMA_RSP_MSG_QW0__CNT
#define FWDMA_RSP_MSG_QW0__CNT__MSB                                          5
#define FWDMA_RSP_MSG_QW0__CNT__LSB                                          0
#define FWDMA_RSP_MSG_QW0__CNT__WIDTH                                        6
#define FWDMA_RSP_MSG_QW0__CNT__MASK                                      0x3f
#define FWDMA_RSP_MSG_QW0__CNT__RESET_VALUE                                0x0

typedef struct {
  FWDMA_RSP_MSG_QW0  qw0;
} FWDMA_RSP_MSG;
//QW_CNT is actual number - 1
#define FWDMA_RSP_MSG_QW_CNT                                                 0
//-----MACRO defines for  Message Group SQE_REQ_MSG: 0xc0000
#define SQE_REQ_MSG_MSG_ID                                                 0xc
//-----Access structure typedef for Message:SQE_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_REQ_MSG_QW0;
//-----MACRO defines for Message:SQE_REQ_MSG_QW0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__FPM
#define SQE_REQ_MSG_QW0__FPM__MSB                                           58
#define SQE_REQ_MSG_QW0__FPM__LSB                                           49
#define SQE_REQ_MSG_QW0__FPM__WIDTH                                         10
#define SQE_REQ_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define SQE_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__QPN
#define SQE_REQ_MSG_QW0__QPN__MSB                                           48
#define SQE_REQ_MSG_QW0__QPN__LSB                                           32
#define SQE_REQ_MSG_QW0__QPN__WIDTH                                         17
#define SQE_REQ_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define SQE_REQ_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__MSG_ID
#define SQE_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define SQE_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define SQE_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define SQE_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define SQE_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__REQ_TAG
#define SQE_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define SQE_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define SQE_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define SQE_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define SQE_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__SRC
#define SQE_REQ_MSG_QW0__SRC__MSB                                           15
#define SQE_REQ_MSG_QW0__SRC__LSB                                           12
#define SQE_REQ_MSG_QW0__SRC__WIDTH                                          4
#define SQE_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define SQE_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__DST
#define SQE_REQ_MSG_QW0__DST__MSB                                           11
#define SQE_REQ_MSG_QW0__DST__LSB                                           10
#define SQE_REQ_MSG_QW0__DST__WIDTH                                          2
#define SQE_REQ_MSG_QW0__DST__MASK                                       0xc00
#define SQE_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__DSTFIFO
#define SQE_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define SQE_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define SQE_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define SQE_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define SQE_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW0__CNT
#define SQE_REQ_MSG_QW0__CNT__MSB                                            5
#define SQE_REQ_MSG_QW0__CNT__LSB                                            0
#define SQE_REQ_MSG_QW0__CNT__WIDTH                                          6
#define SQE_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define SQE_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:SQE_REQ_MSG_QW1
typedef union {
  struct {
    u64 wqe_idx        : 16;
    u64 wqe_len        : 5;
    u64 sqcqe_obj_addr : 24;
    u64 rsvd0          : 19;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_REQ_MSG_QW1;
//-----MACRO defines for Message:SQE_REQ_MSG_QW1

//-----MACRO defines for fields:SQE_REQ_MSG_QW1__WQE_LEN
#define SQE_REQ_MSG_QW1__WQE_LEN__MSB                                       20
#define SQE_REQ_MSG_QW1__WQE_LEN__LSB                                       16
#define SQE_REQ_MSG_QW1__WQE_LEN__WIDTH                                      5
#define SQE_REQ_MSG_QW1__WQE_LEN__MASK                                0x1f0000
#define SQE_REQ_MSG_QW1__WQE_LEN__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW1__WQE_IDX
#define SQE_REQ_MSG_QW1__WQE_IDX__MSB                                       15
#define SQE_REQ_MSG_QW1__WQE_IDX__LSB                                        0
#define SQE_REQ_MSG_QW1__WQE_IDX__WIDTH                                     16
#define SQE_REQ_MSG_QW1__WQE_IDX__MASK                                  0xffff
#define SQE_REQ_MSG_QW1__WQE_IDX__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR
#define SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__MSB                                44
#define SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__LSB                                21
#define SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__WIDTH                              24
#define SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__MASK                   0x1fffffe00000
#define SQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__RESET_VALUE                       0x0

typedef struct {
  SQE_REQ_MSG_QW0  qw0;
  SQE_REQ_MSG_QW1  qw1;
} SQE_REQ_MSG;
//QW_CNT is actual number - 1
#define SQE_REQ_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group SQE_RSP_MSG: 0xd0000
#define SQE_RSP_MSG_MSG_ID                                                 0xd
//-----Access structure typedef for Message:SQE_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 cqp     : 1;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_RSP_MSG_QW0;
//-----MACRO defines for Message:SQE_RSP_MSG_QW0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__STA
#define SQE_RSP_MSG_QW0__STA__MSB                                           63
#define SQE_RSP_MSG_QW0__STA__LSB                                           60
#define SQE_RSP_MSG_QW0__STA__WIDTH                                          4
#define SQE_RSP_MSG_QW0__STA__MASK                          0xf000000000000000
#define SQE_RSP_MSG_QW0__STA__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__CQP
#define SQE_RSP_MSG_QW0__CQP__MSB                                           59
#define SQE_RSP_MSG_QW0__CQP__LSB                                           59
#define SQE_RSP_MSG_QW0__CQP__WIDTH                                          1
#define SQE_RSP_MSG_QW0__CQP__MASK                           0x800000000000000
#define SQE_RSP_MSG_QW0__CQP__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__FPM
#define SQE_RSP_MSG_QW0__FPM__MSB                                           58
#define SQE_RSP_MSG_QW0__FPM__LSB                                           49
#define SQE_RSP_MSG_QW0__FPM__WIDTH                                         10
#define SQE_RSP_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define SQE_RSP_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__QPN
#define SQE_RSP_MSG_QW0__QPN__MSB                                           48
#define SQE_RSP_MSG_QW0__QPN__LSB                                           32
#define SQE_RSP_MSG_QW0__QPN__WIDTH                                         17
#define SQE_RSP_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define SQE_RSP_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__MSG_ID
#define SQE_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define SQE_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define SQE_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define SQE_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define SQE_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__REQ_TAG
#define SQE_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define SQE_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define SQE_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define SQE_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define SQE_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__SRC
#define SQE_RSP_MSG_QW0__SRC__MSB                                           15
#define SQE_RSP_MSG_QW0__SRC__LSB                                           12
#define SQE_RSP_MSG_QW0__SRC__WIDTH                                          4
#define SQE_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define SQE_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__DST
#define SQE_RSP_MSG_QW0__DST__MSB                                           11
#define SQE_RSP_MSG_QW0__DST__LSB                                           10
#define SQE_RSP_MSG_QW0__DST__WIDTH                                          2
#define SQE_RSP_MSG_QW0__DST__MASK                                       0xc00
#define SQE_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__DSTFIFO
#define SQE_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define SQE_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define SQE_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define SQE_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define SQE_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW0__CNT
#define SQE_RSP_MSG_QW0__CNT__MSB                                            5
#define SQE_RSP_MSG_QW0__CNT__LSB                                            0
#define SQE_RSP_MSG_QW0__CNT__WIDTH                                          6
#define SQE_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define SQE_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:SQE_RSP_MSG_QW1
typedef union {
  struct {
    u64 sqcqe_hmcpageoffset : 5;
    u64 sqcqe_hmcpage       : 19;
    u64 rsvd0               : 14;
    u64 vsi                 : 10;
    u64 wq_desc_index       : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_RSP_MSG_QW1;
//-----MACRO defines for Message:SQE_RSP_MSG_QW1

//-----MACRO defines for fields:SQE_RSP_MSG_QW1__WQ_DESC_INDEX
#define SQE_RSP_MSG_QW1__WQ_DESC_INDEX__MSB                                 63
#define SQE_RSP_MSG_QW1__WQ_DESC_INDEX__LSB                                 48
#define SQE_RSP_MSG_QW1__WQ_DESC_INDEX__WIDTH                               16
#define SQE_RSP_MSG_QW1__WQ_DESC_INDEX__MASK                0xffff000000000000
#define SQE_RSP_MSG_QW1__WQ_DESC_INDEX__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW1__VSI
#define SQE_RSP_MSG_QW1__VSI__MSB                                           47
#define SQE_RSP_MSG_QW1__VSI__LSB                                           38
#define SQE_RSP_MSG_QW1__VSI__WIDTH                                         10
#define SQE_RSP_MSG_QW1__VSI__MASK                              0xffc000000000
#define SQE_RSP_MSG_QW1__VSI__RESET_VALUE                                  0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW1__SQCQE_HMCPAGE
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGE__MSB                                 23
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGE__LSB                                  5
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGE__WIDTH                               19
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGE__MASK                          0xffffe0
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGE__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET__MSB                            4
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET__LSB                            0
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET__WIDTH                          5
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET__MASK                        0x1f
#define SQE_RSP_MSG_QW1__SQCQE_HMCPAGEOFFSET__RESET_VALUE                  0x0

//-----Access structure typedef for Message:SQE_RSP_MSG_QW_DATA
typedef union {
  struct {
    u64 qwe_context : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_RSP_MSG_QW_DATA;
//-----MACRO defines for Message:SQE_RSP_MSG_QW_DATA

//-----MACRO defines for fields:SQE_RSP_MSG_QW_DATA__QWE_CONTEXT
#define SQE_RSP_MSG_QW_DATA__QWE_CONTEXT__MSB                               63
#define SQE_RSP_MSG_QW_DATA__QWE_CONTEXT__LSB                                0
#define SQE_RSP_MSG_QW_DATA__QWE_CONTEXT__WIDTH                             64
#define SQE_RSP_MSG_QW_DATA__QWE_CONTEXT__MASK              0xffffffffffffffff
#define SQE_RSP_MSG_QW_DATA__QWE_CONTEXT__RESET_VALUE                      0x0

typedef struct {
  SQE_RSP_MSG_QW0  qw0;
  SQE_RSP_MSG_QW1  qw1;
  //SQE_RSP_MSG_QW_DATA  qw2;
} SQE_RSP_MSG;
//QW_CNT is actual number - 1
#define SQE_RSP_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group SQE_RETR_MSG: 0xe0000
#define SQE_RETR_MSG_MSG_ID                                                0xe
//-----Access structure typedef for Message:SQE_RETR_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_RETR_MSG_QW0;
//-----MACRO defines for Message:SQE_RETR_MSG_QW0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__FPM
#define SQE_RETR_MSG_QW0__FPM__MSB                                          58
#define SQE_RETR_MSG_QW0__FPM__LSB                                          49
#define SQE_RETR_MSG_QW0__FPM__WIDTH                                        10
#define SQE_RETR_MSG_QW0__FPM__MASK                          0x7fe000000000000
#define SQE_RETR_MSG_QW0__FPM__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__QPN
#define SQE_RETR_MSG_QW0__QPN__MSB                                          48
#define SQE_RETR_MSG_QW0__QPN__LSB                                          32
#define SQE_RETR_MSG_QW0__QPN__WIDTH                                        17
#define SQE_RETR_MSG_QW0__QPN__MASK                            0x1ffff00000000
#define SQE_RETR_MSG_QW0__QPN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__MSG_ID
#define SQE_RETR_MSG_QW0__MSG_ID__MSB                                       31
#define SQE_RETR_MSG_QW0__MSG_ID__LSB                                       24
#define SQE_RETR_MSG_QW0__MSG_ID__WIDTH                                      8
#define SQE_RETR_MSG_QW0__MSG_ID__MASK                              0xff000000
#define SQE_RETR_MSG_QW0__MSG_ID__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__REQ_TAG
#define SQE_RETR_MSG_QW0__REQ_TAG__MSB                                      23
#define SQE_RETR_MSG_QW0__REQ_TAG__LSB                                      16
#define SQE_RETR_MSG_QW0__REQ_TAG__WIDTH                                     8
#define SQE_RETR_MSG_QW0__REQ_TAG__MASK                               0xff0000
#define SQE_RETR_MSG_QW0__REQ_TAG__RESET_VALUE                             0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__SRC
#define SQE_RETR_MSG_QW0__SRC__MSB                                          15
#define SQE_RETR_MSG_QW0__SRC__LSB                                          12
#define SQE_RETR_MSG_QW0__SRC__WIDTH                                         4
#define SQE_RETR_MSG_QW0__SRC__MASK                                     0xf000
#define SQE_RETR_MSG_QW0__SRC__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__DST
#define SQE_RETR_MSG_QW0__DST__MSB                                          11
#define SQE_RETR_MSG_QW0__DST__LSB                                          10
#define SQE_RETR_MSG_QW0__DST__WIDTH                                         2
#define SQE_RETR_MSG_QW0__DST__MASK                                      0xc00
#define SQE_RETR_MSG_QW0__DST__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__DSTFIFO
#define SQE_RETR_MSG_QW0__DSTFIFO__MSB                                       9
#define SQE_RETR_MSG_QW0__DSTFIFO__LSB                                       6
#define SQE_RETR_MSG_QW0__DSTFIFO__WIDTH                                     4
#define SQE_RETR_MSG_QW0__DSTFIFO__MASK                                  0x3c0
#define SQE_RETR_MSG_QW0__DSTFIFO__RESET_VALUE                             0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW0__CNT
#define SQE_RETR_MSG_QW0__CNT__MSB                                           5
#define SQE_RETR_MSG_QW0__CNT__LSB                                           0
#define SQE_RETR_MSG_QW0__CNT__WIDTH                                         6
#define SQE_RETR_MSG_QW0__CNT__MASK                                       0x3f
#define SQE_RETR_MSG_QW0__CNT__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:SQE_RETR_MSG_QW1
typedef union {
  struct {
    u64 wqe_idx  : 16;
    u64 retr_psn : 24;
    u64 psn_ofst : 24;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQE_RETR_MSG_QW1;
//-----MACRO defines for Message:SQE_RETR_MSG_QW1

//-----MACRO defines for fields:SQE_RETR_MSG_QW1__PSN_OFST
#define SQE_RETR_MSG_QW1__PSN_OFST__MSB                                     63
#define SQE_RETR_MSG_QW1__PSN_OFST__LSB                                     40
#define SQE_RETR_MSG_QW1__PSN_OFST__WIDTH                                   24
#define SQE_RETR_MSG_QW1__PSN_OFST__MASK                    0xffffff0000000000
#define SQE_RETR_MSG_QW1__PSN_OFST__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW1__RETR_PSN
#define SQE_RETR_MSG_QW1__RETR_PSN__MSB                                     39
#define SQE_RETR_MSG_QW1__RETR_PSN__LSB                                     16
#define SQE_RETR_MSG_QW1__RETR_PSN__WIDTH                                   24
#define SQE_RETR_MSG_QW1__RETR_PSN__MASK                          0xffffff0000
#define SQE_RETR_MSG_QW1__RETR_PSN__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQE_RETR_MSG_QW1__WQE_IDX
#define SQE_RETR_MSG_QW1__WQE_IDX__MSB                                      15
#define SQE_RETR_MSG_QW1__WQE_IDX__LSB                                       0
#define SQE_RETR_MSG_QW1__WQE_IDX__WIDTH                                    16
#define SQE_RETR_MSG_QW1__WQE_IDX__MASK                                 0xffff
#define SQE_RETR_MSG_QW1__WQE_IDX__RESET_VALUE                             0x0

typedef struct {
  SQE_RETR_MSG_QW0  qw0;
  SQE_RETR_MSG_QW1  qw1;
} SQE_RETR_MSG;
//QW_CNT is actual number - 1
#define SQE_RETR_MSG_QW_CNT                                                  1
//-----MACRO defines for  Message Group RQCQE_REQ_MSG: 0xf0000
#define RQCQE_REQ_MSG_MSG_ID                                               0xf
//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt      : 6;
    u64 dstfifo  : 4;
    u64 dst      : 2;
    u64 src      : 4;
    u64 req_tag  : 8;
    u64 msg_id   : 8;
    u64 qpn      : 17;
    u64 fpm      : 10;
    u64 qp_type  : 3;
    u64 acked    : 1;
    u64 need_rsp : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW0;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__NEED_RSP
#define RQCQE_REQ_MSG_QW0__NEED_RSP__MSB                                    63
#define RQCQE_REQ_MSG_QW0__NEED_RSP__LSB                                    63
#define RQCQE_REQ_MSG_QW0__NEED_RSP__WIDTH                                   1
#define RQCQE_REQ_MSG_QW0__NEED_RSP__MASK                   0x8000000000000000
#define RQCQE_REQ_MSG_QW0__NEED_RSP__RESET_VALUE                           0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__ACKED
#define RQCQE_REQ_MSG_QW0__ACKED__MSB                                       62
#define RQCQE_REQ_MSG_QW0__ACKED__LSB                                       62
#define RQCQE_REQ_MSG_QW0__ACKED__WIDTH                                      1
#define RQCQE_REQ_MSG_QW0__ACKED__MASK                      0x4000000000000000
#define RQCQE_REQ_MSG_QW0__ACKED__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__QP_TYPE
#define RQCQE_REQ_MSG_QW0__QP_TYPE__MSB                                     61
#define RQCQE_REQ_MSG_QW0__QP_TYPE__LSB                                     59
#define RQCQE_REQ_MSG_QW0__QP_TYPE__WIDTH                                    3
#define RQCQE_REQ_MSG_QW0__QP_TYPE__MASK                    0x3800000000000000
#define RQCQE_REQ_MSG_QW0__QP_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__FPM
#define RQCQE_REQ_MSG_QW0__FPM__MSB                                         58
#define RQCQE_REQ_MSG_QW0__FPM__LSB                                         49
#define RQCQE_REQ_MSG_QW0__FPM__WIDTH                                       10
#define RQCQE_REQ_MSG_QW0__FPM__MASK                         0x7fe000000000000
#define RQCQE_REQ_MSG_QW0__FPM__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__QPN
#define RQCQE_REQ_MSG_QW0__QPN__MSB                                         48
#define RQCQE_REQ_MSG_QW0__QPN__LSB                                         32
#define RQCQE_REQ_MSG_QW0__QPN__WIDTH                                       17
#define RQCQE_REQ_MSG_QW0__QPN__MASK                           0x1ffff00000000
#define RQCQE_REQ_MSG_QW0__QPN__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__MSG_ID
#define RQCQE_REQ_MSG_QW0__MSG_ID__MSB                                      31
#define RQCQE_REQ_MSG_QW0__MSG_ID__LSB                                      24
#define RQCQE_REQ_MSG_QW0__MSG_ID__WIDTH                                     8
#define RQCQE_REQ_MSG_QW0__MSG_ID__MASK                             0xff000000
#define RQCQE_REQ_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__REQ_TAG
#define RQCQE_REQ_MSG_QW0__REQ_TAG__MSB                                     23
#define RQCQE_REQ_MSG_QW0__REQ_TAG__LSB                                     16
#define RQCQE_REQ_MSG_QW0__REQ_TAG__WIDTH                                    8
#define RQCQE_REQ_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define RQCQE_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__SRC
#define RQCQE_REQ_MSG_QW0__SRC__MSB                                         15
#define RQCQE_REQ_MSG_QW0__SRC__LSB                                         12
#define RQCQE_REQ_MSG_QW0__SRC__WIDTH                                        4
#define RQCQE_REQ_MSG_QW0__SRC__MASK                                    0xf000
#define RQCQE_REQ_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__DST
#define RQCQE_REQ_MSG_QW0__DST__MSB                                         11
#define RQCQE_REQ_MSG_QW0__DST__LSB                                         10
#define RQCQE_REQ_MSG_QW0__DST__WIDTH                                        2
#define RQCQE_REQ_MSG_QW0__DST__MASK                                     0xc00
#define RQCQE_REQ_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__DSTFIFO
#define RQCQE_REQ_MSG_QW0__DSTFIFO__MSB                                      9
#define RQCQE_REQ_MSG_QW0__DSTFIFO__LSB                                      6
#define RQCQE_REQ_MSG_QW0__DSTFIFO__WIDTH                                    4
#define RQCQE_REQ_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define RQCQE_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW0__CNT
#define RQCQE_REQ_MSG_QW0__CNT__MSB                                          5
#define RQCQE_REQ_MSG_QW0__CNT__LSB                                          0
#define RQCQE_REQ_MSG_QW0__CNT__WIDTH                                        6
#define RQCQE_REQ_MSG_QW0__CNT__MASK                                      0x3f
#define RQCQE_REQ_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW1
typedef union {
  struct {
    u64 psn   : 24;
    u64 rsvd0 : 22;
    u64 cqn   : 18;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW1;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW1

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW1__CQN
#define RQCQE_REQ_MSG_QW1__CQN__MSB                                         63
#define RQCQE_REQ_MSG_QW1__CQN__LSB                                         46
#define RQCQE_REQ_MSG_QW1__CQN__WIDTH                                       18
#define RQCQE_REQ_MSG_QW1__CQN__MASK                        0xffffc00000000000
#define RQCQE_REQ_MSG_QW1__CQN__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW1__PSN
#define RQCQE_REQ_MSG_QW1__PSN__MSB                                         23
#define RQCQE_REQ_MSG_QW1__PSN__LSB                                          0
#define RQCQE_REQ_MSG_QW1__PSN__WIDTH                                       24
#define RQCQE_REQ_MSG_QW1__PSN__MASK                                  0xffffff
#define RQCQE_REQ_MSG_QW1__PSN__RESET_VALUE                                0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW2
typedef union {
  struct {
    u64 inv_rkey_or_ud_src_qpn : 32;
    u64 pyld_len               : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW2;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW2

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW2__PYLD_LEN
#define RQCQE_REQ_MSG_QW2__PYLD_LEN__MSB                                    63
#define RQCQE_REQ_MSG_QW2__PYLD_LEN__LSB                                    32
#define RQCQE_REQ_MSG_QW2__PYLD_LEN__WIDTH                                  32
#define RQCQE_REQ_MSG_QW2__PYLD_LEN__MASK                   0xffffffff00000000
#define RQCQE_REQ_MSG_QW2__PYLD_LEN__RESET_VALUE                           0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN
#define RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN__MSB                      31
#define RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN__LSB                       0
#define RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN__WIDTH                    32
#define RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN__MASK             0xffffffff
#define RQCQE_REQ_MSG_QW2__INV_RKEY_OR_UD_SRC_QPN__RESET_VALUE             0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW3
typedef union {
  struct {
    u64 minor_error_code : 16;
    u64 major_error_code : 16;
    u64 wq_desc_index    : 15;
    u64 rsvd0            : 3;
    u64 extended_cqe     : 1;
    u64 rsvd1            : 2;
    u64 rc_key_ud_ipv4   : 1;
    u64 se               : 1;
    u64 error            : 1;
    u64 rsvd2            : 7;
    u64 cqe_vld          : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW3;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW3

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__CQE_VLD
#define RQCQE_REQ_MSG_QW3__CQE_VLD__MSB                                     63
#define RQCQE_REQ_MSG_QW3__CQE_VLD__LSB                                     63
#define RQCQE_REQ_MSG_QW3__CQE_VLD__WIDTH                                    1
#define RQCQE_REQ_MSG_QW3__CQE_VLD__MASK                    0x8000000000000000
#define RQCQE_REQ_MSG_QW3__CQE_VLD__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__ERROR
#define RQCQE_REQ_MSG_QW3__ERROR__MSB                                       55
#define RQCQE_REQ_MSG_QW3__ERROR__LSB                                       55
#define RQCQE_REQ_MSG_QW3__ERROR__WIDTH                                      1
#define RQCQE_REQ_MSG_QW3__ERROR__MASK                        0x80000000000000
#define RQCQE_REQ_MSG_QW3__ERROR__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__SE
#define RQCQE_REQ_MSG_QW3__SE__MSB                                          54
#define RQCQE_REQ_MSG_QW3__SE__LSB                                          54
#define RQCQE_REQ_MSG_QW3__SE__WIDTH                                         1
#define RQCQE_REQ_MSG_QW3__SE__MASK                           0x40000000000000
#define RQCQE_REQ_MSG_QW3__SE__RESET_VALUE                                 0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4
#define RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4__MSB                              53
#define RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4__LSB                              53
#define RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4__WIDTH                             1
#define RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4__MASK               0x20000000000000
#define RQCQE_REQ_MSG_QW3__RC_KEY_UD_IPV4__RESET_VALUE                     0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__EXTENDED_CQE
#define RQCQE_REQ_MSG_QW3__EXTENDED_CQE__MSB                                50
#define RQCQE_REQ_MSG_QW3__EXTENDED_CQE__LSB                                50
#define RQCQE_REQ_MSG_QW3__EXTENDED_CQE__WIDTH                               1
#define RQCQE_REQ_MSG_QW3__EXTENDED_CQE__MASK                  0x4000000000000
#define RQCQE_REQ_MSG_QW3__EXTENDED_CQE__RESET_VALUE                       0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX
#define RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX__MSB                               46
#define RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX__LSB                               32
#define RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX__WIDTH                             15
#define RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX__MASK                  0x7fff00000000
#define RQCQE_REQ_MSG_QW3__WQ_DESC_INDEX__RESET_VALUE                      0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE
#define RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__MSB                            31
#define RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__LSB                            16
#define RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__WIDTH                          16
#define RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__MASK                   0xffff0000
#define RQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__RESET_VALUE                   0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE
#define RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__MSB                            15
#define RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__LSB                             0
#define RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__WIDTH                          16
#define RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__MASK                       0xffff
#define RQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__RESET_VALUE                   0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW4
typedef union {
  struct {
    u64 imm_data : 32;
    u64 rsvd0    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW4;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW4

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW4__IMM_DATA
#define RQCQE_REQ_MSG_QW4__IMM_DATA__MSB                                    31
#define RQCQE_REQ_MSG_QW4__IMM_DATA__LSB                                     0
#define RQCQE_REQ_MSG_QW4__IMM_DATA__WIDTH                                  32
#define RQCQE_REQ_MSG_QW4__IMM_DATA__MASK                           0xffffffff
#define RQCQE_REQ_MSG_QW4__IMM_DATA__RESET_VALUE                           0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW5
typedef union {
  struct {
    u64 noused : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW5;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW5

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW5__NOUSED
#define RQCQE_REQ_MSG_QW5__NOUSED__MSB                                      63
#define RQCQE_REQ_MSG_QW5__NOUSED__LSB                                       0
#define RQCQE_REQ_MSG_QW5__NOUSED__WIDTH                                    64
#define RQCQE_REQ_MSG_QW5__NOUSED__MASK                     0xffffffffffffffff
#define RQCQE_REQ_MSG_QW5__NOUSED__RESET_VALUE                             0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW6
typedef union {
  struct {
    u64 ud_smac     : 48;
    u64 ud_vlan_tag : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW6;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW6

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW6__UD_VLAN_TAG
#define RQCQE_REQ_MSG_QW6__UD_VLAN_TAG__MSB                                 63
#define RQCQE_REQ_MSG_QW6__UD_VLAN_TAG__LSB                                 48
#define RQCQE_REQ_MSG_QW6__UD_VLAN_TAG__WIDTH                               16
#define RQCQE_REQ_MSG_QW6__UD_VLAN_TAG__MASK                0xffff000000000000
#define RQCQE_REQ_MSG_QW6__UD_VLAN_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW6__UD_SMAC
#define RQCQE_REQ_MSG_QW6__UD_SMAC__MSB                                     47
#define RQCQE_REQ_MSG_QW6__UD_SMAC__LSB                                      0
#define RQCQE_REQ_MSG_QW6__UD_SMAC__WIDTH                                   48
#define RQCQE_REQ_MSG_QW6__UD_SMAC__MASK                        0xffffffffffff
#define RQCQE_REQ_MSG_QW6__UD_SMAC__RESET_VALUE                            0x0

//-----Access structure typedef for Message:RQCQE_REQ_MSG_QW7
typedef union {
  struct {
    u64 rsvd0           : 60;
    u64 ud_vlan_tag_vld : 1;
    u64 ud_mac_vld      : 1;
    u64 imm_data_vld    : 1;
    u64 extcqe_vld      : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_MSG_QW7;
//-----MACRO defines for Message:RQCQE_REQ_MSG_QW7

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW7__EXTCQE_VLD
#define RQCQE_REQ_MSG_QW7__EXTCQE_VLD__MSB                                  63
#define RQCQE_REQ_MSG_QW7__EXTCQE_VLD__LSB                                  63
#define RQCQE_REQ_MSG_QW7__EXTCQE_VLD__WIDTH                                 1
#define RQCQE_REQ_MSG_QW7__EXTCQE_VLD__MASK                 0x8000000000000000
#define RQCQE_REQ_MSG_QW7__EXTCQE_VLD__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW7__IMM_DATA_VLD
#define RQCQE_REQ_MSG_QW7__IMM_DATA_VLD__MSB                                62
#define RQCQE_REQ_MSG_QW7__IMM_DATA_VLD__LSB                                62
#define RQCQE_REQ_MSG_QW7__IMM_DATA_VLD__WIDTH                               1
#define RQCQE_REQ_MSG_QW7__IMM_DATA_VLD__MASK               0x4000000000000000
#define RQCQE_REQ_MSG_QW7__IMM_DATA_VLD__RESET_VALUE                       0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW7__UD_MAC_VLD
#define RQCQE_REQ_MSG_QW7__UD_MAC_VLD__MSB                                  61
#define RQCQE_REQ_MSG_QW7__UD_MAC_VLD__LSB                                  61
#define RQCQE_REQ_MSG_QW7__UD_MAC_VLD__WIDTH                                 1
#define RQCQE_REQ_MSG_QW7__UD_MAC_VLD__MASK                 0x2000000000000000
#define RQCQE_REQ_MSG_QW7__UD_MAC_VLD__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD
#define RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD__MSB                             60
#define RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD__LSB                             60
#define RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD__WIDTH                            1
#define RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD__MASK            0x1000000000000000
#define RQCQE_REQ_MSG_QW7__UD_VLAN_TAG_VLD__RESET_VALUE                    0x0

typedef struct {
  RQCQE_REQ_MSG_QW0  qw0;
  RQCQE_REQ_MSG_QW1  qw1;
  RQCQE_REQ_MSG_QW2  qw2;
  RQCQE_REQ_MSG_QW3  qw3;
  RQCQE_REQ_MSG_QW4  qw4;
  RQCQE_REQ_MSG_QW5  qw5;
  RQCQE_REQ_MSG_QW6  qw6;
  RQCQE_REQ_MSG_QW7  qw7;
} RQCQE_REQ_MSG;
//QW_CNT is actual number - 1
#define RQCQE_REQ_MSG_QW_CNT                                                 7
//-----MACRO defines for  Message Group RQCQE_REQ_RSP_MSG: 0x100000
#define RQCQE_REQ_RSP_MSG_MSG_ID                                          0x10
//-----Access structure typedef for Message:RQCQE_REQ_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_REQ_RSP_MSG_QW0;
//-----MACRO defines for Message:RQCQE_REQ_RSP_MSG_QW0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__MSG_ID
#define RQCQE_REQ_RSP_MSG_QW0__MSG_ID__MSB                                  31
#define RQCQE_REQ_RSP_MSG_QW0__MSG_ID__LSB                                  24
#define RQCQE_REQ_RSP_MSG_QW0__MSG_ID__WIDTH                                 8
#define RQCQE_REQ_RSP_MSG_QW0__MSG_ID__MASK                         0xff000000
#define RQCQE_REQ_RSP_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__REQ_TAG
#define RQCQE_REQ_RSP_MSG_QW0__REQ_TAG__MSB                                 23
#define RQCQE_REQ_RSP_MSG_QW0__REQ_TAG__LSB                                 16
#define RQCQE_REQ_RSP_MSG_QW0__REQ_TAG__WIDTH                                8
#define RQCQE_REQ_RSP_MSG_QW0__REQ_TAG__MASK                          0xff0000
#define RQCQE_REQ_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__SRC
#define RQCQE_REQ_RSP_MSG_QW0__SRC__MSB                                     15
#define RQCQE_REQ_RSP_MSG_QW0__SRC__LSB                                     12
#define RQCQE_REQ_RSP_MSG_QW0__SRC__WIDTH                                    4
#define RQCQE_REQ_RSP_MSG_QW0__SRC__MASK                                0xf000
#define RQCQE_REQ_RSP_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__DST
#define RQCQE_REQ_RSP_MSG_QW0__DST__MSB                                     11
#define RQCQE_REQ_RSP_MSG_QW0__DST__LSB                                     10
#define RQCQE_REQ_RSP_MSG_QW0__DST__WIDTH                                    2
#define RQCQE_REQ_RSP_MSG_QW0__DST__MASK                                 0xc00
#define RQCQE_REQ_RSP_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__DSTFIFO
#define RQCQE_REQ_RSP_MSG_QW0__DSTFIFO__MSB                                  9
#define RQCQE_REQ_RSP_MSG_QW0__DSTFIFO__LSB                                  6
#define RQCQE_REQ_RSP_MSG_QW0__DSTFIFO__WIDTH                                4
#define RQCQE_REQ_RSP_MSG_QW0__DSTFIFO__MASK                             0x3c0
#define RQCQE_REQ_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:RQCQE_REQ_RSP_MSG_QW0__CNT
#define RQCQE_REQ_RSP_MSG_QW0__CNT__MSB                                      5
#define RQCQE_REQ_RSP_MSG_QW0__CNT__LSB                                      0
#define RQCQE_REQ_RSP_MSG_QW0__CNT__WIDTH                                    6
#define RQCQE_REQ_RSP_MSG_QW0__CNT__MASK                                  0x3f
#define RQCQE_REQ_RSP_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  RQCQE_REQ_RSP_MSG_QW0  qw0;
} RQCQE_REQ_RSP_MSG;
//QW_CNT is actual number - 1
#define RQCQE_REQ_RSP_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group RQCQE_CPL_MSG: 0x110000
#define RQCQE_CPL_MSG_MSG_ID                                              0x11
//-----Access structure typedef for Message:RQCQE_CPL_MSG_QW0
typedef union {
  struct {
    u64 cnt          : 6;
    u64 dstfifo      : 4;
    u64 dst          : 2;
    u64 src          : 4;
    u64 req_tag      : 8;
    u64 msg_id       : 8;
    u64 qpn          : 17;
    u64 fpm          : 10;
    u64 flush_type   : 2;
    u64 flush        : 1;
    u64 flush_uncomp : 1;
    u64 need_rsp     : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_CPL_MSG_QW0;
//-----MACRO defines for Message:RQCQE_CPL_MSG_QW0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__NEED_RSP
#define RQCQE_CPL_MSG_QW0__NEED_RSP__MSB                                    63
#define RQCQE_CPL_MSG_QW0__NEED_RSP__LSB                                    63
#define RQCQE_CPL_MSG_QW0__NEED_RSP__WIDTH                                   1
#define RQCQE_CPL_MSG_QW0__NEED_RSP__MASK                   0x8000000000000000
#define RQCQE_CPL_MSG_QW0__NEED_RSP__RESET_VALUE                           0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP
#define RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__MSB                                62
#define RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__LSB                                62
#define RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__WIDTH                               1
#define RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__MASK               0x4000000000000000
#define RQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__RESET_VALUE                       0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__FLUSH
#define RQCQE_CPL_MSG_QW0__FLUSH__MSB                                       61
#define RQCQE_CPL_MSG_QW0__FLUSH__LSB                                       61
#define RQCQE_CPL_MSG_QW0__FLUSH__WIDTH                                      1
#define RQCQE_CPL_MSG_QW0__FLUSH__MASK                      0x2000000000000000
#define RQCQE_CPL_MSG_QW0__FLUSH__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__FLUSH_TYPE
#define RQCQE_CPL_MSG_QW0__FLUSH_TYPE__MSB                                  60
#define RQCQE_CPL_MSG_QW0__FLUSH_TYPE__LSB                                  59
#define RQCQE_CPL_MSG_QW0__FLUSH_TYPE__WIDTH                                 2
#define RQCQE_CPL_MSG_QW0__FLUSH_TYPE__MASK                 0x1800000000000000
#define RQCQE_CPL_MSG_QW0__FLUSH_TYPE__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__FPM
#define RQCQE_CPL_MSG_QW0__FPM__MSB                                         58
#define RQCQE_CPL_MSG_QW0__FPM__LSB                                         49
#define RQCQE_CPL_MSG_QW0__FPM__WIDTH                                       10
#define RQCQE_CPL_MSG_QW0__FPM__MASK                         0x7fe000000000000
#define RQCQE_CPL_MSG_QW0__FPM__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__QPN
#define RQCQE_CPL_MSG_QW0__QPN__MSB                                         48
#define RQCQE_CPL_MSG_QW0__QPN__LSB                                         32
#define RQCQE_CPL_MSG_QW0__QPN__WIDTH                                       17
#define RQCQE_CPL_MSG_QW0__QPN__MASK                           0x1ffff00000000
#define RQCQE_CPL_MSG_QW0__QPN__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__MSG_ID
#define RQCQE_CPL_MSG_QW0__MSG_ID__MSB                                      31
#define RQCQE_CPL_MSG_QW0__MSG_ID__LSB                                      24
#define RQCQE_CPL_MSG_QW0__MSG_ID__WIDTH                                     8
#define RQCQE_CPL_MSG_QW0__MSG_ID__MASK                             0xff000000
#define RQCQE_CPL_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__REQ_TAG
#define RQCQE_CPL_MSG_QW0__REQ_TAG__MSB                                     23
#define RQCQE_CPL_MSG_QW0__REQ_TAG__LSB                                     16
#define RQCQE_CPL_MSG_QW0__REQ_TAG__WIDTH                                    8
#define RQCQE_CPL_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define RQCQE_CPL_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__SRC
#define RQCQE_CPL_MSG_QW0__SRC__MSB                                         15
#define RQCQE_CPL_MSG_QW0__SRC__LSB                                         12
#define RQCQE_CPL_MSG_QW0__SRC__WIDTH                                        4
#define RQCQE_CPL_MSG_QW0__SRC__MASK                                    0xf000
#define RQCQE_CPL_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__DST
#define RQCQE_CPL_MSG_QW0__DST__MSB                                         11
#define RQCQE_CPL_MSG_QW0__DST__LSB                                         10
#define RQCQE_CPL_MSG_QW0__DST__WIDTH                                        2
#define RQCQE_CPL_MSG_QW0__DST__MASK                                     0xc00
#define RQCQE_CPL_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__DSTFIFO
#define RQCQE_CPL_MSG_QW0__DSTFIFO__MSB                                      9
#define RQCQE_CPL_MSG_QW0__DSTFIFO__LSB                                      6
#define RQCQE_CPL_MSG_QW0__DSTFIFO__WIDTH                                    4
#define RQCQE_CPL_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define RQCQE_CPL_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW0__CNT
#define RQCQE_CPL_MSG_QW0__CNT__MSB                                          5
#define RQCQE_CPL_MSG_QW0__CNT__LSB                                          0
#define RQCQE_CPL_MSG_QW0__CNT__WIDTH                                        6
#define RQCQE_CPL_MSG_QW0__CNT__MASK                                      0x3f
#define RQCQE_CPL_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:RQCQE_CPL_MSG_QW1
typedef union {
  struct {
    u64 minor_error_code : 16;
    u64 major_error_code : 16;
    u64 rsvd0            : 14;
    u64 cqn              : 18;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_CPL_MSG_QW1;
//-----MACRO defines for Message:RQCQE_CPL_MSG_QW1

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW1__CQN
#define RQCQE_CPL_MSG_QW1__CQN__MSB                                         63
#define RQCQE_CPL_MSG_QW1__CQN__LSB                                         46
#define RQCQE_CPL_MSG_QW1__CQN__WIDTH                                       18
#define RQCQE_CPL_MSG_QW1__CQN__MASK                        0xffffc00000000000
#define RQCQE_CPL_MSG_QW1__CQN__RESET_VALUE                                0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE
#define RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE__MSB                            31
#define RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE__LSB                            16
#define RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE__WIDTH                          16
#define RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE__MASK                   0xffff0000
#define RQCQE_CPL_MSG_QW1__MAJOR_ERROR_CODE__RESET_VALUE                   0x0

//-----MACRO defines for fields:RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE
#define RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE__MSB                            15
#define RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE__LSB                             0
#define RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE__WIDTH                          16
#define RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE__MASK                       0xffff
#define RQCQE_CPL_MSG_QW1__MINOR_ERROR_CODE__RESET_VALUE                   0x0

typedef struct {
  RQCQE_CPL_MSG_QW0  qw0;
  RQCQE_CPL_MSG_QW1  qw1;
} RQCQE_CPL_MSG;
//QW_CNT is actual number - 1
#define RQCQE_CPL_MSG_QW_CNT                                                 1
//-----MACRO defines for  Message Group RQCQE_CPL_RSP_MSG: 0x120000
#define RQCQE_CPL_RSP_MSG_MSG_ID                                          0x12
//-----Access structure typedef for Message:RQCQE_CPL_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQCQE_CPL_RSP_MSG_QW0;
//-----MACRO defines for Message:RQCQE_CPL_RSP_MSG_QW0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__MSG_ID
#define RQCQE_CPL_RSP_MSG_QW0__MSG_ID__MSB                                  31
#define RQCQE_CPL_RSP_MSG_QW0__MSG_ID__LSB                                  24
#define RQCQE_CPL_RSP_MSG_QW0__MSG_ID__WIDTH                                 8
#define RQCQE_CPL_RSP_MSG_QW0__MSG_ID__MASK                         0xff000000
#define RQCQE_CPL_RSP_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__REQ_TAG
#define RQCQE_CPL_RSP_MSG_QW0__REQ_TAG__MSB                                 23
#define RQCQE_CPL_RSP_MSG_QW0__REQ_TAG__LSB                                 16
#define RQCQE_CPL_RSP_MSG_QW0__REQ_TAG__WIDTH                                8
#define RQCQE_CPL_RSP_MSG_QW0__REQ_TAG__MASK                          0xff0000
#define RQCQE_CPL_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__SRC
#define RQCQE_CPL_RSP_MSG_QW0__SRC__MSB                                     15
#define RQCQE_CPL_RSP_MSG_QW0__SRC__LSB                                     12
#define RQCQE_CPL_RSP_MSG_QW0__SRC__WIDTH                                    4
#define RQCQE_CPL_RSP_MSG_QW0__SRC__MASK                                0xf000
#define RQCQE_CPL_RSP_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__DST
#define RQCQE_CPL_RSP_MSG_QW0__DST__MSB                                     11
#define RQCQE_CPL_RSP_MSG_QW0__DST__LSB                                     10
#define RQCQE_CPL_RSP_MSG_QW0__DST__WIDTH                                    2
#define RQCQE_CPL_RSP_MSG_QW0__DST__MASK                                 0xc00
#define RQCQE_CPL_RSP_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__DSTFIFO
#define RQCQE_CPL_RSP_MSG_QW0__DSTFIFO__MSB                                  9
#define RQCQE_CPL_RSP_MSG_QW0__DSTFIFO__LSB                                  6
#define RQCQE_CPL_RSP_MSG_QW0__DSTFIFO__WIDTH                                4
#define RQCQE_CPL_RSP_MSG_QW0__DSTFIFO__MASK                             0x3c0
#define RQCQE_CPL_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:RQCQE_CPL_RSP_MSG_QW0__CNT
#define RQCQE_CPL_RSP_MSG_QW0__CNT__MSB                                      5
#define RQCQE_CPL_RSP_MSG_QW0__CNT__LSB                                      0
#define RQCQE_CPL_RSP_MSG_QW0__CNT__WIDTH                                    6
#define RQCQE_CPL_RSP_MSG_QW0__CNT__MASK                                  0x3f
#define RQCQE_CPL_RSP_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  RQCQE_CPL_RSP_MSG_QW0  qw0;
} RQCQE_CPL_RSP_MSG;
//QW_CNT is actual number - 1
#define RQCQE_CPL_RSP_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group SQCQE_REQ_MSG: 0x130000
#define SQCQE_REQ_MSG_MSG_ID                                              0x13
//-----Access structure typedef for Message:SQCQE_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt      : 6;
    u64 dstfifo  : 4;
    u64 dst      : 2;
    u64 src      : 4;
    u64 req_tag  : 8;
    u64 msg_id   : 8;
    u64 qpn      : 17;
    u64 fpm      : 10;
    u64 qp_type  : 3;
    u64 acked    : 1;
    u64 need_rsp : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_REQ_MSG_QW0;
//-----MACRO defines for Message:SQCQE_REQ_MSG_QW0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__NEED_RSP
#define SQCQE_REQ_MSG_QW0__NEED_RSP__MSB                                    63
#define SQCQE_REQ_MSG_QW0__NEED_RSP__LSB                                    63
#define SQCQE_REQ_MSG_QW0__NEED_RSP__WIDTH                                   1
#define SQCQE_REQ_MSG_QW0__NEED_RSP__MASK                   0x8000000000000000
#define SQCQE_REQ_MSG_QW0__NEED_RSP__RESET_VALUE                           0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__ACKED
#define SQCQE_REQ_MSG_QW0__ACKED__MSB                                       62
#define SQCQE_REQ_MSG_QW0__ACKED__LSB                                       62
#define SQCQE_REQ_MSG_QW0__ACKED__WIDTH                                      1
#define SQCQE_REQ_MSG_QW0__ACKED__MASK                      0x4000000000000000
#define SQCQE_REQ_MSG_QW0__ACKED__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__QP_TYPE
#define SQCQE_REQ_MSG_QW0__QP_TYPE__MSB                                     61
#define SQCQE_REQ_MSG_QW0__QP_TYPE__LSB                                     59
#define SQCQE_REQ_MSG_QW0__QP_TYPE__WIDTH                                    3
#define SQCQE_REQ_MSG_QW0__QP_TYPE__MASK                    0x3800000000000000
#define SQCQE_REQ_MSG_QW0__QP_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__FPM
#define SQCQE_REQ_MSG_QW0__FPM__MSB                                         58
#define SQCQE_REQ_MSG_QW0__FPM__LSB                                         49
#define SQCQE_REQ_MSG_QW0__FPM__WIDTH                                       10
#define SQCQE_REQ_MSG_QW0__FPM__MASK                         0x7fe000000000000
#define SQCQE_REQ_MSG_QW0__FPM__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__QPN
#define SQCQE_REQ_MSG_QW0__QPN__MSB                                         48
#define SQCQE_REQ_MSG_QW0__QPN__LSB                                         32
#define SQCQE_REQ_MSG_QW0__QPN__WIDTH                                       17
#define SQCQE_REQ_MSG_QW0__QPN__MASK                           0x1ffff00000000
#define SQCQE_REQ_MSG_QW0__QPN__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__MSG_ID
#define SQCQE_REQ_MSG_QW0__MSG_ID__MSB                                      31
#define SQCQE_REQ_MSG_QW0__MSG_ID__LSB                                      24
#define SQCQE_REQ_MSG_QW0__MSG_ID__WIDTH                                     8
#define SQCQE_REQ_MSG_QW0__MSG_ID__MASK                             0xff000000
#define SQCQE_REQ_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__REQ_TAG
#define SQCQE_REQ_MSG_QW0__REQ_TAG__MSB                                     23
#define SQCQE_REQ_MSG_QW0__REQ_TAG__LSB                                     16
#define SQCQE_REQ_MSG_QW0__REQ_TAG__WIDTH                                    8
#define SQCQE_REQ_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define SQCQE_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__SRC
#define SQCQE_REQ_MSG_QW0__SRC__MSB                                         15
#define SQCQE_REQ_MSG_QW0__SRC__LSB                                         12
#define SQCQE_REQ_MSG_QW0__SRC__WIDTH                                        4
#define SQCQE_REQ_MSG_QW0__SRC__MASK                                    0xf000
#define SQCQE_REQ_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__DST
#define SQCQE_REQ_MSG_QW0__DST__MSB                                         11
#define SQCQE_REQ_MSG_QW0__DST__LSB                                         10
#define SQCQE_REQ_MSG_QW0__DST__WIDTH                                        2
#define SQCQE_REQ_MSG_QW0__DST__MASK                                     0xc00
#define SQCQE_REQ_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__DSTFIFO
#define SQCQE_REQ_MSG_QW0__DSTFIFO__MSB                                      9
#define SQCQE_REQ_MSG_QW0__DSTFIFO__LSB                                      6
#define SQCQE_REQ_MSG_QW0__DSTFIFO__WIDTH                                    4
#define SQCQE_REQ_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define SQCQE_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW0__CNT
#define SQCQE_REQ_MSG_QW0__CNT__MSB                                          5
#define SQCQE_REQ_MSG_QW0__CNT__LSB                                          0
#define SQCQE_REQ_MSG_QW0__CNT__WIDTH                                        6
#define SQCQE_REQ_MSG_QW0__CNT__MASK                                      0x3f
#define SQCQE_REQ_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:SQCQE_REQ_MSG_QW1
typedef union {
  struct {
    u64 prev_sqcqe_obj_hmcpage : 19;
    u64 rsvd0                  : 1;
    u64 sqcqe_obj_addr         : 24;
    u64 rsvd1                  : 2;
    u64 cqn                    : 18;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_REQ_MSG_QW1;
//-----MACRO defines for Message:SQCQE_REQ_MSG_QW1

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW1__CQN
#define SQCQE_REQ_MSG_QW1__CQN__MSB                                         63
#define SQCQE_REQ_MSG_QW1__CQN__LSB                                         46
#define SQCQE_REQ_MSG_QW1__CQN__WIDTH                                       18
#define SQCQE_REQ_MSG_QW1__CQN__MASK                        0xffffc00000000000
#define SQCQE_REQ_MSG_QW1__CQN__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR
#define SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__MSB                              43
#define SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__LSB                              20
#define SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__WIDTH                            24
#define SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__MASK                  0xffffff00000
#define SQCQE_REQ_MSG_QW1__SQCQE_OBJ_ADDR__RESET_VALUE                     0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE
#define SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE__MSB                      18
#define SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE__LSB                       0
#define SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE__WIDTH                    19
#define SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE__MASK                0x7ffff
#define SQCQE_REQ_MSG_QW1__PREV_SQCQE_OBJ_HMCPAGE__RESET_VALUE             0x0

//-----Access structure typedef for Message:SQCQE_REQ_MSG_QW2
typedef union {
  struct {
    u64 psn        : 24;
    u64 wqe_idx    : 16;
    u64 local_flag : 1;
    u64 op         : 6;
    u64 err        : 1;
    u64 signal_cpl : 1;
    u64 rsvd0      : 12;
    u64 cqp        : 1;
    u64 report_rtt : 1;
    u64 rsvd1      : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_REQ_MSG_QW2;
//-----MACRO defines for Message:SQCQE_REQ_MSG_QW2

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__REPORT_RTT
#define SQCQE_REQ_MSG_QW2__REPORT_RTT__MSB                                  62
#define SQCQE_REQ_MSG_QW2__REPORT_RTT__LSB                                  62
#define SQCQE_REQ_MSG_QW2__REPORT_RTT__WIDTH                                 1
#define SQCQE_REQ_MSG_QW2__REPORT_RTT__MASK                 0x4000000000000000
#define SQCQE_REQ_MSG_QW2__REPORT_RTT__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__CQP
#define SQCQE_REQ_MSG_QW2__CQP__MSB                                         61
#define SQCQE_REQ_MSG_QW2__CQP__LSB                                         61
#define SQCQE_REQ_MSG_QW2__CQP__WIDTH                                        1
#define SQCQE_REQ_MSG_QW2__CQP__MASK                        0x2000000000000000
#define SQCQE_REQ_MSG_QW2__CQP__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__SIGNAL_CPL
#define SQCQE_REQ_MSG_QW2__SIGNAL_CPL__MSB                                  48
#define SQCQE_REQ_MSG_QW2__SIGNAL_CPL__LSB                                  48
#define SQCQE_REQ_MSG_QW2__SIGNAL_CPL__WIDTH                                 1
#define SQCQE_REQ_MSG_QW2__SIGNAL_CPL__MASK                    0x1000000000000
#define SQCQE_REQ_MSG_QW2__SIGNAL_CPL__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__ERR
#define SQCQE_REQ_MSG_QW2__ERR__MSB                                         47
#define SQCQE_REQ_MSG_QW2__ERR__LSB                                         47
#define SQCQE_REQ_MSG_QW2__ERR__WIDTH                                        1
#define SQCQE_REQ_MSG_QW2__ERR__MASK                            0x800000000000
#define SQCQE_REQ_MSG_QW2__ERR__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__OP
#define SQCQE_REQ_MSG_QW2__OP__MSB                                          46
#define SQCQE_REQ_MSG_QW2__OP__LSB                                          41
#define SQCQE_REQ_MSG_QW2__OP__WIDTH                                         6
#define SQCQE_REQ_MSG_QW2__OP__MASK                             0x7e0000000000
#define SQCQE_REQ_MSG_QW2__OP__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__LOCAL_FLAG
#define SQCQE_REQ_MSG_QW2__LOCAL_FLAG__MSB                                  40
#define SQCQE_REQ_MSG_QW2__LOCAL_FLAG__LSB                                  40
#define SQCQE_REQ_MSG_QW2__LOCAL_FLAG__WIDTH                                 1
#define SQCQE_REQ_MSG_QW2__LOCAL_FLAG__MASK                      0x10000000000
#define SQCQE_REQ_MSG_QW2__LOCAL_FLAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__WQE_IDX
#define SQCQE_REQ_MSG_QW2__WQE_IDX__MSB                                     39
#define SQCQE_REQ_MSG_QW2__WQE_IDX__LSB                                     24
#define SQCQE_REQ_MSG_QW2__WQE_IDX__WIDTH                                   16
#define SQCQE_REQ_MSG_QW2__WQE_IDX__MASK                          0xffff000000
#define SQCQE_REQ_MSG_QW2__WQE_IDX__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW2__PSN
#define SQCQE_REQ_MSG_QW2__PSN__MSB                                         23
#define SQCQE_REQ_MSG_QW2__PSN__LSB                                          0
#define SQCQE_REQ_MSG_QW2__PSN__WIDTH                                       24
#define SQCQE_REQ_MSG_QW2__PSN__MASK                                  0xffffff
#define SQCQE_REQ_MSG_QW2__PSN__RESET_VALUE                                0x0

//-----Access structure typedef for Message:SQCQE_REQ_MSG_QW3
typedef union {
  struct {
    u64 minor_error_code : 16;
    u64 major_error_code : 16;
    u64 pyld_len         : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_REQ_MSG_QW3;
//-----MACRO defines for Message:SQCQE_REQ_MSG_QW3

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW3__PYLD_LEN
#define SQCQE_REQ_MSG_QW3__PYLD_LEN__MSB                                    63
#define SQCQE_REQ_MSG_QW3__PYLD_LEN__LSB                                    32
#define SQCQE_REQ_MSG_QW3__PYLD_LEN__WIDTH                                  32
#define SQCQE_REQ_MSG_QW3__PYLD_LEN__MASK                   0xffffffff00000000
#define SQCQE_REQ_MSG_QW3__PYLD_LEN__RESET_VALUE                           0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE
#define SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__MSB                            31
#define SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__LSB                            16
#define SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__WIDTH                          16
#define SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__MASK                   0xffff0000
#define SQCQE_REQ_MSG_QW3__MAJOR_ERROR_CODE__RESET_VALUE                   0x0

//-----MACRO defines for fields:SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE
#define SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__MSB                            15
#define SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__LSB                             0
#define SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__WIDTH                          16
#define SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__MASK                       0xffff
#define SQCQE_REQ_MSG_QW3__MINOR_ERROR_CODE__RESET_VALUE                   0x0

typedef struct {
  SQCQE_REQ_MSG_QW0  qw0;
  SQCQE_REQ_MSG_QW1  qw1;
  SQCQE_REQ_MSG_QW2  qw2;
  SQCQE_REQ_MSG_QW3  qw3;
} SQCQE_REQ_MSG;
//QW_CNT is actual number - 1
#define SQCQE_REQ_MSG_QW_CNT                                                 3
//-----MACRO defines for  Message Group SQCQE_REQ_RSP_MSG: 0x140000
#define SQCQE_REQ_RSP_MSG_MSG_ID                                          0x14
//-----Access structure typedef for Message:SQCQE_REQ_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_REQ_RSP_MSG_QW0;
//-----MACRO defines for Message:SQCQE_REQ_RSP_MSG_QW0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__MSG_ID
#define SQCQE_REQ_RSP_MSG_QW0__MSG_ID__MSB                                  31
#define SQCQE_REQ_RSP_MSG_QW0__MSG_ID__LSB                                  24
#define SQCQE_REQ_RSP_MSG_QW0__MSG_ID__WIDTH                                 8
#define SQCQE_REQ_RSP_MSG_QW0__MSG_ID__MASK                         0xff000000
#define SQCQE_REQ_RSP_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__REQ_TAG
#define SQCQE_REQ_RSP_MSG_QW0__REQ_TAG__MSB                                 23
#define SQCQE_REQ_RSP_MSG_QW0__REQ_TAG__LSB                                 16
#define SQCQE_REQ_RSP_MSG_QW0__REQ_TAG__WIDTH                                8
#define SQCQE_REQ_RSP_MSG_QW0__REQ_TAG__MASK                          0xff0000
#define SQCQE_REQ_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__SRC
#define SQCQE_REQ_RSP_MSG_QW0__SRC__MSB                                     15
#define SQCQE_REQ_RSP_MSG_QW0__SRC__LSB                                     12
#define SQCQE_REQ_RSP_MSG_QW0__SRC__WIDTH                                    4
#define SQCQE_REQ_RSP_MSG_QW0__SRC__MASK                                0xf000
#define SQCQE_REQ_RSP_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__DST
#define SQCQE_REQ_RSP_MSG_QW0__DST__MSB                                     11
#define SQCQE_REQ_RSP_MSG_QW0__DST__LSB                                     10
#define SQCQE_REQ_RSP_MSG_QW0__DST__WIDTH                                    2
#define SQCQE_REQ_RSP_MSG_QW0__DST__MASK                                 0xc00
#define SQCQE_REQ_RSP_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__DSTFIFO
#define SQCQE_REQ_RSP_MSG_QW0__DSTFIFO__MSB                                  9
#define SQCQE_REQ_RSP_MSG_QW0__DSTFIFO__LSB                                  6
#define SQCQE_REQ_RSP_MSG_QW0__DSTFIFO__WIDTH                                4
#define SQCQE_REQ_RSP_MSG_QW0__DSTFIFO__MASK                             0x3c0
#define SQCQE_REQ_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQCQE_REQ_RSP_MSG_QW0__CNT
#define SQCQE_REQ_RSP_MSG_QW0__CNT__MSB                                      5
#define SQCQE_REQ_RSP_MSG_QW0__CNT__LSB                                      0
#define SQCQE_REQ_RSP_MSG_QW0__CNT__WIDTH                                    6
#define SQCQE_REQ_RSP_MSG_QW0__CNT__MASK                                  0x3f
#define SQCQE_REQ_RSP_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  SQCQE_REQ_RSP_MSG_QW0  qw0;
} SQCQE_REQ_RSP_MSG;
//QW_CNT is actual number - 1
#define SQCQE_REQ_RSP_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group SQCQE_CPL_MSG: 0x150000
#define SQCQE_CPL_MSG_MSG_ID                                              0x15
//-----Access structure typedef for Message:SQCQE_CPL_MSG_QW0
typedef union {
  struct {
    u64 cnt          : 6;
    u64 dstfifo      : 4;
    u64 dst          : 2;
    u64 src          : 4;
    u64 req_tag      : 8;
    u64 msg_id       : 8;
    u64 qpn          : 17;
    u64 fpm          : 10;
    u64 flush_type   : 2;
    u64 flush        : 1;
    u64 flush_uncomp : 1;
    u64 need_rsp     : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_CPL_MSG_QW0;
//-----MACRO defines for Message:SQCQE_CPL_MSG_QW0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__NEED_RSP
#define SQCQE_CPL_MSG_QW0__NEED_RSP__MSB                                    63
#define SQCQE_CPL_MSG_QW0__NEED_RSP__LSB                                    63
#define SQCQE_CPL_MSG_QW0__NEED_RSP__WIDTH                                   1
#define SQCQE_CPL_MSG_QW0__NEED_RSP__MASK                   0x8000000000000000
#define SQCQE_CPL_MSG_QW0__NEED_RSP__RESET_VALUE                           0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP
#define SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__MSB                                62
#define SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__LSB                                62
#define SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__WIDTH                               1
#define SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__MASK               0x4000000000000000
#define SQCQE_CPL_MSG_QW0__FLUSH_UNCOMP__RESET_VALUE                       0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__FLUSH
#define SQCQE_CPL_MSG_QW0__FLUSH__MSB                                       61
#define SQCQE_CPL_MSG_QW0__FLUSH__LSB                                       61
#define SQCQE_CPL_MSG_QW0__FLUSH__WIDTH                                      1
#define SQCQE_CPL_MSG_QW0__FLUSH__MASK                      0x2000000000000000
#define SQCQE_CPL_MSG_QW0__FLUSH__RESET_VALUE                              0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__FLUSH_TYPE
#define SQCQE_CPL_MSG_QW0__FLUSH_TYPE__MSB                                  60
#define SQCQE_CPL_MSG_QW0__FLUSH_TYPE__LSB                                  59
#define SQCQE_CPL_MSG_QW0__FLUSH_TYPE__WIDTH                                 2
#define SQCQE_CPL_MSG_QW0__FLUSH_TYPE__MASK                 0x1800000000000000
#define SQCQE_CPL_MSG_QW0__FLUSH_TYPE__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__FPM
#define SQCQE_CPL_MSG_QW0__FPM__MSB                                         58
#define SQCQE_CPL_MSG_QW0__FPM__LSB                                         49
#define SQCQE_CPL_MSG_QW0__FPM__WIDTH                                       10
#define SQCQE_CPL_MSG_QW0__FPM__MASK                         0x7fe000000000000
#define SQCQE_CPL_MSG_QW0__FPM__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__QPN
#define SQCQE_CPL_MSG_QW0__QPN__MSB                                         48
#define SQCQE_CPL_MSG_QW0__QPN__LSB                                         32
#define SQCQE_CPL_MSG_QW0__QPN__WIDTH                                       17
#define SQCQE_CPL_MSG_QW0__QPN__MASK                           0x1ffff00000000
#define SQCQE_CPL_MSG_QW0__QPN__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__MSG_ID
#define SQCQE_CPL_MSG_QW0__MSG_ID__MSB                                      31
#define SQCQE_CPL_MSG_QW0__MSG_ID__LSB                                      24
#define SQCQE_CPL_MSG_QW0__MSG_ID__WIDTH                                     8
#define SQCQE_CPL_MSG_QW0__MSG_ID__MASK                             0xff000000
#define SQCQE_CPL_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__REQ_TAG
#define SQCQE_CPL_MSG_QW0__REQ_TAG__MSB                                     23
#define SQCQE_CPL_MSG_QW0__REQ_TAG__LSB                                     16
#define SQCQE_CPL_MSG_QW0__REQ_TAG__WIDTH                                    8
#define SQCQE_CPL_MSG_QW0__REQ_TAG__MASK                              0xff0000
#define SQCQE_CPL_MSG_QW0__REQ_TAG__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__SRC
#define SQCQE_CPL_MSG_QW0__SRC__MSB                                         15
#define SQCQE_CPL_MSG_QW0__SRC__LSB                                         12
#define SQCQE_CPL_MSG_QW0__SRC__WIDTH                                        4
#define SQCQE_CPL_MSG_QW0__SRC__MASK                                    0xf000
#define SQCQE_CPL_MSG_QW0__SRC__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__DST
#define SQCQE_CPL_MSG_QW0__DST__MSB                                         11
#define SQCQE_CPL_MSG_QW0__DST__LSB                                         10
#define SQCQE_CPL_MSG_QW0__DST__WIDTH                                        2
#define SQCQE_CPL_MSG_QW0__DST__MASK                                     0xc00
#define SQCQE_CPL_MSG_QW0__DST__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__DSTFIFO
#define SQCQE_CPL_MSG_QW0__DSTFIFO__MSB                                      9
#define SQCQE_CPL_MSG_QW0__DSTFIFO__LSB                                      6
#define SQCQE_CPL_MSG_QW0__DSTFIFO__WIDTH                                    4
#define SQCQE_CPL_MSG_QW0__DSTFIFO__MASK                                 0x3c0
#define SQCQE_CPL_MSG_QW0__DSTFIFO__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW0__CNT
#define SQCQE_CPL_MSG_QW0__CNT__MSB                                          5
#define SQCQE_CPL_MSG_QW0__CNT__LSB                                          0
#define SQCQE_CPL_MSG_QW0__CNT__WIDTH                                        6
#define SQCQE_CPL_MSG_QW0__CNT__MASK                                      0x3f
#define SQCQE_CPL_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:SQCQE_CPL_MSG_QW1
typedef union {
  struct {
    u64 cpl_ctx_hi : 32;
    u64 op         : 8;
    u64 rsvd0      : 4;
    u64 cqp        : 1;
    u64 rrsp       : 1;
    u64 cqn        : 18;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_CPL_MSG_QW1;
//-----MACRO defines for Message:SQCQE_CPL_MSG_QW1

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW1__CQN
#define SQCQE_CPL_MSG_QW1__CQN__MSB                                         63
#define SQCQE_CPL_MSG_QW1__CQN__LSB                                         46
#define SQCQE_CPL_MSG_QW1__CQN__WIDTH                                       18
#define SQCQE_CPL_MSG_QW1__CQN__MASK                        0xffffc00000000000
#define SQCQE_CPL_MSG_QW1__CQN__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW1__RRSP
#define SQCQE_CPL_MSG_QW1__RRSP__MSB                                        45
#define SQCQE_CPL_MSG_QW1__RRSP__LSB                                        45
#define SQCQE_CPL_MSG_QW1__RRSP__WIDTH                                       1
#define SQCQE_CPL_MSG_QW1__RRSP__MASK                           0x200000000000
#define SQCQE_CPL_MSG_QW1__RRSP__RESET_VALUE                               0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW1__CQP
#define SQCQE_CPL_MSG_QW1__CQP__MSB                                         44
#define SQCQE_CPL_MSG_QW1__CQP__LSB                                         44
#define SQCQE_CPL_MSG_QW1__CQP__WIDTH                                        1
#define SQCQE_CPL_MSG_QW1__CQP__MASK                            0x100000000000
#define SQCQE_CPL_MSG_QW1__CQP__RESET_VALUE                                0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW1__OP
#define SQCQE_CPL_MSG_QW1__OP__MSB                                          39
#define SQCQE_CPL_MSG_QW1__OP__LSB                                          32
#define SQCQE_CPL_MSG_QW1__OP__WIDTH                                         8
#define SQCQE_CPL_MSG_QW1__OP__MASK                               0xff00000000
#define SQCQE_CPL_MSG_QW1__OP__RESET_VALUE                                 0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW1__CPL_CTX_HI
#define SQCQE_CPL_MSG_QW1__CPL_CTX_HI__MSB                                  31
#define SQCQE_CPL_MSG_QW1__CPL_CTX_HI__LSB                                   0
#define SQCQE_CPL_MSG_QW1__CPL_CTX_HI__WIDTH                                32
#define SQCQE_CPL_MSG_QW1__CPL_CTX_HI__MASK                         0xffffffff
#define SQCQE_CPL_MSG_QW1__CPL_CTX_HI__RESET_VALUE                         0x0

//-----Access structure typedef for Message:SQCQE_CPL_MSG_QW2
typedef union {
  struct {
    u64 psn_or_sqcqe_hmcpage : 24;
    u64 rsvd0                : 6;
    u64 local_flag           : 1;
    u64 rtt_vld              : 1;
    u64 rtt_or_cpl_ctx_lo    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_CPL_MSG_QW2;
//-----MACRO defines for Message:SQCQE_CPL_MSG_QW2

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO
#define SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO__MSB                           63
#define SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO__LSB                           32
#define SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO__WIDTH                         32
#define SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO__MASK          0xffffffff00000000
#define SQCQE_CPL_MSG_QW2__RTT_OR_CPL_CTX_LO__RESET_VALUE                  0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW2__RTT_VLD
#define SQCQE_CPL_MSG_QW2__RTT_VLD__MSB                                     31
#define SQCQE_CPL_MSG_QW2__RTT_VLD__LSB                                     31
#define SQCQE_CPL_MSG_QW2__RTT_VLD__WIDTH                                    1
#define SQCQE_CPL_MSG_QW2__RTT_VLD__MASK                            0x80000000
#define SQCQE_CPL_MSG_QW2__RTT_VLD__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW2__LOCAL_FLAG
#define SQCQE_CPL_MSG_QW2__LOCAL_FLAG__MSB                                  30
#define SQCQE_CPL_MSG_QW2__LOCAL_FLAG__LSB                                  30
#define SQCQE_CPL_MSG_QW2__LOCAL_FLAG__WIDTH                                 1
#define SQCQE_CPL_MSG_QW2__LOCAL_FLAG__MASK                         0x40000000
#define SQCQE_CPL_MSG_QW2__LOCAL_FLAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE
#define SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE__MSB                        23
#define SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE__LSB                         0
#define SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE__WIDTH                      24
#define SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE__MASK                 0xffffff
#define SQCQE_CPL_MSG_QW2__PSN_OR_SQCQE_HMCPAGE__RESET_VALUE               0x0

//-----Access structure typedef for Message:SQCQE_CPL_MSG_QW3
typedef union {
  struct {
    u64 minor_error_code       : 16;
    u64 major_error_code       : 16;
    u64 operation_return_value : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_CPL_MSG_QW3;
//-----MACRO defines for Message:SQCQE_CPL_MSG_QW3

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE
#define SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE__MSB                      63
#define SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE__LSB                      32
#define SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE__WIDTH                    32
#define SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE__MASK     0xffffffff00000000
#define SQCQE_CPL_MSG_QW3__OPERATION_RETURN_VALUE__RESET_VALUE             0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE
#define SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE__MSB                            31
#define SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE__LSB                            16
#define SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE__WIDTH                          16
#define SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE__MASK                   0xffff0000
#define SQCQE_CPL_MSG_QW3__MAJOR_ERROR_CODE__RESET_VALUE                   0x0

//-----MACRO defines for fields:SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE
#define SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE__MSB                            15
#define SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE__LSB                             0
#define SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE__WIDTH                          16
#define SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE__MASK                       0xffff
#define SQCQE_CPL_MSG_QW3__MINOR_ERROR_CODE__RESET_VALUE                   0x0

typedef struct {
  SQCQE_CPL_MSG_QW0  qw0;
  SQCQE_CPL_MSG_QW1  qw1;
  SQCQE_CPL_MSG_QW2  qw2;
  SQCQE_CPL_MSG_QW3  qw3;
} SQCQE_CPL_MSG;
//QW_CNT is actual number - 1
#define SQCQE_CPL_MSG_QW_CNT                                                 3
//-----MACRO defines for  Message Group SQCQE_CPL_RSP_MSG: 0x160000
#define SQCQE_CPL_RSP_MSG_MSG_ID                                          0x16
//-----Access structure typedef for Message:SQCQE_CPL_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SQCQE_CPL_RSP_MSG_QW0;
//-----MACRO defines for Message:SQCQE_CPL_RSP_MSG_QW0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__MSG_ID
#define SQCQE_CPL_RSP_MSG_QW0__MSG_ID__MSB                                  31
#define SQCQE_CPL_RSP_MSG_QW0__MSG_ID__LSB                                  24
#define SQCQE_CPL_RSP_MSG_QW0__MSG_ID__WIDTH                                 8
#define SQCQE_CPL_RSP_MSG_QW0__MSG_ID__MASK                         0xff000000
#define SQCQE_CPL_RSP_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__REQ_TAG
#define SQCQE_CPL_RSP_MSG_QW0__REQ_TAG__MSB                                 23
#define SQCQE_CPL_RSP_MSG_QW0__REQ_TAG__LSB                                 16
#define SQCQE_CPL_RSP_MSG_QW0__REQ_TAG__WIDTH                                8
#define SQCQE_CPL_RSP_MSG_QW0__REQ_TAG__MASK                          0xff0000
#define SQCQE_CPL_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__SRC
#define SQCQE_CPL_RSP_MSG_QW0__SRC__MSB                                     15
#define SQCQE_CPL_RSP_MSG_QW0__SRC__LSB                                     12
#define SQCQE_CPL_RSP_MSG_QW0__SRC__WIDTH                                    4
#define SQCQE_CPL_RSP_MSG_QW0__SRC__MASK                                0xf000
#define SQCQE_CPL_RSP_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__DST
#define SQCQE_CPL_RSP_MSG_QW0__DST__MSB                                     11
#define SQCQE_CPL_RSP_MSG_QW0__DST__LSB                                     10
#define SQCQE_CPL_RSP_MSG_QW0__DST__WIDTH                                    2
#define SQCQE_CPL_RSP_MSG_QW0__DST__MASK                                 0xc00
#define SQCQE_CPL_RSP_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__DSTFIFO
#define SQCQE_CPL_RSP_MSG_QW0__DSTFIFO__MSB                                  9
#define SQCQE_CPL_RSP_MSG_QW0__DSTFIFO__LSB                                  6
#define SQCQE_CPL_RSP_MSG_QW0__DSTFIFO__WIDTH                                4
#define SQCQE_CPL_RSP_MSG_QW0__DSTFIFO__MASK                             0x3c0
#define SQCQE_CPL_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:SQCQE_CPL_RSP_MSG_QW0__CNT
#define SQCQE_CPL_RSP_MSG_QW0__CNT__MSB                                      5
#define SQCQE_CPL_RSP_MSG_QW0__CNT__LSB                                      0
#define SQCQE_CPL_RSP_MSG_QW0__CNT__WIDTH                                    6
#define SQCQE_CPL_RSP_MSG_QW0__CNT__MASK                                  0x3f
#define SQCQE_CPL_RSP_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  SQCQE_CPL_RSP_MSG_QW0  qw0;
} SQCQE_CPL_RSP_MSG;
//QW_CNT is actual number - 1
#define SQCQE_CPL_RSP_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group INB_PKT_MSG: 0x170000
#define INB_PKT_MSG_MSG_ID                                                0x17
//-----Access structure typedef for Message:INB_PKT_MSG_QW0
typedef union {
  struct {
    u64 cnt             : 6;
    u64 flush_type      : 2;
    u64 qp_type         : 3;
    u64 eth_crc_present : 1;
    u64 mcast           : 1;
    u64 mcast_last      : 1;
    u64 qpn             : 17;
    u64 fpm             : 10;
    u64 opcode          : 8;
    u64 flush           : 1;
    u64 pd_index_hi     : 2;
    u64 rsvd0           : 2;
    u64 privilegeenable : 1;
    u64 qset            : 9;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW0;
//-----MACRO defines for Message:INB_PKT_MSG_QW0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__QSET
#define INB_PKT_MSG_QW0__QSET__MSB                                          63
#define INB_PKT_MSG_QW0__QSET__LSB                                          55
#define INB_PKT_MSG_QW0__QSET__WIDTH                                         9
#define INB_PKT_MSG_QW0__QSET__MASK                         0xff80000000000000
#define INB_PKT_MSG_QW0__QSET__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__PRIVILEGEENABLE
#define INB_PKT_MSG_QW0__PRIVILEGEENABLE__MSB                               54
#define INB_PKT_MSG_QW0__PRIVILEGEENABLE__LSB                               54
#define INB_PKT_MSG_QW0__PRIVILEGEENABLE__WIDTH                              1
#define INB_PKT_MSG_QW0__PRIVILEGEENABLE__MASK                0x40000000000000
#define INB_PKT_MSG_QW0__PRIVILEGEENABLE__RESET_VALUE                      0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__PD_INDEX_HI
#define INB_PKT_MSG_QW0__PD_INDEX_HI__MSB                                   51
#define INB_PKT_MSG_QW0__PD_INDEX_HI__LSB                                   50
#define INB_PKT_MSG_QW0__PD_INDEX_HI__WIDTH                                  2
#define INB_PKT_MSG_QW0__PD_INDEX_HI__MASK                     0xc000000000000
#define INB_PKT_MSG_QW0__PD_INDEX_HI__RESET_VALUE                          0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__FLUSH
#define INB_PKT_MSG_QW0__FLUSH__MSB                                         49
#define INB_PKT_MSG_QW0__FLUSH__LSB                                         49
#define INB_PKT_MSG_QW0__FLUSH__WIDTH                                        1
#define INB_PKT_MSG_QW0__FLUSH__MASK                           0x2000000000000
#define INB_PKT_MSG_QW0__FLUSH__RESET_VALUE                                0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__OPCODE
#define INB_PKT_MSG_QW0__OPCODE__MSB                                        48
#define INB_PKT_MSG_QW0__OPCODE__LSB                                        41
#define INB_PKT_MSG_QW0__OPCODE__WIDTH                                       8
#define INB_PKT_MSG_QW0__OPCODE__MASK                          0x1fe0000000000
#define INB_PKT_MSG_QW0__OPCODE__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__FPM
#define INB_PKT_MSG_QW0__FPM__MSB                                           40
#define INB_PKT_MSG_QW0__FPM__LSB                                           31
#define INB_PKT_MSG_QW0__FPM__WIDTH                                         10
#define INB_PKT_MSG_QW0__FPM__MASK                               0x1ff80000000
#define INB_PKT_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__QPN
#define INB_PKT_MSG_QW0__QPN__MSB                                           30
#define INB_PKT_MSG_QW0__QPN__LSB                                           14
#define INB_PKT_MSG_QW0__QPN__WIDTH                                         17
#define INB_PKT_MSG_QW0__QPN__MASK                                  0x7fffc000
#define INB_PKT_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__MCAST_LAST
#define INB_PKT_MSG_QW0__MCAST_LAST__MSB                                    13
#define INB_PKT_MSG_QW0__MCAST_LAST__LSB                                    13
#define INB_PKT_MSG_QW0__MCAST_LAST__WIDTH                                   1
#define INB_PKT_MSG_QW0__MCAST_LAST__MASK                               0x2000
#define INB_PKT_MSG_QW0__MCAST_LAST__RESET_VALUE                           0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__MCAST
#define INB_PKT_MSG_QW0__MCAST__MSB                                         12
#define INB_PKT_MSG_QW0__MCAST__LSB                                         12
#define INB_PKT_MSG_QW0__MCAST__WIDTH                                        1
#define INB_PKT_MSG_QW0__MCAST__MASK                                    0x1000
#define INB_PKT_MSG_QW0__MCAST__RESET_VALUE                                0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__ETH_CRC_PRESENT
#define INB_PKT_MSG_QW0__ETH_CRC_PRESENT__MSB                               11
#define INB_PKT_MSG_QW0__ETH_CRC_PRESENT__LSB                               11
#define INB_PKT_MSG_QW0__ETH_CRC_PRESENT__WIDTH                              1
#define INB_PKT_MSG_QW0__ETH_CRC_PRESENT__MASK                           0x800
#define INB_PKT_MSG_QW0__ETH_CRC_PRESENT__RESET_VALUE                      0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__QP_TYPE
#define INB_PKT_MSG_QW0__QP_TYPE__MSB                                       10
#define INB_PKT_MSG_QW0__QP_TYPE__LSB                                        8
#define INB_PKT_MSG_QW0__QP_TYPE__WIDTH                                      3
#define INB_PKT_MSG_QW0__QP_TYPE__MASK                                   0x700
#define INB_PKT_MSG_QW0__QP_TYPE__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__FLUSH_TYPE
#define INB_PKT_MSG_QW0__FLUSH_TYPE__MSB                                     7
#define INB_PKT_MSG_QW0__FLUSH_TYPE__LSB                                     6
#define INB_PKT_MSG_QW0__FLUSH_TYPE__WIDTH                                   2
#define INB_PKT_MSG_QW0__FLUSH_TYPE__MASK                                 0xc0
#define INB_PKT_MSG_QW0__FLUSH_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW0__CNT
#define INB_PKT_MSG_QW0__CNT__MSB                                            5
#define INB_PKT_MSG_QW0__CNT__LSB                                            0
#define INB_PKT_MSG_QW0__CNT__WIDTH                                          6
#define INB_PKT_MSG_QW0__CNT__MASK                                        0x3f
#define INB_PKT_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW1
typedef union {
  struct {
    u64 psn         : 24;
    u64 padcnt      : 2;
    u64 rsvd0       : 1;
    u64 ackreq      : 1;
    u64 rsvd1       : 1;
    u64 se          : 1;
    u64 pe_dup      : 1;
    u64 rsvd2       : 1;
    u64 pyld_len    : 16;
    u64 pd_index_lo : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW1;
//-----MACRO defines for Message:INB_PKT_MSG_QW1

//-----MACRO defines for fields:INB_PKT_MSG_QW1__PD_INDEX_LO
#define INB_PKT_MSG_QW1__PD_INDEX_LO__MSB                                   63
#define INB_PKT_MSG_QW1__PD_INDEX_LO__LSB                                   48
#define INB_PKT_MSG_QW1__PD_INDEX_LO__WIDTH                                 16
#define INB_PKT_MSG_QW1__PD_INDEX_LO__MASK                  0xffff000000000000
#define INB_PKT_MSG_QW1__PD_INDEX_LO__RESET_VALUE                          0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__PYLD_LEN
#define INB_PKT_MSG_QW1__PYLD_LEN__MSB                                      47
#define INB_PKT_MSG_QW1__PYLD_LEN__LSB                                      32
#define INB_PKT_MSG_QW1__PYLD_LEN__WIDTH                                    16
#define INB_PKT_MSG_QW1__PYLD_LEN__MASK                         0xffff00000000
#define INB_PKT_MSG_QW1__PYLD_LEN__RESET_VALUE                             0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__PE_DUP
#define INB_PKT_MSG_QW1__PE_DUP__MSB                                        30
#define INB_PKT_MSG_QW1__PE_DUP__LSB                                        30
#define INB_PKT_MSG_QW1__PE_DUP__WIDTH                                       1
#define INB_PKT_MSG_QW1__PE_DUP__MASK                               0x40000000
#define INB_PKT_MSG_QW1__PE_DUP__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__SE
#define INB_PKT_MSG_QW1__SE__MSB                                            29
#define INB_PKT_MSG_QW1__SE__LSB                                            29
#define INB_PKT_MSG_QW1__SE__WIDTH                                           1
#define INB_PKT_MSG_QW1__SE__MASK                                   0x20000000
#define INB_PKT_MSG_QW1__SE__RESET_VALUE                                   0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__ACKREQ
#define INB_PKT_MSG_QW1__ACKREQ__MSB                                        27
#define INB_PKT_MSG_QW1__ACKREQ__LSB                                        27
#define INB_PKT_MSG_QW1__ACKREQ__WIDTH                                       1
#define INB_PKT_MSG_QW1__ACKREQ__MASK                                0x8000000
#define INB_PKT_MSG_QW1__ACKREQ__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__PADCNT
#define INB_PKT_MSG_QW1__PADCNT__MSB                                        25
#define INB_PKT_MSG_QW1__PADCNT__LSB                                        24
#define INB_PKT_MSG_QW1__PADCNT__WIDTH                                       2
#define INB_PKT_MSG_QW1__PADCNT__MASK                                0x3000000
#define INB_PKT_MSG_QW1__PADCNT__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW1__PSN
#define INB_PKT_MSG_QW1__PSN__MSB                                           23
#define INB_PKT_MSG_QW1__PSN__LSB                                            0
#define INB_PKT_MSG_QW1__PSN__WIDTH                                         24
#define INB_PKT_MSG_QW1__PSN__MASK                                    0xffffff
#define INB_PKT_MSG_QW1__PSN__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW2
typedef union {
  struct {
    u64 va    : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW2;
//-----MACRO defines for Message:INB_PKT_MSG_QW2

//-----MACRO defines for fields:INB_PKT_MSG_QW2__VA
#define INB_PKT_MSG_QW2__VA__MSB                                            63
#define INB_PKT_MSG_QW2__VA__LSB                                             0
#define INB_PKT_MSG_QW2__VA__WIDTH                                          64
#define INB_PKT_MSG_QW2__VA__MASK                           0xffffffffffffffff
#define INB_PKT_MSG_QW2__VA__RESET_VALUE                                   0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW3
typedef union {
  struct {
    u64 dmalen : 32;
    u64 key    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW3;
//-----MACRO defines for Message:INB_PKT_MSG_QW3

//-----MACRO defines for fields:INB_PKT_MSG_QW3__KEY
#define INB_PKT_MSG_QW3__KEY__MSB                                           63
#define INB_PKT_MSG_QW3__KEY__LSB                                           32
#define INB_PKT_MSG_QW3__KEY__WIDTH                                         32
#define INB_PKT_MSG_QW3__KEY__MASK                          0xffffffff00000000
#define INB_PKT_MSG_QW3__KEY__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW3__DMALEN
#define INB_PKT_MSG_QW3__DMALEN__MSB                                        31
#define INB_PKT_MSG_QW3__DMALEN__LSB                                         0
#define INB_PKT_MSG_QW3__DMALEN__WIDTH                                      32
#define INB_PKT_MSG_QW3__DMALEN__MASK                               0xffffffff
#define INB_PKT_MSG_QW3__DMALEN__RESET_VALUE                               0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW4
typedef union {
  struct {
    u64 rdb_buf_ofst : 2;
    u64 rdb_buf_ptr  : 10;
    u64 dup_pkt_tag  : 10;
    u64 dup_pkt      : 1;
    u64 rsvd0        : 1;
    u64 psn_ofst     : 24;
    u64 wqe_index    : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW4;
//-----MACRO defines for Message:INB_PKT_MSG_QW4

//-----MACRO defines for fields:INB_PKT_MSG_QW4__WQE_INDEX
#define INB_PKT_MSG_QW4__WQE_INDEX__MSB                                     63
#define INB_PKT_MSG_QW4__WQE_INDEX__LSB                                     48
#define INB_PKT_MSG_QW4__WQE_INDEX__WIDTH                                   16
#define INB_PKT_MSG_QW4__WQE_INDEX__MASK                    0xffff000000000000
#define INB_PKT_MSG_QW4__WQE_INDEX__RESET_VALUE                            0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW4__PSN_OFST
#define INB_PKT_MSG_QW4__PSN_OFST__MSB                                      47
#define INB_PKT_MSG_QW4__PSN_OFST__LSB                                      24
#define INB_PKT_MSG_QW4__PSN_OFST__WIDTH                                    24
#define INB_PKT_MSG_QW4__PSN_OFST__MASK                         0xffffff000000
#define INB_PKT_MSG_QW4__PSN_OFST__RESET_VALUE                             0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW4__DUP_PKT
#define INB_PKT_MSG_QW4__DUP_PKT__MSB                                       22
#define INB_PKT_MSG_QW4__DUP_PKT__LSB                                       22
#define INB_PKT_MSG_QW4__DUP_PKT__WIDTH                                      1
#define INB_PKT_MSG_QW4__DUP_PKT__MASK                                0x400000
#define INB_PKT_MSG_QW4__DUP_PKT__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW4__DUP_PKT_TAG
#define INB_PKT_MSG_QW4__DUP_PKT_TAG__MSB                                   21
#define INB_PKT_MSG_QW4__DUP_PKT_TAG__LSB                                   12
#define INB_PKT_MSG_QW4__DUP_PKT_TAG__WIDTH                                 10
#define INB_PKT_MSG_QW4__DUP_PKT_TAG__MASK                            0x3ff000
#define INB_PKT_MSG_QW4__DUP_PKT_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW4__RDB_BUF_PTR
#define INB_PKT_MSG_QW4__RDB_BUF_PTR__MSB                                   11
#define INB_PKT_MSG_QW4__RDB_BUF_PTR__LSB                                    2
#define INB_PKT_MSG_QW4__RDB_BUF_PTR__WIDTH                                 10
#define INB_PKT_MSG_QW4__RDB_BUF_PTR__MASK                               0xffc
#define INB_PKT_MSG_QW4__RDB_BUF_PTR__RESET_VALUE                          0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW4__RDB_BUF_OFST
#define INB_PKT_MSG_QW4__RDB_BUF_OFST__MSB                                   1
#define INB_PKT_MSG_QW4__RDB_BUF_OFST__LSB                                   0
#define INB_PKT_MSG_QW4__RDB_BUF_OFST__WIDTH                                 2
#define INB_PKT_MSG_QW4__RDB_BUF_OFST__MASK                                0x3
#define INB_PKT_MSG_QW4__RDB_BUF_OFST__RESET_VALUE                         0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW5
typedef union {
  struct {
    u64 rqe_prefetch_cnt  : 4;
    u64 rsvd0             : 5;
    u64 pmtu              : 3;
    u64 rtt_vld           : 1;
    u64 minipo_remain_cnt : 5;
    u64 ud_l23_hdr_bcnt   : 6;
    u64 rsvd1             : 3;
    u64 vlan_tag_vld      : 1;
    u64 comp              : 1;
    u64 tph_en            : 1;
    u64 ipv4              : 1;
    u64 rsvd2             : 1;
    u64 rtt               : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW5;
//-----MACRO defines for Message:INB_PKT_MSG_QW5

//-----MACRO defines for fields:INB_PKT_MSG_QW5__RTT
#define INB_PKT_MSG_QW5__RTT__MSB                                           63
#define INB_PKT_MSG_QW5__RTT__LSB                                           32
#define INB_PKT_MSG_QW5__RTT__WIDTH                                         32
#define INB_PKT_MSG_QW5__RTT__MASK                          0xffffffff00000000
#define INB_PKT_MSG_QW5__RTT__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__IPV4
#define INB_PKT_MSG_QW5__IPV4__MSB                                          30
#define INB_PKT_MSG_QW5__IPV4__LSB                                          30
#define INB_PKT_MSG_QW5__IPV4__WIDTH                                         1
#define INB_PKT_MSG_QW5__IPV4__MASK                                 0x40000000
#define INB_PKT_MSG_QW5__IPV4__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__TPH_EN
#define INB_PKT_MSG_QW5__TPH_EN__MSB                                        29
#define INB_PKT_MSG_QW5__TPH_EN__LSB                                        29
#define INB_PKT_MSG_QW5__TPH_EN__WIDTH                                       1
#define INB_PKT_MSG_QW5__TPH_EN__MASK                               0x20000000
#define INB_PKT_MSG_QW5__TPH_EN__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__COMP
#define INB_PKT_MSG_QW5__COMP__MSB                                          28
#define INB_PKT_MSG_QW5__COMP__LSB                                          28
#define INB_PKT_MSG_QW5__COMP__WIDTH                                         1
#define INB_PKT_MSG_QW5__COMP__MASK                                 0x10000000
#define INB_PKT_MSG_QW5__COMP__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__VLAN_TAG_VLD
#define INB_PKT_MSG_QW5__VLAN_TAG_VLD__MSB                                  27
#define INB_PKT_MSG_QW5__VLAN_TAG_VLD__LSB                                  27
#define INB_PKT_MSG_QW5__VLAN_TAG_VLD__WIDTH                                 1
#define INB_PKT_MSG_QW5__VLAN_TAG_VLD__MASK                          0x8000000
#define INB_PKT_MSG_QW5__VLAN_TAG_VLD__RESET_VALUE                         0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__UD_L23_HDR_BCNT
#define INB_PKT_MSG_QW5__UD_L23_HDR_BCNT__MSB                               23
#define INB_PKT_MSG_QW5__UD_L23_HDR_BCNT__LSB                               18
#define INB_PKT_MSG_QW5__UD_L23_HDR_BCNT__WIDTH                              6
#define INB_PKT_MSG_QW5__UD_L23_HDR_BCNT__MASK                        0xfc0000
#define INB_PKT_MSG_QW5__UD_L23_HDR_BCNT__RESET_VALUE                      0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT
#define INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT__MSB                             17
#define INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT__LSB                             13
#define INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT__WIDTH                            5
#define INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT__MASK                       0x3e000
#define INB_PKT_MSG_QW5__MINIPO_REMAIN_CNT__RESET_VALUE                    0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__RTT_VLD
#define INB_PKT_MSG_QW5__RTT_VLD__MSB                                       12
#define INB_PKT_MSG_QW5__RTT_VLD__LSB                                       12
#define INB_PKT_MSG_QW5__RTT_VLD__WIDTH                                      1
#define INB_PKT_MSG_QW5__RTT_VLD__MASK                                  0x1000
#define INB_PKT_MSG_QW5__RTT_VLD__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__PMTU
#define INB_PKT_MSG_QW5__PMTU__MSB                                          11
#define INB_PKT_MSG_QW5__PMTU__LSB                                           9
#define INB_PKT_MSG_QW5__PMTU__WIDTH                                         3
#define INB_PKT_MSG_QW5__PMTU__MASK                                      0xe00
#define INB_PKT_MSG_QW5__PMTU__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW5__RQE_PREFETCH_CNT
#define INB_PKT_MSG_QW5__RQE_PREFETCH_CNT__MSB                               3
#define INB_PKT_MSG_QW5__RQE_PREFETCH_CNT__LSB                               0
#define INB_PKT_MSG_QW5__RQE_PREFETCH_CNT__WIDTH                             4
#define INB_PKT_MSG_QW5__RQE_PREFETCH_CNT__MASK                            0xf
#define INB_PKT_MSG_QW5__RQE_PREFETCH_CNT__RESET_VALUE                     0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW6
typedef union {
  struct {
    u64 immediate      : 32;
    u64 total_pyld_len : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW6;
//-----MACRO defines for Message:INB_PKT_MSG_QW6

//-----MACRO defines for fields:INB_PKT_MSG_QW6__TOTAL_PYLD_LEN
#define INB_PKT_MSG_QW6__TOTAL_PYLD_LEN__MSB                                63
#define INB_PKT_MSG_QW6__TOTAL_PYLD_LEN__LSB                                32
#define INB_PKT_MSG_QW6__TOTAL_PYLD_LEN__WIDTH                              32
#define INB_PKT_MSG_QW6__TOTAL_PYLD_LEN__MASK               0xffffffff00000000
#define INB_PKT_MSG_QW6__TOTAL_PYLD_LEN__RESET_VALUE                       0x0

//-----MACRO defines for fields:INB_PKT_MSG_QW6__IMMEDIATE
#define INB_PKT_MSG_QW6__IMMEDIATE__MSB                                     31
#define INB_PKT_MSG_QW6__IMMEDIATE__LSB                                      0
#define INB_PKT_MSG_QW6__IMMEDIATE__WIDTH                                   32
#define INB_PKT_MSG_QW6__IMMEDIATE__MASK                            0xffffffff
#define INB_PKT_MSG_QW6__IMMEDIATE__RESET_VALUE                            0x0

//-----Access structure typedef for Message:INB_PKT_MSG_QW7
typedef union {
  struct {
    u64 l23_hdr : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_PKT_MSG_QW7;
//-----MACRO defines for Message:INB_PKT_MSG_QW7

//-----MACRO defines for fields:INB_PKT_MSG_QW7__L23_HDR
#define INB_PKT_MSG_QW7__L23_HDR__MSB                                       63
#define INB_PKT_MSG_QW7__L23_HDR__LSB                                        0
#define INB_PKT_MSG_QW7__L23_HDR__WIDTH                                     64
#define INB_PKT_MSG_QW7__L23_HDR__MASK                      0xffffffffffffffff
#define INB_PKT_MSG_QW7__L23_HDR__RESET_VALUE                              0x0

typedef struct {
  INB_PKT_MSG_QW0  qw0;
  INB_PKT_MSG_QW1  qw1;
  INB_PKT_MSG_QW2  qw2;
  INB_PKT_MSG_QW3  qw3;
  INB_PKT_MSG_QW4  qw4;
  INB_PKT_MSG_QW5  qw5;
  INB_PKT_MSG_QW6  qw6;
  INB_PKT_MSG_QW7  qw7;
} INB_PKT_MSG;
//QW_CNT is actual number - 1
#define INB_PKT_MSG_QW_CNT                                                   7
//-----MACRO defines for  Message Group INB_NAK_MSG: 0x180000
#define INB_NAK_MSG_MSG_ID                                                0x18
//-----Access structure typedef for Message:INB_NAK_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_NAK_MSG_QW0;
//-----MACRO defines for Message:INB_NAK_MSG_QW0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__FPM
#define INB_NAK_MSG_QW0__FPM__MSB                                           58
#define INB_NAK_MSG_QW0__FPM__LSB                                           49
#define INB_NAK_MSG_QW0__FPM__WIDTH                                         10
#define INB_NAK_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define INB_NAK_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__QPN
#define INB_NAK_MSG_QW0__QPN__MSB                                           48
#define INB_NAK_MSG_QW0__QPN__LSB                                           32
#define INB_NAK_MSG_QW0__QPN__WIDTH                                         17
#define INB_NAK_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define INB_NAK_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__MSG_ID
#define INB_NAK_MSG_QW0__MSG_ID__MSB                                        31
#define INB_NAK_MSG_QW0__MSG_ID__LSB                                        24
#define INB_NAK_MSG_QW0__MSG_ID__WIDTH                                       8
#define INB_NAK_MSG_QW0__MSG_ID__MASK                               0xff000000
#define INB_NAK_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__REQ_TAG
#define INB_NAK_MSG_QW0__REQ_TAG__MSB                                       23
#define INB_NAK_MSG_QW0__REQ_TAG__LSB                                       16
#define INB_NAK_MSG_QW0__REQ_TAG__WIDTH                                      8
#define INB_NAK_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define INB_NAK_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__SRC
#define INB_NAK_MSG_QW0__SRC__MSB                                           15
#define INB_NAK_MSG_QW0__SRC__LSB                                           12
#define INB_NAK_MSG_QW0__SRC__WIDTH                                          4
#define INB_NAK_MSG_QW0__SRC__MASK                                      0xf000
#define INB_NAK_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__DST
#define INB_NAK_MSG_QW0__DST__MSB                                           11
#define INB_NAK_MSG_QW0__DST__LSB                                           10
#define INB_NAK_MSG_QW0__DST__WIDTH                                          2
#define INB_NAK_MSG_QW0__DST__MASK                                       0xc00
#define INB_NAK_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__DSTFIFO
#define INB_NAK_MSG_QW0__DSTFIFO__MSB                                        9
#define INB_NAK_MSG_QW0__DSTFIFO__LSB                                        6
#define INB_NAK_MSG_QW0__DSTFIFO__WIDTH                                      4
#define INB_NAK_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define INB_NAK_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW0__CNT
#define INB_NAK_MSG_QW0__CNT__MSB                                            5
#define INB_NAK_MSG_QW0__CNT__LSB                                            0
#define INB_NAK_MSG_QW0__CNT__WIDTH                                          6
#define INB_NAK_MSG_QW0__CNT__MASK                                        0x3f
#define INB_NAK_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:INB_NAK_MSG_QW1
typedef union {
  struct {
    u64 bth_dw0 : 32;
    u64 bth_dw1 : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_NAK_MSG_QW1;
//-----MACRO defines for Message:INB_NAK_MSG_QW1

//-----MACRO defines for fields:INB_NAK_MSG_QW1__BTH_DW1
#define INB_NAK_MSG_QW1__BTH_DW1__MSB                                       63
#define INB_NAK_MSG_QW1__BTH_DW1__LSB                                       32
#define INB_NAK_MSG_QW1__BTH_DW1__WIDTH                                     32
#define INB_NAK_MSG_QW1__BTH_DW1__MASK                      0xffffffff00000000
#define INB_NAK_MSG_QW1__BTH_DW1__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW1__BTH_DW0
#define INB_NAK_MSG_QW1__BTH_DW0__MSB                                       31
#define INB_NAK_MSG_QW1__BTH_DW0__LSB                                        0
#define INB_NAK_MSG_QW1__BTH_DW0__WIDTH                                     32
#define INB_NAK_MSG_QW1__BTH_DW0__MASK                              0xffffffff
#define INB_NAK_MSG_QW1__BTH_DW0__RESET_VALUE                              0x0

//-----Access structure typedef for Message:INB_NAK_MSG_QW2
typedef union {
  struct {
    u64 bth_dw2 : 32;
    u64 aeth    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_NAK_MSG_QW2;
//-----MACRO defines for Message:INB_NAK_MSG_QW2

//-----MACRO defines for fields:INB_NAK_MSG_QW2__AETH
#define INB_NAK_MSG_QW2__AETH__MSB                                          63
#define INB_NAK_MSG_QW2__AETH__LSB                                          32
#define INB_NAK_MSG_QW2__AETH__WIDTH                                        32
#define INB_NAK_MSG_QW2__AETH__MASK                         0xffffffff00000000
#define INB_NAK_MSG_QW2__AETH__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_NAK_MSG_QW2__BTH_DW2
#define INB_NAK_MSG_QW2__BTH_DW2__MSB                                       31
#define INB_NAK_MSG_QW2__BTH_DW2__LSB                                        0
#define INB_NAK_MSG_QW2__BTH_DW2__WIDTH                                     32
#define INB_NAK_MSG_QW2__BTH_DW2__MASK                              0xffffffff
#define INB_NAK_MSG_QW2__BTH_DW2__RESET_VALUE                              0x0

typedef struct {
  INB_NAK_MSG_QW0  qw0;
  INB_NAK_MSG_QW1  qw1;
  INB_NAK_MSG_QW2  qw2;
} INB_NAK_MSG;
//QW_CNT is actual number - 1
#define INB_NAK_MSG_QW_CNT                                                   2
//-----MACRO defines for  Message Group INB_CNP_MSG: 0x190000
#define INB_CNP_MSG_MSG_ID                                                0x19
//-----Access structure typedef for Message:INB_CNP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 6;
    u64 qset    : 9;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_CNP_MSG_QW0;
//-----MACRO defines for Message:INB_CNP_MSG_QW0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__QSET
#define INB_CNP_MSG_QW0__QSET__MSB                                          63
#define INB_CNP_MSG_QW0__QSET__LSB                                          55
#define INB_CNP_MSG_QW0__QSET__WIDTH                                         9
#define INB_CNP_MSG_QW0__QSET__MASK                         0xff80000000000000
#define INB_CNP_MSG_QW0__QSET__RESET_VALUE                                 0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__FPM
#define INB_CNP_MSG_QW0__FPM__MSB                                           54
#define INB_CNP_MSG_QW0__FPM__LSB                                           49
#define INB_CNP_MSG_QW0__FPM__WIDTH                                          6
#define INB_CNP_MSG_QW0__FPM__MASK                            0x7e000000000000
#define INB_CNP_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__QPN
#define INB_CNP_MSG_QW0__QPN__MSB                                           48
#define INB_CNP_MSG_QW0__QPN__LSB                                           32
#define INB_CNP_MSG_QW0__QPN__WIDTH                                         17
#define INB_CNP_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define INB_CNP_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__MSG_ID
#define INB_CNP_MSG_QW0__MSG_ID__MSB                                        31
#define INB_CNP_MSG_QW0__MSG_ID__LSB                                        24
#define INB_CNP_MSG_QW0__MSG_ID__WIDTH                                       8
#define INB_CNP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define INB_CNP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__REQ_TAG
#define INB_CNP_MSG_QW0__REQ_TAG__MSB                                       23
#define INB_CNP_MSG_QW0__REQ_TAG__LSB                                       16
#define INB_CNP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define INB_CNP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define INB_CNP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__SRC
#define INB_CNP_MSG_QW0__SRC__MSB                                           15
#define INB_CNP_MSG_QW0__SRC__LSB                                           12
#define INB_CNP_MSG_QW0__SRC__WIDTH                                          4
#define INB_CNP_MSG_QW0__SRC__MASK                                      0xf000
#define INB_CNP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__DST
#define INB_CNP_MSG_QW0__DST__MSB                                           11
#define INB_CNP_MSG_QW0__DST__LSB                                           10
#define INB_CNP_MSG_QW0__DST__WIDTH                                          2
#define INB_CNP_MSG_QW0__DST__MASK                                       0xc00
#define INB_CNP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__DSTFIFO
#define INB_CNP_MSG_QW0__DSTFIFO__MSB                                        9
#define INB_CNP_MSG_QW0__DSTFIFO__LSB                                        6
#define INB_CNP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define INB_CNP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define INB_CNP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_CNP_MSG_QW0__CNT
#define INB_CNP_MSG_QW0__CNT__MSB                                            5
#define INB_CNP_MSG_QW0__CNT__LSB                                            0
#define INB_CNP_MSG_QW0__CNT__WIDTH                                          6
#define INB_CNP_MSG_QW0__CNT__MASK                                        0x3f
#define INB_CNP_MSG_QW0__CNT__RESET_VALUE                                  0x0

typedef struct {
  INB_CNP_MSG_QW0  qw0;
} INB_CNP_MSG;
//QW_CNT is actual number - 1
#define INB_CNP_MSG_QW_CNT                                                   0
//-----MACRO defines for  Message Group INB_ECN_MSG: 0x1a0000
#define INB_ECN_MSG_MSG_ID                                                0x1a
//-----Access structure typedef for Message:INB_ECN_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_ECN_MSG_QW0;
//-----MACRO defines for Message:INB_ECN_MSG_QW0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__FPM
#define INB_ECN_MSG_QW0__FPM__MSB                                           58
#define INB_ECN_MSG_QW0__FPM__LSB                                           49
#define INB_ECN_MSG_QW0__FPM__WIDTH                                         10
#define INB_ECN_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define INB_ECN_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__QPN
#define INB_ECN_MSG_QW0__QPN__MSB                                           48
#define INB_ECN_MSG_QW0__QPN__LSB                                           32
#define INB_ECN_MSG_QW0__QPN__WIDTH                                         17
#define INB_ECN_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define INB_ECN_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__MSG_ID
#define INB_ECN_MSG_QW0__MSG_ID__MSB                                        31
#define INB_ECN_MSG_QW0__MSG_ID__LSB                                        24
#define INB_ECN_MSG_QW0__MSG_ID__WIDTH                                       8
#define INB_ECN_MSG_QW0__MSG_ID__MASK                               0xff000000
#define INB_ECN_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__REQ_TAG
#define INB_ECN_MSG_QW0__REQ_TAG__MSB                                       23
#define INB_ECN_MSG_QW0__REQ_TAG__LSB                                       16
#define INB_ECN_MSG_QW0__REQ_TAG__WIDTH                                      8
#define INB_ECN_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define INB_ECN_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__SRC
#define INB_ECN_MSG_QW0__SRC__MSB                                           15
#define INB_ECN_MSG_QW0__SRC__LSB                                           12
#define INB_ECN_MSG_QW0__SRC__WIDTH                                          4
#define INB_ECN_MSG_QW0__SRC__MASK                                      0xf000
#define INB_ECN_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__DST
#define INB_ECN_MSG_QW0__DST__MSB                                           11
#define INB_ECN_MSG_QW0__DST__LSB                                           10
#define INB_ECN_MSG_QW0__DST__WIDTH                                          2
#define INB_ECN_MSG_QW0__DST__MASK                                       0xc00
#define INB_ECN_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__DSTFIFO
#define INB_ECN_MSG_QW0__DSTFIFO__MSB                                        9
#define INB_ECN_MSG_QW0__DSTFIFO__LSB                                        6
#define INB_ECN_MSG_QW0__DSTFIFO__WIDTH                                      4
#define INB_ECN_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define INB_ECN_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW0__CNT
#define INB_ECN_MSG_QW0__CNT__MSB                                            5
#define INB_ECN_MSG_QW0__CNT__LSB                                            0
#define INB_ECN_MSG_QW0__CNT__WIDTH                                          6
#define INB_ECN_MSG_QW0__CNT__MASK                                        0x3f
#define INB_ECN_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:INB_ECN_MSG_QW1
typedef union {
  struct {
    u64 dscp     : 8;
    u64 ecn      : 2;
    u64 rsvd0    : 6;
    u64 vlan_pri : 3;
    u64 rsvd1    : 45;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INB_ECN_MSG_QW1;
//-----MACRO defines for Message:INB_ECN_MSG_QW1

//-----MACRO defines for fields:INB_ECN_MSG_QW1__VLAN_PRI
#define INB_ECN_MSG_QW1__VLAN_PRI__MSB                                      18
#define INB_ECN_MSG_QW1__VLAN_PRI__LSB                                      16
#define INB_ECN_MSG_QW1__VLAN_PRI__WIDTH                                     3
#define INB_ECN_MSG_QW1__VLAN_PRI__MASK                                0x70000
#define INB_ECN_MSG_QW1__VLAN_PRI__RESET_VALUE                             0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW1__ECN
#define INB_ECN_MSG_QW1__ECN__MSB                                            9
#define INB_ECN_MSG_QW1__ECN__LSB                                            8
#define INB_ECN_MSG_QW1__ECN__WIDTH                                          2
#define INB_ECN_MSG_QW1__ECN__MASK                                       0x300
#define INB_ECN_MSG_QW1__ECN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INB_ECN_MSG_QW1__DSCP
#define INB_ECN_MSG_QW1__DSCP__MSB                                           7
#define INB_ECN_MSG_QW1__DSCP__LSB                                           0
#define INB_ECN_MSG_QW1__DSCP__WIDTH                                         8
#define INB_ECN_MSG_QW1__DSCP__MASK                                       0xff
#define INB_ECN_MSG_QW1__DSCP__RESET_VALUE                                 0x0

typedef struct {
  INB_ECN_MSG_QW0  qw0;
  INB_ECN_MSG_QW1  qw1;
} INB_ECN_MSG;
//QW_CNT is actual number - 1
#define INB_ECN_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group INV_MSG: 0x1b0000
#define INV_MSG_MSG_ID                                                    0x1b
//-----Access structure typedef for Message:INV_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INV_MSG_QW0;
//-----MACRO defines for Message:INV_MSG_QW0

//-----MACRO defines for fields:INV_MSG_QW0__FPM
#define INV_MSG_QW0__FPM__MSB                                               58
#define INV_MSG_QW0__FPM__LSB                                               49
#define INV_MSG_QW0__FPM__WIDTH                                             10
#define INV_MSG_QW0__FPM__MASK                               0x7fe000000000000
#define INV_MSG_QW0__FPM__RESET_VALUE                                      0x0

//-----MACRO defines for fields:INV_MSG_QW0__QPN
#define INV_MSG_QW0__QPN__MSB                                               48
#define INV_MSG_QW0__QPN__LSB                                               32
#define INV_MSG_QW0__QPN__WIDTH                                             17
#define INV_MSG_QW0__QPN__MASK                                 0x1ffff00000000
#define INV_MSG_QW0__QPN__RESET_VALUE                                      0x0

//-----MACRO defines for fields:INV_MSG_QW0__MSG_ID
#define INV_MSG_QW0__MSG_ID__MSB                                            31
#define INV_MSG_QW0__MSG_ID__LSB                                            24
#define INV_MSG_QW0__MSG_ID__WIDTH                                           8
#define INV_MSG_QW0__MSG_ID__MASK                                   0xff000000
#define INV_MSG_QW0__MSG_ID__RESET_VALUE                                   0x0

//-----MACRO defines for fields:INV_MSG_QW0__REQ_TAG
#define INV_MSG_QW0__REQ_TAG__MSB                                           23
#define INV_MSG_QW0__REQ_TAG__LSB                                           16
#define INV_MSG_QW0__REQ_TAG__WIDTH                                          8
#define INV_MSG_QW0__REQ_TAG__MASK                                    0xff0000
#define INV_MSG_QW0__REQ_TAG__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INV_MSG_QW0__SRC
#define INV_MSG_QW0__SRC__MSB                                               15
#define INV_MSG_QW0__SRC__LSB                                               12
#define INV_MSG_QW0__SRC__WIDTH                                              4
#define INV_MSG_QW0__SRC__MASK                                          0xf000
#define INV_MSG_QW0__SRC__RESET_VALUE                                      0x0

//-----MACRO defines for fields:INV_MSG_QW0__DST
#define INV_MSG_QW0__DST__MSB                                               11
#define INV_MSG_QW0__DST__LSB                                               10
#define INV_MSG_QW0__DST__WIDTH                                              2
#define INV_MSG_QW0__DST__MASK                                           0xc00
#define INV_MSG_QW0__DST__RESET_VALUE                                      0x0

//-----MACRO defines for fields:INV_MSG_QW0__DSTFIFO
#define INV_MSG_QW0__DSTFIFO__MSB                                            9
#define INV_MSG_QW0__DSTFIFO__LSB                                            6
#define INV_MSG_QW0__DSTFIFO__WIDTH                                          4
#define INV_MSG_QW0__DSTFIFO__MASK                                       0x3c0
#define INV_MSG_QW0__DSTFIFO__RESET_VALUE                                  0x0

//-----MACRO defines for fields:INV_MSG_QW0__CNT
#define INV_MSG_QW0__CNT__MSB                                                5
#define INV_MSG_QW0__CNT__LSB                                                0
#define INV_MSG_QW0__CNT__WIDTH                                              6
#define INV_MSG_QW0__CNT__MASK                                            0x3f
#define INV_MSG_QW0__CNT__RESET_VALUE                                      0x0

//-----Access structure typedef for Message:INV_MSG_QW1
typedef union {
  struct {
    u64 rsvd0 : 32;
    u64 stag  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} INV_MSG_QW1;
//-----MACRO defines for Message:INV_MSG_QW1

//-----MACRO defines for fields:INV_MSG_QW1__STAG
#define INV_MSG_QW1__STAG__MSB                                              63
#define INV_MSG_QW1__STAG__LSB                                              32
#define INV_MSG_QW1__STAG__WIDTH                                            32
#define INV_MSG_QW1__STAG__MASK                             0xffffffff00000000
#define INV_MSG_QW1__STAG__RESET_VALUE                                     0x0

typedef struct {
  INV_MSG_QW0  qw0;
  INV_MSG_QW1  qw1;
} INV_MSG;
//QW_CNT is actual number - 1
#define INV_MSG_QW_CNT                                                       1
//-----MACRO defines for  Message Group RQE_REQ_MSG: 0x1c0000
#define RQE_REQ_MSG_MSG_ID                                                0x1c
//-----Access structure typedef for Message:RQE_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt              : 6;
    u64 dstfifo          : 4;
    u64 dst              : 2;
    u64 src              : 4;
    u64 req_tag          : 8;
    u64 msg_id           : 8;
    u64 qpn              : 17;
    u64 fpm              : 6;
    u64 rqe_prefetch_cnt : 4;
    u64 pop              : 1;
    u64 rsvd0            : 1;
    u64 rc_type          : 1;
    u64 rsvd1            : 2;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQE_REQ_MSG_QW0;
//-----MACRO defines for Message:RQE_REQ_MSG_QW0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__RC_TYPE
#define RQE_REQ_MSG_QW0__RC_TYPE__MSB                                       61
#define RQE_REQ_MSG_QW0__RC_TYPE__LSB                                       61
#define RQE_REQ_MSG_QW0__RC_TYPE__WIDTH                                      1
#define RQE_REQ_MSG_QW0__RC_TYPE__MASK                      0x2000000000000000
#define RQE_REQ_MSG_QW0__RC_TYPE__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__POP
#define RQE_REQ_MSG_QW0__POP__MSB                                           59
#define RQE_REQ_MSG_QW0__POP__LSB                                           59
#define RQE_REQ_MSG_QW0__POP__WIDTH                                          1
#define RQE_REQ_MSG_QW0__POP__MASK                           0x800000000000000
#define RQE_REQ_MSG_QW0__POP__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT
#define RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT__MSB                              58
#define RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT__LSB                              55
#define RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT__WIDTH                             4
#define RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT__MASK              0x780000000000000
#define RQE_REQ_MSG_QW0__RQE_PREFETCH_CNT__RESET_VALUE                     0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__FPM
#define RQE_REQ_MSG_QW0__FPM__MSB                                           54
#define RQE_REQ_MSG_QW0__FPM__LSB                                           49
#define RQE_REQ_MSG_QW0__FPM__WIDTH                                          6
#define RQE_REQ_MSG_QW0__FPM__MASK                            0x7e000000000000
#define RQE_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__QPN
#define RQE_REQ_MSG_QW0__QPN__MSB                                           48
#define RQE_REQ_MSG_QW0__QPN__LSB                                           32
#define RQE_REQ_MSG_QW0__QPN__WIDTH                                         17
#define RQE_REQ_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define RQE_REQ_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__MSG_ID
#define RQE_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define RQE_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define RQE_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define RQE_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define RQE_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__REQ_TAG
#define RQE_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define RQE_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define RQE_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define RQE_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define RQE_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__SRC
#define RQE_REQ_MSG_QW0__SRC__MSB                                           15
#define RQE_REQ_MSG_QW0__SRC__LSB                                           12
#define RQE_REQ_MSG_QW0__SRC__WIDTH                                          4
#define RQE_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define RQE_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__DST
#define RQE_REQ_MSG_QW0__DST__MSB                                           11
#define RQE_REQ_MSG_QW0__DST__LSB                                           10
#define RQE_REQ_MSG_QW0__DST__WIDTH                                          2
#define RQE_REQ_MSG_QW0__DST__MASK                                       0xc00
#define RQE_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__DSTFIFO
#define RQE_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define RQE_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define RQE_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define RQE_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define RQE_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_REQ_MSG_QW0__CNT
#define RQE_REQ_MSG_QW0__CNT__MSB                                            5
#define RQE_REQ_MSG_QW0__CNT__LSB                                            0
#define RQE_REQ_MSG_QW0__CNT__WIDTH                                          6
#define RQE_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define RQE_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

typedef struct {
  RQE_REQ_MSG_QW0  qw0;
} RQE_REQ_MSG;
//QW_CNT is actual number - 1
#define RQE_REQ_MSG_QW_CNT                                                   0
//-----MACRO defines for  Message Group RQE_RSP_MSG: 0x1d0000
#define RQE_RSP_MSG_MSG_ID                                                0x1d
//-----Access structure typedef for Message:RQE_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQE_RSP_MSG_QW0;
//-----MACRO defines for Message:RQE_RSP_MSG_QW0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__STA
#define RQE_RSP_MSG_QW0__STA__MSB                                           63
#define RQE_RSP_MSG_QW0__STA__LSB                                           60
#define RQE_RSP_MSG_QW0__STA__WIDTH                                          4
#define RQE_RSP_MSG_QW0__STA__MASK                          0xf000000000000000
#define RQE_RSP_MSG_QW0__STA__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__MSG_ID
#define RQE_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define RQE_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define RQE_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define RQE_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define RQE_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__REQ_TAG
#define RQE_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define RQE_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define RQE_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define RQE_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define RQE_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__SRC
#define RQE_RSP_MSG_QW0__SRC__MSB                                           15
#define RQE_RSP_MSG_QW0__SRC__LSB                                           12
#define RQE_RSP_MSG_QW0__SRC__WIDTH                                          4
#define RQE_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define RQE_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__DST
#define RQE_RSP_MSG_QW0__DST__MSB                                           11
#define RQE_RSP_MSG_QW0__DST__LSB                                           10
#define RQE_RSP_MSG_QW0__DST__WIDTH                                          2
#define RQE_RSP_MSG_QW0__DST__MASK                                       0xc00
#define RQE_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__DSTFIFO
#define RQE_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define RQE_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define RQE_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define RQE_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define RQE_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW0__CNT
#define RQE_RSP_MSG_QW0__CNT__MSB                                            5
#define RQE_RSP_MSG_QW0__CNT__LSB                                            0
#define RQE_RSP_MSG_QW0__CNT__WIDTH                                          6
#define RQE_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define RQE_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:RQE_RSP_MSG_QW1
typedef union {
  struct {
    u64 rsvd0            : 38;
    u64 add_fragment_cnt : 4;
    u64 wq_desc_idx      : 15;
    u64 rsvd1            : 6;
    u64 wqe_vld          : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RQE_RSP_MSG_QW1;
//-----MACRO defines for Message:RQE_RSP_MSG_QW1

//-----MACRO defines for fields:RQE_RSP_MSG_QW1__WQE_VLD
#define RQE_RSP_MSG_QW1__WQE_VLD__MSB                                       63
#define RQE_RSP_MSG_QW1__WQE_VLD__LSB                                       63
#define RQE_RSP_MSG_QW1__WQE_VLD__WIDTH                                      1
#define RQE_RSP_MSG_QW1__WQE_VLD__MASK                      0x8000000000000000
#define RQE_RSP_MSG_QW1__WQE_VLD__RESET_VALUE                              0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW1__WQ_DESC_IDX
#define RQE_RSP_MSG_QW1__WQ_DESC_IDX__MSB                                   56
#define RQE_RSP_MSG_QW1__WQ_DESC_IDX__LSB                                   42
#define RQE_RSP_MSG_QW1__WQ_DESC_IDX__WIDTH                                 15
#define RQE_RSP_MSG_QW1__WQ_DESC_IDX__MASK                   0x1fffc0000000000
#define RQE_RSP_MSG_QW1__WQ_DESC_IDX__RESET_VALUE                          0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT
#define RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT__MSB                              41
#define RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT__LSB                              38
#define RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT__WIDTH                             4
#define RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT__MASK                  0x3c000000000
#define RQE_RSP_MSG_QW1__ADD_FRAGMENT_CNT__RESET_VALUE                     0x0

//-----Access structure typedef for Message:RQE_RSP_MSG_QW2
typedef union {
  struct {
    u128 tagged_offset  : 64;
    u128 key            : 32;
    u128 fragment_len   : 31;
    u128 fragment_valid : 1;
  };
  u128 reg;
} RQE_RSP_MSG_QW2;
//-----MACRO defines for Message:RQE_RSP_MSG_QW2

//-----MACRO defines for fields:RQE_RSP_MSG_QW2__FRAGMENT_VALID
#define RQE_RSP_MSG_QW2__FRAGMENT_VALID__MSB                               127
#define RQE_RSP_MSG_QW2__FRAGMENT_VALID__LSB                               127
#define RQE_RSP_MSG_QW2__FRAGMENT_VALID__WIDTH                               1
#define RQE_RSP_MSG_QW2__FRAGMENT_VALID__MASK 0x80000000000000000000000000000000
#define RQE_RSP_MSG_QW2__FRAGMENT_VALID__RESET_VALUE                       0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW2__FRAGMENT_LEN
#define RQE_RSP_MSG_QW2__FRAGMENT_LEN__MSB                                 126
#define RQE_RSP_MSG_QW2__FRAGMENT_LEN__LSB                                  96
#define RQE_RSP_MSG_QW2__FRAGMENT_LEN__WIDTH                                31
#define RQE_RSP_MSG_QW2__FRAGMENT_LEN__MASK 0x7fffffff000000000000000000000000
#define RQE_RSP_MSG_QW2__FRAGMENT_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW2__KEY
#define RQE_RSP_MSG_QW2__KEY__MSB                                           95
#define RQE_RSP_MSG_QW2__KEY__LSB                                           64
#define RQE_RSP_MSG_QW2__KEY__WIDTH                                         32
#define RQE_RSP_MSG_QW2__KEY__MASK                  0xffffffff0000000000000000
#define RQE_RSP_MSG_QW2__KEY__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RQE_RSP_MSG_QW2__TAGGED_OFFSET
#define RQE_RSP_MSG_QW2__TAGGED_OFFSET__MSB                                 63
#define RQE_RSP_MSG_QW2__TAGGED_OFFSET__LSB                                  0
#define RQE_RSP_MSG_QW2__TAGGED_OFFSET__WIDTH                               64
#define RQE_RSP_MSG_QW2__TAGGED_OFFSET__MASK                0xffffffffffffffff
#define RQE_RSP_MSG_QW2__TAGGED_OFFSET__RESET_VALUE                        0x0

typedef struct {
  RQE_RSP_MSG_QW0  qw0;
  RQE_RSP_MSG_QW1  qw1;
  RQE_RSP_MSG_QW2  qw2;
} RQE_RSP_MSG;
//QW_CNT is actual number - 1
#define RQE_RSP_MSG_QW_CNT                                                   2
//-----MACRO defines for  Message Group POP_PKT_MSG: 0x1e0000
#define POP_PKT_MSG_MSG_ID                                                0x1e
//-----Access structure typedef for Message:POP_PKT_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POP_PKT_MSG_QW0;
//-----MACRO defines for Message:POP_PKT_MSG_QW0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__MSG_ID
#define POP_PKT_MSG_QW0__MSG_ID__MSB                                        31
#define POP_PKT_MSG_QW0__MSG_ID__LSB                                        24
#define POP_PKT_MSG_QW0__MSG_ID__WIDTH                                       8
#define POP_PKT_MSG_QW0__MSG_ID__MASK                               0xff000000
#define POP_PKT_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__REQ_TAG
#define POP_PKT_MSG_QW0__REQ_TAG__MSB                                       23
#define POP_PKT_MSG_QW0__REQ_TAG__LSB                                       16
#define POP_PKT_MSG_QW0__REQ_TAG__WIDTH                                      8
#define POP_PKT_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define POP_PKT_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__SRC
#define POP_PKT_MSG_QW0__SRC__MSB                                           15
#define POP_PKT_MSG_QW0__SRC__LSB                                           12
#define POP_PKT_MSG_QW0__SRC__WIDTH                                          4
#define POP_PKT_MSG_QW0__SRC__MASK                                      0xf000
#define POP_PKT_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__DST
#define POP_PKT_MSG_QW0__DST__MSB                                           11
#define POP_PKT_MSG_QW0__DST__LSB                                           10
#define POP_PKT_MSG_QW0__DST__WIDTH                                          2
#define POP_PKT_MSG_QW0__DST__MASK                                       0xc00
#define POP_PKT_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__DSTFIFO
#define POP_PKT_MSG_QW0__DSTFIFO__MSB                                        9
#define POP_PKT_MSG_QW0__DSTFIFO__LSB                                        6
#define POP_PKT_MSG_QW0__DSTFIFO__WIDTH                                      4
#define POP_PKT_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define POP_PKT_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW0__CNT
#define POP_PKT_MSG_QW0__CNT__MSB                                            5
#define POP_PKT_MSG_QW0__CNT__LSB                                            0
#define POP_PKT_MSG_QW0__CNT__WIDTH                                          6
#define POP_PKT_MSG_QW0__CNT__MASK                                        0x3f
#define POP_PKT_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:POP_PKT_MSG_QW1
typedef union {
  struct {
    u64 pyld_ofst     : 5;
    u64 start_d1_idx  : 2;
    u64 pld_start_buf : 13;
    u64 rsvd0         : 44;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POP_PKT_MSG_QW1;
//-----MACRO defines for Message:POP_PKT_MSG_QW1

//-----MACRO defines for fields:POP_PKT_MSG_QW1__PLD_START_BUF
#define POP_PKT_MSG_QW1__PLD_START_BUF__MSB                                 19
#define POP_PKT_MSG_QW1__PLD_START_BUF__LSB                                  7
#define POP_PKT_MSG_QW1__PLD_START_BUF__WIDTH                               13
#define POP_PKT_MSG_QW1__PLD_START_BUF__MASK                           0xfff80
#define POP_PKT_MSG_QW1__PLD_START_BUF__RESET_VALUE                        0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW1__START_D1_IDX
#define POP_PKT_MSG_QW1__START_D1_IDX__MSB                                   6
#define POP_PKT_MSG_QW1__START_D1_IDX__LSB                                   5
#define POP_PKT_MSG_QW1__START_D1_IDX__WIDTH                                 2
#define POP_PKT_MSG_QW1__START_D1_IDX__MASK                               0x60
#define POP_PKT_MSG_QW1__START_D1_IDX__RESET_VALUE                         0x0

//-----MACRO defines for fields:POP_PKT_MSG_QW1__PYLD_OFST
#define POP_PKT_MSG_QW1__PYLD_OFST__MSB                                      4
#define POP_PKT_MSG_QW1__PYLD_OFST__LSB                                      0
#define POP_PKT_MSG_QW1__PYLD_OFST__WIDTH                                    5
#define POP_PKT_MSG_QW1__PYLD_OFST__MASK                                  0x1f
#define POP_PKT_MSG_QW1__PYLD_OFST__RESET_VALUE                            0x0

typedef struct {
  POP_PKT_MSG_QW0  qw0;
  POP_PKT_MSG_QW1  qw1;
} POP_PKT_MSG;
//QW_CNT is actual number - 1
#define POP_PKT_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group PRE_SEG_MSG: 0x1f0000
#define PRE_SEG_MSG_MSG_ID                                                0x1f
//-----Access structure typedef for Message:PRE_SEG_MSG_QW0
typedef union {
  struct {
    u64 qpn      : 17;
    u64 fpm      : 10;
    u64 seg_cnt  : 5;
    u64 rsvd0    : 1;
    u64 qp_type  : 3;
    u64 msg_type : 2;
    u64 pmtu     : 3;
    u64 dst_qpn  : 17;
    u64 rsvd1    : 6;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW0;
//-----MACRO defines for Message:PRE_SEG_MSG_QW0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__DST_QPN
#define PRE_SEG_MSG_QW0__DST_QPN__MSB                                       57
#define PRE_SEG_MSG_QW0__DST_QPN__LSB                                       41
#define PRE_SEG_MSG_QW0__DST_QPN__WIDTH                                     17
#define PRE_SEG_MSG_QW0__DST_QPN__MASK                       0x3fffe0000000000
#define PRE_SEG_MSG_QW0__DST_QPN__RESET_VALUE                              0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__PMTU
#define PRE_SEG_MSG_QW0__PMTU__MSB                                          40
#define PRE_SEG_MSG_QW0__PMTU__LSB                                          38
#define PRE_SEG_MSG_QW0__PMTU__WIDTH                                         3
#define PRE_SEG_MSG_QW0__PMTU__MASK                              0x1c000000000
#define PRE_SEG_MSG_QW0__PMTU__RESET_VALUE                                 0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__MSG_TYPE
#define PRE_SEG_MSG_QW0__MSG_TYPE__MSB                                      37
#define PRE_SEG_MSG_QW0__MSG_TYPE__LSB                                      36
#define PRE_SEG_MSG_QW0__MSG_TYPE__WIDTH                                     2
#define PRE_SEG_MSG_QW0__MSG_TYPE__MASK                           0x3000000000
#define PRE_SEG_MSG_QW0__MSG_TYPE__RESET_VALUE                             0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__QP_TYPE
#define PRE_SEG_MSG_QW0__QP_TYPE__MSB                                       35
#define PRE_SEG_MSG_QW0__QP_TYPE__LSB                                       33
#define PRE_SEG_MSG_QW0__QP_TYPE__WIDTH                                      3
#define PRE_SEG_MSG_QW0__QP_TYPE__MASK                             0xe00000000
#define PRE_SEG_MSG_QW0__QP_TYPE__RESET_VALUE                              0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__SEG_CNT
#define PRE_SEG_MSG_QW0__SEG_CNT__MSB                                       31
#define PRE_SEG_MSG_QW0__SEG_CNT__LSB                                       27
#define PRE_SEG_MSG_QW0__SEG_CNT__WIDTH                                      5
#define PRE_SEG_MSG_QW0__SEG_CNT__MASK                              0xf8000000
#define PRE_SEG_MSG_QW0__SEG_CNT__RESET_VALUE                              0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__FPM
#define PRE_SEG_MSG_QW0__FPM__MSB                                           26
#define PRE_SEG_MSG_QW0__FPM__LSB                                           17
#define PRE_SEG_MSG_QW0__FPM__WIDTH                                         10
#define PRE_SEG_MSG_QW0__FPM__MASK                                   0x7fe0000
#define PRE_SEG_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW0__QPN
#define PRE_SEG_MSG_QW0__QPN__MSB                                           16
#define PRE_SEG_MSG_QW0__QPN__LSB                                            0
#define PRE_SEG_MSG_QW0__QPN__WIDTH                                         17
#define PRE_SEG_MSG_QW0__QPN__MASK                                     0x1ffff
#define PRE_SEG_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW1
typedef union {
  struct {
    u64 init_psn : 24;
    u64 rsvd0    : 8;
    u64 psn_ofst : 24;
    u64 rsvd1    : 8;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW1;
//-----MACRO defines for Message:PRE_SEG_MSG_QW1

//-----MACRO defines for fields:PRE_SEG_MSG_QW1__PSN_OFST
#define PRE_SEG_MSG_QW1__PSN_OFST__MSB                                      55
#define PRE_SEG_MSG_QW1__PSN_OFST__LSB                                      32
#define PRE_SEG_MSG_QW1__PSN_OFST__WIDTH                                    24
#define PRE_SEG_MSG_QW1__PSN_OFST__MASK                       0xffffff00000000
#define PRE_SEG_MSG_QW1__PSN_OFST__RESET_VALUE                             0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW1__INIT_PSN
#define PRE_SEG_MSG_QW1__INIT_PSN__MSB                                      23
#define PRE_SEG_MSG_QW1__INIT_PSN__LSB                                       0
#define PRE_SEG_MSG_QW1__INIT_PSN__WIDTH                                    24
#define PRE_SEG_MSG_QW1__INIT_PSN__MASK                               0xffffff
#define PRE_SEG_MSG_QW1__INIT_PSN__RESET_VALUE                             0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW2
typedef union {
  struct {
    u64 pd_idx : 18;
    u64 rsvd0  : 14;
    u64 key    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW2;
//-----MACRO defines for Message:PRE_SEG_MSG_QW2

//-----MACRO defines for fields:PRE_SEG_MSG_QW2__KEY
#define PRE_SEG_MSG_QW2__KEY__MSB                                           63
#define PRE_SEG_MSG_QW2__KEY__LSB                                           32
#define PRE_SEG_MSG_QW2__KEY__WIDTH                                         32
#define PRE_SEG_MSG_QW2__KEY__MASK                          0xffffffff00000000
#define PRE_SEG_MSG_QW2__KEY__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW2__PD_IDX
#define PRE_SEG_MSG_QW2__PD_IDX__MSB                                        17
#define PRE_SEG_MSG_QW2__PD_IDX__LSB                                         0
#define PRE_SEG_MSG_QW2__PD_IDX__WIDTH                                      18
#define PRE_SEG_MSG_QW2__PD_IDX__MASK                                  0x3ffff
#define PRE_SEG_MSG_QW2__PD_IDX__RESET_VALUE                               0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW3
typedef union {
  struct {
    u64 qw3_tagged_offset : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW3;
//-----MACRO defines for Message:PRE_SEG_MSG_QW3

//-----MACRO defines for fields:PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET
#define PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET__MSB                             63
#define PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET__LSB                              0
#define PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET__WIDTH                           64
#define PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET__MASK            0xffffffffffffffff
#define PRE_SEG_MSG_QW3__QW3_TAGGED_OFFSET__RESET_VALUE                    0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW4
typedef union {
  struct {
    u64 qw4_key          : 32;
    u64 qw4_fragment_len : 31;
    u64 qw4_fragment_vld : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW4;
//-----MACRO defines for Message:PRE_SEG_MSG_QW4

//-----MACRO defines for fields:PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD__MSB                              63
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD__LSB                              63
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD__WIDTH                             1
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD__MASK             0x8000000000000000
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_VLD__RESET_VALUE                     0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN__MSB                              62
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN__LSB                              32
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN__WIDTH                            31
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN__MASK             0x7fffffff00000000
#define PRE_SEG_MSG_QW4__QW4_FRAGMENT_LEN__RESET_VALUE                     0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW4__QW4_KEY
#define PRE_SEG_MSG_QW4__QW4_KEY__MSB                                       31
#define PRE_SEG_MSG_QW4__QW4_KEY__LSB                                        0
#define PRE_SEG_MSG_QW4__QW4_KEY__WIDTH                                     32
#define PRE_SEG_MSG_QW4__QW4_KEY__MASK                              0xffffffff
#define PRE_SEG_MSG_QW4__QW4_KEY__RESET_VALUE                              0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW5
typedef union {
  struct {
    u64 remote_taged_offset : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW5;
//-----MACRO defines for Message:PRE_SEG_MSG_QW5

//-----MACRO defines for fields:PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET
#define PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET__MSB                           63
#define PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET__LSB                            0
#define PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET__WIDTH                         64
#define PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET__MASK          0xffffffffffffffff
#define PRE_SEG_MSG_QW5__REMOTE_TAGED_OFFSET__RESET_VALUE                  0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW6
typedef union {
  struct {
    u64 remote_stag      : 32;
    u64 wqe_opcode       : 6;
    u64 add_fragment_cnt : 4;
    u64 rsvd0            : 5;
    u64 immed_data_flag  : 1;
    u64 rsvd1            : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW6;
//-----MACRO defines for Message:PRE_SEG_MSG_QW6

//-----MACRO defines for fields:PRE_SEG_MSG_QW6__IMMED_DATA_FLAG
#define PRE_SEG_MSG_QW6__IMMED_DATA_FLAG__MSB                               47
#define PRE_SEG_MSG_QW6__IMMED_DATA_FLAG__LSB                               47
#define PRE_SEG_MSG_QW6__IMMED_DATA_FLAG__WIDTH                              1
#define PRE_SEG_MSG_QW6__IMMED_DATA_FLAG__MASK                  0x800000000000
#define PRE_SEG_MSG_QW6__IMMED_DATA_FLAG__RESET_VALUE                      0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT
#define PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT__MSB                              41
#define PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT__LSB                              38
#define PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT__WIDTH                             4
#define PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT__MASK                  0x3c000000000
#define PRE_SEG_MSG_QW6__ADD_FRAGMENT_CNT__RESET_VALUE                     0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW6__WQE_OPCODE
#define PRE_SEG_MSG_QW6__WQE_OPCODE__MSB                                    37
#define PRE_SEG_MSG_QW6__WQE_OPCODE__LSB                                    32
#define PRE_SEG_MSG_QW6__WQE_OPCODE__WIDTH                                   6
#define PRE_SEG_MSG_QW6__WQE_OPCODE__MASK                         0x3f00000000
#define PRE_SEG_MSG_QW6__WQE_OPCODE__RESET_VALUE                           0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW6__REMOTE_STAG
#define PRE_SEG_MSG_QW6__REMOTE_STAG__MSB                                   31
#define PRE_SEG_MSG_QW6__REMOTE_STAG__LSB                                    0
#define PRE_SEG_MSG_QW6__REMOTE_STAG__WIDTH                                 32
#define PRE_SEG_MSG_QW6__REMOTE_STAG__MASK                          0xffffffff
#define PRE_SEG_MSG_QW6__REMOTE_STAG__RESET_VALUE                          0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW7
typedef union {
  struct {
    u128 tagged_offset : 64;
    u128 stag          : 32;
    u128 fragment_len  : 31;
    u128 fragment_vld  : 1;
  };
  u128 reg;
} PRE_SEG_MSG_QW7;
//-----MACRO defines for Message:PRE_SEG_MSG_QW7

//-----MACRO defines for fields:PRE_SEG_MSG_QW7__TAGGED_OFFSET
#define PRE_SEG_MSG_QW7__TAGGED_OFFSET__MSB                                 63
#define PRE_SEG_MSG_QW7__TAGGED_OFFSET__LSB                                  0
#define PRE_SEG_MSG_QW7__TAGGED_OFFSET__WIDTH                               64
#define PRE_SEG_MSG_QW7__TAGGED_OFFSET__MASK                0xffffffffffffffff
#define PRE_SEG_MSG_QW7__TAGGED_OFFSET__RESET_VALUE                        0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW7__FRAGMENT_VLD
#define PRE_SEG_MSG_QW7__FRAGMENT_VLD__MSB                                 127
#define PRE_SEG_MSG_QW7__FRAGMENT_VLD__LSB                                 127
#define PRE_SEG_MSG_QW7__FRAGMENT_VLD__WIDTH                                 1
#define PRE_SEG_MSG_QW7__FRAGMENT_VLD__MASK 0x80000000000000000000000000000000
#define PRE_SEG_MSG_QW7__FRAGMENT_VLD__RESET_VALUE                         0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW7__FRAGMENT_LEN
#define PRE_SEG_MSG_QW7__FRAGMENT_LEN__MSB                                 126
#define PRE_SEG_MSG_QW7__FRAGMENT_LEN__LSB                                  96
#define PRE_SEG_MSG_QW7__FRAGMENT_LEN__WIDTH                                31
#define PRE_SEG_MSG_QW7__FRAGMENT_LEN__MASK 0x7fffffff000000000000000000000000
#define PRE_SEG_MSG_QW7__FRAGMENT_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:PRE_SEG_MSG_QW7__STAG
#define PRE_SEG_MSG_QW7__STAG__MSB                                          95
#define PRE_SEG_MSG_QW7__STAG__LSB                                          64
#define PRE_SEG_MSG_QW7__STAG__WIDTH                                        32
#define PRE_SEG_MSG_QW7__STAG__MASK                 0xffffffff0000000000000000
#define PRE_SEG_MSG_QW7__STAG__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:PRE_SEG_MSG_QW8
typedef union {
  struct {
    u64 immed_data : 32;
    u64 rsvd0      : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PRE_SEG_MSG_QW8;
//-----MACRO defines for Message:PRE_SEG_MSG_QW8

//-----MACRO defines for fields:PRE_SEG_MSG_QW8__IMMED_DATA
#define PRE_SEG_MSG_QW8__IMMED_DATA__MSB                                    31
#define PRE_SEG_MSG_QW8__IMMED_DATA__LSB                                     0
#define PRE_SEG_MSG_QW8__IMMED_DATA__WIDTH                                  32
#define PRE_SEG_MSG_QW8__IMMED_DATA__MASK                           0xffffffff
#define PRE_SEG_MSG_QW8__IMMED_DATA__RESET_VALUE                           0x0

typedef struct {
  PRE_SEG_MSG_QW0  qw0;
  PRE_SEG_MSG_QW1  qw1;
  PRE_SEG_MSG_QW2  qw2;
  PRE_SEG_MSG_QW3  qw3;
  PRE_SEG_MSG_QW4  qw4;
  PRE_SEG_MSG_QW5  qw5;
  PRE_SEG_MSG_QW6  qw6;
  PRE_SEG_MSG_QW7  qw7;
  PRE_SEG_MSG_QW8  qw8;
} PRE_SEG_MSG;
//QW_CNT is actual number - 1
#define PRE_SEG_MSG_QW_CNT                                                   8
//-----MACRO defines for  Message Group POST_SEG_MSG: 0x200000
#define POST_SEG_MSG_MSG_ID                                               0x20
//-----Access structure typedef for Message:POST_SEG_MSG_QW0
typedef union {
  struct {
    u64 qpn              : 17;
    u64 fpm              : 10;
    u64 retr             : 1;
    u64 rsvd0            : 4;
    u64 opcode           : 8;
    u64 add_fragment_cnt : 4;
    u64 payload_len      : 13;
    u64 rsvd1            : 3;
    u64 sta              : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW0;
//-----MACRO defines for Message:POST_SEG_MSG_QW0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__STA
#define POST_SEG_MSG_QW0__STA__MSB                                          63
#define POST_SEG_MSG_QW0__STA__LSB                                          60
#define POST_SEG_MSG_QW0__STA__WIDTH                                         4
#define POST_SEG_MSG_QW0__STA__MASK                         0xf000000000000000
#define POST_SEG_MSG_QW0__STA__RESET_VALUE                                 0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__PAYLOAD_LEN
#define POST_SEG_MSG_QW0__PAYLOAD_LEN__MSB                                  56
#define POST_SEG_MSG_QW0__PAYLOAD_LEN__LSB                                  44
#define POST_SEG_MSG_QW0__PAYLOAD_LEN__WIDTH                                13
#define POST_SEG_MSG_QW0__PAYLOAD_LEN__MASK                  0x1fff00000000000
#define POST_SEG_MSG_QW0__PAYLOAD_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT
#define POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT__MSB                             43
#define POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT__LSB                             40
#define POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT__WIDTH                            4
#define POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT__MASK                 0xf0000000000
#define POST_SEG_MSG_QW0__ADD_FRAGMENT_CNT__RESET_VALUE                    0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__OPCODE
#define POST_SEG_MSG_QW0__OPCODE__MSB                                       39
#define POST_SEG_MSG_QW0__OPCODE__LSB                                       32
#define POST_SEG_MSG_QW0__OPCODE__WIDTH                                      8
#define POST_SEG_MSG_QW0__OPCODE__MASK                            0xff00000000
#define POST_SEG_MSG_QW0__OPCODE__RESET_VALUE                              0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__RETR
#define POST_SEG_MSG_QW0__RETR__MSB                                         27
#define POST_SEG_MSG_QW0__RETR__LSB                                         27
#define POST_SEG_MSG_QW0__RETR__WIDTH                                        1
#define POST_SEG_MSG_QW0__RETR__MASK                                 0x8000000
#define POST_SEG_MSG_QW0__RETR__RESET_VALUE                                0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__FPM
#define POST_SEG_MSG_QW0__FPM__MSB                                          26
#define POST_SEG_MSG_QW0__FPM__LSB                                          17
#define POST_SEG_MSG_QW0__FPM__WIDTH                                        10
#define POST_SEG_MSG_QW0__FPM__MASK                                  0x7fe0000
#define POST_SEG_MSG_QW0__FPM__RESET_VALUE                                 0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW0__QPN
#define POST_SEG_MSG_QW0__QPN__MSB                                          16
#define POST_SEG_MSG_QW0__QPN__LSB                                           0
#define POST_SEG_MSG_QW0__QPN__WIDTH                                        17
#define POST_SEG_MSG_QW0__QPN__MASK                                    0x1ffff
#define POST_SEG_MSG_QW0__QPN__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW1
typedef union {
  struct {
    u64 dstqp : 17;
    u64 rsvd0 : 1;
    u64 psn   : 24;
    u64 rsvd1 : 15;
    u64 pad   : 2;
    u64 se    : 1;
    u64 rsvd2 : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW1;
//-----MACRO defines for Message:POST_SEG_MSG_QW1

//-----MACRO defines for fields:POST_SEG_MSG_QW1__SE
#define POST_SEG_MSG_QW1__SE__MSB                                           59
#define POST_SEG_MSG_QW1__SE__LSB                                           59
#define POST_SEG_MSG_QW1__SE__WIDTH                                          1
#define POST_SEG_MSG_QW1__SE__MASK                           0x800000000000000
#define POST_SEG_MSG_QW1__SE__RESET_VALUE                                  0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW1__PAD
#define POST_SEG_MSG_QW1__PAD__MSB                                          58
#define POST_SEG_MSG_QW1__PAD__LSB                                          57
#define POST_SEG_MSG_QW1__PAD__WIDTH                                         2
#define POST_SEG_MSG_QW1__PAD__MASK                          0x600000000000000
#define POST_SEG_MSG_QW1__PAD__RESET_VALUE                                 0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW1__PSN
#define POST_SEG_MSG_QW1__PSN__MSB                                          41
#define POST_SEG_MSG_QW1__PSN__LSB                                          18
#define POST_SEG_MSG_QW1__PSN__WIDTH                                        24
#define POST_SEG_MSG_QW1__PSN__MASK                              0x3fffffc0000
#define POST_SEG_MSG_QW1__PSN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW1__DSTQP
#define POST_SEG_MSG_QW1__DSTQP__MSB                                        16
#define POST_SEG_MSG_QW1__DSTQP__LSB                                         0
#define POST_SEG_MSG_QW1__DSTQP__WIDTH                                      17
#define POST_SEG_MSG_QW1__DSTQP__MASK                                  0x1ffff
#define POST_SEG_MSG_QW1__DSTQP__RESET_VALUE                               0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW2
typedef union {
  struct {
    u64 remote_va : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW2;
//-----MACRO defines for Message:POST_SEG_MSG_QW2

//-----MACRO defines for fields:POST_SEG_MSG_QW2__REMOTE_VA
#define POST_SEG_MSG_QW2__REMOTE_VA__MSB                                    63
#define POST_SEG_MSG_QW2__REMOTE_VA__LSB                                     0
#define POST_SEG_MSG_QW2__REMOTE_VA__WIDTH                                  64
#define POST_SEG_MSG_QW2__REMOTE_VA__MASK                   0xffffffffffffffff
#define POST_SEG_MSG_QW2__REMOTE_VA__RESET_VALUE                           0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW3
typedef union {
  struct {
    u64 dmalen : 32;
    u64 r_key  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW3;
//-----MACRO defines for Message:POST_SEG_MSG_QW3

//-----MACRO defines for fields:POST_SEG_MSG_QW3__R_KEY
#define POST_SEG_MSG_QW3__R_KEY__MSB                                        63
#define POST_SEG_MSG_QW3__R_KEY__LSB                                        32
#define POST_SEG_MSG_QW3__R_KEY__WIDTH                                      32
#define POST_SEG_MSG_QW3__R_KEY__MASK                       0xffffffff00000000
#define POST_SEG_MSG_QW3__R_KEY__RESET_VALUE                               0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW3__DMALEN
#define POST_SEG_MSG_QW3__DMALEN__MSB                                       31
#define POST_SEG_MSG_QW3__DMALEN__LSB                                        0
#define POST_SEG_MSG_QW3__DMALEN__WIDTH                                     32
#define POST_SEG_MSG_QW3__DMALEN__MASK                              0xffffffff
#define POST_SEG_MSG_QW3__DMALEN__RESET_VALUE                              0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW4
typedef union {
  struct {
    u64 pd_idx : 18;
    u64 rsvd0  : 14;
    u64 q_key  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW4;
//-----MACRO defines for Message:POST_SEG_MSG_QW4

//-----MACRO defines for fields:POST_SEG_MSG_QW4__Q_KEY
#define POST_SEG_MSG_QW4__Q_KEY__MSB                                        63
#define POST_SEG_MSG_QW4__Q_KEY__LSB                                        32
#define POST_SEG_MSG_QW4__Q_KEY__WIDTH                                      32
#define POST_SEG_MSG_QW4__Q_KEY__MASK                       0xffffffff00000000
#define POST_SEG_MSG_QW4__Q_KEY__RESET_VALUE                               0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW4__PD_IDX
#define POST_SEG_MSG_QW4__PD_IDX__MSB                                       17
#define POST_SEG_MSG_QW4__PD_IDX__LSB                                        0
#define POST_SEG_MSG_QW4__PD_IDX__WIDTH                                     18
#define POST_SEG_MSG_QW4__PD_IDX__MASK                                 0x3ffff
#define POST_SEG_MSG_QW4__PD_IDX__RESET_VALUE                              0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW5
typedef union {
  struct {
    u192 fragment_va         : 64;
    u192 stag                : 32;
    u192 fragment_len        : 14;
    u192 rsvd0               : 17;
    u192 first_cut           : 1;
    u192 ori_fragment_len    : 32;
    u192 remain_fregment_len : 32;
  };
  u192 reg;
} POST_SEG_MSG_QW5;
//-----MACRO defines for Message:POST_SEG_MSG_QW5

//-----MACRO defines for fields:POST_SEG_MSG_QW5__FRAGMENT_VA
#define POST_SEG_MSG_QW5__FRAGMENT_VA__MSB                                  63
#define POST_SEG_MSG_QW5__FRAGMENT_VA__LSB                                   0
#define POST_SEG_MSG_QW5__FRAGMENT_VA__WIDTH                                64
#define POST_SEG_MSG_QW5__FRAGMENT_VA__MASK                 0xffffffffffffffff
#define POST_SEG_MSG_QW5__FRAGMENT_VA__RESET_VALUE                         0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW5__STAG
#define POST_SEG_MSG_QW5__STAG__MSB                                         95
#define POST_SEG_MSG_QW5__STAG__LSB                                         64
#define POST_SEG_MSG_QW5__STAG__WIDTH                                       32
#define POST_SEG_MSG_QW5__STAG__MASK                0xffffffff0000000000000000
#define POST_SEG_MSG_QW5__STAG__RESET_VALUE                                0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW5__FRAGMENT_LEN
#define POST_SEG_MSG_QW5__FRAGMENT_LEN__MSB                                109
#define POST_SEG_MSG_QW5__FRAGMENT_LEN__LSB                                 96
#define POST_SEG_MSG_QW5__FRAGMENT_LEN__WIDTH                               14
#define POST_SEG_MSG_QW5__FRAGMENT_LEN__MASK    0x3fff000000000000000000000000
#define POST_SEG_MSG_QW5__FRAGMENT_LEN__RESET_VALUE                        0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW5__FIRST_CUT
#define POST_SEG_MSG_QW5__FIRST_CUT__MSB                                   127
#define POST_SEG_MSG_QW5__FIRST_CUT__LSB                                   127
#define POST_SEG_MSG_QW5__FIRST_CUT__WIDTH                                   1
#define POST_SEG_MSG_QW5__FIRST_CUT__MASK   0x80000000000000000000000000000000
#define POST_SEG_MSG_QW5__FIRST_CUT__RESET_VALUE                           0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN
#define POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN__MSB                            159
#define POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN__LSB                            128
#define POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN__WIDTH                           32
#define POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN__MASK 0xffffffff00000000000000000000000000000000
#define POST_SEG_MSG_QW5__ORI_FRAGMENT_LEN__RESET_VALUE                    0x0

//-----MACRO defines for fields:POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN
#define POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN__MSB                         191
#define POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN__LSB                         160
#define POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN__WIDTH                        32
#define POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN__MASK 0xffffffff0000000000000000000000000000000000000000
#define POST_SEG_MSG_QW5__REMAIN_FREGMENT_LEN__RESET_VALUE                 0x0

//-----Access structure typedef for Message:POST_SEG_MSG_QW6
typedef union {
  struct {
    u64 immed_data : 32;
    u64 rsvd0      : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} POST_SEG_MSG_QW6;
//-----MACRO defines for Message:POST_SEG_MSG_QW6

//-----MACRO defines for fields:POST_SEG_MSG_QW6__IMMED_DATA
#define POST_SEG_MSG_QW6__IMMED_DATA__MSB                                   31
#define POST_SEG_MSG_QW6__IMMED_DATA__LSB                                    0
#define POST_SEG_MSG_QW6__IMMED_DATA__WIDTH                                 32
#define POST_SEG_MSG_QW6__IMMED_DATA__MASK                          0xffffffff
#define POST_SEG_MSG_QW6__IMMED_DATA__RESET_VALUE                          0x0

typedef struct {
  POST_SEG_MSG_QW0  qw0;
  POST_SEG_MSG_QW1  qw1;
  POST_SEG_MSG_QW2  qw2;
  POST_SEG_MSG_QW3  qw3;
  POST_SEG_MSG_QW4  qw4;
  POST_SEG_MSG_QW5  qw5;
  POST_SEG_MSG_QW6  qw6;
} POST_SEG_MSG;
//QW_CNT is actual number - 1
#define POST_SEG_MSG_QW_CNT                                                  6
//-----MACRO defines for  Message Group XMIT_PKT_MSG: 0x210000
#define XMIT_PKT_MSG_MSG_ID                                               0x21
//-----Access structure typedef for Message:XMIT_PKT_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 tc      : 3;
    u64 rsvd0   : 2;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} XMIT_PKT_MSG_QW0;
//-----MACRO defines for Message:XMIT_PKT_MSG_QW0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__TC
#define XMIT_PKT_MSG_QW0__TC__MSB                                           61
#define XMIT_PKT_MSG_QW0__TC__LSB                                           59
#define XMIT_PKT_MSG_QW0__TC__WIDTH                                          3
#define XMIT_PKT_MSG_QW0__TC__MASK                          0x3800000000000000
#define XMIT_PKT_MSG_QW0__TC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__FPM
#define XMIT_PKT_MSG_QW0__FPM__MSB                                          58
#define XMIT_PKT_MSG_QW0__FPM__LSB                                          49
#define XMIT_PKT_MSG_QW0__FPM__WIDTH                                        10
#define XMIT_PKT_MSG_QW0__FPM__MASK                          0x7fe000000000000
#define XMIT_PKT_MSG_QW0__FPM__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__QPN
#define XMIT_PKT_MSG_QW0__QPN__MSB                                          48
#define XMIT_PKT_MSG_QW0__QPN__LSB                                          32
#define XMIT_PKT_MSG_QW0__QPN__WIDTH                                        17
#define XMIT_PKT_MSG_QW0__QPN__MASK                            0x1ffff00000000
#define XMIT_PKT_MSG_QW0__QPN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__MSG_ID
#define XMIT_PKT_MSG_QW0__MSG_ID__MSB                                       31
#define XMIT_PKT_MSG_QW0__MSG_ID__LSB                                       24
#define XMIT_PKT_MSG_QW0__MSG_ID__WIDTH                                      8
#define XMIT_PKT_MSG_QW0__MSG_ID__MASK                              0xff000000
#define XMIT_PKT_MSG_QW0__MSG_ID__RESET_VALUE                              0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__REQ_TAG
#define XMIT_PKT_MSG_QW0__REQ_TAG__MSB                                      23
#define XMIT_PKT_MSG_QW0__REQ_TAG__LSB                                      16
#define XMIT_PKT_MSG_QW0__REQ_TAG__WIDTH                                     8
#define XMIT_PKT_MSG_QW0__REQ_TAG__MASK                               0xff0000
#define XMIT_PKT_MSG_QW0__REQ_TAG__RESET_VALUE                             0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__SRC
#define XMIT_PKT_MSG_QW0__SRC__MSB                                          15
#define XMIT_PKT_MSG_QW0__SRC__LSB                                          12
#define XMIT_PKT_MSG_QW0__SRC__WIDTH                                         4
#define XMIT_PKT_MSG_QW0__SRC__MASK                                     0xf000
#define XMIT_PKT_MSG_QW0__SRC__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__DST
#define XMIT_PKT_MSG_QW0__DST__MSB                                          11
#define XMIT_PKT_MSG_QW0__DST__LSB                                          10
#define XMIT_PKT_MSG_QW0__DST__WIDTH                                         2
#define XMIT_PKT_MSG_QW0__DST__MASK                                      0xc00
#define XMIT_PKT_MSG_QW0__DST__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__DSTFIFO
#define XMIT_PKT_MSG_QW0__DSTFIFO__MSB                                       9
#define XMIT_PKT_MSG_QW0__DSTFIFO__LSB                                       6
#define XMIT_PKT_MSG_QW0__DSTFIFO__WIDTH                                     4
#define XMIT_PKT_MSG_QW0__DSTFIFO__MASK                                  0x3c0
#define XMIT_PKT_MSG_QW0__DSTFIFO__RESET_VALUE                             0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW0__CNT
#define XMIT_PKT_MSG_QW0__CNT__MSB                                           5
#define XMIT_PKT_MSG_QW0__CNT__LSB                                           0
#define XMIT_PKT_MSG_QW0__CNT__WIDTH                                         6
#define XMIT_PKT_MSG_QW0__CNT__MASK                                       0x3f
#define XMIT_PKT_MSG_QW0__CNT__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:XMIT_PKT_MSG_QW1
typedef union {
  struct {
    u64 cbuf_addr : 26;
    u64 rsvd0     : 6;
    u64 cbuf_bcnt : 14;
    u64 rsvd1     : 10;
    u64 pkt_type  : 8;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} XMIT_PKT_MSG_QW1;
//-----MACRO defines for Message:XMIT_PKT_MSG_QW1

//-----MACRO defines for fields:XMIT_PKT_MSG_QW1__PKT_TYPE
#define XMIT_PKT_MSG_QW1__PKT_TYPE__MSB                                     63
#define XMIT_PKT_MSG_QW1__PKT_TYPE__LSB                                     56
#define XMIT_PKT_MSG_QW1__PKT_TYPE__WIDTH                                    8
#define XMIT_PKT_MSG_QW1__PKT_TYPE__MASK                    0xff00000000000000
#define XMIT_PKT_MSG_QW1__PKT_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW1__CBUF_BCNT
#define XMIT_PKT_MSG_QW1__CBUF_BCNT__MSB                                    45
#define XMIT_PKT_MSG_QW1__CBUF_BCNT__LSB                                    32
#define XMIT_PKT_MSG_QW1__CBUF_BCNT__WIDTH                                  14
#define XMIT_PKT_MSG_QW1__CBUF_BCNT__MASK                       0x3fff00000000
#define XMIT_PKT_MSG_QW1__CBUF_BCNT__RESET_VALUE                           0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW1__CBUF_ADDR
#define XMIT_PKT_MSG_QW1__CBUF_ADDR__MSB                                    25
#define XMIT_PKT_MSG_QW1__CBUF_ADDR__LSB                                     0
#define XMIT_PKT_MSG_QW1__CBUF_ADDR__WIDTH                                  26
#define XMIT_PKT_MSG_QW1__CBUF_ADDR__MASK                            0x3ffffff
#define XMIT_PKT_MSG_QW1__CBUF_ADDR__RESET_VALUE                           0x0

//-----Access structure typedef for Message:XMIT_PKT_MSG_QW2
typedef union {
  struct {
    u64 syndrome             : 8;
    u64 syndrome_vld         : 1;
    u64 rsvd0                : 38;
    u64 udp_srcport_override : 1;
    u64 udp_srcport          : 16;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} XMIT_PKT_MSG_QW2;
//-----MACRO defines for Message:XMIT_PKT_MSG_QW2

//-----MACRO defines for fields:XMIT_PKT_MSG_QW2__UDP_SRCPORT
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT__MSB                                  63
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT__LSB                                  48
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT__WIDTH                                16
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT__MASK                 0xffff000000000000
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT__RESET_VALUE                         0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE__MSB                         47
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE__LSB                         47
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE__WIDTH                        1
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE__MASK            0x800000000000
#define XMIT_PKT_MSG_QW2__UDP_SRCPORT_OVERRIDE__RESET_VALUE                0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW2__SYNDROME_VLD
#define XMIT_PKT_MSG_QW2__SYNDROME_VLD__MSB                                  8
#define XMIT_PKT_MSG_QW2__SYNDROME_VLD__LSB                                  8
#define XMIT_PKT_MSG_QW2__SYNDROME_VLD__WIDTH                                1
#define XMIT_PKT_MSG_QW2__SYNDROME_VLD__MASK                             0x100
#define XMIT_PKT_MSG_QW2__SYNDROME_VLD__RESET_VALUE                        0x0

//-----MACRO defines for fields:XMIT_PKT_MSG_QW2__SYNDROME
#define XMIT_PKT_MSG_QW2__SYNDROME__MSB                                      7
#define XMIT_PKT_MSG_QW2__SYNDROME__LSB                                      0
#define XMIT_PKT_MSG_QW2__SYNDROME__WIDTH                                    8
#define XMIT_PKT_MSG_QW2__SYNDROME__MASK                                  0xff
#define XMIT_PKT_MSG_QW2__SYNDROME__RESET_VALUE                            0x0

typedef struct {
  XMIT_PKT_MSG_QW0  qw0;
  XMIT_PKT_MSG_QW1  qw1;
  XMIT_PKT_MSG_QW2  qw2;
} XMIT_PKT_MSG;
//QW_CNT is actual number - 1
#define XMIT_PKT_MSG_QW_CNT                                                  2
//-----MACRO defines for  Message Group PKT_GEN_MSG: 0x220000
#define PKT_GEN_MSG_MSG_ID                                                0x22
//-----Access structure typedef for Message:PKT_GEN_MSG_QW0
typedef union {
  struct {
    u64 qpn                   : 17;
    u64 fpm                   : 10;
    u64 retr                  : 1;
    u64 dcb_tc                : 3;
    u64 privileged_enabled    : 1;
    u64 opcode                : 8;
    u64 additionalfragmentcnt : 4;
    u64 pyld_len              : 13;
    u64 inline1               : 1;
    u64 cbuf                  : 1;
    u64 report_comp           : 1;
    u64 report_rtt            : 1;
    u64 flush_type            : 2;
    u64 flush                 : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW0;
//-----MACRO defines for Message:PKT_GEN_MSG_QW0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__FLUSH
#define PKT_GEN_MSG_QW0__FLUSH__MSB                                         63
#define PKT_GEN_MSG_QW0__FLUSH__LSB                                         63
#define PKT_GEN_MSG_QW0__FLUSH__WIDTH                                        1
#define PKT_GEN_MSG_QW0__FLUSH__MASK                        0x8000000000000000
#define PKT_GEN_MSG_QW0__FLUSH__RESET_VALUE                                0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__FLUSH_TYPE
#define PKT_GEN_MSG_QW0__FLUSH_TYPE__MSB                                    62
#define PKT_GEN_MSG_QW0__FLUSH_TYPE__LSB                                    61
#define PKT_GEN_MSG_QW0__FLUSH_TYPE__WIDTH                                   2
#define PKT_GEN_MSG_QW0__FLUSH_TYPE__MASK                   0x6000000000000000
#define PKT_GEN_MSG_QW0__FLUSH_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__REPORT_RTT
#define PKT_GEN_MSG_QW0__REPORT_RTT__MSB                                    60
#define PKT_GEN_MSG_QW0__REPORT_RTT__LSB                                    60
#define PKT_GEN_MSG_QW0__REPORT_RTT__WIDTH                                   1
#define PKT_GEN_MSG_QW0__REPORT_RTT__MASK                   0x1000000000000000
#define PKT_GEN_MSG_QW0__REPORT_RTT__RESET_VALUE                           0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__REPORT_COMP
#define PKT_GEN_MSG_QW0__REPORT_COMP__MSB                                   59
#define PKT_GEN_MSG_QW0__REPORT_COMP__LSB                                   59
#define PKT_GEN_MSG_QW0__REPORT_COMP__WIDTH                                  1
#define PKT_GEN_MSG_QW0__REPORT_COMP__MASK                   0x800000000000000
#define PKT_GEN_MSG_QW0__REPORT_COMP__RESET_VALUE                          0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__CBUF
#define PKT_GEN_MSG_QW0__CBUF__MSB                                          58
#define PKT_GEN_MSG_QW0__CBUF__LSB                                          58
#define PKT_GEN_MSG_QW0__CBUF__WIDTH                                         1
#define PKT_GEN_MSG_QW0__CBUF__MASK                          0x400000000000000
#define PKT_GEN_MSG_QW0__CBUF__RESET_VALUE                                 0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__INLINE
#define PKT_GEN_MSG_QW0__INLINE__MSB                                        57
#define PKT_GEN_MSG_QW0__INLINE__LSB                                        57
#define PKT_GEN_MSG_QW0__INLINE__WIDTH                                       1
#define PKT_GEN_MSG_QW0__INLINE__MASK                        0x200000000000000
#define PKT_GEN_MSG_QW0__INLINE__RESET_VALUE                               0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__PYLD_LEN
#define PKT_GEN_MSG_QW0__PYLD_LEN__MSB                                      56
#define PKT_GEN_MSG_QW0__PYLD_LEN__LSB                                      44
#define PKT_GEN_MSG_QW0__PYLD_LEN__WIDTH                                    13
#define PKT_GEN_MSG_QW0__PYLD_LEN__MASK                      0x1fff00000000000
#define PKT_GEN_MSG_QW0__PYLD_LEN__RESET_VALUE                             0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT
#define PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT__MSB                         43
#define PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT__LSB                         40
#define PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT__WIDTH                        4
#define PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT__MASK             0xf0000000000
#define PKT_GEN_MSG_QW0__ADDITIONALFRAGMENTCNT__RESET_VALUE                0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__OPCODE
#define PKT_GEN_MSG_QW0__OPCODE__MSB                                        39
#define PKT_GEN_MSG_QW0__OPCODE__LSB                                        32
#define PKT_GEN_MSG_QW0__OPCODE__WIDTH                                       8
#define PKT_GEN_MSG_QW0__OPCODE__MASK                             0xff00000000
#define PKT_GEN_MSG_QW0__OPCODE__RESET_VALUE                               0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED
#define PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED__MSB                            31
#define PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED__LSB                            31
#define PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED__WIDTH                           1
#define PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED__MASK                   0x80000000
#define PKT_GEN_MSG_QW0__PRIVILEGED_ENABLED__RESET_VALUE                   0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__DCB_TC
#define PKT_GEN_MSG_QW0__DCB_TC__MSB                                        30
#define PKT_GEN_MSG_QW0__DCB_TC__LSB                                        28
#define PKT_GEN_MSG_QW0__DCB_TC__WIDTH                                       3
#define PKT_GEN_MSG_QW0__DCB_TC__MASK                               0x70000000
#define PKT_GEN_MSG_QW0__DCB_TC__RESET_VALUE                               0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__RETR
#define PKT_GEN_MSG_QW0__RETR__MSB                                          27
#define PKT_GEN_MSG_QW0__RETR__LSB                                          27
#define PKT_GEN_MSG_QW0__RETR__WIDTH                                         1
#define PKT_GEN_MSG_QW0__RETR__MASK                                  0x8000000
#define PKT_GEN_MSG_QW0__RETR__RESET_VALUE                                 0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__FPM
#define PKT_GEN_MSG_QW0__FPM__MSB                                           26
#define PKT_GEN_MSG_QW0__FPM__LSB                                           17
#define PKT_GEN_MSG_QW0__FPM__WIDTH                                         10
#define PKT_GEN_MSG_QW0__FPM__MASK                                   0x7fe0000
#define PKT_GEN_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW0__QPN
#define PKT_GEN_MSG_QW0__QPN__MSB                                           16
#define PKT_GEN_MSG_QW0__QPN__LSB                                            0
#define PKT_GEN_MSG_QW0__QPN__WIDTH                                         17
#define PKT_GEN_MSG_QW0__QPN__MASK                                     0x1ffff
#define PKT_GEN_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW1
typedef union {
  struct {
    u64 dstqp_lo : 17;
    u64 ackreq   : 1;
    u64 psn      : 24;
    u64 pad      : 2;
    u64 se       : 1;
    u64 wqe_idx  : 16;
    u64 qp_type  : 3;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW1;
//-----MACRO defines for Message:PKT_GEN_MSG_QW1

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__QP_TYPE
#define PKT_GEN_MSG_QW1__QP_TYPE__MSB                                       63
#define PKT_GEN_MSG_QW1__QP_TYPE__LSB                                       61
#define PKT_GEN_MSG_QW1__QP_TYPE__WIDTH                                      3
#define PKT_GEN_MSG_QW1__QP_TYPE__MASK                      0xe000000000000000
#define PKT_GEN_MSG_QW1__QP_TYPE__RESET_VALUE                              0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__WQE_IDX
#define PKT_GEN_MSG_QW1__WQE_IDX__MSB                                       60
#define PKT_GEN_MSG_QW1__WQE_IDX__LSB                                       45
#define PKT_GEN_MSG_QW1__WQE_IDX__WIDTH                                     16
#define PKT_GEN_MSG_QW1__WQE_IDX__MASK                      0x1fffe00000000000
#define PKT_GEN_MSG_QW1__WQE_IDX__RESET_VALUE                              0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__SE
#define PKT_GEN_MSG_QW1__SE__MSB                                            44
#define PKT_GEN_MSG_QW1__SE__LSB                                            44
#define PKT_GEN_MSG_QW1__SE__WIDTH                                           1
#define PKT_GEN_MSG_QW1__SE__MASK                               0x100000000000
#define PKT_GEN_MSG_QW1__SE__RESET_VALUE                                   0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__PAD
#define PKT_GEN_MSG_QW1__PAD__MSB                                           43
#define PKT_GEN_MSG_QW1__PAD__LSB                                           42
#define PKT_GEN_MSG_QW1__PAD__WIDTH                                          2
#define PKT_GEN_MSG_QW1__PAD__MASK                               0xc0000000000
#define PKT_GEN_MSG_QW1__PAD__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__PSN
#define PKT_GEN_MSG_QW1__PSN__MSB                                           41
#define PKT_GEN_MSG_QW1__PSN__LSB                                           18
#define PKT_GEN_MSG_QW1__PSN__WIDTH                                         24
#define PKT_GEN_MSG_QW1__PSN__MASK                               0x3fffffc0000
#define PKT_GEN_MSG_QW1__PSN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__ACKREQ
#define PKT_GEN_MSG_QW1__ACKREQ__MSB                                        17
#define PKT_GEN_MSG_QW1__ACKREQ__LSB                                        17
#define PKT_GEN_MSG_QW1__ACKREQ__WIDTH                                       1
#define PKT_GEN_MSG_QW1__ACKREQ__MASK                                  0x20000
#define PKT_GEN_MSG_QW1__ACKREQ__RESET_VALUE                               0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW1__DSTQP_LO
#define PKT_GEN_MSG_QW1__DSTQP_LO__MSB                                      16
#define PKT_GEN_MSG_QW1__DSTQP_LO__LSB                                       0
#define PKT_GEN_MSG_QW1__DSTQP_LO__WIDTH                                    17
#define PKT_GEN_MSG_QW1__DSTQP_LO__MASK                                0x1ffff
#define PKT_GEN_MSG_QW1__DSTQP_LO__RESET_VALUE                             0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW2
typedef union {
  struct {
    u64 remote_va : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW2;
//-----MACRO defines for Message:PKT_GEN_MSG_QW2

//-----MACRO defines for fields:PKT_GEN_MSG_QW2__REMOTE_VA
#define PKT_GEN_MSG_QW2__REMOTE_VA__MSB                                     63
#define PKT_GEN_MSG_QW2__REMOTE_VA__LSB                                      0
#define PKT_GEN_MSG_QW2__REMOTE_VA__WIDTH                                   64
#define PKT_GEN_MSG_QW2__REMOTE_VA__MASK                    0xffffffffffffffff
#define PKT_GEN_MSG_QW2__REMOTE_VA__RESET_VALUE                            0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW3
typedef union {
  struct {
    u64 dmalen : 32;
    u64 r_key  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW3;
//-----MACRO defines for Message:PKT_GEN_MSG_QW3

//-----MACRO defines for fields:PKT_GEN_MSG_QW3__R_KEY
#define PKT_GEN_MSG_QW3__R_KEY__MSB                                         63
#define PKT_GEN_MSG_QW3__R_KEY__LSB                                         32
#define PKT_GEN_MSG_QW3__R_KEY__WIDTH                                       32
#define PKT_GEN_MSG_QW3__R_KEY__MASK                        0xffffffff00000000
#define PKT_GEN_MSG_QW3__R_KEY__RESET_VALUE                                0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW3__DMALEN
#define PKT_GEN_MSG_QW3__DMALEN__MSB                                        31
#define PKT_GEN_MSG_QW3__DMALEN__LSB                                         0
#define PKT_GEN_MSG_QW3__DMALEN__WIDTH                                      32
#define PKT_GEN_MSG_QW3__DMALEN__MASK                               0xffffffff
#define PKT_GEN_MSG_QW3__DMALEN__RESET_VALUE                               0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW4
typedef union {
  struct {
    u64 pd_index       : 18;
    u64 vsi            : 10;
    u64 pf_idx         : 2;
    u64 force_pf       : 1;
    u64 retr_first_pkt : 1;
    u64 q_key          : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW4;
//-----MACRO defines for Message:PKT_GEN_MSG_QW4

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__Q_KEY
#define PKT_GEN_MSG_QW4__Q_KEY__MSB                                         63
#define PKT_GEN_MSG_QW4__Q_KEY__LSB                                         32
#define PKT_GEN_MSG_QW4__Q_KEY__WIDTH                                       32
#define PKT_GEN_MSG_QW4__Q_KEY__MASK                        0xffffffff00000000
#define PKT_GEN_MSG_QW4__Q_KEY__RESET_VALUE                                0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__RETR_FIRST_PKT
#define PKT_GEN_MSG_QW4__RETR_FIRST_PKT__MSB                                31
#define PKT_GEN_MSG_QW4__RETR_FIRST_PKT__LSB                                31
#define PKT_GEN_MSG_QW4__RETR_FIRST_PKT__WIDTH                               1
#define PKT_GEN_MSG_QW4__RETR_FIRST_PKT__MASK                       0x80000000
#define PKT_GEN_MSG_QW4__RETR_FIRST_PKT__RESET_VALUE                       0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__FORCE_PF
#define PKT_GEN_MSG_QW4__FORCE_PF__MSB                                      30
#define PKT_GEN_MSG_QW4__FORCE_PF__LSB                                      30
#define PKT_GEN_MSG_QW4__FORCE_PF__WIDTH                                     1
#define PKT_GEN_MSG_QW4__FORCE_PF__MASK                             0x40000000
#define PKT_GEN_MSG_QW4__FORCE_PF__RESET_VALUE                             0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__PF_IDX
#define PKT_GEN_MSG_QW4__PF_IDX__MSB                                        29
#define PKT_GEN_MSG_QW4__PF_IDX__LSB                                        28
#define PKT_GEN_MSG_QW4__PF_IDX__WIDTH                                       2
#define PKT_GEN_MSG_QW4__PF_IDX__MASK                               0x30000000
#define PKT_GEN_MSG_QW4__PF_IDX__RESET_VALUE                               0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__VSI
#define PKT_GEN_MSG_QW4__VSI__MSB                                           27
#define PKT_GEN_MSG_QW4__VSI__LSB                                           18
#define PKT_GEN_MSG_QW4__VSI__WIDTH                                         10
#define PKT_GEN_MSG_QW4__VSI__MASK                                   0xffc0000
#define PKT_GEN_MSG_QW4__VSI__RESET_VALUE                                  0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW4__PD_INDEX
#define PKT_GEN_MSG_QW4__PD_INDEX__MSB                                      17
#define PKT_GEN_MSG_QW4__PD_INDEX__LSB                                       0
#define PKT_GEN_MSG_QW4__PD_INDEX__WIDTH                                    18
#define PKT_GEN_MSG_QW4__PD_INDEX__MASK                                0x3ffff
#define PKT_GEN_MSG_QW4__PD_INDEX__RESET_VALUE                             0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW5
typedef union {
  struct {
    u192 fragment_va         : 64;
    u192 stag                : 32;
    u192 fragment_len        : 14;
    u192 rsvd0               : 17;
    u192 first_cut           : 1;
    u192 ori_fragment_len    : 32;
    u192 remain_fragment_len : 32;
  };
  u192 reg;
} PKT_GEN_MSG_QW5;
//-----MACRO defines for Message:PKT_GEN_MSG_QW5

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__FRAGMENT_VA
#define PKT_GEN_MSG_QW5__FRAGMENT_VA__MSB                                   63
#define PKT_GEN_MSG_QW5__FRAGMENT_VA__LSB                                    0
#define PKT_GEN_MSG_QW5__FRAGMENT_VA__WIDTH                                 64
#define PKT_GEN_MSG_QW5__FRAGMENT_VA__MASK                  0xffffffffffffffff
#define PKT_GEN_MSG_QW5__FRAGMENT_VA__RESET_VALUE                          0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__STAG
#define PKT_GEN_MSG_QW5__STAG__MSB                                          95
#define PKT_GEN_MSG_QW5__STAG__LSB                                          64
#define PKT_GEN_MSG_QW5__STAG__WIDTH                                        32
#define PKT_GEN_MSG_QW5__STAG__MASK                 0xffffffff0000000000000000
#define PKT_GEN_MSG_QW5__STAG__RESET_VALUE                                 0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__FRAGMENT_LEN
#define PKT_GEN_MSG_QW5__FRAGMENT_LEN__MSB                                 109
#define PKT_GEN_MSG_QW5__FRAGMENT_LEN__LSB                                  96
#define PKT_GEN_MSG_QW5__FRAGMENT_LEN__WIDTH                                14
#define PKT_GEN_MSG_QW5__FRAGMENT_LEN__MASK     0x3fff000000000000000000000000
#define PKT_GEN_MSG_QW5__FRAGMENT_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__FIRST_CUT
#define PKT_GEN_MSG_QW5__FIRST_CUT__MSB                                    127
#define PKT_GEN_MSG_QW5__FIRST_CUT__LSB                                    127
#define PKT_GEN_MSG_QW5__FIRST_CUT__WIDTH                                    1
#define PKT_GEN_MSG_QW5__FIRST_CUT__MASK    0x80000000000000000000000000000000
#define PKT_GEN_MSG_QW5__FIRST_CUT__RESET_VALUE                            0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN
#define PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN__MSB                             159
#define PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN__LSB                             128
#define PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN__WIDTH                            32
#define PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN__MASK 0xffffffff00000000000000000000000000000000
#define PKT_GEN_MSG_QW5__ORI_FRAGMENT_LEN__RESET_VALUE                     0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN
#define PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN__MSB                          191
#define PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN__LSB                          160
#define PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN__WIDTH                         32
#define PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN__MASK 0xffffffff0000000000000000000000000000000000000000
#define PKT_GEN_MSG_QW5__REMAIN_FRAGMENT_LEN__RESET_VALUE                  0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW6
typedef union {
  struct {
    u64 inline_data : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW6;
//-----MACRO defines for Message:PKT_GEN_MSG_QW6

//-----MACRO defines for fields:PKT_GEN_MSG_QW6__INLINE_DATA
#define PKT_GEN_MSG_QW6__INLINE_DATA__MSB                                   63
#define PKT_GEN_MSG_QW6__INLINE_DATA__LSB                                    0
#define PKT_GEN_MSG_QW6__INLINE_DATA__WIDTH                                 64
#define PKT_GEN_MSG_QW6__INLINE_DATA__MASK                  0xffffffffffffffff
#define PKT_GEN_MSG_QW6__INLINE_DATA__RESET_VALUE                          0x0

//-----Access structure typedef for Message:PKT_GEN_MSG_QW7
typedef union {
  struct {
    u64 immdata           : 32;
    u64 sqcqe_hmcpageofst : 5;
    u64 sqcqe_hmcpage     : 19;
    u64 rsvd0             : 1;
    u64 dstqp_hi          : 7;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PKT_GEN_MSG_QW7;
//-----MACRO defines for Message:PKT_GEN_MSG_QW7

//-----MACRO defines for fields:PKT_GEN_MSG_QW7__DSTQP_HI
#define PKT_GEN_MSG_QW7__DSTQP_HI__MSB                                      63
#define PKT_GEN_MSG_QW7__DSTQP_HI__LSB                                      57
#define PKT_GEN_MSG_QW7__DSTQP_HI__WIDTH                                     7
#define PKT_GEN_MSG_QW7__DSTQP_HI__MASK                     0xfe00000000000000
#define PKT_GEN_MSG_QW7__DSTQP_HI__RESET_VALUE                             0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW7__SQCQE_HMCPAGE
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGE__MSB                                 55
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGE__LSB                                 37
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGE__WIDTH                               19
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGE__MASK                  0xffffe000000000
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGE__RESET_VALUE                        0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST__MSB                             36
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST__LSB                             32
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST__WIDTH                            5
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST__MASK                  0x1f00000000
#define PKT_GEN_MSG_QW7__SQCQE_HMCPAGEOFST__RESET_VALUE                    0x0

//-----MACRO defines for fields:PKT_GEN_MSG_QW7__IMMDATA
#define PKT_GEN_MSG_QW7__IMMDATA__MSB                                       31
#define PKT_GEN_MSG_QW7__IMMDATA__LSB                                        0
#define PKT_GEN_MSG_QW7__IMMDATA__WIDTH                                     32
#define PKT_GEN_MSG_QW7__IMMDATA__MASK                              0xffffffff
#define PKT_GEN_MSG_QW7__IMMDATA__RESET_VALUE                              0x0

typedef struct {
  PKT_GEN_MSG_QW0  qw0;
  PKT_GEN_MSG_QW1  qw1;
  PKT_GEN_MSG_QW2  qw2;
  PKT_GEN_MSG_QW3  qw3;
  PKT_GEN_MSG_QW4  qw4;
  PKT_GEN_MSG_QW5  qw5;
  PKT_GEN_MSG_QW6  qw6;
  PKT_GEN_MSG_QW7  qw7;
} PKT_GEN_MSG;
//QW_CNT is actual number - 1
#define PKT_GEN_MSG_QW_CNT                                                   7
//-----MACRO defines for  Message Group RETR_NOTIFY_MSG: 0x230000
#define RETR_NOTIFY_MSG_MSG_ID                                            0x23
//-----Access structure typedef for Message:RETR_NOTIFY_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RETR_NOTIFY_MSG_QW0;
//-----MACRO defines for Message:RETR_NOTIFY_MSG_QW0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__FPM
#define RETR_NOTIFY_MSG_QW0__FPM__MSB                                       58
#define RETR_NOTIFY_MSG_QW0__FPM__LSB                                       49
#define RETR_NOTIFY_MSG_QW0__FPM__WIDTH                                     10
#define RETR_NOTIFY_MSG_QW0__FPM__MASK                       0x7fe000000000000
#define RETR_NOTIFY_MSG_QW0__FPM__RESET_VALUE                              0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__QPN
#define RETR_NOTIFY_MSG_QW0__QPN__MSB                                       48
#define RETR_NOTIFY_MSG_QW0__QPN__LSB                                       32
#define RETR_NOTIFY_MSG_QW0__QPN__WIDTH                                     17
#define RETR_NOTIFY_MSG_QW0__QPN__MASK                         0x1ffff00000000
#define RETR_NOTIFY_MSG_QW0__QPN__RESET_VALUE                              0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__MSG_ID
#define RETR_NOTIFY_MSG_QW0__MSG_ID__MSB                                    31
#define RETR_NOTIFY_MSG_QW0__MSG_ID__LSB                                    24
#define RETR_NOTIFY_MSG_QW0__MSG_ID__WIDTH                                   8
#define RETR_NOTIFY_MSG_QW0__MSG_ID__MASK                           0xff000000
#define RETR_NOTIFY_MSG_QW0__MSG_ID__RESET_VALUE                           0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__REQ_TAG
#define RETR_NOTIFY_MSG_QW0__REQ_TAG__MSB                                   23
#define RETR_NOTIFY_MSG_QW0__REQ_TAG__LSB                                   16
#define RETR_NOTIFY_MSG_QW0__REQ_TAG__WIDTH                                  8
#define RETR_NOTIFY_MSG_QW0__REQ_TAG__MASK                            0xff0000
#define RETR_NOTIFY_MSG_QW0__REQ_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__SRC
#define RETR_NOTIFY_MSG_QW0__SRC__MSB                                       15
#define RETR_NOTIFY_MSG_QW0__SRC__LSB                                       12
#define RETR_NOTIFY_MSG_QW0__SRC__WIDTH                                      4
#define RETR_NOTIFY_MSG_QW0__SRC__MASK                                  0xf000
#define RETR_NOTIFY_MSG_QW0__SRC__RESET_VALUE                              0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__DST
#define RETR_NOTIFY_MSG_QW0__DST__MSB                                       11
#define RETR_NOTIFY_MSG_QW0__DST__LSB                                       10
#define RETR_NOTIFY_MSG_QW0__DST__WIDTH                                      2
#define RETR_NOTIFY_MSG_QW0__DST__MASK                                   0xc00
#define RETR_NOTIFY_MSG_QW0__DST__RESET_VALUE                              0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__DSTFIFO
#define RETR_NOTIFY_MSG_QW0__DSTFIFO__MSB                                    9
#define RETR_NOTIFY_MSG_QW0__DSTFIFO__LSB                                    6
#define RETR_NOTIFY_MSG_QW0__DSTFIFO__WIDTH                                  4
#define RETR_NOTIFY_MSG_QW0__DSTFIFO__MASK                               0x3c0
#define RETR_NOTIFY_MSG_QW0__DSTFIFO__RESET_VALUE                          0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW0__CNT
#define RETR_NOTIFY_MSG_QW0__CNT__MSB                                        5
#define RETR_NOTIFY_MSG_QW0__CNT__LSB                                        0
#define RETR_NOTIFY_MSG_QW0__CNT__WIDTH                                      6
#define RETR_NOTIFY_MSG_QW0__CNT__MASK                                    0x3f
#define RETR_NOTIFY_MSG_QW0__CNT__RESET_VALUE                              0x0

//-----Access structure typedef for Message:RETR_NOTIFY_MSG_QW1
typedef union {
  struct {
    u64 retr_psn     : 24;
    u64 retr_psn_vld : 1;
    u64 rsvd0        : 39;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RETR_NOTIFY_MSG_QW1;
//-----MACRO defines for Message:RETR_NOTIFY_MSG_QW1

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD
#define RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD__MSB                              24
#define RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD__LSB                              24
#define RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD__WIDTH                             1
#define RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD__MASK                      0x1000000
#define RETR_NOTIFY_MSG_QW1__RETR_PSN_VLD__RESET_VALUE                     0x0

//-----MACRO defines for fields:RETR_NOTIFY_MSG_QW1__RETR_PSN
#define RETR_NOTIFY_MSG_QW1__RETR_PSN__MSB                                  23
#define RETR_NOTIFY_MSG_QW1__RETR_PSN__LSB                                   0
#define RETR_NOTIFY_MSG_QW1__RETR_PSN__WIDTH                                24
#define RETR_NOTIFY_MSG_QW1__RETR_PSN__MASK                           0xffffff
#define RETR_NOTIFY_MSG_QW1__RETR_PSN__RESET_VALUE                         0x0

typedef struct {
  RETR_NOTIFY_MSG_QW0  qw0;
  RETR_NOTIFY_MSG_QW1  qw1;
} RETR_NOTIFY_MSG;
//QW_CNT is actual number - 1
#define RETR_NOTIFY_MSG_QW_CNT                                               1
//-----MACRO defines for  Message Group RETR_RSP_MSG: 0x240000
#define RETR_RSP_MSG_MSG_ID                                               0x24
//-----Access structure typedef for Message:RETR_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 28;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RETR_RSP_MSG_QW0;
//-----MACRO defines for Message:RETR_RSP_MSG_QW0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__STA
#define RETR_RSP_MSG_QW0__STA__MSB                                          63
#define RETR_RSP_MSG_QW0__STA__LSB                                          60
#define RETR_RSP_MSG_QW0__STA__WIDTH                                         4
#define RETR_RSP_MSG_QW0__STA__MASK                         0xf000000000000000
#define RETR_RSP_MSG_QW0__STA__RESET_VALUE                                 0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__MSG_ID
#define RETR_RSP_MSG_QW0__MSG_ID__MSB                                       31
#define RETR_RSP_MSG_QW0__MSG_ID__LSB                                       24
#define RETR_RSP_MSG_QW0__MSG_ID__WIDTH                                      8
#define RETR_RSP_MSG_QW0__MSG_ID__MASK                              0xff000000
#define RETR_RSP_MSG_QW0__MSG_ID__RESET_VALUE                              0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__REQ_TAG
#define RETR_RSP_MSG_QW0__REQ_TAG__MSB                                      23
#define RETR_RSP_MSG_QW0__REQ_TAG__LSB                                      16
#define RETR_RSP_MSG_QW0__REQ_TAG__WIDTH                                     8
#define RETR_RSP_MSG_QW0__REQ_TAG__MASK                               0xff0000
#define RETR_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                             0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__SRC
#define RETR_RSP_MSG_QW0__SRC__MSB                                          15
#define RETR_RSP_MSG_QW0__SRC__LSB                                          12
#define RETR_RSP_MSG_QW0__SRC__WIDTH                                         4
#define RETR_RSP_MSG_QW0__SRC__MASK                                     0xf000
#define RETR_RSP_MSG_QW0__SRC__RESET_VALUE                                 0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__DST
#define RETR_RSP_MSG_QW0__DST__MSB                                          11
#define RETR_RSP_MSG_QW0__DST__LSB                                          10
#define RETR_RSP_MSG_QW0__DST__WIDTH                                         2
#define RETR_RSP_MSG_QW0__DST__MASK                                      0xc00
#define RETR_RSP_MSG_QW0__DST__RESET_VALUE                                 0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__DSTFIFO
#define RETR_RSP_MSG_QW0__DSTFIFO__MSB                                       9
#define RETR_RSP_MSG_QW0__DSTFIFO__LSB                                       6
#define RETR_RSP_MSG_QW0__DSTFIFO__WIDTH                                     4
#define RETR_RSP_MSG_QW0__DSTFIFO__MASK                                  0x3c0
#define RETR_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                             0x0

//-----MACRO defines for fields:RETR_RSP_MSG_QW0__CNT
#define RETR_RSP_MSG_QW0__CNT__MSB                                           5
#define RETR_RSP_MSG_QW0__CNT__LSB                                           0
#define RETR_RSP_MSG_QW0__CNT__WIDTH                                         6
#define RETR_RSP_MSG_QW0__CNT__MASK                                       0x3f
#define RETR_RSP_MSG_QW0__CNT__RESET_VALUE                                 0x0

typedef struct {
  RETR_RSP_MSG_QW0  qw0;
} RETR_RSP_MSG;
//QW_CNT is actual number - 1
#define RETR_RSP_MSG_QW_CNT                                                  0
//-----MACRO defines for  Message Group AEQ_REQ_MSG: 0x270000
#define AEQ_REQ_MSG_MSG_ID                                                0x27
//-----Access structure typedef for Message:AEQ_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt        : 6;
    u64 dstfifo    : 4;
    u64 dst        : 2;
    u64 src        : 4;
    u64 req_tag    : 8;
    u64 msg_id     : 8;
    u64 qpn        : 17;
    u64 fpm        : 10;
    u64 no_rsp     : 1;
    u64 flush      : 1;
    u64 flush_type : 2;
    u64 rsvd0      : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AEQ_REQ_MSG_QW0;
//-----MACRO defines for Message:AEQ_REQ_MSG_QW0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__FLUSH_TYPE
#define AEQ_REQ_MSG_QW0__FLUSH_TYPE__MSB                                    62
#define AEQ_REQ_MSG_QW0__FLUSH_TYPE__LSB                                    61
#define AEQ_REQ_MSG_QW0__FLUSH_TYPE__WIDTH                                   2
#define AEQ_REQ_MSG_QW0__FLUSH_TYPE__MASK                   0x6000000000000000
#define AEQ_REQ_MSG_QW0__FLUSH_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__FLUSH
#define AEQ_REQ_MSG_QW0__FLUSH__MSB                                         60
#define AEQ_REQ_MSG_QW0__FLUSH__LSB                                         60
#define AEQ_REQ_MSG_QW0__FLUSH__WIDTH                                        1
#define AEQ_REQ_MSG_QW0__FLUSH__MASK                        0x1000000000000000
#define AEQ_REQ_MSG_QW0__FLUSH__RESET_VALUE                                0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__NO_RSP
#define AEQ_REQ_MSG_QW0__NO_RSP__MSB                                        59
#define AEQ_REQ_MSG_QW0__NO_RSP__LSB                                        59
#define AEQ_REQ_MSG_QW0__NO_RSP__WIDTH                                       1
#define AEQ_REQ_MSG_QW0__NO_RSP__MASK                        0x800000000000000
#define AEQ_REQ_MSG_QW0__NO_RSP__RESET_VALUE                               0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__FPM
#define AEQ_REQ_MSG_QW0__FPM__MSB                                           58
#define AEQ_REQ_MSG_QW0__FPM__LSB                                           49
#define AEQ_REQ_MSG_QW0__FPM__WIDTH                                         10
#define AEQ_REQ_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define AEQ_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__QPN
#define AEQ_REQ_MSG_QW0__QPN__MSB                                           48
#define AEQ_REQ_MSG_QW0__QPN__LSB                                           32
#define AEQ_REQ_MSG_QW0__QPN__WIDTH                                         17
#define AEQ_REQ_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define AEQ_REQ_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__MSG_ID
#define AEQ_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define AEQ_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define AEQ_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define AEQ_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define AEQ_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__REQ_TAG
#define AEQ_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define AEQ_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define AEQ_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define AEQ_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define AEQ_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__SRC
#define AEQ_REQ_MSG_QW0__SRC__MSB                                           15
#define AEQ_REQ_MSG_QW0__SRC__LSB                                           12
#define AEQ_REQ_MSG_QW0__SRC__WIDTH                                          4
#define AEQ_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define AEQ_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__DST
#define AEQ_REQ_MSG_QW0__DST__MSB                                           11
#define AEQ_REQ_MSG_QW0__DST__LSB                                           10
#define AEQ_REQ_MSG_QW0__DST__WIDTH                                          2
#define AEQ_REQ_MSG_QW0__DST__MASK                                       0xc00
#define AEQ_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__DSTFIFO
#define AEQ_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define AEQ_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define AEQ_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define AEQ_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define AEQ_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW0__CNT
#define AEQ_REQ_MSG_QW0__CNT__MSB                                            5
#define AEQ_REQ_MSG_QW0__CNT__LSB                                            0
#define AEQ_REQ_MSG_QW0__CNT__WIDTH                                          6
#define AEQ_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define AEQ_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:AEQ_REQ_MSG_QW1
typedef union {
  struct {
    u64 cpl_ctx_val : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AEQ_REQ_MSG_QW1;
//-----MACRO defines for Message:AEQ_REQ_MSG_QW1

//-----MACRO defines for fields:AEQ_REQ_MSG_QW1__CPL_CTX_VAL
#define AEQ_REQ_MSG_QW1__CPL_CTX_VAL__MSB                                   63
#define AEQ_REQ_MSG_QW1__CPL_CTX_VAL__LSB                                    0
#define AEQ_REQ_MSG_QW1__CPL_CTX_VAL__WIDTH                                 64
#define AEQ_REQ_MSG_QW1__CPL_CTX_VAL__MASK                  0xffffffffffffffff
#define AEQ_REQ_MSG_QW1__CPL_CTX_VAL__RESET_VALUE                          0x0

//-----Access structure typedef for Message:AEQ_REQ_MSG_QW2
typedef union {
  struct {
    u64 qp_cq_id      : 18;
    u64 wq_desc_index : 15;
    u64 rsvd0         : 1;
    u64 ae_code       : 12;
    u64 rsvd1         : 4;
    u64 ae_source     : 4;
    u64 rdma_state    : 3;
    u64 rsvd2         : 6;
    u64 aeqe_valid    : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AEQ_REQ_MSG_QW2;
//-----MACRO defines for Message:AEQ_REQ_MSG_QW2

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__AEQE_VALID
#define AEQ_REQ_MSG_QW2__AEQE_VALID__MSB                                    63
#define AEQ_REQ_MSG_QW2__AEQE_VALID__LSB                                    63
#define AEQ_REQ_MSG_QW2__AEQE_VALID__WIDTH                                   1
#define AEQ_REQ_MSG_QW2__AEQE_VALID__MASK                   0x8000000000000000
#define AEQ_REQ_MSG_QW2__AEQE_VALID__RESET_VALUE                           0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__RDMA_STATE
#define AEQ_REQ_MSG_QW2__RDMA_STATE__MSB                                    56
#define AEQ_REQ_MSG_QW2__RDMA_STATE__LSB                                    54
#define AEQ_REQ_MSG_QW2__RDMA_STATE__WIDTH                                   3
#define AEQ_REQ_MSG_QW2__RDMA_STATE__MASK                    0x1c0000000000000
#define AEQ_REQ_MSG_QW2__RDMA_STATE__RESET_VALUE                           0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__AE_SOURCE
#define AEQ_REQ_MSG_QW2__AE_SOURCE__MSB                                     53
#define AEQ_REQ_MSG_QW2__AE_SOURCE__LSB                                     50
#define AEQ_REQ_MSG_QW2__AE_SOURCE__WIDTH                                    4
#define AEQ_REQ_MSG_QW2__AE_SOURCE__MASK                      0x3c000000000000
#define AEQ_REQ_MSG_QW2__AE_SOURCE__RESET_VALUE                            0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__AE_CODE
#define AEQ_REQ_MSG_QW2__AE_CODE__MSB                                       45
#define AEQ_REQ_MSG_QW2__AE_CODE__LSB                                       34
#define AEQ_REQ_MSG_QW2__AE_CODE__WIDTH                                     12
#define AEQ_REQ_MSG_QW2__AE_CODE__MASK                          0x3ffc00000000
#define AEQ_REQ_MSG_QW2__AE_CODE__RESET_VALUE                              0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__WQ_DESC_INDEX
#define AEQ_REQ_MSG_QW2__WQ_DESC_INDEX__MSB                                 32
#define AEQ_REQ_MSG_QW2__WQ_DESC_INDEX__LSB                                 18
#define AEQ_REQ_MSG_QW2__WQ_DESC_INDEX__WIDTH                               15
#define AEQ_REQ_MSG_QW2__WQ_DESC_INDEX__MASK                       0x1fffc0000
#define AEQ_REQ_MSG_QW2__WQ_DESC_INDEX__RESET_VALUE                        0x0

//-----MACRO defines for fields:AEQ_REQ_MSG_QW2__QP_CQ_ID
#define AEQ_REQ_MSG_QW2__QP_CQ_ID__MSB                                      17
#define AEQ_REQ_MSG_QW2__QP_CQ_ID__LSB                                       0
#define AEQ_REQ_MSG_QW2__QP_CQ_ID__WIDTH                                    18
#define AEQ_REQ_MSG_QW2__QP_CQ_ID__MASK                                0x3ffff
#define AEQ_REQ_MSG_QW2__QP_CQ_ID__RESET_VALUE                             0x0

typedef struct {
  AEQ_REQ_MSG_QW0  qw0;
  AEQ_REQ_MSG_QW1  qw1;
  AEQ_REQ_MSG_QW2  qw2;
} AEQ_REQ_MSG;
//QW_CNT is actual number - 1
#define AEQ_REQ_MSG_QW_CNT                                                   2
//-----MACRO defines for  Message Group AEQ_RSP_MSG: 0x280000
#define AEQ_RSP_MSG_MSG_ID                                                0x28
//-----Access structure typedef for Message:AEQ_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AEQ_RSP_MSG_QW0;
//-----MACRO defines for Message:AEQ_RSP_MSG_QW0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__MSG_ID
#define AEQ_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define AEQ_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define AEQ_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define AEQ_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define AEQ_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__REQ_TAG
#define AEQ_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define AEQ_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define AEQ_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define AEQ_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define AEQ_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__SRC
#define AEQ_RSP_MSG_QW0__SRC__MSB                                           15
#define AEQ_RSP_MSG_QW0__SRC__LSB                                           12
#define AEQ_RSP_MSG_QW0__SRC__WIDTH                                          4
#define AEQ_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define AEQ_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__DST
#define AEQ_RSP_MSG_QW0__DST__MSB                                           11
#define AEQ_RSP_MSG_QW0__DST__LSB                                           10
#define AEQ_RSP_MSG_QW0__DST__WIDTH                                          2
#define AEQ_RSP_MSG_QW0__DST__MASK                                       0xc00
#define AEQ_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__DSTFIFO
#define AEQ_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define AEQ_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define AEQ_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define AEQ_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define AEQ_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:AEQ_RSP_MSG_QW0__CNT
#define AEQ_RSP_MSG_QW0__CNT__MSB                                            5
#define AEQ_RSP_MSG_QW0__CNT__LSB                                            0
#define AEQ_RSP_MSG_QW0__CNT__WIDTH                                          6
#define AEQ_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define AEQ_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

typedef struct {
  AEQ_RSP_MSG_QW0  qw0;
} AEQ_RSP_MSG;
//QW_CNT is actual number - 1
#define AEQ_RSP_MSG_QW_CNT                                                   0
//-----MACRO defines for  Message Group CEQ_REQ_MSG: 0x290000
#define CEQ_REQ_MSG_MSG_ID                                                0x29
//-----Access structure typedef for Message:CEQ_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt        : 6;
    u64 dstfifo    : 4;
    u64 dst        : 2;
    u64 src        : 4;
    u64 req_tag    : 8;
    u64 msg_id     : 8;
    u64 ceq_idx    : 8;
    u64 rsvd0      : 9;
    u64 fpm        : 10;
    u64 no_rsp     : 1;
    u64 flush      : 1;
    u64 flush_type : 2;
    u64 rsvd1      : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} CEQ_REQ_MSG_QW0;
//-----MACRO defines for Message:CEQ_REQ_MSG_QW0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__FLUSH_TYPE
#define CEQ_REQ_MSG_QW0__FLUSH_TYPE__MSB                                    62
#define CEQ_REQ_MSG_QW0__FLUSH_TYPE__LSB                                    61
#define CEQ_REQ_MSG_QW0__FLUSH_TYPE__WIDTH                                   2
#define CEQ_REQ_MSG_QW0__FLUSH_TYPE__MASK                   0x6000000000000000
#define CEQ_REQ_MSG_QW0__FLUSH_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__FLUSH
#define CEQ_REQ_MSG_QW0__FLUSH__MSB                                         60
#define CEQ_REQ_MSG_QW0__FLUSH__LSB                                         60
#define CEQ_REQ_MSG_QW0__FLUSH__WIDTH                                        1
#define CEQ_REQ_MSG_QW0__FLUSH__MASK                        0x1000000000000000
#define CEQ_REQ_MSG_QW0__FLUSH__RESET_VALUE                                0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__NO_RSP
#define CEQ_REQ_MSG_QW0__NO_RSP__MSB                                        59
#define CEQ_REQ_MSG_QW0__NO_RSP__LSB                                        59
#define CEQ_REQ_MSG_QW0__NO_RSP__WIDTH                                       1
#define CEQ_REQ_MSG_QW0__NO_RSP__MASK                        0x800000000000000
#define CEQ_REQ_MSG_QW0__NO_RSP__RESET_VALUE                               0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__FPM
#define CEQ_REQ_MSG_QW0__FPM__MSB                                           58
#define CEQ_REQ_MSG_QW0__FPM__LSB                                           49
#define CEQ_REQ_MSG_QW0__FPM__WIDTH                                         10
#define CEQ_REQ_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define CEQ_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__CEQ_IDX
#define CEQ_REQ_MSG_QW0__CEQ_IDX__MSB                                       39
#define CEQ_REQ_MSG_QW0__CEQ_IDX__LSB                                       32
#define CEQ_REQ_MSG_QW0__CEQ_IDX__WIDTH                                      8
#define CEQ_REQ_MSG_QW0__CEQ_IDX__MASK                            0xff00000000
#define CEQ_REQ_MSG_QW0__CEQ_IDX__RESET_VALUE                              0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__MSG_ID
#define CEQ_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define CEQ_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define CEQ_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define CEQ_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define CEQ_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__REQ_TAG
#define CEQ_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define CEQ_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define CEQ_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define CEQ_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define CEQ_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__SRC
#define CEQ_REQ_MSG_QW0__SRC__MSB                                           15
#define CEQ_REQ_MSG_QW0__SRC__LSB                                           12
#define CEQ_REQ_MSG_QW0__SRC__WIDTH                                          4
#define CEQ_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define CEQ_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__DST
#define CEQ_REQ_MSG_QW0__DST__MSB                                           11
#define CEQ_REQ_MSG_QW0__DST__LSB                                           10
#define CEQ_REQ_MSG_QW0__DST__WIDTH                                          2
#define CEQ_REQ_MSG_QW0__DST__MASK                                       0xc00
#define CEQ_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__DSTFIFO
#define CEQ_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define CEQ_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define CEQ_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define CEQ_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define CEQ_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:CEQ_REQ_MSG_QW0__CNT
#define CEQ_REQ_MSG_QW0__CNT__MSB                                            5
#define CEQ_REQ_MSG_QW0__CNT__LSB                                            0
#define CEQ_REQ_MSG_QW0__CNT__WIDTH                                          6
#define CEQ_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define CEQ_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:CEQ_REQ_MSG_QW1
typedef union {
  struct {
    u64 cq_context_value : 63;
    u64 rsvd0            : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} CEQ_REQ_MSG_QW1;
//-----MACRO defines for Message:CEQ_REQ_MSG_QW1

//-----MACRO defines for fields:CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE
#define CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE__MSB                              62
#define CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE__LSB                               0
#define CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE__WIDTH                            63
#define CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE__MASK             0x7fffffffffffffff
#define CEQ_REQ_MSG_QW1__CQ_CONTEXT_VALUE__RESET_VALUE                     0x0

typedef struct {
  CEQ_REQ_MSG_QW0  qw0;
  CEQ_REQ_MSG_QW1  qw1;
} CEQ_REQ_MSG;
//QW_CNT is actual number - 1
#define CEQ_REQ_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group CEQ_RSP_MSG: 0x2a0000
#define CEQ_RSP_MSG_MSG_ID                                                0x2a
//-----Access structure typedef for Message:CEQ_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} CEQ_RSP_MSG_QW0;
//-----MACRO defines for Message:CEQ_RSP_MSG_QW0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__MSG_ID
#define CEQ_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define CEQ_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define CEQ_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define CEQ_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define CEQ_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__REQ_TAG
#define CEQ_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define CEQ_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define CEQ_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define CEQ_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define CEQ_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__SRC
#define CEQ_RSP_MSG_QW0__SRC__MSB                                           15
#define CEQ_RSP_MSG_QW0__SRC__LSB                                           12
#define CEQ_RSP_MSG_QW0__SRC__WIDTH                                          4
#define CEQ_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define CEQ_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__DST
#define CEQ_RSP_MSG_QW0__DST__MSB                                           11
#define CEQ_RSP_MSG_QW0__DST__LSB                                           10
#define CEQ_RSP_MSG_QW0__DST__WIDTH                                          2
#define CEQ_RSP_MSG_QW0__DST__MASK                                       0xc00
#define CEQ_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__DSTFIFO
#define CEQ_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define CEQ_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define CEQ_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define CEQ_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define CEQ_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:CEQ_RSP_MSG_QW0__CNT
#define CEQ_RSP_MSG_QW0__CNT__MSB                                            5
#define CEQ_RSP_MSG_QW0__CNT__LSB                                            0
#define CEQ_RSP_MSG_QW0__CNT__WIDTH                                          6
#define CEQ_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define CEQ_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

typedef struct {
  CEQ_RSP_MSG_QW0  qw0;
} CEQ_RSP_MSG;
//QW_CNT is actual number - 1
#define CEQ_RSP_MSG_QW_CNT                                                   0
//-----MACRO defines for  Message Group MG_REQ_MSG: 0x2b0000
#define MG_REQ_MSG_MSG_ID                                                 0x2b
//-----Access structure typedef for Message:MG_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 mg_id   : 13;
    u64 rsvd0   : 4;
    u64 fpm     : 10;
    u64 rsvd1   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW0;
//-----MACRO defines for Message:MG_REQ_MSG_QW0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__FPM
#define MG_REQ_MSG_QW0__FPM__MSB                                            58
#define MG_REQ_MSG_QW0__FPM__LSB                                            49
#define MG_REQ_MSG_QW0__FPM__WIDTH                                          10
#define MG_REQ_MSG_QW0__FPM__MASK                            0x7fe000000000000
#define MG_REQ_MSG_QW0__FPM__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__MG_ID
#define MG_REQ_MSG_QW0__MG_ID__MSB                                          44
#define MG_REQ_MSG_QW0__MG_ID__LSB                                          32
#define MG_REQ_MSG_QW0__MG_ID__WIDTH                                        13
#define MG_REQ_MSG_QW0__MG_ID__MASK                             0x1fff00000000
#define MG_REQ_MSG_QW0__MG_ID__RESET_VALUE                                 0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__MSG_ID
#define MG_REQ_MSG_QW0__MSG_ID__MSB                                         31
#define MG_REQ_MSG_QW0__MSG_ID__LSB                                         24
#define MG_REQ_MSG_QW0__MSG_ID__WIDTH                                        8
#define MG_REQ_MSG_QW0__MSG_ID__MASK                                0xff000000
#define MG_REQ_MSG_QW0__MSG_ID__RESET_VALUE                                0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__REQ_TAG
#define MG_REQ_MSG_QW0__REQ_TAG__MSB                                        23
#define MG_REQ_MSG_QW0__REQ_TAG__LSB                                        16
#define MG_REQ_MSG_QW0__REQ_TAG__WIDTH                                       8
#define MG_REQ_MSG_QW0__REQ_TAG__MASK                                 0xff0000
#define MG_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                               0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__SRC
#define MG_REQ_MSG_QW0__SRC__MSB                                            15
#define MG_REQ_MSG_QW0__SRC__LSB                                            12
#define MG_REQ_MSG_QW0__SRC__WIDTH                                           4
#define MG_REQ_MSG_QW0__SRC__MASK                                       0xf000
#define MG_REQ_MSG_QW0__SRC__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__DST
#define MG_REQ_MSG_QW0__DST__MSB                                            11
#define MG_REQ_MSG_QW0__DST__LSB                                            10
#define MG_REQ_MSG_QW0__DST__WIDTH                                           2
#define MG_REQ_MSG_QW0__DST__MASK                                        0xc00
#define MG_REQ_MSG_QW0__DST__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__DSTFIFO
#define MG_REQ_MSG_QW0__DSTFIFO__MSB                                         9
#define MG_REQ_MSG_QW0__DSTFIFO__LSB                                         6
#define MG_REQ_MSG_QW0__DSTFIFO__WIDTH                                       4
#define MG_REQ_MSG_QW0__DSTFIFO__MASK                                    0x3c0
#define MG_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                               0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW0__CNT
#define MG_REQ_MSG_QW0__CNT__MSB                                             5
#define MG_REQ_MSG_QW0__CNT__LSB                                             0
#define MG_REQ_MSG_QW0__CNT__WIDTH                                           6
#define MG_REQ_MSG_QW0__CNT__MASK                                         0x3f
#define MG_REQ_MSG_QW0__CNT__RESET_VALUE                                   0x0

//-----Access structure typedef for Message:MG_REQ_MSG_QW1
typedef union {
  struct {
    u64 rsvd0      : 47;
    u64 ipv4       : 1;
    u64 qp_vld_num : 3;
    u64 rsvd1      : 1;
    u64 qp_id_msb  : 8;
    u64 opcode     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW1;
//-----MACRO defines for Message:MG_REQ_MSG_QW1

//-----MACRO defines for fields:MG_REQ_MSG_QW1__OPCODE
#define MG_REQ_MSG_QW1__OPCODE__MSB                                         63
#define MG_REQ_MSG_QW1__OPCODE__LSB                                         60
#define MG_REQ_MSG_QW1__OPCODE__WIDTH                                        4
#define MG_REQ_MSG_QW1__OPCODE__MASK                        0xf000000000000000
#define MG_REQ_MSG_QW1__OPCODE__RESET_VALUE                                0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW1__QP_ID_MSB
#define MG_REQ_MSG_QW1__QP_ID_MSB__MSB                                      59
#define MG_REQ_MSG_QW1__QP_ID_MSB__LSB                                      52
#define MG_REQ_MSG_QW1__QP_ID_MSB__WIDTH                                     8
#define MG_REQ_MSG_QW1__QP_ID_MSB__MASK                      0xff0000000000000
#define MG_REQ_MSG_QW1__QP_ID_MSB__RESET_VALUE                             0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW1__QP_VLD_NUM
#define MG_REQ_MSG_QW1__QP_VLD_NUM__MSB                                     50
#define MG_REQ_MSG_QW1__QP_VLD_NUM__LSB                                     48
#define MG_REQ_MSG_QW1__QP_VLD_NUM__WIDTH                                    3
#define MG_REQ_MSG_QW1__QP_VLD_NUM__MASK                       0x7000000000000
#define MG_REQ_MSG_QW1__QP_VLD_NUM__RESET_VALUE                            0x0

//-----MACRO defines for fields:MG_REQ_MSG_QW1__IPV4
#define MG_REQ_MSG_QW1__IPV4__MSB                                           47
#define MG_REQ_MSG_QW1__IPV4__LSB                                           47
#define MG_REQ_MSG_QW1__IPV4__WIDTH                                          1
#define MG_REQ_MSG_QW1__IPV4__MASK                              0x800000000000
#define MG_REQ_MSG_QW1__IPV4__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:MG_REQ_MSG_QW2
typedef union {
  struct {
    u64 qpn0_3 : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW2;
//-----MACRO defines for Message:MG_REQ_MSG_QW2

//-----MACRO defines for fields:MG_REQ_MSG_QW2__QPN0_3
#define MG_REQ_MSG_QW2__QPN0_3__MSB                                         63
#define MG_REQ_MSG_QW2__QPN0_3__LSB                                          0
#define MG_REQ_MSG_QW2__QPN0_3__WIDTH                                       64
#define MG_REQ_MSG_QW2__QPN0_3__MASK                        0xffffffffffffffff
#define MG_REQ_MSG_QW2__QPN0_3__RESET_VALUE                                0x0

//-----Access structure typedef for Message:MG_REQ_MSG_QW3
typedef union {
  struct {
    u64 qpn4_7 : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW3;
//-----MACRO defines for Message:MG_REQ_MSG_QW3

//-----MACRO defines for fields:MG_REQ_MSG_QW3__QPN4_7
#define MG_REQ_MSG_QW3__QPN4_7__MSB                                         63
#define MG_REQ_MSG_QW3__QPN4_7__LSB                                          0
#define MG_REQ_MSG_QW3__QPN4_7__WIDTH                                       64
#define MG_REQ_MSG_QW3__QPN4_7__MASK                        0xffffffffffffffff
#define MG_REQ_MSG_QW3__QPN4_7__RESET_VALUE                                0x0

//-----Access structure typedef for Message:MG_REQ_MSG_QW4
typedef union {
  struct {
    u64 ip_addr_lo : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW4;
//-----MACRO defines for Message:MG_REQ_MSG_QW4

//-----MACRO defines for fields:MG_REQ_MSG_QW4__IP_ADDR_LO
#define MG_REQ_MSG_QW4__IP_ADDR_LO__MSB                                     63
#define MG_REQ_MSG_QW4__IP_ADDR_LO__LSB                                      0
#define MG_REQ_MSG_QW4__IP_ADDR_LO__WIDTH                                   64
#define MG_REQ_MSG_QW4__IP_ADDR_LO__MASK                    0xffffffffffffffff
#define MG_REQ_MSG_QW4__IP_ADDR_LO__RESET_VALUE                            0x0

//-----Access structure typedef for Message:MG_REQ_MSG_QW5
typedef union {
  struct {
    u64 ip_addr_hi : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_REQ_MSG_QW5;
//-----MACRO defines for Message:MG_REQ_MSG_QW5

//-----MACRO defines for fields:MG_REQ_MSG_QW5__IP_ADDR_HI
#define MG_REQ_MSG_QW5__IP_ADDR_HI__MSB                                     63
#define MG_REQ_MSG_QW5__IP_ADDR_HI__LSB                                      0
#define MG_REQ_MSG_QW5__IP_ADDR_HI__WIDTH                                   64
#define MG_REQ_MSG_QW5__IP_ADDR_HI__MASK                    0xffffffffffffffff
#define MG_REQ_MSG_QW5__IP_ADDR_HI__RESET_VALUE                            0x0

typedef struct {
  MG_REQ_MSG_QW0  qw0;
  MG_REQ_MSG_QW1  qw1;
  MG_REQ_MSG_QW2  qw2;
  MG_REQ_MSG_QW3  qw3;
  MG_REQ_MSG_QW4  qw4;
  MG_REQ_MSG_QW5  qw5;
} MG_REQ_MSG;
//QW_CNT is actual number - 1
#define MG_REQ_MSG_QW_CNT                                                    5
//-----MACRO defines for  Message Group MG_RSP_MSG: 0x2c0000
#define MG_RSP_MSG_MSG_ID                                                 0x2c
//-----Access structure typedef for Message:MG_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 rsvd0   : 10;
    u64 last    : 1;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_RSP_MSG_QW0;
//-----MACRO defines for Message:MG_RSP_MSG_QW0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__STA
#define MG_RSP_MSG_QW0__STA__MSB                                            63
#define MG_RSP_MSG_QW0__STA__LSB                                            60
#define MG_RSP_MSG_QW0__STA__WIDTH                                           4
#define MG_RSP_MSG_QW0__STA__MASK                           0xf000000000000000
#define MG_RSP_MSG_QW0__STA__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__LAST
#define MG_RSP_MSG_QW0__LAST__MSB                                           59
#define MG_RSP_MSG_QW0__LAST__LSB                                           59
#define MG_RSP_MSG_QW0__LAST__WIDTH                                          1
#define MG_RSP_MSG_QW0__LAST__MASK                           0x800000000000000
#define MG_RSP_MSG_QW0__LAST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__QPN
#define MG_RSP_MSG_QW0__QPN__MSB                                            48
#define MG_RSP_MSG_QW0__QPN__LSB                                            32
#define MG_RSP_MSG_QW0__QPN__WIDTH                                          17
#define MG_RSP_MSG_QW0__QPN__MASK                              0x1ffff00000000
#define MG_RSP_MSG_QW0__QPN__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__MSG_ID
#define MG_RSP_MSG_QW0__MSG_ID__MSB                                         31
#define MG_RSP_MSG_QW0__MSG_ID__LSB                                         24
#define MG_RSP_MSG_QW0__MSG_ID__WIDTH                                        8
#define MG_RSP_MSG_QW0__MSG_ID__MASK                                0xff000000
#define MG_RSP_MSG_QW0__MSG_ID__RESET_VALUE                                0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__REQ_TAG
#define MG_RSP_MSG_QW0__REQ_TAG__MSB                                        23
#define MG_RSP_MSG_QW0__REQ_TAG__LSB                                        16
#define MG_RSP_MSG_QW0__REQ_TAG__WIDTH                                       8
#define MG_RSP_MSG_QW0__REQ_TAG__MASK                                 0xff0000
#define MG_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                               0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__SRC
#define MG_RSP_MSG_QW0__SRC__MSB                                            15
#define MG_RSP_MSG_QW0__SRC__LSB                                            12
#define MG_RSP_MSG_QW0__SRC__WIDTH                                           4
#define MG_RSP_MSG_QW0__SRC__MASK                                       0xf000
#define MG_RSP_MSG_QW0__SRC__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__DST
#define MG_RSP_MSG_QW0__DST__MSB                                            11
#define MG_RSP_MSG_QW0__DST__LSB                                            10
#define MG_RSP_MSG_QW0__DST__WIDTH                                           2
#define MG_RSP_MSG_QW0__DST__MASK                                        0xc00
#define MG_RSP_MSG_QW0__DST__RESET_VALUE                                   0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__DSTFIFO
#define MG_RSP_MSG_QW0__DSTFIFO__MSB                                         9
#define MG_RSP_MSG_QW0__DSTFIFO__LSB                                         6
#define MG_RSP_MSG_QW0__DSTFIFO__WIDTH                                       4
#define MG_RSP_MSG_QW0__DSTFIFO__MASK                                    0x3c0
#define MG_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                               0x0

//-----MACRO defines for fields:MG_RSP_MSG_QW0__CNT
#define MG_RSP_MSG_QW0__CNT__MSB                                             5
#define MG_RSP_MSG_QW0__CNT__LSB                                             0
#define MG_RSP_MSG_QW0__CNT__WIDTH                                           6
#define MG_RSP_MSG_QW0__CNT__MASK                                         0x3f
#define MG_RSP_MSG_QW0__CNT__RESET_VALUE                                   0x0

typedef struct {
  MG_RSP_MSG_QW0  qw0;
} MG_RSP_MSG;
//QW_CNT is actual number - 1
#define MG_RSP_MSG_QW_CNT                                                    0
//-----MACRO defines for  Message Group MG_SEARCH_REQ_MSG: 0x2d0000
#define MG_SEARCH_REQ_MSG_MSG_ID                                          0x2d
//-----Access structure typedef for Message:MG_SEARCH_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 17;
    u64 fpm     : 10;
    u64 ipv4    : 1;
    u64 rsvd1   : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_SEARCH_REQ_MSG_QW0;
//-----MACRO defines for Message:MG_SEARCH_REQ_MSG_QW0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__IPV4
#define MG_SEARCH_REQ_MSG_QW0__IPV4__MSB                                    59
#define MG_SEARCH_REQ_MSG_QW0__IPV4__LSB                                    59
#define MG_SEARCH_REQ_MSG_QW0__IPV4__WIDTH                                   1
#define MG_SEARCH_REQ_MSG_QW0__IPV4__MASK                    0x800000000000000
#define MG_SEARCH_REQ_MSG_QW0__IPV4__RESET_VALUE                           0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__FPM
#define MG_SEARCH_REQ_MSG_QW0__FPM__MSB                                     58
#define MG_SEARCH_REQ_MSG_QW0__FPM__LSB                                     49
#define MG_SEARCH_REQ_MSG_QW0__FPM__WIDTH                                   10
#define MG_SEARCH_REQ_MSG_QW0__FPM__MASK                     0x7fe000000000000
#define MG_SEARCH_REQ_MSG_QW0__FPM__RESET_VALUE                            0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__MSG_ID
#define MG_SEARCH_REQ_MSG_QW0__MSG_ID__MSB                                  31
#define MG_SEARCH_REQ_MSG_QW0__MSG_ID__LSB                                  24
#define MG_SEARCH_REQ_MSG_QW0__MSG_ID__WIDTH                                 8
#define MG_SEARCH_REQ_MSG_QW0__MSG_ID__MASK                         0xff000000
#define MG_SEARCH_REQ_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__REQ_TAG
#define MG_SEARCH_REQ_MSG_QW0__REQ_TAG__MSB                                 23
#define MG_SEARCH_REQ_MSG_QW0__REQ_TAG__LSB                                 16
#define MG_SEARCH_REQ_MSG_QW0__REQ_TAG__WIDTH                                8
#define MG_SEARCH_REQ_MSG_QW0__REQ_TAG__MASK                          0xff0000
#define MG_SEARCH_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__SRC
#define MG_SEARCH_REQ_MSG_QW0__SRC__MSB                                     15
#define MG_SEARCH_REQ_MSG_QW0__SRC__LSB                                     12
#define MG_SEARCH_REQ_MSG_QW0__SRC__WIDTH                                    4
#define MG_SEARCH_REQ_MSG_QW0__SRC__MASK                                0xf000
#define MG_SEARCH_REQ_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__DST
#define MG_SEARCH_REQ_MSG_QW0__DST__MSB                                     11
#define MG_SEARCH_REQ_MSG_QW0__DST__LSB                                     10
#define MG_SEARCH_REQ_MSG_QW0__DST__WIDTH                                    2
#define MG_SEARCH_REQ_MSG_QW0__DST__MASK                                 0xc00
#define MG_SEARCH_REQ_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__DSTFIFO
#define MG_SEARCH_REQ_MSG_QW0__DSTFIFO__MSB                                  9
#define MG_SEARCH_REQ_MSG_QW0__DSTFIFO__LSB                                  6
#define MG_SEARCH_REQ_MSG_QW0__DSTFIFO__WIDTH                                4
#define MG_SEARCH_REQ_MSG_QW0__DSTFIFO__MASK                             0x3c0
#define MG_SEARCH_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW0__CNT
#define MG_SEARCH_REQ_MSG_QW0__CNT__MSB                                      5
#define MG_SEARCH_REQ_MSG_QW0__CNT__LSB                                      0
#define MG_SEARCH_REQ_MSG_QW0__CNT__WIDTH                                    6
#define MG_SEARCH_REQ_MSG_QW0__CNT__MASK                                  0x3f
#define MG_SEARCH_REQ_MSG_QW0__CNT__RESET_VALUE                            0x0

//-----Access structure typedef for Message:MG_SEARCH_REQ_MSG_QW1
typedef union {
  struct {
    u64 ip_addr_lo : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_SEARCH_REQ_MSG_QW1;
//-----MACRO defines for Message:MG_SEARCH_REQ_MSG_QW1

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO
#define MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO__MSB                              63
#define MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO__LSB                               0
#define MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO__WIDTH                            64
#define MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO__MASK             0xffffffffffffffff
#define MG_SEARCH_REQ_MSG_QW1__IP_ADDR_LO__RESET_VALUE                     0x0

//-----Access structure typedef for Message:MG_SEARCH_REQ_MSG_QW2
typedef union {
  struct {
    u64 ip_addr_hi : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MG_SEARCH_REQ_MSG_QW2;
//-----MACRO defines for Message:MG_SEARCH_REQ_MSG_QW2

//-----MACRO defines for fields:MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI
#define MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI__MSB                              63
#define MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI__LSB                               0
#define MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI__WIDTH                            64
#define MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI__MASK             0xffffffffffffffff
#define MG_SEARCH_REQ_MSG_QW2__IP_ADDR_HI__RESET_VALUE                     0x0

typedef struct {
  MG_SEARCH_REQ_MSG_QW0  qw0;
  MG_SEARCH_REQ_MSG_QW1  qw1;
  MG_SEARCH_REQ_MSG_QW2  qw2;
} MG_SEARCH_REQ_MSG;
//QW_CNT is actual number - 1
#define MG_SEARCH_REQ_MSG_QW_CNT                                             2
//-----MACRO defines for  Message Group ERR_RPT_MSG: 0x2f0000
#define ERR_RPT_MSG_MSG_ID                                                0x2f
//-----Access structure typedef for Message:ERR_RPT_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 cqn_hi  : 1;
    u64 rsvd0   : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ERR_RPT_MSG_QW0;
//-----MACRO defines for Message:ERR_RPT_MSG_QW0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__CQN_HI
#define ERR_RPT_MSG_QW0__CQN_HI__MSB                                        59
#define ERR_RPT_MSG_QW0__CQN_HI__LSB                                        59
#define ERR_RPT_MSG_QW0__CQN_HI__WIDTH                                       1
#define ERR_RPT_MSG_QW0__CQN_HI__MASK                        0x800000000000000
#define ERR_RPT_MSG_QW0__CQN_HI__RESET_VALUE                               0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__FPM
#define ERR_RPT_MSG_QW0__FPM__MSB                                           58
#define ERR_RPT_MSG_QW0__FPM__LSB                                           49
#define ERR_RPT_MSG_QW0__FPM__WIDTH                                         10
#define ERR_RPT_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define ERR_RPT_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__QPN
#define ERR_RPT_MSG_QW0__QPN__MSB                                           48
#define ERR_RPT_MSG_QW0__QPN__LSB                                           32
#define ERR_RPT_MSG_QW0__QPN__WIDTH                                         17
#define ERR_RPT_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define ERR_RPT_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__MSG_ID
#define ERR_RPT_MSG_QW0__MSG_ID__MSB                                        31
#define ERR_RPT_MSG_QW0__MSG_ID__LSB                                        24
#define ERR_RPT_MSG_QW0__MSG_ID__WIDTH                                       8
#define ERR_RPT_MSG_QW0__MSG_ID__MASK                               0xff000000
#define ERR_RPT_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__REQ_TAG
#define ERR_RPT_MSG_QW0__REQ_TAG__MSB                                       23
#define ERR_RPT_MSG_QW0__REQ_TAG__LSB                                       16
#define ERR_RPT_MSG_QW0__REQ_TAG__WIDTH                                      8
#define ERR_RPT_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define ERR_RPT_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__SRC
#define ERR_RPT_MSG_QW0__SRC__MSB                                           15
#define ERR_RPT_MSG_QW0__SRC__LSB                                           12
#define ERR_RPT_MSG_QW0__SRC__WIDTH                                          4
#define ERR_RPT_MSG_QW0__SRC__MASK                                      0xf000
#define ERR_RPT_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__DST
#define ERR_RPT_MSG_QW0__DST__MSB                                           11
#define ERR_RPT_MSG_QW0__DST__LSB                                           10
#define ERR_RPT_MSG_QW0__DST__WIDTH                                          2
#define ERR_RPT_MSG_QW0__DST__MASK                                       0xc00
#define ERR_RPT_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__DSTFIFO
#define ERR_RPT_MSG_QW0__DSTFIFO__MSB                                        9
#define ERR_RPT_MSG_QW0__DSTFIFO__LSB                                        6
#define ERR_RPT_MSG_QW0__DSTFIFO__WIDTH                                      4
#define ERR_RPT_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define ERR_RPT_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW0__CNT
#define ERR_RPT_MSG_QW0__CNT__MSB                                            5
#define ERR_RPT_MSG_QW0__CNT__LSB                                            0
#define ERR_RPT_MSG_QW0__CNT__WIDTH                                          6
#define ERR_RPT_MSG_QW0__CNT__MASK                                        0x3f
#define ERR_RPT_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:ERR_RPT_MSG_QW1
typedef union {
  struct {
    u64 errcode           : 32;
    u64 asyn              : 1;
    u64 signal_completion : 1;
    u64 rsvd0             : 6;
    u64 psn               : 24;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ERR_RPT_MSG_QW1;
//-----MACRO defines for Message:ERR_RPT_MSG_QW1

//-----MACRO defines for fields:ERR_RPT_MSG_QW1__PSN
#define ERR_RPT_MSG_QW1__PSN__MSB                                           63
#define ERR_RPT_MSG_QW1__PSN__LSB                                           40
#define ERR_RPT_MSG_QW1__PSN__WIDTH                                         24
#define ERR_RPT_MSG_QW1__PSN__MASK                          0xffffff0000000000
#define ERR_RPT_MSG_QW1__PSN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW1__SIGNAL_COMPLETION
#define ERR_RPT_MSG_QW1__SIGNAL_COMPLETION__MSB                             33
#define ERR_RPT_MSG_QW1__SIGNAL_COMPLETION__LSB                             33
#define ERR_RPT_MSG_QW1__SIGNAL_COMPLETION__WIDTH                            1
#define ERR_RPT_MSG_QW1__SIGNAL_COMPLETION__MASK                   0x200000000
#define ERR_RPT_MSG_QW1__SIGNAL_COMPLETION__RESET_VALUE                    0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW1__ASYN
#define ERR_RPT_MSG_QW1__ASYN__MSB                                          32
#define ERR_RPT_MSG_QW1__ASYN__LSB                                          32
#define ERR_RPT_MSG_QW1__ASYN__WIDTH                                         1
#define ERR_RPT_MSG_QW1__ASYN__MASK                                0x100000000
#define ERR_RPT_MSG_QW1__ASYN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW1__ERRCODE
#define ERR_RPT_MSG_QW1__ERRCODE__MSB                                       31
#define ERR_RPT_MSG_QW1__ERRCODE__LSB                                        0
#define ERR_RPT_MSG_QW1__ERRCODE__WIDTH                                     32
#define ERR_RPT_MSG_QW1__ERRCODE__MASK                              0xffffffff
#define ERR_RPT_MSG_QW1__ERRCODE__RESET_VALUE                              0x0

//-----Access structure typedef for Message:ERR_RPT_MSG_QW2
typedef union {
  struct {
    u64 rdb_buf_ofst : 2;
    u64 rdb_buf_ptr  : 10;
    u64 dup_pkt_tag  : 10;
    u64 dup_pkt      : 1;
    u64 opcode       : 8;
    u64 rsvd0        : 1;
    u64 po_len       : 14;
    u64 wqe_idx      : 16;
    u64 rsvd1        : 2;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ERR_RPT_MSG_QW2;
//-----MACRO defines for Message:ERR_RPT_MSG_QW2

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__WQE_IDX
#define ERR_RPT_MSG_QW2__WQE_IDX__MSB                                       61
#define ERR_RPT_MSG_QW2__WQE_IDX__LSB                                       46
#define ERR_RPT_MSG_QW2__WQE_IDX__WIDTH                                     16
#define ERR_RPT_MSG_QW2__WQE_IDX__MASK                      0x3fffc00000000000
#define ERR_RPT_MSG_QW2__WQE_IDX__RESET_VALUE                              0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__PO_LEN
#define ERR_RPT_MSG_QW2__PO_LEN__MSB                                        45
#define ERR_RPT_MSG_QW2__PO_LEN__LSB                                        32
#define ERR_RPT_MSG_QW2__PO_LEN__WIDTH                                      14
#define ERR_RPT_MSG_QW2__PO_LEN__MASK                           0x3fff00000000
#define ERR_RPT_MSG_QW2__PO_LEN__RESET_VALUE                               0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__OPCODE
#define ERR_RPT_MSG_QW2__OPCODE__MSB                                        30
#define ERR_RPT_MSG_QW2__OPCODE__LSB                                        23
#define ERR_RPT_MSG_QW2__OPCODE__WIDTH                                       8
#define ERR_RPT_MSG_QW2__OPCODE__MASK                               0x7f800000
#define ERR_RPT_MSG_QW2__OPCODE__RESET_VALUE                               0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__DUP_PKT
#define ERR_RPT_MSG_QW2__DUP_PKT__MSB                                       22
#define ERR_RPT_MSG_QW2__DUP_PKT__LSB                                       22
#define ERR_RPT_MSG_QW2__DUP_PKT__WIDTH                                      1
#define ERR_RPT_MSG_QW2__DUP_PKT__MASK                                0x400000
#define ERR_RPT_MSG_QW2__DUP_PKT__RESET_VALUE                              0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__DUP_PKT_TAG
#define ERR_RPT_MSG_QW2__DUP_PKT_TAG__MSB                                   21
#define ERR_RPT_MSG_QW2__DUP_PKT_TAG__LSB                                   12
#define ERR_RPT_MSG_QW2__DUP_PKT_TAG__WIDTH                                 10
#define ERR_RPT_MSG_QW2__DUP_PKT_TAG__MASK                            0x3ff000
#define ERR_RPT_MSG_QW2__DUP_PKT_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__RDB_BUF_PTR
#define ERR_RPT_MSG_QW2__RDB_BUF_PTR__MSB                                   11
#define ERR_RPT_MSG_QW2__RDB_BUF_PTR__LSB                                    2
#define ERR_RPT_MSG_QW2__RDB_BUF_PTR__WIDTH                                 10
#define ERR_RPT_MSG_QW2__RDB_BUF_PTR__MASK                               0xffc
#define ERR_RPT_MSG_QW2__RDB_BUF_PTR__RESET_VALUE                          0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW2__RDB_BUF_OFST
#define ERR_RPT_MSG_QW2__RDB_BUF_OFST__MSB                                   1
#define ERR_RPT_MSG_QW2__RDB_BUF_OFST__LSB                                   0
#define ERR_RPT_MSG_QW2__RDB_BUF_OFST__WIDTH                                 2
#define ERR_RPT_MSG_QW2__RDB_BUF_OFST__MASK                                0x3
#define ERR_RPT_MSG_QW2__RDB_BUF_OFST__RESET_VALUE                         0x0

//-----Access structure typedef for Message:ERR_RPT_MSG_QW3
typedef union {
  struct {
    u64 sqcqe_hmcpageofst : 5;
    u64 sqcqe_hmcpage     : 19;
    u64 rsvd0             : 40;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ERR_RPT_MSG_QW3;
//-----MACRO defines for Message:ERR_RPT_MSG_QW3

//-----MACRO defines for fields:ERR_RPT_MSG_QW3__SQCQE_HMCPAGE
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGE__MSB                                 23
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGE__LSB                                  5
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGE__WIDTH                               19
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGE__MASK                          0xffffe0
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGE__RESET_VALUE                        0x0

//-----MACRO defines for fields:ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST__MSB                              4
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST__LSB                              0
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST__WIDTH                            5
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST__MASK                          0x1f
#define ERR_RPT_MSG_QW3__SQCQE_HMCPAGEOFST__RESET_VALUE                    0x0

//-----Access structure typedef for Message:ERR_RPT_MSG_QW4
typedef union {
  struct {
    u64 bth_ibeh : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ERR_RPT_MSG_QW4;
//-----MACRO defines for Message:ERR_RPT_MSG_QW4

//-----MACRO defines for fields:ERR_RPT_MSG_QW4__BTH_IBEH
#define ERR_RPT_MSG_QW4__BTH_IBEH__MSB                                      63
#define ERR_RPT_MSG_QW4__BTH_IBEH__LSB                                       0
#define ERR_RPT_MSG_QW4__BTH_IBEH__WIDTH                                    64
#define ERR_RPT_MSG_QW4__BTH_IBEH__MASK                     0xffffffffffffffff
#define ERR_RPT_MSG_QW4__BTH_IBEH__RESET_VALUE                             0x0

typedef struct {
  ERR_RPT_MSG_QW0  qw0;
  ERR_RPT_MSG_QW1  qw1;
  ERR_RPT_MSG_QW2  qw2;
  ERR_RPT_MSG_QW3  qw3;
  ERR_RPT_MSG_QW4  qw4;
} ERR_RPT_MSG;
//QW_CNT is actual number - 1
#define ERR_RPT_MSG_QW_CNT                                                   4
//-----MACRO defines for  Message Group RTO_REQ_MSG: 0x300000
#define RTO_REQ_MSG_MSG_ID                                                0x30
//-----Access structure typedef for Message:RTO_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt            : 6;
    u64 dstfifo        : 4;
    u64 dst            : 2;
    u64 src            : 4;
    u64 req_tag        : 8;
    u64 msg_id         : 8;
    u64 qpn            : 17;
    u64 fpm            : 10;
    u64 retr_first_pkt : 1;
    u64 rebind_to_slot : 1;
    u64 retry          : 1;
    u64 packet_type    : 1;
    u64 fw_owned       : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_REQ_MSG_QW0;
//-----MACRO defines for Message:RTO_REQ_MSG_QW0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__FW_OWNED
#define RTO_REQ_MSG_QW0__FW_OWNED__MSB                                      63
#define RTO_REQ_MSG_QW0__FW_OWNED__LSB                                      63
#define RTO_REQ_MSG_QW0__FW_OWNED__WIDTH                                     1
#define RTO_REQ_MSG_QW0__FW_OWNED__MASK                     0x8000000000000000
#define RTO_REQ_MSG_QW0__FW_OWNED__RESET_VALUE                             0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__PACKET_TYPE
#define RTO_REQ_MSG_QW0__PACKET_TYPE__MSB                                   62
#define RTO_REQ_MSG_QW0__PACKET_TYPE__LSB                                   62
#define RTO_REQ_MSG_QW0__PACKET_TYPE__WIDTH                                  1
#define RTO_REQ_MSG_QW0__PACKET_TYPE__MASK                  0x4000000000000000
#define RTO_REQ_MSG_QW0__PACKET_TYPE__RESET_VALUE                          0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__RETRY
#define RTO_REQ_MSG_QW0__RETRY__MSB                                         61
#define RTO_REQ_MSG_QW0__RETRY__LSB                                         61
#define RTO_REQ_MSG_QW0__RETRY__WIDTH                                        1
#define RTO_REQ_MSG_QW0__RETRY__MASK                        0x2000000000000000
#define RTO_REQ_MSG_QW0__RETRY__RESET_VALUE                                0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__REBIND_TO_SLOT
#define RTO_REQ_MSG_QW0__REBIND_TO_SLOT__MSB                                60
#define RTO_REQ_MSG_QW0__REBIND_TO_SLOT__LSB                                60
#define RTO_REQ_MSG_QW0__REBIND_TO_SLOT__WIDTH                               1
#define RTO_REQ_MSG_QW0__REBIND_TO_SLOT__MASK               0x1000000000000000
#define RTO_REQ_MSG_QW0__REBIND_TO_SLOT__RESET_VALUE                       0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__RETR_FIRST_PKT
#define RTO_REQ_MSG_QW0__RETR_FIRST_PKT__MSB                                59
#define RTO_REQ_MSG_QW0__RETR_FIRST_PKT__LSB                                59
#define RTO_REQ_MSG_QW0__RETR_FIRST_PKT__WIDTH                               1
#define RTO_REQ_MSG_QW0__RETR_FIRST_PKT__MASK                0x800000000000000
#define RTO_REQ_MSG_QW0__RETR_FIRST_PKT__RESET_VALUE                       0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__FPM
#define RTO_REQ_MSG_QW0__FPM__MSB                                           58
#define RTO_REQ_MSG_QW0__FPM__LSB                                           49
#define RTO_REQ_MSG_QW0__FPM__WIDTH                                         10
#define RTO_REQ_MSG_QW0__FPM__MASK                           0x7fe000000000000
#define RTO_REQ_MSG_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__QPN
#define RTO_REQ_MSG_QW0__QPN__MSB                                           48
#define RTO_REQ_MSG_QW0__QPN__LSB                                           32
#define RTO_REQ_MSG_QW0__QPN__WIDTH                                         17
#define RTO_REQ_MSG_QW0__QPN__MASK                             0x1ffff00000000
#define RTO_REQ_MSG_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__MSG_ID
#define RTO_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define RTO_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define RTO_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define RTO_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define RTO_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__REQ_TAG
#define RTO_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define RTO_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define RTO_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define RTO_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define RTO_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__SRC
#define RTO_REQ_MSG_QW0__SRC__MSB                                           15
#define RTO_REQ_MSG_QW0__SRC__LSB                                           12
#define RTO_REQ_MSG_QW0__SRC__WIDTH                                          4
#define RTO_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define RTO_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__DST
#define RTO_REQ_MSG_QW0__DST__MSB                                           11
#define RTO_REQ_MSG_QW0__DST__LSB                                           10
#define RTO_REQ_MSG_QW0__DST__WIDTH                                          2
#define RTO_REQ_MSG_QW0__DST__MASK                                       0xc00
#define RTO_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__DSTFIFO
#define RTO_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define RTO_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define RTO_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define RTO_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define RTO_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW0__CNT
#define RTO_REQ_MSG_QW0__CNT__MSB                                            5
#define RTO_REQ_MSG_QW0__CNT__LSB                                            0
#define RTO_REQ_MSG_QW0__CNT__WIDTH                                          6
#define RTO_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define RTO_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:RTO_REQ_MSG_QW1
typedef union {
  struct {
    u64 to_val                   : 8;
    u64 rsvd0                    : 11;
    u64 rebind_coarse_slotid     : 9;
    u64 rebind_coarse_slotid_vld : 1;
    u64 rsvd1                    : 3;
    u64 psn                      : 24;
    u64 fw_use_coarse_timer      : 1;
    u64 rsvd2                    : 6;
    u64 need_rsp                 : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_REQ_MSG_QW1;
//-----MACRO defines for Message:RTO_REQ_MSG_QW1

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__NEED_RSP
#define RTO_REQ_MSG_QW1__NEED_RSP__MSB                                      63
#define RTO_REQ_MSG_QW1__NEED_RSP__LSB                                      63
#define RTO_REQ_MSG_QW1__NEED_RSP__WIDTH                                     1
#define RTO_REQ_MSG_QW1__NEED_RSP__MASK                     0x8000000000000000
#define RTO_REQ_MSG_QW1__NEED_RSP__RESET_VALUE                             0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER
#define RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER__MSB                           56
#define RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER__LSB                           56
#define RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER__WIDTH                          1
#define RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER__MASK           0x100000000000000
#define RTO_REQ_MSG_QW1__FW_USE_COARSE_TIMER__RESET_VALUE                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__PSN
#define RTO_REQ_MSG_QW1__PSN__MSB                                           55
#define RTO_REQ_MSG_QW1__PSN__LSB                                           32
#define RTO_REQ_MSG_QW1__PSN__WIDTH                                         24
#define RTO_REQ_MSG_QW1__PSN__MASK                            0xffffff00000000
#define RTO_REQ_MSG_QW1__PSN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD__MSB                      28
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD__LSB                      28
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD__WIDTH                     1
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD__MASK             0x10000000
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID_VLD__RESET_VALUE             0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID__MSB                          27
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID__LSB                          19
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID__WIDTH                         9
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID__MASK                  0xff80000
#define RTO_REQ_MSG_QW1__REBIND_COARSE_SLOTID__RESET_VALUE                 0x0

//-----MACRO defines for fields:RTO_REQ_MSG_QW1__TO_VAL
#define RTO_REQ_MSG_QW1__TO_VAL__MSB                                         7
#define RTO_REQ_MSG_QW1__TO_VAL__LSB                                         0
#define RTO_REQ_MSG_QW1__TO_VAL__WIDTH                                       8
#define RTO_REQ_MSG_QW1__TO_VAL__MASK                                     0xff
#define RTO_REQ_MSG_QW1__TO_VAL__RESET_VALUE                               0x0

typedef struct {
  RTO_REQ_MSG_QW0  qw0;
  RTO_REQ_MSG_QW1  qw1;
} RTO_REQ_MSG;
//QW_CNT is actual number - 1
#define RTO_REQ_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group RTO_RSP_MSG: 0x310000
#define RTO_RSP_MSG_MSG_ID                                                0x31
//-----Access structure typedef for Message:RTO_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt            : 6;
    u64 dstfifo        : 4;
    u64 dst            : 2;
    u64 src            : 4;
    u64 req_tag        : 8;
    u64 msg_id         : 8;
    u64 slotid         : 17;
    u64 additional_val : 8;
    u64 rsvd0          : 3;
    u64 sta            : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_RSP_MSG_QW0;
//-----MACRO defines for Message:RTO_RSP_MSG_QW0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__STA
#define RTO_RSP_MSG_QW0__STA__MSB                                           63
#define RTO_RSP_MSG_QW0__STA__LSB                                           60
#define RTO_RSP_MSG_QW0__STA__WIDTH                                          4
#define RTO_RSP_MSG_QW0__STA__MASK                          0xf000000000000000
#define RTO_RSP_MSG_QW0__STA__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__ADDITIONAL_VAL
#define RTO_RSP_MSG_QW0__ADDITIONAL_VAL__MSB                                56
#define RTO_RSP_MSG_QW0__ADDITIONAL_VAL__LSB                                49
#define RTO_RSP_MSG_QW0__ADDITIONAL_VAL__WIDTH                               8
#define RTO_RSP_MSG_QW0__ADDITIONAL_VAL__MASK                0x1fe000000000000
#define RTO_RSP_MSG_QW0__ADDITIONAL_VAL__RESET_VALUE                       0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__SLOTID
#define RTO_RSP_MSG_QW0__SLOTID__MSB                                        48
#define RTO_RSP_MSG_QW0__SLOTID__LSB                                        32
#define RTO_RSP_MSG_QW0__SLOTID__WIDTH                                      17
#define RTO_RSP_MSG_QW0__SLOTID__MASK                          0x1ffff00000000
#define RTO_RSP_MSG_QW0__SLOTID__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__MSG_ID
#define RTO_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define RTO_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define RTO_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define RTO_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define RTO_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__REQ_TAG
#define RTO_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define RTO_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define RTO_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define RTO_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define RTO_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__SRC
#define RTO_RSP_MSG_QW0__SRC__MSB                                           15
#define RTO_RSP_MSG_QW0__SRC__LSB                                           12
#define RTO_RSP_MSG_QW0__SRC__WIDTH                                          4
#define RTO_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define RTO_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__DST
#define RTO_RSP_MSG_QW0__DST__MSB                                           11
#define RTO_RSP_MSG_QW0__DST__LSB                                           10
#define RTO_RSP_MSG_QW0__DST__WIDTH                                          2
#define RTO_RSP_MSG_QW0__DST__MASK                                       0xc00
#define RTO_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__DSTFIFO
#define RTO_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define RTO_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define RTO_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define RTO_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define RTO_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:RTO_RSP_MSG_QW0__CNT
#define RTO_RSP_MSG_QW0__CNT__MSB                                            5
#define RTO_RSP_MSG_QW0__CNT__LSB                                            0
#define RTO_RSP_MSG_QW0__CNT__WIDTH                                          6
#define RTO_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define RTO_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

typedef struct {
  RTO_RSP_MSG_QW0  qw0;
} RTO_RSP_MSG;
//QW_CNT is actual number - 1
#define RTO_RSP_MSG_QW_CNT                                                   0
//-----MACRO defines for  Message Group RTO_TO_MSG: 0x320000
#define RTO_TO_MSG_MSG_ID                                                 0x32
//-----Access structure typedef for Message:RTO_TO_MSG_QW0
typedef union {
  struct {
    u64 cnt        : 6;
    u64 dstfifo    : 4;
    u64 dst        : 2;
    u64 src        : 4;
    u64 req_tag    : 8;
    u64 msg_id     : 8;
    u64 rsvd0      : 9;
    u64 rtoslotcnt : 18;
    u64 fw_owned   : 1;
    u64 rsvd1      : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_TO_MSG_QW0;
//-----MACRO defines for Message:RTO_TO_MSG_QW0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__FW_OWNED
#define RTO_TO_MSG_QW0__FW_OWNED__MSB                                       59
#define RTO_TO_MSG_QW0__FW_OWNED__LSB                                       59
#define RTO_TO_MSG_QW0__FW_OWNED__WIDTH                                      1
#define RTO_TO_MSG_QW0__FW_OWNED__MASK                       0x800000000000000
#define RTO_TO_MSG_QW0__FW_OWNED__RESET_VALUE                              0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__RTOSLOTCNT
#define RTO_TO_MSG_QW0__RTOSLOTCNT__MSB                                     58
#define RTO_TO_MSG_QW0__RTOSLOTCNT__LSB                                     41
#define RTO_TO_MSG_QW0__RTOSLOTCNT__WIDTH                                   18
#define RTO_TO_MSG_QW0__RTOSLOTCNT__MASK                     0x7fffe0000000000
#define RTO_TO_MSG_QW0__RTOSLOTCNT__RESET_VALUE                            0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__MSG_ID
#define RTO_TO_MSG_QW0__MSG_ID__MSB                                         31
#define RTO_TO_MSG_QW0__MSG_ID__LSB                                         24
#define RTO_TO_MSG_QW0__MSG_ID__WIDTH                                        8
#define RTO_TO_MSG_QW0__MSG_ID__MASK                                0xff000000
#define RTO_TO_MSG_QW0__MSG_ID__RESET_VALUE                                0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__REQ_TAG
#define RTO_TO_MSG_QW0__REQ_TAG__MSB                                        23
#define RTO_TO_MSG_QW0__REQ_TAG__LSB                                        16
#define RTO_TO_MSG_QW0__REQ_TAG__WIDTH                                       8
#define RTO_TO_MSG_QW0__REQ_TAG__MASK                                 0xff0000
#define RTO_TO_MSG_QW0__REQ_TAG__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__SRC
#define RTO_TO_MSG_QW0__SRC__MSB                                            15
#define RTO_TO_MSG_QW0__SRC__LSB                                            12
#define RTO_TO_MSG_QW0__SRC__WIDTH                                           4
#define RTO_TO_MSG_QW0__SRC__MASK                                       0xf000
#define RTO_TO_MSG_QW0__SRC__RESET_VALUE                                   0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__DST
#define RTO_TO_MSG_QW0__DST__MSB                                            11
#define RTO_TO_MSG_QW0__DST__LSB                                            10
#define RTO_TO_MSG_QW0__DST__WIDTH                                           2
#define RTO_TO_MSG_QW0__DST__MASK                                        0xc00
#define RTO_TO_MSG_QW0__DST__RESET_VALUE                                   0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__DSTFIFO
#define RTO_TO_MSG_QW0__DSTFIFO__MSB                                         9
#define RTO_TO_MSG_QW0__DSTFIFO__LSB                                         6
#define RTO_TO_MSG_QW0__DSTFIFO__WIDTH                                       4
#define RTO_TO_MSG_QW0__DSTFIFO__MASK                                    0x3c0
#define RTO_TO_MSG_QW0__DSTFIFO__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_TO_MSG_QW0__CNT
#define RTO_TO_MSG_QW0__CNT__MSB                                             5
#define RTO_TO_MSG_QW0__CNT__LSB                                             0
#define RTO_TO_MSG_QW0__CNT__WIDTH                                           6
#define RTO_TO_MSG_QW0__CNT__MASK                                         0x3f
#define RTO_TO_MSG_QW0__CNT__RESET_VALUE                                   0x0

//-----Access structure typedef for Message:RTO_TO_MSG_QW1
typedef union {
  struct {
    u64 rtoslotidx : 17;
    u64 rsvd0      : 47;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_TO_MSG_QW1;
//-----MACRO defines for Message:RTO_TO_MSG_QW1

//-----MACRO defines for fields:RTO_TO_MSG_QW1__RTOSLOTIDX
#define RTO_TO_MSG_QW1__RTOSLOTIDX__MSB                                     16
#define RTO_TO_MSG_QW1__RTOSLOTIDX__LSB                                      0
#define RTO_TO_MSG_QW1__RTOSLOTIDX__WIDTH                                   17
#define RTO_TO_MSG_QW1__RTOSLOTIDX__MASK                               0x1ffff
#define RTO_TO_MSG_QW1__RTOSLOTIDX__RESET_VALUE                            0x0

typedef struct {
  RTO_TO_MSG_QW0  qw0;
  RTO_TO_MSG_QW1  qw1;
} RTO_TO_MSG;
//QW_CNT is actual number - 1
#define RTO_TO_MSG_QW_CNT                                                    1
//-----MACRO defines for  Message Group FL_RECYCLE_REQ_MSG: 0x330000
#define FL_RECYCLE_REQ_MSG_MSG_ID                                         0x33
//-----Access structure typedef for Message:FL_RECYCLE_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 fl_type : 3;
    u64 rsvd0   : 2;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FL_RECYCLE_REQ_MSG_QW0;
//-----MACRO defines for Message:FL_RECYCLE_REQ_MSG_QW0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__FL_TYPE
#define FL_RECYCLE_REQ_MSG_QW0__FL_TYPE__MSB                                61
#define FL_RECYCLE_REQ_MSG_QW0__FL_TYPE__LSB                                59
#define FL_RECYCLE_REQ_MSG_QW0__FL_TYPE__WIDTH                               3
#define FL_RECYCLE_REQ_MSG_QW0__FL_TYPE__MASK               0x3800000000000000
#define FL_RECYCLE_REQ_MSG_QW0__FL_TYPE__RESET_VALUE                       0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__FPM
#define FL_RECYCLE_REQ_MSG_QW0__FPM__MSB                                    58
#define FL_RECYCLE_REQ_MSG_QW0__FPM__LSB                                    49
#define FL_RECYCLE_REQ_MSG_QW0__FPM__WIDTH                                  10
#define FL_RECYCLE_REQ_MSG_QW0__FPM__MASK                    0x7fe000000000000
#define FL_RECYCLE_REQ_MSG_QW0__FPM__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__QPN
#define FL_RECYCLE_REQ_MSG_QW0__QPN__MSB                                    48
#define FL_RECYCLE_REQ_MSG_QW0__QPN__LSB                                    32
#define FL_RECYCLE_REQ_MSG_QW0__QPN__WIDTH                                  17
#define FL_RECYCLE_REQ_MSG_QW0__QPN__MASK                      0x1ffff00000000
#define FL_RECYCLE_REQ_MSG_QW0__QPN__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__MSG_ID
#define FL_RECYCLE_REQ_MSG_QW0__MSG_ID__MSB                                 31
#define FL_RECYCLE_REQ_MSG_QW0__MSG_ID__LSB                                 24
#define FL_RECYCLE_REQ_MSG_QW0__MSG_ID__WIDTH                                8
#define FL_RECYCLE_REQ_MSG_QW0__MSG_ID__MASK                        0xff000000
#define FL_RECYCLE_REQ_MSG_QW0__MSG_ID__RESET_VALUE                        0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__REQ_TAG
#define FL_RECYCLE_REQ_MSG_QW0__REQ_TAG__MSB                                23
#define FL_RECYCLE_REQ_MSG_QW0__REQ_TAG__LSB                                16
#define FL_RECYCLE_REQ_MSG_QW0__REQ_TAG__WIDTH                               8
#define FL_RECYCLE_REQ_MSG_QW0__REQ_TAG__MASK                         0xff0000
#define FL_RECYCLE_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                       0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__SRC
#define FL_RECYCLE_REQ_MSG_QW0__SRC__MSB                                    15
#define FL_RECYCLE_REQ_MSG_QW0__SRC__LSB                                    12
#define FL_RECYCLE_REQ_MSG_QW0__SRC__WIDTH                                   4
#define FL_RECYCLE_REQ_MSG_QW0__SRC__MASK                               0xf000
#define FL_RECYCLE_REQ_MSG_QW0__SRC__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__DST
#define FL_RECYCLE_REQ_MSG_QW0__DST__MSB                                    11
#define FL_RECYCLE_REQ_MSG_QW0__DST__LSB                                    10
#define FL_RECYCLE_REQ_MSG_QW0__DST__WIDTH                                   2
#define FL_RECYCLE_REQ_MSG_QW0__DST__MASK                                0xc00
#define FL_RECYCLE_REQ_MSG_QW0__DST__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__DSTFIFO
#define FL_RECYCLE_REQ_MSG_QW0__DSTFIFO__MSB                                 9
#define FL_RECYCLE_REQ_MSG_QW0__DSTFIFO__LSB                                 6
#define FL_RECYCLE_REQ_MSG_QW0__DSTFIFO__WIDTH                               4
#define FL_RECYCLE_REQ_MSG_QW0__DSTFIFO__MASK                            0x3c0
#define FL_RECYCLE_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                       0x0

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW0__CNT
#define FL_RECYCLE_REQ_MSG_QW0__CNT__MSB                                     5
#define FL_RECYCLE_REQ_MSG_QW0__CNT__LSB                                     0
#define FL_RECYCLE_REQ_MSG_QW0__CNT__WIDTH                                   6
#define FL_RECYCLE_REQ_MSG_QW0__CNT__MASK                                 0x3f
#define FL_RECYCLE_REQ_MSG_QW0__CNT__RESET_VALUE                           0x0

//-----Access structure typedef for Message:FL_RECYCLE_REQ_MSG_QW1
typedef union {
  struct {
    u64 fle_id : 24;
    u64 rsvd0  : 40;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FL_RECYCLE_REQ_MSG_QW1;
//-----MACRO defines for Message:FL_RECYCLE_REQ_MSG_QW1

//-----MACRO defines for fields:FL_RECYCLE_REQ_MSG_QW1__FLE_ID
#define FL_RECYCLE_REQ_MSG_QW1__FLE_ID__MSB                                 23
#define FL_RECYCLE_REQ_MSG_QW1__FLE_ID__LSB                                  0
#define FL_RECYCLE_REQ_MSG_QW1__FLE_ID__WIDTH                               24
#define FL_RECYCLE_REQ_MSG_QW1__FLE_ID__MASK                          0xffffff
#define FL_RECYCLE_REQ_MSG_QW1__FLE_ID__RESET_VALUE                        0x0

typedef struct {
  FL_RECYCLE_REQ_MSG_QW0  qw0;
  FL_RECYCLE_REQ_MSG_QW1  qw1;
} FL_RECYCLE_REQ_MSG;
//QW_CNT is actual number - 1
#define FL_RECYCLE_REQ_MSG_QW_CNT                                            1
//-----MACRO defines for  Message Group FL_RECYCLE_RSP_MSG: 0x340000
#define FL_RECYCLE_RSP_MSG_MSG_ID                                         0x34
//-----Access structure typedef for Message:FL_RECYCLE_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} FL_RECYCLE_RSP_MSG_QW0;
//-----MACRO defines for Message:FL_RECYCLE_RSP_MSG_QW0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__MSG_ID
#define FL_RECYCLE_RSP_MSG_QW0__MSG_ID__MSB                                 31
#define FL_RECYCLE_RSP_MSG_QW0__MSG_ID__LSB                                 24
#define FL_RECYCLE_RSP_MSG_QW0__MSG_ID__WIDTH                                8
#define FL_RECYCLE_RSP_MSG_QW0__MSG_ID__MASK                        0xff000000
#define FL_RECYCLE_RSP_MSG_QW0__MSG_ID__RESET_VALUE                        0x0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__REQ_TAG
#define FL_RECYCLE_RSP_MSG_QW0__REQ_TAG__MSB                                23
#define FL_RECYCLE_RSP_MSG_QW0__REQ_TAG__LSB                                16
#define FL_RECYCLE_RSP_MSG_QW0__REQ_TAG__WIDTH                               8
#define FL_RECYCLE_RSP_MSG_QW0__REQ_TAG__MASK                         0xff0000
#define FL_RECYCLE_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                       0x0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__SRC
#define FL_RECYCLE_RSP_MSG_QW0__SRC__MSB                                    15
#define FL_RECYCLE_RSP_MSG_QW0__SRC__LSB                                    12
#define FL_RECYCLE_RSP_MSG_QW0__SRC__WIDTH                                   4
#define FL_RECYCLE_RSP_MSG_QW0__SRC__MASK                               0xf000
#define FL_RECYCLE_RSP_MSG_QW0__SRC__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__DST
#define FL_RECYCLE_RSP_MSG_QW0__DST__MSB                                    11
#define FL_RECYCLE_RSP_MSG_QW0__DST__LSB                                    10
#define FL_RECYCLE_RSP_MSG_QW0__DST__WIDTH                                   2
#define FL_RECYCLE_RSP_MSG_QW0__DST__MASK                                0xc00
#define FL_RECYCLE_RSP_MSG_QW0__DST__RESET_VALUE                           0x0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__DSTFIFO
#define FL_RECYCLE_RSP_MSG_QW0__DSTFIFO__MSB                                 9
#define FL_RECYCLE_RSP_MSG_QW0__DSTFIFO__LSB                                 6
#define FL_RECYCLE_RSP_MSG_QW0__DSTFIFO__WIDTH                               4
#define FL_RECYCLE_RSP_MSG_QW0__DSTFIFO__MASK                            0x3c0
#define FL_RECYCLE_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                       0x0

//-----MACRO defines for fields:FL_RECYCLE_RSP_MSG_QW0__CNT
#define FL_RECYCLE_RSP_MSG_QW0__CNT__MSB                                     5
#define FL_RECYCLE_RSP_MSG_QW0__CNT__LSB                                     0
#define FL_RECYCLE_RSP_MSG_QW0__CNT__WIDTH                                   6
#define FL_RECYCLE_RSP_MSG_QW0__CNT__MASK                                 0x3f
#define FL_RECYCLE_RSP_MSG_QW0__CNT__RESET_VALUE                           0x0

typedef struct {
  FL_RECYCLE_RSP_MSG_QW0  qw0;
} FL_RECYCLE_RSP_MSG;
//QW_CNT is actual number - 1
#define FL_RECYCLE_RSP_MSG_QW_CNT                                            0
//-----MACRO defines for  Message Group OUTB_DCQCN_BCNT_EXPIRE_MSG: 0x350000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_MSG_ID                                 0x35
//-----Access structure typedef for Message:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 qset    : 9;
    u64 rsvd0   : 6;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0;
//-----MACRO defines for Message:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET__MSB                           57
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET__LSB                           49
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET__WIDTH                          9
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET__MASK           0x3fe000000000000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QSET__RESET_VALUE                  0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN__MSB                            48
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN__LSB                            32
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN__WIDTH                          17
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN__MASK              0x1ffff00000000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__QPN__RESET_VALUE                   0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID__MSB                         31
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID__LSB                         24
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID__WIDTH                        8
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID__MASK                0xff000000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__MSG_ID__RESET_VALUE                0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG__MSB                        23
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG__LSB                        16
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG__WIDTH                       8
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG__MASK                 0xff0000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__REQ_TAG__RESET_VALUE               0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC__MSB                            15
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC__LSB                            12
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC__WIDTH                           4
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC__MASK                       0xf000
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__SRC__RESET_VALUE                   0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST__MSB                            11
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST__LSB                            10
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST__WIDTH                           2
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST__MASK                        0xc00
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DST__RESET_VALUE                   0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO__MSB                         9
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO__LSB                         6
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO__WIDTH                       4
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO__MASK                    0x3c0
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__DSTFIFO__RESET_VALUE               0x0

//-----MACRO defines for fields:OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT__MSB                             5
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT__LSB                             0
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT__WIDTH                           6
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT__MASK                         0x3f
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0__CNT__RESET_VALUE                   0x0

typedef struct {
  OUTB_DCQCN_BCNT_EXPIRE_MSG_QW0  qw0;
} OUTB_DCQCN_BCNT_EXPIRE_MSG;
//QW_CNT is actual number - 1
#define OUTB_DCQCN_BCNT_EXPIRE_MSG_QW_CNT                                    0
//-----MACRO defines for  Message Group XMIT_RSP_MSG: 0x360000
#define XMIT_RSP_MSG_MSG_ID                                               0x36
//-----Access structure typedef for Message:XMIT_RSP_MSG_QW0
typedef union {
  struct {
    u32 cnt     : 6;
    u32 dstfifo : 4;
    u32 dst     : 2;
    u32 src     : 4;
    u32 req_tag : 8;
    u32 msg_id  : 8;
  };
  u32 reg;
} XMIT_RSP_MSG_QW0;
//-----MACRO defines for Message:XMIT_RSP_MSG_QW0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__MSG_ID
#define XMIT_RSP_MSG_QW0__MSG_ID__MSB                                       31
#define XMIT_RSP_MSG_QW0__MSG_ID__LSB                                       24
#define XMIT_RSP_MSG_QW0__MSG_ID__WIDTH                                      8
#define XMIT_RSP_MSG_QW0__MSG_ID__MASK                              0xff000000
#define XMIT_RSP_MSG_QW0__MSG_ID__RESET_VALUE                              0x0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__REQ_TAG
#define XMIT_RSP_MSG_QW0__REQ_TAG__MSB                                      23
#define XMIT_RSP_MSG_QW0__REQ_TAG__LSB                                      16
#define XMIT_RSP_MSG_QW0__REQ_TAG__WIDTH                                     8
#define XMIT_RSP_MSG_QW0__REQ_TAG__MASK                               0xff0000
#define XMIT_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                             0x0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__SRC
#define XMIT_RSP_MSG_QW0__SRC__MSB                                          15
#define XMIT_RSP_MSG_QW0__SRC__LSB                                          12
#define XMIT_RSP_MSG_QW0__SRC__WIDTH                                         4
#define XMIT_RSP_MSG_QW0__SRC__MASK                                     0xf000
#define XMIT_RSP_MSG_QW0__SRC__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__DST
#define XMIT_RSP_MSG_QW0__DST__MSB                                          11
#define XMIT_RSP_MSG_QW0__DST__LSB                                          10
#define XMIT_RSP_MSG_QW0__DST__WIDTH                                         2
#define XMIT_RSP_MSG_QW0__DST__MASK                                      0xc00
#define XMIT_RSP_MSG_QW0__DST__RESET_VALUE                                 0x0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__DSTFIFO
#define XMIT_RSP_MSG_QW0__DSTFIFO__MSB                                       9
#define XMIT_RSP_MSG_QW0__DSTFIFO__LSB                                       6
#define XMIT_RSP_MSG_QW0__DSTFIFO__WIDTH                                     4
#define XMIT_RSP_MSG_QW0__DSTFIFO__MASK                                  0x3c0
#define XMIT_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                             0x0

//-----MACRO defines for fields:XMIT_RSP_MSG_QW0__CNT
#define XMIT_RSP_MSG_QW0__CNT__MSB                                           5
#define XMIT_RSP_MSG_QW0__CNT__LSB                                           0
#define XMIT_RSP_MSG_QW0__CNT__WIDTH                                         6
#define XMIT_RSP_MSG_QW0__CNT__MASK                                       0x3f
#define XMIT_RSP_MSG_QW0__CNT__RESET_VALUE                                 0x0

typedef struct {
  XMIT_RSP_MSG_QW0  qw0;
} XMIT_RSP_MSG;
//QW_CNT is actual number - 1
#define XMIT_RSP_MSG_QW_CNT                                                  0
//-----MACRO defines for  Message Group RTO_TO_RSP_MSG: 0x370000
#define RTO_TO_RSP_MSG_MSG_ID                                             0x37
//-----Access structure typedef for Message:RTO_TO_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RTO_TO_RSP_MSG_QW0;
//-----MACRO defines for Message:RTO_TO_RSP_MSG_QW0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__MSG_ID
#define RTO_TO_RSP_MSG_QW0__MSG_ID__MSB                                     31
#define RTO_TO_RSP_MSG_QW0__MSG_ID__LSB                                     24
#define RTO_TO_RSP_MSG_QW0__MSG_ID__WIDTH                                    8
#define RTO_TO_RSP_MSG_QW0__MSG_ID__MASK                            0xff000000
#define RTO_TO_RSP_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__REQ_TAG
#define RTO_TO_RSP_MSG_QW0__REQ_TAG__MSB                                    23
#define RTO_TO_RSP_MSG_QW0__REQ_TAG__LSB                                    16
#define RTO_TO_RSP_MSG_QW0__REQ_TAG__WIDTH                                   8
#define RTO_TO_RSP_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define RTO_TO_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__SRC
#define RTO_TO_RSP_MSG_QW0__SRC__MSB                                        15
#define RTO_TO_RSP_MSG_QW0__SRC__LSB                                        12
#define RTO_TO_RSP_MSG_QW0__SRC__WIDTH                                       4
#define RTO_TO_RSP_MSG_QW0__SRC__MASK                                   0xf000
#define RTO_TO_RSP_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__DST
#define RTO_TO_RSP_MSG_QW0__DST__MSB                                        11
#define RTO_TO_RSP_MSG_QW0__DST__LSB                                        10
#define RTO_TO_RSP_MSG_QW0__DST__WIDTH                                       2
#define RTO_TO_RSP_MSG_QW0__DST__MASK                                    0xc00
#define RTO_TO_RSP_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__DSTFIFO
#define RTO_TO_RSP_MSG_QW0__DSTFIFO__MSB                                     9
#define RTO_TO_RSP_MSG_QW0__DSTFIFO__LSB                                     6
#define RTO_TO_RSP_MSG_QW0__DSTFIFO__WIDTH                                   4
#define RTO_TO_RSP_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define RTO_TO_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:RTO_TO_RSP_MSG_QW0__CNT
#define RTO_TO_RSP_MSG_QW0__CNT__MSB                                         5
#define RTO_TO_RSP_MSG_QW0__CNT__LSB                                         0
#define RTO_TO_RSP_MSG_QW0__CNT__WIDTH                                       6
#define RTO_TO_RSP_MSG_QW0__CNT__MASK                                     0x3f
#define RTO_TO_RSP_MSG_QW0__CNT__RESET_VALUE                               0x0

typedef struct {
  RTO_TO_RSP_MSG_QW0  qw0;
} RTO_TO_RSP_MSG;
//QW_CNT is actual number - 1
#define RTO_TO_RSP_MSG_QW_CNT                                                0
//-----MACRO defines for  Message Group DMA_REQ_MSG: 0x400000
#define DMA_REQ_MSG_MSG_ID                                                0x40
//-----Access structure typedef for Message:DMA_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 ckl     : 1;
    u64 rsvd0   : 27;
    u64 func    : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_REQ_MSG_QW0;
//-----MACRO defines for Message:DMA_REQ_MSG_QW0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__FUNC
#define DMA_REQ_MSG_QW0__FUNC__MSB                                          63
#define DMA_REQ_MSG_QW0__FUNC__LSB                                          60
#define DMA_REQ_MSG_QW0__FUNC__WIDTH                                         4
#define DMA_REQ_MSG_QW0__FUNC__MASK                         0xf000000000000000
#define DMA_REQ_MSG_QW0__FUNC__RESET_VALUE                                 0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__CKL
#define DMA_REQ_MSG_QW0__CKL__MSB                                           32
#define DMA_REQ_MSG_QW0__CKL__LSB                                           32
#define DMA_REQ_MSG_QW0__CKL__WIDTH                                          1
#define DMA_REQ_MSG_QW0__CKL__MASK                                 0x100000000
#define DMA_REQ_MSG_QW0__CKL__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__MSG_ID
#define DMA_REQ_MSG_QW0__MSG_ID__MSB                                        31
#define DMA_REQ_MSG_QW0__MSG_ID__LSB                                        24
#define DMA_REQ_MSG_QW0__MSG_ID__WIDTH                                       8
#define DMA_REQ_MSG_QW0__MSG_ID__MASK                               0xff000000
#define DMA_REQ_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__REQ_TAG
#define DMA_REQ_MSG_QW0__REQ_TAG__MSB                                       23
#define DMA_REQ_MSG_QW0__REQ_TAG__LSB                                       16
#define DMA_REQ_MSG_QW0__REQ_TAG__WIDTH                                      8
#define DMA_REQ_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define DMA_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__SRC
#define DMA_REQ_MSG_QW0__SRC__MSB                                           15
#define DMA_REQ_MSG_QW0__SRC__LSB                                           12
#define DMA_REQ_MSG_QW0__SRC__WIDTH                                          4
#define DMA_REQ_MSG_QW0__SRC__MASK                                      0xf000
#define DMA_REQ_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__DST
#define DMA_REQ_MSG_QW0__DST__MSB                                           11
#define DMA_REQ_MSG_QW0__DST__LSB                                           10
#define DMA_REQ_MSG_QW0__DST__WIDTH                                          2
#define DMA_REQ_MSG_QW0__DST__MASK                                       0xc00
#define DMA_REQ_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__DSTFIFO
#define DMA_REQ_MSG_QW0__DSTFIFO__MSB                                        9
#define DMA_REQ_MSG_QW0__DSTFIFO__LSB                                        6
#define DMA_REQ_MSG_QW0__DSTFIFO__WIDTH                                      4
#define DMA_REQ_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define DMA_REQ_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW0__CNT
#define DMA_REQ_MSG_QW0__CNT__MSB                                            5
#define DMA_REQ_MSG_QW0__CNT__LSB                                            0
#define DMA_REQ_MSG_QW0__CNT__WIDTH                                          6
#define DMA_REQ_MSG_QW0__CNT__MASK                                        0x3f
#define DMA_REQ_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:DMA_REQ_MSG_QW1
typedef union {
  struct {
    u64 addr  : 36;
    u64 rsvd0 : 4;
    u64 blen  : 24;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_REQ_MSG_QW1;
//-----MACRO defines for Message:DMA_REQ_MSG_QW1

//-----MACRO defines for fields:DMA_REQ_MSG_QW1__BLEN
#define DMA_REQ_MSG_QW1__BLEN__MSB                                          63
#define DMA_REQ_MSG_QW1__BLEN__LSB                                          40
#define DMA_REQ_MSG_QW1__BLEN__WIDTH                                        24
#define DMA_REQ_MSG_QW1__BLEN__MASK                         0xffffff0000000000
#define DMA_REQ_MSG_QW1__BLEN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW1__ADDR
#define DMA_REQ_MSG_QW1__ADDR__MSB                                          35
#define DMA_REQ_MSG_QW1__ADDR__LSB                                           0
#define DMA_REQ_MSG_QW1__ADDR__WIDTH                                        36
#define DMA_REQ_MSG_QW1__ADDR__MASK                                0xfffffffff
#define DMA_REQ_MSG_QW1__ADDR__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:DMA_REQ_MSG_QW2
typedef union {
  struct {
    u64 addr  : 36;
    u64 rsvd0 : 4;
    u64 blen  : 24;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_REQ_MSG_QW2;
//-----MACRO defines for Message:DMA_REQ_MSG_QW2

//-----MACRO defines for fields:DMA_REQ_MSG_QW2__BLEN
#define DMA_REQ_MSG_QW2__BLEN__MSB                                          63
#define DMA_REQ_MSG_QW2__BLEN__LSB                                          40
#define DMA_REQ_MSG_QW2__BLEN__WIDTH                                        24
#define DMA_REQ_MSG_QW2__BLEN__MASK                         0xffffff0000000000
#define DMA_REQ_MSG_QW2__BLEN__RESET_VALUE                                 0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW2__ADDR
#define DMA_REQ_MSG_QW2__ADDR__MSB                                          35
#define DMA_REQ_MSG_QW2__ADDR__LSB                                           0
#define DMA_REQ_MSG_QW2__ADDR__WIDTH                                        36
#define DMA_REQ_MSG_QW2__ADDR__MASK                                0xfffffffff
#define DMA_REQ_MSG_QW2__ADDR__RESET_VALUE                                 0x0

//-----Access structure typedef for Message:DMA_REQ_MSG_QW3
typedef union {
  struct {
    u64 skip    : 4;
    u64 rd_blen : 12;
    u64 wr_blen : 12;
    u64 rsvd0   : 4;
    u64 mask    : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_REQ_MSG_QW3;
//-----MACRO defines for Message:DMA_REQ_MSG_QW3

//-----MACRO defines for fields:DMA_REQ_MSG_QW3__SKIP
#define DMA_REQ_MSG_QW3__SKIP__MSB                                           3
#define DMA_REQ_MSG_QW3__SKIP__LSB                                           0
#define DMA_REQ_MSG_QW3__SKIP__WIDTH                                         4
#define DMA_REQ_MSG_QW3__SKIP__MASK                                        0xf
#define DMA_REQ_MSG_QW3__SKIP__RESET_VALUE                                 0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW3__RD_BLEN
#define DMA_REQ_MSG_QW3__RD_BLEN__MSB                                       15
#define DMA_REQ_MSG_QW3__RD_BLEN__LSB                                        4
#define DMA_REQ_MSG_QW3__RD_BLEN__WIDTH                                     12
#define DMA_REQ_MSG_QW3__RD_BLEN__MASK                                  0xfff0
#define DMA_REQ_MSG_QW3__RD_BLEN__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW3__WR_BLEN
#define DMA_REQ_MSG_QW3__WR_BLEN__MSB                                       27
#define DMA_REQ_MSG_QW3__WR_BLEN__LSB                                       16
#define DMA_REQ_MSG_QW3__WR_BLEN__WIDTH                                     12
#define DMA_REQ_MSG_QW3__WR_BLEN__MASK                               0xfff0000
#define DMA_REQ_MSG_QW3__WR_BLEN__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_REQ_MSG_QW3__MASK
#define DMA_REQ_MSG_QW3__MASK__MSB                                          63
#define DMA_REQ_MSG_QW3__MASK__LSB                                          32
#define DMA_REQ_MSG_QW3__MASK__WIDTH                                        32
#define DMA_REQ_MSG_QW3__MASK__MASK                         0xffffffff00000000
#define DMA_REQ_MSG_QW3__MASK__RESET_VALUE                                 0x0

typedef struct {
  DMA_REQ_MSG_QW0  qw0;
  DMA_REQ_MSG_QW1  qw1;
  DMA_REQ_MSG_QW2  qw2;
  DMA_REQ_MSG_QW3  qw3;
} DMA_REQ_MSG;
//QW_CNT is actual number - 1
#define DMA_REQ_MSG_QW_CNT                                                   3
//-----MACRO defines for  Message Group DMA_RSP_MSG: 0x410000
#define DMA_RSP_MSG_MSG_ID                                                0x41
//-----Access structure typedef for Message:DMA_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 ckl     : 1;
    u64 rsvd0   : 3;
    u64 valid   : 1;
    u64 rsvd1   : 3;
    u64 num     : 4;
    u64 rsvd2   : 19;
    u64 sta     : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_RSP_MSG_QW0;
//-----MACRO defines for Message:DMA_RSP_MSG_QW0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__STA
#define DMA_RSP_MSG_QW0__STA__MSB                                           63
#define DMA_RSP_MSG_QW0__STA__LSB                                           63
#define DMA_RSP_MSG_QW0__STA__WIDTH                                          1
#define DMA_RSP_MSG_QW0__STA__MASK                          0x8000000000000000
#define DMA_RSP_MSG_QW0__STA__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__VALID
#define DMA_RSP_MSG_QW0__VALID__MSB                                         36
#define DMA_RSP_MSG_QW0__VALID__LSB                                         36
#define DMA_RSP_MSG_QW0__VALID__WIDTH                                        1
#define DMA_RSP_MSG_QW0__VALID__MASK                              0x1000000000
#define DMA_RSP_MSG_QW0__VALID__RESET_VALUE                                0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__NUM
#define DMA_RSP_MSG_QW0__NUM__MSB                                           43
#define DMA_RSP_MSG_QW0__NUM__LSB                                           40
#define DMA_RSP_MSG_QW0__NUM__WIDTH                                          4
#define DMA_RSP_MSG_QW0__NUM__MASK                               0xf0000000000
#define DMA_RSP_MSG_QW0__NUM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__CKL
#define DMA_RSP_MSG_QW0__CKL__MSB                                           32
#define DMA_RSP_MSG_QW0__CKL__LSB                                           32
#define DMA_RSP_MSG_QW0__CKL__WIDTH                                          1
#define DMA_RSP_MSG_QW0__CKL__MASK                                 0x100000000
#define DMA_RSP_MSG_QW0__CKL__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__MSG_ID
#define DMA_RSP_MSG_QW0__MSG_ID__MSB                                        31
#define DMA_RSP_MSG_QW0__MSG_ID__LSB                                        24
#define DMA_RSP_MSG_QW0__MSG_ID__WIDTH                                       8
#define DMA_RSP_MSG_QW0__MSG_ID__MASK                               0xff000000
#define DMA_RSP_MSG_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__REQ_TAG
#define DMA_RSP_MSG_QW0__REQ_TAG__MSB                                       23
#define DMA_RSP_MSG_QW0__REQ_TAG__LSB                                       16
#define DMA_RSP_MSG_QW0__REQ_TAG__WIDTH                                      8
#define DMA_RSP_MSG_QW0__REQ_TAG__MASK                                0xff0000
#define DMA_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__SRC
#define DMA_RSP_MSG_QW0__SRC__MSB                                           15
#define DMA_RSP_MSG_QW0__SRC__LSB                                           12
#define DMA_RSP_MSG_QW0__SRC__WIDTH                                          4
#define DMA_RSP_MSG_QW0__SRC__MASK                                      0xf000
#define DMA_RSP_MSG_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__DST
#define DMA_RSP_MSG_QW0__DST__MSB                                           11
#define DMA_RSP_MSG_QW0__DST__LSB                                           10
#define DMA_RSP_MSG_QW0__DST__WIDTH                                          2
#define DMA_RSP_MSG_QW0__DST__MASK                                       0xc00
#define DMA_RSP_MSG_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__DSTFIFO
#define DMA_RSP_MSG_QW0__DSTFIFO__MSB                                        9
#define DMA_RSP_MSG_QW0__DSTFIFO__LSB                                        6
#define DMA_RSP_MSG_QW0__DSTFIFO__WIDTH                                      4
#define DMA_RSP_MSG_QW0__DSTFIFO__MASK                                   0x3c0
#define DMA_RSP_MSG_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW0__CNT
#define DMA_RSP_MSG_QW0__CNT__MSB                                            5
#define DMA_RSP_MSG_QW0__CNT__LSB                                            0
#define DMA_RSP_MSG_QW0__CNT__WIDTH                                          6
#define DMA_RSP_MSG_QW0__CNT__MASK                                        0x3f
#define DMA_RSP_MSG_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:DMA_RSP_MSG_QW1
typedef union {
  struct {
    u64 result  : 32;
    u64 addr_lo : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} DMA_RSP_MSG_QW1;
//-----MACRO defines for Message:DMA_RSP_MSG_QW1

//-----MACRO defines for fields:DMA_RSP_MSG_QW1__RESULT
#define DMA_RSP_MSG_QW1__RESULT__MSB                                        31
#define DMA_RSP_MSG_QW1__RESULT__LSB                                         0
#define DMA_RSP_MSG_QW1__RESULT__WIDTH                                      32
#define DMA_RSP_MSG_QW1__RESULT__MASK                               0xffffffff
#define DMA_RSP_MSG_QW1__RESULT__RESET_VALUE                               0x0

//-----MACRO defines for fields:DMA_RSP_MSG_QW1__ADDR_LO
#define DMA_RSP_MSG_QW1__ADDR_LO__MSB                                       63
#define DMA_RSP_MSG_QW1__ADDR_LO__LSB                                       32
#define DMA_RSP_MSG_QW1__ADDR_LO__WIDTH                                     32
#define DMA_RSP_MSG_QW1__ADDR_LO__MASK                      0xffffffff00000000
#define DMA_RSP_MSG_QW1__ADDR_LO__RESET_VALUE                              0x0

typedef struct {
  DMA_RSP_MSG_QW0  qw0;
  DMA_RSP_MSG_QW1  qw1;
} DMA_RSP_MSG;
//QW_CNT is actual number - 1
#define DMA_RSP_MSG_QW_CNT                                                   1
//-----MACRO defines for  Message Group AQM_MNG_TX_CPL: 0xa00000
#define AQM_MNG_TX_CPL_MSG_ID                                             0xa0
//-----Access structure typedef for Message:AQM_MNG_TX_CPL_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_CPL_QW0;
//-----MACRO defines for Message:AQM_MNG_TX_CPL_QW0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__DUMMY
#define AQM_MNG_TX_CPL_QW0__DUMMY__MSB                                      63
#define AQM_MNG_TX_CPL_QW0__DUMMY__LSB                                      63
#define AQM_MNG_TX_CPL_QW0__DUMMY__WIDTH                                     1
#define AQM_MNG_TX_CPL_QW0__DUMMY__MASK                     0x8000000000000000
#define AQM_MNG_TX_CPL_QW0__DUMMY__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__VSI
#define AQM_MNG_TX_CPL_QW0__VSI__MSB                                        58
#define AQM_MNG_TX_CPL_QW0__VSI__LSB                                        49
#define AQM_MNG_TX_CPL_QW0__VSI__WIDTH                                      10
#define AQM_MNG_TX_CPL_QW0__VSI__MASK                        0x7fe000000000000
#define AQM_MNG_TX_CPL_QW0__VSI__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__Q_TYPE
#define AQM_MNG_TX_CPL_QW0__Q_TYPE__MSB                                     39
#define AQM_MNG_TX_CPL_QW0__Q_TYPE__LSB                                     32
#define AQM_MNG_TX_CPL_QW0__Q_TYPE__WIDTH                                    8
#define AQM_MNG_TX_CPL_QW0__Q_TYPE__MASK                          0xff00000000
#define AQM_MNG_TX_CPL_QW0__Q_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__MSG_ID
#define AQM_MNG_TX_CPL_QW0__MSG_ID__MSB                                     31
#define AQM_MNG_TX_CPL_QW0__MSG_ID__LSB                                     24
#define AQM_MNG_TX_CPL_QW0__MSG_ID__WIDTH                                    8
#define AQM_MNG_TX_CPL_QW0__MSG_ID__MASK                            0xff000000
#define AQM_MNG_TX_CPL_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__REQ_TAG
#define AQM_MNG_TX_CPL_QW0__REQ_TAG__MSB                                    23
#define AQM_MNG_TX_CPL_QW0__REQ_TAG__LSB                                    16
#define AQM_MNG_TX_CPL_QW0__REQ_TAG__WIDTH                                   8
#define AQM_MNG_TX_CPL_QW0__REQ_TAG__MASK                             0xff0000
#define AQM_MNG_TX_CPL_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__SRC
#define AQM_MNG_TX_CPL_QW0__SRC__MSB                                        15
#define AQM_MNG_TX_CPL_QW0__SRC__LSB                                        12
#define AQM_MNG_TX_CPL_QW0__SRC__WIDTH                                       4
#define AQM_MNG_TX_CPL_QW0__SRC__MASK                                   0xf000
#define AQM_MNG_TX_CPL_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__DST
#define AQM_MNG_TX_CPL_QW0__DST__MSB                                        11
#define AQM_MNG_TX_CPL_QW0__DST__LSB                                        10
#define AQM_MNG_TX_CPL_QW0__DST__WIDTH                                       2
#define AQM_MNG_TX_CPL_QW0__DST__MASK                                    0xc00
#define AQM_MNG_TX_CPL_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__DSTFIFO
#define AQM_MNG_TX_CPL_QW0__DSTFIFO__MSB                                     9
#define AQM_MNG_TX_CPL_QW0__DSTFIFO__LSB                                     6
#define AQM_MNG_TX_CPL_QW0__DSTFIFO__WIDTH                                   4
#define AQM_MNG_TX_CPL_QW0__DSTFIFO__MASK                                0x3c0
#define AQM_MNG_TX_CPL_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW0__CNT
#define AQM_MNG_TX_CPL_QW0__CNT__MSB                                         5
#define AQM_MNG_TX_CPL_QW0__CNT__LSB                                         0
#define AQM_MNG_TX_CPL_QW0__CNT__WIDTH                                       6
#define AQM_MNG_TX_CPL_QW0__CNT__MASK                                     0x3f
#define AQM_MNG_TX_CPL_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:AQM_MNG_TX_CPL_QW1
typedef union {
  struct {
    u64 rsvd0      : 32;
    u64 local_addr : 24;
    u64 rsvd1      : 6;
    u64 overflow   : 1;
    u64 critical   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_CPL_QW1;
//-----MACRO defines for Message:AQM_MNG_TX_CPL_QW1

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW1__CRITICAL
#define AQM_MNG_TX_CPL_QW1__CRITICAL__MSB                                   63
#define AQM_MNG_TX_CPL_QW1__CRITICAL__LSB                                   63
#define AQM_MNG_TX_CPL_QW1__CRITICAL__WIDTH                                  1
#define AQM_MNG_TX_CPL_QW1__CRITICAL__MASK                  0x8000000000000000
#define AQM_MNG_TX_CPL_QW1__CRITICAL__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW1__OVERFLOW
#define AQM_MNG_TX_CPL_QW1__OVERFLOW__MSB                                   62
#define AQM_MNG_TX_CPL_QW1__OVERFLOW__LSB                                   62
#define AQM_MNG_TX_CPL_QW1__OVERFLOW__WIDTH                                  1
#define AQM_MNG_TX_CPL_QW1__OVERFLOW__MASK                  0x4000000000000000
#define AQM_MNG_TX_CPL_QW1__OVERFLOW__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW1__LOCAL_ADDR
#define AQM_MNG_TX_CPL_QW1__LOCAL_ADDR__MSB                                 55
#define AQM_MNG_TX_CPL_QW1__LOCAL_ADDR__LSB                                 32
#define AQM_MNG_TX_CPL_QW1__LOCAL_ADDR__WIDTH                               24
#define AQM_MNG_TX_CPL_QW1__LOCAL_ADDR__MASK                  0xffffff00000000
#define AQM_MNG_TX_CPL_QW1__LOCAL_ADDR__RESET_VALUE                        0x0

//-----Access structure typedef for Message:AQM_MNG_TX_CPL_QW2
typedef union {
  struct {
    u64 dd           : 1;
    u64 return_value : 7;
    u64 wb           : 1;
    u64 lb           : 1;
    u64 rd           : 1;
    u64 rsvd0        : 1;
    u64 buffer       : 1;
    u64 si           : 1;
    u64 ei           : 1;
    u64 fe           : 1;
    u64 opcode       : 16;
    u64 data_len     : 16;
    u64 mbxid        : 9;
    u64 fw_rsvd      : 7;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_CPL_QW2;
//-----MACRO defines for Message:AQM_MNG_TX_CPL_QW2

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__FW_RSVD
#define AQM_MNG_TX_CPL_QW2__FW_RSVD__MSB                                    63
#define AQM_MNG_TX_CPL_QW2__FW_RSVD__LSB                                    57
#define AQM_MNG_TX_CPL_QW2__FW_RSVD__WIDTH                                   7
#define AQM_MNG_TX_CPL_QW2__FW_RSVD__MASK                   0xfe00000000000000
#define AQM_MNG_TX_CPL_QW2__FW_RSVD__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__MBXID
#define AQM_MNG_TX_CPL_QW2__MBXID__MSB                                      56
#define AQM_MNG_TX_CPL_QW2__MBXID__LSB                                      48
#define AQM_MNG_TX_CPL_QW2__MBXID__WIDTH                                     9
#define AQM_MNG_TX_CPL_QW2__MBXID__MASK                      0x1ff000000000000
#define AQM_MNG_TX_CPL_QW2__MBXID__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__DATA_LEN
#define AQM_MNG_TX_CPL_QW2__DATA_LEN__MSB                                   47
#define AQM_MNG_TX_CPL_QW2__DATA_LEN__LSB                                   32
#define AQM_MNG_TX_CPL_QW2__DATA_LEN__WIDTH                                 16
#define AQM_MNG_TX_CPL_QW2__DATA_LEN__MASK                      0xffff00000000
#define AQM_MNG_TX_CPL_QW2__DATA_LEN__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__OPCODE
#define AQM_MNG_TX_CPL_QW2__OPCODE__MSB                                     31
#define AQM_MNG_TX_CPL_QW2__OPCODE__LSB                                     16
#define AQM_MNG_TX_CPL_QW2__OPCODE__WIDTH                                   16
#define AQM_MNG_TX_CPL_QW2__OPCODE__MASK                            0xffff0000
#define AQM_MNG_TX_CPL_QW2__OPCODE__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__FE
#define AQM_MNG_TX_CPL_QW2__FE__MSB                                         15
#define AQM_MNG_TX_CPL_QW2__FE__LSB                                         15
#define AQM_MNG_TX_CPL_QW2__FE__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__FE__MASK                                    0x8000
#define AQM_MNG_TX_CPL_QW2__FE__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__EI
#define AQM_MNG_TX_CPL_QW2__EI__MSB                                         14
#define AQM_MNG_TX_CPL_QW2__EI__LSB                                         14
#define AQM_MNG_TX_CPL_QW2__EI__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__EI__MASK                                    0x4000
#define AQM_MNG_TX_CPL_QW2__EI__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__SI
#define AQM_MNG_TX_CPL_QW2__SI__MSB                                         13
#define AQM_MNG_TX_CPL_QW2__SI__LSB                                         13
#define AQM_MNG_TX_CPL_QW2__SI__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__SI__MASK                                    0x2000
#define AQM_MNG_TX_CPL_QW2__SI__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__BUFFER
#define AQM_MNG_TX_CPL_QW2__BUFFER__MSB                                     12
#define AQM_MNG_TX_CPL_QW2__BUFFER__LSB                                     12
#define AQM_MNG_TX_CPL_QW2__BUFFER__WIDTH                                    1
#define AQM_MNG_TX_CPL_QW2__BUFFER__MASK                                0x1000
#define AQM_MNG_TX_CPL_QW2__BUFFER__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__RD
#define AQM_MNG_TX_CPL_QW2__RD__MSB                                         10
#define AQM_MNG_TX_CPL_QW2__RD__LSB                                         10
#define AQM_MNG_TX_CPL_QW2__RD__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__RD__MASK                                     0x400
#define AQM_MNG_TX_CPL_QW2__RD__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__LB
#define AQM_MNG_TX_CPL_QW2__LB__MSB                                          9
#define AQM_MNG_TX_CPL_QW2__LB__LSB                                          9
#define AQM_MNG_TX_CPL_QW2__LB__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__LB__MASK                                     0x200
#define AQM_MNG_TX_CPL_QW2__LB__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__WB
#define AQM_MNG_TX_CPL_QW2__WB__MSB                                          8
#define AQM_MNG_TX_CPL_QW2__WB__LSB                                          8
#define AQM_MNG_TX_CPL_QW2__WB__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__WB__MASK                                     0x100
#define AQM_MNG_TX_CPL_QW2__WB__RESET_VALUE                                0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__RETURN_VALUE
#define AQM_MNG_TX_CPL_QW2__RETURN_VALUE__MSB                                7
#define AQM_MNG_TX_CPL_QW2__RETURN_VALUE__LSB                                1
#define AQM_MNG_TX_CPL_QW2__RETURN_VALUE__WIDTH                              7
#define AQM_MNG_TX_CPL_QW2__RETURN_VALUE__MASK                            0xfe
#define AQM_MNG_TX_CPL_QW2__RETURN_VALUE__RESET_VALUE                      0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW2__DD
#define AQM_MNG_TX_CPL_QW2__DD__MSB                                          0
#define AQM_MNG_TX_CPL_QW2__DD__LSB                                          0
#define AQM_MNG_TX_CPL_QW2__DD__WIDTH                                        1
#define AQM_MNG_TX_CPL_QW2__DD__MASK                                       0x1
#define AQM_MNG_TX_CPL_QW2__DD__RESET_VALUE                                0x0

//-----Access structure typedef for Message:AQM_MNG_TX_CPL_QW3
typedef union {
  struct {
    u64 addr_hi : 32;
    u64 addr_lo : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_CPL_QW3;
//-----MACRO defines for Message:AQM_MNG_TX_CPL_QW3

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW3__ADDR_LO
#define AQM_MNG_TX_CPL_QW3__ADDR_LO__MSB                                    63
#define AQM_MNG_TX_CPL_QW3__ADDR_LO__LSB                                    32
#define AQM_MNG_TX_CPL_QW3__ADDR_LO__WIDTH                                  32
#define AQM_MNG_TX_CPL_QW3__ADDR_LO__MASK                   0xffffffff00000000
#define AQM_MNG_TX_CPL_QW3__ADDR_LO__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_TX_CPL_QW3__ADDR_HI
#define AQM_MNG_TX_CPL_QW3__ADDR_HI__MSB                                    31
#define AQM_MNG_TX_CPL_QW3__ADDR_HI__LSB                                     0
#define AQM_MNG_TX_CPL_QW3__ADDR_HI__WIDTH                                  32
#define AQM_MNG_TX_CPL_QW3__ADDR_HI__MASK                           0xffffffff
#define AQM_MNG_TX_CPL_QW3__ADDR_HI__RESET_VALUE                           0x0

typedef struct {
  AQM_MNG_TX_CPL_QW0  qw0;
  AQM_MNG_TX_CPL_QW1  qw1;
  AQM_MNG_TX_CPL_QW2  qw2;
  AQM_MNG_TX_CPL_QW3  qw3;
} AQM_MNG_TX_CPL;
//QW_CNT is actual number - 1
#define AQM_MNG_TX_CPL_QW_CNT                                                3
//-----MACRO defines for  Message Group AQM_MNG_TX_WRBK_CPL: 0xa10000
#define AQM_MNG_TX_WRBK_CPL_MSG_ID                                        0xa1
//-----Access structure typedef for Message:AQM_MNG_TX_WRBK_CPL_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_WRBK_CPL_QW0;
//-----MACRO defines for Message:AQM_MNG_TX_WRBK_CPL_QW0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__DUMMY
#define AQM_MNG_TX_WRBK_CPL_QW0__DUMMY__MSB                                 63
#define AQM_MNG_TX_WRBK_CPL_QW0__DUMMY__LSB                                 63
#define AQM_MNG_TX_WRBK_CPL_QW0__DUMMY__WIDTH                                1
#define AQM_MNG_TX_WRBK_CPL_QW0__DUMMY__MASK                0x8000000000000000
#define AQM_MNG_TX_WRBK_CPL_QW0__DUMMY__RESET_VALUE                        0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__VSI
#define AQM_MNG_TX_WRBK_CPL_QW0__VSI__MSB                                   58
#define AQM_MNG_TX_WRBK_CPL_QW0__VSI__LSB                                   49
#define AQM_MNG_TX_WRBK_CPL_QW0__VSI__WIDTH                                 10
#define AQM_MNG_TX_WRBK_CPL_QW0__VSI__MASK                   0x7fe000000000000
#define AQM_MNG_TX_WRBK_CPL_QW0__VSI__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE
#define AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE__MSB                                39
#define AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE__LSB                                32
#define AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE__WIDTH                               8
#define AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE__MASK                     0xff00000000
#define AQM_MNG_TX_WRBK_CPL_QW0__Q_TYPE__RESET_VALUE                       0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID
#define AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID__MSB                                31
#define AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID__LSB                                24
#define AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID__WIDTH                               8
#define AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID__MASK                       0xff000000
#define AQM_MNG_TX_WRBK_CPL_QW0__MSG_ID__RESET_VALUE                       0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG
#define AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG__MSB                               23
#define AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG__LSB                               16
#define AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG__WIDTH                              8
#define AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG__MASK                        0xff0000
#define AQM_MNG_TX_WRBK_CPL_QW0__REQ_TAG__RESET_VALUE                      0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__SRC
#define AQM_MNG_TX_WRBK_CPL_QW0__SRC__MSB                                   15
#define AQM_MNG_TX_WRBK_CPL_QW0__SRC__LSB                                   12
#define AQM_MNG_TX_WRBK_CPL_QW0__SRC__WIDTH                                  4
#define AQM_MNG_TX_WRBK_CPL_QW0__SRC__MASK                              0xf000
#define AQM_MNG_TX_WRBK_CPL_QW0__SRC__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__DST
#define AQM_MNG_TX_WRBK_CPL_QW0__DST__MSB                                   11
#define AQM_MNG_TX_WRBK_CPL_QW0__DST__LSB                                   10
#define AQM_MNG_TX_WRBK_CPL_QW0__DST__WIDTH                                  2
#define AQM_MNG_TX_WRBK_CPL_QW0__DST__MASK                               0xc00
#define AQM_MNG_TX_WRBK_CPL_QW0__DST__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO
#define AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO__MSB                                9
#define AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO__LSB                                6
#define AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO__WIDTH                              4
#define AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO__MASK                           0x3c0
#define AQM_MNG_TX_WRBK_CPL_QW0__DSTFIFO__RESET_VALUE                      0x0

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW0__CNT
#define AQM_MNG_TX_WRBK_CPL_QW0__CNT__MSB                                    5
#define AQM_MNG_TX_WRBK_CPL_QW0__CNT__LSB                                    0
#define AQM_MNG_TX_WRBK_CPL_QW0__CNT__WIDTH                                  6
#define AQM_MNG_TX_WRBK_CPL_QW0__CNT__MASK                                0x3f
#define AQM_MNG_TX_WRBK_CPL_QW0__CNT__RESET_VALUE                          0x0

//-----Access structure typedef for Message:AQM_MNG_TX_WRBK_CPL_QW1
typedef union {
  struct {
    u64 rsvd0     : 63;
    u64 wb_status : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_TX_WRBK_CPL_QW1;
//-----MACRO defines for Message:AQM_MNG_TX_WRBK_CPL_QW1

//-----MACRO defines for fields:AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS
#define AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS__MSB                             63
#define AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS__LSB                             63
#define AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS__WIDTH                            1
#define AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS__MASK            0x8000000000000000
#define AQM_MNG_TX_WRBK_CPL_QW1__WB_STATUS__RESET_VALUE                    0x0

typedef struct {
  AQM_MNG_TX_WRBK_CPL_QW0  qw0;
  AQM_MNG_TX_WRBK_CPL_QW1  qw1;
} AQM_MNG_TX_WRBK_CPL;
//QW_CNT is actual number - 1
#define AQM_MNG_TX_WRBK_CPL_QW_CNT                                           1
//-----MACRO defines for  Message Group AQM_MNG_RX_CPL: 0xa20000
#define AQM_MNG_RX_CPL_MSG_ID                                             0xa2
//-----Access structure typedef for Message:AQM_MNG_RX_CPL_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_RX_CPL_QW0;
//-----MACRO defines for Message:AQM_MNG_RX_CPL_QW0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__DUMMY
#define AQM_MNG_RX_CPL_QW0__DUMMY__MSB                                      63
#define AQM_MNG_RX_CPL_QW0__DUMMY__LSB                                      63
#define AQM_MNG_RX_CPL_QW0__DUMMY__WIDTH                                     1
#define AQM_MNG_RX_CPL_QW0__DUMMY__MASK                     0x8000000000000000
#define AQM_MNG_RX_CPL_QW0__DUMMY__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__VSI
#define AQM_MNG_RX_CPL_QW0__VSI__MSB                                        58
#define AQM_MNG_RX_CPL_QW0__VSI__LSB                                        49
#define AQM_MNG_RX_CPL_QW0__VSI__WIDTH                                      10
#define AQM_MNG_RX_CPL_QW0__VSI__MASK                        0x7fe000000000000
#define AQM_MNG_RX_CPL_QW0__VSI__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__Q_TYPE
#define AQM_MNG_RX_CPL_QW0__Q_TYPE__MSB                                     39
#define AQM_MNG_RX_CPL_QW0__Q_TYPE__LSB                                     32
#define AQM_MNG_RX_CPL_QW0__Q_TYPE__WIDTH                                    8
#define AQM_MNG_RX_CPL_QW0__Q_TYPE__MASK                          0xff00000000
#define AQM_MNG_RX_CPL_QW0__Q_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__MSG_ID
#define AQM_MNG_RX_CPL_QW0__MSG_ID__MSB                                     31
#define AQM_MNG_RX_CPL_QW0__MSG_ID__LSB                                     24
#define AQM_MNG_RX_CPL_QW0__MSG_ID__WIDTH                                    8
#define AQM_MNG_RX_CPL_QW0__MSG_ID__MASK                            0xff000000
#define AQM_MNG_RX_CPL_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__REQ_TAG
#define AQM_MNG_RX_CPL_QW0__REQ_TAG__MSB                                    23
#define AQM_MNG_RX_CPL_QW0__REQ_TAG__LSB                                    16
#define AQM_MNG_RX_CPL_QW0__REQ_TAG__WIDTH                                   8
#define AQM_MNG_RX_CPL_QW0__REQ_TAG__MASK                             0xff0000
#define AQM_MNG_RX_CPL_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__SRC
#define AQM_MNG_RX_CPL_QW0__SRC__MSB                                        15
#define AQM_MNG_RX_CPL_QW0__SRC__LSB                                        12
#define AQM_MNG_RX_CPL_QW0__SRC__WIDTH                                       4
#define AQM_MNG_RX_CPL_QW0__SRC__MASK                                   0xf000
#define AQM_MNG_RX_CPL_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__DST
#define AQM_MNG_RX_CPL_QW0__DST__MSB                                        11
#define AQM_MNG_RX_CPL_QW0__DST__LSB                                        10
#define AQM_MNG_RX_CPL_QW0__DST__WIDTH                                       2
#define AQM_MNG_RX_CPL_QW0__DST__MASK                                    0xc00
#define AQM_MNG_RX_CPL_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__DSTFIFO
#define AQM_MNG_RX_CPL_QW0__DSTFIFO__MSB                                     9
#define AQM_MNG_RX_CPL_QW0__DSTFIFO__LSB                                     6
#define AQM_MNG_RX_CPL_QW0__DSTFIFO__WIDTH                                   4
#define AQM_MNG_RX_CPL_QW0__DSTFIFO__MASK                                0x3c0
#define AQM_MNG_RX_CPL_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW0__CNT
#define AQM_MNG_RX_CPL_QW0__CNT__MSB                                         5
#define AQM_MNG_RX_CPL_QW0__CNT__LSB                                         0
#define AQM_MNG_RX_CPL_QW0__CNT__WIDTH                                       6
#define AQM_MNG_RX_CPL_QW0__CNT__MASK                                     0x3f
#define AQM_MNG_RX_CPL_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:AQM_MNG_RX_CPL_QW1
typedef union {
  struct {
    u64 rsvd0    : 62;
    u64 overflow : 1;
    u64 critical : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_MNG_RX_CPL_QW1;
//-----MACRO defines for Message:AQM_MNG_RX_CPL_QW1

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW1__CRITICAL
#define AQM_MNG_RX_CPL_QW1__CRITICAL__MSB                                   63
#define AQM_MNG_RX_CPL_QW1__CRITICAL__LSB                                   63
#define AQM_MNG_RX_CPL_QW1__CRITICAL__WIDTH                                  1
#define AQM_MNG_RX_CPL_QW1__CRITICAL__MASK                  0x8000000000000000
#define AQM_MNG_RX_CPL_QW1__CRITICAL__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_MNG_RX_CPL_QW1__OVERFLOW
#define AQM_MNG_RX_CPL_QW1__OVERFLOW__MSB                                   62
#define AQM_MNG_RX_CPL_QW1__OVERFLOW__LSB                                   62
#define AQM_MNG_RX_CPL_QW1__OVERFLOW__WIDTH                                  1
#define AQM_MNG_RX_CPL_QW1__OVERFLOW__MASK                  0x4000000000000000
#define AQM_MNG_RX_CPL_QW1__OVERFLOW__RESET_VALUE                          0x0

typedef struct {
  AQM_MNG_RX_CPL_QW0  qw0;
  AQM_MNG_RX_CPL_QW1  qw1;
} AQM_MNG_RX_CPL;
//QW_CNT is actual number - 1
#define AQM_MNG_RX_CPL_QW_CNT                                                1
//-----MACRO defines for  Message Group AQM_RPP_FDIR_REQ: 0xa30000
#define AQM_RPP_FDIR_REQ_MSG_ID                                           0xa3
//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW0;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__DUMMY
#define AQM_RPP_FDIR_REQ_QW0__DUMMY__MSB                                    63
#define AQM_RPP_FDIR_REQ_QW0__DUMMY__LSB                                    63
#define AQM_RPP_FDIR_REQ_QW0__DUMMY__WIDTH                                   1
#define AQM_RPP_FDIR_REQ_QW0__DUMMY__MASK                   0x8000000000000000
#define AQM_RPP_FDIR_REQ_QW0__DUMMY__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__VSI
#define AQM_RPP_FDIR_REQ_QW0__VSI__MSB                                      58
#define AQM_RPP_FDIR_REQ_QW0__VSI__LSB                                      49
#define AQM_RPP_FDIR_REQ_QW0__VSI__WIDTH                                    10
#define AQM_RPP_FDIR_REQ_QW0__VSI__MASK                      0x7fe000000000000
#define AQM_RPP_FDIR_REQ_QW0__VSI__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__Q_TYPE
#define AQM_RPP_FDIR_REQ_QW0__Q_TYPE__MSB                                   39
#define AQM_RPP_FDIR_REQ_QW0__Q_TYPE__LSB                                   32
#define AQM_RPP_FDIR_REQ_QW0__Q_TYPE__WIDTH                                  8
#define AQM_RPP_FDIR_REQ_QW0__Q_TYPE__MASK                        0xff00000000
#define AQM_RPP_FDIR_REQ_QW0__Q_TYPE__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__MSG_ID
#define AQM_RPP_FDIR_REQ_QW0__MSG_ID__MSB                                   31
#define AQM_RPP_FDIR_REQ_QW0__MSG_ID__LSB                                   24
#define AQM_RPP_FDIR_REQ_QW0__MSG_ID__WIDTH                                  8
#define AQM_RPP_FDIR_REQ_QW0__MSG_ID__MASK                          0xff000000
#define AQM_RPP_FDIR_REQ_QW0__MSG_ID__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__REQ_TAG
#define AQM_RPP_FDIR_REQ_QW0__REQ_TAG__MSB                                  23
#define AQM_RPP_FDIR_REQ_QW0__REQ_TAG__LSB                                  16
#define AQM_RPP_FDIR_REQ_QW0__REQ_TAG__WIDTH                                 8
#define AQM_RPP_FDIR_REQ_QW0__REQ_TAG__MASK                           0xff0000
#define AQM_RPP_FDIR_REQ_QW0__REQ_TAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__SRC
#define AQM_RPP_FDIR_REQ_QW0__SRC__MSB                                      15
#define AQM_RPP_FDIR_REQ_QW0__SRC__LSB                                      12
#define AQM_RPP_FDIR_REQ_QW0__SRC__WIDTH                                     4
#define AQM_RPP_FDIR_REQ_QW0__SRC__MASK                                 0xf000
#define AQM_RPP_FDIR_REQ_QW0__SRC__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__DST
#define AQM_RPP_FDIR_REQ_QW0__DST__MSB                                      11
#define AQM_RPP_FDIR_REQ_QW0__DST__LSB                                      10
#define AQM_RPP_FDIR_REQ_QW0__DST__WIDTH                                     2
#define AQM_RPP_FDIR_REQ_QW0__DST__MASK                                  0xc00
#define AQM_RPP_FDIR_REQ_QW0__DST__RESET_VALUE                             0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__DSTFIFO
#define AQM_RPP_FDIR_REQ_QW0__DSTFIFO__MSB                                   9
#define AQM_RPP_FDIR_REQ_QW0__DSTFIFO__LSB                                   6
#define AQM_RPP_FDIR_REQ_QW0__DSTFIFO__WIDTH                                 4
#define AQM_RPP_FDIR_REQ_QW0__DSTFIFO__MASK                              0x3c0
#define AQM_RPP_FDIR_REQ_QW0__DSTFIFO__RESET_VALUE                         0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW0__CNT
#define AQM_RPP_FDIR_REQ_QW0__CNT__MSB                                       5
#define AQM_RPP_FDIR_REQ_QW0__CNT__LSB                                       0
#define AQM_RPP_FDIR_REQ_QW0__CNT__WIDTH                                     6
#define AQM_RPP_FDIR_REQ_QW0__CNT__MASK                                   0x3f
#define AQM_RPP_FDIR_REQ_QW0__CNT__RESET_VALUE                             0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW1
typedef union {
  struct {
    u64 dd           : 1;
    u64 return_value : 7;
    u64 wb           : 1;
    u64 lb           : 1;
    u64 rd           : 1;
    u64 rsvd0        : 1;
    u64 buffer       : 1;
    u64 si           : 1;
    u64 ei           : 1;
    u64 fe           : 1;
    u64 opcode       : 16;
    u64 data_len     : 16;
    u64 mbxid        : 9;
    u64 fw_rsvd      : 7;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW1;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW1

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__FW_RSVD
#define AQM_RPP_FDIR_REQ_QW1__FW_RSVD__MSB                                  63
#define AQM_RPP_FDIR_REQ_QW1__FW_RSVD__LSB                                  57
#define AQM_RPP_FDIR_REQ_QW1__FW_RSVD__WIDTH                                 7
#define AQM_RPP_FDIR_REQ_QW1__FW_RSVD__MASK                 0xfe00000000000000
#define AQM_RPP_FDIR_REQ_QW1__FW_RSVD__RESET_VALUE                         0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__MBXID
#define AQM_RPP_FDIR_REQ_QW1__MBXID__MSB                                    56
#define AQM_RPP_FDIR_REQ_QW1__MBXID__LSB                                    48
#define AQM_RPP_FDIR_REQ_QW1__MBXID__WIDTH                                   9
#define AQM_RPP_FDIR_REQ_QW1__MBXID__MASK                    0x1ff000000000000
#define AQM_RPP_FDIR_REQ_QW1__MBXID__RESET_VALUE                           0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__DATA_LEN
#define AQM_RPP_FDIR_REQ_QW1__DATA_LEN__MSB                                 47
#define AQM_RPP_FDIR_REQ_QW1__DATA_LEN__LSB                                 32
#define AQM_RPP_FDIR_REQ_QW1__DATA_LEN__WIDTH                               16
#define AQM_RPP_FDIR_REQ_QW1__DATA_LEN__MASK                    0xffff00000000
#define AQM_RPP_FDIR_REQ_QW1__DATA_LEN__RESET_VALUE                        0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__OPCODE
#define AQM_RPP_FDIR_REQ_QW1__OPCODE__MSB                                   31
#define AQM_RPP_FDIR_REQ_QW1__OPCODE__LSB                                   16
#define AQM_RPP_FDIR_REQ_QW1__OPCODE__WIDTH                                 16
#define AQM_RPP_FDIR_REQ_QW1__OPCODE__MASK                          0xffff0000
#define AQM_RPP_FDIR_REQ_QW1__OPCODE__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__FE
#define AQM_RPP_FDIR_REQ_QW1__FE__MSB                                       15
#define AQM_RPP_FDIR_REQ_QW1__FE__LSB                                       15
#define AQM_RPP_FDIR_REQ_QW1__FE__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__FE__MASK                                  0x8000
#define AQM_RPP_FDIR_REQ_QW1__FE__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__EI
#define AQM_RPP_FDIR_REQ_QW1__EI__MSB                                       14
#define AQM_RPP_FDIR_REQ_QW1__EI__LSB                                       14
#define AQM_RPP_FDIR_REQ_QW1__EI__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__EI__MASK                                  0x4000
#define AQM_RPP_FDIR_REQ_QW1__EI__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__SI
#define AQM_RPP_FDIR_REQ_QW1__SI__MSB                                       13
#define AQM_RPP_FDIR_REQ_QW1__SI__LSB                                       13
#define AQM_RPP_FDIR_REQ_QW1__SI__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__SI__MASK                                  0x2000
#define AQM_RPP_FDIR_REQ_QW1__SI__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__BUFFER
#define AQM_RPP_FDIR_REQ_QW1__BUFFER__MSB                                   12
#define AQM_RPP_FDIR_REQ_QW1__BUFFER__LSB                                   12
#define AQM_RPP_FDIR_REQ_QW1__BUFFER__WIDTH                                  1
#define AQM_RPP_FDIR_REQ_QW1__BUFFER__MASK                              0x1000
#define AQM_RPP_FDIR_REQ_QW1__BUFFER__RESET_VALUE                          0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__RD
#define AQM_RPP_FDIR_REQ_QW1__RD__MSB                                       10
#define AQM_RPP_FDIR_REQ_QW1__RD__LSB                                       10
#define AQM_RPP_FDIR_REQ_QW1__RD__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__RD__MASK                                   0x400
#define AQM_RPP_FDIR_REQ_QW1__RD__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__LB
#define AQM_RPP_FDIR_REQ_QW1__LB__MSB                                        9
#define AQM_RPP_FDIR_REQ_QW1__LB__LSB                                        9
#define AQM_RPP_FDIR_REQ_QW1__LB__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__LB__MASK                                   0x200
#define AQM_RPP_FDIR_REQ_QW1__LB__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__WB
#define AQM_RPP_FDIR_REQ_QW1__WB__MSB                                        8
#define AQM_RPP_FDIR_REQ_QW1__WB__LSB                                        8
#define AQM_RPP_FDIR_REQ_QW1__WB__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__WB__MASK                                   0x100
#define AQM_RPP_FDIR_REQ_QW1__WB__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE
#define AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE__MSB                              7
#define AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE__LSB                              1
#define AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE__WIDTH                            7
#define AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE__MASK                          0xfe
#define AQM_RPP_FDIR_REQ_QW1__RETURN_VALUE__RESET_VALUE                    0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW1__DD
#define AQM_RPP_FDIR_REQ_QW1__DD__MSB                                        0
#define AQM_RPP_FDIR_REQ_QW1__DD__LSB                                        0
#define AQM_RPP_FDIR_REQ_QW1__DD__WIDTH                                      1
#define AQM_RPP_FDIR_REQ_QW1__DD__MASK                                     0x1
#define AQM_RPP_FDIR_REQ_QW1__DD__RESET_VALUE                              0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW2
typedef union {
  struct {
    u64 addr_hi : 32;
    u64 addr_lo : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW2;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW2

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW2__ADDR_LO
#define AQM_RPP_FDIR_REQ_QW2__ADDR_LO__MSB                                  63
#define AQM_RPP_FDIR_REQ_QW2__ADDR_LO__LSB                                  32
#define AQM_RPP_FDIR_REQ_QW2__ADDR_LO__WIDTH                                32
#define AQM_RPP_FDIR_REQ_QW2__ADDR_LO__MASK                 0xffffffff00000000
#define AQM_RPP_FDIR_REQ_QW2__ADDR_LO__RESET_VALUE                         0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW2__ADDR_HI
#define AQM_RPP_FDIR_REQ_QW2__ADDR_HI__MSB                                  31
#define AQM_RPP_FDIR_REQ_QW2__ADDR_HI__LSB                                   0
#define AQM_RPP_FDIR_REQ_QW2__ADDR_HI__WIDTH                                32
#define AQM_RPP_FDIR_REQ_QW2__ADDR_HI__MASK                         0xffffffff
#define AQM_RPP_FDIR_REQ_QW2__ADDR_HI__RESET_VALUE                         0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW3
typedef union {
  struct {
    u64 ip6_sa1 : 32;
    u64 ip6_sa2 : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW3;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW3

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW3__IP6_SA2
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA2__MSB                                  63
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA2__LSB                                  32
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA2__WIDTH                                32
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA2__MASK                 0xffffffff00000000
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA2__RESET_VALUE                         0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW3__IP6_SA1
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA1__MSB                                  31
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA1__LSB                                   0
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA1__WIDTH                                32
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA1__MASK                         0xffffffff
#define AQM_RPP_FDIR_REQ_QW3__IP6_SA1__RESET_VALUE                         0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW4
typedef union {
  struct {
    u64 ip6_sa3 : 32;
    u64 sa      : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW4;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW4

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW4__SA
#define AQM_RPP_FDIR_REQ_QW4__SA__MSB                                       63
#define AQM_RPP_FDIR_REQ_QW4__SA__LSB                                       32
#define AQM_RPP_FDIR_REQ_QW4__SA__WIDTH                                     32
#define AQM_RPP_FDIR_REQ_QW4__SA__MASK                      0xffffffff00000000
#define AQM_RPP_FDIR_REQ_QW4__SA__RESET_VALUE                              0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW4__IP6_SA3
#define AQM_RPP_FDIR_REQ_QW4__IP6_SA3__MSB                                  31
#define AQM_RPP_FDIR_REQ_QW4__IP6_SA3__LSB                                   0
#define AQM_RPP_FDIR_REQ_QW4__IP6_SA3__WIDTH                                32
#define AQM_RPP_FDIR_REQ_QW4__IP6_SA3__MASK                         0xffffffff
#define AQM_RPP_FDIR_REQ_QW4__IP6_SA3__RESET_VALUE                         0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW5
typedef union {
  struct {
    u64 da    : 32;
    u64 port  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW5;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW5

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW5__PORT
#define AQM_RPP_FDIR_REQ_QW5__PORT__MSB                                     63
#define AQM_RPP_FDIR_REQ_QW5__PORT__LSB                                     32
#define AQM_RPP_FDIR_REQ_QW5__PORT__WIDTH                                   32
#define AQM_RPP_FDIR_REQ_QW5__PORT__MASK                    0xffffffff00000000
#define AQM_RPP_FDIR_REQ_QW5__PORT__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW5__DA
#define AQM_RPP_FDIR_REQ_QW5__DA__MSB                                       31
#define AQM_RPP_FDIR_REQ_QW5__DA__LSB                                        0
#define AQM_RPP_FDIR_REQ_QW5__DA__WIDTH                                     32
#define AQM_RPP_FDIR_REQ_QW5__DA__MASK                              0xffffffff
#define AQM_RPP_FDIR_REQ_QW5__DA__RESET_VALUE                              0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW6
typedef union {
  struct {
    u64 flex  : 32;
    u64 hash  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW6;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW6

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW6__HASH
#define AQM_RPP_FDIR_REQ_QW6__HASH__MSB                                     63
#define AQM_RPP_FDIR_REQ_QW6__HASH__LSB                                     32
#define AQM_RPP_FDIR_REQ_QW6__HASH__WIDTH                                   32
#define AQM_RPP_FDIR_REQ_QW6__HASH__MASK                    0xffffffff00000000
#define AQM_RPP_FDIR_REQ_QW6__HASH__RESET_VALUE                            0x0

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW6__FLEX
#define AQM_RPP_FDIR_REQ_QW6__FLEX__MSB                                     31
#define AQM_RPP_FDIR_REQ_QW6__FLEX__LSB                                      0
#define AQM_RPP_FDIR_REQ_QW6__FLEX__WIDTH                                   32
#define AQM_RPP_FDIR_REQ_QW6__FLEX__MASK                            0xffffffff
#define AQM_RPP_FDIR_REQ_QW6__FLEX__RESET_VALUE                            0x0

//-----Access structure typedef for Message:AQM_RPP_FDIR_REQ_QW7
typedef union {
  struct {
    u64 cmd   : 32;
    u64 rsvd0 : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} AQM_RPP_FDIR_REQ_QW7;
//-----MACRO defines for Message:AQM_RPP_FDIR_REQ_QW7

//-----MACRO defines for fields:AQM_RPP_FDIR_REQ_QW7__CMD
#define AQM_RPP_FDIR_REQ_QW7__CMD__MSB                                      31
#define AQM_RPP_FDIR_REQ_QW7__CMD__LSB                                       0
#define AQM_RPP_FDIR_REQ_QW7__CMD__WIDTH                                    32
#define AQM_RPP_FDIR_REQ_QW7__CMD__MASK                             0xffffffff
#define AQM_RPP_FDIR_REQ_QW7__CMD__RESET_VALUE                             0x0

typedef struct {
  AQM_RPP_FDIR_REQ_QW0  qw0;
  AQM_RPP_FDIR_REQ_QW1  qw1;
  AQM_RPP_FDIR_REQ_QW2  qw2;
  AQM_RPP_FDIR_REQ_QW3  qw3;
  AQM_RPP_FDIR_REQ_QW4  qw4;
  AQM_RPP_FDIR_REQ_QW5  qw5;
  AQM_RPP_FDIR_REQ_QW6  qw6;
  AQM_RPP_FDIR_REQ_QW7  qw7;
} AQM_RPP_FDIR_REQ;
//QW_CNT is actual number - 1
#define AQM_RPP_FDIR_REQ_QW_CNT                                              7
//-----MACRO defines for  Message Group MNG_AQM_TX_WRBK: 0xa40000
#define MNG_AQM_TX_WRBK_MSG_ID                                            0xa4
//-----Access structure typedef for Message:MNG_AQM_TX_WRBK_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_TX_WRBK_QW0;
//-----MACRO defines for Message:MNG_AQM_TX_WRBK_QW0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__DUMMY
#define MNG_AQM_TX_WRBK_QW0__DUMMY__MSB                                     63
#define MNG_AQM_TX_WRBK_QW0__DUMMY__LSB                                     63
#define MNG_AQM_TX_WRBK_QW0__DUMMY__WIDTH                                    1
#define MNG_AQM_TX_WRBK_QW0__DUMMY__MASK                    0x8000000000000000
#define MNG_AQM_TX_WRBK_QW0__DUMMY__RESET_VALUE                            0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__VSI
#define MNG_AQM_TX_WRBK_QW0__VSI__MSB                                       58
#define MNG_AQM_TX_WRBK_QW0__VSI__LSB                                       49
#define MNG_AQM_TX_WRBK_QW0__VSI__WIDTH                                     10
#define MNG_AQM_TX_WRBK_QW0__VSI__MASK                       0x7fe000000000000
#define MNG_AQM_TX_WRBK_QW0__VSI__RESET_VALUE                              0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__Q_TYPE
#define MNG_AQM_TX_WRBK_QW0__Q_TYPE__MSB                                    39
#define MNG_AQM_TX_WRBK_QW0__Q_TYPE__LSB                                    32
#define MNG_AQM_TX_WRBK_QW0__Q_TYPE__WIDTH                                   8
#define MNG_AQM_TX_WRBK_QW0__Q_TYPE__MASK                         0xff00000000
#define MNG_AQM_TX_WRBK_QW0__Q_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__MSG_ID
#define MNG_AQM_TX_WRBK_QW0__MSG_ID__MSB                                    31
#define MNG_AQM_TX_WRBK_QW0__MSG_ID__LSB                                    24
#define MNG_AQM_TX_WRBK_QW0__MSG_ID__WIDTH                                   8
#define MNG_AQM_TX_WRBK_QW0__MSG_ID__MASK                           0xff000000
#define MNG_AQM_TX_WRBK_QW0__MSG_ID__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__REQ_TAG
#define MNG_AQM_TX_WRBK_QW0__REQ_TAG__MSB                                   23
#define MNG_AQM_TX_WRBK_QW0__REQ_TAG__LSB                                   16
#define MNG_AQM_TX_WRBK_QW0__REQ_TAG__WIDTH                                  8
#define MNG_AQM_TX_WRBK_QW0__REQ_TAG__MASK                            0xff0000
#define MNG_AQM_TX_WRBK_QW0__REQ_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__SRC
#define MNG_AQM_TX_WRBK_QW0__SRC__MSB                                       15
#define MNG_AQM_TX_WRBK_QW0__SRC__LSB                                       12
#define MNG_AQM_TX_WRBK_QW0__SRC__WIDTH                                      4
#define MNG_AQM_TX_WRBK_QW0__SRC__MASK                                  0xf000
#define MNG_AQM_TX_WRBK_QW0__SRC__RESET_VALUE                              0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__DST
#define MNG_AQM_TX_WRBK_QW0__DST__MSB                                       11
#define MNG_AQM_TX_WRBK_QW0__DST__LSB                                       10
#define MNG_AQM_TX_WRBK_QW0__DST__WIDTH                                      2
#define MNG_AQM_TX_WRBK_QW0__DST__MASK                                   0xc00
#define MNG_AQM_TX_WRBK_QW0__DST__RESET_VALUE                              0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__DSTFIFO
#define MNG_AQM_TX_WRBK_QW0__DSTFIFO__MSB                                    9
#define MNG_AQM_TX_WRBK_QW0__DSTFIFO__LSB                                    6
#define MNG_AQM_TX_WRBK_QW0__DSTFIFO__WIDTH                                  4
#define MNG_AQM_TX_WRBK_QW0__DSTFIFO__MASK                               0x3c0
#define MNG_AQM_TX_WRBK_QW0__DSTFIFO__RESET_VALUE                          0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW0__CNT
#define MNG_AQM_TX_WRBK_QW0__CNT__MSB                                        5
#define MNG_AQM_TX_WRBK_QW0__CNT__LSB                                        0
#define MNG_AQM_TX_WRBK_QW0__CNT__WIDTH                                      6
#define MNG_AQM_TX_WRBK_QW0__CNT__MASK                                    0x3f
#define MNG_AQM_TX_WRBK_QW0__CNT__RESET_VALUE                              0x0

//-----Access structure typedef for Message:MNG_AQM_TX_WRBK_QW1
typedef union {
  struct {
    u64 rsvd0      : 32;
    u64 local_addr : 24;
    u64 txq_buf    : 1;
    u64 rsvd1      : 7;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_TX_WRBK_QW1;
//-----MACRO defines for Message:MNG_AQM_TX_WRBK_QW1

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW1__TXQ_BUF
#define MNG_AQM_TX_WRBK_QW1__TXQ_BUF__MSB                                   56
#define MNG_AQM_TX_WRBK_QW1__TXQ_BUF__LSB                                   56
#define MNG_AQM_TX_WRBK_QW1__TXQ_BUF__WIDTH                                  1
#define MNG_AQM_TX_WRBK_QW1__TXQ_BUF__MASK                   0x100000000000000
#define MNG_AQM_TX_WRBK_QW1__TXQ_BUF__RESET_VALUE                          0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR
#define MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR__MSB                                55
#define MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR__LSB                                32
#define MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR__WIDTH                              24
#define MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR__MASK                 0xffffff00000000
#define MNG_AQM_TX_WRBK_QW1__LOCAL_ADDR__RESET_VALUE                       0x0

//-----Access structure typedef for Message:MNG_AQM_TX_WRBK_QW2
typedef union {
  struct {
    u64 dd           : 1;
    u64 return_value : 7;
    u64 wb           : 1;
    u64 lb           : 1;
    u64 rd           : 1;
    u64 rsvd0        : 1;
    u64 buffer       : 1;
    u64 si           : 1;
    u64 ei           : 1;
    u64 fe           : 1;
    u64 opcode       : 16;
    u64 data_len     : 16;
    u64 mbxid        : 9;
    u64 fw_rsvd      : 7;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_TX_WRBK_QW2;
//-----MACRO defines for Message:MNG_AQM_TX_WRBK_QW2

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__FW_RSVD
#define MNG_AQM_TX_WRBK_QW2__FW_RSVD__MSB                                   63
#define MNG_AQM_TX_WRBK_QW2__FW_RSVD__LSB                                   57
#define MNG_AQM_TX_WRBK_QW2__FW_RSVD__WIDTH                                  7
#define MNG_AQM_TX_WRBK_QW2__FW_RSVD__MASK                  0xfe00000000000000
#define MNG_AQM_TX_WRBK_QW2__FW_RSVD__RESET_VALUE                          0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__MBXID
#define MNG_AQM_TX_WRBK_QW2__MBXID__MSB                                     56
#define MNG_AQM_TX_WRBK_QW2__MBXID__LSB                                     48
#define MNG_AQM_TX_WRBK_QW2__MBXID__WIDTH                                    9
#define MNG_AQM_TX_WRBK_QW2__MBXID__MASK                     0x1ff000000000000
#define MNG_AQM_TX_WRBK_QW2__MBXID__RESET_VALUE                            0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__DATA_LEN
#define MNG_AQM_TX_WRBK_QW2__DATA_LEN__MSB                                  47
#define MNG_AQM_TX_WRBK_QW2__DATA_LEN__LSB                                  32
#define MNG_AQM_TX_WRBK_QW2__DATA_LEN__WIDTH                                16
#define MNG_AQM_TX_WRBK_QW2__DATA_LEN__MASK                     0xffff00000000
#define MNG_AQM_TX_WRBK_QW2__DATA_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__OPCODE
#define MNG_AQM_TX_WRBK_QW2__OPCODE__MSB                                    31
#define MNG_AQM_TX_WRBK_QW2__OPCODE__LSB                                    16
#define MNG_AQM_TX_WRBK_QW2__OPCODE__WIDTH                                  16
#define MNG_AQM_TX_WRBK_QW2__OPCODE__MASK                           0xffff0000
#define MNG_AQM_TX_WRBK_QW2__OPCODE__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__FE
#define MNG_AQM_TX_WRBK_QW2__FE__MSB                                        15
#define MNG_AQM_TX_WRBK_QW2__FE__LSB                                        15
#define MNG_AQM_TX_WRBK_QW2__FE__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__FE__MASK                                   0x8000
#define MNG_AQM_TX_WRBK_QW2__FE__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__EI
#define MNG_AQM_TX_WRBK_QW2__EI__MSB                                        14
#define MNG_AQM_TX_WRBK_QW2__EI__LSB                                        14
#define MNG_AQM_TX_WRBK_QW2__EI__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__EI__MASK                                   0x4000
#define MNG_AQM_TX_WRBK_QW2__EI__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__SI
#define MNG_AQM_TX_WRBK_QW2__SI__MSB                                        13
#define MNG_AQM_TX_WRBK_QW2__SI__LSB                                        13
#define MNG_AQM_TX_WRBK_QW2__SI__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__SI__MASK                                   0x2000
#define MNG_AQM_TX_WRBK_QW2__SI__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__BUFFER
#define MNG_AQM_TX_WRBK_QW2__BUFFER__MSB                                    12
#define MNG_AQM_TX_WRBK_QW2__BUFFER__LSB                                    12
#define MNG_AQM_TX_WRBK_QW2__BUFFER__WIDTH                                   1
#define MNG_AQM_TX_WRBK_QW2__BUFFER__MASK                               0x1000
#define MNG_AQM_TX_WRBK_QW2__BUFFER__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__RD
#define MNG_AQM_TX_WRBK_QW2__RD__MSB                                        10
#define MNG_AQM_TX_WRBK_QW2__RD__LSB                                        10
#define MNG_AQM_TX_WRBK_QW2__RD__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__RD__MASK                                    0x400
#define MNG_AQM_TX_WRBK_QW2__RD__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__LB
#define MNG_AQM_TX_WRBK_QW2__LB__MSB                                         9
#define MNG_AQM_TX_WRBK_QW2__LB__LSB                                         9
#define MNG_AQM_TX_WRBK_QW2__LB__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__LB__MASK                                    0x200
#define MNG_AQM_TX_WRBK_QW2__LB__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__WB
#define MNG_AQM_TX_WRBK_QW2__WB__MSB                                         8
#define MNG_AQM_TX_WRBK_QW2__WB__LSB                                         8
#define MNG_AQM_TX_WRBK_QW2__WB__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__WB__MASK                                    0x100
#define MNG_AQM_TX_WRBK_QW2__WB__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__RETURN_VALUE
#define MNG_AQM_TX_WRBK_QW2__RETURN_VALUE__MSB                               7
#define MNG_AQM_TX_WRBK_QW2__RETURN_VALUE__LSB                               1
#define MNG_AQM_TX_WRBK_QW2__RETURN_VALUE__WIDTH                             7
#define MNG_AQM_TX_WRBK_QW2__RETURN_VALUE__MASK                           0xfe
#define MNG_AQM_TX_WRBK_QW2__RETURN_VALUE__RESET_VALUE                     0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW2__DD
#define MNG_AQM_TX_WRBK_QW2__DD__MSB                                         0
#define MNG_AQM_TX_WRBK_QW2__DD__LSB                                         0
#define MNG_AQM_TX_WRBK_QW2__DD__WIDTH                                       1
#define MNG_AQM_TX_WRBK_QW2__DD__MASK                                      0x1
#define MNG_AQM_TX_WRBK_QW2__DD__RESET_VALUE                               0x0

//-----Access structure typedef for Message:MNG_AQM_TX_WRBK_QW3
typedef union {
  struct {
    u64 addr_hi : 32;
    u64 addr_lo : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_TX_WRBK_QW3;
//-----MACRO defines for Message:MNG_AQM_TX_WRBK_QW3

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW3__ADDR_LO
#define MNG_AQM_TX_WRBK_QW3__ADDR_LO__MSB                                   63
#define MNG_AQM_TX_WRBK_QW3__ADDR_LO__LSB                                   32
#define MNG_AQM_TX_WRBK_QW3__ADDR_LO__WIDTH                                 32
#define MNG_AQM_TX_WRBK_QW3__ADDR_LO__MASK                  0xffffffff00000000
#define MNG_AQM_TX_WRBK_QW3__ADDR_LO__RESET_VALUE                          0x0

//-----MACRO defines for fields:MNG_AQM_TX_WRBK_QW3__ADDR_HI
#define MNG_AQM_TX_WRBK_QW3__ADDR_HI__MSB                                   31
#define MNG_AQM_TX_WRBK_QW3__ADDR_HI__LSB                                    0
#define MNG_AQM_TX_WRBK_QW3__ADDR_HI__WIDTH                                 32
#define MNG_AQM_TX_WRBK_QW3__ADDR_HI__MASK                          0xffffffff
#define MNG_AQM_TX_WRBK_QW3__ADDR_HI__RESET_VALUE                          0x0

typedef struct {
  MNG_AQM_TX_WRBK_QW0  qw0;
  MNG_AQM_TX_WRBK_QW1  qw1;
  MNG_AQM_TX_WRBK_QW2  qw2;
  MNG_AQM_TX_WRBK_QW3  qw3;
} MNG_AQM_TX_WRBK;
//QW_CNT is actual number - 1
#define MNG_AQM_TX_WRBK_QW_CNT                                               3
//-----MACRO defines for  Message Group MNG_AQM_RX_REQ: 0xa50000
#define MNG_AQM_RX_REQ_MSG_ID                                             0xa5
//-----Access structure typedef for Message:MNG_AQM_RX_REQ_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_RX_REQ_QW0;
//-----MACRO defines for Message:MNG_AQM_RX_REQ_QW0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__DUMMY
#define MNG_AQM_RX_REQ_QW0__DUMMY__MSB                                      63
#define MNG_AQM_RX_REQ_QW0__DUMMY__LSB                                      63
#define MNG_AQM_RX_REQ_QW0__DUMMY__WIDTH                                     1
#define MNG_AQM_RX_REQ_QW0__DUMMY__MASK                     0x8000000000000000
#define MNG_AQM_RX_REQ_QW0__DUMMY__RESET_VALUE                             0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__VSI
#define MNG_AQM_RX_REQ_QW0__VSI__MSB                                        58
#define MNG_AQM_RX_REQ_QW0__VSI__LSB                                        49
#define MNG_AQM_RX_REQ_QW0__VSI__WIDTH                                      10
#define MNG_AQM_RX_REQ_QW0__VSI__MASK                        0x7fe000000000000
#define MNG_AQM_RX_REQ_QW0__VSI__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__Q_TYPE
#define MNG_AQM_RX_REQ_QW0__Q_TYPE__MSB                                     39
#define MNG_AQM_RX_REQ_QW0__Q_TYPE__LSB                                     32
#define MNG_AQM_RX_REQ_QW0__Q_TYPE__WIDTH                                    8
#define MNG_AQM_RX_REQ_QW0__Q_TYPE__MASK                          0xff00000000
#define MNG_AQM_RX_REQ_QW0__Q_TYPE__RESET_VALUE                            0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__MSG_ID
#define MNG_AQM_RX_REQ_QW0__MSG_ID__MSB                                     31
#define MNG_AQM_RX_REQ_QW0__MSG_ID__LSB                                     24
#define MNG_AQM_RX_REQ_QW0__MSG_ID__WIDTH                                    8
#define MNG_AQM_RX_REQ_QW0__MSG_ID__MASK                            0xff000000
#define MNG_AQM_RX_REQ_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__REQ_TAG
#define MNG_AQM_RX_REQ_QW0__REQ_TAG__MSB                                    23
#define MNG_AQM_RX_REQ_QW0__REQ_TAG__LSB                                    16
#define MNG_AQM_RX_REQ_QW0__REQ_TAG__WIDTH                                   8
#define MNG_AQM_RX_REQ_QW0__REQ_TAG__MASK                             0xff0000
#define MNG_AQM_RX_REQ_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__SRC
#define MNG_AQM_RX_REQ_QW0__SRC__MSB                                        15
#define MNG_AQM_RX_REQ_QW0__SRC__LSB                                        12
#define MNG_AQM_RX_REQ_QW0__SRC__WIDTH                                       4
#define MNG_AQM_RX_REQ_QW0__SRC__MASK                                   0xf000
#define MNG_AQM_RX_REQ_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__DST
#define MNG_AQM_RX_REQ_QW0__DST__MSB                                        11
#define MNG_AQM_RX_REQ_QW0__DST__LSB                                        10
#define MNG_AQM_RX_REQ_QW0__DST__WIDTH                                       2
#define MNG_AQM_RX_REQ_QW0__DST__MASK                                    0xc00
#define MNG_AQM_RX_REQ_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__DSTFIFO
#define MNG_AQM_RX_REQ_QW0__DSTFIFO__MSB                                     9
#define MNG_AQM_RX_REQ_QW0__DSTFIFO__LSB                                     6
#define MNG_AQM_RX_REQ_QW0__DSTFIFO__WIDTH                                   4
#define MNG_AQM_RX_REQ_QW0__DSTFIFO__MASK                                0x3c0
#define MNG_AQM_RX_REQ_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW0__CNT
#define MNG_AQM_RX_REQ_QW0__CNT__MSB                                         5
#define MNG_AQM_RX_REQ_QW0__CNT__LSB                                         0
#define MNG_AQM_RX_REQ_QW0__CNT__WIDTH                                       6
#define MNG_AQM_RX_REQ_QW0__CNT__MASK                                     0x3f
#define MNG_AQM_RX_REQ_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:MNG_AQM_RX_REQ_QW1
typedef union {
  struct {
    u64 data_len     : 16;
    u64 opcode       : 16;
    u64 local_addr   : 24;
    u64 return_value : 7;
    u64 rsvd0        : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_RX_REQ_QW1;
//-----MACRO defines for Message:MNG_AQM_RX_REQ_QW1

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW1__RETURN_VALUE
#define MNG_AQM_RX_REQ_QW1__RETURN_VALUE__MSB                               62
#define MNG_AQM_RX_REQ_QW1__RETURN_VALUE__LSB                               56
#define MNG_AQM_RX_REQ_QW1__RETURN_VALUE__WIDTH                              7
#define MNG_AQM_RX_REQ_QW1__RETURN_VALUE__MASK              0x7f00000000000000
#define MNG_AQM_RX_REQ_QW1__RETURN_VALUE__RESET_VALUE                      0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW1__LOCAL_ADDR
#define MNG_AQM_RX_REQ_QW1__LOCAL_ADDR__MSB                                 55
#define MNG_AQM_RX_REQ_QW1__LOCAL_ADDR__LSB                                 32
#define MNG_AQM_RX_REQ_QW1__LOCAL_ADDR__WIDTH                               24
#define MNG_AQM_RX_REQ_QW1__LOCAL_ADDR__MASK                  0xffffff00000000
#define MNG_AQM_RX_REQ_QW1__LOCAL_ADDR__RESET_VALUE                        0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW1__OPCODE
#define MNG_AQM_RX_REQ_QW1__OPCODE__MSB                                     31
#define MNG_AQM_RX_REQ_QW1__OPCODE__LSB                                     16
#define MNG_AQM_RX_REQ_QW1__OPCODE__WIDTH                                   16
#define MNG_AQM_RX_REQ_QW1__OPCODE__MASK                            0xffff0000
#define MNG_AQM_RX_REQ_QW1__OPCODE__RESET_VALUE                            0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW1__DATA_LEN
#define MNG_AQM_RX_REQ_QW1__DATA_LEN__MSB                                   15
#define MNG_AQM_RX_REQ_QW1__DATA_LEN__LSB                                    0
#define MNG_AQM_RX_REQ_QW1__DATA_LEN__WIDTH                                 16
#define MNG_AQM_RX_REQ_QW1__DATA_LEN__MASK                              0xffff
#define MNG_AQM_RX_REQ_QW1__DATA_LEN__RESET_VALUE                          0x0

//-----Access structure typedef for Message:MNG_AQM_RX_REQ_QW2
typedef union {
  struct {
    u64 mbxid   : 9;
    u64 fw_rsvd : 7;
    u64 rsvd0   : 48;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} MNG_AQM_RX_REQ_QW2;
//-----MACRO defines for Message:MNG_AQM_RX_REQ_QW2

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW2__FW_RSVD
#define MNG_AQM_RX_REQ_QW2__FW_RSVD__MSB                                    15
#define MNG_AQM_RX_REQ_QW2__FW_RSVD__LSB                                     9
#define MNG_AQM_RX_REQ_QW2__FW_RSVD__WIDTH                                   7
#define MNG_AQM_RX_REQ_QW2__FW_RSVD__MASK                               0xfe00
#define MNG_AQM_RX_REQ_QW2__FW_RSVD__RESET_VALUE                           0x0

//-----MACRO defines for fields:MNG_AQM_RX_REQ_QW2__MBXID
#define MNG_AQM_RX_REQ_QW2__MBXID__MSB                                       8
#define MNG_AQM_RX_REQ_QW2__MBXID__LSB                                       0
#define MNG_AQM_RX_REQ_QW2__MBXID__WIDTH                                     9
#define MNG_AQM_RX_REQ_QW2__MBXID__MASK                                  0x1ff
#define MNG_AQM_RX_REQ_QW2__MBXID__RESET_VALUE                             0x0

typedef struct {
  MNG_AQM_RX_REQ_QW0  qw0;
  MNG_AQM_RX_REQ_QW1  qw1;
  MNG_AQM_RX_REQ_QW2  qw2;
} MNG_AQM_RX_REQ;
//QW_CNT is actual number - 1
#define MNG_AQM_RX_REQ_QW_CNT                                                2
//-----MACRO defines for  Message Group RPP_AQM_FDIR_WRBK: 0xa60000
#define RPP_AQM_FDIR_WRBK_MSG_ID                                          0xa6
//-----Access structure typedef for Message:RPP_AQM_FDIR_WRBK_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 q_type  : 8;
    u64 rsvd0   : 9;
    u64 vsi     : 10;
    u64 rsvd1   : 4;
    u64 dummy   : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RPP_AQM_FDIR_WRBK_QW0;
//-----MACRO defines for Message:RPP_AQM_FDIR_WRBK_QW0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__DUMMY
#define RPP_AQM_FDIR_WRBK_QW0__DUMMY__MSB                                   63
#define RPP_AQM_FDIR_WRBK_QW0__DUMMY__LSB                                   63
#define RPP_AQM_FDIR_WRBK_QW0__DUMMY__WIDTH                                  1
#define RPP_AQM_FDIR_WRBK_QW0__DUMMY__MASK                  0x8000000000000000
#define RPP_AQM_FDIR_WRBK_QW0__DUMMY__RESET_VALUE                          0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__VSI
#define RPP_AQM_FDIR_WRBK_QW0__VSI__MSB                                     58
#define RPP_AQM_FDIR_WRBK_QW0__VSI__LSB                                     49
#define RPP_AQM_FDIR_WRBK_QW0__VSI__WIDTH                                   10
#define RPP_AQM_FDIR_WRBK_QW0__VSI__MASK                     0x7fe000000000000
#define RPP_AQM_FDIR_WRBK_QW0__VSI__RESET_VALUE                            0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__Q_TYPE
#define RPP_AQM_FDIR_WRBK_QW0__Q_TYPE__MSB                                  39
#define RPP_AQM_FDIR_WRBK_QW0__Q_TYPE__LSB                                  32
#define RPP_AQM_FDIR_WRBK_QW0__Q_TYPE__WIDTH                                 8
#define RPP_AQM_FDIR_WRBK_QW0__Q_TYPE__MASK                       0xff00000000
#define RPP_AQM_FDIR_WRBK_QW0__Q_TYPE__RESET_VALUE                         0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__MSG_ID
#define RPP_AQM_FDIR_WRBK_QW0__MSG_ID__MSB                                  31
#define RPP_AQM_FDIR_WRBK_QW0__MSG_ID__LSB                                  24
#define RPP_AQM_FDIR_WRBK_QW0__MSG_ID__WIDTH                                 8
#define RPP_AQM_FDIR_WRBK_QW0__MSG_ID__MASK                         0xff000000
#define RPP_AQM_FDIR_WRBK_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__REQ_TAG
#define RPP_AQM_FDIR_WRBK_QW0__REQ_TAG__MSB                                 23
#define RPP_AQM_FDIR_WRBK_QW0__REQ_TAG__LSB                                 16
#define RPP_AQM_FDIR_WRBK_QW0__REQ_TAG__WIDTH                                8
#define RPP_AQM_FDIR_WRBK_QW0__REQ_TAG__MASK                          0xff0000
#define RPP_AQM_FDIR_WRBK_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__SRC
#define RPP_AQM_FDIR_WRBK_QW0__SRC__MSB                                     15
#define RPP_AQM_FDIR_WRBK_QW0__SRC__LSB                                     12
#define RPP_AQM_FDIR_WRBK_QW0__SRC__WIDTH                                    4
#define RPP_AQM_FDIR_WRBK_QW0__SRC__MASK                                0xf000
#define RPP_AQM_FDIR_WRBK_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__DST
#define RPP_AQM_FDIR_WRBK_QW0__DST__MSB                                     11
#define RPP_AQM_FDIR_WRBK_QW0__DST__LSB                                     10
#define RPP_AQM_FDIR_WRBK_QW0__DST__WIDTH                                    2
#define RPP_AQM_FDIR_WRBK_QW0__DST__MASK                                 0xc00
#define RPP_AQM_FDIR_WRBK_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__DSTFIFO
#define RPP_AQM_FDIR_WRBK_QW0__DSTFIFO__MSB                                  9
#define RPP_AQM_FDIR_WRBK_QW0__DSTFIFO__LSB                                  6
#define RPP_AQM_FDIR_WRBK_QW0__DSTFIFO__WIDTH                                4
#define RPP_AQM_FDIR_WRBK_QW0__DSTFIFO__MASK                             0x3c0
#define RPP_AQM_FDIR_WRBK_QW0__DSTFIFO__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW0__CNT
#define RPP_AQM_FDIR_WRBK_QW0__CNT__MSB                                      5
#define RPP_AQM_FDIR_WRBK_QW0__CNT__LSB                                      0
#define RPP_AQM_FDIR_WRBK_QW0__CNT__WIDTH                                    6
#define RPP_AQM_FDIR_WRBK_QW0__CNT__MASK                                  0x3f
#define RPP_AQM_FDIR_WRBK_QW0__CNT__RESET_VALUE                            0x0

//-----Access structure typedef for Message:RPP_AQM_FDIR_WRBK_QW1
typedef union {
  struct {
    u64 dd           : 1;
    u64 return_value : 7;
    u64 wb           : 1;
    u64 lb           : 1;
    u64 rd           : 1;
    u64 rsvd0        : 1;
    u64 buffer       : 1;
    u64 si           : 1;
    u64 ei           : 1;
    u64 fe           : 1;
    u64 fdir_free    : 16;
    u64 add_suc      : 1;
    u64 add_fail     : 1;
    u64 rm_suc       : 1;
    u64 rm_fail      : 1;
    u64 rsvd1        : 4;
    u64 max_len      : 15;
    u64 rsvd2        : 9;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RPP_AQM_FDIR_WRBK_QW1;
//-----MACRO defines for Message:RPP_AQM_FDIR_WRBK_QW1

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__MAX_LEN
#define RPP_AQM_FDIR_WRBK_QW1__MAX_LEN__MSB                                 54
#define RPP_AQM_FDIR_WRBK_QW1__MAX_LEN__LSB                                 40
#define RPP_AQM_FDIR_WRBK_QW1__MAX_LEN__WIDTH                               15
#define RPP_AQM_FDIR_WRBK_QW1__MAX_LEN__MASK                  0x7fff0000000000
#define RPP_AQM_FDIR_WRBK_QW1__MAX_LEN__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__RM_FAIL
#define RPP_AQM_FDIR_WRBK_QW1__RM_FAIL__MSB                                 35
#define RPP_AQM_FDIR_WRBK_QW1__RM_FAIL__LSB                                 35
#define RPP_AQM_FDIR_WRBK_QW1__RM_FAIL__WIDTH                                1
#define RPP_AQM_FDIR_WRBK_QW1__RM_FAIL__MASK                       0x800000000
#define RPP_AQM_FDIR_WRBK_QW1__RM_FAIL__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__RM_SUC
#define RPP_AQM_FDIR_WRBK_QW1__RM_SUC__MSB                                  34
#define RPP_AQM_FDIR_WRBK_QW1__RM_SUC__LSB                                  34
#define RPP_AQM_FDIR_WRBK_QW1__RM_SUC__WIDTH                                 1
#define RPP_AQM_FDIR_WRBK_QW1__RM_SUC__MASK                        0x400000000
#define RPP_AQM_FDIR_WRBK_QW1__RM_SUC__RESET_VALUE                         0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL
#define RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL__MSB                                33
#define RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL__LSB                                33
#define RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL__WIDTH                               1
#define RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL__MASK                      0x200000000
#define RPP_AQM_FDIR_WRBK_QW1__ADD_FAIL__RESET_VALUE                       0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__ADD_SUC
#define RPP_AQM_FDIR_WRBK_QW1__ADD_SUC__MSB                                 32
#define RPP_AQM_FDIR_WRBK_QW1__ADD_SUC__LSB                                 32
#define RPP_AQM_FDIR_WRBK_QW1__ADD_SUC__WIDTH                                1
#define RPP_AQM_FDIR_WRBK_QW1__ADD_SUC__MASK                       0x100000000
#define RPP_AQM_FDIR_WRBK_QW1__ADD_SUC__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE
#define RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE__MSB                               31
#define RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE__LSB                               16
#define RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE__WIDTH                             16
#define RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE__MASK                      0xffff0000
#define RPP_AQM_FDIR_WRBK_QW1__FDIR_FREE__RESET_VALUE                      0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__FE
#define RPP_AQM_FDIR_WRBK_QW1__FE__MSB                                      15
#define RPP_AQM_FDIR_WRBK_QW1__FE__LSB                                      15
#define RPP_AQM_FDIR_WRBK_QW1__FE__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__FE__MASK                                 0x8000
#define RPP_AQM_FDIR_WRBK_QW1__FE__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__EI
#define RPP_AQM_FDIR_WRBK_QW1__EI__MSB                                      14
#define RPP_AQM_FDIR_WRBK_QW1__EI__LSB                                      14
#define RPP_AQM_FDIR_WRBK_QW1__EI__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__EI__MASK                                 0x4000
#define RPP_AQM_FDIR_WRBK_QW1__EI__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__SI
#define RPP_AQM_FDIR_WRBK_QW1__SI__MSB                                      13
#define RPP_AQM_FDIR_WRBK_QW1__SI__LSB                                      13
#define RPP_AQM_FDIR_WRBK_QW1__SI__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__SI__MASK                                 0x2000
#define RPP_AQM_FDIR_WRBK_QW1__SI__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__BUFFER
#define RPP_AQM_FDIR_WRBK_QW1__BUFFER__MSB                                  12
#define RPP_AQM_FDIR_WRBK_QW1__BUFFER__LSB                                  12
#define RPP_AQM_FDIR_WRBK_QW1__BUFFER__WIDTH                                 1
#define RPP_AQM_FDIR_WRBK_QW1__BUFFER__MASK                             0x1000
#define RPP_AQM_FDIR_WRBK_QW1__BUFFER__RESET_VALUE                         0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__RD
#define RPP_AQM_FDIR_WRBK_QW1__RD__MSB                                      10
#define RPP_AQM_FDIR_WRBK_QW1__RD__LSB                                      10
#define RPP_AQM_FDIR_WRBK_QW1__RD__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__RD__MASK                                  0x400
#define RPP_AQM_FDIR_WRBK_QW1__RD__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__LB
#define RPP_AQM_FDIR_WRBK_QW1__LB__MSB                                       9
#define RPP_AQM_FDIR_WRBK_QW1__LB__LSB                                       9
#define RPP_AQM_FDIR_WRBK_QW1__LB__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__LB__MASK                                  0x200
#define RPP_AQM_FDIR_WRBK_QW1__LB__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__WB
#define RPP_AQM_FDIR_WRBK_QW1__WB__MSB                                       8
#define RPP_AQM_FDIR_WRBK_QW1__WB__LSB                                       8
#define RPP_AQM_FDIR_WRBK_QW1__WB__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__WB__MASK                                  0x100
#define RPP_AQM_FDIR_WRBK_QW1__WB__RESET_VALUE                             0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE
#define RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE__MSB                             7
#define RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE__LSB                             1
#define RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE__WIDTH                           7
#define RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE__MASK                         0xfe
#define RPP_AQM_FDIR_WRBK_QW1__RETURN_VALUE__RESET_VALUE                   0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW1__DD
#define RPP_AQM_FDIR_WRBK_QW1__DD__MSB                                       0
#define RPP_AQM_FDIR_WRBK_QW1__DD__LSB                                       0
#define RPP_AQM_FDIR_WRBK_QW1__DD__WIDTH                                     1
#define RPP_AQM_FDIR_WRBK_QW1__DD__MASK                                    0x1
#define RPP_AQM_FDIR_WRBK_QW1__DD__RESET_VALUE                             0x0

//-----Access structure typedef for Message:RPP_AQM_FDIR_WRBK_QW2
typedef union {
  struct {
    u64 addr_hi : 32;
    u64 addr_lo : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} RPP_AQM_FDIR_WRBK_QW2;
//-----MACRO defines for Message:RPP_AQM_FDIR_WRBK_QW2

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW2__ADDR_LO
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_LO__MSB                                 63
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_LO__LSB                                 32
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_LO__WIDTH                               32
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_LO__MASK                0xffffffff00000000
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_LO__RESET_VALUE                        0x0

//-----MACRO defines for fields:RPP_AQM_FDIR_WRBK_QW2__ADDR_HI
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_HI__MSB                                 31
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_HI__LSB                                  0
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_HI__WIDTH                               32
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_HI__MASK                        0xffffffff
#define RPP_AQM_FDIR_WRBK_QW2__ADDR_HI__RESET_VALUE                        0x0

typedef struct {
  RPP_AQM_FDIR_WRBK_QW0  qw0;
  RPP_AQM_FDIR_WRBK_QW1  qw1;
  RPP_AQM_FDIR_WRBK_QW2  qw2;
} RPP_AQM_FDIR_WRBK;
//QW_CNT is actual number - 1
#define RPP_AQM_FDIR_WRBK_QW_CNT                                             2
//-----MACRO defines for  Message Group PCIE_EXTCM_MSG: 0xa70000
#define PCIE_EXTCM_MSG_MSG_ID                                             0xa7
//-----Access structure typedef for Message:PCIE_EXTCM_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 rsvd0   : 17;
    u64 vf      : 8;
    u64 pf      : 2;
    u64 vfa     : 1;
    u64 rsvd1   : 3;
    u64 sta     : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PCIE_EXTCM_MSG_QW0;
//-----MACRO defines for Message:PCIE_EXTCM_MSG_QW0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__STA
#define PCIE_EXTCM_MSG_QW0__STA__MSB                                        63
#define PCIE_EXTCM_MSG_QW0__STA__LSB                                        63
#define PCIE_EXTCM_MSG_QW0__STA__WIDTH                                       1
#define PCIE_EXTCM_MSG_QW0__STA__MASK                       0x8000000000000000
#define PCIE_EXTCM_MSG_QW0__STA__RESET_VALUE                               0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__VFA
#define PCIE_EXTCM_MSG_QW0__VFA__MSB                                        59
#define PCIE_EXTCM_MSG_QW0__VFA__LSB                                        59
#define PCIE_EXTCM_MSG_QW0__VFA__WIDTH                                       1
#define PCIE_EXTCM_MSG_QW0__VFA__MASK                        0x800000000000000
#define PCIE_EXTCM_MSG_QW0__VFA__RESET_VALUE                               0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__PF
#define PCIE_EXTCM_MSG_QW0__PF__MSB                                         58
#define PCIE_EXTCM_MSG_QW0__PF__LSB                                         57
#define PCIE_EXTCM_MSG_QW0__PF__WIDTH                                        2
#define PCIE_EXTCM_MSG_QW0__PF__MASK                         0x600000000000000
#define PCIE_EXTCM_MSG_QW0__PF__RESET_VALUE                                0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__VF
#define PCIE_EXTCM_MSG_QW0__VF__MSB                                         56
#define PCIE_EXTCM_MSG_QW0__VF__LSB                                         49
#define PCIE_EXTCM_MSG_QW0__VF__WIDTH                                        8
#define PCIE_EXTCM_MSG_QW0__VF__MASK                         0x1fe000000000000
#define PCIE_EXTCM_MSG_QW0__VF__RESET_VALUE                                0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__MSG_ID
#define PCIE_EXTCM_MSG_QW0__MSG_ID__MSB                                     31
#define PCIE_EXTCM_MSG_QW0__MSG_ID__LSB                                     24
#define PCIE_EXTCM_MSG_QW0__MSG_ID__WIDTH                                    8
#define PCIE_EXTCM_MSG_QW0__MSG_ID__MASK                            0xff000000
#define PCIE_EXTCM_MSG_QW0__MSG_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__REQ_TAG
#define PCIE_EXTCM_MSG_QW0__REQ_TAG__MSB                                    23
#define PCIE_EXTCM_MSG_QW0__REQ_TAG__LSB                                    16
#define PCIE_EXTCM_MSG_QW0__REQ_TAG__WIDTH                                   8
#define PCIE_EXTCM_MSG_QW0__REQ_TAG__MASK                             0xff0000
#define PCIE_EXTCM_MSG_QW0__REQ_TAG__RESET_VALUE                           0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__SRC
#define PCIE_EXTCM_MSG_QW0__SRC__MSB                                        15
#define PCIE_EXTCM_MSG_QW0__SRC__LSB                                        12
#define PCIE_EXTCM_MSG_QW0__SRC__WIDTH                                       4
#define PCIE_EXTCM_MSG_QW0__SRC__MASK                                   0xf000
#define PCIE_EXTCM_MSG_QW0__SRC__RESET_VALUE                               0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__DST
#define PCIE_EXTCM_MSG_QW0__DST__MSB                                        11
#define PCIE_EXTCM_MSG_QW0__DST__LSB                                        10
#define PCIE_EXTCM_MSG_QW0__DST__WIDTH                                       2
#define PCIE_EXTCM_MSG_QW0__DST__MASK                                    0xc00
#define PCIE_EXTCM_MSG_QW0__DST__RESET_VALUE                               0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__DSTFIFO
#define PCIE_EXTCM_MSG_QW0__DSTFIFO__MSB                                     9
#define PCIE_EXTCM_MSG_QW0__DSTFIFO__LSB                                     6
#define PCIE_EXTCM_MSG_QW0__DSTFIFO__WIDTH                                   4
#define PCIE_EXTCM_MSG_QW0__DSTFIFO__MASK                                0x3c0
#define PCIE_EXTCM_MSG_QW0__DSTFIFO__RESET_VALUE                           0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW0__CNT
#define PCIE_EXTCM_MSG_QW0__CNT__MSB                                         5
#define PCIE_EXTCM_MSG_QW0__CNT__LSB                                         0
#define PCIE_EXTCM_MSG_QW0__CNT__WIDTH                                       6
#define PCIE_EXTCM_MSG_QW0__CNT__MASK                                     0x3f
#define PCIE_EXTCM_MSG_QW0__CNT__RESET_VALUE                               0x0

//-----Access structure typedef for Message:PCIE_EXTCM_MSG_QW1
typedef union {
  struct {
    u64 blen     : 9;
    u64 msg_type : 5;
    u64 dw3_vld  : 1;
    u64 data_vld : 1;
    u64 req_id   : 16;
    u64 msg_code : 8;
    u64 data_num : 9;
    u64 rsvd0    : 7;
    u64 pcie_tag : 8;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PCIE_EXTCM_MSG_QW1;
//-----MACRO defines for Message:PCIE_EXTCM_MSG_QW1

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__PCIE_TAG
#define PCIE_EXTCM_MSG_QW1__PCIE_TAG__MSB                                   63
#define PCIE_EXTCM_MSG_QW1__PCIE_TAG__LSB                                   56
#define PCIE_EXTCM_MSG_QW1__PCIE_TAG__WIDTH                                  8
#define PCIE_EXTCM_MSG_QW1__PCIE_TAG__MASK                  0xff00000000000000
#define PCIE_EXTCM_MSG_QW1__PCIE_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__DATA_NUM
#define PCIE_EXTCM_MSG_QW1__DATA_NUM__MSB                                   48
#define PCIE_EXTCM_MSG_QW1__DATA_NUM__LSB                                   40
#define PCIE_EXTCM_MSG_QW1__DATA_NUM__WIDTH                                  9
#define PCIE_EXTCM_MSG_QW1__DATA_NUM__MASK                     0x1ff0000000000
#define PCIE_EXTCM_MSG_QW1__DATA_NUM__RESET_VALUE                          0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__MSG_CODE
#define PCIE_EXTCM_MSG_QW1__MSG_CODE__MSB                                   39
#define PCIE_EXTCM_MSG_QW1__MSG_CODE__LSB                                   32
#define PCIE_EXTCM_MSG_QW1__MSG_CODE__WIDTH                                  8
#define PCIE_EXTCM_MSG_QW1__MSG_CODE__MASK                        0xff00000000
#define PCIE_EXTCM_MSG_QW1__MSG_CODE__RESET_VALUE                          0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__REQ_ID
#define PCIE_EXTCM_MSG_QW1__REQ_ID__MSB                                     31
#define PCIE_EXTCM_MSG_QW1__REQ_ID__LSB                                     16
#define PCIE_EXTCM_MSG_QW1__REQ_ID__WIDTH                                   16
#define PCIE_EXTCM_MSG_QW1__REQ_ID__MASK                            0xffff0000
#define PCIE_EXTCM_MSG_QW1__REQ_ID__RESET_VALUE                            0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__DATA_VLD
#define PCIE_EXTCM_MSG_QW1__DATA_VLD__MSB                                   15
#define PCIE_EXTCM_MSG_QW1__DATA_VLD__LSB                                   15
#define PCIE_EXTCM_MSG_QW1__DATA_VLD__WIDTH                                  1
#define PCIE_EXTCM_MSG_QW1__DATA_VLD__MASK                              0x8000
#define PCIE_EXTCM_MSG_QW1__DATA_VLD__RESET_VALUE                          0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__DW3_VLD
#define PCIE_EXTCM_MSG_QW1__DW3_VLD__MSB                                    14
#define PCIE_EXTCM_MSG_QW1__DW3_VLD__LSB                                    14
#define PCIE_EXTCM_MSG_QW1__DW3_VLD__WIDTH                                   1
#define PCIE_EXTCM_MSG_QW1__DW3_VLD__MASK                               0x4000
#define PCIE_EXTCM_MSG_QW1__DW3_VLD__RESET_VALUE                           0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__MSG_TYPE
#define PCIE_EXTCM_MSG_QW1__MSG_TYPE__MSB                                   13
#define PCIE_EXTCM_MSG_QW1__MSG_TYPE__LSB                                    9
#define PCIE_EXTCM_MSG_QW1__MSG_TYPE__WIDTH                                  5
#define PCIE_EXTCM_MSG_QW1__MSG_TYPE__MASK                              0x3e00
#define PCIE_EXTCM_MSG_QW1__MSG_TYPE__RESET_VALUE                          0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW1__BLEN
#define PCIE_EXTCM_MSG_QW1__BLEN__MSB                                        8
#define PCIE_EXTCM_MSG_QW1__BLEN__LSB                                        0
#define PCIE_EXTCM_MSG_QW1__BLEN__WIDTH                                      9
#define PCIE_EXTCM_MSG_QW1__BLEN__MASK                                   0x1ff
#define PCIE_EXTCM_MSG_QW1__BLEN__RESET_VALUE                              0x0

//-----Access structure typedef for Message:PCIE_EXTCM_MSG_QW2
typedef union {
  struct {
    u64 hdr_dw3 : 32;
    u64 hdr_dw2 : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PCIE_EXTCM_MSG_QW2;
//-----MACRO defines for Message:PCIE_EXTCM_MSG_QW2

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW2__HDR_DW2
#define PCIE_EXTCM_MSG_QW2__HDR_DW2__MSB                                    63
#define PCIE_EXTCM_MSG_QW2__HDR_DW2__LSB                                    32
#define PCIE_EXTCM_MSG_QW2__HDR_DW2__WIDTH                                  32
#define PCIE_EXTCM_MSG_QW2__HDR_DW2__MASK                   0xffffffff00000000
#define PCIE_EXTCM_MSG_QW2__HDR_DW2__RESET_VALUE                           0x0

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW2__HDR_DW3
#define PCIE_EXTCM_MSG_QW2__HDR_DW3__MSB                                    31
#define PCIE_EXTCM_MSG_QW2__HDR_DW3__LSB                                     0
#define PCIE_EXTCM_MSG_QW2__HDR_DW3__WIDTH                                  32
#define PCIE_EXTCM_MSG_QW2__HDR_DW3__MASK                           0xffffffff
#define PCIE_EXTCM_MSG_QW2__HDR_DW3__RESET_VALUE                           0x0

//-----Access structure typedef for Message:PCIE_EXTCM_MSG_QW_DATA
typedef union {
  struct {
    u64 msg_data : 64;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} PCIE_EXTCM_MSG_QW_DATA;
//-----MACRO defines for Message:PCIE_EXTCM_MSG_QW_DATA

//-----MACRO defines for fields:PCIE_EXTCM_MSG_QW_DATA__MSG_DATA
#define PCIE_EXTCM_MSG_QW_DATA__MSG_DATA__MSB                               63
#define PCIE_EXTCM_MSG_QW_DATA__MSG_DATA__LSB                                0
#define PCIE_EXTCM_MSG_QW_DATA__MSG_DATA__WIDTH                             64
#define PCIE_EXTCM_MSG_QW_DATA__MSG_DATA__MASK              0xffffffffffffffff
#define PCIE_EXTCM_MSG_QW_DATA__MSG_DATA__RESET_VALUE                      0x0

typedef struct {
  PCIE_EXTCM_MSG_QW0  qw0;
  PCIE_EXTCM_MSG_QW1  qw1;
  PCIE_EXTCM_MSG_QW2  qw2;
  // PCIE_EXTCM_MSG_QW_DATA  qw3;
  u8 payload[0];
} PCIE_EXTCM_MSG;
//QW_CNT is actual number - 1
#define PCIE_EXTCM_MSG_QW_CNT                                                2
//-----MACRO defines for  Message Group SCH_TIMER_REQ_MSG: 0xb00000
#define SCH_TIMER_REQ_MSG_MSG_ID                                          0xb0
//-----Access structure typedef for Message:SCH_TIMER_REQ_MSG_QW0
typedef union {
  struct {
    u64 cnt      : 6;
    u64 opcode   : 2;
    u64 rsvd0    : 2;
    u64 dst      : 2;
    u64 src      : 4;
    u64 req_tag  : 3;
    u64 rsvd1    : 5;
    u64 msg_id   : 8;
    u64 obj_idx  : 12;
    u64 rsvd2    : 1;
    u64 to_val   : 15;
    u64 rsvd3    : 3;
    u64 need_rsp : 1;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SCH_TIMER_REQ_MSG_QW0;
//-----MACRO defines for Message:SCH_TIMER_REQ_MSG_QW0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__NEED_RSP
#define SCH_TIMER_REQ_MSG_QW0__NEED_RSP__MSB                                63
#define SCH_TIMER_REQ_MSG_QW0__NEED_RSP__LSB                                63
#define SCH_TIMER_REQ_MSG_QW0__NEED_RSP__WIDTH                               1
#define SCH_TIMER_REQ_MSG_QW0__NEED_RSP__MASK               0x8000000000000000
#define SCH_TIMER_REQ_MSG_QW0__NEED_RSP__RESET_VALUE                       0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__TO_VAL
#define SCH_TIMER_REQ_MSG_QW0__TO_VAL__MSB                                  59
#define SCH_TIMER_REQ_MSG_QW0__TO_VAL__LSB                                  45
#define SCH_TIMER_REQ_MSG_QW0__TO_VAL__WIDTH                                15
#define SCH_TIMER_REQ_MSG_QW0__TO_VAL__MASK                  0xfffe00000000000
#define SCH_TIMER_REQ_MSG_QW0__TO_VAL__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__OBJ_IDX
#define SCH_TIMER_REQ_MSG_QW0__OBJ_IDX__MSB                                 43
#define SCH_TIMER_REQ_MSG_QW0__OBJ_IDX__LSB                                 32
#define SCH_TIMER_REQ_MSG_QW0__OBJ_IDX__WIDTH                               12
#define SCH_TIMER_REQ_MSG_QW0__OBJ_IDX__MASK                     0xfff00000000
#define SCH_TIMER_REQ_MSG_QW0__OBJ_IDX__RESET_VALUE                        0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__MSG_ID
#define SCH_TIMER_REQ_MSG_QW0__MSG_ID__MSB                                  31
#define SCH_TIMER_REQ_MSG_QW0__MSG_ID__LSB                                  24
#define SCH_TIMER_REQ_MSG_QW0__MSG_ID__WIDTH                                 8
#define SCH_TIMER_REQ_MSG_QW0__MSG_ID__MASK                         0xff000000
#define SCH_TIMER_REQ_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__REQ_TAG
#define SCH_TIMER_REQ_MSG_QW0__REQ_TAG__MSB                                 18
#define SCH_TIMER_REQ_MSG_QW0__REQ_TAG__LSB                                 16
#define SCH_TIMER_REQ_MSG_QW0__REQ_TAG__WIDTH                                3
#define SCH_TIMER_REQ_MSG_QW0__REQ_TAG__MASK                           0x70000
#define SCH_TIMER_REQ_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__SRC
#define SCH_TIMER_REQ_MSG_QW0__SRC__MSB                                     15
#define SCH_TIMER_REQ_MSG_QW0__SRC__LSB                                     12
#define SCH_TIMER_REQ_MSG_QW0__SRC__WIDTH                                    4
#define SCH_TIMER_REQ_MSG_QW0__SRC__MASK                                0xf000
#define SCH_TIMER_REQ_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__DST
#define SCH_TIMER_REQ_MSG_QW0__DST__MSB                                     11
#define SCH_TIMER_REQ_MSG_QW0__DST__LSB                                     10
#define SCH_TIMER_REQ_MSG_QW0__DST__WIDTH                                    2
#define SCH_TIMER_REQ_MSG_QW0__DST__MASK                                 0xc00
#define SCH_TIMER_REQ_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__OPCODE
#define SCH_TIMER_REQ_MSG_QW0__OPCODE__MSB                                   7
#define SCH_TIMER_REQ_MSG_QW0__OPCODE__LSB                                   6
#define SCH_TIMER_REQ_MSG_QW0__OPCODE__WIDTH                                 2
#define SCH_TIMER_REQ_MSG_QW0__OPCODE__MASK                               0xc0
#define SCH_TIMER_REQ_MSG_QW0__OPCODE__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_REQ_MSG_QW0__CNT
#define SCH_TIMER_REQ_MSG_QW0__CNT__MSB                                      5
#define SCH_TIMER_REQ_MSG_QW0__CNT__LSB                                      0
#define SCH_TIMER_REQ_MSG_QW0__CNT__WIDTH                                    6
#define SCH_TIMER_REQ_MSG_QW0__CNT__MASK                                  0x3f
#define SCH_TIMER_REQ_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  SCH_TIMER_REQ_MSG_QW0  qw0;
} SCH_TIMER_REQ_MSG;
//QW_CNT is actual number - 1
#define SCH_TIMER_REQ_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group SCH_TIMER_RSP_MSG: 0xb10000
#define SCH_TIMER_RSP_MSG_MSG_ID                                          0xb1
//-----Access structure typedef for Message:SCH_TIMER_RSP_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 opcode  : 2;
    u64 rsvd0   : 2;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 3;
    u64 rsvd1   : 5;
    u64 msg_id  : 8;
    u64 obj_idx : 12;
    u64 rsvd2   : 16;
    u64 sta     : 4;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SCH_TIMER_RSP_MSG_QW0;
//-----MACRO defines for Message:SCH_TIMER_RSP_MSG_QW0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__STA
#define SCH_TIMER_RSP_MSG_QW0__STA__MSB                                     63
#define SCH_TIMER_RSP_MSG_QW0__STA__LSB                                     60
#define SCH_TIMER_RSP_MSG_QW0__STA__WIDTH                                    4
#define SCH_TIMER_RSP_MSG_QW0__STA__MASK                    0xf000000000000000
#define SCH_TIMER_RSP_MSG_QW0__STA__RESET_VALUE                            0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__OBJ_IDX
#define SCH_TIMER_RSP_MSG_QW0__OBJ_IDX__MSB                                 43
#define SCH_TIMER_RSP_MSG_QW0__OBJ_IDX__LSB                                 32
#define SCH_TIMER_RSP_MSG_QW0__OBJ_IDX__WIDTH                               12
#define SCH_TIMER_RSP_MSG_QW0__OBJ_IDX__MASK                     0xfff00000000
#define SCH_TIMER_RSP_MSG_QW0__OBJ_IDX__RESET_VALUE                        0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__MSG_ID
#define SCH_TIMER_RSP_MSG_QW0__MSG_ID__MSB                                  31
#define SCH_TIMER_RSP_MSG_QW0__MSG_ID__LSB                                  24
#define SCH_TIMER_RSP_MSG_QW0__MSG_ID__WIDTH                                 8
#define SCH_TIMER_RSP_MSG_QW0__MSG_ID__MASK                         0xff000000
#define SCH_TIMER_RSP_MSG_QW0__MSG_ID__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__REQ_TAG
#define SCH_TIMER_RSP_MSG_QW0__REQ_TAG__MSB                                 18
#define SCH_TIMER_RSP_MSG_QW0__REQ_TAG__LSB                                 16
#define SCH_TIMER_RSP_MSG_QW0__REQ_TAG__WIDTH                                3
#define SCH_TIMER_RSP_MSG_QW0__REQ_TAG__MASK                           0x70000
#define SCH_TIMER_RSP_MSG_QW0__REQ_TAG__RESET_VALUE                        0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__SRC
#define SCH_TIMER_RSP_MSG_QW0__SRC__MSB                                     15
#define SCH_TIMER_RSP_MSG_QW0__SRC__LSB                                     12
#define SCH_TIMER_RSP_MSG_QW0__SRC__WIDTH                                    4
#define SCH_TIMER_RSP_MSG_QW0__SRC__MASK                                0xf000
#define SCH_TIMER_RSP_MSG_QW0__SRC__RESET_VALUE                            0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__DST
#define SCH_TIMER_RSP_MSG_QW0__DST__MSB                                     11
#define SCH_TIMER_RSP_MSG_QW0__DST__LSB                                     10
#define SCH_TIMER_RSP_MSG_QW0__DST__WIDTH                                    2
#define SCH_TIMER_RSP_MSG_QW0__DST__MASK                                 0xc00
#define SCH_TIMER_RSP_MSG_QW0__DST__RESET_VALUE                            0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__OPCODE
#define SCH_TIMER_RSP_MSG_QW0__OPCODE__MSB                                   7
#define SCH_TIMER_RSP_MSG_QW0__OPCODE__LSB                                   6
#define SCH_TIMER_RSP_MSG_QW0__OPCODE__WIDTH                                 2
#define SCH_TIMER_RSP_MSG_QW0__OPCODE__MASK                               0xc0
#define SCH_TIMER_RSP_MSG_QW0__OPCODE__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_RSP_MSG_QW0__CNT
#define SCH_TIMER_RSP_MSG_QW0__CNT__MSB                                      5
#define SCH_TIMER_RSP_MSG_QW0__CNT__LSB                                      0
#define SCH_TIMER_RSP_MSG_QW0__CNT__WIDTH                                    6
#define SCH_TIMER_RSP_MSG_QW0__CNT__MASK                                  0x3f
#define SCH_TIMER_RSP_MSG_QW0__CNT__RESET_VALUE                            0x0

typedef struct {
  SCH_TIMER_RSP_MSG_QW0  qw0;
} SCH_TIMER_RSP_MSG;
//QW_CNT is actual number - 1
#define SCH_TIMER_RSP_MSG_QW_CNT                                             0
//-----MACRO defines for  Message Group SCH_TIMER_TO_MSG: 0xb20000
#define SCH_TIMER_TO_MSG_MSG_ID                                           0xb2
//-----Access structure typedef for Message:SCH_TIMER_TO_MSG_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 rsvd0   : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 3;
    u64 rsvd1   : 5;
    u64 msg_id  : 8;
    u64 obj_idx : 12;
    u64 rsvd2   : 20;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} SCH_TIMER_TO_MSG_QW0;
//-----MACRO defines for Message:SCH_TIMER_TO_MSG_QW0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__OBJ_IDX
#define SCH_TIMER_TO_MSG_QW0__OBJ_IDX__MSB                                  43
#define SCH_TIMER_TO_MSG_QW0__OBJ_IDX__LSB                                  32
#define SCH_TIMER_TO_MSG_QW0__OBJ_IDX__WIDTH                                12
#define SCH_TIMER_TO_MSG_QW0__OBJ_IDX__MASK                      0xfff00000000
#define SCH_TIMER_TO_MSG_QW0__OBJ_IDX__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__MSG_ID
#define SCH_TIMER_TO_MSG_QW0__MSG_ID__MSB                                   31
#define SCH_TIMER_TO_MSG_QW0__MSG_ID__LSB                                   24
#define SCH_TIMER_TO_MSG_QW0__MSG_ID__WIDTH                                  8
#define SCH_TIMER_TO_MSG_QW0__MSG_ID__MASK                          0xff000000
#define SCH_TIMER_TO_MSG_QW0__MSG_ID__RESET_VALUE                          0x0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__REQ_TAG
#define SCH_TIMER_TO_MSG_QW0__REQ_TAG__MSB                                  18
#define SCH_TIMER_TO_MSG_QW0__REQ_TAG__LSB                                  16
#define SCH_TIMER_TO_MSG_QW0__REQ_TAG__WIDTH                                 3
#define SCH_TIMER_TO_MSG_QW0__REQ_TAG__MASK                            0x70000
#define SCH_TIMER_TO_MSG_QW0__REQ_TAG__RESET_VALUE                         0x0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__SRC
#define SCH_TIMER_TO_MSG_QW0__SRC__MSB                                      15
#define SCH_TIMER_TO_MSG_QW0__SRC__LSB                                      12
#define SCH_TIMER_TO_MSG_QW0__SRC__WIDTH                                     4
#define SCH_TIMER_TO_MSG_QW0__SRC__MASK                                 0xf000
#define SCH_TIMER_TO_MSG_QW0__SRC__RESET_VALUE                             0x0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__DST
#define SCH_TIMER_TO_MSG_QW0__DST__MSB                                      11
#define SCH_TIMER_TO_MSG_QW0__DST__LSB                                      10
#define SCH_TIMER_TO_MSG_QW0__DST__WIDTH                                     2
#define SCH_TIMER_TO_MSG_QW0__DST__MASK                                  0xc00
#define SCH_TIMER_TO_MSG_QW0__DST__RESET_VALUE                             0x0

//-----MACRO defines for fields:SCH_TIMER_TO_MSG_QW0__CNT
#define SCH_TIMER_TO_MSG_QW0__CNT__MSB                                       5
#define SCH_TIMER_TO_MSG_QW0__CNT__LSB                                       0
#define SCH_TIMER_TO_MSG_QW0__CNT__WIDTH                                     6
#define SCH_TIMER_TO_MSG_QW0__CNT__MASK                                   0x3f
#define SCH_TIMER_TO_MSG_QW0__CNT__RESET_VALUE                             0x0

typedef struct {
  SCH_TIMER_TO_MSG_QW0  qw0;
} SCH_TIMER_TO_MSG;
//QW_CNT is actual number - 1
#define SCH_TIMER_TO_MSG_QW_CNT                                              0
//-----MACRO defines for  Message Group TXBAR_MSG: 0xb30000
#define TXBAR_MSG_MSG_ID                                                  0xb3
//-----Access structure typedef for Message:TXBAR_MSG_TDB_PO_RLS
typedef union {
  struct {
    u47 mpo_start_buf : 12;
    u47 rsvd0         : 1;
    u47 tc            : 3;
    u47 eth_grp       : 2;
    u47 mpo_len       : 5;
    u47 start_dl_idx  : 2;
    u47 pld_start_buf : 12;
    u47 pld_len       : 9;
    u47 pld_rls_vld   : 1;
  };
  u47 reg;
} TXBAR_MSG_TDB_PO_RLS;
//-----MACRO defines for Message:TXBAR_MSG_TDB_PO_RLS

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD
#define TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD__MSB                              46
#define TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD__LSB                              46
#define TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD__WIDTH                             1
#define TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD__MASK                 0x400000000000
#define TXBAR_MSG_TDB_PO_RLS__PLD_RLS_VLD__RESET_VALUE                     0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__PLD_LEN
#define TXBAR_MSG_TDB_PO_RLS__PLD_LEN__MSB                                  45
#define TXBAR_MSG_TDB_PO_RLS__PLD_LEN__LSB                                  37
#define TXBAR_MSG_TDB_PO_RLS__PLD_LEN__WIDTH                                 9
#define TXBAR_MSG_TDB_PO_RLS__PLD_LEN__MASK                     0x3fe000000000
#define TXBAR_MSG_TDB_PO_RLS__PLD_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF
#define TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF__MSB                            36
#define TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF__LSB                            25
#define TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF__WIDTH                          12
#define TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF__MASK                 0x1ffe000000
#define TXBAR_MSG_TDB_PO_RLS__PLD_START_BUF__RESET_VALUE                   0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__START_DL_IDX
#define TXBAR_MSG_TDB_PO_RLS__START_DL_IDX__MSB                             24
#define TXBAR_MSG_TDB_PO_RLS__START_DL_IDX__LSB                             23
#define TXBAR_MSG_TDB_PO_RLS__START_DL_IDX__WIDTH                            2
#define TXBAR_MSG_TDB_PO_RLS__START_DL_IDX__MASK                     0x1800000
#define TXBAR_MSG_TDB_PO_RLS__START_DL_IDX__RESET_VALUE                    0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__MPO_LEN
#define TXBAR_MSG_TDB_PO_RLS__MPO_LEN__MSB                                  22
#define TXBAR_MSG_TDB_PO_RLS__MPO_LEN__LSB                                  18
#define TXBAR_MSG_TDB_PO_RLS__MPO_LEN__WIDTH                                 5
#define TXBAR_MSG_TDB_PO_RLS__MPO_LEN__MASK                           0x7c0000
#define TXBAR_MSG_TDB_PO_RLS__MPO_LEN__RESET_VALUE                         0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__ETH_GRP
#define TXBAR_MSG_TDB_PO_RLS__ETH_GRP__MSB                                  17
#define TXBAR_MSG_TDB_PO_RLS__ETH_GRP__LSB                                  16
#define TXBAR_MSG_TDB_PO_RLS__ETH_GRP__WIDTH                                 2
#define TXBAR_MSG_TDB_PO_RLS__ETH_GRP__MASK                            0x30000
#define TXBAR_MSG_TDB_PO_RLS__ETH_GRP__RESET_VALUE                         0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__TC
#define TXBAR_MSG_TDB_PO_RLS__TC__MSB                                       15
#define TXBAR_MSG_TDB_PO_RLS__TC__LSB                                       13
#define TXBAR_MSG_TDB_PO_RLS__TC__WIDTH                                      3
#define TXBAR_MSG_TDB_PO_RLS__TC__MASK                                  0xe000
#define TXBAR_MSG_TDB_PO_RLS__TC__RESET_VALUE                              0x0

//-----MACRO defines for fields:TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF
#define TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF__MSB                            11
#define TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF__LSB                             0
#define TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF__WIDTH                          12
#define TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF__MASK                        0xfff
#define TXBAR_MSG_TDB_PO_RLS__MPO_START_BUF__RESET_VALUE                   0x0

//-----Access structure typedef for Message:TXBAR_MSG_TRT_MALLOC_REQ
typedef union {
  struct {
    u32 pld_size : 5;
    u32 tc       : 3;
    u32 lan_prt  : 1;
    u32 last     : 1;
    u32 update   : 1;
    u32 rsvd0    : 21;
  };
  u32 reg;
} TXBAR_MSG_TRT_MALLOC_REQ;
//-----MACRO defines for Message:TXBAR_MSG_TRT_MALLOC_REQ

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_REQ__UPDATE
#define TXBAR_MSG_TRT_MALLOC_REQ__UPDATE__MSB                               10
#define TXBAR_MSG_TRT_MALLOC_REQ__UPDATE__LSB                               10
#define TXBAR_MSG_TRT_MALLOC_REQ__UPDATE__WIDTH                              1
#define TXBAR_MSG_TRT_MALLOC_REQ__UPDATE__MASK                           0x400
#define TXBAR_MSG_TRT_MALLOC_REQ__UPDATE__RESET_VALUE                      0x0

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_REQ__LAST
#define TXBAR_MSG_TRT_MALLOC_REQ__LAST__MSB                                  9
#define TXBAR_MSG_TRT_MALLOC_REQ__LAST__LSB                                  9
#define TXBAR_MSG_TRT_MALLOC_REQ__LAST__WIDTH                                1
#define TXBAR_MSG_TRT_MALLOC_REQ__LAST__MASK                             0x200
#define TXBAR_MSG_TRT_MALLOC_REQ__LAST__RESET_VALUE                        0x0

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT
#define TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT__MSB                               8
#define TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT__LSB                               8
#define TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT__WIDTH                             1
#define TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT__MASK                          0x100
#define TXBAR_MSG_TRT_MALLOC_REQ__LAN_PRT__RESET_VALUE                     0x0

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_REQ__TC
#define TXBAR_MSG_TRT_MALLOC_REQ__TC__MSB                                    7
#define TXBAR_MSG_TRT_MALLOC_REQ__TC__LSB                                    5
#define TXBAR_MSG_TRT_MALLOC_REQ__TC__WIDTH                                  3
#define TXBAR_MSG_TRT_MALLOC_REQ__TC__MASK                                0xe0
#define TXBAR_MSG_TRT_MALLOC_REQ__TC__RESET_VALUE                          0x0

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE
#define TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE__MSB                              4
#define TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE__LSB                              0
#define TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE__WIDTH                            5
#define TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE__MASK                          0x1f
#define TXBAR_MSG_TRT_MALLOC_REQ__PLD_SIZE__RESET_VALUE                    0x0

//-----Access structure typedef for Message:TXBAR_MSG_TRT_MALLOC_RSP
typedef union {
  struct {
    u32 ack   : 1;
    u32 drp   : 1;
    u32 rsvd0 : 30;
  };
  u32 reg;
} TXBAR_MSG_TRT_MALLOC_RSP;
//-----MACRO defines for Message:TXBAR_MSG_TRT_MALLOC_RSP

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_RSP__DRP
#define TXBAR_MSG_TRT_MALLOC_RSP__DRP__MSB                                   1
#define TXBAR_MSG_TRT_MALLOC_RSP__DRP__LSB                                   1
#define TXBAR_MSG_TRT_MALLOC_RSP__DRP__WIDTH                                 1
#define TXBAR_MSG_TRT_MALLOC_RSP__DRP__MASK                                0x2
#define TXBAR_MSG_TRT_MALLOC_RSP__DRP__RESET_VALUE                         0x0

//-----MACRO defines for fields:TXBAR_MSG_TRT_MALLOC_RSP__ACK
#define TXBAR_MSG_TRT_MALLOC_RSP__ACK__MSB                                   0
#define TXBAR_MSG_TRT_MALLOC_RSP__ACK__LSB                                   0
#define TXBAR_MSG_TRT_MALLOC_RSP__ACK__WIDTH                                 1
#define TXBAR_MSG_TRT_MALLOC_RSP__ACK__MASK                                0x1
#define TXBAR_MSG_TRT_MALLOC_RSP__ACK__RESET_VALUE                         0x0

//-----Access structure typedef for Message:TXBAR_MSG_RDB1_PLD_RLS
typedef union {
  struct {
    u32 tc            : 3;
    u32 eth_grp       : 2;
    u32 start_dl_idx  : 2;
    u32 pld_start_buf : 12;
    u32 pld_len       : 9;
    u32 rsvd0         : 4;
  };
  u32 reg;
} TXBAR_MSG_RDB1_PLD_RLS;
//-----MACRO defines for Message:TXBAR_MSG_RDB1_PLD_RLS

//-----MACRO defines for fields:TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN__MSB                                27
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN__LSB                                19
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN__WIDTH                               9
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN__MASK                        0xff80000
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_LEN__RESET_VALUE                       0x0

//-----MACRO defines for fields:TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF__MSB                          18
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF__LSB                           7
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF__WIDTH                        12
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF__MASK                    0x7ff80
#define TXBAR_MSG_RDB1_PLD_RLS__PLD_START_BUF__RESET_VALUE                 0x0

//-----MACRO defines for fields:TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX
#define TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX__MSB                            6
#define TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX__LSB                            5
#define TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX__WIDTH                          2
#define TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX__MASK                        0x60
#define TXBAR_MSG_RDB1_PLD_RLS__START_DL_IDX__RESET_VALUE                  0x0

//-----MACRO defines for fields:TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP
#define TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP__MSB                                 4
#define TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP__LSB                                 3
#define TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP__WIDTH                               2
#define TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP__MASK                             0x18
#define TXBAR_MSG_RDB1_PLD_RLS__ETH_GRP__RESET_VALUE                       0x0

//-----MACRO defines for fields:TXBAR_MSG_RDB1_PLD_RLS__TC
#define TXBAR_MSG_RDB1_PLD_RLS__TC__MSB                                      2
#define TXBAR_MSG_RDB1_PLD_RLS__TC__LSB                                      0
#define TXBAR_MSG_RDB1_PLD_RLS__TC__WIDTH                                    3
#define TXBAR_MSG_RDB1_PLD_RLS__TC__MASK                                   0x7
#define TXBAR_MSG_RDB1_PLD_RLS__TC__RESET_VALUE                            0x0

typedef struct {
  //TXBAR_MSG_TDB_PO_RLS  qw0;
  //TXBAR_MSG_TRT_MALLOC_REQ  qw0;
  //TXBAR_MSG_TRT_MALLOC_RSP  qw0;
  //TXBAR_MSG_RDB1_PLD_RLS  qw0;
} TXBAR_MSG;
//QW_CNT is actual number - 1
#define TXBAR_MSG_QW_CNT                                                    -1
//-----MACRO defines for  Message Group TB_FW_CMD_MSG: 0xf00000
#define TB_FW_CMD_MSG_MSG_ID                                              0xf0
//-----Access structure typedef for Message:TB_FW_CMD_MSG_QW0
typedef union {
  struct {
    u64 cnt      : 6;
    u64 rsvd0    : 2;
    u64 cmd_type : 8;
    u64 tag      : 8;
    u64 msg_id   : 8;
    u64 cmd_idx  : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} TB_FW_CMD_MSG_QW0;
//-----MACRO defines for Message:TB_FW_CMD_MSG_QW0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW0__CMD_IDX
#define TB_FW_CMD_MSG_QW0__CMD_IDX__MSB                                     63
#define TB_FW_CMD_MSG_QW0__CMD_IDX__LSB                                     32
#define TB_FW_CMD_MSG_QW0__CMD_IDX__WIDTH                                   32
#define TB_FW_CMD_MSG_QW0__CMD_IDX__MASK                    0xffffffff00000000
#define TB_FW_CMD_MSG_QW0__CMD_IDX__RESET_VALUE                            0x0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW0__MSG_ID
#define TB_FW_CMD_MSG_QW0__MSG_ID__MSB                                      31
#define TB_FW_CMD_MSG_QW0__MSG_ID__LSB                                      24
#define TB_FW_CMD_MSG_QW0__MSG_ID__WIDTH                                     8
#define TB_FW_CMD_MSG_QW0__MSG_ID__MASK                             0xff000000
#define TB_FW_CMD_MSG_QW0__MSG_ID__RESET_VALUE                             0x0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW0__TAG
#define TB_FW_CMD_MSG_QW0__TAG__MSB                                         23
#define TB_FW_CMD_MSG_QW0__TAG__LSB                                         16
#define TB_FW_CMD_MSG_QW0__TAG__WIDTH                                        8
#define TB_FW_CMD_MSG_QW0__TAG__MASK                                  0xff0000
#define TB_FW_CMD_MSG_QW0__TAG__RESET_VALUE                                0x0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW0__CMD_TYPE
#define TB_FW_CMD_MSG_QW0__CMD_TYPE__MSB                                    15
#define TB_FW_CMD_MSG_QW0__CMD_TYPE__LSB                                     8
#define TB_FW_CMD_MSG_QW0__CMD_TYPE__WIDTH                                   8
#define TB_FW_CMD_MSG_QW0__CMD_TYPE__MASK                               0xff00
#define TB_FW_CMD_MSG_QW0__CMD_TYPE__RESET_VALUE                           0x0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW0__CNT
#define TB_FW_CMD_MSG_QW0__CNT__MSB                                          5
#define TB_FW_CMD_MSG_QW0__CNT__LSB                                          0
#define TB_FW_CMD_MSG_QW0__CNT__WIDTH                                        6
#define TB_FW_CMD_MSG_QW0__CNT__MASK                                      0x3f
#define TB_FW_CMD_MSG_QW0__CNT__RESET_VALUE                                0x0

//-----Access structure typedef for Message:TB_FW_CMD_MSG_QW1
typedef union {
  struct {
    u64 addr  : 32;
    u64 val   : 32;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} TB_FW_CMD_MSG_QW1;
//-----MACRO defines for Message:TB_FW_CMD_MSG_QW1

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW1__VAL
#define TB_FW_CMD_MSG_QW1__VAL__MSB                                         63
#define TB_FW_CMD_MSG_QW1__VAL__LSB                                         32
#define TB_FW_CMD_MSG_QW1__VAL__WIDTH                                       32
#define TB_FW_CMD_MSG_QW1__VAL__MASK                        0xffffffff00000000
#define TB_FW_CMD_MSG_QW1__VAL__RESET_VALUE                                0x0

//-----MACRO defines for fields:TB_FW_CMD_MSG_QW1__ADDR
#define TB_FW_CMD_MSG_QW1__ADDR__MSB                                        31
#define TB_FW_CMD_MSG_QW1__ADDR__LSB                                         0
#define TB_FW_CMD_MSG_QW1__ADDR__WIDTH                                      32
#define TB_FW_CMD_MSG_QW1__ADDR__MASK                               0xffffffff
#define TB_FW_CMD_MSG_QW1__ADDR__RESET_VALUE                               0x0

typedef struct {
  TB_FW_CMD_MSG_QW0  qw0;
  TB_FW_CMD_MSG_QW1  qw1;
} TB_FW_CMD_MSG;
//QW_CNT is actual number - 1
#define TB_FW_CMD_MSG_QW_CNT                                                 1
//-----MACRO defines for  Message Group ECU_PEC_EVT: 0xf10000
#define ECU_PEC_EVT_MSG_ID                                                0xf1
//-----Access structure typedef for Message:ECU_PEC_EVT_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ECU_PEC_EVT_QW0;
//-----MACRO defines for Message:ECU_PEC_EVT_QW0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__FPM
#define ECU_PEC_EVT_QW0__FPM__MSB                                           58
#define ECU_PEC_EVT_QW0__FPM__LSB                                           49
#define ECU_PEC_EVT_QW0__FPM__WIDTH                                         10
#define ECU_PEC_EVT_QW0__FPM__MASK                           0x7fe000000000000
#define ECU_PEC_EVT_QW0__FPM__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__QPN
#define ECU_PEC_EVT_QW0__QPN__MSB                                           48
#define ECU_PEC_EVT_QW0__QPN__LSB                                           32
#define ECU_PEC_EVT_QW0__QPN__WIDTH                                         17
#define ECU_PEC_EVT_QW0__QPN__MASK                             0x1ffff00000000
#define ECU_PEC_EVT_QW0__QPN__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__MSG_ID
#define ECU_PEC_EVT_QW0__MSG_ID__MSB                                        31
#define ECU_PEC_EVT_QW0__MSG_ID__LSB                                        24
#define ECU_PEC_EVT_QW0__MSG_ID__WIDTH                                       8
#define ECU_PEC_EVT_QW0__MSG_ID__MASK                               0xff000000
#define ECU_PEC_EVT_QW0__MSG_ID__RESET_VALUE                               0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__REQ_TAG
#define ECU_PEC_EVT_QW0__REQ_TAG__MSB                                       23
#define ECU_PEC_EVT_QW0__REQ_TAG__LSB                                       16
#define ECU_PEC_EVT_QW0__REQ_TAG__WIDTH                                      8
#define ECU_PEC_EVT_QW0__REQ_TAG__MASK                                0xff0000
#define ECU_PEC_EVT_QW0__REQ_TAG__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__SRC
#define ECU_PEC_EVT_QW0__SRC__MSB                                           15
#define ECU_PEC_EVT_QW0__SRC__LSB                                           12
#define ECU_PEC_EVT_QW0__SRC__WIDTH                                          4
#define ECU_PEC_EVT_QW0__SRC__MASK                                      0xf000
#define ECU_PEC_EVT_QW0__SRC__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__DST
#define ECU_PEC_EVT_QW0__DST__MSB                                           11
#define ECU_PEC_EVT_QW0__DST__LSB                                           10
#define ECU_PEC_EVT_QW0__DST__WIDTH                                          2
#define ECU_PEC_EVT_QW0__DST__MASK                                       0xc00
#define ECU_PEC_EVT_QW0__DST__RESET_VALUE                                  0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__DSTFIFO
#define ECU_PEC_EVT_QW0__DSTFIFO__MSB                                        9
#define ECU_PEC_EVT_QW0__DSTFIFO__LSB                                        6
#define ECU_PEC_EVT_QW0__DSTFIFO__WIDTH                                      4
#define ECU_PEC_EVT_QW0__DSTFIFO__MASK                                   0x3c0
#define ECU_PEC_EVT_QW0__DSTFIFO__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW0__CNT
#define ECU_PEC_EVT_QW0__CNT__MSB                                            5
#define ECU_PEC_EVT_QW0__CNT__LSB                                            0
#define ECU_PEC_EVT_QW0__CNT__WIDTH                                          6
#define ECU_PEC_EVT_QW0__CNT__MASK                                        0x3f
#define ECU_PEC_EVT_QW0__CNT__RESET_VALUE                                  0x0

//-----Access structure typedef for Message:ECU_PEC_EVT_QW1
typedef union {
  struct {
    u64 event_id    : 8;
    u64 core_idx    : 1;
    u64 is_vf       : 1;
    u64 pf_index    : 8;
    u64 vf_index    : 16;
    u64 dma_vsi_idx : 8;
    u64 rsvd0       : 22;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ECU_PEC_EVT_QW1;
//-----MACRO defines for Message:ECU_PEC_EVT_QW1

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__DMA_VSI_IDX
#define ECU_PEC_EVT_QW1__DMA_VSI_IDX__MSB                                   41
#define ECU_PEC_EVT_QW1__DMA_VSI_IDX__LSB                                   34
#define ECU_PEC_EVT_QW1__DMA_VSI_IDX__WIDTH                                  8
#define ECU_PEC_EVT_QW1__DMA_VSI_IDX__MASK                       0x3fc00000000
#define ECU_PEC_EVT_QW1__DMA_VSI_IDX__RESET_VALUE                          0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__VF_INDEX
#define ECU_PEC_EVT_QW1__VF_INDEX__MSB                                      33
#define ECU_PEC_EVT_QW1__VF_INDEX__LSB                                      18
#define ECU_PEC_EVT_QW1__VF_INDEX__WIDTH                                    16
#define ECU_PEC_EVT_QW1__VF_INDEX__MASK                            0x3fffc0000
#define ECU_PEC_EVT_QW1__VF_INDEX__RESET_VALUE                             0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__PF_INDEX
#define ECU_PEC_EVT_QW1__PF_INDEX__MSB                                      17
#define ECU_PEC_EVT_QW1__PF_INDEX__LSB                                      10
#define ECU_PEC_EVT_QW1__PF_INDEX__WIDTH                                     8
#define ECU_PEC_EVT_QW1__PF_INDEX__MASK                                0x3fc00
#define ECU_PEC_EVT_QW1__PF_INDEX__RESET_VALUE                             0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__IS_VF
#define ECU_PEC_EVT_QW1__IS_VF__MSB                                          9
#define ECU_PEC_EVT_QW1__IS_VF__LSB                                          9
#define ECU_PEC_EVT_QW1__IS_VF__WIDTH                                        1
#define ECU_PEC_EVT_QW1__IS_VF__MASK                                     0x200
#define ECU_PEC_EVT_QW1__IS_VF__RESET_VALUE                                0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__CORE_IDX
#define ECU_PEC_EVT_QW1__CORE_IDX__MSB                                       8
#define ECU_PEC_EVT_QW1__CORE_IDX__LSB                                       8
#define ECU_PEC_EVT_QW1__CORE_IDX__WIDTH                                     1
#define ECU_PEC_EVT_QW1__CORE_IDX__MASK                                  0x100
#define ECU_PEC_EVT_QW1__CORE_IDX__RESET_VALUE                             0x0

//-----MACRO defines for fields:ECU_PEC_EVT_QW1__EVENT_ID
#define ECU_PEC_EVT_QW1__EVENT_ID__MSB                                       7
#define ECU_PEC_EVT_QW1__EVENT_ID__LSB                                       0
#define ECU_PEC_EVT_QW1__EVENT_ID__WIDTH                                     8
#define ECU_PEC_EVT_QW1__EVENT_ID__MASK                                   0xff
#define ECU_PEC_EVT_QW1__EVENT_ID__RESET_VALUE                             0x0

typedef struct {
  ECU_PEC_EVT_QW0  qw0;
  ECU_PEC_EVT_QW1  qw1;
} ECU_PEC_EVT;
//QW_CNT is actual number - 1
#define ECU_PEC_EVT_QW_CNT                                                   1
//-----MACRO defines for  Message Group ECU_PEC_EVT_RSP: 0xf20000
#define ECU_PEC_EVT_RSP_MSG_ID                                            0xf2
//-----Access structure typedef for Message:ECU_PEC_EVT_RSP_QW0
typedef union {
  struct {
    u64 cnt     : 6;
    u64 dstfifo : 4;
    u64 dst     : 2;
    u64 src     : 4;
    u64 req_tag : 8;
    u64 msg_id  : 8;
    u64 qpn     : 17;
    u64 fpm     : 10;
    u64 rsvd0   : 5;
  };
  u64 reg;
  struct {
    u32 dw0;
    u32 dw1;
  };
} ECU_PEC_EVT_RSP_QW0;
//-----MACRO defines for Message:ECU_PEC_EVT_RSP_QW0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__FPM
#define ECU_PEC_EVT_RSP_QW0__FPM__MSB                                       58
#define ECU_PEC_EVT_RSP_QW0__FPM__LSB                                       49
#define ECU_PEC_EVT_RSP_QW0__FPM__WIDTH                                     10
#define ECU_PEC_EVT_RSP_QW0__FPM__MASK                       0x7fe000000000000
#define ECU_PEC_EVT_RSP_QW0__FPM__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__QPN
#define ECU_PEC_EVT_RSP_QW0__QPN__MSB                                       48
#define ECU_PEC_EVT_RSP_QW0__QPN__LSB                                       32
#define ECU_PEC_EVT_RSP_QW0__QPN__WIDTH                                     17
#define ECU_PEC_EVT_RSP_QW0__QPN__MASK                         0x1ffff00000000
#define ECU_PEC_EVT_RSP_QW0__QPN__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__MSG_ID
#define ECU_PEC_EVT_RSP_QW0__MSG_ID__MSB                                    31
#define ECU_PEC_EVT_RSP_QW0__MSG_ID__LSB                                    24
#define ECU_PEC_EVT_RSP_QW0__MSG_ID__WIDTH                                   8
#define ECU_PEC_EVT_RSP_QW0__MSG_ID__MASK                           0xff000000
#define ECU_PEC_EVT_RSP_QW0__MSG_ID__RESET_VALUE                           0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__REQ_TAG
#define ECU_PEC_EVT_RSP_QW0__REQ_TAG__MSB                                   23
#define ECU_PEC_EVT_RSP_QW0__REQ_TAG__LSB                                   16
#define ECU_PEC_EVT_RSP_QW0__REQ_TAG__WIDTH                                  8
#define ECU_PEC_EVT_RSP_QW0__REQ_TAG__MASK                            0xff0000
#define ECU_PEC_EVT_RSP_QW0__REQ_TAG__RESET_VALUE                          0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__SRC
#define ECU_PEC_EVT_RSP_QW0__SRC__MSB                                       15
#define ECU_PEC_EVT_RSP_QW0__SRC__LSB                                       12
#define ECU_PEC_EVT_RSP_QW0__SRC__WIDTH                                      4
#define ECU_PEC_EVT_RSP_QW0__SRC__MASK                                  0xf000
#define ECU_PEC_EVT_RSP_QW0__SRC__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__DST
#define ECU_PEC_EVT_RSP_QW0__DST__MSB                                       11
#define ECU_PEC_EVT_RSP_QW0__DST__LSB                                       10
#define ECU_PEC_EVT_RSP_QW0__DST__WIDTH                                      2
#define ECU_PEC_EVT_RSP_QW0__DST__MASK                                   0xc00
#define ECU_PEC_EVT_RSP_QW0__DST__RESET_VALUE                              0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__DSTFIFO
#define ECU_PEC_EVT_RSP_QW0__DSTFIFO__MSB                                    9
#define ECU_PEC_EVT_RSP_QW0__DSTFIFO__LSB                                    6
#define ECU_PEC_EVT_RSP_QW0__DSTFIFO__WIDTH                                  4
#define ECU_PEC_EVT_RSP_QW0__DSTFIFO__MASK                               0x3c0
#define ECU_PEC_EVT_RSP_QW0__DSTFIFO__RESET_VALUE                          0x0

//-----MACRO defines for fields:ECU_PEC_EVT_RSP_QW0__CNT
#define ECU_PEC_EVT_RSP_QW0__CNT__MSB                                        5
#define ECU_PEC_EVT_RSP_QW0__CNT__LSB                                        0
#define ECU_PEC_EVT_RSP_QW0__CNT__WIDTH                                      6
#define ECU_PEC_EVT_RSP_QW0__CNT__MASK                                    0x3f
#define ECU_PEC_EVT_RSP_QW0__CNT__RESET_VALUE                              0x0

typedef struct {
  ECU_PEC_EVT_RSP_QW0  qw0;
} ECU_PEC_EVT_RSP;
//QW_CNT is actual number - 1
#define ECU_PEC_EVT_RSP_QW_CNT                                               0

#endif //MESSAGE_H_
