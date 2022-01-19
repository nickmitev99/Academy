#ifndef DEBTORS_H
#define DEBTORS_H

typedef enum EStatus EStatus;
typedef enum EMessage EMessage;
typedef struct SDebtors SDebtors;

enum EStatus{
  FILENAUGHTY,
  FILENICE
};

enum EMessage{
  GENEROUS,
  NICE,
  NAUGHTY,
  VERY_NAUGHTY,
  BAD
};

struct SDebtors{
  char *strName;
  double dAmountDue;
  double dAmountPayed;
  EStatus oStatus;
  EMessage oMessage;
};

#endif //DEBTORS_H