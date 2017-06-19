/*Exercise 2.1 from K&R*/
/*Write program wich shows ranges of char, short, int, (signed and usigned), float and double */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    printf("signed ranges: char - %d/%d,int - %d/%d, short - %d/%d, long - %li/%li, float - %f/%f, double - %f/%f \n",SCHAR_MAX,SCHAR_MIN,INT_MAX,INT_MIN,SHRT_MAX,SHRT_MIN,LONG_MAX,LONG_MIN,FLT_MAX,FLT_MIN,DBL_MAX,DBL_MIN);
    printf("unsigned ranges:char - %d/%d,int - %d/%d, short - %d/%d, long - %li/%d \n",UCHAR_MAX,0,UINT_MAX,0,USHRT_MAX,0,ULONG_MAX,0);
}



