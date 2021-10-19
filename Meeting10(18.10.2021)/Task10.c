/*
Задача 10. Напишете функция void itob(int n, char s[], int b), която
преобразува цяло число n в низ s базиран на основа b.
Например itob( n, s[], 16) представя числото n като шеснадесетично число в
стринга s[].
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itob(int iNum, char *sStr, int iBase);
void reverse(char* sStr);
int menu();

int main()
{
    int isExit = 0;

    do
    {
        isExit = menu();
    } while (!isExit);

    system("cls");

    return 0;
}

int menu()
{
    char sStr[100] = { 0 };
    int iChoice = 0, iNum = 0;

    system("cls");
    printf("--Number Converter--\n");
    printf("Choose the base you would like to convert to:\n");
    printf("1. Decimal\n");
    printf("2. Hexadecimal\n");
    printf("3. Octal\n");
    printf("4. Binary\n");
    printf("5. Exit\n");
    scanf("%d", &iChoice);

    system("cls");
    if(iChoice != 5)
    {
        printf("Enter a number: ");
        scanf("%d", &iNum);
    }
    
    switch(iChoice)
    {
        case 1:
            {
                itob(iNum, sStr, 10);
                printf("%d in decimal is: %s\n", iNum, sStr);
                system("pause");
            }
            break;

        case 2:
            {
                itob(iNum, sStr, 16);
                printf("%d in hexadecimal is: %s\n", iNum, sStr);
                system("pause");
            }
            break;

        case 3:
            {
                itob(iNum, sStr, 8);
                printf("%d in octal is: %s\n", iNum, sStr);
                system("pause");
            }
            break;

        case 4:
            {
                itob(iNum, sStr, 2);
                printf("%d in binary is: %s\n", iNum, sStr);
                system("pause");
            }
            break;

        case 5:
            printf("Exiting...\n");
            system("pause");
            return 1;

        default:
            printf("Invalid option! Please try again!");
            break;
        
        return 0;
    }
}

void itob(int iNum, char *sStr, int iBase)
{
    char *temp = sStr;

    do
    {
        if( iBase == 10 )
        {
            *sStr += ( (iNum % 10) + '0');
            iNum /= 10;
        }
        else if ( iBase == 16)
        {
            *sStr += (iNum % 16);
            if( (*sStr >= 10) && (*sStr <= 15) )
            {
                *sStr += 55;
            }
            else 
            {
                *sStr += '0';
            }
            iNum /= 16;
        }
        else if ( iBase == 8)
        {
            *sStr += ( (iNum % 8) + '0');
            iNum /= 8;
        }
        else if ( iBase == 2)
        {
            *sStr += ( (iNum % 2) + '0');
            iNum /= 2;
        }

        sStr++;
    } while (iNum != 0);

    reverse(temp);
}

void reverse(char* sStr)
{
    char temp;

    for(int i = 0, j = strlen(sStr) - 1; i <= j; i++, j--)
    {
        temp = sStr[i];
        sStr[i] = sStr[j];
        sStr[j] = temp;
    }
}