/*
JTSK-320112
a1_p3.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#define MAX(a, b, c) (a >= b && a >= c ? a : b >= a && b >= c ? b : c)  
#define MIN(a, b, c) (a <= b && a <= c ? a : b <= a && b <= c ? b : c)
#define MID_RANGE(a, b, c) ((MAX(a, b, c) + MIN(a, b, c)) / 2.0)

int main () {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    float mid = MID_RANGE(a, b, c); //finding mid_range of three numbers
    printf("The mid-range is: %0.6f\n", mid); //precision of 6

    return 0;
}