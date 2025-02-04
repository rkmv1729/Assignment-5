#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *sourceFile, *destinationFile;
    char ch;

    // Check if the correct number of arguments are passed
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    // Open the source file in read mode
    sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file %s\n", argv[1]);
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(argv[2], "w");
    if (destinationFile == NULL) {
        printf("Error: Could not open destination file %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
