CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all

all: int2ascii ascii2int hello table capitalise array

int2ascii: int2ascii.c
	$(CC) -o $@ $^ $(CFLAGS)

ascii2int: ascii2int.c
	$(CC) -o $@ $^ $(CFLAGS)

hello: hello.c
	$(CC) -o $@ $^ $(CFLAGS)

table: table.c
	$(CC) -o $@ $^ $(CFLAGS)

capitalise: capitalise.c
	$(CC) -o $@ $^ $(CFLAGS)

array: array.c
	$(CC) -o $@ $^ $(CFLAGS)
