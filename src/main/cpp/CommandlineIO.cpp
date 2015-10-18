//
// Created by Fabi on 13.10.2015.
//
#include <iostream>
#include <string>
#include "headers/CommandlineIO.h"
#include "headers/DBAccess.h"
#include <stdlib.h>

using std::cout;
using std::cin;

void CommandlineIO::mainMenu() {
    std::string input;

    //Creating the DB
    Datenbank db = Datenbank("test.db");
    Product bananen;
    bananen = Product("Banane", 2.5, 2);
    db.add(bananen, "FOODBANK");
    Product apfel;
    apfel = Product("Apfel", 0.79, 1.2);
    std::string tableName = "FOODBANK";
    db.create(tableName);


    //User interaction
    system("cls");
    cout << "|*******************************************|" << std::endl;
    cout << "|_________________MAIN MENU_________________|" << std::endl;
    cout << "|                                           |" << std::endl;
    cout << "|+ enter 'a' to start the add dialog        |" << std::endl;
    cout << "|+ enter 'c' to start the consumption dialog|" << std::endl;
    cout << "|+ enter 'all' to list the whole stack      |" << std::endl;
    cout << "|+ enter 'exit' to exit this program        |" << std::endl;
    cout << "|*******************************************|" << std::endl;

    cin >> input;
    utility::toLower(&input);

    if(input == "a") {
        cout << std::endl << "You chose the option 'add'" << std::endl;
        CommandlineIO::add(&db);
    } else if(input == "c") {
        cout << std::endl << "You chose the option 'consume'" << std::endl;
        consume(&db);
    } else if(input == "all") {
        cout << std::endl << "You chose the option 'show all'" << std::endl;
        utility::printAsList(db.readAll());
        cout << std::endl << "type in any character to proceed" << std::endl;
        cin >> input;
    } else if(input == "exit") {
        cout << std::endl << "Goodbye, thank you for using Cartomatic" << std::endl;
        return;
    } else {
        cout << "your input did not match any of the given options";
        cout << input;
    }
}

void CommandlineIO::add(Datenbank *db) {
    std::string name;
    int index;
    double add;
    vector<Product> searchResults;
    Product searchResult;

    system("cls");
    cout << "____________________ADD________________" << std::endl;
    cout << "enter the Name of the product to enter." << std::endl << "name: ";

    cin >> name;
    searchResults = db->getVectorByName(name);
    utility::printAsList(searchResults);
    cout << std::endl;
    cout << "Type in the INDEX that belongs to the product you want to add (only integers allowed): ";
    cin >> index; cout << std::endl;
    cout << "Which amount shall be added? (Numbers in double-format allowed)"; cin >> add;
    searchResults.at(index - 1).setLagerbestand(searchResults.at(index - 1).getLagerbestand() + add);
    cout << std::endl << "New stock is " <<searchResults.at(index - 1).getLagerbestand() << std::endl;
}

void CommandlineIO::consume(Datenbank *db) {
    system("cls");
    system("echo NOT IMPLEMENTED YET");
}


