// Задача 4. Дефинирайте тип указател към функция, която изпълнява
// определена операция върху две целочислени променливи. Дефинирайте
// функции, които изпълняват операциите +, -, *, /. Използвайте новия тип, за да
// извикате всяка една от функциите.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu();
double fnAdd(double a, double b);
double fnSubtract(double a, double b);
double fnMultiply(double a, double b);
double fnDivide(double a, double b);

typedef double (*pfCalc)(double, double);

int main()
{
    menu();
    
    
    return 0;
}

void menu()
{
    pfCalc pF[] = { fnAdd, fnSubtract, fnMultiply, fnDivide };
    double iNum1 = 0, iNum2 = 0;
    char cChoice = 0;

    do
    {
        system("cls");
        printf("--WELCOME--\n");
        printf("\nEnter a choice:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("Anything else to exit.\n");

        printf("\nYour choice: ");
        cChoice = getch();
        system("cls");
        
        if( (cChoice >= '1') && (cChoice <= '4') )
        {
            printf("\nEnter the first number: ");
            scanf("%lf", &iNum1);

            printf("\nEnter the second number: ");
            scanf("%lf", &iNum2);
        }

        switch(cChoice)
        {
            case '1':
                printf("Result: %.3lf\n", pF[cChoice-'1'](iNum1, iNum2));
                break;

            case '2':
                printf("Result: %.3lf\n", pF[cChoice-'1'](iNum1, iNum2));
                break;

            case '3':
                printf("Result: %.3lf\n", pF[cChoice-'1'](iNum1, iNum2));
                break;

            case '4':
                printf("Result: %.3lf\n", pF[cChoice-'1'](iNum1, iNum2));
                break;
            
            default:
                printf("\nExiting...");
                return;
        }
        system("pause");
    } while (cChoice < '5');
}

double fnAdd(double a, double b)
{
    return (a+b);
}

double fnSubtract(double a, double b)
{
    return (a-b);
}

double fnMultiply(double a, double b)
{
    return (a*b);
}

double fnDivide(double a, double b)
{
    return (a/b);
}