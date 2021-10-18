/*
Задача 1.Направете глобална константа pi = 3.14, както правихме в
предишния урок. Напишете функция, която изчислява площта на кръг, на
която като параметър подаваме радиуса и връщаме площта на кръга.
Използвайте глобалната константа pi за да извършите изчисленията.
Извикайте функцията в main() и покажете резултата.
*/

#include <stdio.h>

const double PI = 3.14;

double circleArea(double r);

int main()
{
    double r = 0;

    printf("Enter a radius: ");
    scanf("%lf", &r);

    printf("The area of the circle is: %.3lf", circleArea(r));
   
    return 0;
}

double circleArea(double r)
{
    return r*r*PI;
}