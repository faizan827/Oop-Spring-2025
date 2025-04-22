#include <iostream>
#include <string>

using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double cost) : dishName(name), price(cost) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() {
        cout << "Appetizer: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() {
        cout << "Preparing " << dishName << ": Chopping and mixing ingredients." << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() {
        cout << "Main Course: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() {
        cout << "Preparing " << dishName << ": Cooking on stove and garnishing." << endl;
    }
};

int main() {
    MenuItem* m1 = new Appetizer("Spring Rolls", 5.99);
    MenuItem* m2 = new MainCourse("Grilled Chicken", 12.99);

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    delete m1;
    delete m2;

    return 0;
}
