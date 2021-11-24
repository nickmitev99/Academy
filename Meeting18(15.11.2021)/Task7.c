// Задача 7. Напишете масив от структури наречен key_tab[ ], като използвате
// тази, дефинирана в горното упражнение - потребителски тип key_t, която
// съдържа символен низ и число. Инициализирайте масива с всички ключови
// думи на С, като заделяте паметта за всяка ключова дума динамично.
// Принтирайте масива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

struct keywords{
    char *m_sName;
    int m_iNumber;
};

typedef struct keywords key_t;
typedef key_t* key_tPtr;

void setStruct(key_tPtr tPtr, const int iSize);
void printStruct(key_tPtr tPtr, int iSize);
void freeMem(key_tPtr tPtr, const int iSize);

int main()
{
    key_t tKey[SIZE];

    setStruct(tKey, SIZE);
    printStruct(tKey, SIZE);

    freeMem(tKey, SIZE);

    return 0;
}

void setStruct(key_tPtr tPtr, const int iSize)
{
    const char *asKeywords[] = { "auto", "double", "int", "struct",
                                "break", "else", "long", "switch",
                                "case",	"enum",	"register",	"typedef",
                                "char",	"extern", "return", "union",
                                "continue",	"for", "signed", "void",
                                "do", "if", "static", "while",
                                "default", "goto", "sizeof", "volatile",
                                "const", "float", "short", "unsigned" };

    char sString[SIZE];
    int iStringLenght = 0;


    for(int i = 0; i < iSize; i++)
    {
        iStringLenght = strlen(asKeywords[i]);

        tPtr[i].m_sName = (char*)malloc(iStringLenght);
        strcpy(tPtr[i].m_sName, asKeywords[i]);
        tPtr[i].m_sName[iStringLenght] = '\0';

        tPtr[i].m_iNumber = (i+1);
    }

}

void printStruct(key_tPtr tPtr, const int iSize)
{
    for(int i = 0; i < iSize; i++)
    {
        printf("\nKeyword%d: %s", tPtr[i].m_iNumber, tPtr[i].m_sName);
    }
}

void freeMem(key_tPtr tPtr, const int iSize)
{
    for(int i = 0; i < iSize; i++)
    {
        free(tPtr[i].m_sName);
    }
}