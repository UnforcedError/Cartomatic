//
// Created by Fabi on 08.10.2015.
//

#include "headers/Deposit.h"
#include "headers/product.h"
#include <vector>



Deposit::Deposit() {
    vectorDeposit = std::vector<Product>();
    singleProduct = Product();
}

Deposit *Deposit::getInstance() {
    if(_instance == 0){
        _instance = new Deposit();
    }
    return _instance;
}

std::vector<Product> Deposit::getVector() {
    return this->vectorDeposit;
}

Product Deposit::getProduct() {
    return this->singleProduct;
}

void Deposit::saveSet(std::vector <Product> set_product) {
    this->vectorDeposit.clear();
    this->vectorDeposit=set_product;
}

void Deposit::saveSingle(Product single_product) {
    this->singleProduct = single_product;
}

void Deposit::addProduct(Product single_product) {
    this->vectorDeposit.push_back(single_product);
}

void Deposit::clear() {
    this->vectorDeposit.clear();
    this->singleProduct = Product();
}
