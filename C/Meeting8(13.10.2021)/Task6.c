/*
Задача 6.Използвайте функцията getchar(), с която въвеждате
текст от клавиатурата, докато не подадете ЕОF. Текстът има
букви и цифри. Пребройте колко са въведените букви и колко са
въведените цифри. Определeте броя на цифрите в стринга, като
използвате оператор continue.
*/

#include <stdio.h>

int main()
{
    char cChar = 0;
    int iCountN = 0, iCountL = 0;
    
    while(cChar != EOF)
    {
        cChar = getchar();

        if( ( (cChar >= 'a') && (cChar <= 'z') ) || ( (cChar >= 'A') && (cChar <= 'Z') ) )
        {
            iCountL++;
            continue;
        }

        else if( (cChar >= '0') && (cChar <= '9') )
        {
            iCountN++;
            continue;
        }
    }

    printf("Inputed letters: %d\n", iCountL);
    printf("Inputed numbers: %d\n", iCountN);


    return 0;
}