#include <stdio.h>

int main(void)
{
    int iCaravanCount = 3, iCamperCount = 3, iChoice = 0;
    float fCaravanPrice = 90.0, fCamperPrice = 100.0, fClientDue = 0.0;

    do
    {
        printf("--Welcome--\n");
        printf("What would you like to choose?\n");
        printf("1. Hire a Caravan\n");
        printf("2. Hire a Camper\n");
        printf("3. Exit.\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                if(iCaravanCount > 0)
                {
                    iCaravanCount--;
                }
                
                else
                {
                    printf("We are sorry! We don't have anymore Caravans available. Please try again later.\n");
                    break;
                }

                fClientDue += fCaravanPrice;
                printf("You have succesfully hired a caravan. You now have %.2f$ due.\n", fClientDue);
                break;

            case 2:
                if(iCamperCount > 0)
                {
                    iCamperCount--;
                }

                else
                {
                    printf("We are sorry! We don't have anymore Campers available. Please try again later.\n");
                    break;
                }
                
                fClientDue += fCamperPrice;
                printf("You have succesfully hired a caravan. You now have %.2f$ due.\n", fClientDue);
                break;
            
            case 3:
                return 0;

            default:
                printf("Ivalid option! Please press a key from 1-3.\n");
        }
    } while (iCaravanCount >= 0 && iCamperCount >= 0);
    
    return 0;
}

/*Представете си, че имате фирма за отдаване на каравани и кемпери под
наем, за която трябва да разработите софтуер. Вие сте малка фирма и имате
общо 3 каравани на цена 90 лв. на ден и 3 кемпера на цена 100 лв. на ден.
Декларирайте променливи за броя на караваните, цената на караваните, броя на
кемперите и цената им. Направете меню, което пита клиента каравана или
кемпер ще иска. Направете променлива, в която да се събират парите, които
клиента дължи на компанията. Принтирайте резултата.*/