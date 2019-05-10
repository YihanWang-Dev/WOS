//character encode
#define _TOKEN_H_
#ifndef _TOKEN_H_

enum TokenCode
{
    TK_PLUS,                    // +
    TK_MINUS,                   // -
    TK_STAR,                    // *
    TK_DIVIDE,                  // /
    TK_MOD,                     // %
    TK_EQ,                      // ==
    TK_NEQ,                     // !=
    TK_LT,                      // <
    TK_LEQ,                     // <=
    TK_GT,                      // >
    TK_GEQ,                     // >=
    TK_ASSIGN,                  // =
    TK_POSINTSTO,               // -> (point to element of structurenn)
    TK_DOT,                     // . (structure)
    TK_AND,                     // & (address)
    TK_OPENPA,                  // (
    TK_CLOSEPA,                 // )
    TK_OPENEBR,                 // [
    TK_CLOSEEBR,                // ]
    TK_BEGIN,                   // {
    TK_END,                     // }
    TK_SEMICOLON,               // ;
    TK_COMMA,                   // ,
    TK_ELLIPSIS,                // ...
    TK_EOF,                     // EOF
     //constant 
    TK_CINT,                    // int
    TK_CCHAR,                   // char
    TK_CSTR,                    // string
    //ketword
    KW_CHAR,                    // char
    KW_SHORT,                   // short
    KW_INT,                     // int
    KW_VOID,                    // void
    KW_STRUCT,                  // struct
    KW_IF,                      // if
    KW_ELSE,                    // else
    KW_FOR,                     // for
    KW_CONTINUE,                // continue
    KW_BREAK,                   // break
    KW_RETURN,                  // return
    KW_SIZEOF,                  // sizeof

    KW_ALIGN,                   // __glign keyword
    KW_CDECL,                   // __cdecl keyword
    KW_STDCAKK,                 // __stdcall keyword

    //Identifier
    TK_IDENT
};

/*about error*/
enum errorLevel
{
    LEVEL_WARING,
    LEVEL_ERROR
};

enum workStage
{
    STAGE_COMPILE,
    STAGE_LINK
};
#endif



