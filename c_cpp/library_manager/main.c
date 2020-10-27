#include <stdio.h>
#include <stdbool.h>

#include "libs/Books.h"

int main()
{
    // Declare variables
    unsigned int choose;
    unsigned int count;
    FILE * file;

    // Welcome Screen
    printf("==================================\n");
    printf("           Library Manager        \n");
    printf("==================================\n");
    printf("\n");

    do
    {
        // Check database exist
        if((file = fopen(filename, "r"))==NULL)
        {
            printf("Not found database in local!\n");
            // Create new database
            CreateTable();
            printf("\n");
        }

        // Check data in database
        if((count=CheckDatabase())==0)
        {
            choose = MenuOne();
        }
        else
        {
            choose = MenuTwo();
        }

        // Switch case functions
        switch(choose)
        {
            case 1:
                AddNewTitle();
                continue;
            case 2:
                SearchIsbn();
                continue;
            case 3:
                SearchKeyword();
                continue;
            case 4:
                DeleteBook();
                continue;
            case 5:
                ListByGenre();
                continue;
            case 0:
                break;
        }
    }
    while(choose!=0);

    return 0;
}
