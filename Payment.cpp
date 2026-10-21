
#include "../include/Payment.h"

// Payment constructor
Payment::Payment(double amt) {
    amount = amt;
}

// Payment destructor
Payment::~Payment() {
    // No dynamic memory to release
}

// UPI constructor
UPI::UPI(double amt, string id)
    : Payment(amt) {

    upiId = id;
}

// Process UPI payment
bool UPI::pay() {

    if (upiId.empty()) {
        cout << "Invalid UPI ID!" << endl;
        return false;
    }

    cout << "UPI payment successful!" << endl;
    cout << "Amount paid: Rs. " << amount << endl;

    return true;
}

// Card constructor
Card::Card(double amt, string number)
    : Payment(amt) {

    cardNumber = number;
}

// Process card payment
bool Card::pay() {

    if (cardNumber.empty()) {
        cout << "Invalid card number!" << endl;
        return false;
    }

    cout << "Card payment successful!" << endl;
    cout << "Amount paid: Rs. " << amount << endl;

    return true;
}
