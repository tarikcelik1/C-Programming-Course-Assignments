#include <stdio.h>
#include "util.h"
#include <string.h>
#include <stdlib.h>

int find_divisible (int x, int y, int z){        //to create function.
  int a;
        for(int i=x; i<=y; i++){
  
         if( i%z == 0){  //to find the first divisible integer between x and y.

              printf("The first integer between %d and %d divided by %d is %d.\n",x,y,z,i);
              return i;
              a = 1;
  }
 }
       if(a!=1){
        printf("There is not any integer between %d and %d divided by %d.\n",x,y,z);
        return 0;
      
    }   
  
  
}

int find_nth_divisible (int n , int f_I, int z ) {      //to create function.
     int num ;

     num = f_I + (z*n);  //to find nth divisible integer between x and y.

     return num;
}


int validate_identity_number ( char identity_number[])   //to create function.
{
    if(identity_number[0]-48 == 0)  //to check firs digit of identity number zero or not.
      return 0;
  int sum_of_first_10_digit= 0;   
  int i=0;
    while( i< 10   )               //to calculate sum of first ten digit.
     {
      sum_of_first_10_digit += identity_number[i] - 48;
      i++;
     }
  sum_of_first_10_digit = sum_of_first_10_digit %10;  //to calculate mod(10) of sum of first 10 digit.
  int eleventh_digit = identity_number[10] -48;

    if( sum_of_first_10_digit != eleventh_digit )  //to check the eleventh digit true or not.
     return 0;


  int sum_of_odd_digits= 0;
  i=0;
    while( i<9 )                                    //to calculate sum of the odd digits.
     {
      sum_of_odd_digits += identity_number[i] - 48 ; 
      i+=2;
     }
  int temp= sum_of_odd_digits;

  sum_of_odd_digits = sum_of_odd_digits *7;   //to calculate sum of odd digits times 7.

  int sum_of_even_digits= 0;
  i=1;
    while( i<8 )                              //to calcualte sum of even digits.
     {
      sum_of_even_digits += identity_number[i] - 48 ;
      i+=2;
     }
 
  int tenth_digit = identity_number[9] - 48;
    if(  ( sum_of_odd_digits - sum_of_even_digits ) %10  != tenth_digit ) //to check the tenth digit true or not.
     return 0;

 
return 1;
}



int create_customer(char identity_number[],int password){  //to create function.

  FILE *file = fopen("customeraccount.txt","w+");

    if(file=fopen("customeraccount.txt","w+")){      //to write the text file.
      fprintf(file,"%s,%d",identity_number,password);
      fclose(file);

    }
    else
      printf("File not founded.\n");
}


int check_login(char identity_number[],int password){  //to create function.
   char identity[11], pasword[4];
   
   FILE *file = fopen("customeraccount.txt","r+");  //to opening file for reading.

    if((file=fopen("customeraccount.txt","r+")) != NULL){
      fscanf(file,"%s",&identity);                          //reading data from file.
      fscanf(file,"%s",&pasword);                    

      if(identity !=identity_number){            
      return 0;
      }
      if(pasword !=password){                   //checking the identity and password valid or not.
      return 0;
      }
      else
      return 1;



    }
    else
    printf("File not founded.\n");
}

int withdrawable_amount(float cash_amount){

  int temp , withdrawable;

     printf("Enter your withdraw amount: \n");  //to get inout from user for cash amount.
     scanf("%f",&cash_amount);

     temp = cash_amount;
                                             //for calculate the withdrawable value of cash.
     temp = temp%50;
     temp = temp%20;
     temp = temp%10;

     withdrawable = cash_amount - temp;

     printf("Withdrawable amount is %d.\n",withdrawable);
  return 0;
                                                                   
}




 




