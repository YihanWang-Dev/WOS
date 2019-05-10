#include "lexicalAnalysis.h"
/************************************************************
init lex analysis
************************************************************/
void initLex()
{
    tkWord *tp;
    static tkWord keyords[] = {
        {TK_PLUS,     NULL,  "+",               NULL, NULL},
        {TK_MINUS,    NULL,  "-",               NULL, NULL},
        {TK_STAR,     NULL,  "*",               NULL, NULL},
        {TK_DIVIDE,   NULL,  "/",               NULL, NULL},
        {TK_MOD,      NULL,  "%",               NULL, NULL},
        {TK_EQ,       NULL,  "==",              NULL, NULL},
        {TK_NEQ,      NULL,  "!=",              NULL, NULL},
        {TK_LT,       NULL,  "<",               NULL, NULL},
        {TK_LEQ,      NULL,  "<=",              NULL, NULL},
        {TK_GT,       NULL,  ">",               NULL, NULL},
        {TK_GEQ,      NULL,  ">=",              NULL, NULL},
        {TK_ASSIGN,   NULL,  "=",               NULL, NULL},
        {TK_POSITSTO, NULL,  "->",              NULL, NULL},
        {TK_DOT,      NULL,  ".",               NULL, NULL},
        {TK_AND,      NULL,  "&",               NULL, NULL},
        {TK_OPENPA,   NULL,  "(",               NULL, NULL},
        {TK_CLOSEPA,  NULL,  ")",               NULL, NULL},
        {TK_OPENEBR,  NULL,  "[",               NULL, NULL},
        {TK_CLOSEEBR, NULL,  "]",               NULL, NULL},
        {TK_BEGIN,    NULL,  "{",               NULL, NULL},
        {TK_END,      NULL,  "}",               NULL, NULL},
        {TK_SEMICOLON,NULL,  ";",               NULL, NULL},
        {TK_COMMA,    NULL,  ",",               NULL, NULL},
        {TK_ELLIPSIS, NULL,  "...",             NULL, NULL},
        {TK_EOF,      NULL,  "EOF",             NULL, NULL},
        {TK_CINT,     NULL,  "constant int",    NULL, NULL},
        {TK_CCHAR,    NULL,  "constant char",   NULL, NULL},
        {TK_CSTR,     NULL,  "constant string", NULL, NULL},

        {KW_CHAR,     NULL,  "char",            NULL, NULL},
        {KW_SHROT,    NULL,  "short",           NULL, NULL},
        {KW_INT,      NULL,  "int",             NULL, NULL},
        {KW_VOID,     NULL,  "void",            NULL, NULL},
        {KW_STRUCT,   NULL,  "struct",          NULL, NULL},

        {KW_IF,       NULL,  "if",              NULL, NULL},
        {KW_ELSE,     NULL,  "else",            NULL, NULL},
        {KW_FOR,      NULL,  "for",             NULL, NULL},
        {KW_CONTINUE, NULL,  "continue",        NULL, NULL},
        {KW_BREAK,    NULL,  "break",           NULL, NULL},
        {KW_RETURN,   NULL,  "return",          NULL, NULL},
        {KW_SIZEOF,   NULL,  "sizeof",          NULL, NULL},
        {KW_ALIGN,    NULL,  "__align",         NULL, NULL},
        {KW_CDECL,    NULL,  "__cdecl",         NULL, NULL},
        {KW_STDCALL,  NULL,  "__stdcall",       NULL, NULL},
        {0,           NULL,  NULL,              NULL, NULL},
    };
    dynArrayInit(&tkTable, 8);
    for(tp = &keywords[0]; tp->spelling != NULL; tp++)
        tkWordDirectInsert(tp);
}

void getToken()
{
    preprocess();
    switch(ch)
    {
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
        case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
        case 's': case 't': case 'u': case 'v': case 'w': case 'x':
        case 'y': case 'z':
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
        case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
        case 'Y': case 'Z':
        case '_':
        {
            tkWord *tp;
            parseIdentifier();
         n   tp = tkWordInsert(tkstr.data);
            token = tp->tkCode;
            break;
        }
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            parseNum();
            token = TK_CINT;
            break;
        }
        case '+':
        {
            getch();
            token = TK_PLUS;
            break;
        }
        case '-':
        {
            getch();
            if(ch == '>')
            {
                token = TK_POINTSTO;
                getch();
            }
            else
            {
                token = _MINUS;
            }
            break;
        }
        case '/':
        {
            token = TK_DIVIDE;
            getch();
            break;
        }
        case '%':
        {
            token = TK_MOD;
            getch();
            break;
        }
        case '=':
        {
            getch();
            if(ch == '=')
            {
                token = TK_EQ;
                getch();
            }
            else
            {
                token = TK_ASSIGN;
            }
            break;
        }
        case '!':
        {
            getch();
            if(ch == '=')
            {
                token = TK_NEQ;
                getch();
            }
            else
                error("Error do not apply !(not)");
            break;
        }
        case '<':
        {
            getch();
            if(ch == '=')
            {
                token = TK_LEQ;
                getch();
            }
            else
                token = TK_LT;
            break;
        }
        case '>':
        {
            getch();
            if(ch == '=')
            {
                token = TK_GEQ;
                getch();
            }
            else
                token = TK_GT;
            break;
        }
        case '.':
        {
            getch();
            if(ch == '.')
            {
                getch();
                if(ch != '.')
                    error("Ellipsis spelling error!");
                else
                    token - TK_ELLIPSIS;
                getch();
            }
            else
            {
                token = TK_DOT;
            }
            break;
        }
        case '&':
        {
            token = TK_AND;
            getch();
            break;
        }
        case ';':
        {
            token = TK_SEMICOLON;
            getch();
            break;
        }
        case ']':
        {
            token = TK_CLOSEBR;
            getch();
            break;
        }
        case '}':
        {
            token = TK_END;
            getch();
            break;
        }
        case ')':
        {
            token=TK_CLOSEPA;
            getch();
            break;
        }
        case '[':
        {
            token = TK_OPENBR;
            getch();
            break;
        }
        case '{':
        {
            token = TK_BEGIN;
            getch();
            break;
        }
        case ',':
        {
            token = TK_COMMA;
            getch();
            break;
        }
        case '(':
        {
            token = TK_OPENPA;
            getch();
            break;
        }
        case '*':
        {
            token = TK_STAR;
            getch();
            break;
        }
        case '\"':
        {
            parseString(ch);
            token = TK_CSTR;
            break;
        }
        case '\'':
        {
            parseString(ch);
            token = TK_CSTR;
            break;
        }
        case EOF:
        {
            token = TK_EOF;
            break;
        }
        default:
        {
            error("Unknown symbol.\\x%02x", ch);
            getch();
            break;
        }
    }
}

void getch()
{
    ch = getc(fin);
}

void preprogress()
{
    while(1)
    {
        if(ch==' ' || ch=='\t' || ch=='\r' )
            skipWhiteSpace();
        else if(ch == '/')
        {
            //judge if it's notes begining symbol if it is put the ch back.
            getch();
            if(ch == '*')
            {
                parseComment();
            }
            else
            {
                ungetc(ch, fin);
                ch = '/';
                break;
            }
        }
        else
            break;
    }
}

void parseComment()
{
    getch();
    do
    {
        do
        {
            if(ch=='\n' || ch=='*' || ch == CH_EOF)
                break;
            else
                getch();
        }while(1);
        if(ch == '\n')
        {
            line_num++;
            getch();
        }
        else if(ch == '*')
        {
            getch();
            if(ch == '/')
            {
                getch();
                return;
            }
        }
        else
        {
            error("Notes symbol doesn't match.");
            return;
        }
    }while(1);
}

void skipWhiteSpace()
{
    while(ch==' ' || ch=='\t' || ch=='\r')
    {
        if(ch == '\r')
        {
            getch();
            if(ch != '\n')
                return;
            lineNum++;
        }
        printf("%c", ch);
        getch();
    }
}
