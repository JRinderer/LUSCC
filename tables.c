//
// Created by jrinder on 6/20/21.
//

#include "tables.h"

typedef struct toknLex{
    char *LSide;
    char *RSide;
    int key;
}TOKLEXTBL;

TOKLEXTBL tokLexTbl[800];


int tok_tble_size(){
    int i = 0;
    char *dat= (char *) malloc(0 * sizeof(char));
    int match=0;

    char*x = tokLexTbl[0].LSide;

    if(tokLexTbl[0].LSide == 0){
        return 0;
    }

    string_assembler_strt(dat, x);
    //string_match
    match = string_match(dat,"");
    while(match>0){
        i++;
        x = tokLexTbl[i].LSide;
        dat = string_assembler_strt(dat, x);
        match = string_match(dat,"");
    }
    return i;
}

void populate_table(char *tok, char *lex){
    int key = 0;
    key = tok_tble_size();

    tokLexTbl[key].LSide = tok;
    tokLexTbl[key].RSide= lex;
    tokLexTbl[key].key = key;
}


int get_unique_id(){

}