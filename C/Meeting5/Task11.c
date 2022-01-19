/*Задача 18. Довършете задачата за кемперите от миналия път като добавите
променлива , в която да се събират парите , които клиент ът дължи на компанията .
Принтирайте резултата . Питайте клиента дали иска още налични продукти
*/

#include <stdio.h>
#include <stdlib.h>

void buyCaravan(int *iCaravanCount, float *fClientDue, float *fCaravanPrice);
void buyCamper(int* iCamperCount, float* fClientDue, float* fCamperPrice);

int main(void)
{
    int iCaravanCount = 3, iCamperCount = 3, iChoice = 0, iChoice2 = 0;
    float fCaravanPrice = 90.0, fCamperPrice = 100.0, fClientDue = 0.0;

    do
    {
        system("cls");
        printf("--Welcome--\n");
        printf("What would you like to choose?\n");
        printf("1. Hire a Caravan.\n");
        printf("2. Hire a Camper.\n");
        printf("3. Check bill.\n");
        printf("4. Exit.\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                while(1)
                {
                    system("cls");
                    buyCaravan(&iCaravanCount, &fClientDue, &fCaravanPrice);

                    printf("Would you like to buy another caravan? \n(Press 1 for NO, anything else for YES)");
                    scanf("%d", &iChoice2);

                    if(iChoice2 == 1)
                    {
                        break;
                    }
                }

                break;

            case 2:
                while(1)
                {
                    system("cls");
                    buyCamper(&iCamperCount, &fClientDue, &fCamperPrice);

                    printf("Would you like to buy another camper? \n(Press 1 for NO, anything else for YES)");
                    scanf("%d", &iChoice2);

                    if(iChoice2 == 1)
                    {
                        break;
                    }
                }

                break;
            
            case 3:
                system("cls");
                printf("You have %.2f$ due.\n", fClientDue);
                system("pause");
                break;

            case 4:
                system("cls");
                return 0;

            default:
                system("cls");
                printf("Ivalid option! Please press a key from 1-3.\n");
        }
    } while (iCaravanCount >= 0 && iCamperCount >= 0);
    
    return 0;
}

void buyCaravan(int *iCaravanCount, float *fClientDue, float *fCaravanPrice)
{
    if(*iCaravanCount > 0)
    {
        (*iCaravanCount)--;
    }
                
    else
        {
            printf("We are sorry! We don't have anymore Caravans available. Please try again later.\n");
            return;
        }

    *fClientDue += *fCaravanPrice;

    printf("You have succesfully hired a caravan. You now have %.2f$ due.\n", *fClientDue);
}

void buyCamper(int* iCamperCount, float* fClientDue, float* fCamperPrice)
{
    if(*iCamperCount > 0)
        {
            (*iCamperCount)--;
        }

    else
        {
            printf("We are sorry! We don't have anymore Campers available. Please try again later.\n");
            return;
        }
                
    *fClientDue += *fCamperPrice;

    printf("You have succesfully hired a camper. You now have %.2f$ due.\n", *fClientDue);
}