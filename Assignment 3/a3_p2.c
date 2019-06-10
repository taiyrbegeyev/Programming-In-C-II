/*
JTSK-320112
a3_p2.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

//Structure with one parent and one child
struct list {
    int info;
    struct list *next;
};

//add the value to the end of our linked list
struct list* pushBack(struct list* myList, int value) {
    struct list *newel, *cursor;
    cursor = myList;
    newel = (struct list*) malloc(sizeof(struct list));

    if(newel == NULL) {
        printf("Error allocating memory\n");
        return myList;
    }

    newel->info = value;
    newel->next = NULL;

    if(myList == NULL) 
        return newel;

    while(cursor->next != NULL) 
        cursor = cursor->next;
    cursor->next = newel;

    return myList; 
}

//add the value to the beginning of our linked list
struct list* pushFront(struct list* myList, int value) {
    struct list* newel;
    newel = (struct list*) malloc(sizeof(struct list));

    if(newel == NULL) {
        printf("Error allocating memory\n");
        return myList;
    }

    newel->info = value;
    newel->next = myList;
    return newel;
}

//remove a first element from the linked list
struct list* removeFront(struct list* myList) {
    if (myList == NULL) 
        return myList;

    struct list* temp;
    temp = myList;
    myList = myList -> next;
    free(temp);
    return myList;
}

//print structure
void printStruct(struct list* myList) {
    struct list* p;
    for (p = myList; p; p = p->next) {
        printf("%d ", p->info);
    }
    printf("\n");
}

//dispose structure
void freeStructure(struct list* myList) {
    struct list* nextelem;
    while(myList != NULL) {
        nextelem = myList->next;
        free(myList);
        myList = nextelem;
    }
}

// insert element at a certain position
// use cursor3 to find out the length of the linked list
// use cursor2 to walk through linked list until we reach the list, which  
// is after the index (position) we entered. Then tie newel and the rest of the list
// use cursor1 to walk through linked list until we reach the list, which  
// is before the index (position) we entered. Then tie it with already tied newel

struct list* insertElement(struct list* myList, int position, int number) {
    struct list* cursor1, *cursor2, *cursor3, *newel;
    cursor1 = myList;
    cursor2 = myList;

    int length = 0;
    for(cursor3 = myList; cursor3; cursor3 = cursor3->next) {
        length++;
    }
    // check if the position is negative or is greater that the length
    if (position < 0 || position > length) {
        printf("Invalid position!\n");
        return myList;
    }

    if (position == 0) {
        myList = pushFront(myList, number);
        return myList;
    }

    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL) {
        printf("Error allocating memory\n");
        return myList;
    }

    newel->info = number;
    newel->next = NULL;

    int counter = 0;

    while(counter != position) {
        cursor2 = cursor2->next;
        counter++;
    }
    newel->next = cursor2;

    counter = 0;
    while(counter != position - 1) {
        cursor1 = cursor1->next;
        counter++;
    }
    cursor1->next = newel;
    
    return myList;
}

// reverse the order of linked list
struct list* reverseList(struct list* myList) {
    struct list *prev, *current, *next;
    current = myList;
    prev = NULL;
    next = NULL;

    while(current != NULL) {
        //store next
        next = current->next;
        current->next = prev;
        //move pointers
        prev = current;
        current = next;
    }
    current = prev;
    return current;
}

int main() {
    int value, position;
    char command;
    struct list* myList = NULL;

    while(1) {
        scanf("%c", &command);
        switch (command)
        {
            case 'a':
                scanf("%d", &value);    
                myList = pushBack(myList, value);        
                break;
            case 'b':
                scanf("%d", &value);
                myList = pushFront(myList, value);
                break;
            case 'r':
                myList = removeFront(myList);
                break;
            case 'p':
                printStruct(myList);
                break;
            case 'q':
                freeStructure(myList);
                exit(0);
            case 'i':
                scanf("%d", &position);
                scanf("%d", &value);
                myList = insertElement(myList, position, value);
                break;
            case 'R':
                myList = reverseList(myList);
                break;
        }
        getchar();
    }

    return 0;
}