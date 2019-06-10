/*
JTSK-320112
a1_p6.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>

int main() {
    unsigned char ch;
    //input a character
    scanf("%c", &ch);

    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: ");

    //start from the left-most side and go to right
    for(int i = 7; i >= 0; i--) {
        if ((ch >> i) & 1) 
            printf("1");
        else
            printf("0");
    }
    
    printf("\n");

    return 0;
}