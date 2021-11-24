// Задача 4. Напишете функцията за сумиране елементите на масив,
// използвайки адресна аритметика вместо инкрементиращa променливa.

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

int sumArray(int *p, int size);

int main()
{
    int iaNums[SIZE] = { 0 };
    int *p = iaNums;

    setArray(p, SIZE);
    putchar('\n');

    printArray(p, SIZE);

    printf("\nThe sum of the numbers is: %d", sumArray(p, SIZE) );
    
    return 0;
}

int sumArray(int *p, int size)
{
    int iSum = 0;
    int *temp = (p+size);
    int pos = 0;

    while( p < temp )
    {
        if(pos % 2)
        {
            iSum += *p;
        }

        pos++;
        p++;
    }

    return iSum;
}