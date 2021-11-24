/*
6. Напишете програма, която да брои колко пъти се среща едно
число в даден масив от цели числа. Масива трябва да бъде
въведен от клавиатурата. Принтирайте резултатите.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 10

void countOccurences(int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };

    setArray(aInts, SIZE);
    countOccurences(aInts, SIZE);

    return 0;
}

void countOccurences(int* aInts, int size)
{
    int iExists = 0, iTemp = 0, iCount = 0;

    for(int i = 0; i < size; i++)
    {
        if(aInts[i] == iTemp)
        {
            iExists = 1;
        }
        else
        {
            iExists = 0;
        }

        for(int j = 0; j < size; j++)
        {
            if( (aInts[i] == aInts[j]) && (iExists == 0) )     //Counts how many times each element occurs in the array
            {
                iCount++;
            }
        }

        for(int k = 0; k < i; k++)                          //Checking if element has already been counted
        {
            if(aInts[k] == aInts[i])
            {
                iExists = 1;
                break;
            }
        }

        if(iExists == 0)
        {
            printf("%d is met %d times\n", aInts[i], iCount);
        }

        iTemp = aInts[i];
        iCount = 0;
    }
}