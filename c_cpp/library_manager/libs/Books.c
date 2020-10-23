#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <string.h>

#include "Books.h"

/* Sub-functions */

 /*
  * Call back - Print out the result of the queries
  */
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

/*
 * Open Table - Open SQLite3 data table
 */
sqlite3 * OpenTable()
{
  // Declare variables
  sqlite3 * table;

  // Open tables
  int exit = sqlite3_open(fileName, &table);

  // Print out the message if error
  if(exit!=SQLITE_OK)
  {
    printf("Error when open database!\n");
  }

  return table;
}

/*
 * Check Database - Count the number of books available in the database
 */
int CheckDatabase()
{
  // Declare variable
  int count = 0;

  sqlite3 * table;
  sqlite3_stmt * res;

  // Query statement
  char * query = "SELECT COUNT(*) FROM Books;";

  // Open table
  table = OpenTable();

  // Prepare statement
  sqlite3_prepare_v2(table, query, -1, &res, 0);

  // Do query to count the book in database
  sqlite3_step(res);
  count = sqlite3_column_int(res, 0);

  // Clear prepare statement
  sqlite3_finalize(res);

  // Close table
  sqlite3_close(table);
  
  return count;
}

/*
 * Create Database - Create data table in SQLite3, incase the local database is not available
 */
void CreateTable()
{
  // Decare table schema
  sqlite3 * table;
  char * sql = "CREATE TABLE Books("
              "isbn13 TEXT PRIMARY KEY NOT NULL,"
              "isbn10 TEXT,"
              "title TEXT NOT NULL,"
              "author TEXT NOT NULL,"
              "publisher TEXT,"
              "amount INT NOT NULL,"
              "genre TEXT,"
              "language TEXT"
              ");";

  // Declare variables
  int exit;
  char * errmsg;

  // Create Table
  table = OpenTable();
  exit = sqlite3_exec(table, sql, NULL, NULL, &errmsg);

  // Notify if create table has error
  if(exit!=SQLITE_OK)
  {
    printf("Error when create new table!\n");
    sqlite3_free(errmsg);
  }
  else
  {
    printf("Successfully create new database!\n");
  }

  // Close table
  sqlite3_close(table);
}

/*
 * Show Genre - Show all the genre in the databas, if genre is missing, it is Others
 */
void ShowGenre()
{
  // Declare variables
  char * query = "SELECT DISTINCT genre FROM Books;";

  // Open sql table
  sqlite3 * table;

  table = OpenTable();

  // Excute query
  sqlite3_exec(table, query, callback, NULL, NULL);

  // Close table
  sqlite3_close(table);
}

/*
 * Get Values - Get the input values into struct
 */
struct BookInfo getValue()
{
  // Declare variables
  struct BookInfo input;

  input.title = malloc(MAX_STRING*sizeof(char));
  input.author = malloc(MAX_STRING*sizeof(char));
  input.publisher = malloc(MAX_STRING*sizeof(char));
  input.genre = malloc(MAX_STRING*sizeof(char));
  input.language = malloc(MAX_STRING*sizeof(char));

  unsigned int len;

  // Isbn 13
  printf("ISBN-13 (Without dash): ");
  fgets(input.isbn13, 13, stdin);

  // Isbn 10
  printf("ISBN-10 (Without dash): ");
  fgets(input.isbn10, 10, stdin);

  // Title
  printf("Title: ");
  fgets(input.title, 1024, stdin);
  len = strlen(input.title);
  input.title = realloc(input.title, len);

  // Author
  printf("Author: ");
  fgets(input.author, 1024, stdin);
  len = strlen(input.author);
  input.author = realloc(input.author, len);
  
  // Publisher
  printf("Publisher: ");
  fgets(input.publisher, 1024, stdin);
  len = strlen(input.publisher);
  input.publisher = realloc(input.publisher, len);

  // Amount
  printf("Amount: ");
  scanf("%s%*c", input.amount);

  // Genre
  printf("Genre: ");
  fgets(input.genre, 1024, stdin);
  len = strlen(input.genre);
  input.genre = realloc(input.genre, len);

  // Language
  printf("Language: ");
  fgets(input.language, 1024, stdin);
  len = strlen(input.language);
  input.language = realloc(input.language, len);

  return input;
}

/* Main Functions */

/*
 * Menu One - When the local database is not available
 */
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

/*
 * Menu Two - When the local database is available
 */
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
    scanf("%d%*c", &choose);

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

/*
 * Add New Titles - Insert new titles into the database
 */
void AddNewTitle()
{
  // Prompts
  printf("\n");
  printf("------------------------------\n");
  printf("Add New Book\n");
  printf("------------------------------\n");

  // Declare struct
  struct BookInfo book = getValue();

  // SQL Insert statement
  char * insert = "INSERT INTO Books VALUE(";
  char end[] = ");";

  strcat(insert, book.isbn13);
  strcat(insert, ",");
  strcat(insert, book.isbn10);
  strcat(insert, ",");
  strcat(insert, book.title);
  strcat(insert, ",");
  strcat(insert, book.author);
  strcat(insert, ",");
  strcat(insert, book.publisher);
  strcat(insert, ",");
  strcat(insert, book.amount);
  strcat(insert, ",");
  strcat(insert, book.genre);
  strcat(insert, ",");
  strcat(insert, book.language);
  strcat(insert, end);
  
  // Open database and insert
  char * errmsg;
  sqlite3 * table;

  table = OpenTable();

  int exit = sqlite3_exec(table, insert, NULL, NULL, &errmsg);

  // Check if insert is fine
  if(exit!=SQLITE_OK)
  {
    printf("Error Insert!\n");
    sqlite3_free(errmsg);
  }
  else
  {
    printf("Insert data successfully!\n");
  }

  // Close database
  sqlite3_close(table);
}

/*
 * Search Keyword - Search book information by using a keyword in title
 */
void SearchKeyword()
{
  // Declare variables
  char * keyword = malloc(MAX_STRING*sizeof(char));
  unsigned int len;

  // Prompts
  printf("Search by a keyword in title\n");
  printf("------------------------------\n");
  printf("\n");

  printf("Input search keyword: ");
  scanf("%s%*c", keyword);

  len = strlen(keyword);
  keyword = realloc(keyword, len);

  // Prepare SQL statement
  char * query = "SELECT * FROM Books WHERE title LIKE %";
  char end[] = "%;";

  strcat(query, keyword);
  strcat(query, end);

  // Open sql table
  sqlite3 * table;

  table = OpenTable();

  // Excute sql statement
  sqlite3_exec(table, query, callback, NULL, NULL);

  // Free memory
  free(keyword);

  // Close table
  sqlite3_close(table);
}

/*
 * Search ISBN - Search book information by using isbn
 */
void SearchIsbn()
{
  // Declare variables
  char isbn[13];
  unsigned int len;
  unsigned int i;
  bool isTrue = true;

  // Prompts
  printf("Search by ISBN-13 or ISBN-10\n");
  printf("------------------------------\n");
  printf("\n");

  // Input validation
  do
  {
    printf("Input ISBN-13 or ISBN-10 (Without -): ");
    scanf("%s", isbn);

    len = strlen(isbn);

    // Check dash
    for(i=0; i<len; i++)
    {
      if(isbn[i]=='-')
      {
        isTrue = false;
        break;
      }
    }

    // Is true when string has 13 or 10 characters
    isTrue = (isTrue && len==13) || (isTrue && len==10);

    if(!isTrue)
    {
      printf("You enter wrong format!\n");
      printf("Please try again!\n");
    }

  } while(!isTrue);

  // Prepare sql query bases on result
  char * query;
  char end[] = ";";
  sqlite3 * table;

  if(len==10)
  {
    query = "SELECT * FROM Books WHERE isbn10=";
  }
  else
  {
    query = "SELECT * FROM Books WHERE isbn13=";
  }

  // Concat the query string
  strcat(query, isbn);
  strcat(query, end);

  // Open table and excute the statement
  table = OpenTable();

  sqlite3_exec(table, query, callback, NULL, NULL);

  // Close table
  sqlite3_close(table);
}

/*
 * Delete Book - Delete a title in the database using ISBN
 */
void DeleteBook()
{
  // Declare variables
  char isbn[13];
  unsigned int len;
  unsigned int i;
  bool isTrue = true;

  // Prompts
  printf("Delete a Book in database");
  printf("------------------------------\n");
  printf("\n");

  // Input validation
  do
  {
    printf("Input ISBN-13 or ISBN-10 (Without -): ");
    scanf("%s", isbn);

    len = strlen(isbn);

    // Check dash
    for(i=0; i<len; i++)
    {
      if(isbn[i]=='-')
      {
        isTrue = false;
        break;
      }
    }

    // Is true when string has 13 or 10 characters
    isTrue = (isTrue && len==13) || (isTrue && len==10);

    if(!isTrue)
    {
      printf("You enter wrong format!\n");
      printf("Please try again!\n");
    }

  } while(!isTrue);

  // Prepare sql query bases on result
  char * query;
  char end[] = ";";
  sqlite3 * table;

  if(len==10)
  {
    query = "DELETE FROM Books WHERE isbn10=";
  }
  else
  {
    query = "DELETE FROM Books WHERE isbn13=";;
  }

  // Concat the query string
  strcat(query, isbn);
  strcat(query, end);

  // Open table and excute the statement
  table = OpenTable();

  int exit = sqlite3_exec(table, query, callback, NULL, NULL);

  // Send message if fail to delete record
  if(exit!=SQLITE_OK)
  {
    printf("Fail to delete the book!\n");
  }

  // Close table
  sqlite3_close(table);
}

/*
 * List by Genre - List all the book information by a kind of genre
 */
void ListByGenre()
{
  // Declare variables
  char * keyword = malloc(MAX_STRING*sizeof(char));
  unsigned int len;

  // Prompts
  printf("List all the book in a selected genre\n");
  printf("------------------------------\n");
  printf("\n");

  // Show all Genres
  ShowGenre();

  printf("Input genre: ");
  scanf("%s%*c", keyword);

  len = strlen(keyword);
  keyword = realloc(keyword, len);

  // Prepare SQL statement
  char * query = "SELECT * FROM Books WHERE genre=";
  char end[] = ";";

  strcat(query, keyword);
  strcat(query, end);

  // Open sql table
  sqlite3 * table;

  table = OpenTable();

  // Excute sql statement
  sqlite3_exec(table, query, callback, NULL, NULL);

  // Free memory
  free(keyword);

  // Close table
  sqlite3_close(table);
}
