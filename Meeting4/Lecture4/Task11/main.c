#include <stdio.h>

int main()
{
    int iChoice;
    float fBalance = 0.0, fTomato = 4.5, fWheat = 1.8, 
    fYoghurt = 0.5, fIceCream = 0.6, fCandy = 1.5, fLollies = 0.15;

    while(1)
    {
        printf("--Welcome--\n");
        printf("Choose the products that you would like to buy:\n");
        printf("1. Tomatoes (1kg) for 4.5 BGN\n");
        printf("2. Wheat (1kg) for 1.8 BGN\n");
        printf("3. Yoghurt for 0.5 BGN\n");
        printf("4. IceCream for 0.6 BGN\n");
        printf("5. Candy (1kg) for 1.5 BGN\n");
        printf("6. Loli pop for 0.15 BGN\n");
        printf("7. Check total\n");
        printf("8. Exit\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                fBalance += fTomato;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 2:
                fBalance += fWheat;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 3:
                fBalance += fYoghurt;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 4:
                fBalance += fIceCream;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 5:
                fBalance += fCandy;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 6:
                fBalance += fLollies;
                printf("Your total balance is: %f BGN\n", fBalance);
                break;

            case 7:
                printf("Your total balance is: %f BGN\n", fBalance);
                break;
            
            case 8:
                return 0;

            default:
                printf("Invalid option! Press any key from 1-7.\n", fBalance);
                break;
        }
    }
}

/*Създайте С програма, която калкулира стойността на покупки в магазин за
хранителни стоки. Клиентът може да закупи различна комбинация от продукти. В
магазина има следните налични продукти и цени:
Домати- 4.5 лв.за килограм, Брашно 1.80 лв. за килограм,
Кисело мляко - 0.50 лв. за брой, Сладолед на фунийки 0.60 лв. броя
Бонбони 1.50 лв. за килограм, Близалки 0.15 лв. за брой.*/