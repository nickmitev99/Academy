// Задача 2. Създайте нов потребителски тип към тип long long int. Използвайте го
// във функцията printf, отпечатайте размера.

#include <stdio.h>

typedef long long int LL_Int;

int main()
{
    LL_Int iNum = 0;

    printf("Enter a long long int: ");
    scanf("%lld", &iNum);

    printf("\nYour number is: %lld", iNum);
    printf("\nIt's size in bytes: %d", sizeof(LL_Int));

    return 0;
}