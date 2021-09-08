CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all

all: mynameis repeatme noAs dice niels

mynameis: mynameis.c
	$(CC) -o $@ $^ $(CFLAGS)

repeatme: repeatme.c
	$(CC) -o $@ $^ $(CFLAGS)

noAs: noAs.c
	$(CC) -o $@ $^ $(CFLAGS)

dice: dice.c
	$(CC) -o $@ $^ $(CFLAGS)

niels: niels.c
	$(CC) -o $@ $^ $(CFLAGS)
