// Задача 7. Разгледайте и имплементирайте quicksort алгоритъма.

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

void quicksort(int *p, int first, int last);
void swapNums(int *iNum1, int *iNum2);

int main()
{
    int iaNums[SIZE] = { 0 };
    int *p = iaNums, iNum = 0;

    setArray(p, SIZE);
    putchar('\n');

    quicksort(p, 0, SIZE-1);

    printArray(p, SIZE);
    putchar('\n');

    return 0;
}

void quicksort(int *p, int iFirst, int iLast)
{
    if(iFirst < iLast)
    {
        int i = iFirst;
        int j = iLast;

        while(i < j)
        {
            while( ( *(p + i)  <= *(p + iFirst) ) && (i < iLast) )
            {
                i++;
            }

            while( ( *(p + j) > *(p + iFirst) ) )
            {
                j--;
            }

            if(i < j)
            {
                swapNums(p+i, p+j);
            }
        }

        swapNums(p+iFirst, p+j);
        quicksort(p, iFirst, j-1);
        quicksort(p, j+1, iLast);
    }
}

void swapNums(int *iNum1, int *iNum2)
{
    int temp = *iNum1;
    *iNum1 = *iNum2;
    *iNum2 = temp;
}