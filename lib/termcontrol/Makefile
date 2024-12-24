.PHONY: build

CC = gcc
C_SO_FLAGS = -Iinclude -fPIC -shared

C_SRC = $(shell find src -name *.c)

SO_LIB = libtermcontrol.so

$(SO_LIB): $(C_SRC)
	$(CC) $(C_SRC) $(C_SO_FLAGS) -o $(SO_LIB)

build:
	mkdir -p build/

clean:
	rm -rf build
	rm -f compile_commands.json
	rm -f $(SO_LIB)
