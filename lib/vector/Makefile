CC = gcc
CFLAGS = -c -Iinclude

C_SRC = $(wildcard src/*.c)
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

AR = ar
ARFLAGS = rcs

LIB = libvector.a

$(LIB): $(C_OBJ)
	$(AR) $(ARFLAGS) $(LIB) $(C_OBJ)

$(C_OBJ): $(C_SRC) build
	$(CC) $(CFLAGS) $< -o $@

build:
	mkdir -p build/

clean:
	rm -rf build
	rm -f $(LIB)
	rm -f compile_commands.json




