#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Product class definition
class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor to initialize the product
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    // Function to update the quantity of the product
    void updateQuantity(int q) {
        quantity += q;  // Increment quantity
    }

    // Function to display the product details
    void displayProduct() const {
        cout << "\nName: " << name << ", \nPrice: $" << price << ", \nQuantity in stock: " << quantity << endl;
    }

    // Getter for product name to search products
    string getName() const {
        return name;
    }
};

// Inventory management system
class Inventory {
private:
    vector<Product> products;  // A list of products

public:
    // Function to add a new product
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Function to update the quantity of an existing product
    void updateProductStock(const string& name, int quantity) {
        for (auto& product : products) {
            if (product.getName() == name) {
                product.updateQuantity(quantity);
                cout << "Product stock updated successfully." << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    // Function to generate a report of all available products
    void generateReport() const {
        if (products.empty()) {
            cout << "No products available." << endl;
        } else {
            cout << "\nInventory Report:\n";
            for (const auto& product : products) {
                product.displayProduct();
            }
        }
    }
};

// Main function to test the Inventory system
int main() {
    Inventory inventory;
    int choice;

    while (true) {
        // Menu for the inventory system
        cout << "\nInventory Management System\n";
        cout << "1. Add new product\n";
        cout << "2. Update product stock\n";
        cout << "3. Generate inventory report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Adding a new product
            string name;
            double price;
            int quantity;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;

            Product newProduct(name, price, quantity);
            inventory.addProduct(newProduct);
            cout << "Product added successfully." << endl;

        } else if (choice == 2) {
            // Updating product stock
            string name;
            int quantity;
            cout << "Enter product name to update: ";
            cin >> name;
            cout << "Enter quantity to add/remove: ";
            cin >> quantity;

            inventory.updateProductStock(name, quantity);

        } else if (choice == 3) {
            // Generating a report of all products
            inventory.generateReport();

        } else if (choice == 4) {
            // Exiting the system
            cout << "Exiting system..." << endl;
            break;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
