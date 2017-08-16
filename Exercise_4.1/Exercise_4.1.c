/* Exercise 4.1 from K&R*/
/* Write function strindex(s, t) which returns position of the rightmost "t" in "s" or returns "-1", if there is no "t". */

#include <stdio.h>
#define MAXLINE 100

int strindex(char[], char []);

int main(){
    char s[MAXLINE],t[MAXLINE];

    for(int i = 0; i < MAXLINE; i++){/*filling s*/
        if ((s[i] = (char) getchar()) == '\n')
            break;
    }

    scanf(t);/*getting needed pattern*/

    printf("The rightmost %s in the %s has index %d",s,t,strindex(s,t));
}

int strindex(char s[],char t[]){
    int pos = -1;
    int j,k;
    for(int i = 0;s[i] != '\0'; i++){/*checking "s"*/
        for(j = i, k = 0;s[j] == t[k];j++,k++){
            if(k > 0 && t[k] == '\0'){
                pos = i;/*if pattern was found, set it's position into "pos" */
            }
        }
    }
    return pos;/*returns the rightmost position of "t" or "-1" - if nothing was found*/
}