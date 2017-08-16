/*Exercise 3.3 from K&R*/
/*Write function expand(s1, s2) changing "a-z" in s1 to equal "abc...xyz" in s2. In s1 there might be letters and digits.
 * You have to deal with cases like "a-b-c", "a-z0-9" and "-a-b". Sign "-" in the beginning or ending of s1 count as "minus" */

#include <stdio.h>

void expand(char [],char []);

void expand(char s1[],char s2[]){
    int i,j;
    for (i = j = 0;s1[i] != '\0';i++, j++){
        if(((s2[j] = s1[i])== '-') && (i != 0)){
            if(s1[i-1]>= 'a' && s1[i+1]>= s1[i-1] && s1[i+1]<= 'z')/*filling with letters form "a" to "z"*/
                for (int k = s1[i-1]+1; k < s1[i+1]; k++)/* these values of "k" will help dodging situations like "a-b-c" */
                    s2[j++] = (char) k;/*all "k" letters are local, so they won't "hide" each other */
            else if(s1[i-1]>= 'A' && s1[i+1]>= s1[i-1] && s1[i+1]<= 'Z')/*same thing with "A - Z"*/
                for (int k = s1[i-1]+1; k < s1[i+1]; k++)
                    s2[j++] = (char) k;
            else if(s1[i-1]>= '0' && s1[i+1]>= s1[i-1] && s1[i+1]<= '9')/*And the digits "0 - 9"*/
                for (int k = s1[i-1]+1; k < s1[i+1]; k++)
                    s2[j++] = (char) k;
        }
    }
}