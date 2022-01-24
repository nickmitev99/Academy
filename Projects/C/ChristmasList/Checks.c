#include "Checks.h"

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

//Checks Deptor Balance and sets which file to go and which message to show
int setDeptorStatus(SDebtors **opaDebtors, int iDebtorsCount)
{
	int iDebtorID = 0;

	for (iDebtorID; iDebtorID < iDebtorsCount; iDebtorID++)
	{
		float fBalance = 0;		
		fBalance = opaDebtors[iDebtorID]->dAmountDue - opaDebtors[iDebtorID]->dAmountPayed;
		// printf("%s: %f\n", opaDebtors[iDebtorID]->strName, fBalance);

		if (fBalance <= 0)
		{
			opaDebtors[iDebtorID]->oStatus = FILENICE;
			if (fBalance < 0)
			{
				opaDebtors[iDebtorID]->oMessage = GENEROUS;
			}
			else
			{
				opaDebtors[iDebtorID]->oMessage = NICE;
			}
		}
		else
		{
			opaDebtors[iDebtorID]->oStatus = FILENAUGHTY;
			if (fBalance <= NAUGHTYLIMIT)
			{
				opaDebtors[iDebtorID]->oMessage = NAUGHTY;
			}
			else
			{
				if (fBalance <= VERYNAUGHTYLIMIT)
				{
					opaDebtors[iDebtorID]->oMessage = VERY_NAUGHTY;
				}
				else
				{
					opaDebtors[iDebtorID]->oMessage = BAD;
				}
			}
		}
	}

	return SUCCESS;
}

//checks name for errors
int checkName(char *strName)
{
	if (strName == NULL)
	{
		return ERRNONAME; 
	}

	if (!checkNameMASK(strName))
	{
		return ERRINVNAME; 
	}

	return SUCCESS;
}

int checkNameMASK(char *strName)
{
	int iNameSize = strlen(strName);
	VALIDATION eName = TRUE;

	if(*strName == '\0')
	{
		return FALSE;
	}

	while (*strName)
	{
		if (!IsValidCharacter(strName))
		{
			eName = FALSE;
		}

		strName++;
	}

	return eName;
}

//Checks whether a character is valid for name
int IsValidCharacter(char *cChar)
{
	if (((*cChar >= 'a') && (*cChar <= 'z')) || ((*cChar >= 'A') && (*cChar <= 'Z')) || (*cChar == ' '))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//Checks if a file is opened
int checkIfOpened(FILE *fp)
{
	if (!fp)
	{
		return NULL_FILE;
	}
	else
	{
		return SUCCESS;
	}
}

//Check if a file is closed
int checkIfClosed(FILE *fp)
{
	if (fclose(fp) == EOF)
	{
		return NOT_CLOSED;
	}
	else
	{
		return SUCCESS;
	}
}

void initLog(FILE **fpLog)
{
	time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  fprintf (*fpLog, "Run from %s", asctime (timeinfo) );
}

//check if read string is valid float number 
int checkNumber(char *strNum)
{
  int iDotCounter = 0;

  if(*strNum == '\0')
  {
    return ERRORINVNUMBER;
  }

  while (*strNum)
  {
    if (((*strNum >= 48) && (*strNum <= 57)) || (*strNum == DOT))
    {
      if (*strNum == DOT)
      {
        iDotCounter++;
      }
    }
    else
    {
      return ERRORINVNUMBER;
    }

    strNum++;
  }

  if (iDotCounter > 1)
  {
    return ERRORINVNUMBER;
  }

  return SUCCESS;
}

// checks if the debtor is already in array of structs, returns index of found existing match
int checkIfExists(SDebtors **opaDebtors, int iDebtorsCount, char *sBuff)
{		
  for (int j = 0; j < iDebtorsCount; j++)
  {
	 lowerString(opaDebtors[j]->strName);
	 lowerString(sBuff);

    if ((strcmp(opaDebtors[j]->strName, sBuff)) == 0)
    {
      return j;
    }
  }

  return NOT_EXIST;
}

void lowerString(char *strTarget)
{
	for ( ; *strTarget; ++strTarget) 
	{
		*strTarget = tolower(*strTarget);
	}
}
