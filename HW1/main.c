#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <string.h>


int main() {

  int x,y,z,n,f_I,p,password=1453;
  float cash_amount;
  char identity_number[11];

    printf("\n\n************ WELCOME ************\n\n\n");
    printf("************** PART 1 **********\n\n");               //Part 1 starts here.

    printf("Enter the first integer : ");  
    scanf("%d",&x);

    printf("Enter the second integer : ");      //to get inputs from user.
    scanf("%d",&y);

    printf("Enter the divisor : ");
    scanf("%d",&z);

   find_divisible(x,y,z);               //to call find_divisible function.
   
   f_I = find_divisible(x,y,z);
  
   if(f_I != 0){
     printf("\nEnter the number how many next : \n");  //to get input from user for n value.
     scanf("%d",&n);

     find_nth_divisible (n,f_I,z);                 //to call find_nth_divisible function.
     if(find_nth_divisible (n,f_I,z) <= y){
     printf("The %dth integer between %d and %d divided by %d is %d",n+1,x,y,z,find_nth_divisible (n,f_I,z));
     }
     else {
       printf("The %dth integer is not between %d and %d.\n",n+1,x,y);
     }

    }
  
printf("\n\n************** PART 2 *************\n\n");    //Part 2 starts here.
  
printf("Enter your identity number : ");             //get user input for identity number.
scanf(" %[^\n]s", identity_number );

validate_identity_number (identity_number);      //checking identity number validate or not.

if(validate_identity_number (identity_number) == 1){

create_customer(identity_number,password);     //creating customer account and save to text file.

printf("\nAccount created succesfully.\n");
 
printf("\n\n************* PART 3 ***********\n\n");  //Part 3 starts here.
check_login(identity_number,password);               //to calling check_login function.

if(check_login(identity_number,password)==1){        //checking identity number and password correct or not.
  printf("Login Sucessful.\n");
  withdrawable_amount(cash_amount);             //to calling withdrawable_amount function.
}
else {
  printf("Invalid identity number or password.\n");
}

}
else
    return(0);                                //end of the main code.
}
