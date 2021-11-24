/*
11. Напишете програма, която да обедини два масива от цели числа, като ги сортира в низходящ
ред и ги принтира.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void sortArray(int* array, int size);
void swapElements(int* min, int* max);
void combineArray(int *array, int *first, int* second, int size);

int main()
{
    int aInts1[SIZE] = { 0 };
    int aInts2[SIZE] = { 0 };
    int aIntsSorted[SIZE*2] = { 0 };

    printf("--Setting first array--\n");
    setArray(aInts1, SIZE);

    printf("\n--Setting second array--\n");
    setArray(aInts2, SIZE);
    
    combineArray(aIntsSorted, aInts1, aInts2, SIZE*2);
    printf("\nSorted array: \n");
    sortArray(aIntsSorted, SIZE*2);
    printArray(aIntsSorted, SIZE*2);    


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
            if(array[index] < array[j])
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

void combineArray(int *array, int *first, int* second, int size)
{
    for(int i = 0, j = 0; i < size; i++)
    {
        if(i < (size/2))
        {
            array[i] = first[i];
        }
        else 
        {
            array[i] = second[j];
            j++;
        }
    }
}