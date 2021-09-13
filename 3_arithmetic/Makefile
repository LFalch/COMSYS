CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all

all: hexabyte bitflip hexdump

hexabyte: hexabyte.c
	$(CC) -o $@ $^ $(CFLAGS)

bitflip: bitflip.c
	$(CC) -o $@ $^ $(CFLAGS)

hexdump: hexdump.c
	$(CC) -o $@ $^ $(CFLAGS)
