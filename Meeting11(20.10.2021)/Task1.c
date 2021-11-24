/*
1. Прочетете масив от цели числа от клавиатурата. Копирайте
въведения масив във втори масив, като умножите стойността
на всеки елемент по 2. Принтирайте двата масива.
*/

#include <stdio.h>

void printArray(int *arr, int size);

int main()
{
    int aInt1[10] = { 0 };
    int aInt2[10] = { 0 };

    for(int i = 0; i < 10; i++)
    {
        printf("Enter element number %d: ", i+1);
        scanf("%d", &aInt1[i]);
    }

    for(int i = 0; i < 10; i++)
    {
        aInt2[i] = aInt1[i] * 2;
    }

    printf("Array1:\n");
    printArray(aInt1, 10);
    
    printf("\nArray2:\n");
    printArray(aInt2, 10);

    return 0;
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Element %d: %d\n", i+1, arr[i]);
    }
}