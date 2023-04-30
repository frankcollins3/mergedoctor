#include <stdio.h>
#include <string.h>

    #define MAX_USER_LENGTH 20

int main () {

    FILE  *fp1, *fp2, *fp3;
    char ch;

    char user[MAX_USER_LENGTH];
    scanf(" %[^\n]s", user);
    
    fp1 = fopen("/Users/medium/Desktop/patrickbetdavid1.txt", "r");
    if (fp1 == NULL) {
        printf("Error: unable to open file patrickbetdavid1.txt.\n");
        return 1;
    }

        while ((ch = fgetc(fp1)) != EOF) {
                    printf("%c", ch);        
        }
    fp2 = fopen("/Users/medium/Desktop/patrickbetdavid2.txt", "r");
    if (fp2 == NULL) {
        printf("Error: unable to open file patrickbetdavid2.txt.\n");
        return 1;
    }
    
        while ((ch = fgetc(fp2)) != EOF) {
                    printf("%c", ch);        
        }

    fp3 = fopen("/Users/medium/Desktop/merged_patrickbetdavid.txt", "w"); // open new file for writing
    if (fp3 == NULL) {
        printf("Error: unable to create file merged_patrickbetdavid.md.\n");
        return 1;
    } else {
        remove("/Users/medium/Desktop/patrickbetdavid1.txt");
        remove("/Users/medium/Desktop/patrickbetdavid2.txt");
    }
    
    // copy contents of first file to new file
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);
    }
    
    // copy contents of second file to new file
    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);
    }
    
    // close all files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
    // delete original files
    // if (remove("patrickbetdavid1.md") == 0 && remove("patrickbetdavid2.md") == 0) {
    //     printf("Files merged successfully and originals deleted.\n");
    // } else {
    //     printf("Error: unable to delete original files.\n");
    // }

    return 0;
}
