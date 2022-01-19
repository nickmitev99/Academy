// Задача 1. Да се направи програма, която заделя динамичен масив с брой
// елементи зададени от потребителя. За всеки елемент от масива се очаква
// потребителят да въведе цяло и число и след това се изчислява сумата на
// всички елементи от масива.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iN = 0;
    int *pI = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &iN);

    pI = (int*) malloc(iN * sizeof(int));

    if(pI != NULL)
    {
        printf("Allocation succesfull!\n");
    }

    setArray(pI, iN);
    printArray(pI, iN);

    free(pI);

    return 0;
}