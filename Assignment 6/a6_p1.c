/*
JTSK-320112
a6_p1.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nameOfFile[100];
    fgets(nameOfFile, sizeof(nameOfFile), stdin);

    // get rid of \n in the end   
    nameOfFile[strlen(nameOfFile) - 1] = '\0';

    //read file with specific name
    FILE *input;
    input = fopen(nameOfFile, "r");
    if(input == NULL) {
        printf("The file is not found\n");
        exit(1);
    }

    char ch;
    int wordcount = 0;
    
    // go until the end of the file
    while ((ch = getc(input)) != EOF) {
        // if current character is one of these, increment wordcount
        if (ch == ' ' || ch == ',' || ch == '?' || ch == '!' ||
             ch == '.' || ch == '\r' || ch == '\t' || ch == '\n') {
                 
                 wordcount++;
                 ch = getc(input);

                // check following characters
                 while(ch == ' ' || ch == ',' || ch == '?' || ch == '!' ||
                    ch == '.' || ch == '\r' || ch == '\t' || ch == '\n') {
                        ch = getc(input);
                }
             }
    }

    printf("%d\n", wordcount);
    fclose(input);
    return 0;
}