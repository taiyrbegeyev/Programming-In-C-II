/*
JTSK-320112
a1_p3.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE

int main() {
    int i, n;
    int *x, *y;

    scanf("%d", &n);
    x = (int*) malloc(sizeof(int) * n);
    y = (int*) malloc(sizeof(int) * n);

    if (x == NULL) {
        printf("Problems with allocating. Exit ... \n");
        exit(1);
    }

    //inputing values for vector x
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    //inputing values for vector y
    for (i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    //calculating  scalar product
    int scalarProduct  = 0;
    for (i = 0; i < n; i++) {
        scalarProduct += x[i] * y[i];
    }

    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
        for (i = 0; i < n; i++) 
            printf("%d\n", x[i] * y[i]);
        printf("The scalar product is: %d\n", scalarProduct);
    #else
        printf("The scalar product is: %d\n", scalarProduct);
    #endif

    //deallocation
    free(x);
    free(y);
    return 0;
}