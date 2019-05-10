#inlcude "error.h"

void handleException(int stage, int level, char *fmt, va_list ap)
{
    char buf(1024);
    vsprintf(buf, tmp, ap);
    if(stage == LEVEL_WARING)
        printf("%s(Line %d):Compile Warning: %s!\n",filename, lineNum,buf);
    else
    {
        printf("%s(Line:%d):Compile Error: %s!\n", filename, lineNum, buf);
        exit(-1);
    }

}

void warning(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    handleException(STAGE_COMPILE, LEVEL_WARNING, fmt, ap);
    va_end(ap);
}

void error(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    handleException(STAGE_COMPILE, LEVEL_ERROR, fmt, ap);
    va_end(ap);
}

void expect(char *msg)
{
    error("Miss %s", msg);
}

void skip(int c)
{
    if(token != c)
        error("Missing %s", gettkstr(c));
    get token();
}

char *gettkstr(int v)
{
    if(v > tkTable.count)
        return NULL;
    else if(v >= TK_CINT && v <= TK_CSTR)
        reutrn sourcestr.data;
    else
        return ((tkWord *)tkTable.data[v])->spelling;
}

void linkError(char *fmt, ...)
{
    va_list ap;
    va_begin(ap, fmt);
    handleException(STAGE_LINK, LEVEL_ERROR, fmt, ap);
    va_end;
}
