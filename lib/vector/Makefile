CC = gcc
C_OBJ_FLAGS = -c -Iinclude -Wall -fPIC

INSTALL_PREFIX = /usr/local

C_SRC = $(wildcard src/*.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

SO_LIB = libvector.so
SO_FLAGS = -shared

.PHONY: clean install uninstall

$(SO_LIB): $(C_OBJ)
	$(CC) $(SO_FLAGS) $(C_OBJ) -o $(SO_LIB)

$(C_OBJ): build/%.o: src/%.c build
	mkdir -p $(dir $@)
	$(CC) $(C_OBJ_FLAGS) $< -o $@

build:
	mkdir -p build/

install:
	sudo cp libvector.so $(INSTALL_PREFIX)/lib
	sudo mkdir -p $(INSTALL_PREFIX)/include/vector
	sudo cp -r include/* $(INSTALL_PREFIX)/include/vector/

uninstall:
	sudo rm -f $(INSTALL_PREFIX)/lib/libvector.so
	sudo rm -rf $(INSTALL_PREFIX)/include/vector/

clean:
	rm -rf build
	rm -f $(SO_LIB)
	rm -f compile_commands.json
