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

memcheck: $(BIN)
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./$(BIN)

debug: $(BIN)
	gdb $(BIN)

clean:
	-@rm -f $(BIN) output.log
