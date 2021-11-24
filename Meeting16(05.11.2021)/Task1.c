// Задача 1. Напишете програма, в която информацията да бъде съхранявана
// в структура, описваща автомобил. Входната информация трябва бъде
// въведена от потребителя, като напишете меню с въпроси към него.
// Принтирайте въведената информация за описание на автомобила.

#include <stdio.h>
#include <string.h>

typedef struct{
    char make[20];
    char model[10];
    float engine;
    float width;
    float height;
    int year;
    char color[20];
}automobile;

void printStruct(automobile* p);
void setStruct(automobile* p);

int main()
{
    automobile a;

    setStruct(&a);
    printStruct(&a);

    return 0;
}

void setStruct(automobile* p)
{
    printf("What is the make of the vehicle? ");
    scanf("%s", (p->make));

    printf("What is the model of the vehicle? ");
    scanf("%s", (p->model));

    printf("What is the engine size of the vehicle? ");
    scanf("%f", &(p->engine));

    printf("What is the width of the vehicle? ");
    scanf("%f", &(p->width));

    printf("What is the height of the vehicle? ");
    scanf("%f", &(p->height));

    printf("What year is the vehicle made? ");
    scanf("%d", &(p->year));

    printf("What is the color of the vehicle? ");
    scanf("%s", (p->color));
}

void printStruct(automobile* p)
{
    printf("\nMake: %s", (p->make));
    printf("\nModel: %s", (p->model));
    printf("\nEngine size: %.1f", (p->engine));
    printf("\nWidth: %.3f", (p->width));
    printf("\nHeight: %.3f", (p->height));
    printf("\nYear: %d", (p->year));
    printf("\nColor: %s", (p->color));
}