#include <stdio.h>
#include <limits.h>

#define student_max 100

typedef struct {
    int id;
    char name[50];
    int score;
    char grade;
} Student;

int main() {
    int num;
    printf("enter  number of student: ");
    scanf("%d", &num);
           // Allocate memory for the array of students
            Student *students = (Student*)malloc(sizeof(Student) * num);

            if (students == NULL) {
                printf( "Memory allocation failed.\n");
                exit(0);
            }

        /*struct Student *ptr=(struct Student *)malloc(num*sizeof(Student));*/

        initial_Students(students, num);
        display_all_Students(students, num);
        display_MinMax_Score(students, num);
        display_Student_Grades(students, num);

    return 0;
}

void initial_Students(Student students[], int num) {

    for (int i = 0; i < num; i++) {

        printf("enter data for student %d id , name  , score [score from 1 to 100]: ", i + 1);
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].score);

        for (int j = 0; j < i; j++) {
            if (students[i].id == students[j].id) {
                printf(" Please enter a unique ID.\n");
                i--;
                break;
            }
        }
        if (students[i].score >= 90) {
            students[i].grade = 'A';
        } else if (students[i].score >= 80) {
            students[i].grade = 'B';
        } else if (students[i].score >= 70) {
            students[i].grade = 'C';
        } else if (students[i].score >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

void display_all_Students(const Student students[], int num) {
    printf("\n all student data:\n");
    for (int i = 0; i < num; i++) {
        printf("iD: %d, name: %s, score: %d\n", students[i].id, students[i].name, students[i].score);
    }
    printf("\n");
}
void display_MinMax_Score(const Student students[], int num) {
    int maxScore = INT_MIN;
    int minScore = INT_MAX;
    int maxIndex = -1;
    int minIndex = -1;

    for (int i = 0; i < num; i++) {
        if (students[i].score > maxScore) {
            maxScore = students[i].score;
            maxIndex = i;
        }
        if (students[i].score < minScore) {
            minScore = students[i].score;
            minIndex = i;
        }
    }

    printf("Student have  the max score:\n");
    printf("id: %d, name: %s, score: %d\n", students[maxIndex].id, students[maxIndex].name, students[maxIndex].score);

    printf("student have min score:\n");
    printf("id: %d, name: %s, score: %d\n", students[minIndex].id, students[minIndex].name, students[minIndex].score);

    printf("\n");
}

void display_Student_Grades(const Student students[], int num) {
    printf("Grades :\n");
    for (int i = 0; i < num; i++) {
        printf("id: %d, name: %s, score: %d, grade: %c\n", students[i].id, students[i].name, students[i].score, students[i].grade);
    }
}
