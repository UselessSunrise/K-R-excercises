/* Exercise 4.12 from K&R */
/* Use ideas from printd to write recursive function itoa. Transform integer into line of characters using recursion */

#include <stdio.h>
#define MAXSIZE 100;

void itoa(int);
char s[100] = {' '};
int i = 0;

int main(){
    itoa(1234);
    printf("%s", s);
}

void itoa(int c){

    if(c < 0)
        s[i++] = '-';

    if(c / 10)
        itoa (c / 10);

    s[i++] = (char)(c % 10 + '0');
}