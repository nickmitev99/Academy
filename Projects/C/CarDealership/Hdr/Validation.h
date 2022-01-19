#ifndef DEFINES_H
#define DEFINES_H

#include "Dealership.h"
#include "VehicleFunctions.h"

//SIZES
#define INPUT_MAX_SIZE 4096
#define VIN_MAX_SIZE 17
#define MAKE_COL_MAX_SIZE 20
#define ENGINE_MAX_SIZE 5
#define PRICE_MAX_SIZE 16

//ERROR CODES
#define SUCCESS 0
#define DUMP -1
#define INVALID_INPUT -101
#define INVALID_INPUT_SIZE -102
#define EXISTS -103
#define NOT_CLOSED -104
#define NULL_FILE -105
#define EMPTY -106

//ALIASES
#define DOT '.'

//TYPEDEF
typedef enum Flag EFlag;

//ENUM FLAG
enum Flag{
  TRUE,
  FALSE
};

//FUNCTIONS FOR VEHICLES
int iHandleInput(char *strInput, int iInputSize, EType oType);
int iCheckIfExists(SNode *opVehicles, SNode *oNew);
int iCheckIfValidInput(char *strInput, int iInputSize, EType oType);
int iCheckIfNumber(char *strInput);
int iCheckIfLetter(char *strInput);
int iCheckIfNumAndLett(char *strInput);

//FUNCTIONS FOR FILES
int checkIfOpened(FILE *fp);
int checkIfClosed(FILE *fp);

#endif //DEFINES_H