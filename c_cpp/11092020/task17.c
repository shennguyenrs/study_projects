/* Task 17: Sum all the numbers that are divisible for 5
 * up to 100
 */

#include<stdio.h>

int main()
{
  int max = 100;
  int sum = 0;

  for(int i=0; i<=max; i+=5)
  {
    sum+=i;
  }

  printf("Sum: %d", sum);

  return 0;
}
