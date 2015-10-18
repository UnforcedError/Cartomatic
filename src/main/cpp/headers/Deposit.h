//
// Created by Fabi on 08.10.2015.
//

#ifndef CARTOMATIC_DEPOSIT_H
#define CARTOMATIC_DEPOSIT_H

#include<vector>
#include "product.h"

/*
 * utility-class to get real products from SELECT invocations
 * */
class Deposit {
private:

    /*
     * member variables
     * */
    std::vector<Product> vectorDeposit;
    Product singleProduct;

    /*
     * Constructors. private to allow only one instance
     * */
    Deposit();
    Deposit( const Deposit&);
    static Deposit* _instance;

public:
    /*
     * Methods to get the content out of the vaults
     * */
    std::vector<Product> getVector();
    Product getProduct();

    /*
     * Methods to save Products to the vaults
     * */
    void saveSingle(Product single_product);
    void saveSet(std::vector<Product> set_product);
    void addProduct(Product single_product);

    /**
     * Returns the Deposit only instance
     */
    static Deposit *getInstance();

    /*
     * Clears the Deposit
     */
    void clear();

};

//Deposit *Deposit::_instance = 0;
#endif //CARTOMATIC_DEPOSIT_H
