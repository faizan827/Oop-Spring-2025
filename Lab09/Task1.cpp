
#include <iostream>
#include <string>

using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "InPatient Treatment for " << name << " (ID: " << id << "): Surgery and overnight stay" << endl;
    }

    double calculateCost() {
        return 1500.0;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "OutPatient Treatment for " << name << " (ID: " << id << "): Consultation and medication" << endl;
    }

    double calculateCost() {
        return 200.0;
    }
};

int main() {
    Patient* p1 = new InPatient("John Doe", "IP001");
    Patient* p2 = new OutPatient("Jane Smith", "OP002");

    p1->displayTreatment();
    cout << "Cost: $" << p1->calculateCost() << endl;

    p2->displayTreatment();
    cout << "Cost: $" << p2->calculateCost() << endl;

    delete p1;
    delete p2;

    return 0;
}

