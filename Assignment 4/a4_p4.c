/*
JTSK-320112
a4_p4.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[30];
    int age;
};

//prototype declaration
int compareName(const void* a, const void* b);
int compareAge(const void* a, const void* b);
void bubbleSort(void *arr, int length, int size, int (*func)(const void *, const void *));
void printStructure(struct person* arr, int length);
void swap(void* xp, void* yp, void* temp, int size);

int main() {
    char buffer[100];
    int NumberOfPersons;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &NumberOfPersons);

    struct person* myList = (struct person*) malloc(sizeof(struct person) * NumberOfPersons);
    if (myList == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    
    for(int i = 0; i < NumberOfPersons; i++) {
        // fill the array of structures with name and age
        fgets(myList[i].name, sizeof(myList[i].name), stdin);
        myList[i].name[strlen(myList[i].name) - 1] = '\0'; //get rid of \n at the last position
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &(myList[i].age));
    }

    // print an array in ascending order by name
    bubbleSort(myList, NumberOfPersons, sizeof(myList[0]),compareName);
    printStructure(myList, NumberOfPersons);
    //print an array in ascending order by age
    bubbleSort(myList, NumberOfPersons, sizeof(myList[0]),compareAge);
    printStructure(myList, NumberOfPersons);

    //deallocation
    free(myList);
    return 0;
}

/*
    @brief implementation of bubble sort
    @param void* arr - a pointer to something
    @param length - length of the structure
    @param size
    @param function pointer (either compareName or compareAge)
*/
void bubbleSort(void *arr, int length, int size, int (*func)(const void *, const void *)) {
    // base case
    if (length < 1)
        return;
    
    // for swapping 
    void* temp = (void*) malloc(size);
    int swapped = 1;
    while(swapped) {
        swapped = 0;
        // swap two adjacent elements if the condition holds
        for (int i = 1; i < length; i++) {
            if (func(arr + (i - 1) * size, arr + i * size) > 0) {
                swap(arr + (i - 1) * size, arr + i * size, temp, size);
                swapped = 1;
            }
        }
    }
    free(temp);
}

/*
    compare names
*/
int compareName(const void* a, const void* b) {
    // cast
    const struct person* x = (const struct person*) a;
    const struct person* y = (const struct person*) b;
    int compare_name = strcmp(x->name, y->name); //comparing two names
   
    if (compare_name < 0)
        return -1;
    else if(compare_name == 0)
        return 0;
    else 
        return 1;
}

/*
    compare ages
*/

int compareAge(const void* a, const void* b) {
    // cast
    const struct person* x = (const struct person*) a;
    const struct person* y = (const struct person*) b;

    // if ages equal
    if (x->age == y->age) 
        return strcmp(x->name, y->name);
    else if (x->age < y->age)
        return -1;
    else 
        return 1;
}

/*
    @brief print the Structure
*/
void printStructure(struct person* structure, int length) {
    for (int i = 0; i < length; i++) {
        printf("{%s, %d}; ", structure[i].name, structure[i].age);
    }
    printf("\n");
}

/*
    swap two elements
*/
void swap(void* xp, void* yp, void* temp, int size) {
    memcpy(temp, xp, size);
    memcpy(xp, yp, size);
    memcpy(yp, temp, size);
}
