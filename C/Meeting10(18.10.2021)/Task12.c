/*
Задача 12. напишете функцията int any(char s1[], char s2[]),
която връща първата позиция в низа s1, където се появява някой от
символите в низа s2 (Стандартната библиотечна функция strpbrk
извършва тази функция).
*/

#include <stdio.h>
#include <string.h>

int any(char sStr1[], char sStr2[]);

int main()
{
    int iPos = 0;
    char sStr1[30];
    char sStr2[30];

    printf("Enter the first string: ");
    gets(sStr1);

    printf("Enter the second string: ");
    gets(sStr2);

    iPos = any(sStr1, sStr2);

    printf("The position for the first character that arrives from sStr2 (%c) into sStr1 is: %d", sStr2[iPos], iPos);

    return 0;
}

int any(char sStr1[], char sStr2[])
{
    int iSize1 = strlen(sStr1);
    int iSize2 = strlen(sStr2);
    int iPos = 0;

    for(int i = 0; i < iSize1; i++)
    {
        for(int j = 0; j < iSize2; j++)
        {
            if (sStr1[i] == sStr2[j])
            {
                iPos = i;
                return iPos;
            }
        }

    }

    return iPos;
}