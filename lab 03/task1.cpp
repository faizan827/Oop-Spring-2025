#include<iostream>
#include<string>
using namespace std;

class Wallet {
    private:
     string OwnerName;
     int TotalAmount;
     string transactionhistory[999];
     int count; 

    public:
    Wallet() {
        OwnerName = "Saad";
        TotalAmount = 20000;
        count = 0;
        transactionhistory[count] = " balance of PKR " + to_string(TotalAmount);  
    }

    void setTotalAmount(int bal) {
        TotalAmount = bal;
    }
    string getOwnerName() {
        return OwnerName;
    }
    int getbalance() {
        return TotalAmount;
    }
    

    void Depositmoney(int money) {
        if (money > 0) {
            TotalAmount = TotalAmount + money;
            count++;
            transactionhistory[count] = "Amount deposited: " + to_string(money) + " PKR, New Balance: " + to_string(TotalAmount);
            cout << "Amount added " << endl;
        } else {
            cout << " please enter amount again" << endl;
        }
    }

    void SpendMoney(int money) {
        if (money > 0 && money <= TotalAmount) {
            TotalAmount = TotalAmount - money;
            count++;
            transactionhistory[count] = "Amount withdrawn: " + to_string(money) + " PKR, New Balance: " + to_string(TotalAmount);
            cout << "Amount withdrawn" << endl;
            if (TotalAmount < 500) {
                cout << "Warning! YOU HAVE LOW BALANCE!" << endl;
            }
        } else {
            cout << "You have insufficient balance!" << endl;
        }
    }

    void displayhistory() {
        cout << "\nTransaction History for " << OwnerName << ":" << endl;
        for (int i=0;i<=count;i++) {
            cout << i+1 << " " << transactionhistory[i] << endl;
        }
    }
};

int main() {
    Wallet Saad_wallet;
    int opt, money;
     
while(1) {
    cout << "1. Add more money ." << endl;
    cout << "2. Spend money. " << endl;
    cout << "3. check transaction history. " << endl;
    cout << "Choose from one of the above: " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter  amount: ";
    cin >> money;
    Saad_wallet.Depositmoney(money);
    break;
    case 2:
    cout << "Enter amount: ";
    cin >> money;
    Saad_wallet.SpendMoney(money);
    break;
    case 3:
    Saad_wallet.displayhistory();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
        }
    return 0;
}
