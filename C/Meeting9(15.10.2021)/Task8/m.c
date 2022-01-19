/*
Задача 8.Напишете прототипите на разгледаните досега функции int
add(int a, int b) и int incr(int c) във файла f.h, a телата на функциите във
файла f.c. използвайте тези функции във файла m.c, където е разписано
тялото на функцията main() . Компилирайте програмата по показания по-
горе начин.
*/

#include <stdio.h>
#include "f.h"

int main()
{
    int a = 0, b = 0, c = 0;

    printf("Enter a value for a: ");
    scanf("%d", &a);

    printf("Enter a value for b: ");
    scanf("%d", &b);

    printf("Enter a value for c: ");
    scanf("%d", &c);

    printf("\nadd(a, b): %d\n", add(a, b));

    printf("incr(c): %d\n", incr(c));

    return 0;
}