/* Task 7: Turn input money to several euro bills
 */

#include<stdio.h>

// Save denominations and its needed amount to 2D array
#define col 7
#define row 2

int main()
{
    // Declare Variables
    int i;
    int euroBill[row][col] = {{5, 10, 20, 50, 100, 200, 500}, {0}}; // Money denominations and its amount of euro bills after convert
    int modulo=0; // Remainder of input money and denomination
    int remainMoney=0;

    // Input the money that is needed to convert
    printf("Enter the money: ");
    scanf("%d", &remainMoney);
    
    // Find the amount of denominations that needs
    // from the input money
    for(i=col-1; i>=0; i--)
    {
      // If the remain money is larger than the certain denomination
      // It will needed to turn into that denomination
      // remainMoney changes into remainder of input money 
      // and particular needed denominations
        if((remainMoney-euroBill[0][i])>=0)
        {
            modulo = remainMoney%euroBill[0][i];
            euroBill[1][i] = remainMoney/euroBill[0][i];
            remainMoney = modulo;
        }
    }

    // Print the denominations that need to convert the money
    printf("The money that you input will turn into: \n");
    for(i=0; i<col; i++)
    {
        if(euroBill[1][i]!=0)
        {
            printf("%d: %d\n", euroBill[0][i], euroBill[1][i]);
        }
    }

    // Print remain money that can not be converted
    if(remainMoney!=0)
    {
        printf("And still remain: %d", remainMoney);
    }

    return 0;
}
