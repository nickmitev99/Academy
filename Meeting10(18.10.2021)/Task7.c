/*
Задача 7. Напишете функция, която прави същото, както в задача
6, но е рекурсивна.
*/

#include <stdio.h>

double recursiveFactorial();

int main()
{
    double a = recursiveFactorial(30);
    printf("!30: %.lf", a);

    return 0;
}

double recursiveFactorial(int i)
{
    double num = 0.0;

    if(i < 2)
    {
        num = i;
        return num;
    }

    return i * recursiveFactorial(i-1);
}