CC=gcc
CC_FLAGS=-std=gnu99 -Wall -Wextra -Werror -pedantic

SOURCES = main.c

TARGET = proj2

all: $(SOURCES)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(TARGET)

run: all $(TARGET)
	./$(TARGET)