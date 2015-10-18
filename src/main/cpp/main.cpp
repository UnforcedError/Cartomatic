#include <iostream>
#include "headers/sqlite3.h"
#include "headers/DBAccess.h"
#include "headers/Deposit.h"
#include "headers/CommandlineIO.h"

using std::cout;
using std::cin;




int Product::counter = 0;
Deposit * Deposit::_instance=0;

int main(int argc, char** argv) {
//  Datenbank db = Datenbank("test.db");
//  Product bananen;
//  bananen = Product("Banane", 2.5, 1);
//  Product apfel;
//  apfel = Product("Apfel", 0.79, 1.2);
//  //cout << apfel.toString();
//
//  std::string tableName = "FOODBANK";
//
//  db.create(tableName);
//  db.add(apfel, tableName);
//  db.add(bananen, tableName);
//  db.getByName("Banane");
//  db.readAll();
    while(true) {
        CommandlineIO::mainMenu();
    }
  return 0;
}
