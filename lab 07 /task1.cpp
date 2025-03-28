#include <iostream>
using namespace std;

class Device {
public:
    int deviceID;
    string deviceName;
    bool status;
    void turnOn() { status = true; }
    void turnOff() { status = false; }
    bool getStatus() { return status; }
    virtual void displayInfo() {}
};

class Light : public Device {
public:
    int brightnessLevel;
    string colorMode;
    void displayInfo() {
        cout << "Light - Brightness: " << brightnessLevel << ", Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
public:
    float temperature;
    string mode;
    float targetTemperature;
    bool getStatus() { return temperature; }
};

class SecurityCamera : public Device {
public:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
    void turnOn() { recordingStatus = true; }
};

class SmartPlug : public Device {
public:
    float powerConsumption;
    int timerSetting;
    void turnOff() { status = false; cout << "Logging power usage." << endl; }
};

int main() {
    Light light;
    light.deviceID = 1;
    light.deviceName = "Living Room Light";
    light.brightnessLevel = 75;
    light.colorMode = "Warm White";
    light.displayInfo();

    Thermostat thermostat;
    thermostat.deviceID = 2;
    thermostat.deviceName = "Home Thermostat";
    thermostat.temperature = 22.5;
    thermostat.mode = "Cooling";
    thermostat.targetTemperature = 24.0;
    cout << "Thermostat Temperature: " << thermostat.getStatus() << endl;

    SecurityCamera camera;
    camera.deviceID = 3;
    camera.deviceName = "Front Door Camera";
    camera.resolution = 1080;
    camera.nightVisionEnabled = true;
    camera.turnOn();
    cout << "Camera Recording: " << camera.recordingStatus << endl;

    SmartPlug plug;
    plug.deviceID = 4;
    plug.deviceName = "Kitchen Plug";
    plug.powerConsumption = 150.5;
    plug.timerSetting = 60;
    plug.turnOff();
    
    return 0;
}

