/*
JTSK-320112
a1_p2.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
//using ternary operation
#define LEASTSIGNIFICANTBIT(CH) ((1) & (CH) ? (1) : (0)) 


int main() {
    unsigned char ch;
    scanf("%c", &ch);

    //printing decimal representation
    printf("The decimal representation is: %d\n", ch);
    //finding LSB
    printf("The least significant bit is: %d\n", LEASTSIGNIFICANTBIT(ch));

    return 0;
}