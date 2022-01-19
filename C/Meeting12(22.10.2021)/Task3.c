/*
3. Напишете програма, която разменя елементите на два еднакви по размер
масива, използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void swapArray(int *pFirst, int *pSecond, int size);

int main()
{
    int arr[SIZE] = { 0 }, arr2[SIZE] = { 0 };
    int  *p = arr, *p2 = arr2;

    printf("\nSet first array:\n");
    setArray(p, SIZE);

    printf("\nSet second array:\n");
    setArray(p2, SIZE);

    printf("\nThe elements of both arrays have been swapped!\n");
    swapArray(p, p2, SIZE);

    printf("\nFirst array:\n");
    printArray(p, SIZE);

    printf("\nSecond array:\n");
    printArray(p2, SIZE);

    return 0;
}

void swapArray(int *pFirst, int *pSecond, int size)
{
    int temp = 0;

    for(int i = 0; i < size; i++)
    {
        temp = *(pFirst + i);
        *(pFirst + i) = *(pSecond + i);
        *(pSecond + i) = temp;
    }
}