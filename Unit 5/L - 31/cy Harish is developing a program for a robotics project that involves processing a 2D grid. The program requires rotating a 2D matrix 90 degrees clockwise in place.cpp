





#include <iostream>

void displayMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void rotateMatrix(int** matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            std::swap(matrix[i][j], matrix[i][k]);
        }
    }
}


int main() {
    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Size of the matrix should be positive!" << std::endl;
        return 0;
    }
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    displayMatrix(matrix, n);

    rotateMatrix(matrix, n);
    std::cout << "Matrix after 90-degree clockwise rotation:" << std::endl;
    displayMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
