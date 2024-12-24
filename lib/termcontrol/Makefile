.PHONY: build

CC = gcc
C_OBJ_FLAGS = -Iinclude -fPIC -c
C_SO_FLAGS = -shared

C_SRC = $(shell find src -name *.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

SO_LIB = libtermcontrol.so

$(SO_LIB): $(C_OBJ)
	$(CC) $(C_SO_FLAGS) $(C_OBJ) -o $(SO_LIB)

$(C_OBJ): $(C_SRC) build
	$(CC) $(C_OBJ_FLAGS) $< -o $@

build:
	mkdir -p build/

clean:
	rm -rf build
	rm -f compile_commands.json
	rm -f $(SO_LIB)
