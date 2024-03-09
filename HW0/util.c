#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
  
  int gcd, remainder, temp1, temp2;
  temp1 = *n;
  temp2 = *d;
  
  while (temp1 != 0){              /* to calculate the GCD of numerator and denominator */
    remainder = temp2 % temp1;
    temp2 = temp1;
    temp1 = remainder;
    }
   gcd = temp2;
   
   *n = *n/gcd;   /* Divide denominator and numerator to get simpliest versions of them. */
   *d = *d/gcd;
    
    printf("\n Simplified version = %d / %d \n", *n,*d);
    }
 /* end fraction_div */
