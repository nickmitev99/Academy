// Задача 2. Напишете програма, която чете съобщение и го принтира в обратен
// ред.

#include <stdio.h>

int main(int argc, char* argv[])
{
    for (size_t i = argc-1; i > 0; i--)
    {
        printf("%s ", *(argv+i) );
    }

    return 0;
}