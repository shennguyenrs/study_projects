#include <stdio.h>
#include <stdbool.h>

#include "MenuOne.c"
#include "MenuTwo.c"
#include "OpenTable.c"
#include "CheckDatabase.c"
#include "CreateTable.c"

#include "AddNewTitle.c"
#include "SearchTitle.c"
#include "EditTitle.c"
#include "ListGenre.c"

int main()
{
    // Declare variables
    unsigned int choose;
    unsigned int count;
    char * fileName = "books.db";
    FILE * file;

    // Welcome Screen
    printf("==================================\n");
    printf("           Library Manager        \n");
    printf("==================================\n");
    printf("\n");

    do
    {
        // Check database exist
        if((file = fopen(fileName, "r"))==NULL)
        {
            // Create new database
            CreateTable();
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
                SearchTitle();
                continue;
            case 3:
                EditTitle();
                continue;
            case 4:
                ListGenre();
                continue;
            case 0:
                break;
        }
    }
    while(1);

    return 0;
}
