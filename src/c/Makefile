.PHONY: all

all: $(C_OBJECTS)

$(C_OBJECT_DIR)/%.o: %.c Makefile
	$(CC) $(CFLAGS) -MD -MP -c $< -o $@

-include $(C_OBJECTS:.o=.d)
