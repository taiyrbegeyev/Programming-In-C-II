/*
JTSK-320112
a3_p3.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct doublyLinkedList {
    char info;
    struct doublyLinkedList *prev;
    struct doublyLinkedList *next;
};

//Prototype Declaration
struct doublyLinkedList *pushFront(struct doublyLinkedList* myList, char ch);
struct doublyLinkedList *removeAllElements(struct doublyLinkedList* myList, char ch);
void printDLL(struct doublyLinkedList* myList);
void printBackwards(struct doublyLinkedList* myList);
void disposeDLL(struct doublyLinkedList* myList);

int main() {
    struct doublyLinkedList* myList = NULL;
    char command, value;
    
    while(1) {
        scanf("%c", &command);
        getchar();
        switch(command) {
            //add the char to the beginning of the list 
            case '1':
                scanf("%c", &value);
                getchar();
                myList = pushFront(myList, value);
                break;
            //remove all of the char value in the list
            case '2':
                scanf("%c", &value);
                getchar();
                myList = removeAllElements(myList, value);
                break;
            //print the list
            case '3':
                printDLL(myList);
                break;
            //print the list backwards
            case '4':
                printBackwards(myList);
                // since we use recursive function we need to add a new line here
                printf("\n");
                break;
            //free and exit
            case '5':
                disposeDLL(myList);
                exit(0);
        }
    }

    return 0;
}

//1
//add the char to the beginning of the list 
struct doublyLinkedList *pushFront(struct doublyLinkedList* myList, char ch) {
    struct doublyLinkedList* el;
    el = (struct doublyLinkedList*) malloc(sizeof(struct doublyLinkedList));

    //chech for validality of the memory allocation
    if (el == NULL) {
        printf("Error allocating memory\n");
        return myList;
    }

    el->info = ch;   
    el->prev = NULL;
    el->next = myList;
    return el;
}

//2
//remove all of the char value in the list
struct doublyLinkedList* removeAllElements(struct doublyLinkedList *my_list, char info){
    struct doublyLinkedList* cursor;
	int count = 0;
	for (cursor = my_list; cursor != NULL; cursor = cursor->next) {
		struct doublyLinkedList* temp = cursor;

        //element is found
		if (cursor->info == info) {
			count = 1;
			if (cursor == my_list) {
				//element is in the head of the list
				my_list = cursor->next;
			}
			if (cursor->next != NULL) {
				//when the element is not at the last place
				cursor->next->prev = cursor->prev;
			}
			if (cursor->prev != NULL) {
				//when the element is not at the first place
				cursor->prev->next = cursor->next;
			}
		free(temp); //deallocation
	}
	}
	if (count == 0) {
		//if the element we are looking for is not in the list
		printf("The element is not in the list!\n");
	}
	return my_list;
}

//3
//print the list
void printDLL(struct doublyLinkedList* myList) {
    struct doublyLinkedList* cursor;
    for (cursor = myList; cursor; cursor = cursor->next)
        printf("%c ", cursor->info);
    printf("\n");
}

//4
//print the list backwards
void printBackwards(struct doublyLinkedList* myList) {
    if (myList == NULL) 
        return;
    else if (myList->next == NULL) {
        printf("%c ", myList->info);
    }
    else {
        /*while(cursor->next != NULL) 
            cursor = cursor->next;
        
        while(cursor != NULL) {
            printf("%c ", cursor->info);
            cursor = cursor->prev;
        }
        printf("\n");*/
        //use recursion
        printBackwards(myList->next);
        printf("%c ", myList->info);
    }
}

//5
//free and exit
void disposeDLL(struct doublyLinkedList* myList) {
    struct doublyLinkedList* nextel;
    while(myList != NULL) {
        nextel = myList->next;
        free(myList);
        myList = nextel;
    }
}