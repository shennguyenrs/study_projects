#include <stdio.h>

/*Calculate factorial of an integer number*/
void factorial() 
{
  int n;
  int result=1;

  printf("----------------------------------------------------");
  printf("\nEnter an integer number: ");
  scanf("%d", &n);

  if (n==0)
  {
    result=1;
  }
  else
  {
    for (int i=1; i<=n; i++) 
    {
      result*=i;
    }
  }

  printf("The factorial number of %d is %d", n, result);
  printf("\n----------------------------------------------------");

}