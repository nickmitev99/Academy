/*
Задача 4. Напишете функция, която връща резултат a*2 + b*c.
*/

#include <stdio.h>

int fResult(int a, int b, int c);

int main()
{
    int iValue1 = 0, iValue2 = 0, iValue3 = 0, iResult = 0;

    printf("Enter the first number: ");
    scanf("%d", &iValue1);

    printf("Enter the second number: ");
    scanf("%d", &iValue2);

    printf("Enter the third number: ");
    scanf("%d", &iValue3);

    iResult = fResult(iValue1, iValue2, iValue3);

    printf("The result for (%d * 2) + (%d * %d) is: %d", iValue1, iValue2, iValue3, iResult);

    return 0;
}

int fResult(int a, int b, int c)
{

    return (a * 2) + (b * c);
}