ARCH=i686-elf

CC=$(ARCH)-gcc
AS=$(ARCH)-as
CFLAGS=-ffreestanding -O2 -Wall -Wextra

MKDIR=mkdir -p
RM=rm -rf
CP=cp
QEMU=qemu-system-x86_64

SOURCE_DIR=src
BUILD_DIR=build
ISO_DIR=isodir

TARGET=myos
BINARY=$(BUILD_DIR)/$(TARGET).bin
ISO=$(TARGET).iso

OBJ_FILES=boot.o kernel.o gdt.o idt.o keyboard.o keymap.o vga.o string.o tty.o stdio.o heap.o
CRTBEGIN_OBJ=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJ=$(shell $(CC) -print-file-name=crtend.o)
OBJ=$(BUILD_DIR)/crti.o $(CRTBEGIN_OBJ) $(patsubst %,$(BUILD_DIR)/%,$(OBJ_FILES)) $(CRTEND_OBJ) $(BUILD_DIR)/crtn.o


# Default action is set to making kernel binary
.PHONY: all run run-iso clean
all: $(BINARY)

# Creating iso file
$(ISO): $(BINARY)
	grub-file --is-x86-multiboot $(BINARY)
	mkdir -p $(ISO_DIR)/boot/grub
	$(CP) $(BINARY) $(ISO_DIR)/boot/$(TARGET).bin
	$(CP) $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR)

# Linking object files into kernel binary
$(BINARY): $(OBJ)
	$(CC) -T $(SOURCE_DIR)/linker.ld -o $@ $(CFLAGS) -nostdlib $^ -lgcc

# Compiling as sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.s
	$(MKDIR) $(BUILD_DIR)
	$(AS) $< -o $@

# Compiling C sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(MKDIR) $(BUILD_DIR)
	$(CC) -c $< -o $@ -std=gnu99 $(CFLAGS)

# Boot kernel binary in qemu
run: $(BINARY)
	$(QEMU) -kernel $<

# Boot iso in qemu
run-iso: $(ISO)
	$(QEMU) -cdrom $<

# Clean build files
clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(ISO)
