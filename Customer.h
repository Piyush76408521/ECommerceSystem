#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

// Customer class
class Customer {
private:
    int customerId;
    string name;
    string email;
    Cart cart;

public:
    // Constructor
    Customer(int id, string n, string e);

    // Get customer ID
    int getCustomerId() const;

    // Get customer name
    string getName() const;

    // Get customer email
    string getEmail() const;

    // Access customer's cart
    Cart& getCart();

    // Display customer details
    void displayCustomer() const;
};

#endif
