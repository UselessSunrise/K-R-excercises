/*Exercise 2.6from K&R*/
/* Write function setbits(x,p,n,y), which returns "x" value, where "n" bits from position "p" changed to "n" right digits of "y" */

unsigned setbits(unsigned x,int p, int n, unsigned y);


unsigned setbits(unsigned x,int p, int n, unsigned y){
    y = y & ~(~0 << n); /*getting "n" right bits of "y"*/
    return (((((x >> p) << n) | y) << (p-n)) | (x & ~(~0 << n))); /* "((x >> p) << n)" sets "n" number of "0" in the end of the x;
 * "| y" changes these "0" to the right "n" bits of "y"
 * "<< (p-n)" adds "p-n" nulls which we need to save in the original "x"
 * "| (x & ~(~0 << n))" transforms these nulls into proper digits */
}