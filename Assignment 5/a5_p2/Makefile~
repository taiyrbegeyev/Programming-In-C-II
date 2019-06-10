CC = gcc
CFLAG = -Wall 

all: use_teststack
	./use_teststack

use_teststack: stack.o teststack.o
	$(CC) $(CFLAG) -o use_teststack stack.o teststack.o

stack.o: stack.h stack.c
	$(CC) -c stack.c
teststack.o: stack.h teststack.c
	$(CC) -c teststack.c

clean: 
	rm use_teststack *.o