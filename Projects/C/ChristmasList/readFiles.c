#include "readFiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//clears the buffer
void clearBuffer(char *strBuff)
{
  while (*strBuff)
  {
    *strBuff = 0;
    strBuff++;
  }
}

//divides a string by the SEMICOLON symbol into two parts
void separateInput(char *strSource, char *strBuff, char *strNumBuff)
{
  while (*strSource)
  {
    if (*strSource == SEMICOLON)
    {
      *strBuff = '\0';
      strSource++;
      break;
    }

    *strBuff = *strSource;
    strSource++;
    strBuff++;
  }

  while (*strSource)
  {
    if (*strSource == '\n')
    {
      *strNumBuff = '\0';
      break;
    }

    *strNumBuff = *strSource;
    strSource++;
    strNumBuff++;
  }
}
//reads both input files and fills the array of structs
SDebtors **readFromFiles(int *iDebtorsCount, FILE **fpLog)
{
  int iResult = 0;
  char strBuff[SIZEOFNAME] = { 0 };
  char strName[SIZEOFNAME] = { 0 };
  char strNum[SIZEOFNAME] = { 0 };
  SDebtors **opaDebtors = NULL;

  //reads INVOICES file
  FILE *fp = fopen("INVOICES", "r");

  if (checkIfOpened(fp) != SUCCESS)
  {
    fprintf(*fpLog, FILEOPERR);
    return NULL;
  }

  opaDebtors = (SDebtors **)malloc(sizeof(SDebtors *));

  while (!feof(fp))
  {
    clearBuffer(strNum);
    clearBuffer(strName);
    clearBuffer(strBuff);   

    fgets(strBuff, SIZEOFNAME, fp);

    separateInput(strBuff, strName, strNum);
    // printf("INV: Name %s Balance %s\n", strName, strNum);

    //skips invalid names
    if (checkName(strName) == ERRINVNAME)
    {
      fprintf(*fpLog, "%s\n", INVREADERR);
      fprintf(*fpLog, "\"%s\"\n", strBuff);
      continue;
    }
    //skips invalid sums
    if (checkNumber(strNum) == ERRORINVNUMBER)
    {
      fprintf(*fpLog, "%s\n", INVREADERR);
      fprintf(*fpLog, "\"%s\"\n", strBuff);
      continue;
    }
    
    iResult = checkIfExists(opaDebtors, *iDebtorsCount, strName);    

    //appends data to existing debtor
    if (iResult != NOT_EXIST)
    {
      opaDebtors[iResult]->dAmountDue += atof(strNum);
      continue;
    }

    //new debtor sequence
    opaDebtors[*iDebtorsCount] = (SDebtors *)calloc(1, sizeof(SDebtors));
    opaDebtors[*iDebtorsCount]->strName = (char *)calloc(1, strlen(strName));
    strcpy(opaDebtors[*iDebtorsCount]->strName, strName);

    opaDebtors[*iDebtorsCount]->dAmountDue = atof(strNum);

    (*iDebtorsCount)++;
    opaDebtors = realloc(opaDebtors, (*iDebtorsCount + 1) * sizeof(SDebtors)); 
  }  

  if (checkIfClosed(fp) != SUCCESS)
  {
    fprintf(*fpLog, FILECLERR);
    return NULL;
  }

  //reads Payments file
  fp = fopen("PAYMENTS", "r");
  if (checkIfOpened(fp) != SUCCESS)
  {
    fprintf(*fpLog, FILEOPERR);
    return NULL;
  }
  while (!feof(fp))
  {
    clearBuffer(strNum);
    clearBuffer(strName);
    clearBuffer(strBuff);   

    fgets(strBuff, SIZEOFNAME, fp);

    separateInput(strBuff, strName, strNum);
    // printf("PAYM: Name %s Balance %s\n", strName, strNum);

    if (checkName(strName) == ERRINVNAME)
    {
      fprintf(*fpLog, "%s\n", PAYREADERR);
      fprintf(*fpLog, "\"%s\"\n", strBuff);
      continue;
    }

    if (checkNumber(strNum) == ERRORINVNUMBER)
    {
      fprintf(*fpLog, "%s\n", PAYREADERR);
      fprintf(*fpLog, "\"%s\"\n", strBuff);
      continue;
    }

    iResult = checkIfExists(opaDebtors, *iDebtorsCount, strName);

    if (iResult != NOT_EXIST)
    {
      opaDebtors[iResult]->dAmountPayed += atof(strNum);
      continue;
    }

    opaDebtors[*iDebtorsCount] = (SDebtors *)calloc(1, sizeof(SDebtors));
    opaDebtors[*iDebtorsCount]->strName = (char *)calloc(1, strlen(strName));
    strcpy(opaDebtors[*iDebtorsCount]->strName, strName);

    opaDebtors[*iDebtorsCount]->dAmountPayed = atof(strNum);

    (*iDebtorsCount)++;
    opaDebtors = realloc(opaDebtors, (*iDebtorsCount + 1) * sizeof(SDebtors));
  }

  if (checkIfClosed(fp) != SUCCESS)
  {
    fprintf(*fpLog, FILECLERR);
    return NULL;
  }

  return opaDebtors;
}
