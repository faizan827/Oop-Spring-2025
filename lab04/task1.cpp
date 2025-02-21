#include <iostream>
#include <string>

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;

public:
    
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true) {}

    
    void updateCarDetails(string ;newBrand, string ;newModel, double newRentalPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newRentalPrice;
    }

   
    bool checkAvailability()  {
        return isAvailable;
    }

    
    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Car rented successfully.\n";
        } else {
            cout << "Car is already rented.\n";
        }
    }


    void displayCarInfo() {
        std::cout << "Brand: " << brand << "\nModel: " << model
                  << "\nRental Price: $" << rentalPrice
                  << "\nAvailability: " << (isAvailable ? "Available" : "Rented") << "\n";
    }
};

int main() {
    Car car1;
    car1.displayCarInfo();

    
    car1.updateCarDetails("Toyota", "Corolla", 50.0);
    car1.displayCarInfo();

    
    car1.rentCar();
    car1.rentCar(); 

    return 0;
}

