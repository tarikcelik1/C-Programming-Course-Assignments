#include <stdio.h>
#include <math.h>

#define PI 3.14
enum Shapes   //to defining shapes with enum.
{
  Triangle = 1,
  Quadrilateral,
  Circle,
  Pyramid,
  Cylinder
};
enum Calculators  //to define calculator type with enum.
{
  Area = 1,
  Perimeter,
  Volume
};

int select_shape()  //to define select_shape function.
{
  int n, x = 0, i = 0;
  printf("\nSelect a shape to calculate: \n");      
  printf("----------------------------\n");
  printf("1.Triangle\n");
  printf("2.Quadrilateral\n");
  printf("3.Circle\n");
  printf("4.Pyramid\n");
  printf("5.Cylinder\n");
  printf("0.Exit\n");
  printf("----------------------------\n");

  do                                             //to get user input for selecting shape from menu.
  {
    if (i >= 1)
      printf("ERROR !!Please enter valid a entry.\n");  //to warn user if input is a character.
    i = 0;
    printf("Input : ");
    x = scanf("%d", &n);
    getchar();
    i++;
    if (5 < n || n < 0)      //to checking input is correct or not.
    {
      x = 0;
    }
  } while (x == 0);        //to checking input is a character or an integer.
  return n;
}

int select_calc()        //to define select_calc function.                      
{
  int n, x = 0, i = 0;
  printf("\nSelect calculator: \n");
  printf("----------------------------\n");
  printf("1.Area\n");
  printf("2.Perimeter\n");
  printf("3.Volume\n");
  printf("0.Exit\n");
  printf("----------------------------\n");

  do                                           //to get user input for selceting calculator type from menu.
  {
    if (i >= 1)
      printf("ERROR !!Please enter valid a entry.\n");  //to warn user if input is a character.
    i = 0;
    printf("Input : ");
    x = scanf("%d", &n);
    getchar();
    if (3 < n || n < 0)                 //to checking input is correct or not.
    {
      x = 0;
    }
    i++;
  } while (x == 0);                  //to checking input is a character or an integer.
  return n;
}

int calc_triangle(int n)            //to define calc_triangle function.
{
  int x = 0, y = 0, z = 0, k1, k2, k3, i = 0, s;
  float A, p;
  printf("Please enter three sides of the triangle :\n");
  do                   //to get user input for the size of triangle.
  {
    if (i >= 1)
      printf("ERROR !!Please enter valid a entry.\n");    //to warn user if input is not correct.
    i = 0;
    x = scanf("%d", &k1);
    getchar();
    y = scanf("%d", &k2);
    getchar();
    z = scanf("%d", &k3);
    getchar();
    if (k1 > k2 + k3 || k1 < k3 - k2 || k1 < k2 - k3 || k1 <= 0)     //to checking the triangle inequality.
    {
      x = 0;
    }
    if (k2 > k1 + k3 || k2 < k1 - k2 || k2 < k1 - k3 || k2 <= 0)    //to checking the triangle inequality.
    {
      y = 0;
    }
    if (k3 > k2 + k1 || k3 < k1 - k2 || k3 < k2 - k1 || k3 <= 0)    //to checking the triangle inequality.
    {
      z = 0;
    }
    i++;
  } while (x == 0 || y == 0 || z == 0);      //to checking the user input is a character or an integer.
  switch (n)
  {
  case 1:
    s = (k1 + k2 + k3) / 2;
    A = sqrt(s * (s - k1) * (s - k2) * (s - k3));              //to calculate the area of triangle.
    printf("\nArea of TRIANGLE : %.2lf\n", A);
    break;
  case 2:
    p = k1 + k2 + k3;
    printf("\nPerimeter of TRIANGLE : %.2lf\n", p);   //to calculate the perimeter of triangle.
    break;
  default:
    break;
  }
  return 0;
}
int calc_quadrilateral(int n)  //to define calc_quadrilateral function.
{
  int x = 0, y = 0, z = 0, t = 0, k1, k2, k3, k4, i = 0, s;
  float A, p;
  printf("Please enter four sides of the quadrilateral :\n");  
  do
  {
    if (i >= 1)
      printf("ERROR !!Please enter valid a entry.\n");  //to warn user if input is not correct.
    i = 0;
    x = scanf("%d", &k1);
    getchar();
    y = scanf("%d", &k2);
    getchar();
    z = scanf("%d", &k3);
    getchar();
    t = scanf("%d", &k4);
    getchar();
    if(k1 <= 0) x = 0;
    if(k2 <= 0) y = 0;
    if(k3 <= 0) z = 0;
    if(k4 <= 0) t = 0;
    i++;
  } while (x == 0 || y == 0 || z == 0 || t == 0);  //to checking the input is a character or an integer.
  switch (n)
  {
  case 1:
    s = (k1 + k2 + k3 + k4) / 2;
    A = sqrt((s - k1) * (s - k2) * (s - k3) * (s - k4));   //to calculate the area of quadrilateral.
    printf("\nArea of QUADRILATERAL : %.2lf\n", A);
    break;
  case 2:
    p = k1 + k2 + k3 + k4;
    printf("\nPerimeter of QUADRILATERAL : %.2lf\n", p);   //to calculate the perimeter of quadrilateral.
    break;
  default:
    break;
  }
}

int calc_circle(int n)    //to define calc_circle funcion.
{
  int r, x = 0, i = 0;
  float A, p;
  printf("Please enter radius of the circle :\n");
  do
  {
    if (i >= 1)
      printf("ERROR !!Please enter valid a entry.\n");  //to warn user if input is no correct.
    i = 0;
    x = scanf("%d", &r);    //to get user input for radius of circle.
    getchar();
    if(r <= 0) x = 0;
    i++;
  } while (x == 0);   //to checking the user input is a character or an integer.

  switch (n)
  {
  case 1:
    A = PI * r * r;
    printf("\nArea of CIRCLE : %.2lf\n", A);  //to calculate the area of circle.
    break;
  case 2:
    p = 2 * PI * r;
    printf("\nPerimeter of CIRCLE : %.2lf\n", p);  //to calculate the perimeter of circle.
    break;
  default:
    break;
  }
}

int calc_pyramid(int n)         //to define calc_pyramid function.
{
  int h, a, x = 0, y = 0, j = 0;
  float B, L, I, SA, P, V;
  printf("Please enter the base side and height of a Pyramid :\n");
  do
  {
    if (j >= 1)
      printf("ERROR !!Please enter valid a entry.\n");   //to warn user if inpur is not correct.
    j = 0;
    x = scanf("%d", &a);  //to get user input for base side of pyramid.
    getchar();
    y = scanf("%d", &h);  //to get user input for height of pyramid.
    getchar();
    if(a <= 0) x = 0;
    if(h <= 0) y = 0;
    j++;
  } while (x == 0 || y == 0);  //to checking the user input is a character or an integer.
  switch (n)
  {
  case 1:
    B = a * a;                          //to calculate base surface area of pyramid.
    I = sqrt((a * a / 4) + (h * h));   
    L = 2 * a * I;                   //to calculate lateral surface area of pyramid.
    SA = B + L;                     //to calculate surface area of pyramid.
    printf("\nBase surface area of a PYRAMID : %.2lf\n", B);
    printf("\nLateral surface area of a PYRAMID : %.2lf\n", L);
    printf("\nSurface area of a PYRAMID : %.2lf\n", SA);
    break;
  case 2:
    P = 4 * a;                   //to calculate perimeter of pyramid.
    printf("\nBase surface perimeter of a PYRAMID : %.2lf\n", P);
    break;
  case 3:
    V = (a * a * h) / 3;           //to calculate volume of pyramid.
    printf("\nVolume of a PYRAMID : %.2lf\n", V);
    break;
  default:
    break;
  }
}

int calc_cylinder(int n)   //to define the calc_cylinder function.
{
  int j = 0, r, h, x = 0, y = 0;
  float B, L, SA, P, V;
  printf("Please enter the base radius and height of a Cylinder :\n");
  do
  {
    if (j >= 1)
      printf("ERROR !!Please enter valid a entry.\n");  //to warn user if input is not correct.
    j = 0;
    x = scanf("%d", &r);   //to get user input for radius of cylinder.
    getchar();
    y = scanf("%d", &h);  //to get user input for height of cylinder.
    getchar();
    if(r <= 0) x=0;
    if(h <= 0) y=0;
    j++;
  } while (x == 0 || y == 0);   //to cehcking the user input is a character or an integer.
  switch (n)
  {
  case 1:
    B = PI * r * r;    //to calculate base surface area of cylinder.
    L = 2 * PI * r * h;  //to calculate lateral surface area of cylinder.
    SA = 2 * PI * r * (r + h);   //to calculate surface arae of cylinder.
    printf("\nBase surface area of a Cylinder : %.2lf\n", B);
    printf("\nLateral surface area of a Cylinder : %.2lf\n", L);
    printf("\nSurface area of a Cylinder : %.2lf\n", SA);
    break;
  case 2:
    P = 2 * PI * r;   //to calculate perimeter of cylinder.
    printf("\nBase surface perimeterr of a Cylinder : %.2lf\n", P);
    break;
  case 3:
    V = PI * r * r * h;  //to calculate volume of cylinder.
    printf("\nVolume of a Cylinder : %.2lf\n", V);
    break;
  default:
    break;
  }
}

int calculate(int s, int c)  //to define calculate function.
{
  switch (s)    //to selecting shape.
  {
  case 0:
    break;
  case 1:
    switch (c)  //to selecting calculator type.
    {
    case 0:
      break;
    case 1: //this case for calculations of triangle.
      calc_triangle(1);  //to calling the calc_triangle function for calculate the area.
      break;
    case 2:
      calc_triangle(2);  //to calling the calc_triangle function for calculate the perimeter.
      break;
    case 3:
      printf("ERROR !! You cannot calculate volume of a triangle.Please try again.\n");  //to warn user.
      break;
    default:
      break;
    }
    break; //the end of the triangle calculations.
  case 2:  //this case for quadrilateral calculations.
    switch (c)
    {
    case 0:
      break;
    case 1:
      calc_quadrilateral(1);  //to calling the calc_quadrilateral function for calculate the area.
      break;
    case 2:
      calc_quadrilateral(2);  //to calling the calc_quadrilateral function for calculate the perimeter.
      break;
    case 3:
      printf("ERROR !! You cannot calculate volume of a quadrilateral.Please try again.\n");  //to warn user.
      break;
    default:
      break;
    }
    break; //the end of the quadrilateral calculations.

  case 3: //this case for the calculations of circle.
    switch (c)
    {
    case 0:
      break;
    case 1:
      calc_circle(1);  //to calling calc_circle function for calculate the area.
      break;
    case 2:
      calc_circle(2);  //to calling calc_circle function for calculate the area.
      break;
    case 3:
      printf("ERROR !! You cannot calculate volume of a circle.Please try again.\n"); //to warn user.
      break;
    default:
      break;
    }
    break; //the end of the circle calculations.
  case 4:  //this case for the calculations of pyramid.
    switch (c)
    {
    case 0:
      break;
    case 1:
      calc_pyramid(1);   //to calling calc_pyramid function for calculate the area.
      break;
    case 2:
      calc_pyramid(2);  //to calling calc_pyramid function for calculate the perimeter.
      break;
    case 3:
      calc_pyramid(3);  //to calling calc_pyramid function for calculate the volume.
      break;
    default:
      break;
    }
    break;  //the end of pyramid calculations.
  case 5:  //this case for the calculations of cylinder calculations.
    switch (c)
    {
    case 0:
      break;
    case 1:
      calc_cylinder(1);  //to calling calc_cylinder function for calculate the area.
      break;
    case 2:
      calc_cylinder(2);  //to calling calc_cylinder function for calculate the perimeter.
      break;
    case 3:
      calc_cylinder(3);  //to calling calc_cylinder function for calculate the volume.
      break;
    default:
      break;
    }
    break; //the end of the cylinder calculations.
  default:
    break;
  }
}
int main()     //to define the main function.
{
  int x, y, s, c;
  x = select_shape();   //to calling select_shape function and get it's return value.
  if(x == 0)
    s = 0;
  else if (x == Triangle)       
    s = 1;
  else if (x == Quadrilateral)    //to checking select_shape function's return value is equal to which enum Shapes value.
    s = 2;
  else if (x == Circle)
    s = 3;
  else if (x == Pyramid)
    s = 4;
  else if (x == Cylinder)
    s = 5;
  if(x != 0){
  y = select_calc();  //to calling select_calc function and get it's return value.
  if(y == 0)
    c = 0;
  else if (y == Area)
    c = 1;
  else if (y == Perimeter)   //to checking select_calc function's return value is equal to which enum Calculators value.
    c = 2;
  else if (y == Volume)
    c = 3;
  }
  calculate(s, c);   //to calling the calculate function.

  return 0;
}                       //the end of the code.