// Задача 3 Напишете функции, с помощта на които да реализирате
// динамичен масив от елементи, чиято големина може да се променя по
// време на изпълнение на програмата.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iSize = 0, iResize = 0;
    int *pI = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &iSize);

    pI = (int*) malloc(iSize * sizeof(int));

    if(!pI)
    {
        printf("Allocation unsuccesfull!\n");
        return -1;
    }

    setArray(pI, iSize);
    printArray(pI, iSize);

    do
    {
        printf("Enter the new number of elements (To exit, enter 1): ");
        scanf("%d", &iResize);
        pI = (int*) realloc(pI, iResize * sizeof(int));

        if(!pI)
        {
            printf("Reallocation unsuccesfull!\n");
            return -2;
        }

        if(iSize < iResize)
        {
            for(int i = iSize; i < iResize; i++)
            {
                printf("Enter a value for aInts[%d]: ", i);
                scanf("%d", &pI[i]);  
            }
        }

        printArray(pI, iResize);
        iSize = iResize;
    }while(iResize != 1);
    
    free(pI);

    return 0;
}