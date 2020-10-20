#include <stdio.h>
#include <stdbool.h>

int MenuOne()
{
    // Declare variable
    int choose;
    bool isTrue = false;

    printf("You do not have any book in database!\n");
    printf("Please add more books!\n");
    printf("\n");
    printf("1 = Add new book\n");
    printf("0 = Exit\n");
    printf("\n");

    // Input validation
    do 
    {
        printf("Input function number: ");
        scanf("%d%*c", &choose);

        isTrue = (choose==0 || choose==1);

        if(!isTrue)
        {
            printf("Wrong input number!\n");
            printf("Please try again!\n");
        }

    }
    while(!isTrue);

    return choose;
}
