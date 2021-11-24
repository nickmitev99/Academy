#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Functions.h"

void writeFile(user** usr)
{
    int iLastFriend = MAX_FRIEND_SIZE - 1;
    FILE* fp = NULL;

    if( (fp = fopen("Users.xml", "w+")) == NULL )
    {
        printf("\nError! Can't open the file for writing!\n");
        return;
    }

    fprintf(fp, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    fprintf(fp, "<UsersData>\n");
    for(int i = 0; i < gTop; i++)
    {
        fprintf(fp, "\t<user%d>\n", usr[i]->id);
        fprintf(fp, "\t\t<id>%u<id>\n", usr[i]->id);
        fprintf(fp, "\t\t<email>%s</email>\n", usr[i]->email);
        fprintf(fp, "\t\t<password>%s</password>\n", usr[i]->password);
        fprintf(fp, "\t\t<username>%s</username>\n", usr[i]->username);
        fprintf(fp, "\t\t<friends>");
        for(int j = 0; j < MAX_FRIEND_SIZE; j++)
        {
            if(j == iLastFriend)
            {
                fprintf(fp, "%d", usr[i]->friends[j]);
            }
            else
            {
                fprintf(fp, "%d ", usr[i]->friends[j]);
            }
        }
        fprintf(fp, "</friends>\n");
        fprintf(fp, "\t</user%d>\n", usr[i]->id);
    }
    fprintf(fp, "</UsersData>");

    fclose(fp);
}

user** readFile()
{
    FILE* fp = NULL;
    user** usr = NULL;
    char sBuffer[BUFF_ROWS][BUFF_COLLS] = { 0 };
    char sLine[BUFF_ROWS][BUFF_COLLS] = { 0 };
    char *sTarget = NULL;
    int iLinePos = 0;
    int iRow = 0, iCols = 0;

    char ch = '0';

    fp = fopen("Users.xml", "r");

    while(!feof(fp)) 
    {
        ch = fgetc(fp);
        
        if(ch == '\n')
        {
            sBuffer[iRow][iCols] = '\0';
            iRow++;
            iCols = 0;
        }
        else if(ch != '\t')
        {
            sBuffer[iRow][iCols] = ch;
            iCols++;
        }
    }

    iLinePos = getData(sBuffer, sLine, "<id>", iRow);
    
    gTop = iLinePos;

    if(gTop == 0)
    {
        return NULL;
    }

    usr = (user**)malloc(gTop * sizeof(user*));

    for(int i = 0; i < gTop; i++)
    {
         usr[i] = (user*)malloc(sizeof(user));
         memset(usr[i], 0, sizeof(user*));
    }

    for(int i = 0; i < iLinePos; i++)
    {
        sTarget = setData(sLine[i]);
        usr[i]->id = (unsigned int)atoi(sTarget);
        free(sTarget);
    }
    
    iLinePos = getData(sBuffer, sLine, "<email>", iRow);

    for(int i = 0; i < iLinePos; i++)
    {
        usr[i]->email = setData(sLine[i]);
    }

    iLinePos = getData(sBuffer, sLine, "<password>", iRow);

    for(int i = 0; i < iLinePos; i++)
    {
        usr[i]->password = setData(sLine[i]);
    }

    iLinePos = getData(sBuffer, sLine, "<username>", iRow);

    for(int i = 0; i < iLinePos; i++)
    {
        usr[i]->username = setData(sLine[i]);
    }

    iLinePos = getData(sBuffer, sLine, "<friends>", iRow);

    for(int i = 0; i < iLinePos; i++)
    {
        int k = 0;
        int j = 0;

        sTarget = setData(sLine[i]);

        while(sTarget[k] != '\0')
        {
            if(sTarget[k] != ' ')
            {
                usr[i]->friends[j] = (unsigned int)atoi(&sTarget[k]);
                j++;
            }
            k++;
        }

        free(sTarget);
        j = 0;
        k = 0;
    }

    fclose(fp);

    return usr;
}

int getData(char (*sBuffer)[BUFF_COLLS], char (*sLine)[BUFF_COLLS], char *sTag, int iRow)
{
    int iLinePos = 0;
    int iLineSize = 0;
    int iTagSize = strlen(sTag);

    for(int i = 0; i <= iRow; i++)
    {
        int iBufferLenght = strlen(sBuffer[i]);

        if(strstr(sBuffer[i], sTag) != NULL)
        {
            for(int j = iTagSize; j < iBufferLenght; j++)
            {
                if(sBuffer[i][j] == '<')
                {
                    sLine[iLinePos][iLineSize] = '\0';
                    iLineSize = 0;
                    break;
                }
                sLine[iLinePos][iLineSize] = sBuffer[i][j];
                iLineSize++;
            }
            ++iLinePos;
        }
    }

    return iLinePos;
}

char* setData(char *sLine)
{
    int iTargetSize = strlen(sLine);
    char *sTarget = (char*)malloc(iTargetSize);
    strcpy(sTarget, sLine);
    sTarget[iTargetSize] = '\0';

    return sTarget;
}