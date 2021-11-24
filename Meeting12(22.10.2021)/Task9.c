/*
9. Напишете програма, която разменя две числа, използвай указатели.
*/

#include <stdio.h>

void swapNums(int *const first, int *const second);

int main()
{
    int iNum1, iNum2;

    printf("Enter the 1st number: ");
    scanf("%d", &iNum1);

    printf("Enter the 2nd number: ");
    scanf("%d", &iNum2);

    swapNums(&iNum1, &iNum2);

    printf("\nThe first number is now: %d\n", iNum1);
    printf("The second number is now: %d\n", iNum2);

    return 0;
}

void swapNums(int *const first, int *const second)
{
    int temp = *first;

    *first = *second;
    *second = temp;
}