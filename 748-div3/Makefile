.PHONY:  all, clean, mrproper,a,b
CC = g++
CFLAGS = -g -Wall -std=c++11

all: a b

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

a: a.o
	$(CC) $(CFLAGS) -o $@ $+
	./a

b: b.o
	$(CC) $(CFLAGS) -o $@ $+
	./b

clean:
	rm -f *.o

check%: %
	diff test$</1.out test$</1.test.out

mrproper: clean
	rm -f a
	rm -f b
