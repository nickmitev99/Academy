// Задача 3. Пренапишете горния код като работите с аритметика с указатели.

#include <stdio.h>

int main(int argc, char* argv[])
{
    while(argc-- > 1)
    {   
        printf("%s ", *(argv+argc) );
    }

    return 0;
}