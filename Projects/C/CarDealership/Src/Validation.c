#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Hdr/Dealership.h"
#include "../Hdr/Validation.h"
#include "../Hdr/FileFunctions.h"

//Searches the linkedlist for an already existing VIN and requires from the user either to edit the input or to quit and dump it
int iCheckIfExists(SNode *opVehicles, SNode *oNew)
{
  char strInput[INPUT_MAX_SIZE] = { 0 };

  while(opVehicles != NULL)
  {
    while( !(strcmp(opVehicles->m_oData.m_strVIN, oNew->m_oData.m_strVIN)) )
    {
      clear();
      printf("\nThere is already a vehicle with this VIN in the system. Please enter a new VIN or enter '-' to exit: ");
      scanf("%s", strInput);

      if(!strcmp(strInput, "-"))
      {
        return DUMP;
      }

      iHandleInput(strInput, VIN_MAX_SIZE, VIN);

      memset(oNew->m_oData.m_strVIN, 0, sizeof(oNew->m_oData.m_strVIN));
      strcpy(oNew->m_oData.m_strVIN, strInput);
    }

    opVehicles = opVehicles->m_oNext;
  }

  return SUCCESS;
}

//Used for handling of the iCheckIfValidInput(char, int, EType) function and stores it's status in the log
int iHandleInput(char *strInput, int iInputSize, EType oType)
{
  int iResult = iCheckIfValidInput(strInput, iInputSize, oType);
  addStatusToLog(iResult);

  while(iResult != SUCCESS)
  {
    clear();
    printf("\nInvalid input! Please re-enter!\n");
    scanf("%s", strInput);

    iResult = iCheckIfValidInput(strInput, iInputSize, oType);
    addStatusToLog(iResult);
  }

  return SUCCESS;
}

//Performs a check on the inputed VIN, Make, Model, etc. and returns a corresponding error code or success code
int iCheckIfValidInput(char *strInput, int iInputSize, EType oType)
{
  addFuncNameToLog("iCheckIfValidInput");
  if( strlen(strInput) > iInputSize)
  {
    return INVALID_INPUT_SIZE;
  }

  if(iInputSize == VIN_MAX_SIZE)
  {
    if( strlen(strInput) != iInputSize)
    {
      return INVALID_INPUT_SIZE;
    }
  }

  switch (oType)
  {
  case VIN:
    if(iCheckIfNumAndLett(strInput) != SUCCESS)
    {
      return INVALID_INPUT;
    }

    break;

  case STRING:
    if(iCheckIfLetter(strInput) != SUCCESS)
    {
      return INVALID_INPUT;
    }

    break;

  case NUMBER:
    if(iCheckIfNumber(strInput) != SUCCESS)
    {
      return INVALID_INPUT;
    }

    break;
  
  default:
    break;
  }

  return SUCCESS;
}

//Checks if the input consists of numbers and the '.' symbol
int iCheckIfNumber(char *strInput)
{
  int iOccurenceCounter = 0;
  int iDotCounter = 0;

  if(*strInput == '\0')
  {
    return INVALID_INPUT;
  }

  while (*strInput)
  {
    if ( ((*strInput >= 48) && (*strInput <= 57)) || (*strInput == DOT) )
    {
      if (*strInput == DOT)
      {
        iDotCounter++;
      }

      if( (*strInput == DOT) && (iOccurenceCounter == 0) )
      {
        return INVALID_INPUT;
      }
    }
    else
    {
      return INVALID_INPUT;
    }

    strInput++;
    iOccurenceCounter++;
  }

  if (iDotCounter > 1)
  {
    return INVALID_INPUT;
  }

  return SUCCESS;
}

//Checks if the input consists of letters and the '-' symbol
int iCheckIfLetter(char *strInput)
{
  while(*strInput)
  {
    if( !(isalpha(*strInput)) && (*strInput != ' ') && (*strInput != '-') )
    {
      return INVALID_INPUT;
    }

    strInput++;
  }

  return SUCCESS;
}

//Checks if the input for the VIN consists of allowed symbols (letters and numbers)
int iCheckIfNumAndLett(char *strInput)
{
  while(*strInput)
  {
    if( !(isalpha(*strInput)) && ( (*strInput < 48) || (*strInput > 57) ) )
    {
      return INVALID_INPUT;
    }

    strInput++;
  }

  return SUCCESS;
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