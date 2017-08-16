/*Exercise 2.10 from K&R*/
/*Write function "lower" which transforms large letters into small, using conditional operator(not the "if-else" construction"*/

int lower(int c);

int lower(int c){
    c = (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;/*if "c" is between A and Z change it to the letter between a and z else - doesn't change "c" */
    return c;
}

