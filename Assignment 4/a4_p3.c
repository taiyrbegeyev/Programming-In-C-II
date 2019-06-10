/*
JTSK-320112
a4_p3.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

// ascending order
int myCompare1(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// descending order
int myCompare2(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

// print Array
void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &n);

    //dynamically allocate array
    int *arr;
    arr = (int*) malloc(sizeof(int) * n);

    if (arr == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        //read n values from the output
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &arr[i]);
    }

    char command;
    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &command);

        switch (command)
        {
            case 'a':
                //ascending order
                qsort(arr, n, sizeof(arr[0]), myCompare1);
                break;
            case 'd':
                //descending order 
                qsort(arr, n, sizeof(arr[0]), myCompare2);
                break;
            case 'e':
                //deallocate and exit
                free(arr);
                exit(0);
                break;
            default:
                break;
        }
        printArr(arr, n);
    }

    free(arr);
    return 0;
}