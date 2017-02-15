CC=gcc
CFLAGS=-Wall -pedantic

test.out: test.c item.o ../tester/tester.o
	$(CC) $(CFLAGS) -o test.out test.c ../support/item.o ../tester/tester.o
	./test.out

item.o: item.h item.c
	$(CC) $(CFLAGS) -c item.c

.PHONY: clean
clean:
	rm -rf *.o *.out
