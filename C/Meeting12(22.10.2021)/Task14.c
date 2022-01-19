/*
14. Напишете програма, която да изчисли факториал на дадено число,
използвайки указатели.
*/

#include <stdio.h>

double factorial(double* num);

int main()
{
    double iNum = 0, *pNum = &iNum, iResult = 0;

    printf("Enter the number to calc its factorial: ");
    scanf("%lf", &iNum);

    iResult = factorial(pNum);

    if(iResult < 9999999)
    {
        printf("The factorial is: %.lf", iNum, iResult);
    }
    else
    {
        printf("The factorial is: %.7le", iNum, iResult);
    }

    return 0;
}

double factorial(double* num)
{
    for(int i = (*num - 1); i > 1; i--)
    {
        *num *= i;
    }

    return *num;
}

