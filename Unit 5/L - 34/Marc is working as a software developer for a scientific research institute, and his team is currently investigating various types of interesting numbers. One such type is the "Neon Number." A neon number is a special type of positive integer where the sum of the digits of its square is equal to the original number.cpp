









#include <iostream>
using namespace std;

class Number {
public:
    virtual ~Number() {}
};

class NeonNumber : public Number {
private:
    int num;

public:
    NeonNumber(int n) : num(n) {}

    bool isNeon() {
        int square = num * num;
        int sum = 0;

        while (square) {
            sum += square % 10;
            square /= 10;
        }

        return sum == num;
    }
};

int main() {
    int n;
    cin >> n;

    if (n < 0 || n >= 20) {
        cout << "Enter a valid number." << endl;
        return 0;
    }

    NeonNumber neon(n);

    if (neon.isNeon()) {
        cout << n << "  it's a Neon Number." << endl;
    } else {
        cout << n << " it's Not a Neon Number." << endl;
    }

    return 0;
}
