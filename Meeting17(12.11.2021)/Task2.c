// Задача 2. Напишете обединение от число и низ, както и изброим тип за
// съдържанието на обединението. Напишете функция, която получава
// указател към обединението и изброимия тип и извежда съответно низ или
// число.

#include <stdio.h>

typedef union{
    int m_iValue;
    char m_sValue[20];
}uValues;

typedef enum{ str, num }type;

void print(uValues *p, type tp);

int main()
{
    uValues val;

    printf("Enter a value for the integer: ");
    scanf("%d", &val.m_iValue);

    print(&val, num);

    printf("Enter a value for the string: ");
    scanf("%s", val.m_sValue);

    print(&val, str);

    return 0;
}

void print(uValues *p, type tp)
{
    if(tp)
    {
        printf("%d\n", p->m_iValue);
    }
    else
    {
        printf("%s\n", p->m_sValue);
    }
}