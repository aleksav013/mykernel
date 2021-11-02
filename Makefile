ARCH=i686-elf-

export CC=$(ARCH)gcc
export AS=$(ARCH)as
export CFLAGS=-ffreestanding -O2 -Wall -Wextra -fstack-protector-all

MKDIR=mkdir -p
RM=rm -rf
CP=cp
QEMU=qemu-system-x86_64
#QEMU_DEBUG=-d int -D qemu.log

SOURCE_DIR=src
BUILD_DIR=${CURDIR}/build
ISO_DIR=isodir
AS_SOURCE_DIR=$(SOURCE_DIR)/as
C_SOURCE_DIR=$(SOURCE_DIR)/c
export AS_OBJECT_DIR=$(BUILD_DIR)/as
export C_OBJECT_DIR=$(BUILD_DIR)/c

TARGET=myos
BINARY=$(BUILD_DIR)/$(TARGET).bin
ISO=$(TARGET).iso

CRTI_OBJ=crti.o
CRTN_OBJ=crtn.o
AS_OBJ=boot.o irq.o paging.o
C_OBJ=gdt.o heap.o idt.o kernel.o keyboard.o keymap.o stdio.o string.o tty.o vga.o irq.o stack_protector.o timer.o paging.o

export C_OBJECTS=$(patsubst %,$(C_OBJECT_DIR)/%,$(C_OBJ))

AS_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(AS_OBJ))
CRTI_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTI_OBJ))
CRTN_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTN_OBJ))

export AS_OBJECTS=$(AS_OBJECT) $(CRTI_OBJECT) $(CRTN_OBJECT)

CRTBEGIN_OBJECT=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJECT=$(shell $(CC) -print-file-name=crtend.o)
OBJ=$(CRTI_OBJECT) $(CRTBEGIN_OBJECT) $(AS_OBJECT) $(C_OBJECTS) $(CRTEND_OBJECT) $(CRTN_OBJECT)


.PHONY: all compile run run-iso clean
all: compile

$(BINARY): $(OBJ)
	$(CC) -T $(SOURCE_DIR)/linker.ld -o $(BINARY) $(CFLAGS) -nostdlib -lgcc $(OBJ)

compile:
	./headers.sh
	$(MKDIR) $(AS_OBJECT_DIR)
	$(MKDIR) $(C_OBJECT_DIR)
	$(MAKE) --directory $(AS_SOURCE_DIR)
	$(MAKE) --directory $(C_SOURCE_DIR)
	$(MAKE) $(BINARY)

$(ISO): $(BINARY)
	grub-file --is-x86-multiboot $(BINARY)
	mkdir -p $(ISO_DIR)/boot/grub
	$(CP) $(BINARY) $(ISO_DIR)/boot/$(TARGET).bin
	$(CP) $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)

run: compile
	$(QEMU) -kernel $(BINARY) $(QEMU_DEBUG)

run-iso: compile
	$(MAKE) $(ISO)
	$(QEMU) -cdrom $(ISO)

clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(ISO)
