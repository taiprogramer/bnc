# -*- Makefile -*-

# [compiler & flags]
CC = gcc
CFLAGS = -std=c11 -fstack-protector -pedantic-errors -Wunused-variable -Wall

SRC_DIR = src/
INSTALLED_DIR = /usr/lib/
INClUDE_DIR = /usr/include/
HEADER_FILE = $(SRC_DIR)bnc.h
SOURCE_FILE = $(SRC_DIR)libbnc.c
OBJ_FILE = $(SRC_DIR)libbnc.o
STATIC_LIB = $(SRC_DIR)libbnc.a

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
	@rm -rf $(SRC_DIR)*.o $(SRC_DIR)*.a

