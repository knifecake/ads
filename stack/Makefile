CC=gcc
CFLAGS=-Wall
LDFLAGS=-L./

test: test.c stack.o ../support/item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test test.c stack.o item.o ../tester/tester.o
	./test

stack.o: stack.h stack.c
	$(CC) $(CFLAGS) -c stack.c

.PHONY: clean
clean:
	rm -rf *.o main
