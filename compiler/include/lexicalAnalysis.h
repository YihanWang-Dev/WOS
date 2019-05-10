#define _LEXICALANALYSIS_H_
#ifndef _LEXICALANALYSIS_H_
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "token.h"
/*************************************************************/
#define MAXKEY 1024
tkWord *tkHashTable[MAXKEY];
dynArray tkTable;
/*************************************************************/


/************************************************************
init lex analysis
************************************************************/
void initLex();
/*lexical main progress*/
void getToken();

void getch();
/*preprocessing for better text to lexiacal analysis.n*/
void preprogress();
/*handle with comment*/
void parseComment();
/*ignore space tab and enter*/
void skipWhiteSpace();
#endif




