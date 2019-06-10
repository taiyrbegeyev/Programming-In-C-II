/*
JTSK-320112
stack.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

void init(Stack *myStack){
    myStack->count = 0;
    for(int i = 0; i < MAX_LENGTH; i++){
        strcpy(myStack->items[i].word, "");
    }
}

void push(Stack *myStack, char *word){
    if(myStack->count == MAX_LENGTH){
        printf("Stack Overflow\n");
    }

    strcpy(myStack->items[myStack->count].word, word);
    myStack->count++;
}

char* top(Stack *myStack){
    char *ret = (char*) malloc(strlen(myStack->items[myStack->count - 1].word) * sizeof(char));
    strcpy(ret, myStack->items[myStack->count-1].word);
    return ret;
}

void pop(Stack *myStack){
    if(myStack->count == 0){
        printf("Stack Underflow\n");
    }

    strcpy(myStack->items[myStack->count - 1].word, "");
    myStack->count--;
}

int is_empty(Stack *myStack){
    return ((myStack->count) ? 0 : 1);
}
