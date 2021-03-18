#include "sqllite.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>

namespace _SqlLite {
    static int callback(void *data, int argc, char **argv, char **azColName){
        int i;
        fprintf(stderr, "%s: ", (const char*)data);
        
        for(i = 0; i<argc; i++){
            //printf("%s = %s\n", azColName[i], );
            std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " ; ";
        }
        
        //printf("\n");
        std::cout << std::endl;
        return 0;
    }

    int SqlLite::sql() {
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        char *sql;
        const char* data = "Callback function called";

        printf("%s\n", sqlite3_libversion());
    
        /* Open database */
        rc = sqlite3_open("test.db", &db);
   
        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            return(0);
        } else {
            fprintf(stdout, "Opened database successfully\n");
        }

        /* Create SQL statement */
        sql = "CREATE TABLE COMPANY("  \
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "AGE            INT     NOT NULL," \
            "ADDRESS        CHAR(50)," \
            "SALARY         REAL );";

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Table created successfully\n");
        }

        /* Create SQL statement */
        sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
                "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
                "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
                "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
                "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
                "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Records created successfully\n");
        }

        /* Create SQL statement */
        sql = "SELECT * from COMPANY";

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
        
        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Operation done successfully\n");
        }

        sqlite3_close(db);
        return 0;
    }

    std::string SqlLite::encode(const std::string& word) const {
        return word;
    }
    
}