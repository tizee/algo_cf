.PHONY: all, clean, mrproper
CC = clang++
CFLAGS = -g -Wall -std=gnu++17

all: a b

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

a: a.o
	$(CC) $(CFLAGS) -o $@ $+
	./a

b: b.o
	$(CC) $(CFLAGS) -o $@ $+
	./b

c: c.o
	$(CC) $(CFLAGS) -o $@ $+
	./c

d1: d1.o
	$(CC) $(CFLAGS) -o $@ $+
	./d1

e: e.o
	$(CC) $(CFLAGS) -o $@ $+
	./e

f: f.o
	$(CC) $(CFLAGS) -o $@ $+
	./f

clean:
	rm -f *.o

check%: %
	diff test$</1.out test$</1.test.out

mrproper: clean
	rm -f a
	rm -f b
