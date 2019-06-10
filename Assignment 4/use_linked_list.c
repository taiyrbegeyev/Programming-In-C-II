/*
JTSK-320112
use_linked_list.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

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