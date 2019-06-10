CC = gcc
CFLAG = -Wall 

all: use_queue
	./use_queue

use_queue: queue.o testqueue.o
	$(CC) $(CFLAG) -o use_queue queue.o testqueue.o

queue.o: queue.h queue.c
	$(CC) -c queue.c
teststack.o: stack.h testqueue.c
	$(CC) -c testqueue.c

clean: 
	rm use_queue *.o
