#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNumber;
    char name[50];
    char department[50];
    char course[50];
    int yearOfJoining;
} Student;

// Function prototypes
void printStudentsByYear(Student students[], int n, int year);
void printStudentByRollNumber(Student students[], int n, int rollNumber);

int main(void) {
    Student students[MAX_STUDENTS];
    int n = 0; // Number of students

    // Sample data input for demonstration purposes
    students[n++] = (Student){1, "Alice", "CS", "B.Tech", 2022};
    students[n++] = (Student){2, "Bob", "EE", "B.Tech", 2021};
    students[n++] = (Student){3, "Charlie", "ME", "B.Tech", 2022};
    students[n++] = (Student){4, "David", "CS", "B.Tech", 2020};

    int year, rollNumber;

    // Example usage: Print students who joined in a particular year
    printf("Enter the year of joining to search for students: ");
    scanf("%d", &year);
    printStudentsByYear(students, n, year);

    // Example usage: Print student data by roll number
    printf("\nEnter the roll number to search for student data: ");
    scanf("%d", &rollNumber);
    printStudentByRollNumber(students, n, rollNumber);

    return 0;
}

void printStudentsByYear(Student students[], int n, int year) {
    printf("\nStudents who joined in %d:\n", year);
    for (int i = 0; i < n; i++) {
        if (students[i].yearOfJoining == year) {
            printf("%s\n", students[i].name);
        }
    }
}

void printStudentByRollNumber(Student students[], int n, int rollNumber) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent data for roll number %d:\n", rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].yearOfJoining);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
}
