/* Task 1
 */

#include<stdio.h>

#include "menu.h"
#include "calculatetime.h"
#include "calculatedistance.h"
#include "capitalizestring.h"

int main()
{
  // Declare variables
  int choice;

  // Welcome screen
  printf("\n==============================");
  printf("\n           TASK 1             ");
  printf("\n==============================");
  printf("\n");

  do
  {
    // Start the menu
    choice = Menu();

    switch(choice)
    {
      // Calculate travel time in hours
      case 1:
        CalculateTime();
        continue;

      // Calculate distance of 2 points
      case 2:
        CalculateDistance();
        continue;

      // Capitalize string
      case 3:
        CapitalizeString();
        continue;

      case 0:
        continue;

      default:
        printf("\nYou enter wrong number!");
        printf("\nPlease try again!");
        continue;
    }
  }
  while(choice!=0);

  return 0;
}
