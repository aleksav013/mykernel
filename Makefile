CC=i686-elf-gcc
AS=i686-elf-as
CFLAGS=-ffreestanding -O2 -Wall -Wextra

MKDIR=mkdir -p
RM=rm -rf
CP=cp

SOURCE_DIR=src
BUILD_DIR=build
ISO_DIR=isodir

TARGET=myos

OBJ_FILES=boot.o kernel.o gdt.o
CRTBEGIN_OBJ=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJ=$(shell $(CC) -print-file-name=crtend.o)
OBJ=$(BUILD_DIR)/crti.o $(CRTBEGIN_OBJ) $(patsubst %,$(BUILD_DIR)/%,$(OBJ_FILES)) $(CRTEND_OBJ) $(BUILD_DIR)/crtn.o

# Creating iso file
$(TARGET).iso: $(BUILD_DIR)/$(TARGET).bin
	grub-file --is-x86-multiboot $(BUILD_DIR)/myos.bin
	mkdir -p $(ISO_DIR)/boot/grub
	$(CP) $(BUILD_DIR)/myos.bin $(ISO_DIR)/boot/myos.bin
	$(CP) $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(TARGET).iso $(ISO_DIR)

# Linking object files
$(BUILD_DIR)/$(TARGET).bin: $(OBJ)
	$(MKDIR) $(BUILD_DIR)
	$(CC) -T $(SOURCE_DIR)/linker.ld -o $@ $(CFLAGS) -nostdlib $^ -lgcc

# Compiling as sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.s
	$(MKDIR) $(BUILD_DIR)
	$(AS) $< -o $@

# Compiling C sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(MKDIR) $(BUILD_DIR)
	$(CC) -c $< -o $@ -std=gnu99 $(CFLAGS)

# Boot kernel in qemu
.PHONY: run
run: $(TARGET).iso
	qemu-system-x86_64 -cdrom $(TARGET).iso

# Clean build files
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) $(TARGET).iso
