CC = gcc
CFLAGS = -g -Wall -pedantic

test_connect4.c connect4.c main.c: connect4.h

CFILES = main.c connect4.c
OFILES = ${CFILES:.c=.o}

connect4: ${OFILES}
	$(CC) $(CFLAGS) -o connect4 ${OFILES}

test_connect4: test_connect4.o connect4.o
	$(CC) $(CFLAGS) -o test_connect4 test_connect4.o connect4.o

clean:
	rm -r connect4 test_connect4 *.o
