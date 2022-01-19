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

void setString(char *pStr)
{
    gets(pStr);
}

void printString(char *pStr)
{
    while(*pStr)
    {
        putchar( *(pStr++) );
    }
}
