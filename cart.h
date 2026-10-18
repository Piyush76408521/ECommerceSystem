#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

// Structure to store a product and its quantity
struct CartItem {
    Product* product;
    int quantity;
};

// Cart class
class Cart {
private:
    vector<CartItem> items;

public:
    // Add a product to cart
    void addProduct(Product* product, int quantity);

    // Remove a product from cart
    void removeProduct(int productId);

    // Display all cart items
    void displayCart() const;

    // Calculate total price
    double calculateTotal() const;

    // Get cart items
    const vector<CartItem>& getItems() const;

    // Clear cart
    void clearCart();
};

#endif
