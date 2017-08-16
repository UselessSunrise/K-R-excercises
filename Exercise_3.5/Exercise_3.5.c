/*Exercise 3.5 from K&R*/
/* Write function itob(n, s, b), which transforms integer "n" into line "s", in "b"'s representation.
 * For example, itob(n, s, 16) puts into "s" text of "n" in hexadecimal representation. */

#include <string.h>
#include <stdlib.h>
void itob(int, char[], int);
void reverse(char []);

void itob(int n, char s[], int b){
    if(b <= 16){/*Made hexadecimal the highest variant of representation to reduce amount of possible problems */
        int sign;
        int i =  0;
        sign = (n < 0) ? -1 : 1 ;
        do{
            s[i] = (char)(abs(n) % b);/*get next digit */
            if(abs(n) % b > 9){
                s[i] = (char) ('A' + (abs(n) % b) - 10);/*transform it into a letter if necessary */
            }
            i++;
        } while(abs(n /= b) > 0);/*delete this digit*/
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
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

