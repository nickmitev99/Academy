/*
Задача 6. Напишете програма на С, която чрез функция да обръща
десетични числа в двоични.
*/

#include <stdio.h>
#include <string.h>

void fPrintResult();
void fDecToBin(int num, char* p);
void fReverseArray(char *p, int iSize);

int main()
{
    fPrintResult();

    return 0;
}

void fPrintResult()
{
    char sStr[32] = { 0 };
    int iNum1 = 0, iSize = 0;

    printf("Enter a number: ");
    scanf("%d", &iNum1);

    fDecToBin(iNum1, sStr);
    iSize = (strlen(sStr) - 1);
    fReverseArray(sStr, iSize);

    printf("The number %d in binary is %s", iNum1, sStr);
}

void fDecToBin(int num, char* p)
{
    do
    {
        *p += ( (num % 2) + '0' );
        num /= 2;
        p++;
    } while(num != 0);
}
    
void fReverseArray(char* p, int iSize)
{
    char cTemp = 0;

    for(int i = 0; i <= iSize; i++, iSize--)
    {
        cTemp = p[i];
        p[i] = p[iSize];
        p[iSize] = cTemp;
    }
}