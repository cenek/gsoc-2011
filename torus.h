#ifndef TORUS_H_
#define TORUS_H_

/*input: pos-position individual's position
       nei-requested neighbor
            0|1|2
            - - -
            3|4|5
            - - -
            6|7|8
       nei = 0 -> top left neighbor
       nei = 1 -> top center neighbor
       nei = 2 -> top right neighbor
       nei = 3 -> left middle neighbor
       nei = 4 -> center neighbor
       nei = 5 -> right middle neighbor
       nei = 6 -> bottom left neighbor
       nei = 7 -> bottom center neighbor
       nei = 8 -> bottom right neighbor
thenever a calculation on a neighborhood, I use for loop that requests
all 9 negighbor positions...
output: position of a requested neighbor

int neighbor (int pos, int nei, int col, int pop){
*/

int neighbor (int, int, int, int);

#endif /*TORUS_H_*/
