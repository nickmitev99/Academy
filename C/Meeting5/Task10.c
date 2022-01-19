/*Задача 17.* Към задача 16 да се добави втора функция , която изчислява
лицето на елипса по зададени два параметъра ( Пи * A * B).
*/

#include <stdio.h>

const double PI = 3.14159265359;

double calculateCircleArea(const double radius);
double calculateElipseArea(const double a, const double b);

int main()
{
    double iValueA = 0.0;
    double iValueB = 0.0;

    printf("%.16lf\n", calculateCircleArea(1));
    printf("%.16lf\n", calculateCircleArea(1.5));
    printf("%.16lf\n", calculateCircleArea(13));

    printf("Enter A: ");
    scanf("%lf", &iValueA);

    printf("Enter B: ");
    scanf("%lf", &iValueB);

    printf("%.16lf\n", calculateElipseArea(iValueA, iValueB));



    return 0;
}

double calculateCircleArea(const double radius)
{
    return (radius*radius*PI);
}

double calculateElipseArea(const double a, const double b)
{
    return (a*b*PI);
}