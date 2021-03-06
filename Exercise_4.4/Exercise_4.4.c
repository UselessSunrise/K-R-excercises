/* Exercise 4.4 from K&R */
/* Add commands with which would you be able to print top element(saving it in the stack), duplicate it in the stack,
 * swap to top elements in the stack. Add stack cleaning command. */

/*original code */

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operator or operand */
#define NUMBER '0' /* digit sign */

int getop (char []);
void push (double);
double pop (void);
void printtop(void);
void dupl(void);
void swap(void);
void clean(void);

/* calculator with reversed polish entry */
int main ()
{
    int type;
    double op2;
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

/*printtop:printing the top element from the stack */
void printtop(void){
    printf("top element from the stack: %g",val[sp]);
}

/*dupl: duplicate stacks' top element */

void dupl(void){
    val[sp+1] = val [sp];
}

/*swap: swaps two top elements in the stack */
void swap(void){
    double c;

    c = val[sp];
    val[sp] = val [sp-1];
    val[sp -1] = c;
}

/*clean: cleans the stack */
void clean(void){
    while(sp > 0)
        val[sp--] = 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: getting next operator or operand */
int getop(char s[])
{
    int i, c;
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

