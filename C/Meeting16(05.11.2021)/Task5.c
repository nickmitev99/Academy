// Задача 5. Напишете произволна програма, която демонстрира уменията ви
// да боравите с указатели към структури. Нека декларираната от вас
// структура(и) съдържа указател към собствения си тип.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

struct Person{
    char *name;
    
    struct Person *nextPrs;
};

static struct Person *prsHead = NULL;

void insertPeople();
void deletePeople();
void display();

int main()
{
    int iCount;

    printf("Enter how many people you want to have: ");
    scanf("%d", &iCount);

    for(int i = 0; i < iCount; i++)
    {
        insertPeople();
    }

    display();

    while(prsHead != NULL)
    {
        deletePeople(prsHead);
    }

    return 0;
}

void insertPeople()
{
    int i = 0;
    char str[MAX] = { 0 };

    struct Person *prsNew = (struct Person*) malloc(sizeof(struct Person));
    memset(prsNew, 0, sizeof(prsNew));

    printf("\nEnter a name: ");
    scanf("%s", str);

    if(!prsNew)
    {
        printf("\nAllocation failed!");
        return;
    }

    prsNew->name = (char*)malloc(strlen(str));

    strcpy(prsNew->name, str);

    prsNew->nextPrs = prsHead;
    prsHead = prsNew;
}

void deletePeople()
{
    struct Person *prsCurr = prsHead;

    prsHead = prsHead->nextPrs;

    free(prsCurr);
}

void display()
{
    struct Person *it = prsHead;

    if(!it)
    {
        return;
    }

    while(it->nextPrs)
    {
        printf("\n%s is sitting next to %s", it->name, it->nextPrs->name);
        it = it->nextPrs;
    }
}