/*Exercise 2.8 from K&R*/
/* Write function rightrot(х, n) which cyclically moves "x" to the right by the "n" digits */

unsigned rightrot(unsigned x, int n);

unsigned rightrot(unsigned x, int n){
    for(int i = 1; i <= n; i++){
        (x << 1);
    }

    return x; /* This is how I understand the task, maybe it's not the correct idea */
}
