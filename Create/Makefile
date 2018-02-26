TARGET = template

DEBUG = 1

OPT = -Og

#sources path
SOURCES_DIR = \
CORE \
HALLIB/Src \

BUILD_DIR = build

#C Sources
#src/stm32f7xx_hal_msp.c \
#src/main.c \
#src/stm32f7xx_it.c \
#src/system_stm32f7xx.c \

C_SOURCES = \
$(wildcard *.c src/*.c) \
$(wildcard *.c HALLIB/Src/*.c)  

ASM_SOURCES = CORE/startup_stm32f767xx.s


#BIN
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
AR = $(PREFIX)ar
SZ = $(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

CPU = -mcpu=cortex-m7

FPU = -mfpu=fpv5-d16

FLOAT-ABI = -mfloat-abi=hard

MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

AS_DEFS = 

#C define
C_DEFS = \
-DUSE_HAL_DRIVER \
-DSTM32F767xx 

AS_INCLUDES = 

#C Include
C_INCLUDES = \
-IInc \
-IHALLIB/Inc \
-IHALLIB/Inc/Legacy \
-ICORE \
-IHardWare

#compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"

#LDFLAGS
#Link script
LDSCRIPT = STM32F767IGTx_FLASH.ld

#libraries
LIBS = -lc -lm -lnosys
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

#default action:build all
all:$(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

#build the app
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
#list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

#clean up
clean:
	rm -fR .dep $(BUILD_DIR)

#dependencies
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

#st-flash
dowload:
	st-flash write build/$(TARGET).bin 0x8000000

