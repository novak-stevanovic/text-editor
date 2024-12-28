.PHONY: build

CC = gcc
C_SRC_FLAGS = -Iinclude -c -Wall

INSTALL_PREFIX = /usr/local

C_SRC = $(shell find src -name *.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

A_LIB = libtermcontrol.a

$(A_LIB): $(C_OBJ)
	ar rcs $(A_LIB) $(C_OBJ)

$(C_OBJ): build/%.o: src/%.c build
	mkdir -p $(dir $@)
	$(CC) $(C_SRC_FLAGS) $< -o $@

build:
	mkdir -p build/

install:
	sudo mkdir -p $(INSTALL_PREFIX)/include/termcontrol
	sudo cp -r include/* $(INSTALL_PREFIX)/include/termcontrol
	sudo cp $(A_LIB) $(INSTALL_PREFIX)/lib

uninstall:
	sudo rm -rf $(INSTALL_PREFIX)/include/termcontrol
	sudo rm -f $(INSTALL_PREFIX)/lib/$(A_LIB)

clean:
	rm -rf build
	rm -f compile_commands.json
	rm -f $(A_LIB)

