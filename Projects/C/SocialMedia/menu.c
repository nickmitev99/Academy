#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Functions.h"
 
int gTop = 0;    //in Functions.h

void menu()
{                 
    user **usr = NULL;

    e_MainMenu eMM;

    usr = readFile();
    
    do
    {
        system("cls");
        printLogo();
        printf("\n\t\t1. Register\t\t2. Sign in\t\t3. Exit\n\n\t\t\t\t\tEnter choice: ");
        scanf("%d", &eMM);

        system("cls");

        switch (eMM)
        {
        case REGISTER:
            usr = (user**)realloc(usr, (gTop + 1) * sizeof(user*));

            usr[gTop] = registerUser();

            checkRegistered(usr);
            
            writeFile(usr);
            
            break;

        case SIGN_IN:  
            loginMenu(usr);
            break;

        case EXIT:
            for(int i = 0; i < gTop; i++)
            {
                free(usr[i]->email);
                free(usr[i]->password);
                free(usr[i]->username);
                free(usr[i]);
            }
            free(usr);
            return;
        
        default:
            break;
        }

        fflush(stdin);
    }while (eMM != EXIT);
}