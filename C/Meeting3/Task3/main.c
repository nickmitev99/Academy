#include <stdio.h>

int main(void)
{
    float iEarthDays = 0.0, iJupiterYears = 0.0;

    printf("Enter the amount of Earth days you would like to convert: ");
    scanf("%f", &iEarthDays);

    iJupiterYears = 365 * 12;

    printf("The amount in Jupiter years is: %.3f", iEarthDays / iJupiterYears);

    return 0;
}