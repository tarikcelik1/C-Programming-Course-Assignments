#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() { //to create main function.
    int i=0,digit=0;
    int xs,currentlen=0,seqlen;   //to define integers.
    int *looplen=(int *)malloc(sizeof(int)); //to allocate dynamic memory for *looplen.
    int h[9];
           
            for(int k=0;k<9;k++) h[k]=0; //to fill all elements of h array with zero.
        
        printf("\n\n");
        printf("Please enter the sequence length : "); //to get user input for seqlen value.
        scanf("%d",&seqlen);
        printf("Please enter the first element : "); //to get user input for xs value.
        scanf("%d",&xs);

    int *seq = (int *)calloc((seqlen+1),sizeof(int)); //to allocate dynamic memory for *seq.

        generate_sequence (xs,currentlen,seqlen,seq); //to call generate_sequence function for creating sequence.
        
        printf("\n\nSequence : {");  //to print created sequence.
            for(i=0;i<seqlen;i++){
                printf("%d,",seq[i]);
            }
        printf("\b}\n\n\n");
    
    int *loop = (int *)calloc((seqlen+1),sizeof(int)); //to allocate dynamic memory for *loop.
        
        check_loop_iterative(&generate_sequence,xs,seqlen,loop,looplen); //to call check_loop_iterative function for searching loop.
    
    free(loop);
    free(seq);
        
        hist_of_first_digits(&generate_sequence,xs,seqlen,h,digit); //to call hist_of _first_digits function for creating histogram array.
    
    printf("\n\nHistogram of the sequence : {");
        for(int m=0;m<9;m++) printf("%d,",h[m]);  //to print histogram array.
    printf("\b}\n\n"); 

return 0;  //the end of the code.
}