#include <stdio.h>

void printStudentDetails(unsigned char value);

int main(void)
{
    unsigned char studentInfo;

    printf("Enter an 8-bit unsigned character value: ");
    scanf("%hhu", &studentInfo);

    printStudentDetails(studentInfo);

    return 0;
}

void printStudentDetails(unsigned char value)
{
    // Extract gender (bit 7)
    unsigned char gender = (value & 0x80) >> 7;

    // Extract year of study (bits 6 and 5)
    unsigned char yearOfStudy = (value & 0x60) >> 5;

    // Extract age (bits 4 to 0)
    unsigned char age = value & 0x1F;

    // Print the details
    printf("Gender: %s\n", (gender == 1) ? "Male" : "Female");
    printf("Year of Study: %d\n", yearOfStudy);
    printf("Age: %d\n", age);
}
