/*
Задача 2: Пребройте редовете, подадени чрез текст на конзолата.
Използвайте функцията getchar();
*/

#include <stdio.h>

int main()
{
    char cChar = '0';
    int iCount = 0;

    while(cChar != EOF)
    {
        cChar = getchar();

        if(cChar == '\n')
        {
            iCount++;
        }
    }

    printf("The total amount is: %d", iCount);
   
    return 0;
}