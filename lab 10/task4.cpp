#include <iostream>
#include <exception>
#include <string>

// Base class
class DatabaseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

// Derived classes
class ConnectionFailedException : public DatabaseException {
    // Inherits what() without overriding
};

class QueryTimeoutException : public DatabaseException {
    // Inherits what() without overriding
};

// Template class
template<typename T>
class DatabaseConnector {
public:
    void connect(const std::string& dbName) {
        std::cout << "Attempting to connect to " << dbName << "..." << std::endl;
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        }
        std::cout << "Connected to " << dbName << " successfully." << std::endl;
    }
};

// Test program
int main() {
    DatabaseConnector<int> connector;

    try {
        connector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException - what(): " << e.what() << std::endl;
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << std::endl;
    }

    try {
        connector.connect("slow_db");
    } catch (const QueryTimeoutException& e) {
        std::cout << "Caught QueryTimeoutException - what(): " << e.what() << std::endl;
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << std::endl;
    }

    return 0;
}

