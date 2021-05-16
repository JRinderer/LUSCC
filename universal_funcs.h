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

/*the below are what I'm calling 1 dimensional tokes. They're all characters we can compare. Some things can't be compared
like == != >= <= <>. These are similar to the 2d operators I had in KLUMP
*/

token_types is_1d_token(char c){
    /*
    //reserved words
    IF,ELSE, INT, RETURN, VOID, WHILE,
            //symbols
            PLUS,MINUS,TIMES,DIVIDE,LPAREN,RPAREN,LBRACKET,RBRACKET,LCURLY,RCURLY,SEMICOL,ASSIGN,EQL,NTEQL,COMMA, STCMT,ENCMT
            */
    int t_type = ERR;
    switch(c){
        case(43):
            t_type = PLUS;
            break;
        case(32):
            t_type = TIMES;
            break;
        case(47):
            t_type = DIVIDE;
            break;
        case(45):
            t_type = MINUS;
            break;
        case(40):
            t_type = LPAREN;
            break;
        case(41):
            t_type = RPAREN;
            break;
        case(91):
            t_type = LBRACKET;
            break;
        case(93):
            t_type = RBRACKET;
            break;
        case(123):
            t_type = LCURLY;
            break;
        case(125):
            t_type = RCURLY;
            break;
        case(59):
            t_type = SEMICOL;
            break;
        case(61):
            //this is = we need to think about how to deal with == for equality tests! but it won't be in here
            t_type = ASSIGN;
            break;
        case(44):
            t_type = COMMA;
            break;
        default:
            //consider alternative. It may not be an error because it could be a 2 dimensional operator.
            t_type = ERR;
            break
    }
  return t_type;
}

void freeStrings(char **strng){
    free(strng);
    //strng = NULL;
}

#endif //LUSCC_UNIVERSAL_FUNCS_H
