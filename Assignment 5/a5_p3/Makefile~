CC = gcc
CFLAG = -Wall 

all: use_teststack
	./use_teststack

use_teststack: stack.o convertingstack.o
	$(CC) $(CFLAG) -o use_teststack stack.o convertingstack.o

stack.o: stack.h stack.c
	$(CC) -c stack.c
teststack.o: stack.h convertingstack.c
	$(CC) -c convertingstack.c

clean: 
	rm use_teststack *.o
