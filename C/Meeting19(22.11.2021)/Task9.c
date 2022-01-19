// Задача 9. Напишете макрос, който свързва два идентификатора в 
// един общ (конкатениране на идентификатори)

#include <stdio.h>

#define merge(a, b) a##b
#define tostr(x) #x

int main()
{
    int merge(Long,Name) = 0;

    printf("Enter a value for %s: ", tostr(LongName));
    scanf("%d", &LongName);

    printf("\n%s = %d", tostr(LongName), LongName);

    return 0;
}