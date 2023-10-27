




#include <iostream>
#include <iomanip>
#include <cmath>

class CoffeeShop {
public:
    virtual float calculateTotal() = 0;
    virtual ~CoffeeShop() {}
};

class CustomerOrder : public CoffeeShop {
private:
    float coffeePrice, teaPrice, pastryPrice;
    int coffeeQuantity, teaQuantity, pastryQuantity;

public:
    CustomerOrder(float cPrice, int cQuantity, float tPrice, int tQuantity, float pPrice, int pQuantity) 
    : coffeePrice(cPrice), teaPrice(tPrice), pastryPrice(pPrice), coffeeQuantity(cQuantity), teaQuantity(tQuantity), pastryQuantity(pQuantity) {}

    float calculateTotal() override {
        return (coffeePrice * coffeeQuantity) + (teaPrice * teaQuantity) + (pastryPrice * pastryQuantity);
    }
};

int main() {
    float coffeePrice, teaPrice, pastryPrice;
    int coffeeQuantity, teaQuantity, pastryQuantity;

    std::cin >> coffeePrice >> coffeeQuantity;
    std::cin >> teaPrice >> teaQuantity;
    std::cin >> pastryPrice >> pastryQuantity;

    CoffeeShop* order = new CustomerOrder(coffeePrice, coffeeQuantity, teaPrice, teaQuantity, pastryPrice, pastryQuantity);
    
    float totalCost = order->calculateTotal();
    
    if (totalCost == static_cast<int>(totalCost)) {
        std::cout << "Total cost of the order is $" << static_cast<int>(totalCost);
    } else if (static_cast<int>(totalCost * 100) % 10 == 0) {
        std::cout << "Total cost of the order is $" << static_cast<int>(totalCost) << "." << static_cast<int>(totalCost * 10) % 10;
    } else {
        std::cout << "Total cost of the order is $" << static_cast<int>(totalCost) << "." << static_cast<int>(totalCost * 10) % 10 << static_cast<int>(totalCost * 100) % 10;
    }

    std::cout << std::endl;
    delete order;
    return 0;
}
