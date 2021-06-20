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


void print_header(){
    FILE *file = fopen("out.asm","a");
    write_ln(file, "global\t_start");
    write_ln(file, "section .txt");
}


void print()


void gen1_code(char *int_value){
    FILE *file = fopen("out.asm","a");
    //write_ln(file,"main:");
    char *assembly_line= (char *) malloc(0 * sizeof(char));
    char *var_sing = "$";
    char *registr = "%eax";
    char *cmd = "movl";
    int buff_size;


    write_ln(file,".globl\tmain");
    write_ln(file,"main:");
    string_assembler_strt(assembly_line,cmd);
    string_assembler_strt(assembly_line,"\t");
    string_assembler_strt(assembly_line,"$");
    string_assembler_strt(assembly_line,int_value);
    string_assembler_strt(assembly_line,",\t");
    string_assembler_strt(assembly_line,registr);
    write_ln(file,assembly_line);
    freeStrings(assembly_line);

    assembly_line= (char *) malloc(0 * sizeof(char));

    string_assembler_strt(assembly_line, "retq");
    write_ln(file,assembly_line);

}

