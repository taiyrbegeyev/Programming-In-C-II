/*
JTSK-320112
a2_p4.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void readMatrices(int*** arr, int rows, int columns, int depth) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            for (k = 0; k < depth; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
}

void printMatrices(int*** arr, int rows, int columns, int depth) {
    int i, j, k;
    for (i = 0; i < depth; i++) {
        printf("Section %d:\n", i + 1);
        for (j = 0; j < rows; j++) {
            for (k = 0; k < columns; k++) {
                printf("%d ",arr[j][k][i]);
            }
            printf("\n");
        }
    }
}

int main() {
    //our axes
    int rows, columns, depth;
    scanf("%d %d %d", &rows, &columns, &depth);

    //dynamically allocate memory for rows
    int*** massive = (int***) malloc(sizeof(int**) * rows);
    
    //check memory validality
    if (massive == NULL) {
        printf("Error occured. Problems with the allocation\n");
        exit(1);
    }

    //dynamically allocate memory for columns and depth
    //and check memory validality
    int i, j;
    for (i = 0; i < columns; i++) {
        massive[i] = (int**) malloc(sizeof(int*) * columns);
        if (massive[i] == NULL) {
            printf("Error occured. Problems with allocation matrices \n");
            exit(1);
        }
        for (j = 0; j < depth; j++) {
            massive[i][j] = (int*) malloc(sizeof(int) * depth);
            if (massive[i][j] == NULL) {
                printf("Error occured. Problems with allocation matrices \n");
                exit(1);
            }
        }
    }

    //read matrix from the output 
    // and 2D-sections of the 3D-array which are parallel to the “XOY axis”
    
    readMatrices(massive, rows, columns, depth);
    printMatrices(massive, rows, columns, depth);

    //deallocation
    for(i = 0; i < columns; i++) {
        for (j = 0; j < depth; j++) {
            free(massive[i][j]);
        }
    }

    for (i = 0; i < columns; i++) {
        free(massive[i]);
    }

    free(massive);

    return 0;
}