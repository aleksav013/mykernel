.PHONY: all
all: $(C_OBJECTS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $< -o $@ -std=gnu99 $(CFLAGS)
