#include "../include/Order.h"

// Constructor definition
Order::Order(int id, const Customer& customer) {

    orderId = id;
    customerId = customer.getCustomerId();
    customerName = customer.getName();

    subtotal = 0;
    discount = 0;
    finalTotal = 0;

    status = "Pending";
}

// Calculate discount based on total amount
double Order::calculateDiscount(double amount) const {

    if (amount >= 5000) {
        return amount * 0.10; // 10% discount
    }
    else if (amount >= 2000) {
        return amount * 0.05; // 5% discount
    }

    return 0;
}

// Create order from customer's cart
bool Order::createOrder(Customer& customer) {

    const vector<CartItem>& cartItems = customer.getCart().getItems();

    if (cartItems.empty()) {
        cout << "Cart is empty!" << endl;
        return false;
    }

    // Check stock for every product before placing order
    for (const CartItem& item : cartItems) {

        if (!item.product->isAvailable(item.quantity)) {
            cout << "Insufficient stock for: "
                 << item.product->getName() << endl;

            return false;
        }
    }

    // Store cart items in the order
    orderedItems = cartItems;

    // Calculate subtotal
    subtotal = 0;

    for (const CartItem& item : orderedItems) {

        subtotal += item.product->getPrice()
                   * item.quantity;
    }

    // Calculate discount
    discount = calculateDiscount(subtotal);

    // Calculate final total
    finalTotal = subtotal - discount;

    // Reduce stock after successful validation
    for (const CartItem& item : orderedItems) {

        item.product->reduceStock(item.quantity);
    }

    // Mark order as confirmed
    status = "Confirmed";

    // Clear customer's cart
    customer.getCart().clearCart();

    cout << "Order created successfully!" << endl;

    return true;
}

// Display invoice
void Order::displayInvoice() const {

    cout << "\n========== INVOICE ==========" << endl;

    cout << "Order ID: " << orderId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;

    cout << "\n----- ORDER ITEMS -----" << endl;

    for (const CartItem& item : orderedItems) {

        cout << "Product: "
             << item.product->getName() << endl;

        cout << "Quantity: "
             << item.quantity << endl;

        cout << "Price: Rs. "
             << item.product->getPrice() << endl;

        cout << "------------------------" << endl;
    }

    cout << "Subtotal: Rs. " << subtotal << endl;
    cout << "Discount: Rs. " << discount << endl;
    cout << "Final Total: Rs. " << finalTotal << endl;
    cout << "Status: " << status << endl;

    cout << "==============================\n" << endl;
}

// Save order information to file
void Order::saveToFile() const {

    ofstream file("data/orders.txt", ios::app);

    if (!file) {
        cout << "Error opening orders file!" << endl;
        return;
    }

    file << "Order ID: " << orderId << endl;
    file << "Customer ID: " << customerId << endl;
    file << "Customer Name: " << customerName << endl;
    file << "Subtotal: " << subtotal << endl;
    file << "Discount: " << discount << endl;
    file << "Final Total: " << finalTotal << endl;
    file << "Status: " << status << endl;
    file << "--------------------------" << endl;

    file.close();

    cout << "Order saved successfully!" << endl;
}

// Return final total
double Order::getFinalTotal() const {
    return finalTotal;
}

// Return order status
string Order::getStatus() const {
    return status;
}
