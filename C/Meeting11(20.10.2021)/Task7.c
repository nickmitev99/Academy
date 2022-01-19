/*
7. Напишете програма, която да намери максималния и
минималния елемент в масив от цели числа. Масива трябва да
бъде въведен от клавиатурата. Принтирайте целия масив и
резултатите.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 10

int findMax(int *aInts, int size);
int findMin(int *aInts, int size);

int main()
{
    int aInts[10] = { 0 };
    int iMin = 0, iMax = 0;

    setArray(aInts, SIZE);

    iMax = findMax(aInts, SIZE);
    iMin = findMin(aInts, SIZE);

    printArray(aInts, SIZE);

    printf("Max num: %d\n", iMax);
    printf("Min num: %d\n", iMin);

    return 0;
}

int findMax(int *aInts, int size)
{
    int iMax = -2147483648;

    for(int i = 0; i < size; i++)
    {
        if(iMax < aInts[i])
        {
            iMax = aInts[i];
        }
    }

    return iMax;
}

int findMin(int *aInts, int size)
{
    int iMin = 2147483647;

    for(int i = 0; i < size; i++)
    {
        if(iMin > aInts[i])
        {
            iMin = aInts[i];
        }     
    }

    return iMin;
}
