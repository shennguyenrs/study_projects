#include <stdio.h>
#include <stdbool.h>

// Declare global variables
static char * fileName = "books.db";

// Sub functions
#include "callback.c"
#include "OpenTable.c"
#include "CheckDatabase.c"
#include "CreateTable.c"
#include "ShowGenre.c"

// Main functions
#include "MenuOne.c"
#include "MenuTwo.c"

#include "AddNewTitle.c"
#include "SearchKeyword.c"
#include "SearchIsbn.c"
#include "DeleteBook.c"
#include "ListGenre.c"

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
