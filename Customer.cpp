#include "../include/Customer.h"

// Constructor definition
Customer::Customer(int id, string n, string e)
    : customerId(id), name(n), email(e) {
}

// Return customer ID
int Customer::getCustomerId() const {
    return customerId;
}

// Return customer name
string Customer::getName() const {
    return name;
}

// Return customer email
string Customer::getEmail() const {
    return email;
}

// Return reference to customer's cart
Cart& Customer::getCart() {
    return cart;
}

// Display customer details
void Customer::displayCustomer() const {
    cout << "Customer ID: " << customerId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
}
