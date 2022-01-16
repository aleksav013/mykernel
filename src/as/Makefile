.PHONY: all

all: $(AS_OBJECTS)

$(AS_OBJECT_DIR)/%.o: %.s Makefile
	$(AS) $< -o $@
