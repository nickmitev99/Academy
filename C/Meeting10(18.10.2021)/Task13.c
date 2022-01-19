/*
Задача 13. напишете функцията void lower(char s[]), която
преобразува главните букви в малки.
*/

#include <stdio.h>

void lower(char* sStr);

int main()
{
    char sStr[30] = { 0 };

    printf("Enter a string: ");
    gets(sStr);

    lower(sStr);

    printf("aArray1 with func lower() is: %s", sStr);

    return 0;
}

void lower(char* sStr)
{
    while(*sStr)
    {
        if( (*sStr >= 'A') && (*sStr <= 'Z') )
        {
            *sStr += 32;
        }
        sStr++;
    }
}