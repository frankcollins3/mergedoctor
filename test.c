#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#define MAX_USER_LENGTH 20

int main () {

    FILE  *fp1, *fp2, *fp3;
    char ch;

    char user[MAX_USER_LENGTH];
    char file1[260];
    char file2[260];
    char filepath_1[100] = "/Users";
    char filepath_2[100];
    char userpath[100] = "/Users/";
    char desktop_path[100] = "";
    char desktop_path_2[100] = "";
    char prefilepath[100];

    printf("Please enter your username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("My PC/Mac username is: %s\n", user);

    printf("Please enter the name of the first file you'd like to open and merge: ");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';

    strcat(userpath, user);
    strcat(userpath, "/Desktop/");
    printf("userpath:\t %s \n", userpath);

    strcat(desktop_path, "/");
    strcat(desktop_path, userpath);
    printf("desktop_path:\t %s \n", desktop_path);

    strcat(userpath, file1);

    printf("heres my filepath:\t %s \n", userpath);

    fp1 = fopen(userpath, "r");
    if (fp1 == NULL) {
        printf("Error: unable to open file %s.\n", file1);
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);        
    }

    printf("\n"); printf("\n");

    printf("Enter file2 with its file extension into input: ");
    fgets(file2, sizeof(file2), stdin);    
    strcat(filepath_2, desktop_path);
    strcat(filepath_2, file2);

    printf("my filepath2:\t %s\n", filepath_2);

    fp2 = fopen(filepath_2, "r");
    if (fp2 == NULL) {
        printf("Error: unable to open file %s.\n", file2);
        return 1;
    }
    
    while ((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);        
    }

    return 0;
}
