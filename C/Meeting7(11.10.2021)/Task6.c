/*
Упражнение 7.17.* напишете функция void squeeze(char s[], int c),
която премахва символа с от низа s[]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void squeeze(char aArray[], int c);

int main()
{
    char aArray[30];
    char c = 0;

    printf("Enter a character to remove: ");
    scanf("%c", &c);

    fflush(stdin);

    printf("Enter a string: ");
    gets(aArray);

    squeeze(aArray, (int)c);

    printf("The string with the character %c removed is: %s", c, aArray);

    return 0;
}

void squeeze(char aArray[], int c)
{
    int iSize = strlen(aArray);

    for(int i = 0; i < iSize; i++)
    {
        if (aArray[i] == c)
        {
            for(int j = i; j < iSize; j++)
            {
                aArray[j] = aArray[j+1];
            }

            iSize--;
            i--;
        }
    }
    
}