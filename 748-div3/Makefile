.PHONY:  all, clean, mrproper,a,b
CC = g++
CFLAGS = -g -Wall

all: a b

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

a: a.o
	$(CC) $(CFLAGS) -o $@ $+

b: b.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o

mrproper: clean
	rm -f a
