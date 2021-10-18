/*
Задача 8 Напишете функция void reverse(char s[]), която обръща низа
char s[ ].
*/

#include <stdio.h>
#include <string.h>

void reverse(char sStr[]);

int main()
{
    char cChar = 0;
    char sStr[30];
    int i = 0;

    printf("Enter a string: ");
    scanf("%[0-9a-zA-Z .!?,:;~+-()@#$%%^&*""/""]", sStr);

    reverse(sStr);
    printf("\nThe reversed string: %s", sStr);

    return 0;
}

void reverse(char sStr[])
{
    char temp;

    for(int i = 0, j = strlen(sStr) - 1; i <= j; i++, j--)
    {
        temp = sStr[i];
        sStr[i] = sStr[j];
        sStr[j] = temp;
    }
}