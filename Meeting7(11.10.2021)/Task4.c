/*
Упражнение 7.15.* Използвайте do-while цикъл, за да напишете функцията
void itoa(int n, char s[]), която преобразува число в символен низ (обратната
функция на atoi). do-while цикълът e необходим, тъй като в масива с ще
трябва да се постави поне един символ, дори ако n е нула. Ако n = 123, за
да вземем последната цифра, трябва да разделим n по модул(%) на
основата на бройната система 10. За да получите чаръктър число, трябва
да съберете резултата с '0'. За да вземете следващото число, трябва да
разделите n на 10. Това продължава докато n е различно от нула. Това
генерира низа в обратен ред – 321, затова използваме функцията от
Упражнение 7.14. , за да обърнем низа.
*/

#include <stdio.h>
#include <string.h>

void reverseArray(unsigned char* aArray, int iStart, int iEnd);
void itoa(int iNum, unsigned char* aArray);

int main()
{
    unsigned char aArray [30] = { 0 };
    int iEnd = 0;
    int iStart = 0;
    int iNum = 0;

    printf("Enter a number: ");
    scanf("%d", &iNum);

    itoa(iNum, aArray);

    iEnd = (strlen(aArray) - 1);

    reverseArray(aArray, iStart, iEnd);

    printf("The string contains: %s", aArray);

    return 0;
}

void reverseArray(unsigned char* aArray, int iStart, int iEnd)
{
    unsigned char cTemp = 0;

    for(iStart = 0; iStart < iEnd; iStart++, iEnd--)
    {
        
        cTemp = aArray[iStart];
        aArray[iStart] = aArray[iEnd];
        aArray[iEnd] = cTemp;
    }
}

void itoa(int iNum, unsigned char* aArray)
{
    do
    {
        *aArray += ( (iNum % 10) + '0');
        iNum /= 10;

        aArray++;
    } while (iNum != 0);
    
}