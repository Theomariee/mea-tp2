CC = gcc
CFLAGS = -lm

all: main

main: main.o hash_table.o prime.o
	$(CC) $(CFLAGS) -o main main.o hash_table.o prime.o

main.o: main.c hash_table.o
	$(CC) $(CFLAGS) -o main.o -c main.c hash_table.o

hash_table.o: hash_table.c prime.o
	$(CC) $(CFLAGS) -o hash_table.o -c hash_table.c prime.o

prime.o: prime.c
	$(CC) $(CFLAGS) -o prime.o -c prime.c

clean:
	rm -rf *.o
