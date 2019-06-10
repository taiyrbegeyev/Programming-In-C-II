/*
JTSK-320112
wordstack.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int main(){
    Stack stack;
    init(&stack);

    while(1){
        char str[(MAX_LENGTH + 1) * MAX_NUM + 2];
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';

        if(strcmp(str, "exit") == 0){
            exit(0);
        } 
        else {
            char help[MAX_LENGTH];
            strcpy(help, "");
            for(int i = 0; i < strlen(str); i++){
                if(str[i] == ' '){
                    push(&stack, help);
                    strcpy(help, "");
                } else {

                    char *ch = (char*)malloc(sizeof(str[i]));
                    *ch = str[i];
                    strcat(help, ch);
                    free(ch);

                    if(i == strlen(str)-1){
                        push(&stack, help);
                        strcpy(help, "");
                    }
                }
            }

            char newstr[(MAX_LENGTH + 1) * MAX_NUM + 2];
            strcpy(newstr, "");
            while(!is_empty(&stack)){
                strcat(newstr, top(&stack));
                strcat(newstr, " ");
                pop(&stack);
            }

            newstr[strlen(newstr) - 1] = '\0';
            if(strcmp(str, newstr) == 0){
                printf("The sentence is palindromic by words!\n");
            } else {
                printf("The sentence is not palindromic by words!\n");
            }
        }
    }

    return 0;
}
