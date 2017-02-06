CC=gcc
CFLAGS=-Wall
LDFLAGS=-L./

test: test.c set.o ../support/item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test test.c set.o ../support/item.o ../tester/tester.o
	./test

set.o: set.h set.c
	$(CC) $(CFLAGS) -c set.c

.PHONY: clean
clean:
	rm -rf *.o main
