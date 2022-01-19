// Задача 8. Намерете позицията си във файла, като използвате:
// long ftell(FILE *pfile);
// Преместете се няколко пъти напред и назад на различни позиции.

#include <stdio.h>

int main()
{
    FILE* fp = NULL;
    long int iPos = 0;

    if( ( fp = fopen("Task8.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);
    iPos = ftell(fp);

    printf("Position of the first character of the file is: %d\n", iPos);

    fseek(fp, 0, SEEK_END);
    iPos = ftell(fp);

    printf("Position of the last character of the file is: %d\n", iPos);

    fseek(fp, -7, SEEK_CUR);
    iPos = ftell(fp);

    printf("Current position -7 characters of the file is: %d\n", iPos);

    fclose(fp);

    return 0;
}