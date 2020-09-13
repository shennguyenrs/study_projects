/* Task 14.5: Find max from 3 given values
 */

#include<stdio.h>

int FindMax(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int a, b, c;
  int max;
  
  // Input values
  printf("Input value of the first number: ");
  scanf("%d", &a);
  printf("\nInput value of the second number: ");
  scanf("%d", &b);
  printf("\nInput value of the third number: ");
  scanf("%d", &c);

  max = FindMax(FindMax(a,b), FindMax(b,c));
  printf("\nThe maximum number is %d", max);

  return 0;
}
