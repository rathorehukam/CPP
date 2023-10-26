



#include <iostream>
using namespace std;

void readMatrix(int**& matrix, int rows, int cols) {
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void readMatrix(double**& matrix, int rows, int cols) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
bool isIdentity(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            } else if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    int** matrix = nullptr;
    readMatrix(matrix, rows, cols);
    
    if (isIdentity(matrix, rows, cols)) {
        cout << "Identity matrix" << endl;
    } else {
        cout << "Not an identity matrix" << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
