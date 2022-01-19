/*
Задача 9. Напишете три функции, които да правят изчисление по ваш
избор и да се извикват по следния начин:
Main вика Ф1;
Ф1 вика Ф 2;
Ф2 вика Ф3;
Изнесете прототипите им в отделен .h файл.
*/

#include <stdio.h>
#include "header.h"

int main()
{
    int a = 0, b = 0;
    printf("\nMAIN:\n");

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    func1(a, b);

    return 0;
}

int func1(int a, int b)
{
    printf("\nfunc1: %d + %d = %d", a, b, (a+b));
    func2(a, b);

    return 0;
}

int func2(int a, int b)
{
    printf("\nfunc2: %d * %d = %d", a, b, (a*b));
    func3(a, b);

    return 0;
}

int func3(int a, int b)
{
    printf("\nfunc3: %d - %d = %d", a, b, (a-b));

    return 0;
}