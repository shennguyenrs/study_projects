/* Task 19: Account Manager
 * User can make deposits
 * Do withdarwal
 * Check balace
 */

#include<stdio.h>

// Funtions
// Checking balance.txt file
void CheckFile()
{
  FILE* filePointer;

  // Create new account file if balance file not found
  if((filePointer = fopen("balance.txt", "r"))==NULL)
  {
    fclose(filePointer);
  }
  else
  {
    filePointer = fopen("balance.txt", "w");
    fclose(filePointer);
  }
}

// Get Balance
float GetBalance()
{
  float balance=0.0;
  FILE* filePointer;

  // Check balance history from file: balance.txt
  filePointer = fopen("balance.txt", "r");
  
  // Scan the remain balance and close file
  fscanf(filePointer, "%f", &balance);

  // Close file
  fclose(filePointer);
  return balance;
}

// Save Balance
void SaveBalance(float newBalance)
{
  FILE* filePointer;

  // Check balance history from file: balance.txt
  filePointer = fopen("balance.txt", "w");

  // Write new content
  fprintf(filePointer, "%.2f", newBalance);
  printf("Successfully save");

  // Close file
  fclose(filePointer);
}

// Deposit Money
void DepositMoney()
{
  float depositAmount;

  printf("Enter your deposit amount: ");
  scanf("%f", &depositAmount);

  // Save new balance
  SaveBalance(GetBalance()+depositAmount);
}

// Withdarwal Money
void WithdarwalMoney()
{
  float withdarwalAmount;

  printf("Enter your withdarwal amount: ");
  scanf("%f", &withdarwalAmount);

  // Save new balance
  SaveBalance(GetBalance()-withdarwalAmount);
}

int main()
{
  // Declare Variables
  int function;
  float balance;

  // Check balance file or create new account
  CheckFile();

  do
  {
    printf("--------------------\n");
    printf("Task 19: Account Manager\n");
    printf("--------------------\n");
    printf("Choose function that you want:\n");
    printf("1. Check your balance\n");
    printf("2. Deposit money\n");
    printf("3. Withdarwal money\n");
    printf("0. Exit the task\n");
    printf("\n");
    printf("Enter your function:\n");
    scanf("%d", &function);

    // Main task flow
    switch (function) 
    {
      case 1:
        balance = GetBalance();
        printf("Remain balance: %.2f\n", balance);
        continue;

      case 2:
        DepositMoney();
        printf("\n");
        continue;

      case 3:
        WithdarwalMoney();
        printf("\n");
        continue;

      default:
        printf("You enter wrong number! Please try again!\n");
        continue;
    }

  }
  while(function!=0);

  return 0;
}
