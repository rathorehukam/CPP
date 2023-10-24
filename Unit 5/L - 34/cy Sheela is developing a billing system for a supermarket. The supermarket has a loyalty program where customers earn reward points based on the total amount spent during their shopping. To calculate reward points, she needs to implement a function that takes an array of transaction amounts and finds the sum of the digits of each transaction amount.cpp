








#include <iostream>

class SummationCalculator {
public:
    virtual int sum(int a[], int n) = 0;
};

class SimpleSummationCalculator : public SummationCalculator {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        while (sum >= 10) {
            sum = sumOfDigits(sum);
        }
        return sum;
    }

    int sum(int a[], int n) override {
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += sumOfDigits(a[i]);
        }
        return sumOfDigits(totalSum);
    }
};

int main() {
    SimpleSummationCalculator calc;
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << calc.sum(a, n) << std::endl;
    return 0;
}
