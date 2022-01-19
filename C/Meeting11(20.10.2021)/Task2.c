/*
2. Напишете програма, която запълва масив от 20 елемента с
произволно избрани цели числа. За целта използвайте
функцията rand(). Въведете едно цяло число от
клавиатурата. Проверете дали въведеното число от
клавиатурата е намерено в масива. Принтирайте масива и
отговора дали числото е намерено в масива. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

#define SIZE 20

void checkNum(int* aInts, int size, int num);

int main()
{
    int aInts[20] = { 0 };
    int iNum = 0;

    srand(time(0));
    fillWithRandom(aInts, SIZE);

    printf("Enter a number: ");
    scanf("%d", &iNum);

    checkNum(aInts, SIZE, iNum);

    return 0;
}

void checkNum(int* aInts, int size, int num)
{
    int iIsFound = 0;

    for(int i = 0; i < 20; i++)
    {
        if(num == aInts[i])
        {
            printf("Your number is in the array in the %d position: %d\n", i+1, aInts[i]);
            iIsFound = 1;
        }
    }

    if(!iIsFound)
    {
        printf("Your number is not found in the array\n");
    }
}