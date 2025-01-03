CC = gcc

BIN = text_editor
INSTALL_PREFIX = /usr/local

STAT_LIB = termcontrol
DYN_LIB = vector
l_FLAGS = $(foreach stat_lib,$(STAT_LIB),-l$(stat_lib)) $(foreach dyn_lib,$(DYN_LIB),-l$(dyn_lib))
L_FLAGS = $(foreach stat_lib,$(STAT_LIB),-Llib/$(stat_lib)) $(foreach dyn_lib,$(DYN_LIB),-Llib/$(dyn_lib))
STAT_LIB_INCLUDES = $(foreach stat_lib,$(STAT_LIB),-Ilib/$(stat_lib)/include)
DYN_LIB_INCLUDES = $(foreach dyn_lib,$(DYN_LIB),-Ilib/$(dyn_lib)/include)

C_SRC = $(shell find src -name "*.c")
C_OBJ = $(patsubst src/%.c,build/%.o,$(C_SRC))

C_OBJ_FLAGS = $(STAT_LIB_INCLUDES) $(DYN_LIB_INCLUDES) -c
BIN_FLAGS = $(L_FLAGS) $(l_FLAGS) $(foreach dyn_lib,$(DYN_LIB),-Wl,-rpath,lib/$(dyn_lib))

.PHONY: install uninstall clean make_lib clean_lib

$(BIN): make_lib $(C_OBJ) 
	@echo "[!] Making binary file"
	$(CC) $(C_OBJ) -o $(BIN) $(BIN_FLAGS)

make_lib:
	@echo "[!] Making static libs"
	@$(foreach stat_lib,$(STAT_LIB),cd lib/$(stat_lib) && make)
	@echo "[!] Making dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make)

$(C_OBJ): build/%.o: src/%.c build
	mkdir -p $(dir $@)
	@echo "[!] Making object files from src"
	$(CC) $< -o $@ $(C_OBJ_FLAGS)

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

# ---------------------------------------------------------------------------------------------------

install:
	@echo "[!] Installing"
	sudo cp $(BIN) $(INSTALL_PREFIX)/bin
	@echo "[!] Installing dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make install)
	@echo "[!] Installing static libs"
	@$(foreach stat_lib,$(STAT_LIB),cd lib/$(stat_lib) && make install)
	sudo ldconfig

uninstall: uninstall_lib
	sudo rm -f $(INSTALL_PREFIX)/$(BIN)
	@echo "[!] Uninstalling"

uninstall_lib:
	@echo "[!] Uninstalling dynamic libs"
	@$(foreach dyn_lib,$(DYN_LIB),cd lib/$(dyn_lib) && make uninstall)
	@echo "[!] Uninstalling static libs"
	@$(foreach stat_lib,$(STAT_LIB),cd lib/$(stat_lib) && make uninstall)

