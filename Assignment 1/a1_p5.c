/*
JTSK-320112
a1_p5.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>

int main () {
    unsigned char ch;
    scanf("%c", &ch);

    printf("The decimal representation is: %d\n", ch);
    printf("The backwards binary representation is: ");

    while (ch > 0) {
        if (ch & 1)
            printf("1");
        else
            printf("0");
        ch >>= 1;
    }
    printf("\n");
    return 0;
}