#include <stdio.h>
#include <sqlite3.h>

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
