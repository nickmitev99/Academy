#include "writeFiles.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Writes to either NAUGHTY_LIST.txt or NICE_LIST.txt
int writeFiles(SDebtors **opaDebtors, int iDebtorsCount, EStatus oStatus, FILE **fpLog)
{
  FILE *fp = NULL;
  EStatus oCurrStatus = FILENICE;
  int iFileStatus = 0;

  switch(oStatus)
  {
    case FILENICE:
      fp = fopen("NICE_LIST", "w");
      break;

    case FILENAUGHTY:
      fp = fopen("NAUGHTY_LIST", "w");
      break;
  }

  iFileStatus = checkIfOpened(fp);

  if(iFileStatus == NULL_FILE)
  {
    fprintf(*fpLog, "Error in function writeFiles: The files couldn't be created! Exiting...\n");
    return NULL_FILE;
  }

  for(int i = 0; i < iDebtorsCount; i++)
  {
    //oCurrStatus determines if the members of opaDebtors should be stored in NICE_LIST or NAUGHTY_LIST
    oCurrStatus = oCheckStatus(opaDebtors[i]);

    if(oCurrStatus == oStatus)  //If the two statuses match, write in the corresponding file
    {
      writeDebtor(opaDebtors[i], &fp, fpLog);
    }
  }

  iFileStatus = checkIfClosed(fp);

  if(iFileStatus == NOT_CLOSED)
  {
    fprintf(*fpLog, "Error in function writeFiles: The files couldn't be created! Exiting...\n");
    return NOT_CLOSED;
  }

  return SUCCESS;
}

//Returns the status of the debtor
EStatus oCheckStatus(SDebtors *opDebtor)
{
  return ( (opDebtor->oStatus) ? FILENICE : FILENAUGHTY );
}

//Writes the debtor in either file
int writeDebtor(SDebtors *opDebtor, FILE **fp, FILE **fpLog)
{
  char *strMessage = NULL;
  int iMessagePos = opDebtor->oMessage;  

  strMessage = extractMessages(iMessagePos, fpLog);

  if(strMessage == NULL)
  {
    fprintf(*fpLog, "Error in function writeDebtor: There aren't any messages! Exiting...\n");
    return NULL_FILE;
  }
   
  fprintf(*fp, "%s;%s", opDebtor->strName, strMessage);

  free(strMessage);

  return SUCCESS;
}

//Extracts the message from MESSAGES that corresponds to the required status of the deptor
char* extractMessages(int iMsgPos, FILE **fpLog)
{
  char *strMessage = NULL;
  char strTemp[MAX_MESSAGE_SIZE] = { 0 };
  int iCurrLenght = 0;
  int iAmountOfMsg = 0;
  int iIndex = 0;
  FILE *fp = fopen("MESSAGES", "r");

  if( checkIfOpened(fp) != SUCCESS )
  {
    fprintf(*fpLog, "Error in function extractMessages: The file couldn't be created! Exiting...\n");
    return NULL;
  }

  iAmountOfMsg = countMessages(fp);

  //If the file doesn't contain any messages, the function exits
  if(iAmountOfMsg == 0)
  {
    fprintf(*fpLog, "Error in function extractMessages: There aren't any messages! Exiting...\n");
    return NULL;
  }

  while(!feof(fp))
  {
    fgets(strTemp, MAX_MESSAGE_SIZE, fp);

    if(iIndex == iMsgPos)     //When the required message is found, it gets stored in strMessage
    {
      iCurrLenght = strlen(strTemp);

      strMessage = (char*)malloc(iCurrLenght);

      strcpy(strMessage, strTemp);
    }

    iIndex++;
  }

  //Returns the file pointer to the beginning of the file
  fseek(fp, 0, SEEK_SET);

  if(checkIfClosed(fp) != SUCCESS)
  {
    fprintf(*fpLog, "Error in function extractMessages: The files couldn't be created! Exiting...\n");
    return NULL;
  }

  return strMessage;
}

//Count the amount of messages
int countMessages(FILE *fp)
{
  char cTemp = 0;
  int iCount = 0;

  cTemp = fgetc(fp);

  //Counts the occurences of New Line characters and determines the amount of messages
  while(cTemp != EOF)
  {
    if(cTemp == '\n')
    {
      iCount++;
    }

    cTemp = fgetc(fp);
  }

  //Returns the file pointer to the beginning of the file
  fseek(fp, 0, SEEK_SET);

  return iCount;
}