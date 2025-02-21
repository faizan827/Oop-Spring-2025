void rentCar(int days) {
        if (!isAvailable) {
            cout << "Car is already rented and unavailable.\n";
            return;
        }

        double rentalCost = rentalPrice * days;
        this->totalRevenue += rentalCost;
        isAvailable = false;

        cout << "Car rented successfully for " << days << " days.\n";
        cout << "Total rental cost: $" << rentalCost << "\n";
    }

    void displayCarInfo()  {
       cout << "Brand: " << brand << "\nModel: " << model
                  << "\nRental Price per day: $" << rentalPrice
                  << "\nAvailability: " << (isAvailable ? "Available" : "Rented")
                  << "\nTotal Revenue: $" << totalRevenue << "\n";
    }
};
