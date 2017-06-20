/*Excercise 2.2 from K&R*/
/* Write "for" construction equal to
 * "for (i = 0; i < lim-1 && (с = getchar()) != EOF && с != '\n'; ++i)
 * s[i] = c;
 * without using "&&" and "||" */

/* I'll copy the full code, incuding "for", and change this part
 * this is original code*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum size of line */

int gotline(char linef[], int );
void copy(char to[], char fromf[]);

/* printing the longest line */
main()
{
    int len; /* current line's length */
    int max; /* max length */
    char line[MAXLINE]; /* current line */
    char longest[MAXLINE]; /* the longest line */
    max = 0;

    while ((len = gotline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0) /* was there any strings? */
        printf("%s", longest);
    return 0;
}


/* getline: reads a line of s, returns length */
int gotline(char s[], int lim)
{
    int  c,i;


    /*this is a part we need to change */
    for (i = 0; i < lim-1; ++i)
        if((c = getchar()) != EOF) /*we can check "for" conditions using "if-then-else"*/
            if(c != '\n')/*If condition is false, we use "break"*/
                s[i] = c;
            else break;
        else break;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}


/* copy: copy from 'from' to 'to'; to is big enough */
void copy(char to[], char from[])
{
    int i;i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

