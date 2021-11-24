#include <stdio.h>

void setMatrix(int *arr, int rows, int cols)
{
    int size = rows * cols;

    for(int i = 0; i < size; i++)
    {
        printf("Enter element[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void printMatrix(int *arr, int rows, int cols)
{
    int size = rows * cols;
    int n = cols - 1;

    for(int i = 0; i < size; i++)
    {
        printf("Element %d: %d   ", i, arr[i]);
        if(i == n)
        {
            putchar('\n');
            n += cols;
        }
    }
}