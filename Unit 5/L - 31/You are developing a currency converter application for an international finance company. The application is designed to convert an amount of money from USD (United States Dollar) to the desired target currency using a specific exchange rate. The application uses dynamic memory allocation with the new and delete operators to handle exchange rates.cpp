







#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double* exchangeRate = new double;
    double* amountUSD = new double;

    cin >> *exchangeRate;
    cin >> *amountUSD;
    double convertedAmount = (*amountUSD) * (*exchangeRate);

    cout << fixed << setprecision(2) << convertedAmount << endl;

    delete exchangeRate;
    delete amountUSD;

    return 0;
}
