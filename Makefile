CC = gcc
CFLAGS = -g -Wall -Wextra
INCLUDES = -Iinclude
SRCS = src/main.c src/player.c src/list.c src/game.c
TARGET = bin/main

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

test: all
	chmod +x tests/*.sh || true
	./tests/run_all_tests.sh

clean:
	rm -f $(TARGET) *.o
