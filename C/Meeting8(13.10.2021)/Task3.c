/*
Задача 3. Напишете програма, която преброява шпациите, табулациите и
новите редове.
*/
#include <stdio.h>

int main()
{
    char cChar = '0';
    int iCountN = 0, iCountS = 0, iCountT = 0;

    while(cChar != EOF)
    {
        cChar = getchar();

        if( cChar == '\n' )
        {
            iCountN++;
        }

        else if( cChar == ' ' )
        {
            iCountS++;
        }

        else if( cChar == '\t' )
        {
            iCountT++;
        }
    }

    printf("The space counter is: %d\n", iCountS);
    printf("The new line counter is: %d\n", iCountN);
    printf("The tabulation counter is: %d\n", iCountT);
   
    return 0;
}