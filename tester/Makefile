CC=gcc
CFLAGS=-Wall
LDFLAGS=-L./

test: tester.o
	$(CC) $(CFLAGS) -o test test.c tester.o

tester.o: tester.h tester.c
	$(CC) $(CFLAGS) -c tester.c

.PHONY: clean
clean:
	rm -rf test *.o
