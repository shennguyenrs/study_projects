#include <stdio.h>

/*Check prime number*/
void prime_number() 
{
  int n;
  int flag=1;

  printf("----------------------------------------------------");
  printf("\nEnter an integer number that you want to check: ");
  scanf("%d", &n);

  if (n<=1) 
  {
    printf("%d is not a prime number or composite", n);
  }
  else if (n==2)
  {
    printf("%d is a prime number", n);
  }
  else if (n>2)
  {
    for (int i = 2; i <= n; i++)
    {
      flag = (n%i==0) ? 0 : 1;
      if (flag==0)
      {
        printf("%d is not a prime number", n);
        break;
      }
      else 
      {
        printf("%d is a prime number", n);
        break;
      }
    }
  }

  printf("\n----------------------------------------------------\n");

}