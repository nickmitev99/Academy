// Задача 1. Използвайте динамична реализация на стек за
// въвеждане на поредица от цели положителни числа и нейното
// извеждане върху екрана в обратен ред. За край на поредицата от
// клавиатурата се въвежда 0.

#include <stdio.h>
#include <stdlib.h>

struct SStack{
  int iData;
  struct SStack *oNextNode;
};

typedef struct SStack SStack;
typedef SStack* pSStack;

SStack *createNewNode(int iValue);
int isEmpty(SStack *oStack);
void push(SStack **oStack, int iValue);
int pop(SStack **oStack);
void printRecursive(pSStack oStack);
void printNormal(pSStack oStack);
void deleteStack(pSStack oStack);

int main()
{
  int iValue = 0;
  pSStack oStack = NULL;

  do
  {
    printf("Enter an element for the stack: ");
    scanf("%d", &iValue);

    push(&oStack, iValue);
  } while (iValue != 0);
  
  printf("\nPrinting the Stack:\n");

  printRecursive(oStack);

  deleteStack(oStack);

  return 0;
}

SStack *createNewNode(int iValue)
{
  pSStack oNewNode = (pSStack)malloc(sizeof(SStack));

  if(oNewNode == NULL)
  {
    return NULL;
  }  

  oNewNode->iData = iValue;
  oNewNode->oNextNode = NULL;

  return oNewNode;
}

int isEmpty(SStack *oStack)
{
  return !oStack;
}

void push(SStack **oStack, int iValue)
{
  pSStack oNewNode = createNewNode(iValue);
  oNewNode->oNextNode = *oStack;
  *oStack = oNewNode;
}

int pop(SStack **oStack)
{
  int iPopped = 0;
  if(isEmpty(*oStack))
  {
    return 0;
  }

  pSStack oTempNode = *oStack;

  *oStack = (*oStack)->oNextNode;
  
  iPopped = oTempNode->iData;
  free(oTempNode);

  return iPopped;
}

void printRecursive(pSStack oStack)
{
  if(oStack != NULL)
  {
    printRecursive(oStack->oNextNode);
    printf("%d\n", oStack->iData);
  }
}

void printNormal(pSStack oStack)
{
  pSStack oCurrentNode = oStack;

  while(oStack != NULL)
  {
    printf("%d\n", oCurrentNode->iData);
    oCurrentNode = oCurrentNode->oNextNode;
  }
}

void deleteStack(pSStack oStack)
{
    pSStack oTempNode = NULL;

    while(oStack)
    {
        pop(&oStack);
    }
}