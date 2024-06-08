CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o t_binary_tree.o
	$(CC) $(CFLAGS) -o main_program main.o t_binary_tree.o

main.o: main.c t_binary_tree.h
	$(CC) $(CFLAGS) -c -o main.o main.c

t_binary_tree.o: t_binary_tree.c t_binary_tree.h
	$(CC) $(CFLAGS) -c -o t_binary_tree.o t_binary_tree.c

clean:
	rm -f main_program main.o t_binary_tree.o
