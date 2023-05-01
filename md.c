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
    char file3[260] = " ";

    printf("Please enter your username into the input: \n");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("Enter the first file name with file extension that will be used for opening, reading, and merging with file2 \n");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';

    char* file_path_1 = get_file_path(user, file1);
    printf("File path: %s\n", file_path_1);

    fp1 = fopen(file_path_1, "r");
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
    file_path_2[strcspn(file_path_2, "\n")] = '\0';

    fp2 = fopen(file_path_2, "r");
    if (fp2 == NULL) {
        printf("Error: unable to open file %s.\n", file2);
        return 1;
    }

    printf("\033[2J\033[H"); // ANSI escape codes to clear screen

    while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);        
    }

    while ((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);        
    }

    printf("\n");

printf("We will create a new file with which to merge the data from file 1 & 2. Please write file name and extension .md or .txt \n");
    fgets(file3, sizeof(file3), stdin);
    char* file_path_3 = get_file_path(user, file3);
    file_path_3[strcspn(file_path_3, "\n")] = '\0';
    printf("file_path_3:\t %s \n", file_path_3);


    fp3 = fopen(file_path_3, "w"); // open new file for writing

    // fp3 = fopen("/Users/medium/Desktop/merged_patrickbetdavid.md", "w"); // open new file for writing
    if (fp3 == NULL) {
        printf("Error: unable to create file:\t %s \n", file_path_3);
        return 1;
    } 

    
    rewind(fp1); // move file pointer back to beginning of fp1
    rewind(fp2);
    // copy contents of first file to new
    
    // copy contents of first file to new file
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);
    }
    
    // copy contents of second file to new file
    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);
    }

    if (fp3 != NULL) {
        char delete_1;
        char delete_2;
        // printf("want to delete the original files? \n");
        // printf("enter 1 into the input to delete file_1 \t"); printf("enter 2 into the input to delete file_1 \n"); 
        // scanf("%[^\n]", &delete);
            printf("file1\t %s \n", file1);
            printf("!!! 2\t %s \n", file2);


        printf("press y to delete file number 1 or press any other key to ignore. \n");
            char* file_path_1_again = get_file_path(user, file1);
            file_path_1_again[strcspn(file_path_1_again, "\n")] = '\0';
            printf("file_path_1:\t %s \n", file_path_1_again);
            // fgets(&delete_1, sizeof(delete_1), stdin);
            scanf(" %[^\n]", &delete_1);
            printf("\n");
            if (delete_1 == 'y') {
                remove(file_path_1_again);
            }

        printf("press y to delete file number 2 or press any other key to ignore. \n");
            printf("\n");
            scanf(" %[^\n]", &delete_2);
            char* file_path_2_again = get_file_path(user, file2);
            file_path_2_again[strcspn(file_path_2_again, "\n")] = '\0';
            printf(" !!!! 2:\t %s \n", file_path_2_again);
            // fgets(&delete_2, sizeof(delete_2), stdin);
            if (delete_2 == 'y') {
                remove(file_path_2_again);
            }                
        }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("\n");
    printf("thanks for operating today!");
    


    return 0;
}
