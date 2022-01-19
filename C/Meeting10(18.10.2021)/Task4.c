/*
Задача 4. Направете функцията :
void copy(char *to, char *from), която копира една
последователност от символи в друга. Декларирайте масива,
който ще копирате така char *from = "abcdef" или така char from[]
= "abcdef" това е едно и също. Първото е пойнтер, сочещ към
низова константа, второто е началото на масив, сочещ към нея.
Заделете място за масива, в който ще копирате тези символи с
декларация
char to[16]; Копирайте символ по символ масива from[] в to[],
докато не стигнете знака ' 0' терминираща нула знак за край на
стринг. Терминиращият символ ' 0' има стойност 0.
*/

#include <stdio.h>

void copy(char *pFrom, char* pTo);

int main()
{
    char sFrom[30] = { 0 }; 
    char sTo[30] = { 0 };

    printf("Enter a string: ");
    scanf("%[0-9a-zA-Z .!?,:;~+-()@#$%%^&*""/""]", sFrom);

    copy(sFrom, sTo);

    printf("Original: %s\n", sFrom);
    printf("Copy: %s\n", sTo);

    return 0;
}

void copy(char* pFrom, char* pTo)
{
    while(*pFrom)
    {
        *(pTo++) = *(pFrom++);
    }
}