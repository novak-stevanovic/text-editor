CC = gcc

BIN = text_editor

STAT_LIB = termcontrol
DYN_LIB = vector
l_FLAGS = $(foreach stat_lib,$(STAT_LIB),-l$(stat_lib)) $(foreach dyn_lib,$(DYN_LIB),-l$(dyn_lib))
L_FLAGS = $(foreach stat_lib,$(STAT_LIB),-Llib/$(stat_lib)) $(foreach dyn_lib,$(DYN_LIB),-Llib/$(dyn_lib))
STAT_LIB_INCLUDES = $(foreach stat_lib,$(STAT_LIB),-Ilib/$(stat_lib)/include)
DYN_LIB_INCLUDES = $(foreach dyn_lib,$(DYN_LIB),-Ilib/$(dyn_lib)/include)

C_SRC = $(shell find src -name "*.c")
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

C_OBJ_FLAGS = $(STAT_LIB_INCLUDES) $(DYN_LIB_INCLUDES) $(l_FLAGS) $(L_FLAGS) -c
BIN_FLAGS = $(l_FLAGS) $(L_FLAGS)

.PHONY: install uninstall clean make_lib clean_lib

$(BIN): $(C_OBJ) make_lib
	@echo "[!] Making binary file"
	$(CC) $(BIN_FLAGS) $(C_OBJ) -o $(BIN)

make_lib:
	@echo "[!] Making static libs"
	@$(foreach stat_lib,$(STAT_LIB),cd lib/$(stat_lib) && make)
	@echo "[!] Making dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make)

$(C_OBJ): $(C_SRC) build
	@echo "[!] Making object files from src"
	$(CC) $(C_OBJ_FLAGS) $< -o $@

build:
	mkdir -p build

clean: clean_lib
	rm -f $(BIN)
	rm -rf build
	rm -f compile_commands.json

clean_lib:
	@echo "[!] Cleaning static libs"
	@$(foreach stat_lib,$(STAT_LIB),cd lib/$(stat_lib) && make clean)
	@echo "[!] Cleaning dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make clean)

install:
	@echo "[!] Installing"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make install)


uninstall: uninstall_lib
	@echo "[!] Uninstalling"

uninstall_lib:
	@echo "[!] Uninstalling dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make uninstall)

