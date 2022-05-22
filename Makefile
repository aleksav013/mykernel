# HOST ARCH
ARCH=i686-aleksa-


# GCC CROSS COMPILER
export CC=$(ARCH)gcc
export AS=$(ARCH)as

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes

export CFLAGS=-std=gnu99 -O3 $(WARNINGS) -ffreestanding -fstack-protector-all


# TOOLS
export MKDIR=mkdir -p
export RM=rm -rf
export CP=cp -r
QEMU=qemu-system-i386



# DIRS

## SOURCE
SOURCE_DIR=src

## BUILD
ISO_DIR=isodir
BUILD_DIR=${CURDIR}/build
export AS_OBJECT_DIR=$(BUILD_DIR)/as
export C_OBJECT_DIR=$(BUILD_DIR)/c

## GCC USR
GCC_USR_DIR=$(shell $(CC) -print-file-name=)



# TARGET
TARGET=aleksa-os
BINARY=$(BUILD_DIR)/$(TARGET).bin
ISO=$(TARGET).iso



# OBJECTS

## AS OBJECTS
AS_OBJ=boot.o ioport.o gdt.o idt.o irq.o paging.o
export AS_OBJECTS=$(patsubst %,$(AS_OBJECT_DIR)/%,$(AS_OBJ))

## C OBJECTS
C_OBJ=gdt.o heap.o idt.o kernel.o keyboard.o keymap.o stdio.o string.o tty.o vga.o irq_handler.o stack_protector.o timer.o paging.o
export C_OBJECTS=$(patsubst %,$(C_OBJECT_DIR)/%,$(C_OBJ))

## ALL OBJECTS IN ORDER
OBJ=$(GCC_USR_DIR)crti.o $(GCC_USR_DIR)crtbegin.o $(AS_OBJECTS) $(C_OBJECTS) $(GCC_USR_DIR)crtend.o $(GCC_USR_DIR)crtn.o



# OTHER FILES
LINKER=$(SOURCE_DIR)/linker.ld
GRUB.CFG=$(SOURCE_DIR)/grub.cfg


# RULES
.PHONY: all clean compile install_headers iso run run-iso
all: compile

clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(ISO)

$(BINARY): $(OBJ)
	$(CC) -T $(LINKER) -o $(BINARY) $(CFLAGS) -nostdlib -lgcc $(OBJ)

install_headers:
	./scripts/install_headers.sh

compile:
	$(MAKE) install_headers
	@$(MAKE) --directory $(SOURCE_DIR)
	$(MAKE) $(BINARY)

$(ISO): $(OBJ) $(GRUB.CFG)
ifeq ($(shell ./scripts/is_multiboot.sh), 0)
	$(MKDIR) $(ISO_DIR)/boot/grub
	$(CP) $(BINARY) $(ISO_DIR)/boot/$(TARGET).bin
	$(CP) $(GRUB.CFG) $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)
else
	@echo "$(BINARY) is not x86 multiboot compatible"
	$(RM) $(BINARY)
endif

iso: compile
	$(MAKE) $(ISO)

run: compile
	$(QEMU) -kernel $(BINARY) $(QEMU_DEBUG)

run-iso: iso
	$(QEMU) -cdrom $(ISO)
