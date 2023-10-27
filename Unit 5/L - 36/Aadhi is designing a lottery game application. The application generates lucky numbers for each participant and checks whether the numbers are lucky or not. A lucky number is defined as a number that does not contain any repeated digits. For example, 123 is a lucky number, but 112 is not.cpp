






#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class LuckyChecker {
private:
    vector<int> numbers;
    unordered_set<int> usedDigits;

public:
    LuckyChecker(int n, int* lotteryNumbers) {
        for (int i = 0; i < n; i++) {
            numbers.push_back(lotteryNumbers[i]);
        }
    }

    bool isLucky(int num) {
        usedDigits.clear();

        while (num > 0) {
            int digit = num % 10;

            if (usedDigits.find(digit) != usedDigits.end()) {
                return false; 
            }

            usedDigits.insert(digit);
            num /= 10;
        }

        return true; 
    }
};

int main() {
    int n;
    cin >> n;

    int* lotteryNumbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> lotteryNumbers[i];
    }

    LuckyChecker luckyChecker(n, lotteryNumbers);

    for (int i = 0; i < n; i++) {
        if (luckyChecker.isLucky(lotteryNumbers[i])) {
            cout << lotteryNumbers[i] << " is Lucky" << endl;
        } else {
            cout << lotteryNumbers[i] << " is not Lucky" << endl;
        }
    }

    delete[] lotteryNumbers;

    return 0;
}
