/* Exercise 4.2 from K&R*/
/* Upgrade function atof, so it will be able to deal with numbers like 123.456e-6 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMSIZE 100

double ato_f (char []);

int main(){
    char s[] = "123.456e-6";
    printf("%g", ato_f(s));
}

/* atof: changing line s into double */
double ato_f (char s[]) {
    double val, power,number;
    int i, sign, degree, degreesign;
    for (i = 0; isspace (s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit (s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] =='.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    number = sign * val / power;/*Number without degree*/

    if(s[i] == 'e' || s[i] == 'E'){
        i++;

        degreesign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
            i++;

        for (degree = 0; isdigit(s[i]); i++){
            degree = 10 * degree + (s[i] - '0');
        }

        if(abs(degree) <= 10){/*avoiding too high and too low numbers even if it's double*/
            if(degreesign < 0)
                for(int j = 0; j <= degree; j++)
                    number /= 10;
            else
                for(int j = 0; j <= degree; j++)
                    number *= 10;
        }
    }

    return number;
}