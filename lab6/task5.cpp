#include <iostream>

using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool stat) {
        deviceID = id;
        status = stat;
    }

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool stat, float screen)
        : Device(id, stat) {
        screenSize = screen;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool monitor)
        : Device(id, stat) {
        heartRateMonitor = monitor;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, float screen, bool monitor, int steps)
        : SmartPhone(id, stat, screen), SmartWatch(id, stat, monitor), Device(id, stat) {
        stepCounter = steps;
    }

    void displayDetails() override {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int id, steps;
    bool status, monitor;
    float screenSize;

    cout << "Enter Smart Wearable Details:\n";
    cout << "Device ID: ";
    cin >> id;
    cout << "Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Yes, 0 for No): ";
    cin >> monitor;
    cout << "Step Counter: ";
    cin >> steps;

    SmartWearable wearable(id, status, screenSize, monitor, steps);

    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}

