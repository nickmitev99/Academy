// Задача 10. Напишете макрос, който прави идентификатор на низ 
// (стринг)

#include <stdio.h>

#define tostr(x) #x

int main()
{
    printf("%s", tostr(String));

    return 0;
}