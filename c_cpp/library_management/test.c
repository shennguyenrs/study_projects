#include<stdio.h>
#include<string.h>
#include<sqlite3.h>

// Create database function
void CreateDataBase()
{
    // Declcare table
    sqlite3 * database;
    char * sql = "CREATE TABLE Books("
                    "isbn INT PRIMARY KEY NOT NULL,"
                    "name TEXT NOT NULL,"
                    "amount INT NOT NULL,"
                    "subject TEXT NOT NULL"
                    ");";

    int exit = 0;
    char * errorMessage;

    // Create table 
    sqlite3_open("books.db", &database);
    exit = sqlite3_exec(database, sql, NULL, NULL, &errorMessage);

    // Print error
    if(exit!=SQLITE_OK)
    {
        printf("Error Create Table!");
        sqlite3_free(errorMessage);
    }
    else
    {
        printf("Successfully Create Table!");
    }
}

// Callback Function
int callback(void * data, int argc, char ** argv, char ** azColName)
{
    int i = 0;

    // Print out data
    for(i=0; i<argc; i++)
    {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : NULL);
    }
    printf("\n");

    return 0;
}

int main()
{
    // Declare variables
    sqlite3 * database;
    int exit = 0;
    char * errmsg;
    FILE * file;

    // Create database if it is not exist
    if((file = fopen("books.db", "r"))==NULL)
    {
        printf("Not found the database!\n");
        printf("Create new database!\n");
        CreateDataBase();
    }
    else
    {
        fclose(file);

        // Open database
        sqlite3_open("books.db", &database);

        // Queries
        char * selectQuery = "SELECT * FROM Books;";
        /*char * deleteQuery = "DELETE FROM Books WHERE isbn = 3;";*/
        char * values = "INSERT INTO Books VALUES(1, 'C Programming', 1, 'Textbook');" 
                        "INSERT INTO Books VALUES(2, 'C++ Programming', 1, 'Textbook');"
                        "INSERT INTO Books VALUES(3, 'Internet of things', 2, 'Technology');";

        exit = sqlite3_exec(database, values, NULL, NULL, &errmsg);

        if(exit!=SQLITE_OK)
        {
            printf("Error Insert!\n");
            sqlite3_free(errmsg);
        }
        else
        {
            printf("Successfully Insert!\n");
        }

        sqlite3_exec(database, selectQuery, callback, NULL, NULL);
    }

    // Close datatbase
    sqlite3_close(database);

    return 0;
}
