/*
Задача 7. Напишете програма на С, която съдържа 2 функции.
1.Първата смята лице на правоъгълен триъгълник.
2.Втората използва лицето на триъгълника, за да сметне лице на
четириъгълник със същите дължини на страните, като раменете на
триъгълника.
Напишете прототипите на функциите най-отгоре, а телата им под мейн
функцията.
Пример за извикване функция
*/

#include <stdio.h>

int fAreaTriangle(int a, int b);
int fAreaRectangle(int area);

int main()
{
    int iBase = 0, iHeight = 0, iAreaT = 0, iAreaR = 0;

    printf("Enter the base of the triangle: ");
    scanf("%d", &iBase);

    printf("Enter the height of the triangle: ");
    scanf("%d", &iHeight);

    iAreaT = fAreaTriangle(iBase, iHeight);
    iAreaR = fAreaRectangle(iAreaT); 

    printf("\nThe area of the right-angled triangle is: %d\n", iAreaT);
    printf("The area of the rectangle is: %d\n", iAreaR);

}

int fAreaTriangle(int a, int b)
{
    return (a * b)/2;
}

int fAreaRectangle(int area)
{
    return (2 * area);
}