#include <stdio.h>
#include "util.h"


int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}


char dt1a(double PL, double PW, double SL, double SW){  //Part-1 code start.
    
    if (PL < 2.45)
        return 's';                                     //to check the user inputs according to first tree and return the result.
    else if (PW < 1.75 && PL < 4.95 && PW < 1.65)
        return 'e' ; 
    return 'v'; 
}
char dt1b(double PL, double PW, double SL, double SW){

   {
    if (PL < 2.55)
        return 's';                                  //to check the user inputs according to second tree and return the result.
    else if (PW < 1.69 && PL < 4.85)
        return 'v';
    return 'e';
}                                                    //Part-1 code end.

}
double dt2a(double x1, double x2, double x3, int x4, int x5){   //Part-2 code start.
    if(x1 > 31.5){
        if(x2 > -2.5){
            return 5.0;
        }
        else{                                     
            if(x2-0.1<=x1 && x1<=x2+0.1){
                return 2.1;
            }
            else{
                return -1.1;
            }
            
        }                                            //to check the user inputs according to first tree and return the result.

    }
    else{
        if(-1 <= x3 && x3 <= 2){
            return 1.4;
        }
        else{
            if(x4 && x5 ){
                return -2.23;
            } 
            else{
                return 11.0;
            }

        }
    }
}



double dt2b(double x1, double x2, double x3, int x4, int x5){
 if(12<x1 && x1<22){
     if(x3 > 5/3){
         return -2.0;
     }
     else{
         if(x1-01<=x3 && x3<=x1+0.1){
             return 1.01;
         }
         else{
             return -8;
         }
     }                                            //to check the user inputs according to second tree and return the result.

 }
 else{
     if(x4 && x5){
         return -1;
     }
     else{
         if(-1<=x2 && x2<=2){
             return -1/7;
         }
         else{
             return 0.4;
         }
     }

 }
                                                         //Part-2 code end.
}




double dt3a(double x1, double x2, double x3, int x4, int x5){  //Part-3 code start.

    if(x1>3.8){
        if(1.8<=x2<=2.4){
            if(x3<=2.3){
                if(x4 && x5 == 1){
                    return 0.5;
                }
                else {                             //to check user inputs according to first tree and return the result value.
                    return 0.8;
                }
            }
            else{
                if(x1>5){
                    return 24;
                }
                else{
                    return 21.5;
                }
            }

        }
        else{
            return -26;
        }
    }
    else{
        if(x3<5.2){
            if(x4 && x5 ==1){
                return 19.2;
            }
            else {
                return 0.2;
            }
        }
        else{
            if(x2<=6.7){
                if(x3>2.5){
                    return 12.8;
                }
                else{
                    return 20;
                }
            }
            else{
                if(x1<2.8){
                    return 34;
                }
                else{
                    return 32.1;
                }
            }
        }
    }
}

double dt3b(double x1, double x2, double x3, int x4, int x5){

    if(1.2<=x2<=5.9){
        if(x1<=9.4){
            if(x4 && x5 == 1){
                if(2.8<=x3<=4.2){
                    return 0.8;
                }
                else{
                    return 0.5;
                }
            }                        //to check user inputs according to second tree and return the result value.
            else{
                if(x1>5.1){
                    return 34;
                }
                else{
                    return 0.2;
                }
            }

        }
        else{
            return -23;
        }
    }
    else{
        if(x3<7){
            if(x1>=8.2){
                return 18.2;
            }
            else{
                return 11;
            }
        }
        else{
            if(x4 && x5 == 1){
                if(x2>=22){
                    return 13.3;
                }
                else {
                    return 20;
                }
            }
            else {
                if(x1>9){
                    return 5.4;
                }
                else{
                    return 32.1;
                }
            }
        }
    }



}                                 //Part-3 code end.


