// Задача 1. Дефинирайте константи PI, Е, и други с помощта на макроси. 
// Използвайте ги в кода.

#include <stdio.h>

#define PI 3.14159265359
#define E 2.71828182846

int main()
{
    int iNum = 0;
    double iResult = 0.0;

    printf("Enter a number: ");
    scanf("%d", &iNum);

    iResult = iNum * PI;

    printf("%d x %lf = %lf\n", iNum, PI, iResult);

    iResult = iNum * E;

    printf("%d x %lf = %lf", iNum, E, iResult);

    return 0;
}