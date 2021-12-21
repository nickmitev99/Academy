// Задача 5. Напишете програма, която сравнява два файла, като отпечатва първия ред, на който
// има разлика между двата файла.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define STRING_SIZE 200

void compareFiles(FILE *fp1, FILE *fp2);

int main()
{
    FILE *fp1 = fopen("File1.txt", "r");
    FILE *fp2 = fopen("File2.txt", "r");

    if(!fp1 || !fp2)
    {
        perror("ERROR: ");
        exit(errno);
    }

    compareFiles(fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}

void compareFiles(FILE *fp1, FILE *fp2)
{
    char strBuffer1[STRING_SIZE] = { 0 };
    char strBuffer2[STRING_SIZE] = { 0 };
    int iLineCounter = 1;

    while( (!feof(fp1)) && (!feof(fp2)) )
    {
        fgets(strBuffer1, STRING_SIZE, fp1);
        fgets(strBuffer2, STRING_SIZE, fp2);

        if(strcmp(strBuffer1, strBuffer2))
        {
            fprintf(stderr, "FILES DON'T MATCH AT LINE %d!\n", iLineCounter);
            return;
        }

        iLineCounter++;
    }

    printf("The files are identical!\n");
}