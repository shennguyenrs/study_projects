/* Task 10: Compare a and b, print out the message
 */

#include<stdio.h>

int main()
{
  int a, b;

  printf("Input a: ");
  scanf("%d", &a);
  printf("Input b: ");
  scanf("%d", &b);
  
  if(a>b) { printf("\nUp"); }
  else if(a<b) { printf("\nDown"); }
  else { printf("\nEqual"); }

  return 0;
}
