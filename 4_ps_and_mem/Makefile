CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all

all: int2ascii ascii2int

int2ascii: int2ascii.c
	$(CC) -o $@ $^ $(CFLAGS)

ascii2int: ascii2int.c
	$(CC) -o $@ $^ $(CFLAGS)
