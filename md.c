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
    char filepath[100] = "/Users/";

    printf("Please enter your username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("My PC/Mac username is: %s\n", user);

    printf("Please enter the name of the first file you'd like to open and merge: ");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';

    strcat(filepath, user);
    strcat(filepath, "/Desktop/");
    strcat(filepath, file1);

    printf("My file path is: %s\n", filepath);

    fp1 = fopen(filepath, "r");
    if (fp1 == NULL) {
        printf("Error: unable to open file %s.\n", file1);
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);        
    }

    
    // fp2 = fopen("/Users/medium/Desktop/patrickbetdavid2.txt", "r");
    // if (fp2 == NULL) {
    //     printf("Error: unable to open file patrickbetdavid2.txt.\n");
    //     return 1;
    // }
    
    //     while ((ch = fgetc(fp2)) != EOF) {
    //                 printf("%c", ch);        
    //     }

    // fp3 = fopen("/Users/medium/Desktop/merged_patrickbetdavid.txt", "w"); // open new file for writing
    // if (fp3 == NULL) {
    //     printf("Error: unable to create file merged_patrickbetdavid.md.\n");
    //     return 1;
    // } else {
    //     remove("/Users/medium/Desktop/patrickbetdavid1.txt");
    //     remove("/Users/medium/Desktop/patrickbetdavid2.txt");
    // }
    
    // // copy contents of first file to new file
    // while ((ch = fgetc(fp1)) != EOF) {
    //     fputc(ch, fp3);
    // }
    
    // // copy contents of second file to new file
    // while ((ch = fgetc(fp2)) != EOF) {
    //     fputc(ch, fp3);
    // }
    
    // // close all files
    // fclose(fp1);
    // fclose(fp2);
    // fclose(fp3);
    


    return 0;
}
