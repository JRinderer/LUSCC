//
// Created by jrinder on 5/15/21.
//

#ifndef LUSCC_UNIVERSAL_FUNCS_H
#define LUSCC_UNIVERSAL_FUNCS_H

int isExAcceptableChar(char c) {
    if (c == '.' || c == '(' || c == ')' || c == ',' || c =='{' || c == '}' ||
        c == ';' || c == '[' || c == ']' ||
        c == ':' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
        c == '=' || c == '<' || c == '>' || c == '!' || c == '"' || c == '#' || c=='\''
        /* || c == '#' */ ) {

        return 1;
    } else
        return 0;
}

int stringBuilder(char **strng, char c){
    int size=0;
    int i=0;

    char *temp_pntr = (char*)malloc(size+1 * sizeof(char));
    temp_pntr = strng;
    int size2 = strlen(strng);
    temp_pntr[size2]=c;

    strng = realloc(strng,size+1);
    strng = temp_pntr;
    return size2;


}

//remember chars in C start at 65 and run to 122
char_type isLetter(char c){
    int type=ERR;
    //this is a letter
    if(c >=65 && c<=122){
        type=LTR;
    //this is a space, or other seperator
    }else if(c == 32 || c==9){
        type=SPC;
    //this is an END OF FIELD
    }else if(c==EOF){
        type=END;
    //this is a number
    }else if(c >=48 && c <=57){
        type=NUM;
    }
    return type;
}

void freeStrings(char **strng){
    free(strng);
    //strng = NULL;
}

#endif //LUSCC_UNIVERSAL_FUNCS_H
