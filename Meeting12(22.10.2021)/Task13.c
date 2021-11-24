/*
13. Напишете програма, която намира максималния и минималния елементи
в масив, използвай указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

int findMin(const int *pArr, const int size);
int findMax(const int *pArr, const int size);

int main()
{
    int arr[SIZE] = { 0 };
    int iMin = 0, iMax = 0;

    setArray(arr, SIZE);
    printf("\nYour array:\n");
    printArray(arr, SIZE);

    iMin = findMin(arr, SIZE);
    printf("\nSmallest number in the array: %d", iMin);
    
    iMax = findMax(arr, SIZE);
    printf("\nLargest number in the array: %d", iMax);

    return 0;
}

int findMin(const int *pArr, const int size)
{
    int min = *pArr;

    for(int i = 1; i < size; i++)
    {
        if(*(pArr+i) < min)
        {
            min = *(pArr+i);
        }
    }

    return min;
}

int findMax(const int *pArr, const int size)
{
    int max = *pArr;

    for(int i = 1; i < size; i++)
    {
        if(*(pArr+i) > max)
        {
            max = *(pArr+i);
        }
    }

    return max;
}