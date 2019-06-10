CC = gcc
CFLAG = -Wall 

all: use_teststack
	./use_teststack

use_teststack: stack.o wordstack.o
	$(CC) $(CFLAG) -o use_teststack stack.o wordstack.o

stack.o: stack.h stack.c
	$(CC) -c stack.c
teststack.o: stack.h wordsstack.c
	$(CC) -c wordstack.c

clean: 
	rm use_teststack *.o
