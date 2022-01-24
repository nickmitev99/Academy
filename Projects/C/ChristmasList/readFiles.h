#ifndef READ_FILES_H
#define READ_FILES_H

#include "Checks.h"

#define INVREADERR "Error in function readFromFiles: INVOICES contains unusable information"
#define PAYREADERR "Error in function readFromFiles: PAYMENTS contains unusable information"
#define FILECLERR "\nError in function readFromFiles: The files couldn't be closed! Exiting...\n"
#define FILEOPERR "\nError in function readFromFiles: The files couldn't be opened! Exiting...\n"


void clearBuffer(char *strBuff);
void separateInput(char *strSource, char *strBuff, char *strNumBuff);
SDebtors **readFromFiles(int *iDebtorsCount, FILE **fpLog);

#endif //READ_FILES_H
