#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Hdr/Dealership.h"
#include "../Hdr/FileFunctions.h"
#include "../Hdr/Validation.h"

//Used to store the linkedlist in a file
int writeFile(SNode *opVehicles)
{
  SNode *oTemp = opVehicles;
  int iFileStatus = 0;
  FILE *fpWrite = fopen("Files/VEHICLES", "w");

  iFileStatus = checkIfOpened(fpWrite);

  if(iFileStatus == NULL_FILE)
  {
    return NULL_FILE;
  }

  while(oTemp != NULL)
  {
    fprintf(fpWrite, "%s\n%s\n%s\n%f\n%lf\n", oTemp->m_oData.m_strVIN, oTemp->m_oData.m_strMake, oTemp->m_oData.m_strColor
, oTemp->m_oData.m_fEngine, oTemp->m_oData.m_dPrice);
    oTemp = oTemp->m_oNext;
  }

  iFileStatus = checkIfClosed(fpWrite);

  if(iFileStatus == NOT_CLOSED)
  {
    return NOT_CLOSED;
  }

  return SUCCESS;
}

//Used to extract the linked list from a file
SNode *readFile()
{
  int iFileStatus = 0;
  SNode *opVehicles = NULL;
  SNode *oCurr = NULL;
  SNode *oNew = NULL;
  FILE *fpRead = fopen("Files/VEHICLES", "r");

  iFileStatus = checkIfOpened(fpRead);

  fseek(fpRead, 0, SEEK_SET);

  if(iFileStatus == NULL_FILE)
  {
    addStatusToLog(iFileStatus);
    return NULL;
  }

  if(isEmpty(fpRead))
  {
    addStatusToLog(EMPTY);
    return NULL;
  }

  while(!feof(fpRead))
  {
    oNew = (SNode*)calloc(1, sizeof(SNode));
    oNew->m_oNext = NULL;

    oNew->m_oData.m_strVIN = calloc(1, VIN_MAX_SIZE);
    oNew->m_oData.m_strMake = calloc(1, MAKE_COL_MAX_SIZE);
    oNew->m_oData.m_strColor = calloc(1, MAKE_COL_MAX_SIZE);

    // fscanf(fpRead, "%s", oNew->m_oData.m_strVIN);
    // fscanf(fpRead, "%s", oNew->m_oData.m_strMake);
    // fscanf(fpRead, "%s", oNew->m_oData.m_strColor);
    // fscanf(fpRead, "%f", &oNew->m_oData.m_fEngine);
    // fscanf(fpRead, "%lf", &oNew->m_oData.m_dPrice);

    fscanf(fpRead, "%s\n%s\n%s\n%f\n%lf\n", oNew->m_oData.m_strVIN, oNew->m_oData.m_strMake, oNew->m_oData.m_strColor
, &(oNew->m_oData.m_fEngine), &(oNew->m_oData.m_dPrice));

    if(oNew->m_oData.m_fEngine == 0.0)
    {
      freeList(oNew);
      break;
    }

    if(opVehicles == NULL)
    {
      opVehicles = oNew;
    }
    else
    {
      oCurr = opVehicles;

      while(oCurr->m_oNext != NULL)
      {
          oCurr = oCurr->m_oNext;
      }

      oCurr->m_oNext = oNew;
    }
  }

  iFileStatus = checkIfClosed(fpRead);

  if(iFileStatus == NOT_CLOSED)
  {
    addStatusToLog(iFileStatus);
    return NULL;
  }

  addStatusToLog(iFileStatus);

  return opVehicles;
}

//Checks if the file is empty to abort further execution of readFile()
int isEmpty(FILE *fp)
{
	long savedOffset = ftell(fp);
	fseek(fp, 0, SEEK_END);

	if (ftell(fp) == 0){
		return 1;
	}

	fseek(fp, savedOffset, SEEK_SET);

	return 0;
}

//Initialises the log with the current time
void initLog()
{
  FILE *fpLog = fopen("Files/LOG.txt", "w+");
	time_t rawtime;
  struct tm * timeinfo;
  int iFileStatus = 0;

  iFileStatus = checkIfOpened(fpLog);

  if(iFileStatus == NULL_FILE)
  {
    fprintf(stderr, "ERROR! The Log file couldn't be created!");
    return;
  }

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  fprintf (fpLog, "Run from %s\n", asctime (timeinfo) );

  iFileStatus = checkIfClosed(fpLog);

  if(iFileStatus == NOT_CLOSED)
  {
    fprintf(stderr, "ERROR! The Log file couldn't be closed after it's creation!");
    return;
  }
}

//Used to add a function name to the log
void addFuncNameToLog(char *strName)
{
  FILE *fpLog = fopen("Files/LOG.txt", "a+");
  int iFileStatus = 0;

  iFileStatus = checkIfOpened(fpLog);

  if(iFileStatus == NULL_FILE)
  {
    fprintf(stderr, "ERROR while adding a name! The Log file couldn't be opened!");
    return;
  }

  fprintf(fpLog, "\nFUNCTION: %s\n", strName);

  iFileStatus = checkIfClosed(fpLog);

  if(iFileStatus == NOT_CLOSED)
  {
    fprintf(stderr, "ERROR while adding a name! The Log file couldn't be closed!");
    return;
  }
}

//Adds the return value of a function to the log
void addStatusToLog(int iErrorCode)
{
  int iFileStatus = 0;
  FILE *fpLog = fopen("Files/LOG.txt", "r+");

  iFileStatus = checkIfOpened(fpLog);

  if(iFileStatus == NULL_FILE)
  {
    fprintf(stderr, "ERROR! The Log file couldn't be opened!\n");
    return;
  }

  fseek(fpLog, 0, SEEK_END);

  switch(iErrorCode)
  {
    case SUCCESS:
      fprintf(fpLog, "Succesfully executed!\n");
      break;

    case DUMP:
      fprintf(fpLog, "Inputed vehicle wasn't saved. Exiting succesfully!\n");
      break;

    case INVALID_INPUT:
      fprintf(fpLog, "ERR.[%d]: Invalid input!\n", INVALID_INPUT);
      break;

    case INVALID_INPUT_SIZE:
      fprintf(fpLog, "ERR.[%d]: Invalid input size!\n", INVALID_INPUT_SIZE);
      break;

    case EXISTS:
      fprintf(fpLog, "ERR.[%d]: VIN already exists!\n", EXISTS);
      break;

    case NOT_CLOSED:
      fprintf(fpLog, "ERR.[%d]: The file couldn't be closed!\n", NOT_CLOSED);
      break;

    case NULL_FILE:
      fprintf(fpLog, "ERR.[%d]: The file couldn't be opened!\n", NULL_FILE);
      break;

    default:
      fprintf(fpLog, "ERR.[%d]: UNKNOWN ERROR!\n", iErrorCode);
      break;
  }

  iFileStatus = checkIfClosed(fpLog);

  if(iFileStatus == NOT_CLOSED)
  {
    fprintf(stderr, "ERROR! The Log file couldn't be closed!");
    return;
  }
}