CFLAGS=-Wall -Wextra -pedantic -g
CC=gcc


run: clean test_list
	./test_list

test_list: test_list.o list.o
	$(CC) test_list.o list.o -o test_list $(CFLAGS)

test_list.o: test_list.c list.h
	$(CC) -c test_list.c $(CFLAGS)

test.o: list.c list_array.c list.h
	$(CC) -c list.c $(CFLAGS)

clean:
	rm -rf test_list *.o
