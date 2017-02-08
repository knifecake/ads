CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-L./

test.out: test.c set.o ../support/item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test.out test.c set.o ../support/item.o ../tester/tester.o
	./test.out

set.o: set.h set.c
	$(CC) $(CFLAGS) -c set.c

.PHONY: clean
clean:
	rm -rf *.o test.out
