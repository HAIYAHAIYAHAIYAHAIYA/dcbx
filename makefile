OUTPUT_DIR = build
SOURCE_DIR = source
INCLUDE_DIR = include
MKDIR = mkdir -p
NUL = dev/null

CC_FLAGS = -I $(INCLUDE_DIR)/APP
CC_FLAGS += -I $(INCLUDE_DIR)/DCBX
CC_FLAGS += -I $(INCLUDE_DIR)/MCTP
CC_FLAGS += -I $(INCLUDE_DIR)/COMMON
CC_FLAGS += -I $(INCLUDE_DIR)/HSM
CC_FLAGS += -I $(INCLUDE_DIR)/SHA256

C_SRCS = $(wildcard $(SOURCE_DIR)/APP/*.c)
C_SRCS += $(wildcard $(SOURCE_DIR)/MCTP/*.c)
C_SRCS += $(wildcard $(SOURCE_DIR)/DCBX/*.c)
C_SRCS += $(wildcard $(SOURCE_DIR)/HSM/*.c)
C_SRCS += $(wildcard $(SOURCE_DIR)/SHA256/*.c)


OBJS = $(C_SRCS:%.c=$(OUTPUT_DIR)/%.o)

TARGET = $(OUTPUT_DIR)\main.exe

CC = gcc
ALL = cleanall excute clean

#-lwsock32 	$(shell @$(MKDIR) $(dir $@) 2> dev/null || @echo off) -lmingw32 -lgdi32	@echo $(dir $@) @$(MKDIR) $(dir $@) 2> $(NUL)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $' -o $@
 
$(OBJS):$(OUTPUT_DIR)/%.o:%.c
	$(CC) -c -g $(CC_FLAGS) $< -o $@

.PHONY : ALL

cleanall:clean
	del $(OUTPUT_DIR)\main.exe

clean:
	del $(OUTPUT_DIR)\$(SOURCE_DIR)\MCTP\*.o \
		$(OUTPUT_DIR)\$(SOURCE_DIR)\DCBX\*.o \
		$(OUTPUT_DIR)\$(SOURCE_DIR)\APP\*.o  \
		$(OUTPUT_DIR)\$(SOURCE_DIR)\HSM\*.o

excute:
	$(OUTPUT_DIR)/main
