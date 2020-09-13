/* Task 13: Print out number of days following the month number
 */

#include<stdio.h>

int main()
{
  int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int monthNumber;

  printf("Input month number:");
  scanf("%d", &monthNumber);

  printf("\nDays in that month: %d", monthDay[monthNumber-1]);
  return 0;
}
