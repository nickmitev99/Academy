// Задача 2. Напишете програма, която събира две дистанции, които са
// изразени в километри, метри, сантиметри. Дистанциите трябва да бъдат
// въведени от потребителя. Принтирайте изходните и резултатната
// дистанция.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int distanceKM;
    int distanceM;
    int distanceCM;
}distance;

void setDistance(distance *p, int size);
void printDistance(distance *p, int size);
void combineDist(distance *pF, distance *pT, int size);

int main()
{
    distance *dist;
    distance *res;
    int iSize = 2;

    dist = (distance*) malloc(iSize * sizeof(distance));
    res = (distance*) malloc(sizeof(distance));

    memset(dist, 0, iSize * sizeof(distance));
    memset(res, 0, sizeof(distance));

    setDistance(dist, iSize);

    combineDist(dist, res, iSize);

    printf("\nPrinting distance 1 and 2");
    printDistance(dist, iSize);

    printf("\nResulting distance: ");
    printDistance(res, iSize/iSize);

    free(dist);
    free(res);

    return 0;
}

void setDistance(distance *p, int size)
{
    int dist = 0;

    for(int i = 0; i < size; i++)
    {
        printf("Entering distance %d\n", i+1);
        printf("Enter distance in km: ");
        scanf("%d", &dist);

        p[i].distanceKM += dist;

        printf("Enter distance in m: ");
        scanf("%d", &dist);

        p[i].distanceM += dist;

        printf("Enter distance in cm: ");
        scanf("%d", &dist);

        p[i].distanceCM += dist;

        if(p[i].distanceCM >= 100)
        {
            p[i].distanceM += (p[i].distanceCM / 100);
            p[i].distanceCM %= 100;
        }

        if(p[i].distanceM >= 1000)
        {
            p[i].distanceKM += (p[i].distanceM / 1000);
            p[i].distanceM %= 1000;
        }
    }
}

void printDistance(distance *p, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\nDistance in km = %d", p[i].distanceKM);
        printf("\nDistance in m = %d", p[i].distanceM);
        printf("\nDistance in cm = %d\n", p[i].distanceCM);
    }
}

void combineDist(distance *pF, distance *pT, int size)
{
    for(int i = 0; i < size; i++)
    {
        pT->distanceKM += pF[i].distanceKM;
        pT->distanceM += pF[i].distanceM;
        pT->distanceCM += pF[i].distanceCM;
    }

    if(pT->distanceCM >= 100)
    {
        pT->distanceM += (pT->distanceCM / 100);
        pT->distanceCM %= 100;
    }

    if(pT->distanceM >= 1000)
    {
        pT->distanceKM += (pT->distanceM / 1000);
        pT->distanceM %= 1000;
    }
}