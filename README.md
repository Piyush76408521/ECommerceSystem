EcommerceSystem (OOP-06)

 1. About the Project

EcommerceSystem is a console-based e-commerce application developed using C++. It demonstrates how an online shopping system can be represented through object-oriented programming.

The program allows users to view products, add products to a shopping cart, remove products, place orders, and perform payment operations supported by the application.

This project was developed as part of the Object-Oriented Programming Using C++ course at  Sarala Birla University.

 2. Project Objectives

- To understand and implement object-oriented programming concepts in C++.
- To represent products, customers, carts, orders, and payments using classes.
- To demonstrate inheritance and runtime polymorphism.
- To organize a C++ project into header files and implementation files.
- To practice compiling, running, and testing a multi-file C++ application.

3. Features

- Display Products: View the products available in the system.
- Add Products to Cart: Add a product using its product ID.
- Remove Products from Cart: Remove products from the shopping cart.
- Display Cart: View the cart contents and subtotal.
- Place Order: Place an order using the application's order functionality.
- Make Payment:Use the payment functionality provided by the program.
- Display Customer Details: View customer information.
- Menu-Based Interface: Select operations through a console menu.

Note: The application is a student project and does not necessarily include a real online payment gateway, website, or database.

4. Technologies Used

- Programming Language: C++
- C++ Standard: C++17
- Compiler: GCC / g++
- Development Environment: Visual Studio Code
- Version Control:Git and GitHub

5. Project Folder Structure

text
EcommerceSystem/
│
├── main.cpp
│
├── include/
│   ├── Product.h
│   ├── Electronics.h
│   ├── Clothing.h
│   ├── Customer.h
│   ├── Cart.h
│   ├── Order.h
│   └── Payment.h
│
├── src/
│   ├── Product.cpp
│   ├── Electronics.cpp
│   ├── Clothing.cpp
│   ├── Customer.cpp
│   ├── Cart.cpp
│   ├── Order.cpp
│   └── Payment.cpp
│
└── README.md


The `include/` folder contains class declarations and the `src/` folder contains their function implementations. The `main.cpp` file starts the program and provides the main menu.

 6. Object-Oriented Programming Concepts

 6.1 Class and Object

A class is a blueprint that defines the data and functions of a particular type of object. An object is an instance of a class.

For example, `Product` is a class, while a laptop with a particular product ID and price can be represented as a product object.

 6.2 Encapsulation

Encapsulation means combining data and related functions inside a class and controlling access to that data.

For example, the `Product` class keeps details such as the product ID, name, price, and stock private and provides public functions to access or modify them.

 6.3 Inheritance

Inheritance allows one class to reuse or extend the features of another class.

In this project, `Electronics` and `Clothing` are derived from the `Product` base class. They represent different types of products.

6.4 Polymorphism

Polymorphism means that the same function interface can behave differently for different types of objects.

The `Product` class declares a virtual `display()` function. Derived classes can override it to display their specific details, such as an electronic product's warranty or a clothing product's size.

 6.5 Abstraction

Abstraction means showing the necessary operations while hiding unnecessary implementation details.

For example, a user can select an operation such as adding a product to the cart without needing to understand all the internal steps performed by the program.

 6.6 Composition

Composition means that one object contains or uses other objects as parts of a larger system.

The shopping cart, order, customer, and payment components work together to represent different parts of the shopping process, according to their implementation in the project.
7. Requirements

 Hardware Requirements

- A computer or laptop.
- Sufficient memory and storage to run a basic C++ console application.

 Software Requirements

- Windows, Linux, or another supported operating system.
- A C++ compiler that supports C++17.
- GCC / g++ installed and accessible from the terminal.
- A terminal or command prompt.

Visual Studio Code is optional; any suitable editor and terminal can be used.

8. How to Compile and Run

 Step 1: Install a C++ Compiler

Install GCC / g++ and ensure that the compiler is available from your terminal.

Check the installation with:

```bash
g++ --version
```

Step 2: Open the Project Folder

Open a terminal in the main `EcommerceSystem` folder. The folder should contain `main.cpp`, `include/`, and `src/`.

 Step 3: Compile the Program

Run the following command from the project root:

```bash
g++ -std=c++17 main.cpp src/*.cpp -Iinclude -o ecommerce
```

This command compiles `main.cpp` and the implementation files in `src/`, while `-Iinclude` tells the compiler where to find the header files.

 Step 4: Run the Program

On Windows PowerShell:

```powershell
.\ecommerce.exe
```

On Linux or macOS with GCC:

```bash
./ecommerce
```

If compilation fails, check that the folder structure and filenames match the structure shown above and that the compiler is installed correctly.

9. How to Use the Application

1. Run the compiled program.
2. Read the options displayed in the console menu.
3. Select the operation you want to perform.
4. Follow the prompts and enter the required information, such as a product ID or quantity.
5. View the product list or shopping cart to check the results.
6. Place an order or use the payment option if required.
7. Select the exit option when finished.

The exact menu options and behavior depend on the current implementation of the source code.

10. Sample Product Data

The program has been tested with example products such as:

| Product | Example Price |
| Laptop | ₹60,000 |
| Headphones | ₹2,000 |
| T-Shirt | ₹800 |

These are sample values used to demonstrate product display and shopping-cart operations. They are not live store prices.

 11. Testing

The application should be tested using both normal operations and error or boundary cases.

Suggested test cases:

| Test Case | Expected Result |

| Display products | Available products are displayed |
| Add a valid product to the cart | Product is added successfully |
| Display the cart | Cart contents and subtotal are displayed |
| Remove a product | The selected cart item is removed |
| Enter an invalid product ID | An appropriate error is handled |
| Enter a quantity beyond available stock | The application handles the request appropriately |
| Exit the application | The program terminates normally |

Record the actual result of each test before marking it as passed or failed. The expected behavior must also be checked against the features implemented in the source code.

12. Limitations

- The application uses a console-based interface rather than a graphical website.
- It is an educational project, not a complete commercial e-commerce platform.
- Real online payments, delivery tracking, and customer authentication should not be assumed unless explicitly implemented.
- Persistent storage and database functionality should only be claimed if present in the actual source code.
 13. Future Enhancements

Possible improvements include:

- Adding a graphical user interface or web interface.
- Integrating a database for storing products and customer details.
- Adding customer registration and login.
- Improving input validation and error handling.
- Adding order history and invoice generation.
- Integrating a secure payment gateway in a future production-oriented version.

14. Team Members

| Name | SBU ID | Role |
| Yash Kumar Singh | SBU2500181 | Lead / Architecture |
| Piyush Deshmukh | SBU2500403 | Core Developer |
| Shubham Kumar | SBU2500378 | Data / UI / Integration |
| Saurabh Pandey | SBU2500392 | Testing |
| Krish Kumar | SBU2500685 | Documentation |

15. Academic Information

- Institution: Sarala Birla University
- Department: Computer Science and Engineering
- Project Title: EcommerceSystem
- Project Code: OOP-06
- Course: Object-Oriented Programming Using C++
- Academic Year: 2026–2027
- Faculty:Dr. Biswarup Samanta

16. Acknowledgement

We express our sincere gratitude to our faculty, Dr. Biswarup Samanta, for the guidance and support provided during this project.

This project helped us understand the practical application of object-oriented programming concepts, modular code organization, and the development of a multi-file C++ application.
