// Задача 6. Напишете структура с потребителски тип key_t, която съдържа
// символен низ и число. Създайте променлива от новия тип, като
// инициализирате символния низ с динамично заделена памет за него.
// Принтирайте съдържанието на структурата.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct keywords{
    char *m_sName;
    int m_iNumber;
};

typedef struct keywords key_t;
typedef key_t* key_tPtr;

void setStruct(key_tPtr tPtr, int iNumber);
void printStruct(key_tPtr tPtr);

int main()
{
    key_t tKey;

    setStruct(&tKey, 1);
    printStruct(&tKey);

    free(tKey.m_sName);

    return 0;
}

void setStruct(key_tPtr tPtr, int iNumber)
{
    char sString[SIZE];
    int iStringLenght = 0;

    printf("Enter a keyword: ");
    fgets(sString, SIZE, stdin);

    iStringLenght = strlen(sString);

    tPtr->m_sName = (char*)malloc(iStringLenght);
    strcpy(tPtr->m_sName, sString);
    tPtr->m_sName[iStringLenght] = '\0';

    tPtr->m_iNumber = iNumber;
}

void printStruct(key_tPtr tPtr)
{
    printf("Keyword%d: %s", tPtr->m_iNumber, tPtr->m_sName);
}