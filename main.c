#include <ctype.h>
#include "global_defs.h"
#include "scanner.h"
#include "universal_funcs.h"

int main(int argc, char *argv[]) {
    FILE *filePtr;
    //-----process cmd args
    switch (argc) {
        case 1:
            filePtr = stdin;
            break;
        case 2:
            if((filePtr = fopen(strcat(argv[1], ".sc"),"r"))==NULL){
                printf("Cannot open the input file. Validate the file exists");
                exit(1);
            }
            break;
        default:
            printf("Unable to open file. The extension .sc is implicit.");
            exit(0);

    }
    
    //----end of cmd process---

    //----check if file is empty
    char c;
    int numLine = 1;

    int charCount = 0;
    char tempStr[MAX];

    int i;

    int isValid = 1; //1 is true
    //loop through file
    while ((c=fgetc(filePtr))!= EOF){
        //printf("%c",c);
        if(c =='\n'){
            numLine++;
        }

        if(c == '/'){
            if (fgetc(filePtr)== '/'){
                while((c=fgetc(filePtr))!='\n'){
                    numLine++;
                }
            }
        }
        if(isalnum(c)){
            tempStr[charCount] =c;
            charCount++;
            if(charCount>MAX) {
                printf("Word '%s' on line number %d is too long. \n", tempStr, numLine);
                exit(1);
            }
        }else if(isspace(c)|| isExAcceptableChar(c)){
            charCount =0;
        }else{
            printf("Invalid character '%c' at line %d.\n",c,numLine);
            isValid = 0;
        }
    }

    if(isValid==0){
        printf("An error occured in the input file");
        exit(1);
    }

    rewind(filePtr);

    start_scanner(filePtr);

    return 0;
}
