// Задача.3. Направете масив от указатели към функции по следния начин:
// void add(){...}
// void fun2(){...}
// void fun3(){...}
// void (*func_ptr[3])() = {fun1, fun2, fun3};
// Направете меню, с което да питате потребителя коя от горните функции
// иска да използва – събиране, изваждане, умножение и деление. След това
// попитайте за числата, които да участват в тази операция, и извикайте
// функцията, която да извърши желаната операция

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu();
double fnAdd(double a, double b);
double fnSubtract(double a, double b);
double fnMultiply(double a, double b);
double fnDivide(double a, double b);

int main()
{
    menu();
    
    
    return 0;
}

void menu()
{
    double (*pfCalc[])(double, double) = { fnAdd, fnSubtract, fnMultiply, fnDivide };
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
                printf("Result: %.3lf\n", (*pfCalc[atoi(&cChoice)-1])(iNum1, iNum2));
                break;

            case '2':
                printf("Result: %.3lf\n", (*pfCalc[atoi(&cChoice)-1])(iNum1, iNum2));
                break;

            case '3':
                printf("Result: %.3lf\n", (*pfCalc[atoi(&cChoice)-1])(iNum1, iNum2));
                break;

            case '4':
                printf("Result: %.3lf\n", (*pfCalc[atoi(&cChoice)-1])(iNum1, iNum2));
                break;
            
            default:
                printf("\nExiting...");
                return;
        }
        system("pause");
    } while (1);
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