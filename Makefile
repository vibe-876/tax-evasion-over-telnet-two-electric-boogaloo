CC=gcc
CFLAGS=-O0 -g


teot2eb: $(wildcard *.c)
	$(CC) $(CFLAGS) -o $@ $^


## Add each bin file here.
clean::
	rm physics teot2eb
