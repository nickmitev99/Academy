// Задача 9. Представете служителите във фирма в структура с членове:
// пореден номер, име, презиме, фамилия, позиция, трудов стаж в години,
// заплата в лева, указател към структурата, описващ неговия началник.
// Напишете програма, която въвежда 10 служителя, които се съхраняват в
// масив от описаните структури. След като въведете всички служители,
// задайте началник за всеки от тях. В решението трябва да се използва
// динамично заделяне на памет и typedef.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EMPLOYEE_COUNT 3

typedef struct Manager t_Manager;
typedef struct Employee t_Employee;
typedef enum Position t_Position;

enum Position{
    Employee,
    Manager
};

struct Manager{
    int id;
    char* fName;
    char* mName;
    char* lName;
    t_Position position;
};

struct Employee{
    int id;
    char* fName;
    char* mName;
    char* lName;
    t_Position position;

    t_Manager* manager;
};

void setManager(t_Manager **tPMan, int iManCount);
void setEmployee(t_Employee **tPEmp, int iEmpCount, t_Manager **tPMan, int iManCount);
char* setName(const char *structType, const char *nameType);
void printAll(t_Employee **tPEmp, int iEmpCount, t_Manager **tPMan, int iManCount);
void freeManager(t_Manager **tPMan, int iManCount);
void freeEmployee(t_Employee **tPEmp, int iEmpCount);

int main()
{
    int iManCount = 0;
    t_Manager **tMan = NULL;
    t_Employee **tEmp = NULL;

    printf("Enter the amount of Managers: ");
    scanf("%d", &iManCount);

    tMan = (t_Manager**)malloc(sizeof(t_Manager*) * iManCount);

    for(int i = 0; i < iManCount; i++)
    {
        tMan[i] = (t_Manager*)malloc(sizeof(t_Manager));
    }

    tEmp = (t_Employee**)malloc(sizeof(t_Employee*) * EMPLOYEE_COUNT);

    for(int i = 0; i < EMPLOYEE_COUNT; i++)
    {
        tEmp[i] = (t_Employee*)malloc(sizeof(t_Employee));
    }

    setManager(tMan, iManCount);
    setEmployee(tEmp, EMPLOYEE_COUNT, tMan, iManCount);

    printAll(tEmp, EMPLOYEE_COUNT, tMan, iManCount);
    
    freeManager(tMan, iManCount);
    freeEmployee(tEmp, EMPLOYEE_COUNT);

    return 0;
}

void setManager(t_Manager **tPMan, int iManCount)
{
    if(!iManCount)
    {
        return;
    }

    for(int i = 0; i < iManCount; i++)
    {
        tPMan[i]->id = i+1;

        tPMan[i]->fName = setName("Manager", "First");
        tPMan[i]->mName = setName("Manager", "Middle");
        tPMan[i]->lName = setName("Manager", "Last");

        tPMan[i]->position = Manager;

        putchar('\n');
    }

}

void setEmployee(t_Employee **tPEmp, int iEmpCount, t_Manager **tPMan, int iManCount)
{
    int iManager = 0;

    if(!iEmpCount || iManCount < 0)
    {
        return;
    }

    srand(time(0));

    for(int i = 0; i < iEmpCount; i++)
    {
        iManager = rand() % iManCount;

        tPEmp[i]->id = i+1;

        tPEmp[i]->fName = setName("Employee", "First");
        tPEmp[i]->mName = setName("Employee", "Middle");
        tPEmp[i]->lName = setName("Employee", "Last");

        tPEmp[i]->position = Employee;

        tPEmp[i]->manager = tPMan[rand() % iManCount];

        putchar('\n');
    }

}

char* setName(const char *structType, const char *nameType)
{
    char sName[40] = { 0 };
    char *sP;
    int iNameLenght = 0;

    printf("\nEnter %s's %s name: ", structType, nameType);
    scanf("%s", sName);

    iNameLenght = strlen(sName);

    sP = (char*)malloc(iNameLenght);
    strcpy(sP, sName);

    return sP;
}

void printAll(t_Employee **tPEmp, int iEmpCount, t_Manager **tPMan, int iManCount)
{
    system("cls");
    
    printf("--MANAGERS--\n");
    for(int i = 0; i < iManCount; i++)
    {
        printf("\nID: %d", tPMan[i]->id);
        printf("\nName: %s %s %s", tPMan[i]->fName, tPMan[i]->mName, tPMan[i]->lName);
        printf("\nPosition: ", tPMan[i]->position);

        switch(tPMan[i]->position)
        {
            case Employee: 
                printf("Employee");
                break;

            case Manager:
                printf("Manager");
                break;
        }
    }

    printf("\n-EMPLOYEES--\n");
    for(int i = 0; i < iEmpCount; i++)
    {
        printf("\nID: %d", tPEmp[i]->id);
        printf("\nName: %s %s %s", tPEmp[i]->fName, tPEmp[i]->mName, tPEmp[i]->lName);
        printf("\nPosition: ", tPEmp[i]->position);

        switch(tPEmp[i]->position)
        {
            case Employee: 
                printf("Employee");
                break;

            case Manager:
                printf("Manager");
                break;
        }

        printf("\nManager: %s %s %s", tPEmp[i]->manager->fName, tPEmp[i]->manager->mName, tPEmp[i]->manager->lName);
    }
}

void freeManager(t_Manager **tPMan, int iManCount)
{
    for(int i = 0; i < iManCount; i++)
    {
        free(tPMan[i]->fName);
        free(tPMan[i]->mName);
        free(tPMan[i]->lName);
        free(tPMan[i]);
    }

    free(tPMan);
}

void freeEmployee(t_Employee **tPEmp, int iEmpCount)
{
    for(int i = 0; i < iEmpCount; i++)
    {
        free(tPEmp[i]->fName);
        free(tPEmp[i]->mName);
        free(tPEmp[i]->lName);
        free(tPEmp[i]);
    }

    free(tPEmp);
}