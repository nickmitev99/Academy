/*
Задача 5. Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF. Текстът има букви и цифри.
Принтирайте с putchar() само въведените букви. Използвайте
условните оператори, за да принтирате с putchar() само малките
букви от латинската азбука а - z и големите букви A-Z.
*/

#include <stdio.h>

int main()
{
    char cChar = 0;
    
    while(cChar != EOF)
    {
        cChar = getchar();

        if( (cChar >= 'a') && (cChar <= 'z') )
        {
            putchar(cChar);
        }

        else if( (cChar >= 'A') && (cChar <= 'Z') )
        {
            putchar(cChar);
        }
    }

    return 0;
}