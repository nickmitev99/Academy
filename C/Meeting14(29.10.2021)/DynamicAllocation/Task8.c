// Задача 8. Напишете програма, в която се въвеждат пореден номер, име,
// фамилия, възраст на участници в маратон. Изискването е за името и
// фамилията да не се използват масиви с фиксирана дължина. След като
// въвеждането завърши, изведете списък с участниците. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu();
void setContestants(char **sFName, char **sLName, int *iAge, int *iNum, int *pos);
void printContestants(char **sFName, char **sLName, int *iAge, int *iNum, int iPos);
void deallocateString(char **sFName, char **sLName, int iPos);

int main()
{
    menu();

    return 0;
}

void menu()
{
    char **sFName = NULL, **sLName = NULL, cChoice = '0';
    int iNum[10] = { 0 }, iAge[10] = { 0 }, iTemp = 0, iPos = 0;
                                                      
    sFName = (char**) malloc(sizeof(char*));
    sLName = (char**) malloc(sizeof(char*));

    if( (!sFName) || (!sLName) )
    {
        printf("Allocation failed!");
        exit(1);
    }

    while( (cChoice != 'N') && (cChoice != 'n') )
    {
        system("cls");

        setContestants(sFName, sLName, iAge, iNum, &iPos);

        printf("\nWould you like to enter more contestants? (Press N for NO, anything else for YES) \n");
        cChoice = getch();

        fflush(stdin);

        if( (cChoice == 'n') || (cChoice == 'N') )
        {
            break;
        }

        sFName = (char**) realloc(sFName, (iPos+1) * sizeof(char*));
        sLName = (char**) realloc(sLName, (iPos+1) * sizeof(char*));

        if( (!sFName) || (!sLName) )
        {
            printf("Reallocation failed!");
            exit(6);
        }
    }
    
    system("cls");

    printContestants(sFName, sLName, iAge, iNum, iPos);
    deallocateString(sFName, sLName, iPos);

    free(sFName);
    free(sLName);
}

void setContestants(char **sFName, char **sLName, int *iAge, int *iNum, int *pos)
{
    static int iPos = 0;
    int iCount = 1, charCounter = 0;
    char ch = '0';

    printf("--ENTERING CONTESTANTS--\n");

    printf("\nEnter contestant No.%d\n", iPos+1);

    printf("First Name: ");
    sFName[iPos] = (char*) malloc(sizeof(char));

    if( (!sFName[iPos]) )
    {
        printf("Allocation failed!");
        exit(2);
    }

    ch = 0;
    charCounter = 0;

    while (ch != '\n')
    {
        ch = getchar();

        if(ch == '\n')
        {
            break;
        }

        sFName[iPos][charCounter] = ch;
        charCounter++;
        sFName[iPos] = (char *)realloc(sFName[iPos], (charCounter+1) * sizeof(char) );

        if( (!sFName[iPos]) )
        {
            printf("Reallocation failed!");
            exit(3);
        }
    }

    sFName[iPos][charCounter] = '\0';

    printf("Last Name: ");
    sLName[iPos] = (char*) malloc(sizeof(char));

    if( (!sLName[iPos]) )
    {
        printf("Allocation failed!");
        exit(4);
    }

    ch = 0;
    charCounter = 0;

    while (ch != '\n')
    {
        ch = getchar();

        if(ch == '\n')
        {
            break;
        }

        sLName[iPos][charCounter] = ch;
        charCounter++;
        sLName[iPos] = (char *)realloc(sLName[iPos], (charCounter+1) * sizeof(char) );

        if( (!sLName[iPos]) )
        {
            printf("Reallocation failed!");
            exit(5);
        }
    }

    sLName[iPos][charCounter] = '\0';

    printf("Enter age: ");
    scanf("%d", &iAge[iPos]);

    iNum[iPos] = (iPos+1);

    iPos++;
    iCount++;

    *pos = iPos;
}

void printContestants(char **sFName, char **sLName, int *iAge, int *iNum, int iPos)
{
    printf("--LIST OF CONTESTANTS--\n");
    
    for(int i = 0; i < iPos; i++)
    {
        printf("\nName: %s %s", sFName[i], sLName[i]);
        printf("\nAge: %d", iAge[i]);
        printf("\nContestant number: %d\n", iNum[i]);
    }
}

void deallocateString(char **sFName, char **sLName, int iPos)
{
    for(int i = 0; i < iPos; i++)
    {
        free(sFName[i]);
        free(sLName[i]);
    }
}