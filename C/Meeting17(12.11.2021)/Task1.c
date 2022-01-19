// Задача 1. Напишете обединение от три стойности: цяло число, число с
// плаваща запетая и низ. Инициализирайте отделните членове и ги изведете
// на екрана.

#include <stdio.h>

union uValues{
    int m_iValue;
    double m_dValue;
    char m_sValue[20];
};

typedef union uValues uValues;

void initAndPrintInt(uValues *p);
void initAndPrintDouble(uValues *p);
void initAndPrintStr(uValues *p);

int main()
{
    uValues val;

    initAndPrintInt(&val);
    initAndPrintDouble(&val);
    initAndPrintStr(&val);

    return 0;
}

void initAndPrintInt(uValues *p)
{
    printf("Enter a value for the integer: ");
    scanf("%d", &p->m_iValue);

    printf("%d\n", p->m_iValue);
}

void initAndPrintDouble(uValues *p)
{
    printf("Enter a value for the double: ");
    scanf("%lf", &p->m_dValue);

    printf("%lf\n", p->m_dValue);
}

void initAndPrintStr(uValues *p)
{
    printf("Enter a value for the string: ");
    scanf("%s", p->m_sValue);

    printf("%s\n", p->m_sValue);
}