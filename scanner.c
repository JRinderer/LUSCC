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
        token_types t_type;
        c_type = isLetter(c);
        //switch on the type of char
        switch(c_type){
            //we build a string type
            case(LTR):
                buff_size = stringBuilder(running_str,c);
                //printf("LTR\n");
                break;
            //we build a num type
            case(NUM):
                //printf("NUM\n");
                break;
            //A TAB or SAPCE has been reached
            //this indicates the end, but once we include strings that isn't the case
            case(SPC):
                printf("%s\n",running_str);
                //free memory
                freeStrings(running_str);
                //free(running_str);
                //reallocate memory for next;
                running_str = (char *) calloc((buff_size+1),sizeof(char));

                //running_str = (char*)malloc(1 * sizeof(char));
                //printf("tab or space\n");
                break;
            case(NONE_C):
                //almost need to find a better way to deal with ( and other token characters!
                //we're close but I'm priting spaces to terminal. I want to avoid this
                printf("%s\n",running_str);
                freeStrings(running_str);
                running_str = (char *) calloc((buff_size+1),sizeof(char));
                t_type = is_1d_token(c);
                buff_size = stringBuilder(running_str,c);
                printf("%s\n",running_str);
                freeStrings(running_str);
                running_str = (char *) calloc((buff_size+1),sizeof(char));
                break;
            case(END):
                printf("DONE\n");
                curnt_state = DONE;
                break;
        }

        //determine what the char c could be

    }


}