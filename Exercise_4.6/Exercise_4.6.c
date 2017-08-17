/* Exercise 4.6 from K&R */
/* Add commands to work with variables
 * Add variable for saving last printed value*/


#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operator or operand */
#define NUMBER '0' /* digit sign */

int getop (char []);
void push (double);
double pop (void);


double var[26] = {0.0}, lv;/*26 letters are going to be variables; lv - last value */
char key[] = "stvr"; /* key word for saving variables */

/* calculator with reversed polish entry */
int main ()
{
    int type;
    double op2; /*26 letters are going to be variables; lv - last value */
    char s[MAXOP];
    while ((type = getop (s)) != EOF) {
        switch (type) {
            case NUMBER:push (atof (s));
                break;
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                else
                    printf("error: dividing on nil\n");
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            case 'a': case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':case 'n':case 'o':
            case 'p':case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':push(var[type - 'a']);
                break;
            default:
                printf("error: unknown operation %s\n", s);
                break;

        }

        push(lv = pop());/* saving last printed value */

    }
    return 0;
}

#define MAXVAL 100 /* max stack depth */
int sp = 0; /* next free position in stack */
double val[ MAXVAL ]; /* stack */

/* push: put value f into stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf( "error stack is full, %g can't be put \n", f);
}
/* pop: get from the top and return as the result */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf( "error: stack is empty \n");
        return 0.0;
    }
}

#include <ctype.h>
#include <memory.h>

int getch(void);
void ungetch(int);
void setvar(char []);/*to call setvar function you have to write stvr+variable name(like stvra) */

/* getop: getting next operator or operand */
int getop(char s[])
{
    int i, c, j, k;

    for(j = k = 0;s[j] == key[k] && k <= (strlen(key)-1); j++,k++){
        if(k == (strlen(key)-1))
            setvar(s);
        s[j] = ' ';
    }/*checking for setvar combination */

    while ((c = s[0] = (char)getch()) == ' ' || c == '\t' )
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a digit */
    i = 0;

    if (isdigit(c)) /* accumulating integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* accumulating fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

void setvar(char s[]){
    int c = s[4]; /* first 4 positions are "stvr" so variable name is on fifth */
    var[c - 'a'] = val[sp];/* saving in variable current stack positions' value */
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* take ( maybe returned) symbol */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int с) /* return symbol to input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many symbols\n");
    else
        buf[bufp++] = (char) с;
}

