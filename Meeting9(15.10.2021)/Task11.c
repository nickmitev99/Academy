/*
Задача 11*. Напишете програма, която да премахва всички коментари в
една С програма.
*/

#include <stdio.h>

int main()
{
    char cChar = '\0', cPrev = '\0', cPPrev = '\0';
    int iIsCommentS = 0, iIsCommentM = 0;

    while(cChar != EOF)
    {
        cChar = getchar();

        if(cChar == '/' && cPrev == '/')                    //Checking if the input is a single line comment and setting the flag to 1
        {
            iIsCommentS = 1;
        }

        else if (cChar == '\n' && iIsCommentM == 0)         //Checking if the comment has ended and if there isn't any multi line
        {                                                   //comment and then setting the flag back to 0
            iIsCommentS = 0;
        }

        if( (cChar == '*') && (cPrev == '/') )              //Checking if the input is a multi line comment and setting the flag to 1
        {
            iIsCommentM = 1;
        }

        else if ( (cChar == '/') && (cPrev == '*') )        //Checking if the input is the end of a multi line comment
        {
            iIsCommentM = 0;
        }

        if( (iIsCommentS == 0 && iIsCommentM == 0 ) && cChar != '/' && cPrev == '/' && cPPrev != '*')
        {
            putchar(cPrev);                                 //Checking if input is different from '/' and if the previous char is '/'
        }                                                   // and the one before that is differnet than '*' and then printing


        if(iIsCommentS == 0 && iIsCommentM == 0 && cChar != '/')    //Checking if the input is not '/' and then printing it
        {
            putchar(cChar);
        }


        cPPrev = cPrev;
        cPrev = cChar;
    }

    return 0;
}