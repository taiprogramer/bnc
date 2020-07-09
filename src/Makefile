# -*- Makefile -*-

# [compiler & flags]
CC = gcc
CFLAGS = -std=c11 -fstack-protector -pedantic-errors -Wunused-variable -Wall

INSTALLED_DIR = /usr/lib/
SOURCE_FILE = libbnc.c
OBJ_FILE = libbnc.o
STATIC_LIB = libbnc.a

.PHONY: clean static
static:
	@$(CC) -c $(SOURCE_FILE) $(CFLAGS) -o $(OBJ_FILE)
	@ar rcs $(STATIC_LIB) $(OBJ_FILE)

clean:
	@rm -rf *.o *.a

