/*
9. Напишете програма, която да завърти даден масив от цели
числа с N позиции наляво. Масива и числото N трябва да бъдат
въведени от клавиатурата. Принтирайте оригиналния и
резултатния масиви.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 10

void shiftArray(int *arr, int size);

int main()
{
    int aInts[SIZE] = { 0 };

    setArray(aInts, SIZE);
    shiftArray(aInts, SIZE);
    printArray(aInts, SIZE);

    return 0;
}

void shiftArray(int *arr, int size)
{
    int iShift = 0, iTemp = 0, iCount = 0, iSize = size - 1;

    printf("\nEnter a number for left shift positions: ");
    scanf("%d", &iShift);

    while(iCount < iShift)
    {
        iTemp = arr[0];

        for(int j = 0; j < iSize; j++)
        {
            arr[j] = arr[j+1];
        }

        arr[iSize] = iTemp;
        iCount++;
    }
    putchar('\n');
}