




#include <iostream>
#include <iomanip>

using namespace std;
class Product {
public:
    virtual double calculateTotalPrice() = 0; 
};

class Electronics : public Product {
    double price;
    double discount;
public:
    Electronics(double p, double d) : price(p), discount(d) {}
    
    double calculateTotalPrice() {
        return price - (price * (discount / 100.0));
    }
};

class Apparel : public Product {
    double price;
    double tax;
public:
    Apparel(double p, double t) : price(p), tax(t) {}
    
    double calculateTotalPrice() {
        return price + (price * (tax / 100.0));
    }
};

int main() {
    double ePrice, eDiscount, aPrice, aTax;

    cin >> ePrice >> eDiscount >> aPrice >> aTax;

    Electronics electronic(ePrice, eDiscount);
    Apparel apparel(aPrice, aTax);

    cout << fixed << setprecision(2) << electronic.calculateTotalPrice() << endl;
    cout << fixed << setprecision(2) << apparel.calculateTotalPrice() << endl;

    return 0;
}
