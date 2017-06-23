/*Exercise 2.4 from K&R*/
/* Write function squeeze(s1,s2) which delete all symbols from s1, existing in s2*/

#include <stdio.h>
#include <string.h>

void squeeze(char s1[],char s2[]);

void squeeze(char s1[],char s2[]){
    char symb;
    for(i = 0; i <= strlen(s2); i++ ) {
        symb = s2[i];
        int k, j;
        for (k = j = 0; k <= strlen(s1); k++) {
            if (s1[k] != symb)/*if current symbol is different from "symb", leave it in the line*/
                s1[j++] = s[k];
        }
    }
}