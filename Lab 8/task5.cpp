#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value);
};

class Matrix2x2 {
private:
    int elements[2][2];
public:
    Matrix2x2(int a11 = 0, int a12 = 0, int a21 = 0, int a22 = 0) {
        elements[0][0] = a11;
        elements[0][1] = a12;
        elements[1][0] = a21;
        elements[1][1] = a22;
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }

    friend int determinant(const Matrix2x2& m);
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);
    friend class MatrixHelper;
};

void MatrixHelper::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2) {
        matrix.elements[row][col] = value;
    }
}

int determinant(const Matrix2x2& m) {
    return m.elements[0][0] * m.elements[1][1] - m.elements[0][1] * m.elements[1][0];
}

ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << m.elements[0][0] << " " << m.elements[0][1] << endl;
    os << m.elements[1][0] << " " << m.elements[1][1];
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    cout << "Sum:\n" << sum << endl;

    Matrix2x2 diff = m1 - m2;
    cout << "Difference:\n" << diff << endl;

    Matrix2x2 prod = m1 * m2;
    cout << "Product:\n" << prod << endl;

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 9);
    cout << "Updated Matrix 1:\n" << m1 << endl;

    return 0;
}
