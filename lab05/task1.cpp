#include<iostream>
using namespace std;

class Apartment {
private:
    int apartmentID;
    string address;
    string* OwnerName;

public:
    Apartment(int id, string address, string name)
        : apartmentID(id), address(address), OwnerName(new string(name)) {}

    Apartment(Apartment& other) {
        apartmentID = other.apartmentID;
        address = other.address;
        OwnerName = new string(*(other.OwnerName));
    }

    void displayDetails() const {
        cout << "Apartment ID: " << apartmentID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner's Name: " << *OwnerName << endl;
    }

    ~Apartment() {
        delete OwnerName;
    } //to delete the dynamic variable
};

int main() {

    Apartment SaimaClassic(538, "Johar, Karachi", "Jahanzaib");
    SaimaClassic.displayDetails();

    Apartment SaimaClassiclite(SaimaClassic);
    cout << "\nCopied Apartment Details: " << endl;
    SaimaClassic.displayDetails();

    return 0;
}
