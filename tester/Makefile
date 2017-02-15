CC=gcc
CFLAGS=-Wall
LDFLAGS=-L./

test.out: tester.o
	$(CC) $(CFLAGS) -o test.out test.c tester.o

tester.o: tester.h tester.c
	$(CC) $(CFLAGS) -c tester.c

.PHONY: clean
clean:
	rm -rf *.out *.o
