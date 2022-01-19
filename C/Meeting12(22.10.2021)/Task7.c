/*
7. Напишете програма, която конкатери два стринга, използвайки указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 20

void fStrcat(char* pTo, char* pFrom1, char* pFrom2);

int main()
{
    char sStr[SIZE] = { 0 }, sStr2[SIZE] = { 0 };
    char sCombined[SIZE*2] = { 0 };

    printf("Enter the 1st string: ");
    setString(sStr);

    printf("\nEnter the 2nd string: ");
    setString(sStr2);
    
    fStrcat(sCombined, sStr, sStr2);

    printf("\n%s + %s = %s", sStr, sStr2, sCombined);

    return 0;
}

void fStrcat(char* pTo, char* pFrom1, char* pFrom2)
{
    while(*pFrom1)
    {
        *pTo++ = *pFrom1++;
    }

    while(*pFrom2)
    {
        *pTo++ = *pFrom2++;
    }
}