CC=gcc
CFLAGS=-Wall -pedantic

test: test.c item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test test.c item.o ../tester/tester.o
	./test

item.o: item.h item.c
	$(CC) $(CFLAGS) -c item.c

.PHONY: clean
clean:
	rm -rf *.o
