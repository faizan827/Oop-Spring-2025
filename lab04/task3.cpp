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

    
    Car(string carBrand, string carModel, double price, bool available)
        : brand(carBrand), model(carModel), rentalPrice(price), isAvailable(available) {}

   
    Car(Car other)
         brand(other.brand), model(other.model), rentalPrice(other.rentalPrice), isAvailable(other.isAvailable) {
        std::cout << "Car copied successfully!\n";
    }

   
    Car() {
        cout << "Car object [" << brand << " " << model << "] is being deleted.\n";
    }

    
    void updateCarDetails(string; newBrand,  string; newModel, double newRentalPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newRentalPrice;
    }

    
    void displayCarInfo() {
        cout << "Brand: " << brand << "\nModel: " << model
                  << "\nRental Price per day: $" << rentalPrice
                  << "\nAvailability: " << (isAvailable ? "Available" : "Rented") << "\n";
    }
};

int main() {
    
    Car car1("Toyota", "Corolla", 50.0, true);
    cout << "Original Car Details:\n";
    car1.displayCarInfo();

    
    Car car2 = car1;
    scout << "\nCopied Car Details:\n";
    car2.displayCarInfo();

    
    car1.updateCarDetails("Honda", "Civic", 60.0);
    cout << "\nAfter Modifying Original Car:\n";
    car1.displayCarInfo();

    
    cout << "\nCopied Car After Modification of Original:\n";
    car2.displayCarInfo();

    return 0;
}

}

