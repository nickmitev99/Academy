/*
Упражнение 7.18.* напишете алтернативна версия на функцията
void squeeze(char s1[],char s2[]), която премахва всеки символ в s1[],
който съответства на някой от символите в s2.
*/

#include <stdio.h>
#include <string.h>

void squeeze(char aArray1[], char aArray2[]);

int main()
{
    char aArray1[30];
    char aArray2[30];

    printf("Enter the first string: ");
    gets(aArray1);

    printf("Enter the second string: ");
    gets(aArray2);

    squeeze(aArray1, aArray2);

    printf("The result when we remove all characters in aArray2 from aArray1 is: %s", aArray1);

    return 0;
}

void squeeze(char aArray1[], char aArray2[])
{
    int iSize1 = strlen(aArray1);
    int iSize2 = strlen(aArray2);

    for(int i = 0; i < iSize1; i++)
    {
        for(int j = 0; j < iSize2; j++)
        {
            if (aArray1[i] == aArray2[j])
            {
                for(int k = i; k < iSize1; k++)
                {
                    aArray1[k] = aArray1[k+1];
                }

                iSize1--;
                i--;
            }
        }

    }
    
}