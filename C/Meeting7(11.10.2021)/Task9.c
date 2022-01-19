/*
Упражнение 7.20.* напишете функцията void lower(char s[]), която
преобразува главните букви в малки.
*/

#include <stdio.h>

void lower(char* aArray);

int main()
{
    char aArray[30] = { 0 };

    printf("Enter a string: ");
    gets(aArray);

    lower(aArray);

    printf("aArray1 with func lower() is: %s", aArray);

    return 0;
}

void lower(char* aArray)
{
    while(*aArray)
    {
        if( (*aArray >= 'A') && (*aArray <= 'Z') )
        {
            *aArray += 32;
        }
        aArray++;
    }
}