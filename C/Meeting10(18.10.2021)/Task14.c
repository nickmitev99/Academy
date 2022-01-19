/*
Задача 14*. Напишете функция int getline(char s[],int lim), която чете ред в
s[] и връща дължината му.
*/

#include <stdio.h>

int getline(char *pStr, int lim);

int main()
{
    char sStr[30] = { 0 }; 
    printf("Enter a string: ");
    scanf("%s", sStr);

    printf("The number of lines is: %d", getline(sStr, 0));

    return 0;
}

int getline(char *pStr, int lim)
{
    while(*pStr)
    {
        lim++;
        pStr++;
    }

    return lim;
}