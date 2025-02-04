#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n);
void swap(int *a, int *b);

int main() {
    FILE *inputFile, *outputFile;
    int *arr;
    int num, count = 0, size = 10;

    // Open the input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    // Read numbers from the input file
    while (fscanf(inputFile, "%d", &num) == 1) {
        if (count == size) {
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int));
            if (arr == NULL) {
                printf("Error: Memory reallocation failed.\n");
                fclose(inputFile);
                return 1;
            }
        }
        arr[count++] = num;
    }

    fclose(inputFile);

    // Sort the array using bubble sort
    bubbleSort(arr, count);

    // Open the output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        free(arr);
        return 1;
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    fclose(outputFile);
    free(arr);

    printf("Numbers sorted and written to output.txt successfully.\n");
    return 0;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
