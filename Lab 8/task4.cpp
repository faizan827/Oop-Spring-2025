#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice);
    void displayCarDetails(const Car& car);
};

class Car {
private:
    string model;
    double price;
public:
    Car(string m, double p) : model(m), price(p) {}
    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
}

void InventoryManager::displayCarDetails(const Car& car) {
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c1.price < c2.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars are priced equally." << endl;
}

int main() {
    Car car1("Sedan", 20000);
    Car car2("SUV", 25000);

    InventoryManager manager;
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    comparePrice(car1, car2);

    manager.updatePrice(car1, 26000);
    manager.displayCarDetails(car1);

    comparePrice(car1, car2);

    return 0;
}

