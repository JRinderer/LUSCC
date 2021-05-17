//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"


typedef enum
{
    START,INASSIGN,INCOMMENT,INNUM,INID,DONE
}state_type;

//we pass the source code file after main validates there are no unusual or invalid characters
void start_scanner(FILE *f){
    char *running_str = (char*)malloc(0 * sizeof(char));
    int buff_size;
    char c;

    state_type curnt_state = START;
    //first step to read in a char add in error checking
    //while the state is not DONE
    while(curnt_state != DONE){
        c=fgetc(f);
        //get char tyoe;
        char_type c_type;
        
        running_str = (char *) calloc((buff_size+1),sizeof(char));
        //
        buff_size = stringBuilder(running_str,c);
        //free and reallocate
        freeStrings(running_str);
        running_str = (char *) calloc((buff_size+1),sizeof(char));
        token_types t_type;
        t_type = is_1d_token(c);


    }
}