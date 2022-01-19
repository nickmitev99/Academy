#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "../Hdr/Dealership.h"
#include "../Hdr/VehicleFunctions.h"
#include "../Hdr/Validation.h"

//Adds a new node the list (if it's empty, it adds it to the beginning and if it's empty - it adds it to the end)
int iInsertInList(SNode **opVehicles)
{
    SNode *oNew = opInsertVehicle(); //opInsertVehicle
    SNode *oCurr = NULL;

    if(iCheckIfExists(*opVehicles, oNew) != SUCCESS)
    {
      return DUMP;
    }

    if(*opVehicles == NULL)
    {
        *opVehicles= oNew;
    }
    else
    {
        oCurr = *opVehicles;

        while(oCurr->m_oNext != NULL)
        {
            oCurr = oCurr->m_oNext;
        }

        oCurr->m_oNext = oNew;
    }

    return SUCCESS;
}

//Allocates memory for a node, requires for the user to enter a valid input for each field and returns the result to iInsertInList(SNode**)
SNode *opInsertVehicle()
{
  SNode *opVehicle = (SNode*)calloc(1, sizeof(SNode));
  char strInput[INPUT_MAX_SIZE] = { 0 };

  printf("\nEnter a VIN: ");
  scanf("%s", strInput); //opVehicle->m_oData.m_strVIN

  iHandleInput(strInput, VIN_MAX_SIZE, VIN);

  opVehicle->m_oData.m_strVIN = calloc(1, strlen(strInput));
  strcpy(opVehicle->m_oData.m_strVIN, strInput);

  printf("\nEnter a Make: ");
  scanf("%s", strInput); //opVehicle->m_oData.m_strMake

  iHandleInput(strInput, MAKE_COL_MAX_SIZE, STRING);

  opVehicle->m_oData.m_strMake = calloc(1, strlen(strInput));
  strcpy(opVehicle->m_oData.m_strMake, strInput);

  printf("\nEnter a Color: ");
  scanf("%s", strInput); //opVehicle->m_oData.m_strColor

  iHandleInput(strInput, MAKE_COL_MAX_SIZE, STRING);

  opVehicle->m_oData.m_strColor = calloc(1, strlen(strInput));
  strcpy(opVehicle->m_oData.m_strColor, strInput);

  printf("\nEnter an Engine Size: ");
  scanf("%s", strInput); //opVehicle->m_oData.m_fEngine

  iHandleInput(strInput, ENGINE_MAX_SIZE, NUMBER);

  opVehicle->m_oData.m_fEngine = atof(strInput);

  printf("\nEnter a Price: ");
  scanf("%s", strInput); //opVehicle->m_oData.m_dPrice

  iHandleInput(strInput, PRICE_MAX_SIZE, NUMBER);

  opVehicle->m_oData.m_dPrice = atof(strInput);

  opVehicle->m_oNext = NULL;
}

//Depending on the OS of the user, calls either the 'cls' or 'clear' command in the console
void clear()
{
  #if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
    system("cls");

  #elif
    system("clear");

  #endif
}

//A simple pause function
void pause()
{
  printf("\nPress any key to continue...");
  getche();
}

//Frees the memory held by the linked list
void freeList(SNode *opVehicle)
{
    SNode* oCurr = NULL;

    while(opVehicle != NULL)
    {
        oCurr = opVehicle->m_oNext;

        free(opVehicle->m_oData.m_strVIN);
        free(opVehicle->m_oData.m_strMake);
        free(opVehicle->m_oData.m_strColor);
        free(opVehicle);

        opVehicle = oCurr;
    }

    printf("\nMemory freed!");
}

//Deletes a node from the list depending on the inputed VIN from the user
void deleteVehicle(SNode **opVehicle)
{
  SNode *oDeleted = *opVehicle;
  SNode *oCurr = NULL;
  char strInput[INPUT_MAX_SIZE] = { 0 };

  clear();

  if( *opVehicle == NULL)
  {
    printf("There are no vehicles in the database!");
    pause();
    return;
  }

  printf("Enter the VIN of the vehicle you would like to delete: ");
  scanf("%s", strInput);

  if( (oDeleted != NULL) && (!strcmp(oDeleted->m_oData.m_strVIN, strInput)) )
  {
    *opVehicle = (*opVehicle)->m_oNext;

    free(oDeleted->m_oData.m_strVIN);
    free(oDeleted->m_oData.m_strMake);
    free(oDeleted->m_oData.m_strColor);
    free(oDeleted);
    
    printf("\nDeleted vehicle with VIN '%s'", strInput);
    pause();
    return;
  }
  else
  {
    oCurr = *opVehicle;

    while(oCurr->m_oNext != NULL)
    {
      if(!strcmp(oCurr->m_oNext->m_oData.m_strVIN, strInput))
      {
        oDeleted = oCurr->m_oNext;
        oCurr->m_oNext = oCurr->m_oNext->m_oNext;

        free(oDeleted->m_oData.m_strVIN);
        free(oDeleted->m_oData.m_strMake);
        free(oDeleted->m_oData.m_strColor);
        free(oDeleted);

        printf("\nDeleted vehicle with VIN '%s'", strInput);
        pause();
        return;
      }
      else
      {
        oCurr = oCurr->m_oNext;
      }
    }
  }

  printf("\nThere is no such vehicle with a VIN '%s'", strInput);
  pause();
}

//Performs a search by vehicle make in the list and displays all vehicles of that make
void searchByMake(SNode *opVehicle)
{
  char strMake[MAKE_COL_MAX_SIZE] = { 0 };
  char strBuffer[MAKE_COL_MAX_SIZE] = { 0 };
  EFlag oFlag = FALSE;

  clear();

  printf("Enter the make to be displayed: ");
  scanf("%s", strMake);

  printf("\n\n--%s--\n", strMake);

  lowerString(strMake);

  while (opVehicle != NULL) 
  {
    strcpy(strBuffer, opVehicle->m_oData.m_strMake);

    lowerString(strBuffer);

    if(!strcmp(strBuffer, strMake))
    {
      printf("\nVIN: %s", opVehicle->m_oData.m_strVIN);
      printf("\nColor: %s", opVehicle->m_oData.m_strColor);
      printf("\nEngine size: %.1f", opVehicle->m_oData.m_fEngine);
      printf("\nPrice: %.2lf\n", opVehicle->m_oData.m_dPrice);

      oFlag = TRUE;
    }

    opVehicle = opVehicle->m_oNext;
  }

  if(oFlag == FALSE)
  {
    printf("\nNo available vehicles for the coresponding make!");
  }

  pause();
}

//Performs a search by vehicle make in the list and displays all vehicles of that make that have a higher price than the average for the make
void searchByMakeAvg(SNode *opVehicle)
{  
  char strMake[MAKE_COL_MAX_SIZE] = { 0 };
  char strBuffer[MAKE_COL_MAX_SIZE] = { 0 };
  double dAverage = 0.0;
  EFlag oFlag = FALSE;

  clear();

  printf("Enter the make to be displayed: ");
  scanf("%s", strMake);
  
  printf("\n\n--%s--\n", strMake);

  lowerString(strMake);

  dAverage = findAvg(opVehicle, strMake);

  printf("Average price: %lf\n", dAverage);

  while (opVehicle != NULL) 
  {
    strcpy(strBuffer, opVehicle->m_oData.m_strMake);

    lowerString(strBuffer);

    if( (!strcmp(strBuffer, strMake)) && (opVehicle->m_oData.m_dPrice > dAverage) )
    {
      printf("\nVIN: %s", opVehicle->m_oData.m_strVIN);
      printf("\nColor: %s", opVehicle->m_oData.m_strColor);
      printf("\nEngine size: %.1f", opVehicle->m_oData.m_fEngine);
      printf("\nPrice: %.2lf\n", opVehicle->m_oData.m_dPrice);

      oFlag = TRUE;
    }

    opVehicle = opVehicle->m_oNext;
  }

  if(oFlag == FALSE)
  {
    printf("\nNo available vehicles for the coresponding make!");
  }

  pause();
}

//Finds the average price of a vehicle make in the list
double findAvg(SNode *opVehicle, char *strMake)
{
  int iCountVehicles = 0;
  double dAverage = 0.0;
  char strBuffer[MAKE_COL_MAX_SIZE] = { 0 };

  while (opVehicle != NULL) 
  {
    strcpy(strBuffer, opVehicle->m_oData.m_strMake);

    lowerString(strBuffer);

    if(!strcmp(strBuffer, strMake))
    {
      iCountVehicles++;
      dAverage += opVehicle->m_oData.m_dPrice;
    }

    opVehicle = opVehicle->m_oNext;
  }

  return (dAverage / iCountVehicles);
}

//Converts all uppercase letters to lowercase, used to compare user inputs without case sensitivity
void lowerString(char *strTarget)
{
	for ( ; *strTarget; ++strTarget) 
	{
		*strTarget = tolower(*strTarget);
	}
}


//N.B. Prints the list, used for debugging purposes only!
void printList(SNode *oNode)
{
    clear();

    while (oNode != NULL) 
    {
      printf("\nVIN: %s", oNode->m_oData.m_strVIN);
      printf("\nMake: %s", oNode->m_oData.m_strMake);
      printf("\nColor: %s", oNode->m_oData.m_strColor);
      printf("\nEngine size: %.1f", oNode->m_oData.m_fEngine);
      printf("\nPrice: %.2lf\n", oNode->m_oData.m_dPrice);
      oNode = oNode->m_oNext;
    }

    pause();
}