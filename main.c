/* "main" function in root directory to check exercises */
#include <stdio.h>
#include <Exercise_2.9>

int main(){
    extern int bitcount(unsigned);
    printf("%d \n", bitcount(4));
    return 0;
}

