/* Task 12: Solve quadratic equation applying Vieta's Formula
 */

#include <stdio.h>
#include <math.h>

int main() 
{
  // Declare variables
  double a, b, c;
  double delta;

  // Input a, b and c
  printf("\nEnter your number of quadratic equation ax**2 + bx + c = 0");
  printf("\nEnter a = ");
  scanf("%lf", &a);
  printf("Enter b = ");
  scanf("%lf", &b);
  printf("Enter c = ");
  scanf("%lf", &c);
  
  if (a==0)
  {
    printf("The quadratic equation %0.3lfx**2 + %0.3lfx + %0.3lf = 0 has only one real root:", a, b, c);
    printf("\nx = %0.3f", -c/b);
  }
  else
  {
    // Calculate delta
    delta = pow(b,2) - 4*a*c;

    if (delta>0)
    {
      printf("The quadratic equation %0.3lfx**2 + %0.3lfx + %0.3lf = 0 has two distinct real roots:", a, b, c);
      printf("\nx1 is %0.3f",(-b+sqrt(delta))/(2*a));
      printf("\nx2 is %0.3f", (-b-sqrt(delta))/(2*a));
    }
    else if (delta==0)
    {
      printf("The quadratic equation %0.3lfx**2 + %0.3lfx + %0.3lf = 0 has only one real root:", a, b, c);
      printf("\nx = %0.3f", -b/(2*a));
    }
    else 
    {
      printf("The quadratic equation %0.3lfx**2 + %0.3lfx + %0.3lf = 0 has two distinct complex root:", a, b, c);
      printf("\nx1 is %0.3f + i%0.3f", -b/(2*a), sqrt(-delta)/(2*a));
      printf("\nx1 is %0.3f - i%0.3f", -b/(2*a), sqrt(-delta)/(2*a));
    }
  }

  return 0;
}
