CC=gcc
CFLAGS=-c -Wall -Wextra
OBJ=main.o run_length_encoding.o file_handling.o
TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $(TARGET)

run_length_encoding.o: run_length_encoding.c
	$(CC) $(CFLAGS) $^

file_handling.o: file_handling.c
	$(CC) $(CFLAGS) $^

main.o: main.c
	$(CC) $(CFLAGS) $^

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)