// Задача 1. Дефинирайте структура като потребителски тип.Инициализирайте
// членовете на структурата, използвайки новия потребителски тип. Отпечатайте.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char *mp_cName;
    int m_iAge;
};

typedef struct Person s_Person;

void setStruct(s_Person *pPers);
void printStruct(s_Person *pPers);

int main()
{
    s_Person sPers;

    setStruct(&sPers);
    printStruct(&sPers);

    free(sPers.mp_cName);

    return 0;
}

void setStruct(s_Person *pPers)
{
    int iNameLenght = 0;
    char sName[40] = { 0 };

    printf("Enter a name: ");
    scanf("%s", sName);

    iNameLenght = strlen(sName);
    pPers->mp_cName = (char*)malloc(iNameLenght);

    strcpy(pPers->mp_cName, sName);
    pPers->mp_cName[iNameLenght] = '\0';

    printf("Enter an age: ");
    scanf("%d", &pPers->m_iAge);
}

void printStruct(s_Person *pPers)
{
    printf("\nName: %s", pPers->mp_cName);
    printf("\nAge: %d", pPers->m_iAge);
}