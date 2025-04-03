#include<iostream>
#include<string>
using namespace std;

class Product {
private:
    int productID;
    string name;
    int quantity;

public:
    Product(int id, string n, int q) : productID(id), name(n), quantity(q) {}

    int getID() const {
        return productID;
    }

    string getName() const {
        return name;
    }

    void displayDetails() const {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class Inventory {
private:
    Product** products;
    int count;

public:
    Inventory() : products(nullptr), count(0) {}

    void addProduct(int id, string name, int quantity) {
        Product** temp = new Product*[count + 1];
        for (int i = 0; i < count; ++i) {
            temp[i] = products[i];
        }
        temp[count] = new Product(id, name, quantity);
        delete[] products;
        products = temp;
        ++count;
    }

    void sortProducts() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (products[i]->getName() > products[j]->getName()) {
                    Product* temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
    }

    void searchProduct(int id) const {
        for (int i = 0; i < count; ++i) {
            if (products[i]->getID() == id) {
                products[i]->displayDetails();
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    ~Inventory() {
        for (int i = 0; i < count; ++i) {
            delete products[i];
        }
        delete[] products;
    }
};

int main() {
    Inventory inventory;
    inventory.addProduct(3, "Chair", 50);
    inventory.addProduct(1, "Table", 30);
    inventory.addProduct(2, "Lamp", 20);

    inventory.sortProducts();
    inventory.searchProduct(1);

    return 0;
}
