#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <string>

using std::string;

class Product {
private:
    int id;
    string name;
    string beschreibung;
    double preis;
    string laden;
    int bewertung;
    string alternative;
    double lagerbestand;

public:
    static int counter;

    /*
     * Different constructors
     * */
    Product(string, string, double, string, int, string, double);
    Product(string, double, double);
    Product();

    /*
     * Getter and setter methods for every member variable
     * */
    void setID(int);
    int getID();
    void setName(string);
    string getName();
    void setBeschreibung(string);
    string getBeschreibung();
    void setPreis(double);
    double getPreis();
    void setLaden(string);
    string getLaden();
    void setBewertung(int);
    int getBewertung();
    void setAlternative(string);
    string getAlternative();
    void setLagerbestand(double);
    double getLagerbestand();

   /*
    * Converts a Product to a string to use in sql commands
    */
    string toString();

};

#endif
