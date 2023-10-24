







#include <iostream>
#include <iomanip>

class Investment {
protected:
    double initialInvestment;
    double finalValue;

public:
    Investment(double initial, double finalVal) : initialInvestment(initial), finalValue(finalVal) {}
    virtual double calculateReturns() = 0;
    virtual void displayType() = 0;
};

class Stock : public Investment {
public:
    Stock(double initial, double finalVal) : Investment(initial, finalVal) {}

    double calculateReturns() override {
        return ((finalValue - initialInvestment) / initialInvestment) * 100;
    }

    void displayType() override {
        std::cout << "Type: Stock" << std::endl;
    }
};

class Bond : public Investment {
public:
    Bond(double initial, double finalVal) : Investment(initial, finalVal) {}

    double calculateReturns() override {
        return ((finalValue - initialInvestment) / initialInvestment) * 100;
    }

    void displayType() override {
        std::cout << "Type: Bond" << std::endl;
    }
};

int main() {
    double initialStock, finalStock, initialBond, finalBond;

    std::cin >> initialStock >> finalStock >> initialBond >> finalBond;

    Stock stockInvestment(initialStock, finalStock);
    Bond bondInvestment(initialBond, finalBond);

    // Display Stock
    stockInvestment.displayType();
    std::cout << std::fixed << std::setprecision(2) << "Initial Investment: " << initialStock << std::endl;
    std::cout << "Final Value: " << finalStock << std::endl;
    std::cout << "Returns: " << stockInvestment.calculateReturns() << "%" << std::endl << std::endl;

    // Display Bond
    bondInvestment.displayType();
    std::cout << "Initial Investment: " << initialBond << std::endl;
    std::cout << "Final Value: " << finalBond << std::endl;
    std::cout << "Returns: " << bondInvestment.calculateReturns() << "%" << std::endl;

    return 0;
}
