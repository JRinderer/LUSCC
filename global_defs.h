//
// Created by jrinder on 5/15/21.
//

#ifndef LUSCC_GLOBAL_DEFS_H
#define LUSCC_GLOBAL_DEFS_H

#include <stdio.h>
#include <stdlib.h>


#define MAX 10000

typedef enum{
    //reserved words
    IF,ELSE, INT, RETURN, VOID, WHILE,
    //symbols
    PLUS,MINUS,TIMES,DIVIDE,LPAREN,RPAREN,LBRACKET,RBRACKET,LCURLY,RCURLY,SEMICOL,ASSIGN,EQL,NTEQL,COMMA, STCMT,ENCMT,NONE_T
}token_types;


typedef enum{
    //SPC coves tab and space
    LTR,NUM,TAB,SPC,ERR,END,NONE_C
}char_type;

//original source code
extern FILE* src_code;
//output from scanner
extern FILE* scn_code;


#endif //LUSCC_GLOBAL_DEFS_H
