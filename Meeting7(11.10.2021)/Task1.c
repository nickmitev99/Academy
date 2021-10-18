/*
Упражнение 7.13.* Използвайте for цикъл, за да преобразувате низ от char
в целочислено число. Направете проста реализация на библиотечната
функция atoi(). Знаем, че char '0' = 48 т.е. ако char x = '0', за да получим
числото 0, трябва да извадим int r = x ––'0' = 48 48 . Ако имаме
последователност от чарове, записана като char s[] = '123' , трябва да
вземем всеки един елемент s[0],s[1], s[2] да го превърнем в число и да го
умножим по основата на бройната система:
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char sStr[30];
    int iSize = 0;
    int iNum = 0;
    int iPower = 0;

    printf("Enter a number: ");
    scanf("%s", sStr);


    iSize = strlen(sStr);
    iPower = pow(10, (iSize-1));

    for(int i = 0; i < iSize; i++, iPower /= 10)
    {
        if( (sStr[i] < '0') || (sStr[i] > '9') )
        {
            printf("Error! String must contain only numbers!\nExiting...\n");
            break;
        }
        iNum += ((sStr[i] - '0') * iPower);
    }

    printf("The number in the int is: %d", iNum);

    return 0;
}
