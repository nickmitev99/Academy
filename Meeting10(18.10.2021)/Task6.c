/*
Задача 6. Напишете функция, която изчислява произведението на
числата от 1 до 30.
Задача
*/

#include <stdio.h>

double forFactorial(int i);

int main()
{
    printf("!30: %.lf", forFactorial(30));

    return 0;
}

double forFactorial(int i)
{
    double num = 1.0;

    for( ; i > 0; i--)
    {
        num *= i;
    }

    return num;
}