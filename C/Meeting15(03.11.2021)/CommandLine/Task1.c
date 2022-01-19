// Задача 1. Да напишем функция char *month_name(int n), която връща указател към
// символен низ, съдържащ името на n-тия месец. Да декларираме вътрешен static масив
// от указатели, сочещ към стрингове съдържащи имената на месеците
// static char *name[] = {
// "Illegal month",
// "January", "February", "March",
// "April", "May", "June",
// "July", "August", "September",
// "October", "November", "December"
// Функцията връща указател към съответния месец, отговарящ на параметъра n.

#include <stdio.h>

char *month_name(int n);

int main()
{
    int iNum = 0;
    char *p = NULL;

    printf("Enter a number: ");
    scanf("%d", &iNum);    

    if(iNum > 0 && iNum <= 12)
    {
        p = month_name(iNum);
        printf("%s", p);
    }
    else
    {
        p = month_name(0);
        printf("%s", p);
    }

    return 0;
}

char *month_name(int n)
{
    static char* name[] = 
    {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return name[n];
}