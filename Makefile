ARCH=i686-elf

export CC=$(ARCH)-gcc
export AS=$(ARCH)-as
export CFLAGS=-ffreestanding -O2 -Wall -Wextra -fstack-protector-all

MKDIR=mkdir -p
RM=rm -rf
CP=cp
QEMU=qemu-system-x86_64

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

CRTI_SOURCE=crti.s
CRTN_SOURCE=crtn.s
AS_SOURCE=boot.s irq.s paging.s
C_SOURCES=gdt.c heap.c idt.c kernel.c keyboard.c keymap.c stdio.c string.c tty.c vga.c irq.c stack_protector.c timer.c paging.c

C_SOURCE_FILES=$(patsubst %,$(C_SOURCE_DIR)/%,$(C_SOURCES))
export C_OBJECTS=$(patsubst %,$(C_OBJECT_DIR)/%,$(C_SOURCES:c=o))

AS_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(AS_SOURCE:s=o))
CRTI_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTI_SOURCE:s=o))
CRTN_OBJECT=$(patsubst %,$(AS_OBJECT_DIR)/%,$(CRTN_SOURCE:s=o))

AS_SOURCES=$(AS_SOURCE) $(CRTI_SOURCE) $(CRTN_SOURCE)
AS_SOURCE_FILES=$(patsubst %,$(AS_SOURCE_DIR)/%,$(AS_SOURCES))
export AS_OBJECTS=$(patsubst %,$(AS_OBJECT_DIR)/%,$(AS_SOURCES:s=o))

CRTBEGIN_OBJ=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJ=$(shell $(CC) -print-file-name=crtend.o)
OBJ=$(CRTI_OBJECT) $(CRTBEGIN_OBJ) $(AS_OBJECT) $(C_OBJECTS) $(CRTEND_OBJ) $(CRTN_OBJECT)



.PHONY: all compile run run-iso clean
all: compile

$(BINARY): $(OBJ)
	$(CC) -T $(SOURCE_DIR)/linker.ld -o $(BINARY) $(CFLAGS) -nostdlib -lgcc $(OBJ)

compile: $(AS_SOURCE_FILES) $(C_SOURCE_FILES)
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
	$(QEMU) -kernel $(BINARY)

run-iso: compile $(ISO)
	$(QEMU) -cdrom $(ISO)

clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(ISO)
