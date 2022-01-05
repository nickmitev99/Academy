#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define STRING_SIZE 64
#define MAX_FRIEND_SIZE 10
#define BUFF_ROWS 1024
#define BUFF_COLLS 128

typedef struct
{
    unsigned int id;
    char *email;
    char *password;
    char *username;
    unsigned int friends[MAX_FRIEND_SIZE];
}user;

enum MainMenu{
    REGISTER = 1,
    SIGN_IN,
    EXIT
};

enum SignInMenu{
    ADD = 1,
    REMOVE,
    PRINT,
    SIGN_OUT
};

enum StringType{
    USER,
    EMAIL,
    PASS
};

typedef enum MainMenu e_MainMenu;
typedef enum SignInMenu e_SignInMenu;
typedef enum StringType e_StringType;

extern int gTop;

//in menu.c
void menu();

//in userHandling.c
user* registerUser();

int checkIfEmail(user *usr);
int specialSymbols(char *usr);
int loginMenu(user **usr);
int signIn(user** usr);
int isRegistered(user** usr, int iPos);
int checkEmail(user* usr);

void printLogo();
void printUser(user** usr, int iCurr);
void addFriend(user** usr, int iCurr);
void addToFirstAvailable(int *iFriendPosition, int iID);
void removeFriend(user **usr, int iCurr);
void removeFromFriends(int *iFriendPosition, int iID);
void checkRegistered(user** usr);
void checkMaxLenght(char *sTarget, e_StringType tp);
void enterMaskedPassword(char *sTempString);

char* checkString(char *sTarget, e_StringType type);
char* enterNewString();

//in fileHandling.c
void writeFile(user** usr);

user** readFile();

int getData(char (*sBuffer)[BUFF_COLLS], char (*sLine)[BUFF_COLLS], char *sTag, int iRow);

char* setData(char *sLine);

#endif //FUNCTIONS_H