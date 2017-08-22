/* Exercise 4.10 from K&R */
/* Calculator can use function getline, which reads the whole line. This way we don't need getch and ungetch
 * Write program, using this function */


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
    ssize_t len = 0;
    while(len == getline((char **) &s, 0, stdin))
    while ((type = getop (s))!= EOF) {
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


/* getop: getting next operator or operand */
int getop(char s[])
{
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t' )
        ++i;

    s[1] = '\0';

    if (!isdigit(s[i]) && s[i] != '.')
        return s[i]; /* not a digit */
    i = 0;

    if (isdigit(s[i])) /* accumulating integer part */
        while (isdigit(s[++i]))
            ;
    if (s[i] == '.') /* accumulating fractional part */
        while (isdigit(s[++i]))
            ;
    s[i] = '\0';
    if (s[i] != EOF)
        --s;

    return NUMBER;
}

