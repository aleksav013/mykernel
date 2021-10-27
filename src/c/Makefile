.PHONY: all
all: $(C_OBJECTS)

$(C_OBJECT_DIR)/%.o: %.c
	$(CC) -c $< -o $@ -std=gnu99 $(CFLAGS)
