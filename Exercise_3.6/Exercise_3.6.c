/*Exercise 3.6 from K&R*/
/* write itoa version with additional third argument which sets minimum length
 * number must be updated with spaces at the left side if needed*/

#include <stdlib.h>
#include <memory.h>

void reverse(char []);
void itoa(int , char[], int);

/* itoa: changing n to characters in s */
/* taken itoa from 3.4 */
void itoa (int n, char s[], int len) {
    int i, sign;

    sign = (n < 0) ? -1 : 1;

    i = 0;
    do {
        s[i++] = (char) (abs(n % 10) + '0');
    } while (abs(n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    if(i < len){
        do
            s[i++] = ' ';/* adding spaces before reversing*/
        while(i < len);
    }
    s[i] = '\0';
    reverse(s);
}

void reverse (char s[]){
    int c,i;
    long j;
    for(i = 0,j = strlen (s) - 1; i <= j; i++ , j--){
        c = s[i];
        s[i] = s[j];
        s[j] = (char) c;
    }
}