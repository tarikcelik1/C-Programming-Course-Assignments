#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {
 double PL,PW,SW,SL,x1,x2,x3;
 int choose,x4,x5,difference;

 

 printf("Enter what part do you use ; ");
 scanf("%d",&choose);                                 //to ask user what part of program he wants to run.

 if(choose == 1){
     printf("\n********--- PART 1 ---********\n\n");  //Part-1 code start.
     printf("Enter the PL,PW,SL,SW values: ");         //to get inputs from user whic are used in this part.
     scanf("%lf %lf %lf %lf",&PL,&PW,&SL,&SW);
     dt1a(PL, PW, SL, SW);  //to call the functions in the util.c.
     dt1b(PL, PW, SL, SW);
     if(dt1a(PL, PW, SL, SW) == dt1b(PL, PW, SL, SW) &&  dt1a(PL, PW, SL, SW) == 's'){
         printf("Result = Setosa\n");
     }
      if(dt1a(PL, PW, SL, SW) == dt1b(PL, PW, SL, SW) &&  dt1a(PL, PW, SL, SW) == 'v'){  //to compare the results that are comes from trees.
         printf("Result = Virginica\n");                                                 //if they are the same then print it.
     }
      if(dt1a(PL, PW, SL, SW) == dt1b(PL, PW, SL, SW) &&  dt1a(PL, PW, SL, SW) == 'e'){
         printf("Result = Versicolor\n");
     }
     if(dt1a(PL, PW, SL, SW) != dt1b(PL, PW, SL, SW) ){    
         if(dt1a(PL, PW, SL, SW) == 's'){
             printf("First result = Setosa\n");
         }
         if(dt1a(PL, PW, SL, SW) == 'v'){
             printf("First result = Virginica\n");
         }
         if(dt1a(PL, PW, SL, SW) == 'e'){
             printf("First result = Versicolor\n");   //if the results are different then print them seperately.
         }
         if(dt1b(PL, PW, SL, SW) == 's'){
             printf("Second result = Setosa\n");
         }
         if(dt1b(PL, PW, SL, SW) == 'v'){
             printf("Second result = Virginica\n");
         }
         if(dt1b(PL, PW, SL, SW) == 'e'){
             printf("Second result = Versicolor\n");
         }
     }
 }                                                   //Part-1 code end.
 else if(choose == 2){
     printf("\n********--- PART 2 ---********\n\n"); //Part-2 code start.
     printf("Enter x1,x2,x3,x4,x5 values : ");
     scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5); //to get user inputs which are used in this part.
     dt2a(x1,x2,x3,x4,x5);   //to call the functions in util.c.
     dt2b(x1,x2,x3,x4,x5);
     if(dt2a(x1,x2,x3,x4,x5)==dt2b(x1,x2,x3,x4,x5)){ //to compare the results of trees and if they are same then print it.
         printf("%lf\n",dt2a(x1,x2,x3,x4,x5));
         }
         if(dt2a(x1,x2,x3,x4,x5)!=dt2b(x1,x2,x3,x4,x5)){        
             difference = dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5);  //if they are different then calculate the difference of them.
             if(difference <= CLOSE_ENOUGH){                           //to check the difference is smaller or equal to the CLOSE_ENOUGH value.
                 printf("%lf",(dt2a(x1,x2,x3,x4,x5) + dt2b(x1,x2,x3,x4,x5))/2);
             }
             else {
             printf("\nFirst result : %.1lf\n",dt2a(x1,x2,x3,x4,x5));   //to print the different results.
             printf("Second result : %.1lf\n",dt2b(x1,x2,x3,x4,x5));
             }
         }
     
 }                                                       //Part-2 code end.
 else if(choose == 3){
     printf("\n********--- PART 3 ---********\n\n");     //Part-3 code start.
     printf("Enter x1,x2,x3,x4,x5 values : ");
     scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5); //to get user inputs which are used in this part.
     dt3a(x1,x2,x3,x4,x5);   //to call the functions in util.c.
     dt3b(x1,x2,x3,x4,x5);
     if(dt3a(x1,x2,x3,x4,x5)==dt3b(x1,x2,x3,x4,x5)){ //to compare the results of trees and if they are same then print it.
         printf("%lf\n",dt3a(x1,x2,x3,x4,x5));
         }
         if(dt3a(x1,x2,x3,x4,x5)!=dt3b(x1,x2,x3,x4,x5)){        
             difference = dt3a(x1,x2,x3,x4,x5)-dt3b(x1,x2,x3,x4,x5);  //if they are different then calculate the difference of them.
             if(difference <= CLOSE_ENOUGH){                           //to check the difference is smaller or equal to the CLOSE_ENOUGH value.
                 printf("%lf",(dt3a(x1,x2,x3,x4,x5) + dt3b(x1,x2,x3,x4,x5))/2);
             }
             else {
             printf("\nFirst result : %.1lf\n",dt3a(x1,x2,x3,x4,x5));   //to print the different results.
             printf("Second result : %.1lf\n",dt3b(x1,x2,x3,x4,x5));
             }
         }
     
 }                                                       //Part-3 code end.
else if(choose !=1 || choose !=2 || choose !=3){
     printf("Wrong choose !\n");
    
 }

    return 0;
}
