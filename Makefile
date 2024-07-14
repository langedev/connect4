CC = gcc
CFLAGS = -g -Wall -pedantic

connect4.c main.c: connect4.h

TARGET = connect4
CFILES = main.c connect4.c
OFILES = ${CFILES:.c=.o}

all: ${OFILES}
	$(CC) $(CFLAGS) -o ${TARGET} ${OFILES}

clean:
	rm -r ${TARGET} ${OFILES}
