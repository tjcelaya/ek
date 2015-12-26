CC=clang
CCFLAGS=-Wall -pedantic

all: build test

build: ek.c ek.grammar
	$(CC) $(CCFLAGS) mpc/mpc.c ek.c -o ek

test:
	./ek test.maths

.PHONY: clean
clean:
	rm ek