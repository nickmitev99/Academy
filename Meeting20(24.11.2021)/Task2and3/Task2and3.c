// Задача 2. Създайте test.txt файл в избрана от вас директория. Сложете
// някакви данни в него на латиница - име, поздрав, брой. Отворете файла с
// текстов редактор, за да се убедите, че данните са записани.

// Задача 3. Създайте test.txt файл в избрана от вас директория. Сложете
// някакви данни в него на латиница - име, поздрав, брой. Отворете файла за
// четене, като проверявате дали файла наистина е отворен. Използвайте
// fgetc() , която взема само един символ от файла. Направете while цикъл,
// за да изпишете всички символи, като проверявате за край на файл с EOF.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int main()
{
    FILE *fp = NULL;
    char cChar = 0, strInput[SIZE] = { 0 };

    if( ( fp = fopen("Task2and3.txt", "w+") ) == NULL)
    {
        printf("Can not open the file for input and output");
        return -1;
    }

    printf("Enter a name: ");
    scanf("%s", strInput);
    fprintf(fp, "%s, ", strInput);

    printf("Enter a greeting: ");
    scanf("%s", strInput);
    fprintf(fp, "%s, ", strInput);

    printf("Enter a number: ");
    scanf("%s", strInput);
    fprintf(fp, "%d", atoi(strInput));

    fseek(fp, SEEK_SET, 0);

    while(cChar != EOF)
    {
        cChar = fgetc(fp);
        putchar(cChar);
    }

    fclose(fp);

    return 0;
}