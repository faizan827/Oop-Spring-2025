#include <iostream>
using namespace std;

class Product {
public:
    int productID;
    string productName;
    float price;
    int stockQuantity;
    float applyDiscount() { return price * 0.9; }
    float calculateTotalPrice(int quantity) { return price * quantity; }
    virtual void displayProductInfo() {}
};

class Electronics : public Product {
public:
    int warrantyPeriod;
    string brand;
    void displayProductInfo() {
        cout << "Electronics - Brand: " << brand << ", Warranty: " << warrantyPeriod << " years" << endl;
    }
};

class Clothing : public Product {
public:
    string size;
    string color;
    string fabricMaterial;
    float applyDiscount() { return price * 0.8; }
};

class FoodItem : public Product {
public:
    string expirationDate;
    int calories;
    float calculateTotalPrice(int quantity) { return (price * quantity) * 0.95; }
};

class Book : public Product {
public:
    string author;
    string genre;
    void displayProductInfo() {
        cout << "Book - Author: " << author << ", Genre: " << genre << endl;
    }
};
