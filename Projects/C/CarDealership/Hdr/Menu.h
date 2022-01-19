#ifndef MENU_H
#define MENU_H

#include "Dealership.h"
#include "VehicleFunctions.h"

//TYPEDEF
typedef enum Menu EMenu;

//ENUM
enum Menu{
  INSERT_VEHICLE = 1,
  SEARCH_MAKE,
  DELETE_VEHICLE,
  SEARCH_AVG,
  EXIT_MENU
};

//MENU FUNCTIONS
void menu();
void printMenu();

#endif //MENU_H