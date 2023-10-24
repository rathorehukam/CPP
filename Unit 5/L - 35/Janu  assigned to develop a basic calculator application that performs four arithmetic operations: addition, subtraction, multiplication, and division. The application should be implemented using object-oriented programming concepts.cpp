






#include <iostream>

class operationsBase {
public:
    virtual int addition() = 0;
    virtual int subtraction() = 0;
    virtual int multiplication() = 0;
    virtual void division() = 0;
};

class operationsDerived : public operationsBase {
private:
    int a, b;

public:
    operationsDerived(int x, int y) : a(x), b(y) {}

    int addition() override {
        return a + b;
    }

    int subtraction() override {
        return a - b;
    }

    int multiplication() override {
        return a * b;
    }

    void division() override {
        if (b != 0) {
            std::cout << a / b << " ";
        } else {
            std::cout << std::endl << "Division by 0 is not allowed." << std::endl;
        }
    }
};

int main() {
    int x, y;
    std::cin >> x >> y;

    operationsDerived calc(x, y);

    std::cout << calc.addition() << " ";
    std::cout << calc.subtraction() << " ";
    std::cout << calc.multiplication() << " ";
    calc.division();

    return 0;
}
