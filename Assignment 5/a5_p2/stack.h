/*
JTSK-320112
stack.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#ifndef _STACK_H
#define _STACK_H
#define MAX_NUM 12

typedef struct stack {
    unsigned int count;
    int array[MAX_NUM];
}Stack;

/**
 * @brief adds the given value to the end of the stack
 * @param myStack - stack
 * @param value - the number to add the stack
*/
void push(Stack *myStack, int value);

/**
 * @brief delete the last element from the end of the stack
 * @param myStack - stack
*/
int pop(Stack *myStack);

/**
 * @brief empty the stacks
 * @param myStack - stack
*/
void empty(Stack *myStack);

/**
 * @brief check if the stack is empty
 * @param myStack - stack
*/

int isEmpty(Stack *myStack);

#endif
