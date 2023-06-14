ARCH = armv7-a
MCPU = cortex-a8

TARGET = rvpb

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy

LINKER_SCRIPT = ./moonix.ld
MAP_FILE = build/moonix.map

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.os, $(ASM_SRCS))

VPATH = boot 			\
        hal/$(TARGET)	\
        lib

C_SRCS  = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_SRCS += $(notdir $(wildcard lib/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS  = -I include 			\
            -I hal	   			\
            -I hal/$(TARGET)	\
            -I lib

CFLAGS = -c -g -std=c11 -mthumb-interwork

LDFLAGS = -nostartfiles -nostdlib -nodefaultlibs -static -lgcc

moonix = build/moonix.axf
moonix_bin = build/moonix.bin

.PHONY: all clean run debug gdb

all: $(moonix)

clean:
	@rm -fr build
	
run: $(moonix)
	qemu-system-arm -M realview-pb-a8 -kernel $(moonix) -nographic
	
debug: $(moonix)
	qemu-system-arm -M realview-pb-a8 -kernel $(moonix) -S -gdb tcp::1111,ipv4
	
gdb:
	arm-none-eabi-gdb

kill:
	killall qemu-system-arm	

$(moonix): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -n -T $(LINKER_SCRIPT) -o $(moonix) $(ASM_OBJS) $(C_OBJS) -Wl,-Map=$(MAP_FILE) $(LDFLAGS)
	$(OC) -O binary $(moonix) $(moonix_bin)
	
build/%.os: %.S
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) -marm $(INC_DIRS) $(CFLAGS) -o $@ $<
	
build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) -marm $(INC_DIRS) $(CFLAGS) -o $@ $<
	
