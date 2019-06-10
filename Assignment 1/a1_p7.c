/*
JTSK-320112
a1_p7.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>

//prototype declaration
char set3bits(unsigned char, int, int, int);

int main() {
    unsigned char ch;
    int bit1, bit2, bit3;
    scanf("%c %d %d %d", &ch, &bit1, &bit2, &bit3);

    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: ");

    //:before
    //print the binary representation 
    //start from the left-most side and go to right
    for(int i = 7; i >= 0; i--) {
        if ((ch >> i) & 1) 
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    //call the function
    ch = set3bits(ch, bit1, bit2, bit3);

    //:after
    printf("After setting the bits: ");      

    for(int i = 7; i >= 0; i--) {
        if ((ch >> i) & 1) 
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}

/*
    @brief  sets particular bits to 1
    @param character
    @param bit1
    @param bit2
    @param bit2
    @returns modified character
*/

char set3bits(unsigned char character, int bit1, int bit2, int bit3) {
    character |= (1 << (bit1));
    character |= (1 << (bit2));
    character |= (1 << (bit3));
    return character;
}