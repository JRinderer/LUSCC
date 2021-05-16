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
        t_type = is_1d_token(c);
        if(t_type != NONE_T && t_type != IGN){
            //indicates we have a token character
            buff_size = stringBuilder(running_str,c);
            printf("%s\n",running_str);
            freeStrings(running_str);
            running_str = (char *) calloc((buff_size+1),sizeof(char));
        }else {
            c_type = isLetter(c);
            //first determine if the character is a token character
            //switch on the type of char
            switch (c_type) {

                //we build a string type
                case (LTR):
                    buff_size = stringBuilder(running_str, c);
                    //printf("LTR\n");
                    break;
                    //we build a num type
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
                case (NUM):
                    buff_size = stringBuilder(running_str, c);
                    //printf("NUM\n");
                    break;
                case (END):
                    printf("DONE\n");
                    curnt_state = DONE;
                    break;
            }
        }
    }


}