/*
JTSK-320112
a1_p1.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#define SWAP(A, B, TYPE) {TYPE temp = A; A = B; B = temp;}

int main() {
    int a1, b1;
    //it is double cause it doesn't work with float
    //we need to mo
    double a2, b2;

    //input 4 numbers
    //first two numbers are int, two last are floats
    scanf("%d", &a1);
    scanf("%ds", &b1);
    scanf("%lf", &a2);
    scanf("%lf", &b2);

    printf("After swapping:\n");
    //calling macro
    SWAP(a1, b1, int);
    SWAP(a2, b2, double);

    printf("%d\n", a1);
    printf("%d\n", b1);
    printf("%.6lf\n", a2);
    printf("%.6lf\n", b2);

    return 0;
}