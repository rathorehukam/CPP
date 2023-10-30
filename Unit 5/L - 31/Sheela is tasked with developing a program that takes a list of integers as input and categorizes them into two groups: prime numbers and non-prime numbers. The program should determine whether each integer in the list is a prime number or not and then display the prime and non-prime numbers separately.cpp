












#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    int* numbers = new int[N];
    int* primes = new int[N];
    int* nonPrimes = new int[N];
    int primeCount = 0;
    int nonPrimeCount = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
        if (isPrime(numbers[i])) {
            primes[primeCount] = numbers[i];
            primeCount++;
        } else {
            nonPrimes[nonPrimeCount] = numbers[i];
            nonPrimeCount++;
        }
    }

    // Display the prime numbers
    if (primeCount > 0) {
        std::cout << "Prime numbers: ";
        for (int i = 0; i < primeCount; i++) {
            std::cout << primes[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No prime numbers found." << std::endl;
    }

    // Display the non-prime numbers
    if (nonPrimeCount > 0) {
        std::cout << "Non-prime numbers: ";
        for (int i = 0; i < nonPrimeCount; i++) {
            std::cout << nonPrimes[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No non-prime numbers found.";
    }

    // Deallocate memory for the arrays
    delete[] numbers;
    delete[] primes;
    delete[] nonPrimes;

    return 0;
}
