CC = gcc

C_SRC = $(shell find src -name *.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

C_LIB_INCLUDE = $(shell find lib -name include)

.C_LIB_A_FILES = $(shell find lib -name *.a -o -name *.so)
.C_LIB_A_BASENAME = $(notdir $(basename $(.C_LIB_A_FILES)))
C_LIB_A = $(patsubst lib%,%,$(.C_LIB_A_BASENAME))

C_LIB_A_PATHS = $(dir $(.C_LIB_A_FILES))

BIN = text_editor

C_LIB_OPTS = $(foreach include_path,$(C_LIB_INCLUDE),-I$(include_path)) $(foreach lib_path,$(C_LIB_A_PATHS),-L$(lib_path)) $(foreach lib_name,$(C_LIB_A),-l$(lib_name))

C_FLAGS = -Wall -Wextra -Iinclude $(C_LIB_OPTS)

.PHONY: clean

$(BIN): $(C_OBJ)
	export LD_LIBRARY_PATH=$(shell pwd)/lib/termcontrol:$(LD_LIBRARY_PATH)
	gcc $(C_OBJ) $(C_FLAGS) -o $(BIN)

$(C_OBJ): $(C_SRC) build
	gcc -c $< $(C_FLAGS) -o $@

build:
	mkdir -p build/

clean:
	rm -rf build/
	rm -f $(BIN)
	rm -f compile_commands.json

