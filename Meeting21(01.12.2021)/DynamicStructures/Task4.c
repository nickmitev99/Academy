// Задача 4. Да се изтрият в този ред върховете 1, 7, 12 и 14 от дървото на


#include <stdio.h>
#include <stdlib.h>

struct STree{
  int iData;
  struct STree *left;
  struct STree *right;
};

typedef struct STree STree;
typedef STree* pSTree;

pSTree insert(pSTree oTree, int iValue);
void createTree(int iValue, STree **oTree);
void displayTree(pSTree oTree);
void deleteTree(pSTree oTree);
pSTree minValue(pSTree oNode);
pSTree deleteElement(pSTree oTree, int iValue);

int main()
{
  int iValue = 0;
  int iaElements[] = { 6, 5, 3, 1, 10, 8, 7, 13, 11, 12, 14 };
  int iAmount = (sizeof(iaElements)/sizeof(*iaElements));
  pSTree oTree = NULL;

  for(int i = 0; i < iAmount; i++)
  {
    oTree = insert(oTree, iaElements[i]);
  }

  printf("\nFull tree:\n");
  displayTree(oTree);

  oTree = deleteElement(oTree, 1);

  printf("\nAfter deleting 1:\n");
  displayTree(oTree);

  oTree = deleteElement(oTree, 7);

  printf("\nAfter deleting 7:\n");
  displayTree(oTree);

  oTree = deleteElement(oTree, 12);

  printf("\nAfter deleting 12:\n");
  displayTree(oTree);

  oTree = deleteElement(oTree, 14);

  printf("\nAfter deleting 14:\n");
  displayTree(oTree);

  deleteTree(oTree);

  return 0;
}

pSTree newNode(int iValue) 
{
  pSTree oTemp = (pSTree)malloc(sizeof(STree));
  
  oTemp->iData = iValue;
  oTemp->left = NULL;
  oTemp->right = NULL;

  return oTemp;
}

pSTree insert(pSTree oTree, int iValue)
{
  if (oTree == NULL) 
  {
    return newNode(iValue);
  }

  if (iValue < oTree->iData)
  {
    oTree->left = insert(oTree->left, iValue);
  }
  else
  {
    oTree->right = insert(oTree->right, iValue);
  }

  return oTree;
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

pSTree deleteElement(pSTree oTree, int iValue)
{
    if (oTree == NULL)
        return oTree;
 
    if (iValue < oTree->iData)
        oTree->left = deleteElement(oTree->left, iValue);
    else if (iValue > oTree->iData)
        oTree->right = deleteElement(oTree->right, iValue);
    else {
        if (oTree->left == NULL) {
            pSTree oTemp = oTree->right;
            free(oTree);
            return oTemp;
        }
        else if (oTree->right == NULL) {
            pSTree oTemp  = oTree->left;
            free(oTree);
            return oTemp;
        }
 
        pSTree oTemp = minValue(oTree->right);
 
        oTree->iData = oTemp->iData;
 
        oTree->right = deleteElement(oTree->right, oTemp->iData);
    }
    return oTree;
}

pSTree minValue(pSTree oNode)
{
    pSTree oMin = oNode;
 
    while (oMin && oMin->left != NULL)
        oMin = oMin->left;
 
    return oMin;
}