//
// Created by Fabi on 13.10.2015.
//

#ifndef CARTOMATIC_COMMANDLINEIO_H
#define CARTOMATIC_COMMANDLINEIO_H

#include "DBAccess.h"

class CommandlineIO {
public:
    /*
     * displays the main menu
     */
    static void mainMenu();

    /*
     * The dialog to add your groceries
     */
    static void add(Datenbank *db);

    /*
     * consume dialog
     */
    static void consume(Datenbank *db);


};


#endif //CARTOMATIC_COMMANDLINEIO_H
