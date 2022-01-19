// Задача 5. Заделете динамична памет за масив от елементи, като извикате
// функция, която нулира заделената памет.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iN = 0;
    int *pI = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &iN);

    pI = (int*) calloc(iN, sizeof(int));

    if(!pI)
    {
        printf("Allocation unsuccesfull!\n");
        return -1;
    }

    printArray(pI, iN);

    free(pI);

    return 0;
}