/*
Задача 5. Напишете програма на С, която чрез функция проверява дали
дадено число е четно или не.
*/

#include <stdio.h>

void fPrintResult();
int fIsEven(int a);

int main()
{
    fPrintResult();

    return 0;
}

void fPrintResult()
{
    int iValue1 = 0;
    int iMin = 0, iMax = 0;

    printf("Select the starting number: ");
    scanf("%d", &iMin);

    printf("Select the last number: ");
    scanf("%d", &iMax);

    if(iMin > iMax)
    {
        iValue1 = iMin;
        iMin = iMax;
        iMax = iValue1;
        iValue1 = 0;
    }

    for(int i = iMin; i <= iMax; i++)
    {
        iValue1 = fIsEven(i);

        if(!iValue1)
        {
            printf("The number %d is even\n", i);
        }

        else
        {
            printf("The number %d is odd\n", i);
        }
    }
}

int fIsEven(int a)
{
    if(a % 2 == 0)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}