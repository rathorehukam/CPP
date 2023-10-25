





#include <iostream>
using namespace std;

int main() {
    int n, evenCount = 0, oddCount = 0;
    cin >> n;
    
    if(n < 1) {
        cout << "Number of integers should be positive!";
        return 0;
    }
    
    int* arr = new int[n];
    int* even = new int[n];
    int* odd = new int[n];
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }
    
    cout << "List of Odd Integers: ";
    for(int i=0; i<oddCount; i++) {
        cout << odd[i] << " ";
    }
    cout << endl;
    
    cout << "List of Even Integers: ";
    for(int i=0; i<evenCount; i++) {
        cout << even[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    delete[] even;
    delete[] odd;
    
    return 0;
}
