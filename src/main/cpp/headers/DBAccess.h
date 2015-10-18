#ifndef __DB_ACCESS__
#define  __DB_ACCESS__

#include "sqlite3.h"
#include "product.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace utility {
    /*
     * Checks whether a given String has the value NULL, which would be illegal for some uses
     */
    std::string checkForNull(char *null);

    /*
     * converts a string to all lower case characters
     */
    void toLower(std::string *input);

    /*
     * prints the content of a vector as a list
     */
    void printAsList(vector<Product> list);
}

class Datenbank {
private:
    sqlite3 *db;
    int rc;
    char *zErrMsg;
    //vector<string> tables;
    string dbName;

public:
    //Constructors
    Datenbank();
    Datenbank(string dbName);

    /* Create a Table with a given Name
     */
    int create(string table_name);

    /* Add a new prduct to the table.
    * This function is intended for use with products that are not in stock yet.
    */
    int add(Product data, string tableName);

    /*
     *Reads the whole Database
     */
    vector<Product> readAll();

    /*
     * Searches the Database for a specific Attribute/Product
     */
    void getProduct(string field, string criterion);

    /*
     * Searches for ID
     */
    Product getByID(int id);

    /*
     * Finds single Product by Name.
     * returns the first Product with the given Name
     */
    Product getByName(string name);

    /*
     * Finds all products with a matching name.
     * It'recommended to use this method
     */
    vector<Product> getVectorByName(string name);





};


#endif
