CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJFILES = t_queue.o main.o
TARGET = banco

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

queue.o: t_queue.c t_queue.h
	$(CC) $(CFLAGS) -c t_queue.c

main.o: main.c t_queue.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJFILES) $(TARGET)