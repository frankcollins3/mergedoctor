#include <stdio.h>

int doctor() {
//     FILE *fp;
//     char data[50];

//     fp = fopen("localfile.txt", "r"); // open local file for reading
//     if (fp == NULL) { // check if file was successfully opened
//         printf("Error: file not found.\n");
//         return 1;
//     }

//     fgets(data, 50, fp); // read data from file into buffer
//     printf("The data from the file is: %s\n", data);
    
//     fclose(fp); // close file
    
    #include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2, *fp3;
    char ch;
    
    fp1 = fopen("patrickbetdavid1.md", "r"); // open first file for reading
    if (fp1 == NULL) {
        printf("Error: unable to open file patrickbetdavid1.md.\n");
        return 1;
    }
    
    fp2 = fopen("patrickbetdavid2.md", "r"); // open second file for reading
    if (fp2 == NULL) {
        printf("Error: unable to open file patrickbetdavid2.md.\n");
        return 1;
    }
    
    fp3 = fopen("merged_patrickbetdavid.md", "w"); // open new file for writing
    if (fp3 == NULL) {
        printf("Error: unable to create file merged_patrickbetdavid.md.\n");
        return 1;
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
    if (remove("patrickbetdavid1.md") == 0 && remove("patrickbetdavid2.md") == 0) {
        printf("Files merged successfully and originals deleted.\n");
    } else {
        printf("Error: unable to delete original files.\n");
    }
    
    return 0;
}


    return 0;
}
