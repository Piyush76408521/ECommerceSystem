#include <iostream>
#include <vector>
#include <memory>

#include "Product.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Customer.h"
#include "Order.h"
#include "Payment.h"

using namespace std;

// Display all available products
void displayProducts(const vector<unique_ptr<Product>>& products)
{
    cout << "\n========== AVAILABLE PRODUCTS ==========\n";

    for (const auto& product : products)
    {
        product->display();
        cout << "----------------------------------------\n";
    }
}

int main()
{
    // Creating products
    vector<unique_ptr<Product>> products;

    products.push_back(make_unique<Electronics>(
        101, "Laptop", 60000, 5, 24));

    products.push_back(make_unique<Electronics>(
        102, "Headphones", 2000, 10, 12));

    products.push_back(make_unique<Clothing>(
        103, "T-Shirt", 800, 15, "M"));

    products.push_back(make_unique<Electronics>(
        104, "Smartphone", 25000, 8, 12));

    products.push_back(make_unique<Clothing>(
        105, "Jeans", 1500, 12, "L"));

    // Creating a customer
    Customer customer(1, "Piyush", "piyush@gmail.com");

    int choice;
    int nextOrderId = 1001;

    unique_ptr<Order> lastOrder = nullptr;

    do
    {
        cout << "\n========== E-COMMERCE SYSTEM ==========\n";
        cout << "1. Display Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Remove Product from Cart\n";
        cout << "4. Display Cart\n";
        cout << "5. Place Order\n";
        cout << "6. Make Payment\n";
        cout << "7. Display Customer Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                displayProducts(products);
                break;
            }
            
case 2:
{
    int productId;
    int quantity;

    cout << "Enter Product ID: ";
    cin >> productId;

    cout << "Enter Quantity: ";
    cin >> quantity;

    try
    {
        Product* selectedProduct = nullptr;

        for (const auto& product : products)
        {
            if (product->getProductId() == productId)
            {
                selectedProduct = product.get();
                break;
            }
        }

        if (selectedProduct == nullptr)
        {
            throw invalid_argument("Product not found!");
        }

        customer.getCart().addProduct(
            selectedProduct, quantity);
    }
    catch (const exception& error)
    {
        cout << "Error: " << error.what() << endl;
    }

    break;
}

            case 3:
            {
                int productId;

                cout << "Enter Product ID to remove: ";
                cin >> productId;

                customer.getCart().removeProduct(productId);

                break;
            }

            case 4:
            {
                customer.getCart().displayCart();
                break;
            }

            case 5:
            {
                lastOrder = make_unique<Order>(
                    nextOrderId++, customer);

                if (lastOrder->createOrder(customer))
                {
                    lastOrder->saveToFile();
                    cout << "Order placed successfully!\n";
                }
                else
                {
                    lastOrder = nullptr;
                }

                break;
            }

            case 6:
            {
                if (lastOrder == nullptr)
                {
                    cout << "Please place an order first!\n";
                    break;
                }

                double amount = lastOrder->getFinalTotal();

                int paymentChoice;

                cout << "\n========== PAYMENT ==========\n";
                cout << "1. UPI Payment\n";
                cout << "2. Card Payment\n";
                cout << "Enter payment method: ";
                cin >> paymentChoice;

                if (paymentChoice == 1)
                {
                    string upiId;

                    cout << "Enter UPI ID: ";
                    cin >> upiId;

                    UPI payment(amount, upiId);
                    payment.pay();
                }
                else if (paymentChoice == 2)
                {
                    string cardNumber;

                    cout << "Enter Card Number: ";
                    cin >> cardNumber;

                    Card payment(amount, cardNumber);
                    payment.pay();
                }
                else
                {
                    cout << "Invalid payment method!\n";
                }

                break;
            }

            case 7:
            {
                customer.displayCustomer();
                break;
            }

            case 0:
            {
                cout << "Thank you for using the E-Commerce System!\n";
                break;
            }

            default:
            {
                cout << "Invalid choice! Try again.\n";
            }
        }

    } while (choice != 0);

    return 0;
}
