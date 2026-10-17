
#include "../include/Clothing.h"

// Constructor definition
Clothing::Clothing(int id, string n, double p, int s, string sz)
    : Product(id, n, p, s) {

    size = sz;
}

// Display clothing product details
void Clothing::display() const {

    // Display common product details
    Product::display();

    // Display clothing-specific detail
    cout << "Size: " << size << endl;
}
