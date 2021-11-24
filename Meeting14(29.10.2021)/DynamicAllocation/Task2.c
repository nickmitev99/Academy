// Задача 2. Разширяване на заделена памет с realloc.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iN = 0, iM = 0, iTemp = 0;
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

    printf("Enter the new number of elements: ");
    scanf("%d", &iM);

    pI = (int*) realloc(pI, iM * sizeof(int));

    if(pI != NULL)
    {
        printf("Reallocation succesfull!\n");
    }

    if(iN < iM)
    {
        for(int i = iN; i < iM; i++)
        {
            printf("Enter a value for aInts[%d]: ", i);
            scanf("%d", &pI[i]);  
        }
    }

    printArray(pI, iM);

    free(pI);

    return 0;
}