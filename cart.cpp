#include "Cart.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Add a product to the cart
void Cart::addProduct(Product* product, int quantity)
{
    // Exception handling for invalid product
    if (product == nullptr)
    {
        throw invalid_argument("Invalid product!");
    }

    // Exception handling for invalid quantity
    if (quantity <= 0)
    {
        throw invalid_argument(
            "Quantity must be greater than zero!");
    }

    // Check product stock
    if (!product->isAvailable(quantity))
    {
        throw runtime_error(
            "Requested quantity is not available in stock!");
    }

    // Check if product already exists in cart
    for (auto& item : items)
    {
        if (item.product->getProductId() ==
            product->getProductId())
        {
            int newQuantity = item.quantity + quantity;

            if (!product->isAvailable(newQuantity))
            {
                throw runtime_error(
                    "Total quantity exceeds available stock!");
            }

            item.quantity = newQuantity;

            cout << "Product quantity updated in cart!\n";
            return;
        }
    }

    // Add a new product to the cart
    CartItem newItem;
    newItem.product = product;
    newItem.quantity = quantity;

    items.push_back(newItem);

    cout << "Product added to cart!\n";
}

// Remove a product from the cart
void Cart::removeProduct(int productId)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->product->getProductId() == productId)
        {
            items.erase(it);

            cout << "Product removed from cart!\n";
            return;
        }
    }

    cout << "Product not found in cart!\n";
}

// Display cart items
void Cart::displayCart() const
{
    if (items.empty())
    {
        cout << "Cart is empty!\n";
        return;
    }

    cout << "\n----- CART -----\n";

    for (const auto& item : items)
    {
        double subtotal =
            item.product->getPrice() * item.quantity;

        cout << "Product ID: "
             << item.product->getProductId() << endl;

        cout << "Name: "
             << item.product->getName() << endl;

        cout << "Price: Rs. "
             << item.product->getPrice() << endl;

        cout << "Quantity: "
             << item.quantity << endl;

        cout << "Subtotal: Rs. "
             << subtotal << endl;

        cout << "----------------\n";
    }

    cout << "Total: Rs. "
         << calculateTotal() << endl;
}

// Calculate total cart value
double Cart::calculateTotal() const
{
    double total = 0;

    for (const auto& item : items)
    {
        total += item.product->getPrice() * item.quantity;
    }

    return total;
}

// Get cart items
const vector<CartItem>& Cart::getItems() const
{
    return items;
}

// Clear cart
void Cart::clearCart()
{
    items.clear();

    cout << "Cart cleared!\n";
}
