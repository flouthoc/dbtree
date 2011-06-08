CC := gcc
CFLAGS := -g -Wall -Wextra -O2
SOURCE := dbtree.c test.c
BIN := test

all: $(SOURCE)
	$(CC) $(CFLAGS) -o $(BIN) $(SOURCE)
	@echo
	@ls -l $(BIN)

run: $(BIN)
	./$(BIN)

debug: $(BIN)
	valgrind -v $(BIN)

clean:
	@rm -f $(BIN) output.log
