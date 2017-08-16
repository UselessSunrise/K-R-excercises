/*Exercise 2.9 from K&R*/
/* Applied to numbers in the representation of which an additional code is used,
The expression x &= (x-1) destroys the rightmost "1" in x. Explain why.
 Use this observation When writing a faster version of the "bitcount" function. */

#include <stdio.h>

/* It happens because in binary representation numbers "00100" and "100" are equal and the left "0" doesn't increase it's value.
 * That's why the rightmost "1" is being destroyed*/
int bitcount(unsigned x);

int main(){
    printf("%d single bits in this number \n",bitcount(14));
}

int bitcount(unsigned x){
    /*original version is
     * int b;
     * for (b = 0; x != 0; x >>= 1)
         if (x & 01)
           b++;
      return b;*/

      /*my version is*/
    int b;

    for(b = 0; x != 0; x &= (x - 1)){
        b++;/*Destroying the rightmost "1" and increase counter by 1 */
    }

    return b;
}
