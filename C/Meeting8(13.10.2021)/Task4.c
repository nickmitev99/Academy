/*
Задача 4. Напишете програма, която копира входа си на изхода, като
замества всеки низ повече от една шпации, с една единствена
шпация.
*/

#include <stdio.h>

int main()
{
    char cChar = 0;
    int iCount = 0;
    
    while(cChar != '\n')
    {
        cChar = getchar();

        if( cChar == ' ' && iCount == 0)
        {
            putchar(cChar);
            iCount++;
        }

        else if(cChar != ' ')
        {
            putchar(cChar);
            iCount = 0;
        }
    }

    return 0;
}