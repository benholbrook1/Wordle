CC = gcc
CFLAGS = -Wall -g -std=c11 -pedantic

all: wordle

wordle: wordle.o trie.o
	$(CC) $(CFLAGS) wordle.o trie.o -o wordle

wordle.o: wordle.c header.h
	$(CC) $(CFLAGS) -c wordle.c -o wordle.o

trie.o: trie.c header.h
	$(CC) $(CFLAGS) -c trie.c -o trie.o

clean:
	rm *.o wordle