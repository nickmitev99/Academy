// Задача 6. Напишете програма, която пита потребителя колко памет иска и заделя
// съответният блок памет. След това попитайте потребителя за нов размер и
// използвайте функция, която прави това.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iN = 0;
    int *pI = NULL;
    char cChoice = '0';

    printf("Enter the number of elements: ");
    scanf("%d", &iN);

    pI = (int*) malloc(iN * sizeof(int));

    if(!pI)
    {
        printf("Allocation unsuccesfull!\n");
        return -1;
    }

    while( (cChoice != 'N') && (cChoice != 'n') )
    {
        fflush(stdin);
        printf("Would you like more elements? (Press N for NO, anything else for YES) \n");
        cChoice = getchar();

        if( (cChoice == 'N') || (cChoice == 'n') )
        {
            break;
        }

        printf("Enter the number of elements: ");
        scanf("%d", &iN);

        pI = realloc(pI, iN * sizeof(int));
        
        if(!pI)
        {
            printf("Reallocation unsuccesfull!\n");
            return -2;
        }
    }

    setArray(pI, iN);
    printArray(pI, iN);

    free(pI);

    return 0;
}