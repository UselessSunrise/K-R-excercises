/*Exercise 3.2 from K&R*/
/*Write function escape(s,t) which transforms symbols like "new line" or "tab", while copying text from "t" to "s", into
 * "visible symbols" (like "\n" and "\t"). Use "switch" instruction. Write function which change "visible symbols" back. */

#include <stdio.h>

void escape(int [], int[]);

void escape(int s[], int t[]){
    int j = 0;
    for(int i = j; t[i] != EOF;i++){
        s[j] = t[i];
        switch(s[j]){
            case '\n': s[j] = '\\';
                s[j++] = 'n';
                break;
            case '\t': s[j] = '\\';
                s[j++] = 't';
                break;
            default: break;
        }
    }
}

