//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"


typedef enum
{
    START,INASSIGN,INCOMMENT,INNUM,INID,DONE
}state_type;


int is_token_or_reserved(char **str, int size){
    if(is_token(str)!=NONE_T){
        printf("%s\t\t%s\n",str,str);
        freeStrings(str);
        str = (char *) calloc((size+1),sizeof(char));
        token_types t_type;
        return 1;
    }
    return 0;
}

int is_identif(char **str, int size){
    if(is_token(str)==NONE_T){
        printf("%s\t\t%s\n",str,str);
        freeStrings(str);
        str = (char *) calloc((size+1),sizeof(char));
        token_types t_type;
        return 1;
    }
    return 0;
}

int look_ahead(FILE *f, char **buffer){
    char c;
    //get next char;
    c = fgetc(f);
    token_types tk_type;
    int buff_size;

    tk_type = is_char_token(c);
    //almost working, but need to figure out 2d operators like ==
    while(tk_type == NONE_T && is_token(buffer)==NONE_T) {
        buff_size = stringBuilder(buffer, c);
        c = fgetc(f);
        tk_type = is_char_token(c);
    }
    int holder=0;
    holder = is_token_or_reserved(buffer,buff_size);
    if(holder == 0){
        is_identif(buffer,buff_size);
    }

    fseek(f,-1L,SEEK_CUR);
}



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
        buff_size = stringBuilder(running_str,c);
        buff_size = look_ahead(f,running_str);
        if(c==EOF){
            curnt_state=DONE;
        }

    }



    }
