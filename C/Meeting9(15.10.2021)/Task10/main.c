/*
Задача 10. Напишете програма на С, която съдържа 3 функции, изнесете
прототипите им в отделен .h файл.
1. Първата функция да калкулира най-малко общо кратно на две положителни
числа.
2. Втората функция връща абсолютна стойност на числата (положителната
стойност на числата).
a. Трябва да може да приеме като параметър float и да върне float.
b. Тествайте с инт и float.
3. Напишете функция, която калкулира корен квадратен от число.
a. Проверете дали резултатът е отрицателно число и върнете -1.
b. Използвайте втората си функция, за да обърнете числото в положително и да
намерите корен квадратен от него.
*/

#include <stdio.h>
#include <math.h>
#include "header.h"

int main()
{
    int iA = 0, iB = 0;
    float fA = 0.0;

    printf("\nEnter two numbers to find their least common multiple: ");
    scanf("%d %d", &iA, &iB);

    printf("The least common multiple of %d and %d is: %d\n", iA, iB, fLeastCommonMultiple(iA, iB));


    printf("\nEnter a negative integer to find it's absolute value: ");
    scanf("%d", &iA);

    printf("The absolute value of %d is: %d\n", iA, fAbsI(iA));


    printf("\nEnter a negative float to find it's absolute value: ");
    scanf("%f", &fA);

    printf("The absolute value of %.3f is: %.3f\n", fA, fAbsF(fA));


    printf("\nEnter a number to find it's square root: ");
    scanf("%f", &fA);
    
    printf("The square root of %.3f is: %.3f\n", fAbsF(fA), fSqrt(fA));

    return 0;
}

int fLeastCommonMultiple(int a, int b)
{
    int i = 2;
    int LCM = 0;
    int condition = 0;

    if( (a < 0) && (b < 0) )
    {
        return -1;
    }

    do
    {
        condition = ( (a % i == 0) && (b % i == 0) );
        if(condition)
        {
            LCM = i;
            break;
        }

        i++;
    }while(1);

    return LCM;
}

int fAbsI(int a)
{
    if(a < 0)
    {
        return -a;
    }

    return a;
}

float fAbsF(float a)
{
    if(a < 0.0)
    {
        return -a;
    }

    return a;
}

float fSqrt(float a)
{
    return sqrt( fAbsI(a) );
}