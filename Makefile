CC=gcc
CFLAGS=-Wall -Wextra -ansi -O2
SOURCE=dbtree.c test.c
BIN=test

all: $(SOURCE)
	$(CC) $(CFLAGS) -o $(BIN) $(SOURCE)
	@echo
	@ls -l $(BIN)

run: $(BIN)
	./$(BIN)

clean: $(BIN)
	@rm -f $(BIN)
