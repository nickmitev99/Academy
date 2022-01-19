/*
8. Напишете програма, която да отделя в два отделни масива
четните и нечетните числа от даден масив с цели числа. Масива
да бъде въведен от клавиатурата. Принтирайте оригиналния и
двата резултатни масива.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 10

void setOddAndEven(int* aOdd, int* aEven, int* aInts, int size);
void printOddAndEven(int* aOdd, int* aEven, int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };
    int aOdd[SIZE] = { 0 };
    int aEven[SIZE] = { 0 };

    setArray(aInts, SIZE);
    setOddAndEven(aOdd, aEven, aInts, SIZE);
    printArray(aInts, SIZE);
    printOddAndEven(aOdd, aEven, aInts, SIZE);

    return 0;
}

void setOddAndEven(int* aOdd, int* aEven, int* aInts, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(aInts[i] % 2 == 0)
        {
            aEven[i] = aInts[i];
        }
        else 
        {
            aOdd[i] = aInts[i];
        }        
    }
}

void printOddAndEven(int* aOdd, int* aEven, int* aInts, int size)
{
    printf("\nOdd nums: \n");
    for(int i = 0; i < 10; i++)
    {
        if(aOdd[i] != 0)
        {
            printf("%d ", aOdd[i]);
        }
    }

    printf("\nEven nums: \n");
    for(int i = 0; i < 10; i++)
    {
        if(aEven[i] != 0)
        {
            printf("%d ", aEven[i]);
        }
    }

    putchar('\n');
}