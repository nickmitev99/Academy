// Задача 4. Заделете динамично с malloc памет за char* buffer с размер size =
// 2. Въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в
// буфера. Увеличавайте размера на буфера преди да се препълни с realloc().
// Прекъснете цикъла с Ctrl + Z. Принтирайте буфера и освободете паметта.

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    char ch = '0';
    char* buffer = NULL;
    int iCounter = 0, iSize = 2;

    buffer = (char*) malloc( iSize * sizeof(char) );

    if(!buffer)
    {
        printf("Allocation failed!");
        return -1;
    }

    printf("Enter a string (to stop, enter EOF): ");

    do
    {
        ch = getchar();

        if(ch != '\n')
        {
            *(buffer+iCounter) = ch;
            iCounter++;
        }

        if( iSize == iCounter )
        {
            iSize *= 2;
            buffer = (char*) realloc( buffer, iSize * sizeof(char) );

            if(!buffer)
            {
                printf("Rellocation failed!");
                return -1;
            }
        }
    } while (ch != EOF);

    buffer[iCounter] = '\0';
    
    printString(buffer);
    free(buffer);

    return 0;
}