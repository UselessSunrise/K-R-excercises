/* Exercise 4.13 from K&R */
/* Write function reverse(s) which puts elements from s in reversed order */

#include <stdio.h>
#include <memory.h>

void reverse(char []);

char s[] = "Hello, m8";
int i = 0;

int main(){
    reverse(s);
    printf("%s",s);
}

void reverse(char s[]){
    char temp;
    if(i <= strlen(s) - 1 - i) {
        temp = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp;
        i++;
        reverse(s);
    }
}