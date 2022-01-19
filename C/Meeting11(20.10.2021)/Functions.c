#include <stdio.h>
#include <stdlib.h>

void setArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Enter a value for aInts[%d]: ", i);
        scanf("%d", &arr[i]);                                       
    }
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Element %d: %d\n", i+1, arr[i]);
    }
}

void fillWithRandom(int* aInts, int size)
{
    for(int i = 0; i < size; i++)
    {
        aInts[i] = rand() % 100;                                       //Filled with random numbers with a maximum value of 99
    }
}