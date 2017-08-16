/*Exercise 3.4 from K&R*/
/*In two's complement number representation, our version of itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of the
 * machine on which it runs*/

/* The problem is that the absolute of INT_MIN(-2147483648) is "1" bigger than absolute of INT_MAX(2147483647)
 * so when we make n positive we try to fit value, bigger than INT_MAX, into INT type.
 * So we need to calculate sign without making n positive and calculate(again) digits using "abs" */

#include <stdlib.h>
#include <memory.h>

void reverse(char []);
void itoa(int , char[]);

/* itoa: changing n to characters in s */
void itoa (int n, char s[]) {
    int i, sign;
    /*Changing "sign" part*/

    //if ((sign = n) < 0) /* saving a sign */
        //n = -n; /* making n positive */

    sign = (n < 0) ? -1 : 1;/*Doesn't make n positive*/

    i = 0;
    do { /* generate digits in reverse order */
        /*using absolute numbers*/
        s[i++] = (char) (abs(n % 10) + '0'); /* next digit */
    } while (abs(n /= 10) > 0); /* delete it using "abs"*/
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
} /*Fixed version is done*/

void reverse (char s[]){
    int c,i;
    long j;
    for(i = 0,j = strlen (s) - 1; i <= j; i++ , j--){
        c = s[i];
        s[i] = s[j];
        s[j] = (char) c;
    }
}