





#include <iostream>
#include <iomanip> 

using namespace std;

int calc(int a) {
    return a * a;
}

int calc(int a, int b) {
    return a % b;
}

float calc(float a, float b) {
    return a / b;
}

int main() {
    int num1, num2;
    float fnum1, fnum2;
    cin >> num1 >> num2 >> fnum1 >> fnum2;

    cout << "Square of " << num1 << ": " << calc(num1) << endl;
    cout << "Modulus of " << num1 << ", " << num2 << ": " << calc(num1, num2) << endl;
    
  
    cout << "Quotient of " << fnum1 << ", " << fnum2 << ": " 
         << fixed << setprecision(2) << calc(fnum1, fnum2) << endl;

    return 0;
}
