CC=gcc
CC_FLAGS=-std=gnu99 -Wall -Wextra -Werror -Wno-deprecated -pedantic

SOURCES = main.c

TARGET = proj2
TARGET_ARGS = 3 5 100 100

all: $(SOURCES)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(TARGET)

run: all $(TARGET)
	./$(TARGET) $(TARGET_ARGS)
