CC=clang
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
.PHONY: all clean

all: mysystem_test segfault

%.o: %.c
	$(CC) $(CFLAGS) -c $^

mysystem_test: mysystem.o mysystem_test.o
	$(CC) $(CFLAGS) -o $@ $^

segfault: segfault.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o segfault mysystem_test
