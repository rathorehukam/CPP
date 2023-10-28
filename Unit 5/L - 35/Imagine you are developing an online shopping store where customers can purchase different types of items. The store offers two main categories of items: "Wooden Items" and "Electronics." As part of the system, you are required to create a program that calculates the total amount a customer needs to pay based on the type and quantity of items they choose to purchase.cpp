








#include <iostream>
#include <iomanip>

class ItemType {
public:
    virtual double calculateAmount() const = 0; // Pure virtual function
};

class Wooden : public ItemType {
private:
    int noOfItems;
    double cost;

public:
    Wooden(int items, double itemCost) : noOfItems(items), cost(itemCost) {}

    double calculateAmount() const override {
        return noOfItems * cost;
    }
};

class Electronics : public ItemType {
private:
    double cost;

public:
    Electronics(double itemCost) : cost(itemCost) {}

    double calculateAmount() const override {
        return cost * 0.8; // 20% discount
    }
};

int main() {
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        int items;
        double itemCost;
        std::cin >> items >> itemCost;
        Wooden wooden(items, itemCost);
        std::cout << std::fixed << std::setprecision(2) << wooden.calculateAmount() << std::endl;
    } else if (choice == 2) {
        double itemCost;
        std::cin >> itemCost;
        Electronics electronics(itemCost);
        std::cout << std::fixed << std::setprecision(2) << electronics.calculateAmount() << std::endl;
    }

    return 0;
}
