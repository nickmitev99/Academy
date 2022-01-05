#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Functions.h"

user* registerUser()
{
    user *usr = (user*)malloc(sizeof(user));
    char sTempString[STRING_SIZE] = { 0 };
    int iLenght = 0;
    
    if( usr == NULL)
    {
        printf("Allocation failed!");
        exit(2);
    }

    usr->id = gTop + 1;            //gTop is from Functions.h

    printf("\n\t\t\t\tEmail: ");
    scanf("%64s", sTempString);

    checkMaxLenght(sTempString, EMAIL);

    iLenght = strlen(sTempString);

    usr->email = (char*)malloc(iLenght);

    strcpy(usr->email, sTempString);

    checkEmail(usr);

    usr->email = checkString(usr->email, EMAIL);

    printf("\t\t\t\tPassword: ");
    enterMaskedPassword(sTempString);

    checkMaxLenght(sTempString, PASS);

    iLenght = strlen(sTempString);

    usr->password = (char*)malloc(iLenght);
    strcpy(usr->password, sTempString);

    usr->password = checkString(usr->password, PASS);

    printf("\t\t\t\tEnter your username: ");
    scanf("%64s", sTempString);

    checkMaxLenght(sTempString, USER);

    iLenght = strlen(sTempString);

    usr->username = (char*)malloc(iLenght);
    strcpy(usr->username, sTempString);

    usr->username = checkString(usr->username, USER);

    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        usr->friends[i] = 0;
    }

    gTop++;

    return usr;
}

int checkIfEmail(user *usr)
{
    int i = 0, iAtCounter = 0, iDotCounter = 0, iPos = 0;
    int iLenght = strlen(usr->email);
    int iSpecial = specialSymbols(usr->email);

    if(!iSpecial)
    {
        return 0;
    }

    while( usr->email[i] )
    {
        if( usr->email[i] == '@')
        {
            iAtCounter++;
            iPos = i;
        }

        i++;
    }

    for(int j = iPos + 1; j < iLenght; j++)
    {
        if( ( (j - iPos) == 1 ) && ( usr->email[j] == '.' ) && ( usr->email[iPos] == '@') )
        {
            iDotCounter = 0;
            break;
        }
        else if(usr->email[j] == '.')
        {
            iDotCounter++;
        }
        else if( ( !isalpha(usr->email[j]) ) && (usr->email[j] != '.') && (usr->email[j] != '-') )
        {
            iDotCounter = 0;
            break;
        }
    }

    if( (iAtCounter == 1) && (iDotCounter > 0) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int specialSymbols(char *sUsr)
{
    int i = 0;
    char sSpecialSymbols[] = " !\"#$%&'()*+,/:;<=>?[]\\`{}^|~";
    int iLenghtSymbols = sizeof(sSpecialSymbols);

    while( sUsr[i] )
    {
        for(int j = 0; j < iLenghtSymbols; j++)
        {
            if(sUsr[i] == sSpecialSymbols[j])
            {
                printf("\n\t\t\t\tSpecial symbols found! You can only use: ");
                printf("\n\t\t\t\tletters\n\t\t\t\tnumbers\n\t\t\t\t'.'\n\t\t\t\t','\n\t\t\t\t'-'\n\t\t\t\t'_'\n\t\t\t\t");
                system("pause");

                return 0;
            }
        }

        i++;
    }

    return 1;
}

void printLogo()
{
    printf("\t\t\t\t\t\t\t\t#        #\n");
    printf("\t\t\t\t\t\t\t\t##       #\n");
    printf("\t\t\t\t\t\t\t\t# #      #\n");
    printf("\t\t\t\t\t\t\t\t#  #     #\n");
    printf("\t\t\t\t\t\t\t\t#   #    #\n");
    printf("\t\t\t\t\t\t\t\t#    #   #\n");
    printf("\t\t\t\t\t\t\t\t#     #  #\n");
    printf("\t\t\t\t\t\t\t\t#      # #\n");
    printf("\t\t\t\t\t\t\t\t#       ##\n");
    printf("\t\t\t\t\t\t\t\t#        #\n\n\n\n");
}

int signIn(user** usr)
{
    char sEmail[STRING_SIZE] = { 0 }, sPass[STRING_SIZE] = { 0 }, cChoice = 0;
    int iIsLoggedIn = 0;

    printf("\n\t\t\t\tEmail: ");
    scanf("%s", sEmail);

    printf("\t\t\t\tPassword: ");
    enterMaskedPassword(sPass);

    for(int i = 0; i < gTop; i++)
    {
        if( ( !strcmp(sEmail, usr[i]->email) ) && ( !strcmp(sPass, usr[i]->password) ))
        {
            iIsLoggedIn = i;
            return i;
        }
    }

    system("cls");
    printf("\n\t\t\t\tIncorrect email or password! Please enter again or press 0 to cancel!\n");
    cChoice = getch();

    if(cChoice == '0')
    {
        return -2;
    }

    return -1;
}

int loginMenu(user **usr)
{
    int iSignedIn = -1;
    char cChoice = 0;
    e_SignInMenu eSM;

    while(iSignedIn == -1)
    {
        iSignedIn = signIn(usr);
    }

    if(iSignedIn < 0)
    {
        return 0;
    }

    do
    {
        system("cls");
        printf("\t\t\t\tWelcome, %s! Enter a choice:", usr[iSignedIn]->username);
        printf("\n\t\t\t\t1. Add a friend.");
        printf("\n\t\t\t\t2. Remove a friend.");
        printf("\n\t\t\t\t3. Check account settings.");
        printf("\n\t\t\t\t4. Sign out\n\n\t\t\t\tEnter choice: ");

        scanf("%d", &eSM);

        system("cls");

        switch(eSM)
        {
            case ADD:
                addFriend(usr, iSignedIn);
                break;
            
            case REMOVE:
                removeFriend(usr, iSignedIn);
                break;

            case PRINT:
                printUser(usr, iSignedIn);
                break;

            case SIGN_OUT:
                return 0;

            default:
                break;
        }

        fflush(stdin);

        if(eSM < SIGN_OUT)
        {
            system("pause");
        }
    } while(eSM != SIGN_OUT);
}

void printUser(user** usr, int iCurr)
{
    printf("\t\t\t\tNickname: %s\n", usr[iCurr]->email);
    printf("\t\t\t\tPassword: %s\n", usr[iCurr]->password);
    printf("\t\t\t\tUsername: %s\n", usr[iCurr]->username);
    printf("\t\t\t\tFriends:\n");

    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        for(int j = 0; j < gTop; j++)
        {
            if(usr[iCurr]->friends[i] == usr[j]->id)
            {
                printf("\t\t\t\t%s\n", usr[j]->email);
            }
        }
    }

    putchar('\n');
}

void addFriend(user** usr, int iCurr)
{
    char sEmail[STRING_SIZE] = { 0 };
    int iFriendPosition = -1;

    printf("Enter the email of the friend you would like to add: ");
    scanf("%s", sEmail);

    if(!strcmp(usr[iCurr]->email, sEmail))
    {
        printf("\nYou cannot add yourself as a friend!\n");
        return;
    }

    for(int i = 0; i < gTop; i++)
    {
        if(!strcmp(usr[i]->email, sEmail))
        {
            iFriendPosition = i;
        }
    }

    if(iFriendPosition < 0)
    {
        printf("\nUser not found!\n");
        return;
    }

    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        if(usr[iCurr]->friends[i] == 0)
        {
            break;
        }
        else if(i == (MAX_FRIEND_SIZE - 1) && i != 0)
        {
            printf("\nYou've reached the maximum number of friends!\n");
            return;
        }
    }

    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        if(usr[iFriendPosition]->friends[i] == 0)
        {
            break;
        }
        else if(i == (MAX_FRIEND_SIZE - 1) && i != 0)
        {
            printf("\nThis person has reached the maximum number of friends!\n");
            return;
        }
    }

    if(iFriendPosition >= 0)
    {
        for(int i = 0; i < MAX_FRIEND_SIZE; i++)
        {
            if(usr[iCurr]->friends[i] == usr[iFriendPosition]->id)
            {
                printf("\nYou are already friends with this user!\n");
                return;
            }
        }

        addToFirstAvailable(usr[iCurr]->friends, usr[iFriendPosition]->id);
        addToFirstAvailable(usr[iFriendPosition]->friends, usr[iCurr]->id);

        printf("\nAdded user as a friend\n");
    }

    writeFile(usr);
}

void addToFirstAvailable(int *iFriendPosition, int iID)
{
    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        if(iFriendPosition[i] == 0)
        {
            iFriendPosition[i] = iID;
            break;
        }
    }
}

void removeFriend(user **usr, int iCurr)
{
    char sEmail[STRING_SIZE] = { 0 };
    int iFriendPosition = -1;
    int iFriendCount = 0;

    printf("Enter the email of the friend you would like to remove: ");
    scanf("%s", sEmail);

    for(int i = 0; i < gTop; i++)
    {
        if(!strcmp(usr[i]->email, sEmail))
        {
            iFriendPosition = i;
        }
    }

    if(iFriendPosition < 0)
    {
        printf("\nUser not found!\n");
        return;
    }

    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        if(usr[iCurr]->friends[i] != usr[iFriendPosition]->id)
        {
            iFriendCount++;
        }
    }

    if(iFriendPosition == -1 || iFriendCount == MAX_FRIEND_SIZE)
    {
        printf("\n\"%s\" is not in your friends list\n", sEmail);
        return;
    }

    removeFromFriends(usr[iCurr]->friends, usr[iFriendPosition]->id);
    removeFromFriends(usr[iFriendPosition]->friends, usr[iCurr]->id);    

    printf("\n\"%s\" has been removed from your friends.\n", sEmail);

    writeFile(usr);
}

void removeFromFriends(int *iFriendPosition, int iID)
{
    for(int i = 0; i < MAX_FRIEND_SIZE; i++)
    {
        if(iFriendPosition[i] == iID)
        {
            iFriendPosition[i] = 0;
        }
    }
}

int isRegistered(user** usr, int iPos)
{
    for(int i = 0; i < gTop; i++)
    {
        if( (!strcmp(usr[iPos]->email, usr[i]->email) ) && (i != iPos))
        {
            return 0;
        }
    }

    return 1;
}

void checkRegistered(user** usr)
{
    int iCurr = gTop-1, iLenght = 0;
    int iCheck = isRegistered(usr, iCurr);
    char sTempString[STRING_SIZE] = { 0 };

    while( !iCheck )
    {
        system("cls");
        printf("\t\t\t\tThis email is already used. Please enter a new one!\n\t\t\t\t");

        free(usr[iCurr]->email);

        usr[iCurr]->email = enterNewString(sTempString);
        iLenght = strlen(sTempString);

        checkEmail(usr[iCurr]);
        usr[iCurr]->email = checkString(usr[iCurr]->email, EMAIL);

        iCheck = isRegistered(usr, iCurr);
    }
}

char* checkString(char *sTarget, e_StringType type)
{
    char sTempString[STRING_SIZE] = { 0 };
    int iLenght = strlen(sTarget);

    if(type == USER || type == EMAIL)
    {
        while( !(specialSymbols(sTarget) ) )
        {
            system("cls");
            free(sTarget);
            printf("\n\t\t\t\tInvalid input. Please enter a new one.\n\t\t\t\t");
            printf("\n\t\t\t\t ");
            sTarget = enterNewString();
            checkMaxLenght(sTempString, type);
        }
    }
    else
    {
        while(iLenght < 6)
        {
            system("cls");
            printf("\n\t\t\t\tYour password has to be atleast 6 characters! Please enter again!\n\t\t\t\t");
            sTarget = enterNewString();
            iLenght = strlen(sTarget);
            checkMaxLenght(sTempString, type);
        }
    }

    return sTarget;
}

void checkMaxLenght(char *sTarget, e_StringType tp)
{
    int iLenght = strlen(sTarget);

    if(tp == USER || tp == EMAIL)
    {
        while(iLenght >= STRING_SIZE)
        {
            fflush(stdin);
            printf("\n\t\t\t\tYou can use maximum 64 characters! Please enter again!\n\t\t\t\t");
            scanf("%64s", sTarget);
            iLenght = strlen(sTarget);
        }
    }
    else if(tp == PASS)
    {
        while(iLenght >= STRING_SIZE)
        {
            printf("\n\t\t\t\tYou can use maximum 64 characters! Please enter again!\n\t\t\t\t");
            enterMaskedPassword(sTarget);
        }
    }
}

int checkEmail(user* usr)
{
    char sTempString[STRING_SIZE] = { 0 };
    int iLenght = strlen(usr->email);

    while( !( checkIfEmail(usr) ) )
    {
        free(usr->email);
        system("cls");
        printf("\n\t\t\t\tInvalid email. Please enter a new email.\n\t\t\t\t");
        usr->email = enterNewString();
    }
    
    return 1;
}

char* enterNewString()
{
    char *sTarget = NULL;
    char sTempString[STRING_SIZE] = { 0 };
    int iLenght = 0;

    scanf("%64s", &sTempString);

    checkMaxLenght(sTempString, USER);

    iLenght = strlen(sTempString);
    sTarget = (char*)malloc(iLenght);
    strcpy(sTarget, sTempString);

    return sTarget;
}

void enterMaskedPassword(char *sTempString)
{
    char cChar = 0;
    int i = 0;

    fflush(stdin);

    for ( i = 0 ; i < STRING_SIZE ; )
    {
        fflush(stdin);

        cChar = getch();
        sTempString[i] = cChar;

        if ( sTempString[i] == '\b')
        {
            if(i > 0)
            {
                printf("\b \b");
                i--;
            }
            continue;
        }

        if ( sTempString[i] == ' ' || sTempString[i] == '\r' )
        {
            putchar(' ');
        }
        else
        {
            putchar('*');
            i++;
        }

        if ( sTempString[i]=='\r')
        {
            break;
        }
    }

    sTempString[i]='\0';

    putchar('\n');
}