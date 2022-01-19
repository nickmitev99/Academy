/*
Упражнение 7.19.* напишете функцията int any(char s1[], char s2[]),
която връща първата позиция в низа s1, където се появява някой от
символите в низа s2 (Стандартната библиотечна функция strpbrk
извършва тази функция).
*/

#include <stdio.h>
#include <string.h>

int any(char aArray1[], char aArray2[]);

int main()
{
    char aArray1[30];
    char aArray2[30];

    printf("Enter the first string: ");
    gets(aArray1);

    printf("Enter the second string: ");
    gets(aArray2);

    printf("The position for the first character that arrives from aArray2 into aArray2 is: %d", any(aArray1, aArray2));

    return 0;
}

int any(char aArray1[], char aArray2[])
{
    int iSize1 = strlen(aArray1);
    int iSize2 = strlen(aArray2);
    int iPos = 0;

    for(int i = 0; i < iSize1; i++)
    {
        for(int j = 0; j < iSize2; j++)
        {
            if (aArray1[i] == aArray2[j])
            {
                iPos = i;
                return iPos;
            }
        }

    }

    return iPos;
}