// Задача 1. Напишете програма, която чете стринг от стандартния вход и го
// извежда на стандартния изход с функцията gets();

#include <stdio.h>

#define SIZE 30

int main()
{
    char strText[SIZE] = { 0 };
    
    fgets(strText, SIZE, stdin);

    fputs(strText, stdout);

    return 0;
}