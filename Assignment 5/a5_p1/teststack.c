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

    char buffer[100], ch;

    static int value, dummy;

    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &ch);
        switch(ch) {
            case 'q':
                printf("Quit\n");
                exit(0);
            case 's':
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &value);

                if (myStack.count >= MAX_NUM) {
                    printf("Pushing Stack Overflow\n");
                    break;
                } 
                
                printf("Pushing %d\n", value);
                push(&myStack, value);
                break;
            case 'p': 
                printf("Popping ");

                //base case
                if (myStack.count == 0) {
                    printf("Stack Underflow\n");
                    break;
                }

                dummy = pop(&myStack);
                printf("%d\n", dummy);
                break;
            case 'e':
                printf("Emptying Stack ");
                empty(&myStack);
                break;
        }
    }
    return 0;
}