# HOST ARCH
ARCH=i686-aleksa-


# GCC CROSS COMPILER
export CC=$(ARCH)gcc
export AS=$(ARCH)as

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes

export CFLAGS=-ffreestanding -O2 -Wall -Wextra -fstack-protector-all


# TOOLS
MKDIR=mkdir -p
RM=rm -rf
CP=cp -r
QEMU=qemu-system-x86_64
#QEMU_DEBUG=-d int -D qemu.log



# DIRS

## SOURCE
SOURCE_DIR=src
AS_SOURCE_DIR=$(SOURCE_DIR)/as
C_SOURCE_DIR=$(SOURCE_DIR)/c
INCLUDE_DIR=$(SOURCE_DIR)/include

## BUILD
ISO_DIR=isodir
BUILD_DIR=${CURDIR}/build
export AS_OBJECT_DIR=$(BUILD_DIR)/as
export C_OBJECT_DIR=$(BUILD_DIR)/c

## SYSROOT
SYSROOT_DIR=/opt/aleksa
SYSROOT_USR_DIR=$(SYSROOT_DIR)/usr
SYSROOT_INCLUDE_DIR=$(SYSROOT_USR_DIR)/include

## GCC USR
GCC_USR_DIR=$(shell $(CC) -print-file-name=)
GCC_INCLUDE_DIR=$(GCC_USR_DIR)/include



# TARGET
TARGET=myos
BINARY=$(BUILD_DIR)/$(TARGET).bin
ISO=$(TARGET).iso



# OBJECTS

## AS OBJECTS
CRTI_OBJ=crti.o
CRTN_OBJ=crtn.o
AS_OBJ=boot.o irq.o paging.o

AS_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(AS_OBJ))
CRTI_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTI_OBJ))
CRTN_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTN_OBJ))
export AS_OBJECTS=$(AS_OBJECT) $(CRTI_OBJECT) $(CRTN_OBJECT)

CRTBEGIN_OBJECT=$(GCC_USR_DIR)/crtbegin.o
CRTEND_OBJECT=$(GCC_USR_DIR)/crtend.o

## C OBJECTS
C_OBJ=gdt.o heap.o idt.o kernel.o keyboard.o keymap.o stdio.o string.o tty.o vga.o irq.o stack_protector.o timer.o paging.o

export C_OBJECTS=$(patsubst %,$(C_OBJECT_DIR)/%,$(C_OBJ))

## ALL OBJECTS IN ORDER
OBJ=$(CRTI_OBJECT) $(CRTBEGIN_OBJECT) $(AS_OBJECT) $(C_OBJECTS) $(CRTEND_OBJECT) $(CRTN_OBJECT)



# OTHER FILES
LINKER=$(SOURCE_DIR)/linker.ld
GRUB.CFG=$(SOURCE_DIR)/grub.cfg


# RULES
.PHONY: all compile run run-iso clean install_headers
all: compile

$(BINARY): $(OBJ)
	$(CC) -T $(LINKER) -o $(BINARY) $(CFLAGS) -nostdlib -lgcc $(OBJ)

install_headers:
	$(RM) $(SYSROOT_INCLUDE_DIR)
	$(MKDIR) $(SYSROOT_INCLUDE_DIR)
	$(CP) $(INCLUDE_DIR)/* $(SYSROOT_INCLUDE_DIR)

compile:
	$(MAKE) install_headers
	$(MKDIR) $(AS_OBJECT_DIR)
	$(MKDIR) $(C_OBJECT_DIR)
	$(MAKE) --directory $(AS_SOURCE_DIR)
	$(MAKE) --directory $(C_SOURCE_DIR)
	$(MAKE) $(BINARY)

$(ISO): $(BINARY)
	grub-file --is-x86-multiboot $(BINARY)
	$(MKDIR) $(ISO_DIR)/boot/grub
	$(CP) $(BINARY) $(ISO_DIR)/boot/$(TARGET).bin
	$(CP) $(GRUB.CFG) $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)

run: compile
	$(QEMU) -kernel $(BINARY) $(QEMU_DEBUG)

run-iso: compile
	$(MAKE) $(ISO)
	$(QEMU) -cdrom $(ISO)

clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(ISO)
