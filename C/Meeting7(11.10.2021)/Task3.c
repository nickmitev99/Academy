/*
Упражнение 7.14.* Напишете функция void reverse(char s[]), която обръща
низа char s[]. Използвайте for цикъл с два аргумента, разделени със запетая
i = 0, j = strlen(s) – 1; i < j; i++, j-- , за да обърнете стринга.
Задачи за самоподготовка
*/

#include <stdio.h>
#include <string.h>

void reverseArray(unsigned char* aArray, int iStart, int iEnd);

int main()
{
    unsigned char aArray [30];
    int iEnd = 0;
    int iStart = 0;

    printf("Enter a string: ");
    gets(aArray);

    iEnd = (strlen(aArray) - 1);

    printf("Before reversal: %s\n", aArray);

    reverseArray(aArray, iStart, iEnd);

    printf("After reversal: %s\n", aArray);

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