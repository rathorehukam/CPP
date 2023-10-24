




#include <iostream>

class PermutationsAndCombinations {
private:
    int n, r;

    long long factorial(int num) {
        if (num > 10) return -1;
        if (num == 0) return 1;
        return num * factorial(num - 1);
    }

public:
 
    PermutationsAndCombinations(int n, int r): n(n), r(r) {}

    void display() {
        if (n < r || n < 0 || r < 0) {
            std::cout << "Invalid input" << std::endl;
            return;
        }
        
        long long nFactorial = factorial(n);
        if (nFactorial == -1) {
            std::cout << "Invalid input" << std::endl;
            return;
        }
        
        long long rFactorial = factorial(r);
        long long nMinusRFactorial = factorial(n - r);
        
        if (rFactorial == -1 || nMinusRFactorial == -1) {
            std::cout << "Invalid input" << std::endl;
            return;
        }

        long long permutations = nFactorial / nMinusRFactorial;
        long long combinations = nFactorial / (rFactorial * nMinusRFactorial);

        std::cout << "Permutations (nPr): " << permutations << std::endl;
        std::cout << "Combinations (nCr): " << combinations << std::endl;
    }
};

int main() {
    int n, r;
    std::cin >> n >> r;

    PermutationsAndCombinations* pac = new PermutationsAndCombinations(n, r);
    pac->display();
    delete pac;

    return 0;
}
