#ifndef CHECKS_H
#define CHECKS_H

#include "Debtors.h"
#include <stdio.h>

#define NAUGHTYLIMIT 10
#define VERYNAUGHTYLIMIT 50
#define SUCCESS 0
#define SIZEOFNAME 32
#define DOT 46
#define SEMICOLON 59

//ERRORCODES
#define NULL_FILE -41
#define ERRNONAME -42
#define ERRINVNAME -43
#define ERRORINVNUMBER -44
#define NOT_CLOSED -45
#define NOT_EXIST -46

typedef enum VALIDATION VALIDATION; 

enum VALIDATION
{
  FALSE,
  TRUE
};

int setDeptorStatus(SDebtors **opaDebtors, int iDebtorsCount);
int HandleSetDeptorStatus(SDebtors **opaDebtors,int iDebtorsCount);
int checkName(char *strName);
int checkNameMASK(char *strName);
int IsValidCharacter(char *cChar);
int checkIfOpened(FILE *fp);
int checkIfClosed(FILE *fp);
void initLog(FILE **fpLog);
int checkNumber(char *strNum);
int checkIfExists(SDebtors **opaDebtors, int iDebtorsCount, char *sBuff);
void lowerString(char *strTarget);

#endif //CHECKS_H
