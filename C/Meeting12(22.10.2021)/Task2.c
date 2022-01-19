/*
2. Напишете програма, която копира един масив в друг, използвайки
указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void copyArray(int *pFrom, int *pTo, int size);

int main()
{
    int arr[SIZE] = { 0 }, arr2[SIZE] = { 0 }; 
    int *p = arr, *p2 = arr2;

    printf("Setting array1:\n");
    setArray(p, SIZE);

    printf("\nCopied elements from array1 to array2!\n");
    copyArray(p, p2, SIZE);

    printf("\nPriniting array2: \n");
    printArray(p2, SIZE);

    return 0;
}

void copyArray(int *pFrom, int *pTo, int size)
{
    int i = 0;

    while(i++ < size)
    {
        *(pTo++) = *(pFrom++);
    }
}