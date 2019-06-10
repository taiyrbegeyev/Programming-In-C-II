/*
JTSK-320112
stack.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(Stack *myStack, int value) {
    //base case
    if (myStack->count > 12) {
        printf("Stack Overflow\n");
        exit(1);
    }

    myStack->array[myStack->count++] = value;
}

int pop(Stack *myStack) {
    //base case
    if (myStack->count < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }

    myStack->count--;
    return myStack->array[myStack->count];
}

void empty(Stack *myStack) {
    int dummy = myStack->count;

    for(int i = 0; i < dummy; i++) {
        printf("%d ", pop(myStack));
    }

    printf("\n");
}

int isEmpty(Stack *myStack) {
    if (myStack->count > 0)
        return 0;
    else 
        return 1;
}