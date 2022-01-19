/*
12. Напишете програма, която въвежда масив от цели числа от клавиатурата. Сортирайте го във
възходящ ред. След това от клавиатурата въведете цяло число и го поставете на правилната
му позиция в масива, така че да не се нарушава реда. Принтирайте масива.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 11

void sortArray(int* array, int size);
void swapElements(int* min, int* max);

int main()
{
    int aInts[SIZE] = { 0 };
    int iNum = 0;

    printf("--Setting array--\n");
    setArray(aInts, SIZE-1); 

    printf("\n--Printing sorted array--\n");
    sortArray(aInts, SIZE-1);
    printArray(aInts, SIZE-1);

    printf("\nEnter a number: ");
    scanf("%d", &iNum);

    printf("\n--Printing sorted array with an additional num--\n");
    aInts[SIZE-1] = iNum;
    sortArray(aInts, SIZE);
    printArray(aInts, SIZE);

    return 0;
}

void sortArray(int* array, int size)
{
    int index = 0;

    for(int i = 0; i < size; i++)
    {
        index = i;

        for(int j = i; j < size; j++)
        {
            if(array[index] > array[j])
            {
                index = j;
            }
        }
        swapElements(&array[i], &array[index]);
    }
}

void swapElements(int* min, int* max)
{
    int temp = 0;

    temp = *min;
    *min = *max;
    *max = temp;
}