#include <iostream>
using namespace std;

void findPairs(int arr[], int size, int targetSum) {
    bool isPairFound = false;

    // Start from the middle of the array for positive numbers
    int mid = (size % 2 == 0) ? (size / 2) - 1 : (size + 1) / 2 - 1;
    for (int i = mid; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == targetSum && arr[i] > 0 && arr[j] > 0) {
                if(!isPairFound) {
                    cout << "Pairs with the sum " << targetSum << " are:" << endl;
                    isPairFound = true;
                }
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }

    // Search for pairs where one number is positive and the other is negative
    for (int i = size - 1; i >= 0 && arr[i] > 0; i--) {
        for (int j = 0; j < size && arr[j] < 0; j++) {
            if (arr[i] + arr[j] == targetSum) {
                if(!isPairFound) {
                    cout << "Pairs with the sum " << targetSum << " are:" << endl;
                    isPairFound = true;
                }
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }

    if (!isPairFound) {
        cout << "Pairs with the sum " << targetSum << " are:" << endl;
        cout << "No pair" << endl;
    }
}

int main() {
    int size;
    cin >> size;

    if (size <= 0) {
        cout << "Size of the array should be positive!" << endl;
        return 0;
    }

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int targetSum;
    cin >> targetSum;

    findPairs(arr, size, targetSum);

    delete[] arr;

    return 0;
}
