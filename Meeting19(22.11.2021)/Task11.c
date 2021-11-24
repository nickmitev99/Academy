// Задача 11. Напишете функциите като макроси:
// 1. Функция AVG(x, y), която смята средното аритметично на две подадени 
// като параметър числа.
// 2. Функция AVG, която смята средното аритметично на числата от 
// определен диапазон.
// 3. Напишете функцията повдигане на степен, която повдига х на степен у
// 4. Напишете функцията TOUPPER, която прави малката буква а в голяма А
// 5. Напишете функцията DISP((f), (x)), която показва резултата от функции 
// връщащи double като корен квадратен.  DISP(sqrt, 3.0)
// Макрото трябва да се експандне до printf(“sqrt (%g) = %g\n”, 3.0, sqrt(3.0));

#include <stdio.h>
#include <math.h>

#define AVG(x, y) ((x) + (y)) / 2

#define TOUPPER(x) (x) -= 32

#define AVG2(x, y, avg) int i = 0; \
                        for(i = 0 ; i <= (y) - (x); i++) \
                        { avg += ( (x) + i ); } \
                        avg /= i; \
                        printf("\n%f", avg);

#define POW(x, y) int temp = (x); \
                    for(int i = 1; i < (y); i++) \
                    { (x) *= temp; } \
                    if( (y) == 0 ) { (x) = 1; }\
                    printf("\n%lf", x)

#define DISP(f, x) printf("\nsqrt(%g) = %g", (x), f(x));
              
int main()
{
    float fRes = 0;
    float fNumA = 0, fNumB = 0;
    char cChar = 'a';

    printf("\n--Function AVG--\n");
    printf("Enter the first number: ");
    scanf("%f", &fNumA);

    printf("Enter the second number: ");
    scanf("%f", &fNumB);

    printf("%f\n", AVG(fNumA, fNumB));


    printf("\n--Function AVG2--\n");
    printf("Enter the first number: ");
    scanf("%f", &fNumA);

    printf("Enter the second number: ");
    scanf("%f", &fNumB);

    AVG2(fNumA, fNumB, fRes);


    printf("\n--Function POW--\n");
    printf("Enter the first number: ");
    scanf("%f", &fNumA);

    printf("Enter the second number: ");
    scanf("%f", &fNumB);

    POW(fNumA, fNumB);

    fflush(stdin);

    printf("\n--Function TOUPPER--\n");
    printf("Enter a char: ");
    scanf("%c", &cChar);

    fflush(stdin);

    printf("\n%c", TOUPPER(cChar));


    printf("\n--Function DISP--\n");
    printf("Enter a number: ");
    scanf("%f", &fNumA);

    DISP(sqrt, fNumA);

    return 0;
}