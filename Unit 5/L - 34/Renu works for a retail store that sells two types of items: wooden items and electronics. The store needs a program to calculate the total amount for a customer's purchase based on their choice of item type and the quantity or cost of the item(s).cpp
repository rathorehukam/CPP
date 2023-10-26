






#include <iostream>
#include <iomanip>

using namespace std;

class ItemType {
public:
    virtual double calculateAmount() = 0;  
};

class Wooden : public ItemType {
private:
    int numberOfItems;
    double cost;
public:
    Wooden(int n, double c) : numberOfItems(n), cost(c) {}
    
    double calculateAmount() override {
        return numberOfItems * cost;
    }
};

class Electronics : public ItemType {
private:
    double cost;
public:
    Electronics(double c) : cost(c) {}
    
    double calculateAmount() override {
        return cost * 0.8; 
    }
};

int main() {
    int choice;
    cin >> choice;
    double amount;

    if (choice == 1) {
        int numberOfItems;
        double cost;
        cin >> numberOfItems >> cost;

        Wooden w(numberOfItems, cost);
        amount = w.calculateAmount();
    } else if (choice == 2) {
        double cost;
        cin >> cost;

        Electronics e(cost);
        amount = e.calculateAmount();
    }

    cout << fixed << setprecision(2) << amount << endl;

    return 0;
}
