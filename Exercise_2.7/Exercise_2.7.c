/*Exercise 2.7 from K&R*/
/* Write function invert(х, р, n) which returns "x" value with inverted "n" bits from the "p" position*/

unsigned invert(unsigned x, int p, int n);

unsigned invert(unsigned x, int p, int n){
    return(((x >> p) << p) | (~((x >>(p - n)) & ~(~0 << n)) <<(p-n)) | (x & ~(~0 << n)));
    /*"((x >> p) << p)" sets "p" right bits to null
     * "(~((x >>(p - n)) & ~(~0 << n)) <<(p-n))" adds "p" bits with "n" inverted
     * "| (x & ~(~0 << n))" sets the right "null bits" as in the original x */
}
