#include <iostream>
#include <string>

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    float temperature;
public:
    void readData() override {
        temperature = 25.5f;
    }
    void displayReport() override {
        std::cout << "Thermometer Reading: " << temperature << " °C" << std::endl;
    }
};

class Barometer : public WeatherSensor {
private:
    float pressure;
public:
    void readData() override {
        pressure = 1013.25f;
    }
    void displayReport() override {
        std::cout << "Barometer Reading: " << pressure << " hPa" << std::endl;
    }
};

int main() {
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();

    sensor2->readData();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}

