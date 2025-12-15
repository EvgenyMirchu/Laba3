CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = laba3

SOURCES = main.c struct.c container.c arguments.c gnome_sorting.c input-output.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = struct.h container.h arguments.h gnome_sorting.h input-output.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild