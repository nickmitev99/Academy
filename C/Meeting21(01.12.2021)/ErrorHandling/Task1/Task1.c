// Задача 1. Напишете програма, която проверява дали всички отворени къдрави скоби {, (, [ са
// затворени ] ),}. Изпишете грешка при липса на затварящи скоби и реда на който са пропуснати

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define STRING_SIZE 200

void countRound(char *strSource, int* iCounter);
void countSquare(char *strSource, int* iCounter);
void countCurly(char *strSource, int* iCounter);

int main()
{
  FILE *fpRead = fopen("Task1.txt", "r");
  int iRBracketsCount = 0, iSBracketsCount = 0, iCBracketsCount = 0;
  int iLineCount = 0;
  char strBuffer[STRING_SIZE] = { 0 };

  if(fpRead == NULL)
  {
    perror("ERR: ");
    printf("ERR NUM: %d\n", errno);
    exit(errno);
  }

  while(!feof(fpRead))
  {
    iLineCount++;

    fgets(strBuffer, STRING_SIZE, fpRead);

    countRound(strBuffer, &iRBracketsCount);
    countSquare(strBuffer, &iSBracketsCount);
    countCurly(strBuffer, &iCBracketsCount);

    if(iRBracketsCount > 0)
    {
      fprintf(stderr, "\nERROR: Missing closing bracket ')' on line %d: %s", iLineCount, strBuffer);
    }
    if(iSBracketsCount > 0)
    {
      fprintf(stderr, "\nERROR: Missing closing bracket ']' on line %d: %s", iLineCount, strBuffer);
    }
    if(iCBracketsCount > 0)
    {
      fprintf(stderr, "\nERROR: Missing closing bracket '}' on line %d: %s", iLineCount, strBuffer);
    }

    memset(strBuffer, 0, strlen(strBuffer));
  }

  fclose(fpRead);

  return 0;
}

void countRound(char *strSource, int* iCounter)
{
  *iCounter = 0;

  while(*strSource)
  {
    if(*strSource == '(')
    {
      (*iCounter)++;
    }
    else if(*strSource == ')')
    {
       (*iCounter)--;
    }

    strSource++;
  }
}

void countSquare(char *strSource, int* iCounter)
{
  *iCounter = 0;

  while(*strSource)
  {
    if(*strSource == '[')
    {
       (*iCounter)++;
    }
    else if(*strSource == ']')
    {
       (*iCounter)--;
    }

    strSource++;
  }
}

void countCurly(char *strSource, int* iCounter)
{
  *iCounter = 0;

  while(*strSource)
  {
    if(*strSource == '{')
    {
       (*iCounter)++;
    }
    else if(*strSource == '}')
    {
       (*iCounter)--;
    }

    strSource++;
  }
}