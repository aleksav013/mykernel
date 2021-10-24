.PHONY: all
all: $(AS_OBJECTS)

$(BUILD_DIR)/%.o: %.s
	$(AS) $< -o $@
