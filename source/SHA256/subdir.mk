SHA256_DIR = $(SOURCE_DIR)/SHA256
INCLUDES += -I $(SHA256_DIR)

SHA256_C_SRCS = $(wildcard $(SHA256_DIR)/*.c)

C_SRCS += $(SHA256_C_SRCS)