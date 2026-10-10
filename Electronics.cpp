
#include "../include/Electronics.h"

// Constructor definition
Electronics::Electronics(int id, string n, double p, int s, int warranty)
    : Product(id, n, p, s) {

    warrantyMonths = warranty;
}

// Display electronics product details
void Electronics::display() const {

    // Display common product details
    Product::display();

    // Display electronics-specific detail
    cout << "Warranty: " << warrantyMonths << " months" << endl;
}
