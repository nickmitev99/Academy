// Задача 3. Използвайте Задача 2, за да напишете програма, която проверява
// дали съобщението не е палиндром. Палиндром е съобщение, в което
// буквите от ляво на дясно са същите като от дясно на ляво.

#include <stdio.h>
#include <string.h>
#include "Functions.h"

#define SIZE 20

void setReverse(char* pSFrom, char* pSTo);
int isPalindrome(char* pSFrom, char* pSTo);

int main()
{
    char sStr[SIZE] = { 0 }, sCopy[SIZE] = { 0 };
    char *pS = NULL;
    int iLast = 0;

    printf("Enter a string: ");
    setString(sStr);

    iLast = (strlen(sStr) - 1);
    pS = &sStr[iLast];

    setReverse(pS, sCopy);
    
    putchar('\n');
    printf("Original: ");
    printString(sStr);

    putchar('\n');
    printf("Reversed: ");
    printString(sCopy);

    if( (isPalindrome(sStr, sCopy)) == 1)
    {
        printf("\n\nThe strings are palindromes");
    }
    else
    {
        printf("\n\nThe strings aren't palindromes");
    }

    return 0;
}

void setReverse(char* pSFrom, char* pSTo)
{
    while(*pSFrom)
    {
        *pSTo = *pSFrom;

        pSTo++;
        pSFrom--;
    }
}

int isPalindrome(char* pSFrom, char* pSTo)
{
    int iCounter = 0;

    while(*pSFrom || *pSTo)
    {
        if(*pSFrom == *pSTo)
        {
            iCounter = 1;
        }
        else
        {
            iCounter = 0;
        }

        if( (*pSFrom == '0' && *pSTo) || (*pSTo== '0' && *pSFrom) )
        {
            iCounter = 0;
            break;
        }
        pSFrom++;
        pSTo++;
    }

    return iCounter;
}