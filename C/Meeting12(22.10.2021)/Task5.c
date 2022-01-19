/*
5. Напишете програма за търсене на определен елемент в даден масив,
използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void searchArray(int num, int *pArray, int size);

int main()
{
    int arr[SIZE] = { 0 };
    int  *p = arr, iNum = 0;

    printf("\nSet the array:\n");
    setArray(p, SIZE);

    printf("\nEnter a num to search: ");
    scanf("%d", &iNum);
    searchArray(iNum, p, SIZE);

    return 0;
}

void searchArray(int num, int *pArray, int size)
{
    int temp = 0;

    for(int i = 0; i < size; i++)
    {
        if(num == *(pArray+i) )
        {
            printf("The number %d is in the array in position No:%d", num, i);
            return;
        }
    }

    printf("The number %d isn't in the array", num);
}