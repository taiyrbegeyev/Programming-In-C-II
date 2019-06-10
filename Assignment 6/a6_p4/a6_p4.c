/*
JTSK-320112
a6_p4.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

/**
 * @file a6_p4.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct usersfile {
    char *login;
    int pos;
} UsersFile;

int main() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';

    FILE *fp;
    fp = fopen(buffer, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // don't read the whole information from the file for every request,
    // but only store partial information
    // retrieve all usernames from the file
    UsersFile fileUsers[255];
    char line[255]; 
    int counter = 0;
    fileUsers[0].pos = 0;

    while(1) {
        fscanf(fp, "%s\n", line);
        fileUsers[counter].login = (char*) malloc(sizeof(char) * strlen(line));
        strcpy(fileUsers[counter].login, line);
        fileUsers[counter].pos += strlen(line) + 1;

        fscanf(fp, "%s\n", line);
        fileUsers[counter + 1].pos = fileUsers[counter].pos + strlen(line) + 1;
        counter++;

        if(feof(fp))
            break;
    }

    while(1) {
        char username[255];
        fgets(username, sizeof(username), stdin);
        username[strlen(username) - 1] = '\0';

        if(strcmp(username, "exit") == 0) {
            break;
        }
        else {
            char password[255];
            fgets(password, sizeof(password), stdin);
            password[strlen(password) - 1] = '\0';

            int dummy = 0;
            for(int i = 0; i < counter; i++){
                if(strcmp(fileUsers[i].login, username) == 0){
                    dummy = fileUsers[i].pos;
                    break;
                }
            }

            fseek(fp, dummy, SEEK_SET);
            char checkPassword[255];
            fscanf(fp, "%s\n", checkPassword);

            if(strcmp(checkPassword, password) == 0){
                printf("Access to user %s is granted.\n", username);
            } 
            else {
                printf("Access to user %s is denied.\n", username);
            }   
        }
    }
    
    printf("Exiting ...\n");
    for(int i = 0; i < counter; i++){
        free(fileUsers[i].login);
    }
    fclose(fp);

    return 0;
}
