// Задача 3. Да се построи наредено двоично дърво за
// търсене чрез последователно добавяне на следните
// върхове:
// а) 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13
// б) 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65
// в) 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81
// г) 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4
// д) 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14
// Да се сравнят получените дървета. Какви изводи могат
// да се направят?

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
int* createArray(int *iAmount);

int main()
{
  int iAmount = 0;    //FOR THE EXAMPLES, THE SIZE OF THE ARRAY IS 13
  int iValue = 0;
  int *piaElements = NULL;
  pSTree oTree = NULL;

  piaElements = createArray(&iAmount);

  for(int i = 0; i < iAmount; i++)
  {

    createTree(piaElements[i], &oTree);
  }

  displayTree(oTree);

  deleteTree(oTree);

  free(piaElements);

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
  static int iLevel = 0;

  if (oTree != NULL)
  {
    iLevel++;
    displayTree(oTree->left);

    for(int i = 0; i < iLevel; i++)
    {
      printf("   ");
    }

    printf("%d\n", oTree->iData);
    
    displayTree(oTree->right);
    iLevel--;
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

int* createArray(int *iAmount)
{
  int *piaElements = NULL;
  int iSize = 0;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &iSize);

  *iAmount = iSize;

  piaElements = (int*)malloc(iSize * sizeof(int));

  if(piaElements == NULL)
  {
    return NULL;
  }

  printf("Enter the elements: ");

  for(int i = 0; i < iSize; i++)
  {
    scanf("%d,", &piaElements[i]);
  }

  return piaElements;
}