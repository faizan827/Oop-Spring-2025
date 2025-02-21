#include <iostream>
#include <string>

class Car {
private:
    string  brand;
    string  model;
    double rentalPrice;
    bool isAvailable;

public:

    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true) {}

    
    Car(string; carBrand, string ; carModel, double price, bool available)
        : brand(carBrand), model(carModel), rentalPrice(price), isAvailable(available) {}

    
    void updateCarDetails(string; newBrand, const std::string& newModel, double newRentalPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newRentalPrice;
    }

    
    bool checkAvailability()  {
        return isAvailable;
    }

    
    void rentCar(int days) {
        if (!isAvailable) {
            std::cout << "Car is already rented and unavailable.\n";
            return;
        }

        double finalPrice = applyDiscount(days);
        isAvailable = false;
        std::cout << "Car rented successfully for " << days << " days.\n";
        std::cout << "Total rental cost after discount: $" << finalPrice << "\n";
    }

   
    double applyDiscount(int days) const {
        double discount = 0.0;
        if (days > 10) {
            discount = 0.10;  
        } else if (days > 5) {
            discount = 0.05;  
        }
        return rentalPrice * days * (1 - discount);
    }

    
    void displayCarInfo()  {
        std::cout << "Brand: " << brand << "\nModel: " << model
                  << "\nRental Price per day: $" << rentalPrice
                  << "\nAvailability: " << (isAvailable ? "Available" : "Rented") << "\n";
    }
};

int main() {
    Car car1("Toyota", "Corolla", 50.0, true);
    car1.displayCarInfo();

   
    car1.rentCar(6);
    car1.rentCar(3);

    return 0;
}

