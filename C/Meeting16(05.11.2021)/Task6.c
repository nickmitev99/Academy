// Задача 6. Напишете програма, която да изчислява средния успех на всеки
// студент и целия курс, използвайки структури. Входните данни за студентите
// трябва да бъдат въведени от потребителя. Принтирайте резултатите за
// всеки студент поотделно, както и за целия курс.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 128

struct Student{
    char *fName;
    char *lName;
    int iCounter;
    int history;
    int maths;
    int science;
    int english;
    int physics;
    float averageGrade;
};

struct Class
{
    int countStudents;
    float averageGrade;

    struct Student *stud;
};

char* setName();
void enterGrade(int *grade);
void gradeCountIncrement(int *counter);
void addToAverage(int* grade, float* average);
void printGrades(struct Student *stud, int size);

int main()
{
    struct Class *class = (struct Class*)malloc(sizeof(struct Class));
    char cChoice = 'y';
    int i = 0;

    memset(class, 0, sizeof(struct Class));
    
    class->stud = (struct Student*)malloc(sizeof(struct Student));

    memset(class->stud, 0, sizeof(struct Student));

    while(cChoice == 'y' || cChoice == 'Y')
    {
        system("cls");
        fflush(stdin);

        printf("Enter the first name of the student: ");
        class->stud[i].fName = setName();

        printf("Enter the last name of the student: ");
        class->stud[i].lName = setName();

        printf("Enter %s %s's grade in History: ", class->stud[i].fName, class->stud[i].lName);

        enterGrade(&class->stud[i].history);
        gradeCountIncrement(&class->stud[i].iCounter);
        addToAverage(&class->stud[i].history, &class->stud[i].averageGrade);

        printf("Enter %s %s's grade in Maths: ", class->stud[i].fName, class->stud[i].lName);

        enterGrade(&class->stud[i].maths);
        gradeCountIncrement(&class->stud[i].iCounter);
        addToAverage(&class->stud[i].maths, &class->stud[i].averageGrade);

        printf("Enter %s %s's grade in Science: ", class->stud[i].fName, class->stud[i].lName);

        enterGrade(&class->stud[i].science);
        gradeCountIncrement(&class->stud[i].iCounter);
        addToAverage(&class->stud[i].science, &class->stud[i].averageGrade);

        printf("Enter %s %s's grade in English: ", class->stud[i].fName, class->stud[i].lName);

        enterGrade(&class->stud[i].english);
        gradeCountIncrement(&class->stud[i].iCounter);
        addToAverage(&class->stud[i].english, &class->stud[i].averageGrade);

        printf("Enter %s %s's grade in Physics: ", class->stud[i].fName, class->stud[i].lName);

        enterGrade(&class->stud[i].physics);
        gradeCountIncrement(&class->stud[i].iCounter);
        addToAverage(&class->stud[i].physics, &class->stud[i].averageGrade);

        class->stud[i].averageGrade /= class->stud[i].iCounter;

        class->countStudents++;

        class->averageGrade += class->stud[i].averageGrade;

        printf("\nDo you want to enter another student? (Y for YES, anything else for NO):\n");
        cChoice = getch();

        if(cChoice == 'y' || cChoice == 'Y')
        {
            ++i;
            class->stud = (struct Student*)realloc(class->stud, (i+1) * sizeof(struct Student));
            memset(&class->stud[i], 0, sizeof(struct Student));
        }
    }

    system("cls");

    class->averageGrade /= class->countStudents;

    printGrades(class->stud, class->countStudents);

    printf("\nClass average grade: %.2f", class->averageGrade);

    for(int i = 0; i < class->countStudents; i++)
    {
        free(class->stud[i].fName);
        free(class->stud[i].lName);
    }

    free(class->stud);
    free(class);

    return 0;
}

char* setName()
{
    char str[MAX];
    char *pS = NULL;

    scanf("%s", str);

    pS = malloc(strlen(str));
    strcpy(pS, str);

    return pS;
}

void enterGrade(int *grade)
{
    while(1)
    {
        scanf("%d", grade);

        if(*grade < 2 || *grade > 6)
        {
            printf("\nEnter a grade between 2 and 6!\n");
        }
        else
        {
            break;
        }
    }
}

void gradeCountIncrement(int *counter)
{
    (*counter)++;
}

void addToAverage(int* grade, float* average)
{
    *average += *grade;
}

void printGrades(struct Student *stud, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\nStudent: %s %s\tHistory: %d\tMaths: %d", stud[i].fName, stud[i].lName, stud[i].history, stud[i].maths);
        printf("\tScience: %d\tEnglish: %d\tPhysics: %d", stud[i].science, stud[i].english, stud[i].physics);
        printf("\nAverage grade: %.2f\n", stud[i].averageGrade);
    }
}