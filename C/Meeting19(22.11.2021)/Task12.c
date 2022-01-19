// Задача 12. Напишете макро GENERIC_MAX(type), което трябва да се 
// замени със следната функция:
// int int_max(int x, int y)
// {
//      return x > y ? x : y;
// }
// или
// float float_max(float x, float y)
// {
//      return x > y ? x : y;
// }
// или 
// char char_max(char x, char y)
// {
//      return x > y ? x : y;
// }

#include <stdio.h>
#include <conio.h>

#define GENERIC_MAX(type) #type
//#define MAX(x, y) (x) > (y) ? (x) : (y)

int int_max(int x, int y);
float float_max(float x, float y);
char char_max(char x, char y);

int main()
{
    char *cChoice = GENERIC_MAX(float);
    
    if(cChoice == "int")
    {
        int iInt1 = 0, iInt2 = 0, iRes = 0;
        printf("Enter the first integer: ");
        scanf("%d", &iInt1);

        printf("Enter the second integer: ");
        scanf("%d", &iInt2);

        iRes = int_max(iInt1, iInt2);

        printf("\n\n%d is bigger", iRes);
    }
    
    else if(cChoice == "float")
    {
        float fFloat1 = 0, fFloat2 = 0, fRes = 0;
        printf("Enter the first float: ");
        scanf("%f", &fFloat1);

        printf("Enter the second float: ");
        scanf("%f", &fFloat2);

        fRes = float_max(fFloat1, fFloat2);

        printf("\n\n%f is bigger", fRes);
    }

    else if(cChoice == "char")
    {
        char cChar1 = 0, cChar2 = 0, cRes = 0;
        printf("Enter the first char: ");
        cChar1 = getchar();

        fflush(stdin);

        printf("\nEnter the second char: ");
        cChar2 = getchar();

        fflush(stdin);

        cRes = int_max(cChar1, cChar2);

        printf("\n\n%c is bigger", cRes);
    }

    else
    {
        printf("\nInvalid choice!");
    }

    return 0;
}

int int_max(int x, int y)
{
    return x > y ? x : y;
}

float float_max(float x, float y)
{
    return x > y ? x : y;
}

char char_max(char x, char y)
{
    return x > y ? x : y;
}