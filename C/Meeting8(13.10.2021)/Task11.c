/*
Упражнение 11*. Напишете функция void reverse(char s[]), която обръща
низа char s[]. Използвайте for цикъл с два аргумента, разделени със запетая
i = 0, j = strlen(s) – 1; i < j; i++, j-- , за да обърнете стринга.
*/

#include <stdio.h>
#include <string.h>

void reverse(char sStr[]);

int main()
{
    char cChar = 0;
    char sStr[30];
    int i = 0;

    while(cChar != EOF)
    {
        cChar = getchar();

        if(cChar != EOF)
        {
            sStr[i] = cChar;
        }

        i++;
    }

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