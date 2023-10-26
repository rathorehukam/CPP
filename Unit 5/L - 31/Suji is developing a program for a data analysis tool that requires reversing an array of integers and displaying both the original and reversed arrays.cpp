







#include <iostream>
using namespace std;

int* reverseArray(int* arr, int size) {
    int* reversedArr = new int[size];
    for(int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - i - 1];
    }
    return reversedArr;
}

int main() {
    int size;
    cin >> size;
    
    if(size < 0) {
        cout << "Size of the array should be positive!" << endl;
        return 0;
    }
    
    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int* reversedArr = reverseArray(arr, size);

    cout << "Original Array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Reversed Array: ";
    for(int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] reversedArr;

    return 0;
}
