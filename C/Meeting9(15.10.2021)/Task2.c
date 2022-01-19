/*
Задача 2. Напишете функция area() без параметри. Поискайте от
потребителя да въведе радиуса с помощта на функциите :
printf("Enter a radius\n");
scanf("%lf", &r);
Използвайте горната функция 1.за изчисляване на площта на кръг, която
написахме преди малко за да изчислите площта на кръга с този радиус и
върнете резултата:
*/

#include <stdio.h>

double circleArea(double r);
void area();

const double PI = 3.14;

int main()
{
    area();
   
    return 0;
}

void area()
{
    double r = 0;

    printf("Enter a radius: ");
    scanf("%lf", &r);

    printf("The area of the circle is: %.3lf", circleArea(r));
}

double circleArea(double r)
{
    return r*r*PI;
}