CC = gcc
CFLAGS = -Wall -Wextra

all: main clean

main: main.o stack.o
		$(CC) $(CFLAGS) -o main main.o stack.o

main.o: main.c stack.h
		$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
		$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
		rm -rf *.o