#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#define MAX_USER_LENGTH 20

char* get_file_path(char* user, char* file_name) {
    static char file_path[100];
    sprintf(file_path, "/Users/%s/Desktop/%s", user, file_name);
    return file_path;
}

int main () {

        FILE  *fp1, *fp2, *fp3;
    char ch;

    char user[MAX_USER_LENGTH];
    char file1[260] = " ";
    char file2[260] = " ";

    // char redo;

    printf("Please enter your username into the input: \n");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("Enter the first file name with file extension that will be used for opening, reading, and merging with file2 \n");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';
    

    char* file_path_1 = get_file_path(user, file1);
    printf("File path: %s\n", file_path_1);

        
    

    fp1 = fopen(file_path_1, "r");
    // fp1 = fopen("/Users/medium/Desktop/patrickbetdavid1.txt", "r");
    if (fp1 == NULL) {
        printf("Error: unable to open file %s.\n", file1);
        return 1;
    }

    printf("\033[2J\033[H"); // ANSI escape codes to clear screen

    while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);        
    }

    printf("\n \n");
    
    printf("enter the 2nd file path with file extension to merge with the data from the above. See the terminal to see the data. \n");
    fgets(file2, sizeof(file2), stdin);
    char* file_path_2 = get_file_path(user, file2);
    printf("file_path_2:\t %s \n", file_path_2);

    fp2 = fopen(file_path_2, "r");
    // fp2 = fopen("/Users/medium/Desktop/patrickbetdavid2.txt", "r");
    if (fp2 == NULL) {
        printf("Error: unable to open file patrickbetdavid2.txt.\n");
        return 1;
    }

        while ((ch = fgetc(fp2)) != EOF) {
                    printf("%c", ch);        
        }

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
