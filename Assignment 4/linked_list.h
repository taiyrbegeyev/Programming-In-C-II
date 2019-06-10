/*
JTSK-320112
linked_list.h
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

//Structure with one parent and one child
struct list {
    int info;
    struct list *next;
};

struct list* pushBack(struct list* myList, int value);
struct list* pushFront(struct list* myList, int value);
struct list* removeFront(struct list* myList);
void printStruct(struct list* myList);
void freeStructure(struct list* myList);