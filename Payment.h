
#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Payment {
protected:
    double amount;

public:
    // Constructor
    Payment(double amt);

    // Virtual destructor
    virtual ~Payment();

    // Pure virtual function
    virtual bool pay() = 0;
};

// UPI payment class
class UPI : public Payment {
private:
    string upiId;

public:
    // Constructor
    UPI(double amt, string id);

    // Override payment function
    bool pay() override;
};

// Card payment class
class Card : public Payment {
private:
    string cardNumber;

public:
    // Constructor
    Card(double amt, string number);

    // Override payment function
    bool pay() override;
};

#endif
