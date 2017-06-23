/*/*Exercise 2.4 from K&R*/
/* Write function any(s1,s2) which returns position in s1, where is the first symbol, coinciding with any symbol from s2 or return -1 if there is no coincidences*/

#include <stdio.h>
#include <string.h>
int any(char s1[],char s2[]);

int any(char s1[],char s2[]){
    for(int i = 0; s1[i] != '\0'; i++){
        for(int j = 0; s2[j] != '\0';j++){
            if(s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}