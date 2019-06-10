/*
JTSK-320112
a6_p5.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

/**
 * @file a6_p5.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    FILE *output;
    output = fopen("output.txt", "w+");
    if (!output) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    char *filenames[n];
    for(int i = 0; i < n; i++) {
        filenames[i] = (char*) malloc(sizeof(char) * 255);
        fgets(filenames[i], 255, stdin);
        filenames[i][strlen(filenames[i]) - 1] = '\0';
    }

    printf("Concating the content of %d files ...\nThe result is:\n", n);

    for(int i = 0; i < n; i++) {
        FILE *fptr;
        fptr = fopen(filenames[i], "r");
        if(fptr == NULL){
            fprintf(stderr, "Cannot open file!\n");
            exit(1); 
        }

        char *buffer;
        fseek(fptr, 0, SEEK_END);
        int file_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);
        buffer = (char*) malloc(sizeof(char)*(file_size + 1));

        fread(buffer, sizeof(char), file_size, fptr);
        fwrite(buffer, sizeof(char), file_size, output);
        printf("%s\n", buffer);

        fclose(fptr);
        strcpy(buffer, "\n");
        fwrite(buffer, sizeof(char), strlen(buffer), output);
        free(buffer);
    }

    fclose(output);
    return 0;
}