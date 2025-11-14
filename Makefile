CC=gcc
CFLAGS=-O0 -g


teot2eb: $(wildcard *.c) $(wildcard *.h)
	$(CC) $(CFLAGS) -o $@ $(wildcard *.c)


## Add each bin file here.
clean::
	rm teot2eb
