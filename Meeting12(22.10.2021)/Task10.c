/*
10. Напишете програма, която обръща стринг, въведен от клавиатурата,
използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 30

int fStrlen(char *pStr);
void reverseString(char *pStart, char *pEnd);

int main()
{
    char sStr[SIZE] = { 0 };
    char *pStart = NULL, *pEnd = NULL;
    int size = 0;

    printf("Enter a string: ");
    setString(sStr);

    size = fStrlen(sStr) - 1;

    pStart = sStr;
    pEnd = &sStr[size];

    reverseString(pStart, pEnd);

    printf("\n--Reversed string--\n");
    printString(sStr);

    return 0;
}

int fStrlen(char *pStr)
{
    int size = 0;

    while(*pStr++)
    {
        size++;
    }

    return size;
}

void reverseString(char *pStart, char *pEnd)
{
    char temp = 0;
    int size = ( fStrlen(pStart) / 2 );

    for(int i = 0; i < size; i++)
    {
        temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++;
        pEnd--;
    }
}