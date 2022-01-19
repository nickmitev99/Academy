// Задача 8. Напишете собствен тип за структура node, съдържаща един член
// от тип int и един указател към тип самата структура. Заделете динамично
// памет за масив от 10 елемента от тази структура с malloc. За всеки елемент
// от масива попълнете цялото число с неговия пореден номер. Принтирайте
// резултатите.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct node{
    int value;
    struct node *next; 
};

typedef struct node node_t;

void setList(node_t **pHead, int iNum);
void printList(node_t *pHead);
void freeMem(node_t *pHead);

int main()
{
    node_t *node = NULL;

    for(int i = 1; i <= SIZE; i++)
    {
        setList(&node, i);
    }

    printList(node);

    freeMem(node);

    return 0;
}

void setList(node_t **pHead, int iNum)
{
    node_t *pNew = (node_t*)malloc(sizeof(node_t)); 
    node_t *pCurr = NULL;

    pNew->value = iNum;
    pNew->next = NULL;

    if(*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        pCurr = *pHead;

        while(pCurr->next != NULL)
        {
            pCurr = pCurr->next;
        }
        
        pCurr->next = pNew;
    }
}

void printList(node_t *pHead)
{
    node_t *pCurr = pHead;

    while(pCurr != NULL)
    {
        printf("%d -> ", pCurr->value);
        pCurr = pCurr->next;
    }
    printf("NULL\n");
}

void freeMem(node_t *pHead)
{
    node_t *pCurr = NULL;

    while(pHead != NULL)
    {
        pCurr = pHead->next;
        free(pHead);
        pHead = pCurr;
    }
}