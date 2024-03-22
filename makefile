OUTPUT_DIR = build
SOURCE_DIR = source
INCLUDE_DIR = include
CFLAGS = -c -g
MKDIR = mkdir -p
NUL = dev/null

include $(INCLUDE_DIR)/subdir.mk
include $(SOURCE_DIR)/subdir.mk

OBJS = $(C_SRCS:%.c=$(OUTPUT_DIR)/%.o)
OBJS_D := $(patsubst %.c,$(OUTPUT_DIR)/%.d,$(C_SRCS))		# add .d 自动生成依赖

TARGET = $(OUTPUT_DIR)\main.exe

CC = gcc
ALL = cleanall excute clean

#-lwsock32 	$(shell @$(MKDIR) $(dir $@) 2> dev/null || @echo off) -lmingw32 -lgdi32	@echo $(dir $@) @$(MKDIR) $(dir $@) 2> $(NUL)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $' -o $@

-include $(OBJS_D)
$(OBJS):$(OUTPUT_DIR)/%.o:%.c
# $(CC) $(CFLAGS) -MMD $(INCLUDES) $< -o $@
	gcc $(INCLUDES) $< -c -MMD -o $@

.PHONY : ALL

cleanall:clean
	rm -rf $(OUTPUT_DIR)/*.exe

clean:
	rm -rf $(OUTPUT_DIR)/$(SOURCE_DIR)/MCTP/*.o *.d \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/DCBX/*.o *.d \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/APP/*.o *.d  \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/HSM/*.o *.d  \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/SHA256/*.o *.d \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/CJSON/*.o *.d \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/PLDM_BEJ/*.o *.d \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/PLDM_PDR/*.o *.d

excute:
	$(OUTPUT_DIR)/main
