
#include "../include/Product.h"

// Constructor definition
Product::Product(int id, string n, double p, int s) {
    productId = id;
    name = n;
    price = p;
    stock = s;
}

// Destructor definition
Product::~Product() {
    // No dynamic memory to release
}

// Return product ID
int Product::getProductId() const {
    return productId;
}

// Return product name
string Product::getName() const {
    return name;
}

// Return product price
double Product::getPrice() const {
    return price;
}

// Return available stock
int Product::getStock() const {
    return stock;
}

// Reduce stock after a purchase
void Product::reduceStock(int quantity) {
    if (quantity > 0 && quantity <= stock) {
        stock = stock - quantity;
    }
}

// Display product details
void Product::display() const {
    cout << "Product ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Price: Rs. " << price << endl;
    cout << "Stock: " << stock << endl;
}

// Check product availability
bool Product::isAvailable(int quantity) const {
    return quantity > 0 && quantity <= stock;
}
