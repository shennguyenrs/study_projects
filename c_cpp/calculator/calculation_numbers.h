#include <stdio.h>
#include <math.h>

/*Do basic calculation +, -, *, /, ^ */
void calculation_numbers() 
{
  double temp1, temp2;
  char operators;
  char check[7] = {0, '+', '-', '*', '/', '^', '='};

  printf("----------------------------------------------------");
  printf("\nEnter the first number: ");
  scanf("%lf", &temp1);

  while (1)
  {
    int flag=0;

    //loop to check the operators
    do
    {
      printf("Enter the operation +, -, *, /, ^, =: ");
      scanf("%s", &operators);

      for (int i = 0; i < 7; i++)
      {
        flag += (operators==check[i]) ? i : 0;
      }

      if (flag==0)
      {
        printf("Wrong operator!!!\n");
      }
      
    } while (flag==0);
    
    //Conditions of operators
    if (flag==5)
    {
      printf("Enter the next number %0.3lf^", temp1);
      scanf("%lf", &temp2);
      temp1 = pow(temp1, temp2);
    }
    else if (flag==6)
    {
      break;
    }
    else
    {
      printf("Enter the next number %0.3lf%c", temp1, operators);
      scanf("%lf", &temp2);

      if (flag==1)
      {
        temp1+=temp2;
      }
      else if (flag==2)
      {
        temp1-=temp2;
      }
      else if (flag==3)
      {
        temp1*=temp2;
      } 
      else if (flag==4)
      {
        temp1/=temp2;
      }
      
    }
    
  }
  
  printf("\nThe answer is %0.3lf", temp1);
  printf("\n----------------------------------------------------\n");
  
}