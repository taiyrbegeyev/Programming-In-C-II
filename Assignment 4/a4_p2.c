/*
JTSK-320112
a4_p2.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Macros
/*#define IS_LOWER(x) (((x) >= 'a') && ((x) <= 'z')) 
#define TO_UPPER(x) (IS_LOWER(x) ? (x) - 'a' + 'A' : x)
#define IS_UPPER(x) (((x) >= 'A') && ((x) <= 'Z'))
#define TO_LOWER(x) (IS_UPPER(x) ? (x) - 'A' + 'a' : x)*/

//All uppercases
char* AllUpperCases(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
    return str;
}

//All lowercases
char* AllLowerCases(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
    return str;
}

// lowercase -> uppercase
// uppercase -> lowercase
char* ReverseCases(char* str) {
    for (int i = 0; str[i]; i++) {
        if(islower(str[i]))
            str[i] = toupper(str[i]);
        else if(isupper(str[i]))
            str[i] = tolower(str[i]);
    }
    return str;
}

// quit
char* quit() {exit(0);}

char* (*Case[4])(char* myStr) = {AllUpperCases, AllLowerCases, ReverseCases, quit};

int main() {
    char str[100], buffer[100], newStr[100];
    int command;
    fgets(str, sizeof(str), stdin);
    strcpy(newStr, str);

    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &command);

        strcpy(newStr, str);
        printf("%s", (*Case[command - 1])(newStr));
    }

    return 0;
}