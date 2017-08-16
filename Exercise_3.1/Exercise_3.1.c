/*Exercise 3.1 from K&R */
/*In our binary search program there are two condition checks inside the loop
 * but there could be only one check(by increasing checks outside the loop).
 * Write program, using only one inside-loop checking. Take a look at the time required for the program. */

#include <stdio.h>

/* original code
 * int binsearch(int x, int v[], int n)
{
int low, high, mid;
low = 0;
high = n - 1 ;
while (low <= high) {
mid = (low + high) / 2;
if (x < v[mid])
high = mid - 1;
else if (x > v[mid])
low = mid + 1 ;
else
return mid;
}
return -1;
}
*/

/*My variant*/

int binsearch(int , int v[], int);

int binsearch(int x,int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (low + high) / 2;
    while (x != v[mid]){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid -1;
        else low = mid + 1;
    }
    if(mid >= 0 && mid <= n-1)
        return mid;
    else return -1;
}

