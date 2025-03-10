#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string vBrand, int vSpeed) {
        brand = vBrand;
        speed = vSpeed;
    }

    virtual void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string cBrand, int cSpeed, int cSeats)
        : Vehicle(cBrand, cSpeed) {
        seats = cSeats;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string eBrand, int eSpeed, int eSeats, int eBatteryLife)
        : Car(eBrand, eSpeed, eSeats) {
        batteryLife = eBatteryLife;
    }

    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter Electric Car Brand: ";
    getline(cin, brand);
    cout << "Enter Speed (km/h): ";
    cin >> speed;
    cout << "Enter Number of Seats: ";
    cin >> seats;
    cout << "Enter Battery Life (hours): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);

    cout << "\nElectric Car Details:\n";
    eCar.displayDetails();

    return 0;
}

