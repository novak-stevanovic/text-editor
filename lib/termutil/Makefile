.PHONY: build

CC = gcc
CFLAGS = -Iinclude

C_SRC = $(shell find src -name *.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

AR_LIB = libtermutil.a

$(AR_LIB): $(C_OBJ)
	ar rcs $(AR_LIB) $(C_OBJ) 

$(C_OBJ): $(C_SRC) build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build/

clean:
	rm -rf build
	rm -f compile_commands.json
	rm -f $(AR_LIB)

