/* Exercise 4.11 from K&R */
/* Modify getop to avoid using ungetch (use inner static variable) */


#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operator or operand */
#define NUMBER '0' /* digit sign */

int getop (char []);
void push (double);
double pop (void);


/* calculator with reversed polish entry */
int main ()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop (s))) {
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
            case 'EOF':
                printf("End of the file reached, calculating stopped.");
                return 0;
            default:
                printf("error: unknown operation %s\n", s);
                break;

        }
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

int getch(void);
void ungetch(int);

/* getop: getting next operator or operand */
int getop(char s[])
{
    int i, c;
    static int lastsymb = ' ';

    while ((s[0] = (char)(c = (char)getch())) == ' ' || c == '\t' )
        ;

    s[1] = '\0';

    if(lastsymb != ' ')
        c = lastsymb;

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
        lastsymb = c; /*saving last symbol instead of returning it into input */

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for getch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* take ( maybe returned) symbol */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

