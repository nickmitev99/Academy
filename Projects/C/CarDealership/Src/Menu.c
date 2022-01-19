#include <stdio.h>
#include "../Hdr/Dealership.h"
#include "../Hdr/Menu.h"
#include "../Hdr/FileFunctions.h"

//The menu for the file function
void menu()
{
  SNode *opVehicles = NULL;
  EMenu oMenu = EXIT_MENU;
  int iResult = 0;

  initLog();

  addFuncNameToLog("readFile");
  opVehicles = readFile();

  do
  {
    printMenu();
    scanf("%d", &oMenu);

    switch(oMenu)
    {
      case INSERT_VEHICLE:
        addFuncNameToLog("iInsertInList");
        iResult = iInsertInList(&opVehicles);

        addStatusToLog(iResult);

        break;

      case SEARCH_MAKE:
        searchByMake(opVehicles);

        break;

      case DELETE_VEHICLE:
        deleteVehicle(&opVehicles);

        break;

      case SEARCH_AVG:
        searchByMakeAvg(opVehicles);

        break;

      case EXIT_MENU:

        break;

      default:

        break;
    }

    fflush(stdin);

  } while ( oMenu != EXIT_MENU );

  addFuncNameToLog("writeFile");
  iResult = writeFile(opVehicles);

  addStatusToLog(iResult);

  freeList(opVehicles);
}

//Used for repetetive printing of the available functionality that a user can select
void printMenu()
{
  clear();
  printf("--CAR DEALERSHIP--");
  printf("\nEnter your choice:");
  printf("\n1. Insert a new vehicle.");
  printf("\n2. Display vehicles by make.");
  printf("\n3. Delete a vehicle.");
  printf("\n4. Display vehicles with a price, higher than the average for a make.");
  printf("\n5. Exit.");
  printf("\nYour choice: ");
}

//VIN Example: VY123TH321BZ506R4