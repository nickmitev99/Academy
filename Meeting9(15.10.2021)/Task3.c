/*
Задача 3. Напишете функция, която връща резултат (а+в)*4.
*/

#include <stdio.h>

int fResult(int a, int b);

int main()
{
    int iValue1 = 0, iValue2 = 0, iResult = 0;

    printf("Enter the first number: ");
    scanf("%d", &iValue1);

    printf("Enter the second number: ");
    scanf("%d", &iValue2);

    iResult = fResult(iValue1, iValue2);

    printf("The result for (%d + %d) * 4 is: %d", iValue1, iValue2, iResult);

    return 0;
}

int fResult(int a, int b)
{
    return (a+b) * 4;
}