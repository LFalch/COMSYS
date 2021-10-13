CC=clang
CFLAGS=-std=c11 -Wall -Wextra -pedantic -g -pthread
.PHONY: all clean

all: hello

%.o: %.c
	$(CC) $(CFLAGS) -c $^

hello: hello.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o hello
