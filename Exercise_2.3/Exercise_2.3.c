/*Exercise 2.3 from K&R*/
/* Write function "htol(s)" which transforms hexadecimal number into correct integer*/

#include <stdio.h>

#define MAXSIZE 7 /*Maximum size of hexadecimal number*/

int htol(char s[]);
int power(int,  int);

int main(){

    char *c[MAXSIZE+2];/*adding 2 because hexadecimal num starts with "0x" or "0X"*/

    c[0] = 0;
    c[1] = "X";
    printf("Write a hexadecimal number(0..9,A..F or a..f) \n");
    for(int i = 2;i < MAXSIZE + 2 || c[i] != " " || c[i] != "\0";i++){
        c[i] = (char *) getchar();
    }

    printf("Number is - %d",htol((char *) c));
}

int htol(char s[MAXSIZE+2]){

    int number = 0;

    for(int i = 2;(i < MAXSIZE + 2);i++){
        if((s[MAXSIZE + 4 - i] >= '0') && (s[MAXSIZE + 4 - i] <= '9')){
            number += power(16, i-2) * (s[i] - '0');
        }
        if((s[MAXSIZE + 4 - i] >= 'a') && (s[MAXSIZE + 4 - i] <= 'f')){
            number += power(16, i-2) * (s[i] - 'a' + 9);
        }
        if((s[MAXSIZE + 4 - i] >= 'A') && (s[MAXSIZE + 4 - i] <= 'F')){
            number += power(16, i-2) * (s[i] - 'A' + 9);
        }
    }
    return number;
}

int power(int base,  int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}