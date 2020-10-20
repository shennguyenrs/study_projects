#include<stdio.h>

// Calculate travel time in hours
void CalculateTime()
{
  // Declare variables
  float distance, velocity, time;

  // User guide
  printf("\n1 - Calculate travel time\n");
    
  do
  {
    printf("\nInput the distance (km): ");
    scanf("%f%*c", &distance);
    printf("Input the average velocity (km/h): ");
    scanf("%f%*c", &velocity);
  }
  while(distance<=0 && velocity<=0);

  // Calculate travel time
  time = (float) distance / velocity;

  // Print out the result
  printf("\nThe travel time is: %0.3f in hours\n", time);
}
