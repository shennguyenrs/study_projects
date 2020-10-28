/* Task 9: Compare to 100
*/

#include<stdio.h>

int main()
{
  float n;
  float compareNumber = 100.0;

  printf("Input n: ");
  scanf("%f", &n);
  printf("\nn is greater than 100: ");

  if(n>compareNumber)
  {
    printf("True");
  }
  else 
  {
    printf("False");
  }

  return 0;
}
