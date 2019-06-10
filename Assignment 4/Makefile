CC = g++
CFLAG = -Wall
OBJ = use_linked_list.o linked_list.o
all: use_linked_list
use_linked_list: $(OBJ) 
			   $(CC) $(CFLAG) -o use_linked_list $(OBJ)

linked_list.o: linked_list.c linked_list.h
use_linked_list.o: use_linked_list.c linked_list.h
clean: 
	 rm -f use_linked_list *.o