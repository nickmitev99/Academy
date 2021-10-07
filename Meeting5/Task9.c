/*Да се дефинира константата Пи (3.14159...) и да се напише
функция , която изчислява лицето на окръжност по даден радиус Пи * R * R).
В main() да се извика горната функция с радиуси 1, 1.5, 13.
*/

#include <stdio.h>

const double PI = 3.14159265359;

double calculateCircleArea(const double radius);

int main()
{
    printf("%.16lf\n", calculateCircleArea(1));
    printf("%.16lf\n", calculateCircleArea(1.5));
    printf("%.16lf\n", calculateCircleArea(13));

    return 0;
}

double calculateCircleArea(const double radius)
{
    return (radius*radius*PI);
}