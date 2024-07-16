BIN = bin
SRC = src
TST = tests
INC = inc

CC = gcc
CFLAGS = -g -Wall -pedantic -I$(INC)

CSRCFILES = $(wildcard $(SRC)/*.c)
OSRCFILES = $(patsubst %,$(BIN)/%,$(notdir $(CSRCFILES:.c=.o)))
MAIN = $(BIN)/main.o
OSRCFILESNOMAIN = $(filter-out $(MAIN),$(OSRCFILES))

CTSTFILES = $(wildcard $(TST)/*.c)
OTSTFILES = $(patsubst %,$(BIN)/%,$(notdir $(CTSTFILES:.c=.o)))

$(BIN)/%.o: $(SRC)/%.c
	mkdir -p "$(BIN)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%.o: $(TST)/%.c
	mkdir -p "$(BIN)"
	$(CC) $(CFLAGS) -c $< -o $@

all: connect4

connect4: ${OSRCFILES}
	$(CC) $(CFLAGS) -o connect4 ${OSRCFILES}

tests: ${OTSTFILES} ${OSRCFILESNOMAIN}
	$(CC) $(CFLAGS) -o test_connect4 ${OTSTFILES} ${OSRCFILESNOMAIN}

tests/test_connect4.c src/connect4.c src/main.c: inc/connect4.h

clean:
	rm -r connect4 test_connect4 bin

help:
	@echo "src: ${CSRCFILES} | ${OSRCFILES} | ${OSRCFILESNOMAIN} | ${CTSTFILES} | ${OTSTFILES}"
