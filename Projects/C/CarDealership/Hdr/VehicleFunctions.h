#ifndef VEHICLE_H
#define VEHICLE_H

#include "Dealership.h"

typedef enum Type EType;

enum Type{
  VIN,
  STRING,
  NUMBER
};

//NODE HANDLING
int iInsertInList(SNode **opVehicles);
SNode *opInsertVehicle();
void deleteVehicle(SNode **opVehicle);
void freeList(SNode *oHead);

//NODE SEARCHING
void searchByMake(SNode *opVehicle);
void searchByMakeAvg(SNode *opVehicle);

//HELP FUNCTIONS
double findAvg(SNode *opVehicle, char *strMake);
void lowerString(char *strTarget);

//CONSOLE FUNCTIONS
void clear();
void pause();

//DEBUGGING FUNCTIONS
void printList(SNode *oNode);

#endif //VEHICLE_H