/* Task 14: Calculate square of a triangle from 3 sides
 */

#include<stdio.h>
#include<math.h>

int main()
{
  float a, b, c, p;
  float square;

  printf("Input the first side: ");
  scanf("%f", &a);
  printf("\nInput the second side: ");
  scanf("%f", &b);
  printf("\nInput the third side: ");
  scanf("%f", &c);

  p = (a+b+c)/2.0;
  square = sqrt(p*(p-a)*(p-b)*(p-c));

  printf("Square of this triangle is: %f", square);

  return 0;
}
