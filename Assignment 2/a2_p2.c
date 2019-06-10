/*
JTSK-320112
a2_p2.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    int lengthOfStr1 = strlen(str1);
    int lengthOfStr2 = strlen(str2); 

    //get rid of \n in the end
    str1[lengthOfStr1 - 1] = '\0';
    str2[lengthOfStr2 - 1] = '\0';

    //use the string.h to find the sum of lengths of two arrays 
    int length = strlen(str1) + strlen(str2);

    //dynamically allocate
    char* newArr;
    newArr = (char*) malloc(sizeof(char) * length);

    if(newArr == NULL) {
        printf("Error when dynamically allocating array\n");
        exit(1);
    } 

    //concatenate two strings and store in the first one
    strcat(str1, str2);

    strcpy(newArr, str1);
    printf("Result of concatenation: %s\n", newArr);

    //deallocate pointer
    free(newArr);

    return 0;
}