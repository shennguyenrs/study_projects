/* ****************************************************************** */
/* #3 Caculator                                                       */
/*                                                                    */
/* caculator.c                                                        */
/* Created 14.01.2020 by shennguyenrs                                 */
/*                                                                    */
/* ****************************************************************** */


#include <stdio.h>

#include "calculation_numbers.h"
#include "quadratic_equation.h"
#include "prime_number.h"
#include "factorial.h"

int main() 
{
  int selection;

  do
  {
    printf("----------------------------------------------------");
    printf("\n1. Do calculation (+, -, *, /, ^)");
    printf("\n2. Solve quadratic equation");
    printf("\n3. Check prime number");
    printf("\n4. Calculate factorial");
    printf("\n0. Exit program");
    printf("\n----------------------------------------------------");
    printf("\nEnter your selection by number: ");
    scanf("%d", &selection);

    switch (selection)
    {
      case 1:
        calculation_numbers();
        continue;
      
      case 2:
        quadratic_equation();
        continue;
      
      case 3:
        prime_number();
        continue;
      
      case 4:
        factorial();
        continue;

      case 0:
        printf("Exit\n");
        break;

      default:
        printf("\nErorr!!!\n");
        break;
    }
     
  } while (selection!=0);

}