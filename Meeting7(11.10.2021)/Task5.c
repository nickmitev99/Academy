/*
Упражнение 7.16.* Напишете функция void itob(int n, char s[], int b), която
преобразува цяло число n в низ s базиран на основа b.
Например itob( n, s[], 16) представя числото n като шеснадесетично число в
стринга s[].
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itob(int iNum, char *aArray, int iBase);
void reverseArray(char* aArray, int iStart, int iEnd);
void menu();

int main()
{
    int iChoice = 0;
    char aArray[100] = { 0 };
    int iEnd = 0, iStart = 0, iNum = 0, iBase = 0;

    system("cls");
    printf("Enter a number: ");
    scanf("%d", &iNum);

    system("cls");
    printf("--Number Converter--\n");
    printf("Choose the base you would like to convert to:\n");
    printf("1. Decimal\n");
    printf("2. Hexadecimal\n");
    printf("3. Octal\n");
    printf("4. Binary\n");
    printf("5. Exit\n");
    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case 1:
            {
                iBase = 10;
                itob(iNum, aArray, iBase);
                iEnd = (strlen(aArray) - 1);
                reverseArray(aArray, iStart, iEnd);
                printf("%d in decimal is: %s\n", iNum, aArray);
            }
            break;

        case 2:
            {
                iBase = 16;
                itob(iNum, aArray, iBase);
                iEnd = (strlen(aArray) - 1);
                reverseArray(aArray, iStart, iEnd);
                printf("%d in hexadecimal is: %s\n", iNum, aArray);
            }
            break;

        case 3:
            {
                iBase = 8;
                itob(iNum, aArray, iBase);
                iEnd = (strlen(aArray) - 1);
                reverseArray(aArray, iStart, iEnd);
                printf("%d in octal is: %s\n", iNum, aArray);
            }
            break;

        case 4:
            {
                iBase = 2;
                itob(iNum, aArray, iBase);
                iEnd = (strlen(aArray) - 1);
                reverseArray(aArray, iStart, iEnd);
                printf("%d in binary is: %s\n", iNum, aArray);
            }
            break;

        case 5:
            printf("Exiting...");
            return 0;

        default:
            printf("Invalid option! Please try again!");
            break;
    }

    return 0;
}

void itob(int iNum, char *aArray, int iBase)
{
    do
    {
        if( iBase == 10 )
        {
            *aArray += ( (iNum % 10) + '0');
            iNum /= 10;
        }

        if ( iBase == 16)
        {
            *aArray += (iNum % 16);

            if( (*aArray >= 10) && (*aArray <= 15) )
            {
                *aArray += 55;
            }

            else 
            {
                *aArray += '0';
            }

            iNum /= 16;
        }
        
        if ( iBase == 8)
        {
            *aArray += ( (iNum % 8) + '0');
            iNum /= 8;
        }

        if ( iBase == 2)
        {
            *aArray += ( (iNum % 2) + '0');
            iNum /= 2;
        }


        aArray++;
    } while (iNum != 0);
}

void reverseArray(char* aArray, int iStart, int iEnd)
{
    char cTemp = 0;

    for(iStart = 0; iStart < iEnd; iStart++, iEnd--)
    {
        
        cTemp = aArray[iStart];
        aArray[iStart] = aArray[iEnd];
        aArray[iEnd] = cTemp;
    }
}