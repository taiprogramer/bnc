# -*- Makefile -*-

# [compiler & flags]
CC = tcc
CFLAGS = -std=c11 -Wall

INSTALLED_DIR = /usr/lib/
INClUDE_DIR = /usr/include/
HEADER_FILE = src/bnc.h
SOURCE_FILE = src/libbnc.c
OBJ_FILE = src/libbnc.o
STATIC_LIB = src/libbnc.a

# [cmd: make prog=foo]
$(prog): $(prog).c static
# ----- looking in src/ for header files
	@tcc -Isrc -o $@ $< $(OBJ_FILE)

.PHONY: static install clean
static:
	@$(CC) -c $(SOURCE_FILE) $(CFLAGS) -o $(OBJ_FILE)
	@ar rcs $(STATIC_LIB) $(OBJ_FILE)

install: static
	@cp $(STATIC_LIB) $(INSTALLED_DIR)
	@cp $(HEADER_FILE) $(INClUDE_DIR)

uninstall:
	@rm -rf $(INClUDE_DIR)$(HEADER_FILE)
	@rm -rf $(INSTALLED_DIR)$(STATIC_LIB)

clean:
	@rm -rf src/*.o src/*.a

