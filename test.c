#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2, *fp3;
    char ch;

    // Open input files
    fp1 = fopen("/Users/medium/Desktop/patrickbetdavid1.txt", "r");
    if (fp1 == NULL) {
        printf("Error: unable to open input file patrickbetdavid1.txt.\n");
        return 1;
    }
    
    fp2 = fopen("/Users/medium/Desktop/patrickbetdavid2.txt", "r");
    if (fp2 == NULL) {
        printf("Error: unable to open input file patrickbetdavid2.txt.\n");
        fclose(fp1);
        return 1;
    }

    // Open output file for writing
    fp3 = fopen("/Users/medium/Desktop/merged_patrickbetdavid.txt", "w");
    if (fp3 == NULL) {
        printf("Error: unable to create output file merged_patrickbetdavid.txt.\n");
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    // DOCTOR DOCTOR!
    // Copy contents of first file to output file
    while ((ch = fgetc(fp1)) != EOF) {
        if (fputc(ch, fp3) == EOF) {
            printf("Error: failed to write to output file.\n");
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            return 1;
        }
    }

    // DOCTOR DOCTOR! Dont forget to patch 'em up!
    // Copy contents of second file to output file
    while ((ch = fgetc(fp2)) != EOF) {
        if (fputc(ch, fp3) == EOF) {
            printf("Error: failed to write to output file.\n");
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            return 1;
        }
    }

    // Close all files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
    printf("Files merged successfully.\n");
    return 0;
}