/*
15. Напишете програма, която да намери броя на гласни и съгласни букви в
текст, въведен от клавиатурата, като използвате указатели.
*/

#include <stdio.h>
#include "Functions.h"

#define SIZE 20

char lower(char letter);
int countVowels(char* str);
int countConsonants(char *str);

int main()
{
    char sStr[SIZE] = { 0 };

    printf("Enter a string: ");
    setString(sStr);

    printf("Vowels: %d\n", countVowels(sStr));
    printf("Consonants: %d\n", countConsonants(sStr));

    return 0;
}

char lower(char letter)
{
    if( (letter >= 'A') && (letter <= 'Z') )
    {
        letter += 32;
    }

    return letter;
}

int countVowels(char* str)
{
    int iVowels = 0;
    int iCondition = 0;

    while(*str)
    {
        iCondition = ( ( (*str >= 'a') && (*str <= 'z') ) || ( (*str >= 'A') && (*str <= 'Z') ) );

        if(iCondition)
        {
            if( (lower(*str) == 'a') || (lower(*str) == 'e') || (lower(*str) == 'i') || (lower(*str) == 'o') || (lower(*str) == 'u') )
            {
                iVowels++;
            }
        }

        str++;
    }

    return iVowels;
}

int countConsonants(char *str)
{
    int iConsonants = 0;
    int iCondition = 0;

    while(*str)
    {
        iCondition = ( ( (*str >= 'a') && (*str <= 'z') ) || ( (*str >= 'A') && (*str <= 'Z') ) );

        if(iCondition)
        {
            if( (lower(*str) != 'a') && (lower(*str) != 'e') && (lower(*str) != 'i') && (lower(*str) != 'o') && 
            (lower(*str) != 'u') )
            {
                iConsonants++;
            }
        }

        str++;
    }

    return iConsonants;
}