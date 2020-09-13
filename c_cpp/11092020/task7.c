/* Task 7: Turn input money to several euro bills
 */

#include<stdio.h>

int main()
{
    // Declare Variables
    int n=7;
    int euroBill[2][7] = {{5, 10, 20, 50, 100, 200, 500}, {0}};
    int modulo=0;
    int remainMoney=0;

    printf("Enter the money: ");
    scanf("%d", &remainMoney);

    for(int i=n-1; i>=0; i--)
    {
        if((remainMoney-euroBill[0][i])>=0)
        {
            modulo = remainMoney%euroBill[0][i];
            euroBill[1][i] = remainMoney/euroBill[0][i];
            remainMoney = modulo;
        }
    }

    // Print the bills that need to convert the money
    printf("The money that you input will turn into: \n");
    for(int i=0; i<n; i++)
    {
        if(euroBill[1][i]!=0)
        {
            printf("%d: %d\n", euroBill[0][i], euroBill[1][i]);
        }
    }

    // Print remain money
    if(remainMoney!=0)
    {
        printf("And still remain: %d", remainMoney);
    }

    return 0;
}
