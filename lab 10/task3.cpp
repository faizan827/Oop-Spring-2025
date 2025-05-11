#include <iostream>
#include <stdexcept>

// Custom exception class
class InvalidTemperatureException : public std::exception {};

// Template function to convert Celsius to Fahrenheit
template <typename T>
T convertToFahrenheit(T celsius) {
    const double ABSOLUTE_ZERO = -273.15;
    if (celsius < ABSOLUTE_ZERO) {
        throw InvalidTemperatureException();
    }
    return static_cast<T>((celsius * 9.0 / 5.0) + 32);
}

int main() {
    try {
        double temp = -300.0;
        std::cout << "Attempting to convert " << temp << "C...\n";
        double fahrenheit = convertToFahrenheit(temp);
        std::cout << "Converted to " << fahrenheit << "F\n";
    } catch (const InvalidTemperatureException& e) {
        std::cout << "Caught InvalidTemperatureException - what(): " << e.what() << '\n';
    }

    return 0;
}
