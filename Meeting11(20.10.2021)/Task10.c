#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Functions.h"

#define SIZE 10

void putSpaces(int spaces);
void printPos(int* aInts, int size);
void printNum(int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };

    setArray(aInts, SIZE);
    printPos(aInts, SIZE);
    putchar('\n');
    printNum(aInts, SIZE);

    return 0;
}

void putSpaces(int spaces)
{
    int hasOddDigits = spaces % 2;

    if( spaces == 1 )
    {
        spaces += 1;
    }
    else if ( (!hasOddDigits) && hasOddDigits < 4 )
    {
        spaces -= 1;
    }
    else if (hasOddDigits > 4)
    {
        spaces -= (spaces/2);
    }

    for(int j = 0; j < spaces; j++)
    {
        putchar(' ');
    }
}

void printPos(int* aInts, int size)
{
    int iSpaces = 0;
    char temp[10] = { 0 };

    for(int i = 0; i < size; i++)
    {
        itoa(aInts[i], temp, 10);
        iSpaces = strlen(temp);

        if( ! (iSpaces % 2) )
        {
            putSpaces(iSpaces+1);
            printf("%d", i);
            putSpaces(1);
        }
        else if (iSpaces == 1)
        {
            putSpaces(1);
            printf("%d", i);
            putSpaces(iSpaces);
        }
        else
        {
            putSpaces(iSpaces);
            printf("%d", i);
            putSpaces(1);
        }
    }
}

void printNum(int* aInts, int size)
{
    int iSpaces = 0;
    char temp[10] = { 0 };

    for(int i = 0; i < size; i++)
    {
        putchar('|');
        printf(" %d ", aInts[i]);
    }
    putchar('|');
}