#include <stdio.h>
#include <sqlite3.h>

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
