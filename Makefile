CC = i686-elf-gcc
AS = i686-elf-as
CFLAGS = 

MKDIR = mkdir -p
RM = rm -rf
CP = cp

SOURCE_DIR = src
BUILD_DIR = build
ISO_DIR = isodir

AS_SOURCE = boot.s
C_SOURCE = kernel.c

OBJ_FILES = boot.o kernel.o
CRTBEGIN_OBJ:=$(shell $(CC) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) -print-file-name=crtend.o)

OBJ = $(BUILD_DIR)/crti.o $(CRTBEGIN_OBJ) $(patsubst %,$(BUILD_DIR)/%,$(OBJ_FILES)) $(CRTEND_OBJ) $(BUILD_DIR)/crtn.o

# Creating iso file
.PHONY: all
all: $(BUILD_DIR)/myos.bin
	grub-file --is-x86-multiboot $(BUILD_DIR)/myos.bin
	mkdir -p $(ISO_DIR)/boot/grub
	$(CP) $(BUILD_DIR)/myos.bin $(ISO_DIR)/boot/myos.bin
	$(CP) $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso $(ISO_DIR)

# Linking object files
$(BUILD_DIR)/myos.bin: $(OBJ)
	$(MKDIR) $(BUILD_DIR)
	$(CC) -T $(SOURCE_DIR)/linker.ld -o $(BUILD_DIR)/myos.bin -ffreestanding -O2 -nostdlib $(OBJ) -lgcc

# Compiling as sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.s
	$(MKDIR) $(BUILD_DIR)
	$(AS) $< -o $@

# Compiling C sources
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(MKDIR) $(BUILD_DIR)
	$(CC) -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# Cleaning
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR) $(ISO_DIR) myos.iso
