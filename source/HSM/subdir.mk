HSM_DIR = $(SOURCE_DIR)/HSM
INCLUDES += -I $(HSM_DIR)

HSM_C_SRCS = $(wildcard $(HSM_DIR)/*.c)

C_SRCS += $(HSM_C_SRCS)
