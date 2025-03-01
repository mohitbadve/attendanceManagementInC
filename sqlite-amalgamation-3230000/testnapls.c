#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   
   
    sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, "INSERT INTO ATM (NAME,PIN) VALUES (?,?);", 41, &stmt, NULL);
if(stmt != NULL) {
    sqlite3_bind_text(stmt, 1, "John", SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, number);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  printf("Hi");
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
	  printf("Hello");
   }
   sqlite3_close(db);
   return 0;
}