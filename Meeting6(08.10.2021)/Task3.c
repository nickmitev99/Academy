/*
Задача 11. Аритметични оператори
#include <stdio.h>
int main()
{
int iX = 13;
int iY = 44;
int iResult = 0;
iResult = iX - iY;
printf("%d - %d = %d \n", iX, iY, iResult);
iResult = iY / iX;
printf("%d / %d = %d \n", iY, iX, iResult);
iResult = iY % iX;
printf("%d / %d Remainder: %d\n", iY, iX, iResult);
// homework: examples for '*' и '+', float - използвайте вместо int
return 0;
*/

#include <stdio.h>

int main()
{
    int iX = 13, iY = 44, iResult = 0;
    float fX = 13.0, fY = 44.0, fResult = 0.0;

    printf("Examples with int: \n");
    iResult = iX + iY;
    printf("%d + %d = %d \n", iX, iY, iResult);
    iResult = iY * iX;
    printf("%d * %d = %d \n", iY, iX, iResult);

    printf("\nExamples with float: \n");
    fResult = fX + fY;
    printf("%f + %f = %f \n", fX, fY, fResult);
    fResult = fY * fX;
    printf("%f * %f = %f \n", fY, fX, fResult);



    return 0;
}

