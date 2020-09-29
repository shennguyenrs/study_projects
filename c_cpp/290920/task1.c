/* Task 1
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

// Global variables
const int MAX_STRING = 1024;

// Menu of program
int Menu()
{
  int choice;

  // Menu of program
  printf("\n0 = Exit");
  printf("\n1 = Count the time");
  printf("\n2 = Points");
  printf("\n3 = String");
  printf("\n");
  printf("\nChoose an number to start:");

  scanf("%d", &choice);

  return choice;
}

// Calculate travel time in hours
void CalculateTime()
{
  // Declare variables
  float distance, velocity, time;

  // User guide
  printf("\n1 - Calculate travel time\n");
  printf("\nInput the distance (km): ");
  scanf("%f", &distance);
  printf("Input the average velocity (km/h): ");
  scanf("%f", &velocity);

  // Calculate travel time
  time = distance / velocity;

  // Print out the result
  printf("\nThe travel time is: %0.3f in hours\n", time);
}

// Calculate distance of 2 points
void CalculateDistance()
{
  // Declare variables
  float distance;
  float horDis, verDis; // Horizontal distance and Vertical distance

  struct Points
  {
    float xCor;
    float yCor;
  };

  struct Points firstPoint;
  struct Points secondPoint;

  printf("\n2 - Calculate distance of 2 points\n");
  printf("\nInput the coordinate separates by a space: x y\n");

  printf("First point coordinate: ");
  scanf("%f %f", &firstPoint.xCor, &firstPoint.yCor);
  printf("Second point coordinate: ");
  scanf("%f %f", &secondPoint.xCor, &secondPoint.yCor);

  // Calculate distance
  horDis = firstPoint.xCor - secondPoint.xCor;
  verDis = firstPoint.yCor - secondPoint.yCor;
  distance = sqrt(pow(horDis, 2) + pow(verDis, 2));

  // Print out result
  printf("\nThe distance between 2 points is: %0.3f\n", distance);
}

// Capitalize string
void CapitalizeString()
{
  // Declare variables
  char * str = malloc(MAX_STRING*sizeof(char)); // Reserve memory for the string
  int count=0, len, i;

  printf("\n3 - Capitalize String\n");
  printf("\nInput your string: ");

  /*scanf("%[^\n]%*c", str); // Do not work on gcc 10 but work on clang7*/
  scanf("%s", str); // Work without using space 

  // Len the string 
  len = strlen(str);

  // Resize the memory of the string
  str = realloc(str, len);

  // Check if the character is small
  // and print out the capital character
  printf("\nThe capitalized string is: ");
  for(i=0; i<len; i++)
  {
    if(!isupper(*(str+i)))
    {
      *(str+i) = toupper(*(str+i));
      count++;
    }
    printf("%c", *(str+i));
  }
  printf("\nThe number of small letters in this string is %d\n", count);

  free(str);
}


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
