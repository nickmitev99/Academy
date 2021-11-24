/*
12. Напишете примерна програма, която връща няколко стойности от
функция, използвайки указател.
*/

#include <stdio.h>

int isBigger(const int *const first, const int *const second);

int main()
{
    int iNum1, iNum2;

    printf("Enter the first number: ");
    scanf("%d", &iNum1);

    printf("Enter the second number: ");
    scanf("%d", &iNum2);

    if(isBigger(&iNum1, &iNum2) == iNum1)
    {
        printf("\niNum1 = %d is bigger than iNum2 = %d", iNum1, iNum2);
    }
    else if(isBigger(&iNum1, &iNum2) == iNum2)
    {
        printf("\niNum2 = %d is bigger than iNum1 = %d", iNum2, iNum1);
    }
    else
    {
        printf("\niNum1 = %d is equal to iNum2 = %d", iNum1, iNum2);
    }


    return 0;
}

int isBigger(const int *const first, const int *const second)
{
    if(*first > *second)
    {
        return *first;
    }
    else if(*second > *first)
    {
        return *second;
    }
    else
    {
        return 0;
    }
}