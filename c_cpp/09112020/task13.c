/* Task 13: Print out number of days following the month number
 */

#include<stdio.h>

int main()
{
  // Declare variables
  int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int monthNumber;

  // Input month number
  printf("Input month number:");
  scanf("%d", &monthNumber);

  // Print out the day in that month
  // Position of the month in array
  // is equal to month number minus by 1
  // because array counts from 0
  printf("\nDays in that month: %d", monthDay[monthNumber-1]);

  return 0;
}
