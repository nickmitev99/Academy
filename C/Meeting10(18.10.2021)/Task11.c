/*
Задача 11. напишете функция void squeeze(char s[], int c),
която премахва символа с от низа s[]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void squeeze(char sStr[], int c);

int main()
{
    char sStr[30];
    char c = 0;

    printf("Enter a character to remove: ");
    scanf("%[a-zA-Z]", &c);

    fflush(stdin);

    printf("Enter a string: ");
    gets(sStr);

    squeeze(sStr, (int)c);

    printf("The string with the character - %c - removed is: %s", c, sStr);

    return 0;
}

void squeeze(char sStr[], int c)
{
    int iSize = strlen(sStr);

    for(int i = 0; i < iSize; i++)
    {
        if (sStr[i] == c)
        {
            for(int j = i; j < iSize; j++)
            {
                sStr[j] = sStr[j+1];
            }

            iSize--;
            i--;
        }
    }
}