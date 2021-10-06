SOURCE_DIR=src
BUILD_DIR=build
ISO_DIR=isodir

.PHONY: all
all: $(BUILD_DIR)/myos.bin
	grub-file --is-x86-multiboot $(BUILD_DIR)/myos.bin
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(BUILD_DIR)/myos.bin $(ISO_DIR)/boot/myos.bin
	cp $(SOURCE_DIR)/grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso $(ISO_DIR)

$(BUILD_DIR)/boot.o: $(SOURCE_DIR)/boot.s
	mkdir -p $(BUILD_DIR)
	i686-elf-as $(SOURCE_DIR)/boot.s -o $(BUILD_DIR)/boot.o

$(BUILD_DIR)/kernel.o: $(SOURCE_DIR)/kernel.c
	mkdir -p $(BUILD_DIR)
	i686-elf-gcc -c $(SOURCE_DIR)/kernel.c -o $(BUILD_DIR)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(BUILD_DIR)/myos.bin: $(BUILD_DIR)/kernel.o $(BUILD_DIR)/boot.o
	mkdir -p $(BUILD_DIR)
	i686-elf-gcc -T $(SOURCE_DIR)/linker.ld -o $(BUILD_DIR)/myos.bin -ffreestanding -O2 -nostdlib $(BUILD_DIR)/boot.o $(BUILD_DIR)/kernel.o -lgcc

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(ISO_DIR) myos.iso
