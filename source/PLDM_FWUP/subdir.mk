PLDM_FWUP_DIR = $(SOURCE_DIR)/PLDM_FWUP
INCLUDES += -I $(PLDM_FWUP_DIR)

PLDM_FWUP_C_SRCS = $(wildcard $(PLDM_FWUP_DIR)/*.c)

C_SRCS += $(PLDM_FWUP_C_SRCS)
