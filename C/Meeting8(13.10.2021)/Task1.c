/*
Задача 1: Пребройте символите, подавани на конзолата, с
функцията
getchar();
*/

#include <stdio.h>

int main()
{
    char cChar = 0;
    int iCount = 0;

    while(cChar != EOF)
    {
        cChar = getchar();
        iCount++;
    }

    iCount--;

    printf("getchar() has %d symbols (- the EOF)", iCount);
   
    return 0;
}