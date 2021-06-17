
//
// Created by jrinder on 5/15/21.
//

#include "scanner.h"

typedef enum {
    START, INFUNC, OUTFUNC, INASSIGN, INCOMMENT, INNUM, INID, DONE
} state_type;

in_func = INFUNC;

int is_token_or_reserved(char **str, int size) {
    if (is_token(str) != NONE_T) {
        printf("%s\t\t%s\n", str, str);
        freeStrings(str);
        str = (char *) calloc((size + 1), sizeof(char));
        token_types t_type;
        return 1;
    }
    return 0;
}

//identif right now is coming back as number of variables. This isn't accurate, but we're close
int is_identif(char **str, int size) {
    if (is_token(str) == NONE_T) {
        printf("IDENIT\t\t%s\n", str);
        freeStrings(str);
        str = (char *) calloc((size + 1), sizeof(char));
        token_types t_type;
        return 1;
    }
    return 0;
}

int is_numeric(char **str, int size){
    if (is_num(str) == NUM) {
        printf("NUMBER\t\t%s\n", str);
        freeStrings(str);
        str = (char *) calloc((size + 1), sizeof(char));
        token_types t_type;
        return 1;
    }
    return 0;
}

//need to consider how to handle comments in code. Look ahead for / could be simply division or a comment!
int look_ahead_num(FILE *f, char **buffer) {
    char c;
    //get next char;
    c = fgetc(f);
    token_types tk_type;
    int buff_size;

    tk_type = is_char_token(c);
    //almost working, but need to figure out 2d operators like ==
    int match = 0;
    match = string_match(buffer, "=");
    if (c == '=' && match == 1) {
        buff_size = stringBuilder(buffer, c);

    } else {
        while (tk_type == NONE_T && is_token(buffer) == NONE_T && c != EOF) {
            buff_size = stringBuilder(buffer, c);
            c = fgetc(f);
            tk_type = is_char_token(c);
        }
        //only rewind pointer when we've built more than a 2d reserved word
        fseek(f, -1L, SEEK_CUR);
    }
    int holder = 0;
    holder = is_token_or_reserved(buffer, buff_size);
    if (holder == 0) {
        is_numeric(buffer, buff_size);
    }

    if (c == EOF) {
        return EOF;
    }
}

int look_ahead(FILE *f, char **buffer) {
    char c;
    //get next char;
    c = fgetc(f);
    token_types tk_type;
    int buff_size;

    tk_type = is_char_token(c);
    //almost working, but need to figure out 2d operators like ==
    int match = 0;
    match = string_match(buffer, "=");
    if (c == '=' && match == 1) {
        buff_size = stringBuilder(buffer, c);

    } else {
        while (tk_type == NONE_T && is_token(buffer) == NONE_T && c != EOF) {
            buff_size = stringBuilder(buffer, c);
            c = fgetc(f);
            tk_type = is_char_token(c);
        }
        //only rewind pointer when we've built more than a 2d reserved word
        fseek(f, -1L, SEEK_CUR);
    }
    int holder = 0;
    holder = is_token_or_reserved(buffer, buff_size);
    if (holder == 0) {
        is_identif(buffer, buff_size);
    }

    if (c == EOF) {
        return EOF;
    }
}

//we pass the source code file after main validates there are no unusual or invalid characters
void start_scanner(FILE *f) {
    char *running_str = (char *) malloc(0 * sizeof(char));
    int buff_size;
    char c;
    int is_numeric=0;


    state_type curnt_state = START;
    //first step to read in a char add in error checking
    //while the state is not DONE
    while (curnt_state != DONE) {
        c = fgetc(f);
        if (c <=59 && c >=48){
            buff_size = stringBuilder(running_str, c);
            buff_size = look_ahead_num(f, running_str);
        }
         else if (c != ' ' && c != '\n' ) {
            buff_size = stringBuilder(running_str, c);
            buff_size = look_ahead(f, running_str);
        }
        if (c == EOF || buff_size == EOF) {
            curnt_state = DONE;
        }

    }
}
