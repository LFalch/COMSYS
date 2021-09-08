CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all

all: fileexist fileecho noAshere filecopy caesar

fileexist: fileexist.c
	$(CC) -o $@ $^ $(CFLAGS)

fileecho: fileecho.c
	$(CC) -o $@ $^ $(CFLAGS)

noAshere: noAshere.c
	$(CC) -o $@ $^ $(CFLAGS)

filecopy: filecopy.c
	$(CC) -o $@ $^ $(CFLAGS)

caesar: caesar.c
	$(CC) -o $@ $^ $(CFLAGS)
