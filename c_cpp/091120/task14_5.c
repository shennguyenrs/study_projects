/* Task 14.5: Find max from 3 given values
 */

#include<stdio.h>

// Function to find max number between 2 numbers
#define FindMax(a, b) (a>b ? a : b)

int main()
{
  // Declare variables
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
