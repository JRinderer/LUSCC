//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"
#include "global_defs.h"


void stringBuilder(char **strng, char c){
    int size=0;
    int i=0;

    char *temp_pntr = (char*)malloc(size+1 * sizeof(char));
    temp_pntr = strng;
    int size2 = strlen(strng);
    temp_pntr[size2]=c;

    strng = realloc(strng,size+100);
    strng = temp_pntr;
    //return strng;


}

//we pass the source code file after main validates there are no unusual or invalid characters
void start_scanner(FILE *f){
    char *running_str = (char*)malloc(0 * sizeof(char));
    char current_c = 'c';
    stringBuilder(running_str,current_c);
    current_c = 'a';
    stringBuilder(running_str,current_c);
    current_c = 'k';
    stringBuilder(running_str,current_c);
    current_c = 'e';
    stringBuilder(running_str,current_c);
    printf("The current string is:%s",running_str);


}