/*
Упражнение 7.14.1* Напишете функция htoi(s), която преобразува низ от
шестнадесетични цифри в еквивалентна целочислена стойност.
Възможните цифри са между 0 и 9, от а до f и от А до F.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char sStr[30];
    int iSize = 0, iNum = 0, iPower = 0;

    printf("Enter a hexadecimal number: ");
    gets(sStr);


    iSize = strlen(sStr);
    iPower = pow(16, (iSize-1));

    for(int i = 0; i < iSize; i++, iPower /= 16)
    {
        if( (sStr[i] >= 'A') && ( sStr[i] <= 'F') )
        {
            sStr[i] -= 55;
            iNum += (sStr[i] * iPower);
        }

        else if( (sStr[i] >= 'a') && (sStr[i] <= 'f') )
        {
            sStr[i] -= 87;
            iNum += (sStr[i] * iPower);
        }
        else if ( ( (sStr[i] - '0') >= '0') && ( (sStr[i] - '0') <= '9') )
        {
            iNum += ((sStr[i] - '0') * iPower);
        }
        
    }

    printf("The number in the int is: %d", iNum);

    return 0;
}