
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

// Base class for all products
class Product {
private:
    int productId;
    string name;
    double price;
    int stock;

public:
    // Constructor
    Product(int id, string n, double p, int s);

    // Virtual destructor
    virtual ~Product();

    // Get product ID
    int getProductId() const;

    // Get product name
    string getName() const;

    // Get product price
    double getPrice() const;

    // Get available stock
    int getStock() const;

    // Reduce stock after purchase
    void reduceStock(int quantity);

    // Virtual function for runtime polymorphism
    virtual void display() const;

    // Check whether requested quantity is available
    bool isAvailable(int quantity) const;
};

#endif
