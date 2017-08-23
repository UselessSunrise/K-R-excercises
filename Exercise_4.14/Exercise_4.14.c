/* Exercise 4.13 from K&R */
/* Define swap(t,x,y) as macros, which swaps values of type t between x and y */

#include <stdio.h>

#define swap(t, x ,y) t temp1 = y \
    t temp2 = x\
    y =  temp2 \
    x = temp1

int main() {
    int x = 3;
    int y = 7;

    printf("%d %d \n", x, y);

    swap(float, x, y);

    printf("%d %d \n", x, y);

    return 0;
}