#include <stdio.h>

int main(void)
{
    float fEarthGravity = 0.0, fMoonGravity = 0.0;

    printf("Enter your weight (in kg): ");
    scanf("%f", &fEarthGravity);

    fMoonGravity = 0.17 * fEarthGravity;

    printf("Your weight on the moon is %.3f kg\n", fMoonGravity);

    return 0;
}