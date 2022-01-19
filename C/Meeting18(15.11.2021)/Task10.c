// Задача 10. Създайте структура диня с два елемента - диаметър и дебелина
// на кората заделете динамично с malloc() за масив от А на брой дини от сорт
// мелон и попълнете данните за диаметър между 15 и 140 см с функцията
// rand(), за всяка една диня в масива и дебелина на кората между 0.5 и 3.5
// см. Създайте структура диня с два елемента - диаметър и дебелина на
// кората заделете динамично с malloc() за масив от В на брой дини от сорт
// пъмпкин и попълнете данните за диаметър между 35 и 95 см с функцията
// rand(), за всяка една диня в масива и дебелина на кората между 0.3 и 0.9
// см. Намерете средната големина на динята и средната дебелина на кората
// и ги съпоставете с тези от втория масив. Изведете на екрана купчината от
// кой сорт е по добре да се купи.
// Изход: По-добре е да се купят ... дини с диаметър ... сантиметра и кора с
// дебелина D см вместо ... дини с диаметър ... см и дебелина на кората D1 см.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Watermelon{
    int diameter;
    float thickness;
};

typedef struct Watermelon t_Watermelon;
typedef t_Watermelon* t_PtrW;

void randomInt(int *iRand, int iLower, int iHigher);
void randomFloat(float *fRand, float fLower, float fHigher);

int main()
{
    int iPumpkinAmount = 0, iMelonAmount = 0;
    t_PtrW Melon = NULL, Pumpkin = NULL;
    float fMelonDiameter = 0, fPumpkinDiameter = 0, fMelonThickness = 0, fPumpkinThickness = 0;
    float fMelonValue = 0, fPumpkinValue = 0;

    printf("Enter the amount of melons: ");
    scanf("%d", &iMelonAmount);
    printf("Enter the amount of pumpkins: ");
    scanf("%d", &iPumpkinAmount);

    Melon = (t_PtrW)malloc(sizeof(t_Watermelon) * iMelonAmount);
    Pumpkin = (t_PtrW)malloc(sizeof(t_Watermelon) * iPumpkinAmount);
    
    srand(time(0));

    for(int i = 0; i < iMelonAmount; i++)
    {
        randomInt(&Melon[i].diameter, 15, 140);
        randomFloat(&Melon[i].thickness, 0.5, 3.5);

        fMelonDiameter += Melon[i].diameter;
        fMelonThickness += Melon[i].thickness;
    }

    for(int i = 0; i < iPumpkinAmount; i++)
    {
        randomInt(&Pumpkin[i].diameter, 35, 95);
        randomFloat(&Pumpkin[i].thickness, 0.3, 0.9);

        fPumpkinDiameter += Pumpkin[i].diameter;
        fPumpkinThickness += Pumpkin[i].thickness;
    }

    putchar('\n');

    for(int i = 0; i < iMelonAmount; i++)
    {
        printf("Melon%d:\t\t Diameter = %dcm\t Thickness = %.3fcm\n", i+1, Melon[i].diameter, Melon[i].thickness);
    }

    putchar('\n');

    for(int i = 0; i < iPumpkinAmount; i++)
    {
        printf("Pumpkin%d:\t Diameter = %dcm\t Thickness = %.3fcm\n", i+1, Pumpkin[i].diameter, Pumpkin[i].thickness);
    }

    fMelonDiameter /= iMelonAmount;
    fMelonThickness /= iMelonAmount;
    fPumpkinDiameter /= iPumpkinAmount;
    fPumpkinThickness /= iPumpkinAmount;

    fMelonValue = (fMelonDiameter) - (2 * (fMelonThickness));
    fPumpkinValue = (fPumpkinDiameter) - (2 * (fPumpkinThickness));

    if(fMelonValue > fPumpkinValue)
    {
        printf("\nIt's better to buy Melons with %.3f diameter and %.3f thickness ", fMelonDiameter, fMelonThickness);
        printf("than buying Pumpkins with %.3f diameter and %.3f thickness", fPumpkinDiameter, fPumpkinThickness);
    }

    else
    {
        printf("\nIt's better to buy Pumpkins with %.3f diameter and %.3f thickness ", fPumpkinDiameter, fPumpkinThickness);
        printf("than buying Melons with %.3f diameter and %.3f thickness", fMelonDiameter, fMelonThickness);
    }

    free(Melon);
    free(Pumpkin);

    return 0;
}

void randomInt(int *iRand, int iLower, int iHigher)
{
    if(iLower > iHigher)
    {
        int temp = iLower;
        iLower = iHigher;
        iHigher = iLower;
    }

    *iRand = ( rand() % (iHigher - iLower +1) ) + iLower;
}

void randomFloat(float *fRand, float fLower, float fHigher)
{
    if(fLower > fHigher)
    {
        int temp = fLower;
        fLower = fHigher;
        fHigher = fLower;
    }

    *fRand = ( (fHigher - fLower) * ( (float)rand() / RAND_MAX ) ) + fLower;
}