#ifndef DEALERSHIP_H
#define DEALERSHIP_H

//TYPEDEFS
typedef struct Vehicle SVehicle;
typedef struct Node SNode;

//VEHICLE STRUCT
struct Vehicle{
  char *m_strVIN;
  char *m_strColor;
  char *m_strMake;
  float m_fEngine;
  double m_dPrice;
};

//LINKED LIST
struct Node{
  SVehicle m_oData;
  SNode *m_oNext;
};

#endif //DEALERSHIP_H