CC=gcc
CFLAGS=-O0 -g
SRCDIR=src


teot2eb: $(SRCDIR)/main.c $(SRCDIR)/main.h
	$(CC) $(CFLAGS) -o $@ $^
