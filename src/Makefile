.PHONY: all build_as build_c

all: build_as build_c

build_as:
	$(MKDIR) $(AS_OBJECT_DIR)
	@$(MAKE) --directory as

build_c:
	$(MKDIR) $(C_OBJECT_DIR)
	@$(MAKE) --directory c
