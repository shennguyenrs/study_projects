/* Task 16: Sum all even number between 2 - 40
 */

#include<stdio.h>

int main()
{
  int max =40;
  int sum = 0;

  for(int i=0; i<=max; i+=2)
  {
    sum+=i;
  }

  printf("Sum: %d", sum);

  return 0;
}
