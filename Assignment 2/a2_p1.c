/*
JTSK-320112
a2_p1.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    //number of elements
    int n;
    scanf("%d", &n);

    //dynamically allocate the array
    float* arr;
    arr = (float*) malloc(sizeof(float) * n);

    if(arr == NULL) {
        printf("Error when dynamically allocating array\n");
        exit(1);
    }

    //entering elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    //creating new pointer to go through array
    float *p = arr;
    for(;*p >= 0;p++) {
    }

    //the difference between addresses
    printf("Before the first negative value: %ld elements\n", p - arr);

    //reallocation
    free(arr);
    return 0;
}
