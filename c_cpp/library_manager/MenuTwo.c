#include <stdio.h>
#include <stdbool.h>

int MenuTwo()
{
    // Declare variables
    int choose;
    bool isTrue = false;

    printf("1 = Add new book\n");
    printf("2 = Search by ISBN-13 or ISBN-10\n");
    printf("3 = Search by a keyword\n");
    printf("4 = Edit information of a title\n");
    printf("5 = List all the titles of one genre\n");
    printf("0 = Exit\n");
    printf("\n");

    // Input validation
    do 
    {
        printf("Input function number: ");
        scanf("%d", &choose);


        // Change isTrue conditions if
        // there is a new function
        isTrue = (choose==0 || choose==1 || choose==2 || choose==3 || choose==4 || choose==5);

        if(!isTrue)
        {
            printf("Wrong input number!\n");
            printf("Please try again!\n");
        }

    }
    while(!isTrue);

    return choose;
}
