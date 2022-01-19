/*
Задача 9. Използвайте do-while цикъл, за да напишете функцията
void itoa(int n, char s[]), която преобразува число в символен низ (обратната
функция на atoi). do-while цикълът e необходим, тъй като в масива с ще
трябва да се постави поне един символ, дори ако n е нула. Ако n = 123, за
да вземем последната цифра, трябва да разделим n по модул(%) на
основата на бройната система 10. За да получите чаръктър число, трябва
да съберете резултата с '0'. За да вземете следващото число, трябва да
разделите n на 10. Това продължава докато n е различно от нула. Това
генерира низа в обратен ред – 321, затова използваме функцията от
Задача 8., за да обърнем низа.
*/

#include <stdio.h>
#include <string.h>

void reverse(char sStr[]);
void itoa(int iNum, char* aArray);

int main()
{
    char aArray [30] = { 0 };
    int iNum = 0;

    printf("Enter a number: ");
    scanf("%d", &iNum);

    itoa(iNum, aArray);

    reverse(aArray);

    printf("The string contains: %s", aArray);

    return 0;
}

void reverse(char sStr[])
{
    char temp;

    for(int i = 0, j = strlen(sStr) - 1; i <= j; i++, j--)
    {
        temp = sStr[i];
        sStr[i] = sStr[j];
        sStr[j] = temp;
    }
}

void itoa(int iNum, char* aArray)
{
    do
    {
        *aArray += ( (iNum % 10) + '0');
        iNum /= 10;

        aArray++;
    } while (iNum != 0);
    
}