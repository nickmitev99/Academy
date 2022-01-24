#ifndef WRITEFILES_H
#define WRITEFILES_H

#include "Checks.h"

#define MAX_MESSAGE_SIZE 512

int writeFiles(SDebtors **opaDebtors, int iDebtorsCount, EStatus oStatus, FILE **fpLog);
EStatus oCheckStatus(SDebtors *opDebtor);
int writeDebtor(SDebtors *opDebtor, FILE **fp, FILE **fpLog);
char* extractMessages(int iMsgPos, FILE **fpLog);
int countMessages(FILE *fp);

#endif //WRITEFILES_H