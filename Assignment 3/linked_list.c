/*
JTSK-320112
linked_list.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

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

struct list* removeFront(struct list* myList) {
    if (myList == NULL) 
        return myList;

    struct list* temp;
    temp = myList;
    myList = myList -> next;
    free(temp);
    return myList;
}

void printStruct(struct list* myList) {
    struct list* p;
    for (p = myList; p; p = p->next) {
        printf("%d ", p->info);
    }
    printf("\n");
}

void freeStructure(struct list* myList) {
    struct list* nextelem;
    while(myList != NULL) {
        nextelem = myList->next;
        free(myList);
        myList = nextelem;
    }
}