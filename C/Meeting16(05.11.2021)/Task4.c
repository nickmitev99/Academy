// Задача 4. Напишете произволна програма, която да демонстрира уменията
// ви да боравите с nested structure.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    float saved_balance;
}Savings;

typedef struct
{
    float curr_balance;
    Savings *savings;

}BankAccount;

void insert(float *p);
void withdraw(float *p);
void display(float *p);
void transfer(float *pFrom, float *pTo);

int main()
{
    char cChoice = 0;
    BankAccount *ba = (BankAccount*)malloc(sizeof(BankAccount));

    ba->savings = (Savings*)malloc(sizeof(Savings));

    memset(ba, 0, sizeof(ba));
    memset(ba->savings, 0, sizeof(Savings));

    do
    {
        system("cls");
        printf("--BANK ACCOUNT--\n");
        printf("1. Insert in bank account\n");
        printf("2. Withdraw from bank account\n");
        printf("3. Check bank account balance\n");
        printf("4. Check savings balance\n");
        printf("5. Transfer from your account into your savings\n");
        printf("6. Transfer from your savings into your account\n");
        printf("7. Exit\n");

        cChoice = getch();
        fflush(stdin);

        system("cls");

        switch (cChoice)
        {
        case '1':
            insert(&ba->curr_balance);
            break;

        case '2':
            withdraw(&ba->curr_balance);
            break;

        case '3':
            display(&ba->curr_balance);
            break;

        case '4':
            display(&ba->savings->saved_balance);
            break;

        case '5':
            transfer(&ba->curr_balance, &ba->savings->saved_balance);
            break;

        case '6':
            transfer(&ba->savings->saved_balance, &ba->curr_balance);
            break;

        case '7':
            return 0;
            break;
        
        default:
            printf("\nInvalid choice!\n");
            break;
        }

        system("pause");

    } while (1);

    free(ba->savings);
    free(ba);

    return 0;
}

void insert(float *p)
{
    float sum;
    printf("Enter the sum you would like to insert: ");
    scanf("%f", &sum);

    *p += sum;
}

void withdraw(float *p)
{
    float sum;
    printf("Enter the sum you would like to withdraw: ");
    scanf("%f", &sum);

    if(*p < sum)
    {
        printf("\nInsufficient ammount!\n");
    }
    else
    {
        *p -= sum;
        printf("\nYou withdrew %.3fBGN succesfuly!\n", sum);
    }
}

void display(float *p)
{
    printf("\nBalance: %.3fBGN\n", *p);
}

void transfer(float *pFrom, float *pTo)
{
    float sum;

    printf("Enter the sum you would like to transfer: ");
    scanf("%f", &sum);

    if(*pFrom < sum)
    {
        printf("\nInsufficient ammount!\n");
    }
    else
    {
        *pFrom -= sum;
        *pTo += sum;
        printf("\nYou transfered %.3fBGN succesfuly!\n", sum);
    }
}