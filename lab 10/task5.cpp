#include <iostream>
#include <exception>

// Custom exceptions inheriting from std::exception
class NegativeStockException : public std::exception {
    // No override of what()
};

class OverCapacityException : public std::exception {
    // No override of what()
};

// Template class
template<typename T>
class InventoryItem {
    T stock;
    T maxCapacity;
public:
    InventoryItem(T maxCap) : stock(0), maxCapacity(maxCap) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxCapacity) {
            throw OverCapacityException();
        }
        stock = newStock;
    }
};

// Main function to test the implementation
int main() {
    InventoryItem<int> item(100);

    try {
        std::cout << "Attempting to set stock to -5..." << std::endl;
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        std::cout << "Caught NegativeStockException - what(): " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to set stock to 120 (max 100)..." << std::endl;
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        std::cout << "Caught OverCapacityException - what(): " << e.what() << std::endl;
    }

    return 0;
}
