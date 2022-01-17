#include <iostream>

int* paiApply(int *aiArr1, const int &iArr1sz, int *aiArr2, const int &iArr2sz);
void displayArray(const int* aiArr, const int& iArrSz);

int main(void)
{
  int aiArr1[] = { 1, 2, 3 };
  int aiArr2[] = { 10, 20 };
  int *paiArr3 = nullptr;

  int iArr1sz = sizeof(aiArr1)/sizeof(*aiArr1);
  int iArr2sz = sizeof(aiArr2)/sizeof(*aiArr2);
  int iArr3sz = iArr1sz * iArr2sz;

  paiArr3 = paiApply(aiArr1, iArr1sz, aiArr2, iArr2sz);

  displayArray(paiArr3, iArr3sz);

  delete [] paiArr3;

  return 0;
}

int* paiApply(int *aiArr1, const int &iArr1sz, int *aiArr2, const int &iArr2sz)
{
  int *paiResult = new int[iArr1sz * iArr2sz];

  for(int i = 0; i < iArr2sz; i++)
  {
    for(int j = 0; j < iArr1sz; j++)
    {
      int iIndex = (j+i) + (i*2);

      paiResult[iIndex] = aiArr1[j] * aiArr2[i];
    }
  }

  return paiResult;
}

void displayArray(const int* aiArr, const int& iArrSz)
{
  for(int i = 0; i < iArrSz; i++)
  {
    std::cout << "Array member " << i << ": "  << aiArr[i] << std::endl;
  }
}