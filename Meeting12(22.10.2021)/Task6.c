/*
6. Напишете програма, която намира дължината на въведен от клавиатурата
стринг, използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 20

int fStrlen(char *pStr);

int main()
{
    char sStr[SIZE] = { 0 };

    printf("Enter a string: ");
    setString(sStr);

    printf("\nThe size of the string is: %d", fStrlen(sStr));
    
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