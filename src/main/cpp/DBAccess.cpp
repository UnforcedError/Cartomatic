#include "headers/DBAccess.h"
#include "headers/Deposit.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


//Functions from the namespace UTILITY
std::string utility::checkForNull(char *null) {
    if(!null) {
        return "NULL";
    }
    else {
        return null;
    }
}

void utility::toLower(std::string *input) {
    std::transform(input->begin(), input->end(), input->begin(), ::tolower);
}

void utility::printAsList(vector<Product> list) {
    int counter;
    counter = 1;

    cout << "\t Index\tNAME\tLADEN\tPPREIS\tLagerbestand" << std::endl;

    for(auto i = list.begin(); i != list.end(); ++i){
        cout << "\t" << counter << "\t" << i->getName() << "\t" << i->getLaden() << "\t" << i->getPreis() << "\t" << i->getLagerbestand() << std::endl;
        ++counter;
    }


}

//Callback
static int saveToDeposit(void *NotUsed, int argc, char **argv, char **azColName) {
    Product temp;
    vector<Product> temp_v;
    if(argc = 8) {
        temp = Product(
                utility::checkForNull(argv[1]),
                utility::checkForNull(argv[2]),
                stod(argv[3]),
                utility::checkForNull(argv[4]),
                atoi(argv[5]),
                utility::checkForNull(argv[6]),
                stod(argv[7])
        );
        Deposit::getInstance()->addProduct(temp);
    }

    temp_v = Deposit::getInstance()->getVector();
    return 0;
}

//Datenbank's methods
Datenbank::Datenbank() {
  this->dbName = "default.db";
  zErrMsg = (char *) "";
  cout << "Datenbank erstellt!" << endl;
}

Datenbank::Datenbank(string name) {
  dbName = name;
  zErrMsg = (char *) "";
  cout << "Datenbank erstellt!" << endl;

};

int Datenbank::create(string table_name) {

  //open Database
  rc = sqlite3_open(this->dbName.c_str(), &db);
  if(rc) {
    cout << "Can't open database" << endl;
    return(1);
  } else {
    cout << "Opened successfully";
  }

  string sql_create = "CREATE TABLE " + table_name + " (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL," +
          " BESCHREIBUNG TEXT, PREIS REAL NOT NULL, LADEN TEXT, BEWERTUNG TEXT, ALTERNATIVEN TEXT," +
          " LAGERBESTAND REAL NOT NULL);";

  //Execute the SQL-Statement
  rc = sqlite3_exec(db, sql_create.c_str(), saveToDeposit, 0, &zErrMsg);
  if(rc != SQLITE_OK) {
    cout << "SQL-Error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
  } else {
    cout << "Command executed successfully!" << endl;
  }

  sqlite3_close(db);
  return 0;
}

int Datenbank::add(Product data, string tableName) {
    ostringstream oss;
    string sql;

    oss << "INSERT INTO " << tableName << " (ID,NAME,BESCHREIBUNG,PREIS,LADEN,BEWERTUNG,ALTERNATIVEN,LAGERBESTAND) VALUES ";
    oss << data.toString();
    oss << ";";

    sql = oss.str();

    //open Database
    rc = sqlite3_open(this->dbName.c_str(), &db);
    if(rc) {
        cout << "Can't open database" << endl;
        return 1;
    } else {
        cout << "Opened successfully";
    }

    //Execute the SQL-Statement
    rc = sqlite3_exec(db, sql.c_str(), saveToDeposit, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL-Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        cout << "Command executed successfully!" << endl;
    }
    sqlite3_close(db);
    return 0;
}

vector<Product> Datenbank::readAll() {
    string sql;

    //open Database
    rc = sqlite3_open(this->dbName.c_str(), &db);
    if(rc) {
        cout << "Can't open database" << endl;
    } else {
        cout << "Opened successfully";
    }

    sql = "SELECT * from FOODBANK";

    //Execute the SQL-Statement
    rc = sqlite3_exec(db, sql.c_str(), saveToDeposit, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL-Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Command executed successfully!" << endl;
    }
    sqlite3_close(db);

    return Deposit::getInstance()->getVector();
}

Product Datenbank::getByID(int id) {
    string sql;
    stringstream ss;
    vector<Product> erg;

    Deposit::getInstance()->clear();
    //open Database
    rc = sqlite3_open(this->dbName.c_str(), &db);
    if(rc) {
        cout << "Can't open database" << endl;
    } else {
        cout << "Opened successfully";
    }

    ss << "SELECT * from FOODBANK WHERE ID =" << id << ";";
    sql = ss.str().c_str();

    //Execute the SQL-Statement
    rc = sqlite3_exec(db, sql.c_str(), saveToDeposit, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL-Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Command executed successfully!" << endl;
    }
    sqlite3_close(db);

    erg = Deposit::getInstance()->getVector();
    if (erg.size() == 1) {
        return erg.at(0);
    } else {
        for(auto i = erg.begin(); i != erg.end(); ++i) {
            if(i->getID() == id) {
                return *i;
            }
        }
        cout << "ID not found" << endl;
        return Product();
    }
}

Product Datenbank::getByName(string name) {
    string sql;
    stringstream ss;
    vector<Product> erg;

    Deposit::getInstance()->clear();
    //open Database
    rc = sqlite3_open(this->dbName.c_str(), &db);
    if(rc) {
        cout << "Can't open database" << endl;
    } else {
        cout << "Opened successfully";
    }

    ss << "SELECT * from FOODBANK WHERE NAME = '" << name << "';";
    sql = ss.str().c_str();

    //Execute the SQL-Statement
    rc = sqlite3_exec(db, sql.c_str(), saveToDeposit, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL-Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Command executed successfully!" << endl;
    }
    sqlite3_close(db);

    erg = Deposit::getInstance()->getVector();
    if (erg.size() == 1) {
        return erg.at(0);
    } else {
        for(auto i = erg.begin(); i != erg.end(); ++i) {
            if(i->getName() == name) {
                return *i;
            }
        }
        cout << "NAME not found" << endl;
        return Product();
    }
}

vector<Product> Datenbank::getVectorByName(string name) {
    string sql;
    stringstream ss;
    vector<Product> erg;

    Deposit::getInstance()->clear();
    //open Database
    rc = sqlite3_open(this->dbName.c_str(), &db);
    if(rc) {
        cout << "Can't open database" << endl;
    } else {
        cout << "Opened successfully";
    }

    ss << "SELECT * from FOODBANK WHERE NAME = '" << name << "';";
    sql = ss.str().c_str();

    /*
     * Execute the SQL-Statement
     * Die Callbackfunktion "saveToDeposit" speichert das Ergebnis der Datenbank-Abfrage im Deposit
     */
    rc = sqlite3_exec(db, sql.c_str(), saveToDeposit, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cout << "SQL-Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Command executed successfully!" << endl;
    }
    sqlite3_close(db);

    erg = Deposit::getInstance()->getVector();

    return erg;
}