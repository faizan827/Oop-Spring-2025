#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
        string model;
        float fuelCapacity;
        float currentFuelLevel;  // Both in liters

    public:
        Car(string Brand, string Model, float capacity, float level) {
            brand = Brand;
            model = Model;
            fuelCapacity = capacity;
            currentFuelLevel = level;
        }

        void Drive(float kilometers) {
            if (kilometers < 0 || (kilometers / 15) >= currentFuelLevel) {
                cout << "Invalid distance entered." << endl;
            } else {
                currentFuelLevel -= (kilometers / 15); // Assuming 15 km per liter
                if (currentFuelLevel < 5) {
                    cout << "Warning: Low fuel! Please refuel soon." << endl;
                }
                cout << "Fuel level updated after driving." << endl;
            }
        }

        void Refuel(float liters) {
            if (liters < 0 || (liters + currentFuelLevel) > fuelCapacity) {
                cout << "Cannot refuel with the specified amount." << endl;
            } else {
                currentFuelLevel += liters;
                cout << liters << " liters added to the tank." << endl;
            }
        }

        void DisplayFuelStatus() {
            cout << "Current fuel level: " << currentFuelLevel << " liters." << endl;
            if (currentFuelLevel < 5) {
                cout << "Warning: Low fuel! Please refuel soon." << endl;
            }
        }
};

int main() {
    int choice;
    string brand, model;
    float currentFuelLevel, fuelCapacity;

    cout << "Enter the brand of your car: ";
    getline(cin, brand);
    cout << "Enter the model of your car: ";
    getline(cin, model);
    cout << "Enter the current fuel level (liters): ";
    cin >> currentFuelLevel;
    cout << "Enter the total fuel tank capacity (liters): ";
    cin >> fuelCapacity;
    Car myCar(brand, model, fuelCapacity, currentFuelLevel);

    while (true) {
        cout << "\n1. Update fuel after driving." << endl;
        cout << "2. Refuel the car." << endl;
        cout << "3. Check current fuel status." << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                float distance;
                cout << "Enter distance driven (km): ";
                cin >> distance;
                myCar.Drive(distance);
                break;
            }
            case 2: {
                float refuelAmount;
                cout << "Enter amount of fuel to add (liters): ";
                cin >> refuelAmount;
                myCar.Refuel(refuelAmount);
                break;
            }
            case 3:
                myCar.DisplayFuelStatus();
                break;
            default:
                cout << "Invalid option selected." << endl;
                break;
        }
    }
    return 0;
}
