/*
4. Напишете програма, която обръща местата на елементите в един масив,
използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void reverseArray(int *pFirst, int *pSecond, int size);

int main()
{
    int arr[SIZE] = { 0 };
    int  *p = arr;

    printf("\nSet the array:\n");
    setArray(p, SIZE);

    reverseArray(p, &p[SIZE-1], SIZE);

    printf("\nResult of the reversal:\n");
    printArray(p, SIZE);

    return 0;
}

void reverseArray(int *pFirst, int *pSecond, int size)
{
    int temp = 0;

    for(int i = 0; i < size/2; i++)
    {
        temp = *(pFirst + i);
        *(pFirst + i) = *(pSecond - i);
        *(pSecond - i) = temp;
    }
}