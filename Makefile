BUILD_DIR=build
ISO_DIR=isodir

.PHONY: all
all: $(BUILD_DIR)/myos.bin
	grub-file --is-x86-multiboot $(BUILD_DIR)/myos.bin
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(BUILD_DIR)/myos.bin $(ISO_DIR)/boot/myos.bin
	cp grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso $(ISO_DIR)

$(BUILD_DIR)/boot.o: boot.s
	mkdir -p $(BUILD_DIR)
	i686-elf-as boot.s -o $(BUILD_DIR)/boot.o

$(BUILD_DIR)/kernel.o: kernel.c
	mkdir -p $(BUILD_DIR)
	i686-elf-gcc -c kernel.c -o $(BUILD_DIR)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(BUILD_DIR)/myos.bin: $(BUILD_DIR)/kernel.o $(BUILD_DIR)/boot.o
	mkdir -p $(BUILD_DIR)
	i686-elf-gcc -T linker.ld -o $(BUILD_DIR)/myos.bin -ffreestanding -O2 -nostdlib $(BUILD_DIR)/boot.o $(BUILD_DIR)/kernel.o -lgcc

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(ISO_DIR) myos.iso
