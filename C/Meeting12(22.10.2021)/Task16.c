/*
16. Напишете функция-аналог на стандартната С функция strcmp(), като
използвате указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 20

int fStrCmp(const char* str1, const char* str2);

int main()
{
    char sStr1[SIZE] = { 0 };
    char sStr2[SIZE] = { 0 };

    printf("Enter the first string: ");
    setString(sStr1);

    printf("Enter the second string: ");
    setString(sStr2);

    if( ( fStrCmp(sStr1, sStr2) > 0 ) )
    {
        printf("sStr1 is greater than sStr2");
    }
    else if( ( fStrCmp(sStr1, sStr2) < 0 ) )
    {
        printf("sStr2 is greater than sStr1");
    }
    else
    {
        printf("sStr1 is equal to sStr2");
    }
    

    return 0;
}

int fStrCmp(const char* str1, const char* str2)
{
    while( (*str1 == *str2) && (*str1 != '\0') )
    {
        str1++;
        str2++;
    }

    return (unsigned char)(*str1) - (unsigned char)(*str2);
}