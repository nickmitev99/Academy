// Задача 5. Напишете макрос с един параметър, който печата 
// съобщение, само при дефиниран макрос DEBUG. Ако DEBUG не е 
// дефиниран, не печата нищо.

#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG
#define PRINT(x) printf("%s", x)
    
#else
#define PRINT(x)

#endif

    PRINT("If debug is defined, this will print");

    return 0;
}