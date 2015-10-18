//
// Created by Fabi on 05.10.2015.
//
#include "headers/product.h"
#include <sstream>

using std::string;



Product::Product(string name, double preis, double lagerbestand) {
    ++(this->counter);
    setID(this->counter);
    setName(name);
    setPreis(preis);
    setLagerbestand(lagerbestand);
    setBeschreibung("");
    setAlternative("");
    setLaden("");
    setBewertung(0);
}

Product::Product(string name, string beschreibung, double preis, string laden, int bewertung, string alternativen, double lagerbestand) {
    ++counter;
    setID(counter);
    setName(name);
    setBeschreibung(beschreibung);
    setPreis(preis);
    setLaden(laden);
    setBewertung(bewertung);
    setAlternative(alternativen);
    setLagerbestand(lagerbestand);
}

Product::Product() {
    ++counter;
    setID(counter);
    setName("default");
    setBeschreibung("");
    setPreis(0.0);
    setLaden("");
    setBewertung(0);
    setAlternative("");
    setLagerbestand(0.0);
}

string Product::toString() {
    std::ostringstream oss;
    oss << "(";
    oss << this->id << ", ";
    oss << "'" << this->name << "'" << ", ";
    if (this->beschreibung == "")
        oss << "NULL" << ", ";
    else
        oss << "'" << this->beschreibung << "'" << ", ";

    oss << this->preis << ", ";
    if(this->laden == "")
        oss << "NULL" << ", ";
    else
        oss << "'" << this->laden << "'" << ", ";

    if(this->bewertung == 0)
        oss << 0 << ", ";
    else
        oss << this->bewertung << ", ";

    if(this->alternative == "")
        oss << "NULL" << ", ";
    else
        oss << "'" << this->alternative << "'" << ", ";

    oss << this->lagerbestand << ")";

    return oss.str();
}


//Setter Methoden

void Product::setID(int id) {
    this->id = id;
}

void Product::setName(string name) {
    this->name = name;
}

void Product::setBeschreibung(string beschreibung) {
    this->beschreibung = beschreibung;
}

void Product::setPreis(double preis) {
    this->preis = preis;
}

void Product::setLaden(string laden) {
    this->laden = laden;
}

void Product::setBewertung(int bewertung) {
    this->bewertung = bewertung;
}

void Product::setAlternative(string alternative) {
    this->alternative = alternative;
}

void Product::setLagerbestand(double lagerbestand) {
    this->lagerbestand = lagerbestand;
}


//Getter Methoden

int Product::getID() {
    return id;
}

string Product ::getName() {
    return name;
}

string Product::getBeschreibung() {
    return beschreibung;
}

double Product::getPreis() {
    return preis;
}

string Product::getLaden() {
    return laden;
}

int Product::getBewertung() {
    return bewertung;
}

string Product::getAlternative() {
    return alternative;
}

double Product::getLagerbestand() {
    return lagerbestand;
}