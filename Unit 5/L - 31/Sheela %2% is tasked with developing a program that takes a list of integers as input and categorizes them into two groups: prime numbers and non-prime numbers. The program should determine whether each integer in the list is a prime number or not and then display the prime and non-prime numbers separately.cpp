








#include <iostream>
#include <cmath>
bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    std::cout << "Enter the number of integers: ";
    std::cin >> N;
    
    int* nums = new int[N];
    int* primeNums = new int[N];
    int* nonPrimeNums = new int[N];
    
    int primeCount = 0;
    int nonPrimeCount = 0;
    
    std::cout << "Enter the integers: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
        if (isPrime(nums[i])) {
            primeNums[primeCount++] = nums[i];
        } else {
            nonPrimeNums[nonPrimeCount++] = nums[i];
        }
    }
    
    if (primeCount > 0) {
        std::cout << "Prime numbers: ";
        for (int i = 0; i < primeCount; ++i) {
            std::cout << primeNums[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No prime numbers found." << std::endl;
    }
    
    std::cout << "Non-prime numbers: ";
    for (int i = 0; i < nonPrimeCount; ++i) {
        std::cout << nonPrimeNums[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] nums;
    delete[] primeNums;
    delete[] nonPrimeNums;
    
    return 0;
}
