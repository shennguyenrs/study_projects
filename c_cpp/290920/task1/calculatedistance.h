#include<stdio.h>
#include<math.h>

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
  scanf("%f %f%*c", &firstPoint.xCor, &firstPoint.yCor);
  printf("Second point coordinate: ");
  scanf("%f %f%*c", &secondPoint.xCor, &secondPoint.yCor);

  // Calculate distance
  horDis = firstPoint.xCor - secondPoint.xCor;
  verDis = firstPoint.yCor - secondPoint.yCor;
  distance = sqrt(pow(horDis, 2) + pow(verDis, 2));

  // Print out result
  printf("\nThe distance between 2 points is: %0.3f\n", distance);
}
