#include <stdio.h>

int main(void)
{
    float fOunces = 0.0, fCups = 0.0;

    printf("Enter how many ounces you would like: ");
    scanf("%f", &fOunces);

    fCups = fOunces / 8;

    printf("You would have %.3f cups.", fCups);

    return 0;
}