#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string pName, int pAge) {
        name = pName;
        age = pAge;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string tName, int tAge, string tSubject)
        : Person(tName, tAge) {
        subject = tSubject;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string rName, int rAge, string rResearchArea)
        : Person(rName, rAge) {
        researchArea = rResearchArea;
    }

    void displayDetails() override {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string pName, int pAge, string pSubject, string pResearchArea, int pPublications)
        : Person(pName, pAge), Teacher(pName, pAge, pSubject), Researcher(pName, pAge, pResearchArea) {
        publications = pPublications;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter Professor's Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Research Area: ";
    getline(cin, researchArea);
    cout << "Enter Number of Publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);

    cout << "\nProfessor Details:\n";
    prof.displayDetails();

    return 0;
}


