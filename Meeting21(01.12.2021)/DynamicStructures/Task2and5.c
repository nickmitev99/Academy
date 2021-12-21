// Задача 2. Напишете функция за добавяне на елемент в дървото
// рекурсивно с двоен указател, подаван като параметър:
// void insert(int x, struct tree **T)

// Задача 5. Да се напише рекурсивен вариант на функцията за обхождане
// на двоично дърво.

#include <stdio.h>
#include <stdlib.h>

struct STree{
  int iData;
  struct STree *left;
  struct STree *right;
};

typedef struct STree STree;
typedef STree* pSTree;

void insert(pSTree oNewNode, STree **oTree);
void createTree(int iValue, STree **oTree);
void displayTree(pSTree oTree);
void deleteTree(pSTree oTree);

int main()
{
  int iAmount = 0;
  int iValue = 0;
  pSTree oTree = NULL;

  printf("Enter the number of elements in the tree: ");
  scanf("%d", &iAmount);

  for(int i = 0; i < iAmount; i++)
  {
    printf("\nEnter element[%d]: ", i + 1);
    scanf("%d", &iValue);

    createTree(iValue, &oTree);
  }

  displayTree(oTree);

  deleteTree(oTree);

  return 0;
}

void insert(pSTree oNewNode, STree **oTree)
{
  if(*oTree == NULL)
  {
    *oTree = oNewNode;
  }
  else if((*oTree)->iData < oNewNode->iData)
  {
    insert(oNewNode, &(*oTree)->left);
  }
  else
  {
    insert(oNewNode, &(*oTree)->right);
  }
}

void createTree(int iValue, STree **oTree)
{
  pSTree oNewNode = (pSTree)malloc(sizeof(STree));

  if(oNewNode == NULL)
  {
    return;
  }
  else
  {
    oNewNode->iData = iValue;
    oNewNode->left = NULL;
    oNewNode->right = NULL;
    insert(oNewNode, oTree);
  }
}

void displayTree(pSTree oTree)
{
  if (oTree != NULL)
  {
    displayTree(oTree->left);

    printf("%d\n", oTree->iData);
    
    displayTree(oTree->right);
  }
}

void deleteTree(pSTree oTree)
{
  if(oTree == NULL)
  {
    return;
  }

  deleteTree(oTree->left);
  deleteTree(oTree->right);

  free(oTree);
}