#include <iostream>
using namespace std;

class Manager;

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account &from, Account &to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber
             << ", Balance: $" << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " to Account " << acc.accountNumber << endl;
        }
    }

    void withdraw(Account& acc, double amount) {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrew $" << amount << " from Account " << acc.accountNumber << endl;
        } else {
            cout << "Insufficient funds in Account " << acc.accountNumber << endl;
        }
    }
};

void transferFunds(Account &from, Account &to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed: Insufficient funds in Account " << from.accountNumber << endl;
    }
}

int main() {
    Account acc1(1001, 500.0);
    Account acc2(1002, 300.0);
    Manager manager;

    cout << "--- Initial Account States ---" << endl;
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    cout << "\n--- Performing Transactions ---" << endl;
    manager.deposit(acc1, 200.0);
    manager.withdraw(acc2, 100.0);
    transferFunds(acc1, acc2, 250.0);

    cout << "\n--- Final Account States ---" << endl;
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    return 0;
}
