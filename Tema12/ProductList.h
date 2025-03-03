#pragma once

#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <iostream>
#include <string>
using namespace std;


struct Product {
    string name;
    double price;
    int quantity;
    Product* next;
    Product(string n, double p, int q) : name(n), price(p), quantity(q), next(nullptr) {}
};

class ProductList {
private:
    Product* head;
public:
    ProductList() : head(nullptr) {}
    ~ProductList();
    void addProduct(string name, double price, int quantity);
    void displayProducts() const;
    ProductList* copyList() const;
    void deleteProduct(string name);
    Product* searchProduct(string name) const;
    void updateQuantity(string name, int newQuantity);
    void sortByName();
    void sortByPrice();
};

#endif
