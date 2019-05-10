#define _BASE_H_
#ifndef _BASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynString
{
    int count;
    int capacity;
    char *data;
}dynString;
/*dynamatic array structure*/
typedef struct  dynArray
{
    int count;
    int capacity;
    void **data;
}dynArray;
/*token word table structure*/
typedef struct tkWord
{
    int tkCode;                      //word code
    struct tkWord *next;             //point to similar word has confict hash 
    char *spelling;                  //word string
    struct symbol *symStruct;        //point to structur decelaration
    struct symbol *symIdentifier;    // oint to identifier
}tkWord;

/*
 *init dynatic string length
 *pstr : data structure
 *initsize : space when the string get initlized
 */
void dynStringInit(dynString *pstr, int initsize);

/*
 *release the memroy of dynatic string
 *pstr : ...
 */
void dynStringFree(dynString *pstr);

/*
 *reset string ,release first and reinit
 */
void dynStringReset(dynString *pstr);

/*
 *realloc string
 */
void dynStringRealloc(dynString *pstr, int new_size);

/*
 *chcat a character to the string
 *
 */
void dynStringChcat(dynString *pstr, int ch);

/*
 *realloc dynmatic array 
 *parr : dynmatic array data structure
 *new_size : the newest length of dymatic array
 */
void dynArrayRealloc(dynArray *parr, int newSize);

/*
 *add element to dynmatic array
 */
void dynArrayAdd(dynArray *parr, void *data);

/*
 *init dynamatic array
 */
void dynArrayInit(dynArray *parr, int initSize);

/*
 *release the memory array used
 */
void dynArrayFree(dynArray *parr);

/*
 * search element in dynamatic array
 */
void dynArraySearch(dynArray *parr, int key);

/*
 *calculate hash address
 *elf_hash
 * key : hash keyword
 * MAXKEY : max hash length
 */
int elfHash(char *key);

/*
 *word  table function
 */
tkWord *tkWordDirectInsert(tkWord *tp);

/*
 *find word in word table
 *p : target word
 *keyNo : hash value of target word
 */
tkWord *tkWordFind(char *p, int ketNo);

tkWord *tkWordInsert(char *p);

/*allocate memory of head and init as 0
 *size : allocated memory size
 */
void *mallocz(int size);


#endif
