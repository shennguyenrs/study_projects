/* Task 20
 * Solve ccubic equation: 3x^3 - 4x^2 + 9x + 5 = 0
 *
 * By applying Cardano Formula
*/

#include<stdio.h>
#include<math.h>

void quadratic_equation(float* x2, float* x3) 
{
  // Solve quadratic equation by applied Vieta's formula
  
  // Declare Variables
  float a = 1.0;
  float b, c;
  b = *x2;
  c = *x3;
  float delta = pow(b,2) - 4*a*c;

  *x2 = (-b+sqrt(delta))/(2*a);
  *x3 = (-b-sqrt(delta))/(2*a);
}

int main()
{
  // Declare variables
  float a, b, c, d;
  float q, r, s, t, D;
  float x1, x2, x3, complexPart, realPart;

  // Input number for cubic equation
  // ax^3 + bx^2 + cx + d = 0
  printf("--------------------\n");
  printf("Task 20\n");
  printf("Solve cubic equation by applied Cardano Formula\n");
  printf("--------------------\n");
  printf("Input ax^3:");
  scanf("%f", &a);
  printf("Input bx^2:");
  scanf("%f", &b);
  printf("Input cx:");
  scanf("%f", &c);
  printf("Input d:");
  scanf("%f", &d);
  printf("\n");

  // Cardano's Formula
  q = (3*a*c-pow(b,2))/(9*pow(a,2));
  r = (9*a*b*c-27*pow(a,2)*d-2*pow(b,3))/(54*pow(a,3));

  s = cbrt(r+sqrt(pow(q,3)+pow(r,2)));
  t = cbrt(r-sqrt(pow(q,3)+pow(r,2)));

  D = pow(q,3) + pow(r,2);

  // Calculate roots
  x1 = s+t-b/(3*a);
  complexPart = sqrt(3)/2*(s-t);
  realPart = -(s+t)/2 - b/(3*a);

  // Consider cases of D to give the number of roots
  if(D>0)
  {
    // Equation have 1 real root and 2 complex roots
    printf("There are three roots, one is a real number and two are complex numbers.\n");
    printf("x1: %f\n", x1);
    printf("x2: %f + %fi\n", realPart, complexPart);
    printf("x3: %f - %fi\n", realPart, complexPart);
  }
  else if(D==0)
  {
    // Equation have 2 real roots
    printf("All roots are real numbers, there are two roots are equal.\n");
    printf("x1: %f\n", x1);
    printf("x2: %f\n", realPart);
  }
  else
  {
    // Equation have 3 different real roots
    // With x1 = -b/(3*a), the other of equation turns into a quadratic equation x^2 - px + q = 0
    // With p = -2/3*b/a
    // And q = 3*d/b
    // After that we can find roots of quadratic equation by applied Vieta's formula
    x1 = -b/(3*a);
    x2 = -2.0/3.0*(b/a)*(-1.0);
    x3 = 3*d/b;

    quadratic_equation(&x2, &x3);
    printf("All roots are real numbers and unequal.\n");
    printf("x1: %f\n", x1);
    printf("x2: %f\n", x2);
    printf("x3: %f\n", x3);
  }

  return 0;
}
