// Задача 14. Напишете програма, която премахва ред с определен
// номер от зададен файл. Реда, който трябва да се премахне да бъде
// въведен от потребителя. Принтирайте началния и резултатния
// файлове.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

int main()
{
    FILE* fp = NULL, *fp2 = NULL;
    char strOutput[SIZE] = { 0 };
    int iLineCount = 0, iDelete = 0, iFlag = 0;

    if( ( fp = fopen("Task14.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    if( ( fp2 = fopen("Temp.txt", "w+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    printf("Initial file:\n\n");
    fread(strOutput, SIZE, 1, fp);
    printf("%s\n", strOutput);

    fseek(fp, 0, SEEK_SET);

    printf("\nEnter the number of the line you would like to remove: ");
    scanf("%d", &iDelete);

    while(!feof(fp))
    {
        fgets(strOutput, SIZE, fp);
        iLineCount++;

        if(iLineCount != iDelete)
        {
            fprintf(fp2, "%s", strOutput);
        }
        else
        {
            iFlag = 1;
        }
    }

    fclose(fp);
    fclose(fp2);

    if(iFlag == 1)
    {
        printf("Line %d deleted!\n\n", iDelete);
    }
    else
    {
        printf("The file doesn't have a line with an index of %d\n\n", iDelete);
        return 0;
    }

    remove("Task14.txt");
    rename("Temp.txt", "Task14.txt");

    if( ( fp = fopen("Task14.txt", "r+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    printf("The file's new contents are: \n\n");

    memset(strOutput, 0, SIZE);

    fread(strOutput, SIZE, 1, fp);
    printf("%s", strOutput);

    fclose(fp);

    return 0;
}