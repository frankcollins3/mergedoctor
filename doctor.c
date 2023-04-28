#include <stdio.h>

int main() {
    FILE *fp;
    char data[50];

    fp = fopen("localfile.txt", "r"); // open local file for reading
    if (fp == NULL) { // check if file was successfully opened
        printf("Error: file not found.\n");
        return 1;
    }

    fgets(data, 50, fp); // read data from file into buffer
    printf("The data from the file is: %s\n", data);
    
    fclose(fp); // close file

    return 0;
}
