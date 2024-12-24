CC = gcc
C_OBJ_FLAGS = -c -Iinclude -Wall -fPIC

C_SRC = $(wildcard src/*.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

SO_LIB = libvector.so
SO_FLAGS = -shared

.PHONY: clean install

$(SO_LIB): $(C_OBJ)
	$(CC) $(SO_FLAGS) $(C_OBJ) -o $(SO_LIB)

$(C_OBJ): $(C_SRC) build
	$(CC) $(C_OBJ_FLAGS) $< -o $@

build:
	mkdir -p build/

install:
	sudo cp libvector.so /usr/local/lib/
	sudo mkdir -p /usr/local/include/vector
	sudo cp -r include/* /usr/local/include/vector/

uninstall:
	sudo rm -f /usr/local/lib/libvector.so
	sudo rm -rf /usr/local/include/vector/

clean:
	rm -rf build
	rm -f $(SO_LIB)
	rm -f compile_commands.json
