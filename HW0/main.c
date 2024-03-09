#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
  int mynum1, mynum2, mynum3, myden1, myden2, myden3;
  
  printf("\n \n Please enter the first fractional number : \n");
  scanf ("%d %d" ,&mynum1, &myden1);
                                         /* to get user inputs for the fractional numbers.*/
  printf("Please enter the second fractional number : \n");
  scanf("%d %d" ,&mynum2,&myden2);
  
  printf("First number : %d//%d \n Second number : %d//%d \n",mynum1,myden1,mynum2,myden2);
  
  
    printf("Addition: ");
    fraction_add(mynum1, myden1, mynum2, myden2, &mynum3, &myden3);
    fraction_print(mynum3, myden3);
    printf("\n");
    
    printf("Subtraction: ");
    fraction_sub(mynum1, myden1, mynum2, myden2, &mynum3, &myden3);
    fraction_print(mynum3, myden3);
    printf("\n");
    
    printf("Multiplication: ");
    fraction_mul(mynum1, myden1, mynum2, myden2, &mynum3, &myden3);
    fraction_print(mynum3, myden3);
    printf("\n");
    
    
    printf("Division: ");
    fraction_div(mynum1, myden1, mynum2, myden2, &mynum3, &myden3);
    fraction_print(mynum3, myden3);
    printf("\n");
  

    return(0);
}
