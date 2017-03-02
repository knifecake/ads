CC=gcc
CFLAGS=-Wall -g -std=c99
LDFLAGS=-L./

test.out: test.c stack.o ../support/item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test.out test.c stack.o ../support/item.o ../tester/tester.o
	./test.out

stack.o: stack.h stack.c
	$(CC) $(CFLAGS) -c stack.c

.PHONY: clean
clean:
	rm -rf *.o test.out
