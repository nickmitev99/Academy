// Задача 3. Напишете програма, която калкулира разликата на два времеви
// периода, изразени във векове, години, месеци, дни, минути, секудни.
// Принтирайте изходните периоди и резултата.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 2

typedef struct{
    int century;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}tm;

void setTime(tm *p, int size);
void printTime(tm *p, int size);
void normaliseTime(tm* p, int size);
void printDifference(tm *p);
void subtractTime(tm *pF, tm *pT, int size);
void ifLessThanZero(int *num);

int main()
{
    tm *time = calloc(SIZE, sizeof(tm));

    tm *res = calloc(1 ,sizeof(tm));

    setTime(time, SIZE);
    normaliseTime(time, SIZE);

    system("cls");

    printf("\nPrinting time 1 and 2:\n");
    printTime(time, SIZE);

    subtractTime(time, res, SIZE);
    normaliseTime(res, 1);

    printf("\nTime diffrence:\n");
    printTime(res, 1);

    return 0;
}

void setTime(tm *p, int size)
{

    for(int i = 0; i < size; i++)
    {
        int time = 0;

        printf("Entering time period %d\n", i+1);
        printf("Enter centuries: ");
        scanf("%d", &time);

        p[i].century += time;

        printf("Enter years: ");
        scanf("%d", &time);

        p[i].year += time;

        printf("Enter months: ");
        scanf("%d", &time);

        p[i].month += time;

        printf("Enter days: ");
        scanf("%d", &time);

        p[i].day += time;

        printf("Enter hours: ");
        scanf("%d", &time);

        p[i].hour += time;

        printf("Enter minutes: ");
        scanf("%d", &time);

        p[i].minute += time;

        printf("Enter seconds: ");
        scanf("%d", &time);

        p[i].second += time;
    }
}

void normaliseTime(tm* p, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(p[i].second >= 60)
        {
            p[i].minute += (p[i].second / 60);
            p[i].second %= 60;
        }

        if(p[i].minute >= 60)
        {
            p[i].hour += (p[i].minute / 60);
            p[i].minute %= 60;
        }
        
        if(p[i].hour >= 24)
        {
            p[i].day += (p[i].hour / 24);
            p[i].hour %= 24;
        }

        if(p[i].day >= 31)
        {
            p[i].month += (p[i].day / 31);
            p[i].day %= 31;
        }

        if(p[i].month >= 12)
        {
            p[i].year += (p[i].month / 12);
            p[i].month %= 12;
        }

        if(p[i].year >= 100)
        {
            p[i].century += (p[i].year / 100);
            p[i].year %= 100;
        }
    }
}

void printTime(tm *p, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\n%d centuries %d years %d months %d days ", p[i].century, p[i].year, p[i].month, p[i].day);
        printf("%d hours %d minutes %d seconds\n", p[i].hour, p[i].minute, p[i].second);
    }
}

void subtractTime(tm *pF, tm *pT, int size)
{
    int i = 0;
    
    if(pF[i+1].second > pF[i].second)
    {
        --pF[i].minute;
        pF[i].second += 60;
    }
    
    if(pF[i+1].minute > pF[i].minute)
    {
        --pF[i].hour;
        pF[i].minute += 60;
    }

    if(pF[i+1].hour > pF[i].hour)
    {
        --pF[i].day;
        pF[i].hour += 24;
    }
    
    if(pF[i+1].day > pF[i].day)
    {
        --pF[i].month;
        pF[i].day += 31;
    }

    if(pF[i+1].month > pF[i].month)
    {
        --pF[i].year;
        pF[i].month += 12;
    }
    
    if(pF[i+1].year > pF[i].year)
    {
        --pF[i].century;
        pF[i].year += 100;
    }
    
    pT->second += pF[i].second - pF[i+1].second;
    pT->minute += pF[i].minute - pF[i+1].minute;
    pT->hour += pF[i].hour - pF[i+1].hour;
    pT->day += pF[i].day - pF[i+1].day;
    pT->month += pF[i].month - pF[i+1].month;
    pT->year += pF[i].year - pF[i+1].year;
    pT->century += pF[i].century - pF[i+1].century;
}