// Задача 5. Дефинирайте структура с 4 полета (int. char[10], double, enum),
// направете масив от 20 структури и ги попълнете. Изведете масива от
// структури на стандартния изход в CSV формат.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum state{
    Dead,
    Alive
};

struct CSV{
    int m_iNumber;
    char m_sName[10];
    double m_dHealth;
    enum state m_State;
};

typedef struct CSV CSV;

int main()
{
    CSV file[20];
    FILE *fp;
    char filename[] = "structs20.csv";

    srand(time(0));

    if( ( fp = fopen(filename, "w+") ) == NULL )
    {
        printf("Cannot create file!");
        return -1;
    }

    for(int i = 0; i < 20; i++)
    {
        file[i].m_iNumber = i+1;
        strcpy(file[i].m_sName, "Player");
        file[i].m_dHealth = rand() % 11;
        if(file[i].m_dHealth == 0)
        {
            file[i].m_State = Dead;
        }
        else
        {
            file[i].m_State = Alive;
        }
    }

    for(int i = 0; i < 20; i++)
    {
        fprintf(fp, "%s, %d, %.3lf, %d\n", file[i].m_sName, file[i].m_iNumber, file[i].m_dHealth, file[i].m_State);
    }

    fclose(fp);

    return 0;
}