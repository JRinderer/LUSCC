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
    int type=NONE_C;
    //this is a letter
    if(c >=65 && c<=122){
        type=LTR;
    //this is an END OF FIELD
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

char_type is_spce(char c){
    int type= NONE_C;
    if(c ==32 || c==9) {
        type = SPC;
    }
    return type;
}

/*the below are what I'm calling 1 dimensional tokes. They're all characters we can compare. Some things can't be compared
like == != >= <= <>. These are similar to the 2d operators I had in KLUMP
*/

token_types is_1d_token(char c){

    int t_type = NONE_T;
    switch(c){
        case(43):
            t_type = PLUS;
            break;
        case(42):
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
        case(32):
            t_type = IGN;
            break;
        case(9):
            t_type = IGN;
            break;
        default:
            //consider alternative. It may not be an error because it could be a 2 dimensional operator.
            t_type = NONE_T;
            break;
    }
  return t_type;
}

int string_match(char *str1, char *str2){
    unsigned int size1 = strlen(str1);
    unsigned int size2 = strlen(str2);

    int i=0; int j =0;


    if(size1 != size2){
        return 0;
    }

    while(str1[i]!='\0'){
        if(str1[i]==str2[i]){
            j++;
        }
        i++;
    }

    if(j == size1){
        return 1;
    }

}

void freeStrings(char **strng){
    free(strng);
    //strng = NULL;
}

#endif //LUSCC_UNIVERSAL_FUNCS_H
