// Задача 1. Напишете програма, която сумира всички елементи на масив
// намиращи се на нечетна позиция. Масива да бъде въведен от потребителя.
// Разпечатайте в конзолата масива и сумата.

#include <stdio.h>
#include "Functions.h"

#define SIZE 5

int sumOdd(int *p, int size);

int main()
{
    int iaNums[SIZE] = { 0 };
    int *p = iaNums;

    setArray(p, SIZE);
    putchar('\n');

    printArray(p, SIZE);

    printf("\nThe sum of the odd numbers is: %d", sumOdd(p, SIZE) );
    
    return 0;
}

int sumOdd(int *p, int size)
{
    int iSum = 0;

    for(int i = 0; i < size; i++, p++)
    {
        if(i%2)
        {
            iSum += *p;
        }
    }

    return iSum;
}