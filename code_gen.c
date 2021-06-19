//
// Created by jrinder on 6/19/21.
//
//.globl  main
//main:                                   # @main
//# %bb.0:
//        movl    $2, %eax
//        popq    %rbp
//        retq


#include "code_gen.h"
#include <string.h>

void write_ln(FILE *f, char *lne){
    fprintf(f,"%s\n",lne);
}


void gen1_code(char *int_value){
    FILE *file = "out.asm";
    //write_ln(file,"main:");
    char *assembly_line= (char *) malloc(0 * sizeof(char));
    char *var_sing = "$";
    char *registr = "%eax";
    char *cmd = "movl";
    int buff_size;


    string_assembler_strt(assembly_line,"test dicks");
    printf("%s",assembly_line);
}