CC = gcc
CFLAGS = -Wall -g

all: quicksort

quicksort: main.o quicksort.o t_stack.o
	$(CC) $(CFLAGS) -o quicksort main.o quicksort.o t_stack.o

main.o: main.c quicksort.h t_stack.h
	$(CC) $(CFLAGS) -c main.c

quicksort.o: quicksort.c quicksort.h t_stack.h
	$(CC) $(CFLAGS) -c quicksort.c

t_stack.o: t_stack.c t_stack.h
	$(CC) $(CFLAGS) -c t_stack.c

clean:
	rm -f *.o quicksort