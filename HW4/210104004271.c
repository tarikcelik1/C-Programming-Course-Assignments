#include <stdio.h>


int main()
{
 int choice,a,b,c,i,a1,b1,c1,j,k,l,temp; //to define integers.
 do{                                      //to create a infinite loop for the menu.
 printf("Select an operation ...\n");
 printf("1 -> Enter the coefficients.\n");          //to print the menu.
 printf("2 -> Draw the graph.\n");
 printf("3 -> Print the graph to a .txt file.\n");
 printf("4 -> Exit.\n\n");

 printf("Choice: ");
 scanf("%d",&choice);              //to get user input for selection.
 
 switch(choice){                  //for the selection.
     
     case 1:
     printf("Please enter the coefficients for the following equation : x=a*(y*y) + b*y + c \n\n");
     printf("a : ");
     scanf("%d",&a);
     printf("\nb : ");                      //to get user inputs for the coefficients.
     scanf("%d",&b);
     printf("\nc : ");
     scanf("%d",&c);
     
     FILE *file =fopen("coefficients.txt","w+");       //to create a .txt file for writing.
      fprintf(file,"%d \n%d \n%d",a,b,c);              //to writing user inputs in the txt file.
      fclose(file);
      printf("\n\ncoefficients.txt file has been created.\n\n");
     
     break;
     case 2:
     
     file =fopen("coefficients.txt","r+");           //to open the .txt file for reading.
     if ((fscanf(file,"%d",&temp)) !=1) {            //to checking file is ready or not.
      printf("The file not ready yet !!\n\n");
      fclose(file);
   break;  
 }
 else
file =fopen("coefficients.txt","r+");
fscanf(file,"%d %d %d",&a1,&b1,&c1);              //to getting values from the txt file.
fclose(file);
printf("\nCoefficients has been read from coefficients.txt file.\n");
printf("Printing the graph of x=%d*y*y + %d*y + %d\n\n",a1,b1,c1);

  for(i=0;i<33;i++){
      for(j=0;j<115;j++){                               //these loops for printing the graph.
       if(i==16 && j!=0 && j!= 114) printf("-");
       else if(i==16 && j==0) printf("<");
       else if(i==16 && j==114) printf(">");
       else if(j==58 && i!=17 && i!=0 && i!=32) printf("|");
       else if(j==58 && i==0) printf("^");
       else if(j==58 && i==17){printf("\033[0;31m");printf("\b\b\b\b\b\b\b\b\b\b\b\b0 ");printf("\033[0m");printf("|");}
       else if(i==17 && j==6) {printf("\033[0;31m");printf("-50");printf("\033[0m");}     
	     else if(i==17 && j==14) {printf("\033[0;31m");printf("-40");printf("\033[0m");}
	   else if(i==17 && j==22) {printf("\033[0;31m");printf("-30");printf("\033[0m");}
	   else if(i==17 && j==30) {printf("\033[0;31m");printf("-20");printf("\033[0m");}
	   else if(i==17 && j==38) {printf("\033[0;31m");printf("-10");printf("\033[0m");}
	   else if(i==17 && j==68) {printf("\033[0;31m");printf("10");printf("\033[0m");}
	   else if(i==17 && j==77) {printf("\033[0;31m");printf("20");printf("\033[0m");}      //these prints for coloring the text. 
	   else if(i==17 && j==86) {printf("\033[0;31m");printf("30");printf("\033[0m");}
	   else if(i==17 && j==95) {printf("\033[0;31m");printf("40");printf("\033[0m");}
	   else if(i==17 && j==104) {printf("\033[0;31m");printf("50");printf("\033[0m");}
       else if(j==56 && i==1) {printf("\033[0;31m");printf("\b15");printf("\033[0m");}
       else if(j==56 && i==6) {printf("\033[0;31m");printf("\b10");printf("\033[0m");}
       else if(j==56 && i==11) {printf("\033[0;31m");printf("5");printf("\033[0m");}
       else if(j==56 && i==21) {printf("\033[0;31m");printf("\b-5");printf("\033[0m");}
       else if(j==56 && i==26) {printf("\033[0;31m");printf("\b\b-10");printf("\033[0m");}
       else if(j==56 && i==31) {printf("\033[0;31m");printf("\b\b-15");printf("\033[0m");}
       else if(j==58 && i==32) printf("v"); 
	     else printf(" ");   
	     for(k=-15;k<16;k++){                    
         for(l=-55;l<56;l++){                          //for find the values which are provides the equation.
         if(l==a1*k*k+b1*k+c1) {
      	 if(i==k+16 && j==l+58){printf("\033[0;34m");printf("\b#");printf("\033[0m");}  //to printing the values which are we found.
      	
	  }
      
      
  }
}   
       
      
     
  }
  printf("\n");
  }


break;
case 3:
{
printf("\nCoefficients has been read from coefficients.txt file.\n");
printf("The graph of x=%d*y*y + %d*y + %d  has been written to graph.txt file.\n\n",a1,b1,c1);
FILE *fptr=fopen("graph.txt","a+");   //to create a txt file for writing.

 for(i=0;i<33;i++){
      for(j=0;j<115;j++){
       if(i==16 && j!=0 && j!= 114) fprintf(fptr,"%s","-");
       else if(i==16 && j==0) fprintf(fptr,"%s","<");
       else if(i==16 && j==114) fprintf(fptr,"%s",">");
       else if(j==58 && i!=17 && i!=0 && i!=32) fprintf(fptr,"%s","|");   //for writing the graph into graph.txt file.
       else if(j==58 && i==0) fprintf(fptr,"%s","^");
       else if(j==58 && i==17) fprintf(fptr,"%s","|");
       else if(j==58 && i==32) fprintf(fptr,"%s","v");
 
    else fprintf(fptr,"%s"," ");  
    for(k=-15;k<16;k++){
         for(l=-55;l<56;l++){
         if(l==a1*k*k+b1*k+c1) {
         if(i==k+16 && j==l+57) fprintf(fptr,"%s","#");   //for writing the points into graph.txt file.
     
 }
     
     
  }
}  
       
     
     
  }
  fprintf(fptr,"\n");
  }
  break;
  default:
  if(choice !=4) printf("Please select correctly !\n");
  break;

}
 }
 }
 while(choice !=4);  //for exit the menu.

    return 0;
}     //end of the code.