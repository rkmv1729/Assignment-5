#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 10
#define NUM_SUBJECTS 6

typedef struct {
    char name[50];
    int roll;
    int marks[NUM_SUBJECTS];
    float average;
} Student;

void calculateAverage(Student *student);
void sortStudents(Student students[], int n);
void printRankList(Student students[], int n);

int main(void)
{
    Student students[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &students[i].roll);

        for (int j = 0; j < NUM_SUBJECTS; j++)
        {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }

        calculateAverage(&students[i]);
    }

    sortStudents(students, NUM_STUDENTS);
    printRankList(students, NUM_STUDENTS);

    return 0;
}

void calculateAverage(Student *student)
{
    int sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        sum += student->marks[i];
    }
    student->average = (float)sum / NUM_SUBJECTS;
}

void sortStudents(Student students[], int n)
{
    Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (students[i].average > students[j].average)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printRankList(Student students[], int n)
{
    printf("\nRank List (in ascending order of average marks):\n");
    printf("Roll\tName\t\tAverage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%-15s\t%.2f\n", students[i].roll, students[i].name, students[i].average);
    }
}
