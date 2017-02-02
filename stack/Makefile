CC=gcc
CFLAGS=-Wall
LDFLAGS=-L./

test: stack.o item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test test.c stack.o item.o ../tester/tester.o
	./test

stack.o: stack.h stack.c
	$(CC) $(CFLAGS) -c stack.c

item.o: item.h item.c
	$(CC) $(CFLAGS) -c item.c

.PHONY: clean
clean:
	rm -rf *.o main
