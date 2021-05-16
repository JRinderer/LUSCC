//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"
//#include "global_defs.h"

typedef enum
{
    START,INASSIGN,INCOMMENT,INNUM,INID,DONE
}state_type;





//we pass the source code file after main validates there are no unusual or invalid characters
void start_scanner(FILE *f){
    char *running_str = (char*)malloc(0 * sizeof(char));
    char c;
    state_type curnt_state = START;
    //first step to read in a char add in error checking
    //while the state is not DONE
    while(curnt_state != DONE){
        c=fgetc(f);
        //get char tyoe;
        char_type c_type;
        c_type = isLetter(c);
        //switch on the type of char
        switch(c_type){
            //we build a string type
            case(LTR):
                stringBuilder(running_str,c);
                break;
            //we build a num type
            case(NUM):
                printf("no go");
                break;
        }
        curnt_state = DONE;
        //determine what the char c could be

    }


}