#include "writeFiles.h"
#include "readFiles.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int iResult = 0;
  int iCount = 0;
  SDebtors **opaDebtors = NULL;
  FILE *fpLog = fopen("Log", "w+");

  if (checkIfOpened(fpLog) != SUCCESS)
  {
    fprintf(fpLog, "Error in function main: LOG couldn't be opened! Exiting...\n");
    return NOT_CLOSED;
  }

  initLog(&fpLog);

  opaDebtors = readFromFiles(&iCount, &fpLog);

  setDeptorStatus(opaDebtors, iCount);

  iResult = writeFiles(opaDebtors, iCount, FILENICE, &fpLog);
  iResult = writeFiles(opaDebtors, iCount, FILENAUGHTY, &fpLog);  

  for (int i = 0; i < iCount; i++)
  {
    free(opaDebtors[i]->strName);
    free(opaDebtors[i]);
  }
  free(opaDebtors);

  if(checkIfClosed(fpLog) != SUCCESS)
  {
    fprintf(fpLog, "Error in function writeFiles: The files couldn't be created! Exiting...\n");
    return NOT_CLOSED;
  }

  return 0;
}

/*clock_t begin = clock();

...

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;*/