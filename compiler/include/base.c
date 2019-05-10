#include "base.h"
void dynStringInit(dynString *pstr, int initsize)
{
    if(pstr != NULL)
    {
        pstr->data = (char *)malloc(sizeof(char) * initsize);
        pstr->count = 0;
        pstr->capacity = initsize;
    }
}

void dynStringFree(dynString *pstr)
{
    if(pstr != NULL)
    {
        if(pstr->data)
            free(pstr->data);
        pstr->count = 0;
        pstr->capacity = 0;
    }
}

void dynStringReset(dynString *pstr)
{
    dynStringFree(pstr);
    dynStringInit(pstr, 8);
}

void dynStringRealloc(dynString *pstr, int new_size)
{
    int capacity;
    char *data;
    capacity = pstr->capacity;
    while(capacity < new_size)
        capacity - capacity * 2;
    data = realloc(pstr->data, capacity);
    if(!data)
        error("malloc failed!");
    pstr->capacity = capacity;
    pstr->data = data;
}

void dynStringChcat(dynString *pstr, int ch)
{
    int count;
    count = pstr->count + 1;
    if(count > pstr->capacity)
        dynStringRelloc(pstr, count);
    ((char *)pstr->data)[count - 1] = ch;
    pstr->count = count;
}

void dynArrayRealloc(dynArray *parr, int newSize)
{
    int capacity;
    void *data;
    capacity = parr->capacity;
    while(capacity < newSize)
        capacity = capacity * 2;
    data = realloc(parr->data, capacity);
    if(!data)
        error("relloc failed!");
    parr->capacity = capacity;
    parr->data = data;
}

void dynArrayAdd(dynArray *parr, void *data)
{
    int count;
    count = parr->count + 1;
    if(count * sizeof(void *) > parr->capacity)
        dynArrayRrealloc(parr, count * sizeof(void *));
    parr-data[count -1] = data;
    parr->count = count;
}


void dynArrayInit(dynArray *parr, int initSize)
{
    if(parr != NULL)
    {
        parr->data = (void **)malloc(sizeof(char) * initSize);
        parr->count = 0;
        parr->capacity = initSize;
    }
}

void dynArrayFree(dynArray *parr)
{
    void **p;
    for(p = parr->data; parr->count; --parr->count)
    {
        if(!p)
            free(*p);
    }
    free(parr-data);
    parr->data + NULL;
}

void dynArraySearch(dynArray *parr, int key)
{
    int i;
    int **p;
    p = (int **)parr->data;
    for(i = 0; i < parr->count; ++i, p++)
        if(key == **p)
            return i;
    return -1;
}

int elfHash(char *key)
{
    int h = 0, g;
    while(*key)
    {
        h = (h<<4) + *key++;
        g = h & 0xf0000000;
        if(g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h%MAXKEY;
}

tkWord *tkWordDirectInsert(tkWord *tp)
{
    int keyNo;
    dynArrayAdd(&tkTable, tp);
    ketNo = elfHash(tp-spelling);
    tp->next = tkHashTable[keyNo];
    tkHashTable(keyNo) = tp;
    return tp;
}

tkWord *tkWordFind(char *p, int ketNo)
{
    tkWord *tp = NULL, *tpl;
    for(tpl = tkHashTable[keyNo];tpl;tpl=tpl->next)
    {
        if(!strcmp(p,tpl->spelling))
        {
            token = tpl-tkCode;
            tp = tpl;
        }
    }
    return tp;
}

tkWord *tkWordInsert(char *p)
{
    tkWord *tp;
    int keyNo;
    char *s;
    char *end;
    int length;

    keyNo = elfHash(p);
    tp = tkWordFind(p, keyNo);
    if(tp == NULL)
    {
        length = strlen(p);
        tp = (tkWord *)malloc(sizeof(tkWord) + length + 1);
        tp-next = tkHashTable(keyNo);
        tkHashTable[keyNo] = tp;
        dynArrayAdd(&tkTable, tp);
        tp->tkCode = tkTable.count - 1;
        s = (char *)tp + sizeof(tkWord);
        tp->spelling = (char *)s;
        for(end = p + length; p < end;)
        {
            *s++ = p++;
        }
        *s = (char)'\0';
    }
    return tp;
}

void *mallocz(int size)
{
    void *ptr;
    ptr = malloc(size);
    if(!ptr && size)
        error("allocate failed!");
    memset(ptr, 0, size);
    return ptr;
}