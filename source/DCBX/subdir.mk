DCBX_DIR = $(SOURCE_DIR)/DCBX
INCLUDES += -I $(DCBX_DIR)

DCBX_C_SRCS = $(wildcard $(DCBX_DIR)/*.c)

C_SRCS += $(DCBX_C_SRCS)
