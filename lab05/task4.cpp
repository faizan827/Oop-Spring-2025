#include<iostream>
using namespace std;

class AlarmSystem {
private:
    string SecurityLevel;

public:
    AlarmSystem(string level) : SecurityLevel(level) {}

    void updateSecurityLevel(string level) {
        SecurityLevel = level;
    }

    string getSecurityLevel() const {
        return SecurityLevel;
    }
};

class SmartHome {
private:
    int HomeId;
    string Homelocation;
    AlarmSystem Alarmtype;

public:
    SmartHome(int id, string location, string level)
        : HomeId(id), Homelocation(location), Alarmtype(level) {}

    void showDetails() const {
        cout << "Smart Home ID: " << HomeId << endl;
        cout << "Location: " << Homelocation << endl;
        cout << "Alarm System Details:\n";
        cout << "Security Level: " << Alarmtype.getSecurityLevel() << endl;
    }
};

int main() {
    SmartHome newGFCprojcet(420, "New Karachi", "High");
    newGFCprojcet.showDetails();
    return 0;
}
