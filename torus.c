#include <stdio.h>
#include <stdlib.h>

/*
Calculates a position of a requested neighbor based on the spatial position
and neighbor requested
input: pos-position individual's position
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
*/

int neighbor (int pos, int nei, int col, int pop){
  int P_SIZE    = pop;
  int SIDE_SIZE = col;

  if(nei<0 ||nei>8||pos<0||col<1||pop<1){
    printf("Illegal parameter\n");
    exit(0);}

   if (nei==0){
      //top left neighbor
     if((pos+1)==1){
         //top left corner
         return P_SIZE-1;
      }else if(pos<SIDE_SIZE){
         //if top row
         return (P_SIZE-SIDE_SIZE+pos-1);
     }else if((pos+1)%SIDE_SIZE==1){
         //if left column
         return (pos-1);
      }else{
         return (pos-SIDE_SIZE-1);
      }

   }else if(nei==1){
      //top center neighbor
      if(pos<SIDE_SIZE){
         //top row
         return P_SIZE-SIDE_SIZE+pos;
      }else{
         return (pos-SIDE_SIZE);
      }
   }else if (nei==2){
      //top right neighbor
      if((pos+1)==SIDE_SIZE){
         //top right corner
         return (P_SIZE-SIDE_SIZE);
      }else if(pos<SIDE_SIZE){
         //top row
         return (P_SIZE-SIDE_SIZE+pos+1);
      }else if((pos+1)%SIDE_SIZE==0){
         //right side
         return (pos-SIDE_SIZE-SIDE_SIZE+1);
      }else{
         return (pos-SIDE_SIZE+1);
      }
   }else if(nei==3){
      //left center neighbor
      if((pos+1)%SIDE_SIZE==1){
         //left side
         return (SIDE_SIZE+pos-1);
      }else{
         return (pos-1);
      }
   }else if (nei==4){
      //middle neighbor
      return pos;
   }else if (nei==5){
      //right center neighbor
      if((pos+1)%SIDE_SIZE==0){
         //right side
         return (pos-SIDE_SIZE+1);
      }else{
         return (pos+1);
      }
   }else if (nei==6){
      //bottom left neighbor
      if(pos==P_SIZE-SIDE_SIZE){
         //bottom left hand corner
         return SIDE_SIZE-1;
      }else if(pos<P_SIZE && pos>=(P_SIZE-SIDE_SIZE)){
         //bottom side
         return (SIDE_SIZE-(P_SIZE-pos)-1);
      }else if((pos+1)%SIDE_SIZE==1){
         //left side
         return (pos+SIDE_SIZE+SIDE_SIZE-1);
      }else{
         return (pos+SIDE_SIZE-1);
      }
   }else if (nei==7){
      //bottom center neighbor
      if(pos<P_SIZE && pos>=(P_SIZE-SIDE_SIZE)){
         //bottom side
         return (SIDE_SIZE-(P_SIZE-pos));
      }else{
         return (pos+SIDE_SIZE);
      }
   }else if (nei==8){
      //bottom right neighbor
      if(pos==(P_SIZE-1)){
         //bottom right hand corner
         return 0;
      }else if((pos+1)%SIDE_SIZE==0){
         //right side
         return (pos+1);
      }else if(pos<P_SIZE && pos>=(P_SIZE-SIDE_SIZE)){
        //bottom side
         return (SIDE_SIZE-(P_SIZE-pos)+1);
      }else{
         return (pos+SIDE_SIZE+1);
      }
   }else{
      printf("Illegal parameter");
   }
   return -1;
}

