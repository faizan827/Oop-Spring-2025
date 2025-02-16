#include<iostream>
#include<string>
using namespace std;

class Library {
private:
    struct Book {
        string title;
        string author;
        int pages;
    };
    int totalAvailable;
    int totalBorrowed;
    int Index;
    string transactionLog[500];

public:
    Book collection[100];
    Library() {
        totalAvailable = 3;
        totalBorrowed = 0;
        Index = 3;
        collection[0] = {"Diary of a Wimpy Kid", "Dave", 198};
        collection[1] = {"History of Pakistan", "Hussain", 315};
        collection[2] = {"Atomic Habits", "James", 259};
        transactionLog[logIndex] = "Library initialized with three books.";
    }

    void addBooks(int num) {
        num += Index;
        for (int i = Index++; i < num; i++) {
            
            cout << "Enter title of book " << i << ": ";
            getline(cin, collection[i].title);
            cout << "Enter author of book " << i << ": ";
            getline(cin, collection[i].author);
            cout << "Enter number of pages in book " << i << ": ";
            cin >> collection[i].pages;
            totalAvailable++;
            cout << "Book added successfully." << endl;
        }
        Index++;
        transactionLog[Index] = to_string(num) + " books added to the library.";
    }

    void lendBook() {
        string bookTitle;
        cout << "Enter book title to borrow: ";
        cin.ignore();
        getline(cin, bookTitle);
        if (totalAvailable > 0) {
            for (int i = 0; i < totalAvailable; i++) {
                if (bookTitle == collection[i].title) {
                    cout << "You have borrowed: " << bookTitle << ". Please return it on time." << endl;
                    totalBorrowed++;
                    Index++;
                    transactionLog[Index] = "Book borrowed: " + bookTitle;
                    return;
                }
            }
            Index++;
            transactionLog[Index] = "Failed attempt to borrow book: " + bookTitle;
            cout << "Book not available!" << endl;
        } else {
            cout << "No books currently in the library." << endl;
        }
    }

    void returnBook() {
        if (totalBorrowed == 0) {
            cout << "No books to return." << endl;
        } else {
            string bookTitle;
            cout << "Enter book title to return: ";
            cin.ignore();
            getline(cin, bookTitle);
            totalBorrowed--;
            cout << "Book returned successfully." << endl;
            logIndex++;
            transactionLog[Index] = "Book returned: " + bookTitle;
        }
    }

    void showInventoryHistory() {
        cout << "Library Transaction History:" << endl;
        for (int i = 0; i <= Index; i++) {
            cout << transactionLog[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Library myLibrary;
    int choice, numBooks;
    
    while (true) {
        cout << "1. Add books." << endl;
        cout << "2. Borrow a book." << endl;
        cout << "3. Return a book." << endl;
        cout << "4. View  history." << endl;
        cout << "Select an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter number of books to add: ";
                cin >> numBooks;
                myLibrary.addBooks(numBooks);
                break;
            case 2:
                myLibrary.lendBook();
                break;
            case 3:
                myLibrary.returnBook();
                break;
            case 4:
                myLibrary.showInventoryHistory();
                break;
            default:
                cout << "Invalid selection." << endl;
                break;
        }
    }
    return 0;
}
