//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"
#include "global_defs.h"


//we pass the source code file after main validates there are no unusual or invalid characters
void start_scanner(FILE *f){
    char *running_str = (char*)malloc(0 * sizeof(char));
    char current_c = 'c';
    stringBuilder(running_str,current_c); //this function is in universal_funcs.h
    current_c = 'a';
    stringBuilder(running_str,current_c);
    current_c = 'k';
    stringBuilder(running_str,current_c);
    current_c = 'e';
    stringBuilder(running_str,current_c);
    printf("The current string is:%s",running_str);
    
    freeStrings(running_str); //at the end of the scanner free any memory used by string

}