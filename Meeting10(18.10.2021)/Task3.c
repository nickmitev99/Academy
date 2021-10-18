/*
Задача 3.* Добавете проверка във функцията int atof(char
*s) дали подаденият стринг няма показни позиции преди числото,
и ако има, ги премахнете. Проверете дали числото не е
отрицателно и, ако е така, включете знака в резултата.
*/

#include <stdio.h>

double atof(char *pStr);

int main()
{
    char sStr[20] = { 0 }; 

    printf("Enter a floating point number: ");
    scanf("%s", sStr);

    printf("atof(%s): %lf\n", sStr, atof(sStr));

    return 0;
}

double atof(char *pStr)
{
    int beforePoint = 0;
    int afterPoint = 0;
    int power = 1, isNeg = 0;
    double num = 0.0;

    while(*pStr)
    {
        if (pStr[0] == '-')
        {
            isNeg = 1;
        }

        else if (*pStr == '.')
        {
            for(; *pStr != '\0'; pStr++)
            {
                if( ( (*pStr - '0') >= 0 ) && ( (*pStr - '0') <= 9 ) )
                {
                    afterPoint = (10 * afterPoint) + (*pStr - '0');
                    power *= 10;
                }
            }

            break; 
        }

        else if ( ( (*pStr - '0') >= 0 ) && ( (*pStr - '0') <= 9 ) )
        {
            beforePoint = (10 * beforePoint) + (*pStr - '0');
        }

        pStr++;
    }

    num = (double)(afterPoint) / power;
    num += beforePoint;

    if(isNeg)
    {
        return (-num);
    }

    else 
    {
        return num;
    }
}