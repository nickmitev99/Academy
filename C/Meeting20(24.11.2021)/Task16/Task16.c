// Задача 16. Напишете стандартната програма за Linux cat , която приема
// като аргументи от командния ред имена на файлове и изкарва
// съдържанието им на стандартния изход. Ако на програмата не са
// подадени никакви аргументи, то тя да изкара съдържанието подадено от
// стандартния вход на стандартния изход.

#include <stdio.h>
#include <string.h>

#define SIZE 200

int main(int argc, char *argv[])
{
    char sBuffer[SIZE] = { 0 };
    FILE* fp = NULL;

    if(argc == 1)
    {
        fprintf(stdout, "%s", argv[0]);
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            fp = fopen(argv[i], "r");

            fread(sBuffer, 200, 1, fp);
            printf("\n%s:\n%s\n", argv[i], sBuffer);

            memset(sBuffer, 0, SIZE);

            fclose(fp);
        }
    }

    return 0;
}