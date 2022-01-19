/*
3. Напишете програма, която запълва масив от 20 елемента с
произволно избрани стойности. За целта използвайте функцията
rand(). Намерете най-голямото число в масива. Принтирайте
намереното число и масива.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

#define SIZE 20

int findMax(int* aInts, int size);

int main()
{
    int aInts[SIZE] = { 0 };
    int iNum = 0;

    srand(time(0));
    fillWithRandom(aInts, SIZE);

    printf("Printing the array: \n");
    printArray(aInts, SIZE);

    iNum = findMax(aInts, SIZE);
    printf("\nThe biggest number is: = %d", iNum);

    return 0;
}

int findMax(int* aInts, int size)
{
    int num = -2147483648;

    for(int i = 0; i < size; i++)
    {
        if(num < aInts[i])                                            //Checking if every next number is bigger than the previous
        {
            num = aInts[i];                                                  //Storing the biggest number in the array
        }
    }

    return num;
}