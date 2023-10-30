













#include <iostream>
#include <unordered_set>
using namespace std;

void findPairsWithSum(int* arr, int size, int targetSum) {
    unordered_set<int> seenElements;
    bool foundPair = false;

    for (int i = 0; i < size; ++i) {
        int complement = targetSum - arr[i];
        if (seenElements.find(complement) != seenElements.end()) {
            cout << "Pair found: (" << arr[i] << ", " << complement << ")" << endl;
            foundPair = true;
        }
        seenElements.insert(arr[i]);
    }

    if (!foundPair) {
        cout << "No pair" << endl;
    }
}

int main() {
    int size;
    cin >> size;

    if (size <= 0) {
        cout << "Size of the array should be positive!";
        return 0;
    }

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int targetSum;
    cin >> targetSum;
    cout << "Pairs with the sum " << targetSum << " are:" << endl;
    findPairsWithSum(arr, size, targetSum);
    delete[] arr;
    return 0;
}

