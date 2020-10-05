#include <stdio.h>
#include <stdbool.h>

int MenuTwo()
{
    // Declare variables
    int choose;
    bool isTrue = false;

    printf("1 = Add new book\n");
    printf("2 = Search for a title\n");
    printf("3 = Edit information of a title\n");
    printf("4 = List all the titles of one genre\n");
    printf("0 = Exit\n");
    printf("\n");

    // Input validation
    do 
    {
        printf("Input function number:");
        scanf("%d", &choose);

        isTrue = (choose==0 || choose==1 || choose==2 || choose==3 || choose==4);

        if(!isTrue)
        {
            printf("Wrong input number!\n");
            printf("Please try again!\n");
        }

    }
    while(!isTrue);

    return choose;
}
