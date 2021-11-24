// Задача 5. Дефинирайте потребителски тип към масив. Инициализирайте
// масива, изведете на конзолата.

#include <stdio.h>

#define SIZE 5

typedef int aInt[SIZE];
void setArray(int *arr, int size);
void printArray(int *arr, int size);

int main()
{
    aInt iNum;

    setArray(iNum, SIZE);
    printArray(iNum, SIZE);

    return 0;
}

void setArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Enter a value for element[%d]: ", i);
        scanf("%d", &arr[i]);                                       
    }
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\nElement %d: %d", i+1, arr[i]);
    }
}