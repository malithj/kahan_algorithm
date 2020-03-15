CC=g++
CFLAGS="-std=c++11"
TARGET=kahan

kahan: test.o
	$(CC) test.cc -o kahan

.PHONY: clean

clean:
	rm -f test

