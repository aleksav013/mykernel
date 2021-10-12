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

OBJ_FILES=boot.o kernel.o gdt.o idt.o keyboard.o vga.o string.o tty.o
CRTBEGIN_OBJ=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJ=$(shell $(CC) -print-file-name=crtend.o)
OBJ=$(BUILD_DIR)/crti.o $(CRTBEGIN_OBJ) $(patsubst %,$(BUILD_DIR)/%,$(OBJ_FILES)) $(CRTEND_OBJ) $(BUILD_DIR)/crtn.o


# Default action is set to making kernel binary
.PHONY: all
all: $(BUILD_DIR)/$(TARGET).bin

# Creating iso file
$(TARGET).iso: $(BUILD_DIR)/$(TARGET).bin
	grub-file --is-x86-multiboot $(BUILD_DIR)/myos.bin
	mkdir -p $(ISO_DIR)/boot/grub
	$(CP) $(BUILD_DIR)/myos.bin $(ISO_DIR)/boot/myos.bin
	$(CP) $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(TARGET).iso $(ISO_DIR)

# Linking object files into kernel binary
$(BUILD_DIR)/$(TARGET).bin: $(OBJ)
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
.PHONY: run
run: $(BUILD_DIR)/$(TARGET).bin
	$(QEMU) -kernel $^

# Boot iso in qemu
.PHONY: run-iso
run-iso: $(TARGET).iso
	$(QEMU) -cdrom $^

# Debug kernel binary in gdb
.PHONY: debug
debug: $(TARGET).bin
	$(QEMU) -kernel $^ -s -S &
	gdb -x .gdbinit

# Clean build files
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(TARGET).iso
