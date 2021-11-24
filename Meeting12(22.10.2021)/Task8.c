/*
8. Напишете програма, която събира две числа, използвайки указатели.
*/

#include <stdio.h>

int sum(const int *first, const int *second);

int main()
{
    int iNum1 = 0, iNum2 = 0, iResult = 0;

    printf("Enter the 1st number: ");
    scanf("%d", &iNum1);

    printf("Enter the 2nd number: ");
    scanf("%d", &iNum2);

    iResult = sum(&iNum1, &iNum2);

    printf("\nThe sum of the two numbers is: %d", iResult);

    return 0;
}

int sum(const int *first, const int *second)
{
    return (*first + *second);
}