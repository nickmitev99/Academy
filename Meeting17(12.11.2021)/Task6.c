// Задача 6. Използвайки предната задача, напишете програма, която да чете
// от стандартния вход CSV формат на описаната структура и да попълва
// масив от 20 структури. Пример: a.exe < structs20.csv

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum state{
    Dead,
    Alive
};

struct CSV{
    int m_Number;
    char m_Name[10];
    double m_Health;
    enum state m_State;
};

typedef struct CSV CSV;

int main(char argc, char *argv[])
{
    CSV file[20];

    for(int i = 0; i < 20; i++)
    {
        fscanf(stdin, "%[^,], %d, %lf, %d\n", file[i].m_Name, &file[i].m_Number, &file[i].m_Health, &file[i].m_State);
    }
   
    for (int i = 0; i < 20; i++)
    {
        printf("\n%s: %d\nHealth: %.3lf\nStatus:", file[i].m_Name, file[i].m_Number, file[i].m_Health);

        switch(file[i].m_State)
        {
            case Alive:
                printf(" Alive\n");
                break;
            
            case Dead:
                printf(" Dead\n");
                break;
        }
    }

    return 0;
}