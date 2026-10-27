#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Customer.h"
using namespace std;

// Order class
class Order {
private:
    int orderId;
    int customerId;
    string customerName;
    vector<CartItem> orderedItems;
    double subtotal;
    double discount;
    double finalTotal;
    string status;

public:
    // Constructor
    Order(int id, const Customer& customer);

    // Create order from customer's cart
    bool createOrder(Customer& customer);

    // Calculate discount
    double calculateDiscount(double amount) const;

    // Display invoice
    void displayInvoice() const;

    // Save order to file
    void saveToFile() const;

    // Get final total
    double getFinalTotal() const;

    // Get order status
    string getStatus() const;
};

#endif
