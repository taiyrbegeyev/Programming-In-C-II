/*
JTSK-320112
stack.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#define MAX_NUM 12
#define MAX_LENGTH 30

typedef struct item{
    char word[MAX_LENGTH];
} Item;

typedef struct stack{
    unsigned int count;
    Item items[MAX_LENGTH];
} Stack;

/**
 * @brief Initialize the Stack
*/
void init(Stack *myStack);

/**
 * @brief adds the given value to the end of the stack
 * @param myStack - stack
 * @param value - the number to add the stack
*/
void push(Stack *myStack, char *word);

/**
 *  @brief returns the last element added to the stack
*/
char* top(Stack *myStack);

/**
 * @brief delete the last element from the end of the stack
 * @param myStack - stack
*/

void pop(Stack *myStack);

/**
 * @brief check if the stack is empty
 * @param myStack - stack
*/
int is_empty(Stack *myStack);
