#define _ERROR_H_
#ifndef _ERRPR_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum ErrorLevel
{
    LEVEL_WARNING,
    LEVEL_ERROR
};
enum WorkStage
{
    STAGE_COMPILE,
    STAGE_LINK
};
/*
 *Exception handling
 *stage : compile stage or link stage
 *fmt : format of arguments output
 *level : error level
 *ap : changed arguments list
 */
void handleException(int stage, int level, char *fmt, va_list ap);

/*
 *compile warning handling
 * fmt arg output format
 *ap : changed arguments list
 */
void warning(char *fmt, ...);

/*
 *compile fetal error handling.
 */
void error(char *fmt, ...);
/*
 *point out there is a grammatical missing.
 */
void expect(char *msg);
/*
 *skip token, get next and point out error if the token is not c
 *c : the token skiped
 */
void skip(int c);
/*
 * get token v's source string
 * v the number of token
 */
char * gettkstr(int v);
/*
 *link error handling
 */
void linkError(char *fmt, ...);
#endif
