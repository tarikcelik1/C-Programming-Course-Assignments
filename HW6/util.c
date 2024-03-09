#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void generate_sequence (int xs, int currentlen, int seqlen, int *seq){ //to create generate_sequence function.
/*
*This function builds sequence with using user inputs for sequence length and first element of sequence.
*
*And this function fills the seq array with sequence elements.
*
*It is a recursive function.
*This function returns nothing.
*/
    seq[0] = xs;

        if(seq[currentlen]%2==0)  //to checking element of sequence is odd or even.
            seq[currentlen + 1] = seq[currentlen]/2;  //to create next term of the sequence.
        else 
            seq[currentlen + 1] = (3*seq[currentlen]) + 1;

    currentlen++;
        if(currentlen != seqlen)   //to checking sequence length is equal or not equal to user input.
            generate_sequence (xs,currentlen,seqlen,seq);  //to call same function for the next term of sequence.
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le){ //to create has_loop function.
/*
*This function checks is there any loop in given array with using given loop length.
*
*If there is a loop with given lentgh in the given  array this function returns 1.
*If there is not loop with given lentgh in the given  array this function returns 0.
*
*/
    int x = 0;
   
        if(arr[n-looplen]==arr[n-2*looplen]){    //to checking the elements of array are equal or not.
            
            x++;
            (*le)=n-looplen-1; //to get loop end index.
            
        }
    if(x==1) {  //to check there is a loop.
        
        return 1;
    
    }
    else return 0;
}

void check_loop_iterative(void (*f)(int, int , int , int *), int xs, int seqlen, int *loop, int *looplen) //to create check_loop_iterative function.
{   
/*
*This function takes sequence length and first element of sequence and create sequence with calling 
* f function (generate_sequence) and then it calls has_loop function for the searching there is a
* loop in given sequence with given looplen.If there is not a loop which has length of looplen value then
* it checks again and again with decreasing looplen value until looplen value equal to 2.
*
*If there is a loop in created sequence then this function fills loop array with founded loop elements.
*Also this function prints loop array and the indexes of loop in the sequence.
*
*It is a recursive function.
*It returns nothing.
*/
    static int k=0;
    int *ls=(int *)malloc(sizeof(int)); //to allocate dynamic memory for *ls.
    int *le=(int *)malloc(sizeof(int)); //to allocate dynamic memory for *le.
    int x=seqlen/2;
    *looplen = x-k;
    int currentlen=0;
    
    int *seq = (int *)calloc((seqlen+1),sizeof(int)); //to allocate dynamic memory for *seq.
  

    f(xs,currentlen,seqlen,seq); //to call f function which is in arguments.

    printf("Checking if there is a loop of length %d...\n",(*looplen));
    has_loop(seq,seqlen,*looplen,ls,le); //to call has_loop function for checking is there a loop which has length of looplen.
        if (has_loop(seq,seqlen,*looplen,ls,le) == 1){  //to checking has_loop function returns 1 or 0.
                printf("\n\nLoop detected with a lentgh of %d.\n",(*looplen));
                (*ls)=(*le)-(*looplen)+1;
                for(int i=0;i<(*looplen);i++) //to fill the loop array with founded loop elements.
                    loop[i]=seq[(*ls)+i];
                printf("The indexes of the loop's first occurance : %d(first digit)  %d(last digit).\n",(*ls),(*le)); //to print loop star and loop end indexes.
                printf("Loop : {");
                for(int i=0;i<(*looplen);i++){ //to print the loop array.
                    printf("%d,",loop[i]);
                }
                printf("\b}\n");
        }
   
        else{ 
                k++;
                    if((*looplen)>=2){ //to checking looplen is equal or greater than 2.
                        check_loop_iterative(f,xs,seqlen,loop,looplen); //to calling same function for searching loop which has the lentgh decreased by one.
                    }
                    else {
                        printf("No loop found.\n"); //to inform user for there is not a loop.
                    }
            }  
   free(seq);

}

void hist_of_first_digits(void (*f)(int, int , int , int *),int xs,int seqlen,int *h,int digit) //to create hist_of_first_digits function.
{
/*
*This function takes sequence length and first element of sequence and create sequence with calling 
* f function (generate_sequence) and it founds first digits of elements of sequence.
*
*And it increases the elements of h array according to numbers of digits.
*It is a recursive function.
*It returns nothing.
*/
    int y;
    int currentlen=0;
    int *seq = (int *)calloc((seqlen+1),sizeof(int)); //to allocate dynamic memory for *seq.
        f(xs,currentlen,seqlen,seq); //to call f function which is in arguments.
  

    for(int j=0;j<seqlen;j++){ //to get first digit of all elements of seq array.
        y=seq[j];
            while(y>10){ //to get first digit of the element.
                y=y/10;
            }
        
            if(y==digit) h[digit-1]++; //to check is first digit of element equal to digit.
    }                                  //and then increase the h arrays element by one.
  
    digit++;
         if(digit<=9){ //to checking digit is equal or smaller than 9.
            hist_of_first_digits(f,xs,seqlen,h,digit);  //to call same function for decreased digit value.
        }
}



