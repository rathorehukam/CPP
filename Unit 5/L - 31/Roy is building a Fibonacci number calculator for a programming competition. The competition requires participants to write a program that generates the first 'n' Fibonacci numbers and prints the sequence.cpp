








#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << "Number of Fibonacci numbers should be positive!" << endl;
        return 0;
    }

    long long *fib = new long long[n];

    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << fib[i] << " ";
    }
    delete[] fib;
    return 0;
}
