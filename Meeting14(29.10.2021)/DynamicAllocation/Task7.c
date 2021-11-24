// Задача 7. Реализирайте масив с променлива размерност. Началният размер на
// масива да бъде въведен от потребителя. Запълнете масива с избрани от вас цели
// числа. Изведете масива на екрана. Запитайте потребителя за нов размер на
// масива и повторете предните операции - запълнете масива с избрани от вас числа
// и го изведете на екрана.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int iSize = 0, iResize = 0, iTemp = 0;
    int *pI = NULL;
    char cChoice = '0';

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

    while( (cChoice != 'N') && (cChoice != 'n') )
    {
        fflush(stdin);

        printf("\nWould you like more elements? (Press N for NO, anything else for YES) \n");
        cChoice = getchar();

        if( (cChoice == 'N') || (cChoice == 'n') )
        {
            break;
        }

        printf("\nEnter the new number of elements: ");
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
    }
    
    free(pI);

    return 0;
}