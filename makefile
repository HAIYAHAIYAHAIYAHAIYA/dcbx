OUTPUT_DIR = build
SOURCE_DIR = source
INCLUDE_DIR = include
CFLAGS = -c -g
MKDIR = mkdir -p
NUL = dev/null

include $(INCLUDE_DIR)/subdir.mk
include $(SOURCE_DIR)/subdir.mk

OBJS = $(C_SRCS:%.c=$(OUTPUT_DIR)/%.o)

TARGET = $(OUTPUT_DIR)\main.exe

CC = gcc
ALL = cleanall excute clean

#-lwsock32 	$(shell @$(MKDIR) $(dir $@) 2> dev/null || @echo off) -lmingw32 -lgdi32	@echo $(dir $@) @$(MKDIR) $(dir $@) 2> $(NUL)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $' -o $@
 
$(OBJS):$(OUTPUT_DIR)/%.o:%.c
# @echo $(dir $<)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY : ALL

cleanall:clean
	rm $(OUTPUT_DIR)/*.exe

clean:
	rm $(OUTPUT_DIR)/$(SOURCE_DIR)/MCTP/*.o \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/DCBX/*.o \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/APP/*.o  \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/HSM/*.o  \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/SHA256/*.o \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/CJSON/*.o \
		$(OUTPUT_DIR)/$(SOURCE_DIR)/PLDM_BEJ/*.o

excute:
	$(OUTPUT_DIR)/main
