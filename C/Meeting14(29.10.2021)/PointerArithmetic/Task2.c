// Задача 2. Напишете програма, която чете съобщение от клавиатурата, след
// което го принтира в обратен ред, използвайки адресна аритметика.

#include <stdio.h>
#include <string.h>
#include "Functions.h"

#define SIZE 20

void printReverse(char* pS);

int main()
{
    char sStr[SIZE] = { 0 };
    char *pS = NULL;
    int iLast = 0;

    printf("Enter a string: ");
    setString(sStr);

    iLast = (strlen(sStr) - 1);
    pS = &sStr[iLast];

    printReverse(pS);
    
    return 0;
}

void printReverse(char* pS)
{
    while(*pS)
    {
        putchar(*pS);

        pS--;
    }
}