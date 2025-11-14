CC=gcc
CFLAGS=-O0 -g


teot2eb: $(wildcard *.c)
	$(CC) $(CFLAGS) -o $@ $^
