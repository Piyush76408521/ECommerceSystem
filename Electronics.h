
#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Product.h"
using namespace std;

// Electronics inherits from Product
class Electronics : public Product {
private:
    int warrantyMonths;

public:
    // Constructor
    Electronics(int id, string n, double p, int s, int warranty);

    // Override display function
    void display() const override;
};

#endif
