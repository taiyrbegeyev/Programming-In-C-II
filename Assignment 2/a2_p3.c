/*
JTSK-320112
a2_p3.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void readMatrices(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrices(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void multiplicateMatrices(int** arr1, int** arr2, int** arr3, int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            arr3[i][j] = 0;
            for(int k = 0; k < m; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j]; 
            }
        }
    }
}

int main () {
    // n*m and m*p matrices
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    //dynamically allocate memory for rows
    int** matrix1 = (int**) malloc(sizeof(int*) * n); //n * m matrix
    int** matrix2 = (int**) malloc(sizeof(int*) * m); //m * p matrix
    int** resultMatrix = (int**) malloc(sizeof(int*) * n); //n * p matrix

    //check memory validality
    if (matrix1 == NULL) {
        printf("Error occured. Problems with allocation matrices \n");
        exit(1);
    }

    if (matrix2 == NULL) {
        printf("Error occured. Problems with allocation matrices \n");
        exit(1);
    }

    if (resultMatrix == NULL) {
        printf("Error occured. Problems with allocation matrices \n");
        exit(1);
    }

    //dynamically allocate memory for columns
    int i;
    for(i = 0; i < n; i++) {
        matrix1[i] = (int*) malloc(sizeof(int) * m);
        if (matrix1[i] == NULL) {
            printf("Error occured. Problems with allocation matrices \n");
            exit(1);
        }
    }

    for (i = 0; i < m; i++) {
        matrix2[i] = (int*) malloc(sizeof(int) * p);
        if (matrix2[i] == NULL) {
            printf("Error occured. Problems with allocation matrices \n");
            exit(1);
        }
    }

    for (i = 0; i < n; i++) {
        resultMatrix[i] = (int*) malloc(sizeof(int) * p);
        if (resultMatrix[i] == NULL) {
            printf("Error occured. Problems with allocation matrices \n");
            exit(1);
        }
    }

    //read matrix from the output
    readMatrices(matrix1, n, m);   
    readMatrices(matrix2, m, p);

    //print matrix
    printf("Matrix A:\n");
    printMatrices(matrix1, n, m);
    printf("Matrix B:\n");
    printMatrices(matrix2, m, p);

    //print and calculate the result of the multiplication of two matrices
    printf("The multiplication result AxB:\n");
    multiplicateMatrices(matrix1, matrix2, resultMatrix, n, m, p);
    printMatrices(resultMatrix, n, p);

    //deallocation
    for (i = 0; i < n; i++)
        free(matrix1[i]);
    free(matrix1);

    for (i = 0; i < m; i++)
        free(matrix2[i]);
    free(matrix2);

    for(i = 0; i < n; i++)
        free(resultMatrix[i]);
    free(resultMatrix);

    return 0;
}