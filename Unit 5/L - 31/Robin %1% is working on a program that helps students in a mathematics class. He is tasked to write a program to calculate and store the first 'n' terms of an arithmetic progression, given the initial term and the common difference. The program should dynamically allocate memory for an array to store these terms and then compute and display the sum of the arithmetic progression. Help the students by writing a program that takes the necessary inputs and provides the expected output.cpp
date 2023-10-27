







#include <iostream>
using namespace std;

int main() {
    int n, initialTerm, commonDifference;
    cin >> n >> initialTerm >> commonDifference;

    long long* progression = new long long[n];
    progression[0] = initialTerm;

    for (int i = 1; i < n; i++) {
        progression[i] = progression[i - 1] + commonDifference; 
    }

    long long sum= 0;
    for (int i = 0; i < n; i++) {
        sum += progression[i]; 
    }

    cout << sum << endl;

    delete[] progression;

    return 0;
}
