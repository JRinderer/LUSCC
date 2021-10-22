//
// Created by jrinder on 5/15/21.
//

#ifndef LUSCC_UNIVERSAL_FUNCS_H
#define LUSCC_UNIVERSAL_FUNCS_H

#include <string.h>
#include "global_defs.h"

int isExAcceptableChar(char c);

int stringBuilder(char **strng, char c);

//remember chars in C start at 65 and run to 122
char_type isLetter(char c);

char_type is_spce(char c);

/*the below are what I'm calling 1 dimensional tokes. They're all characters we can compare. Some things can't be compared
like == != >= <= <>. These are similar to the 2d operators I had in KLUMP
*/

token_types is_char_token(char c);



int string_match(char *str1, char *str2);

token_types is_token(char *str);

token_types is_reserved_word(char *str);

void freeStrings(char **strng);

#endif //LUSCC_UNIVERSAL_FUNCS_H
