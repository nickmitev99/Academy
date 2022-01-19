#include <stdio.h>

int main()
{
    int iSeconds = 60, iMinutes = 60, iHours = 24, iDays = 365, iLDays = 366, iYear = 0, iLYear = 0;

    iYear = iSeconds * iMinutes * iHours * iDays;
    iLYear = iSeconds * iMinutes * iHours * iLDays;

    printf("One year has %d seconds\n", iYear);
    printf("One leap year has %d seconds", iLYear);
    
    return 0;
}

/*Напишете програма, която изчислява броя на секундите в една
година.*/