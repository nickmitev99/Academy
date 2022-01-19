/*
Упражнение 10.Напишете функция reverse(s), която обръща символния низ
s. Използвайте я, за да напишете програма, която преобръща входа си ред
по ред.
*/

#include <stdio.h>

void reverse(char sStr[], char cChar);

int main()
{
    char cChar = 0;
    char sStr[30];

    reverse(sStr, cChar);

    return 0;
}

void reverse(char sStr[], char cChar)
{
    int i = 0;
    while(cChar != EOF)
    {
        cChar = getchar();
        sStr[i] = cChar;
        i++;
    }

    for( ; i >= 0 ; i--)
    {
        printf("%c", sStr[i]);
    }
}