// Задача 4. Напишете тип за дата, използвайки битови полета. Направете
// функция, която извежда дата, използвайки новия тип. Направете функция,
// която валидира датата.

#include <stdio.h>

struct Time{
    unsigned int m_uiDay : 5;
    unsigned int m_uiMonth : 4;
    unsigned int m_uiYear : 11;
};

enum stateOfDate{
    Invalid,
    Valid
};

typedef struct Time Time;
typedef enum stateOfDate stateOfDate;

void setDate(Time *date);
void printDate(Time *date);
stateOfDate validateDate(Time* date);

int main()
{
    Time date;

    setDate(&date);

    if(validateDate(&date) == Valid)
    {
        printf("\nThe date is valid!");
        printDate(&date);
    }
    else
    {
        printf("\nThe date is invalid!");
    }

    return 0;
}

void setDate(Time *date)
{
    int iDay = 0, iMonth = 0, iYear = 0;

    printf("Enter a year: ");
    scanf("%d", &iYear);

    printf("Enter a month: ");
    scanf("%d", &iMonth);

    printf("Enter a day: ");
    scanf("%d", &iDay);

    if(iYear <= 2047)
    {
        date->m_uiYear = iYear;
    }

    if(iMonth <= 15)
    {
        date->m_uiMonth = iMonth;
    }
    else
    {
        date->m_uiMonth = 0;
    }

    if(iDay <= 31)
    {
        date->m_uiDay = iDay;
    }
    else
    {
        date->m_uiDay = 0;
    }

}

void printDate(Time* date)
{
    printf("\nDate (D/M/Y): %02d/%02d/%d", date->m_uiDay, date->m_uiMonth, date->m_uiYear);
}

stateOfDate validateDate(Time* date)
{
    stateOfDate eStatus = Invalid;
    int iConditionMonth = date->m_uiMonth == 1 || date->m_uiMonth == 3 || date->m_uiMonth == 5 || 
    date->m_uiMonth == 7 || date->m_uiMonth == 8 || date->m_uiMonth == 10 || date->m_uiMonth == 12;
    int iLeapYear = date->m_uiYear % 4;

    if(date->m_uiMonth > 12)
    {
        date->m_uiMonth = 0;
    }

    if(!iConditionMonth)
    {
        if(!iLeapYear && date->m_uiMonth == 2)
        {
            if(date->m_uiDay > 29)
            {
                date->m_uiDay = 0;
            }
        }
        else if(iLeapYear && date->m_uiMonth == 2)
        {
            if(date->m_uiDay > 28)
            {
                date->m_uiDay = 0;
            }
        }
        else
        {
            if(date->m_uiDay > 30)
            {
                date->m_uiDay = 0;
            }
        }
    }

    if( (date->m_uiYear != 0) && (date->m_uiMonth != 0) && (date->m_uiDay != 0) )
    {
        eStatus = Valid;
    }

    return eStatus;
}