#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

class DimensionMismatchException : public std::exception {
private:
    std::string message;
public:
    DimensionMismatchException(int rowsA, int colsA, int rowsB, int colsB) {
        std::ostringstream oss;
        oss << "DimensionMismatchException - Matrices must have same dimensions ("
            << rowsA << "x" << colsA << " vs " << rowsB << "x" << colsB << ")!";
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<T>(c)) {}

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row)
                std::cout << elem << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        // Just for demonstration
        A.set(0, 0, 1); A.set(0, 1, 2); A.set(1, 0, 3); A.set(1, 1, 4);
        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;  // This will throw
        C.print();
    } catch (const DimensionMismatchException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
