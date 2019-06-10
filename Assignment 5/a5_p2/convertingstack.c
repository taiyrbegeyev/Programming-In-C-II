/*
JTSK-320112
teststack.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack myStack;
    myStack.count = 0;
    unsigned int inBin;
    scanf("%d", &inBin);

    int div = inBin;
    if (inBin == 0) {
        //base case
        push(&myStack, 0);
    }
    else {
        while(div > 0) {
            push(&myStack, div % 2);
            div /= 2;    
        }
    }

    printf("The binary representation of %d is ", inBin);
    while(!isEmpty(&myStack)) 
        printf("%d", pop(&myStack));
    printf(".\n");
    
    return 0;
}