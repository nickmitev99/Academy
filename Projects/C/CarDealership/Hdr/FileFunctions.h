#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include "../Hdr/Dealership.h"

//FILE FUNCTIONS
int writeFile(SNode *opVehicles);
SNode *readFile();
int isEmpty(FILE *fp);
void initLog();
void addFuncNameToLog(char *strName);
void addStatusToLog(int iErrorCode);

#endif //FILES_H