
#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"
using namespace std;

// Clothing inherits from Product
class Clothing : public Product {
private:
    string size;

public:
    // Constructor
    Clothing(int id, string n, double p, int s, string sz);

    // Override display function
    void display() const override;
};

#endif
