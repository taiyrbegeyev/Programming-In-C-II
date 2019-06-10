/*
JTSK-320112
a3_p1.c
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

int main() {
    int value;
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
        }
        getchar();
    }

    return 0;
}