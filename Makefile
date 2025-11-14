CC=gcc
CFLAGS=-O0 -g


teot2eb: main.c main.h
	$(CC) $(CFLAGS) -o $@ $^
