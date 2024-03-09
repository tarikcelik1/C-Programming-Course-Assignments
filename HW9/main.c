#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct database
{ // to defining database struct.
    struct tables *tList;
    int n;
    char *name;
} database;

typedef struct tables
{ // to defining tables struct.
    struct tables *next;
    struct table *t;
    char *tablename; // for keeping the name of tables.
} tables;

typedef struct table
{ // to defining table struct.
    char **field;
    char **type;
    bool *isNull;
    bool *isKey;
} table;

void create_database(char *name)
{ // to defining create_database function.
    /*
     * This function creates a new database struct with given name.
     *
     * Returns nothing because function type is void.
     */

    database *database1 = (database *)malloc(sizeof(database)); // to define database struct and memory allocate for it.
    database1->name = name;                                     // to define name of database with given argument.
    database1->tList = (tables *)malloc(sizeof(tables));
}

void show_table(database *d)
{ // to defining show_table function.
    /*
     * This function takes a database struct and prints the table names in this database.
     *
     * Returns nothing because the function type is void.
     */

    tables *list = (tables *)malloc(sizeof(tables)); // to define a tables struct and memory allocate for it.
    list = d->tList;                                 // to get tables from database to new struct for printing.
    while (list != NULL)
    {
        printf("%s", list->tablename); // to printing table names in database.
        list = list->next;
    }
}

void insert_table(database *d, table *t)
{ // to defining insert_table function.
    /*
     * This function takes a database struct and a table struct then it inserts the table into the ned of the linked list in database.
     *
     * Returns nothing because function type is void.
     */
    tables *iter = (tables *)malloc(sizeof(tables)); // to define a tables struct for iteration.
    iter = d->tList;                                 // to get tables from database for iteration.
    while (iter->next != NULL)
    { // to find the end of the linked list
        iter = iter->next;
    }
    iter->next->t = t; // to insert the table to end of the linked list.
    iter->next->tablename = "t";
    iter->next->next = NULL; // to define end of the linked list with NULL
}

void remove_table(database *d, char *name)
{ // to defining the remove_table function.
    /*
     * This function takes a database struct and it searches a table with given name into the database if it founds the table
     *   then it removes the table from the database.
     *
     * Returns nothing because the function type is void.
     */
    tables *list = (tables *)malloc(sizeof(tables)); // to define tables struct and memory allocate for it.
    list = d->tList;
    tables *iter = (tables *)malloc(sizeof(tables)); // to defining another tables struct for iterations and memory allocate for it.
    iter = list;

    if (strcmp(iter->tablename, name) == 0)
    { // to remove the first element of linked list case.
        iter = iter->next;
        d->tList = iter; // the head of the linked list is updated.
    }
    else
    {
        while (strcmp(iter->next->tablename, name) != 0)
        { // to remove elements in other cases.
            iter = iter->next;
        }
        iter->next = iter->next->next;
    }
}

void write_file(database *d)
{ // to define write_file function.
    /*
     * This function takes a database struct and it writes this struct into a .bin file.
     * Returns nothing because the function type is void.
     */

    FILE *fp = fopen("Database.bin", "wb+");         // to create and open a .bin file for writing.
    tables *iter = (tables *)malloc(sizeof(tables)); // to create tables struct and memory allocate for it.
    iter = d->tList;                                 // to get tables from the given database.

    while (iter->next != NULL)
    {
        fwrite(&iter, sizeof(tables), 1, fp); // to writing tables list to file.
        iter = iter->next;
    }
    fclose(fp); // to closing the file.
}

void read_file(database *d)
{ // to defining read_file function.
    /*
     * This function reads a file and it stores tables which are in file to given database struct.
     *
     * Returns nothing because the type of function is void.
     */
    FILE *fp = fopen("Database.bin", "rb+");         // to open a .bin file for reading.
    tables *iter = (tables *)malloc(sizeof(tables)); // to define a tables struct for iterations  and memory allocate for it.
    tables *temp = (tables *)malloc(sizeof(tables));
    iter = NULL;
    temp = iter;
    while (!feof(fp))
    {
        fread(&iter, sizeof(tables), 1, fp); // to reading file and storing it to the linked list.
        iter = iter->next;
        iter->next = NULL;
    }
    d->tList = temp; // for sending tables which are in file to database's linked list.
}

int main() // to defining the main funciton.
{
    char *s;
    database *database1 = (database *)malloc(sizeof(database)); // to define a database and memory allocate for it.
    create_database(s);                                         // to calling create_database function.
    tables *tables1 = (tables *)malloc(sizeof(tables));         // to define a tables struct and memory allocate for it.
    tables1 = NULL;
    table *table1 = (table *)malloc(sizeof(table)); // to define a table struct and memory allocate for it.
    insert_table(database1, table1);                // to calling insert_table function.
    show_table(database1);                          // to calling show_table function.
    remove_table(database1, s);                     // to calling remove_table function.
    return 0;
} // end of the code.