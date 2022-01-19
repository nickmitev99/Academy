// Задача 3. Дефинирайте структура, която да се състои от цели числа, битови
// полета и union. Попълнете всички елементи на структурата, като използвате
// операторите “.” и “->” за достъп до елементите. Разпечатайте отделните
// елементи, както и размера на структурата.

#include <stdio.h>

union uPerson{
    char m_sName[20];
    int m_age;
};

typedef union uPerson uPerson;

struct Value
{
    int count;
    int bit : 6;
    uPerson m_Person;
};

typedef struct Value Value;

int main()
{
    Value val;
    int bit;

    printf("Enter a string: ");
    scanf("%s", val.m_Person.m_sName);

    printf("Enter an integer: ");
    scanf("%d", &val.count);

    printf("Enter a bit (max 31): ");
    scanf("%d", &bit);

    val.bit = bit;

    printf("\nString in union: %s\n", val.m_Person.m_sName);
    printf("Integer in struct: %d\n", val.count);
    printf("Bit field in struct: %d\n", val.bit);

    printf("\nEnter an integer: ");
    scanf("%d", &val.m_Person.m_age);

    printf("\nInteger in union: %d", val.m_Person.m_age);

    return 0;
}