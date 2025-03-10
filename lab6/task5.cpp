#include <iostream>

using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float accBalance) {
        accountNumber = accNum;
        balance = accBalance;
    }

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float accBalance, float rate)
        : Account(accNum, accBalance) {
        interestRate = rate;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float accBalance, float limit)
        : Account(accNum, accBalance) {
        overdraftLimit = limit;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    int accNumber;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Details:\n";
    cout << "Account Number: ";
    cin >> accNumber;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate (%): ";
    cin >> interestRate;
    SavingsAccount savings(accNumber, balance, interestRate);

    cout << "\nEnter Checking Account Details:\n";
    cout << "Account Number: ";
    cin >> accNumber;
    cout << "Balance: ";
    cin >> balance;
    cout << "Overdraft Limit: ";
    cin >> overdraftLimit;
    CheckingAccount checking(accNumber, balance, overdraftLimit);

    cout << "\nSavings Account Details:\n";
    savings.displayDetails();

    cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}

