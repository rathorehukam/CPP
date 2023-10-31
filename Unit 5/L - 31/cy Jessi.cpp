






#include <iostream>

using namespace std;

bool isPrime(int num) {

if (num <= 1)

return false;




for (int i = 2; i * i <= num; i++) {

if (num % i == 0)

return false;

}




return true;

}




int main() {

int n;

cin >> n;

int* primeFactors = new int[n];

int numFactors = 0;




for (int i = 2; i <= n; i++) {

if (n % i == 0 && isPrime(i)) {

primeFactors[numFactors] = i;

numFactors++;

}

}







if (numFactors == 0) {

cout << "No prime factors found for " << n;

} else {

int largestPrimeFactor = primeFactors[numFactors - 1];







cout << "Prime factors of " << n << " are: ";

for (int i = 0; i < numFactors; i++) {

cout << primeFactors[i] << " ";

}







cout << "\nLargest prime factor of " << n << " is: " << largestPrimeFactor;

}

delete[] primeFactors;

return 0;

} 


