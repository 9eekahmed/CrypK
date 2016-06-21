cc = gcc
all: encrypt.o main.o
	$(cc) encrypt.o main.o -o crypK
encrypt.o : encrypt.c
	$(cc) -c encrypt.c
main.o : main.c encrypt.h
	$(cc) -c main.c
clean:
	rm -f *.o crypK
