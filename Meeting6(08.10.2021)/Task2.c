/*
Упражнение 10*. Напишете функция int isLetter(char c), която проверява
дали подадения параметър е буква или не е буква от ASCII таблицата.
*/
#include <stdio.h>

int isLetter(char letter);

int main()
{
    char cLetter = '\0';
    
    printf("Enter a value for the variable cLetter: ");
    scanf("%c", &cLetter);

    isLetter(cLetter);

    return 0;
}

int isLetter(char letter)
{
    int iCondition1 = (letter >= 65) && (letter <= 90);
    int iCondition2 = (letter >= 97) && (letter <= 122);

    if(iCondition1 || iCondition2)
    {
        printf("""%c"" is a letter", letter);
        return 0;
    }

    else
    {
        printf("""%c"" is not a letter", letter);
        return 1;
    }
}