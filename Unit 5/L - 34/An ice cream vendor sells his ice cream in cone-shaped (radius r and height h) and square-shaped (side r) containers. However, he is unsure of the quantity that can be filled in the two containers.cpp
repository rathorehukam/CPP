










#include <iostream>
#include <cmath>
#include <iomanip>

class Icecream {
public:
    static double Quantity(int r) {
        return r * r * r;
    }
    
    static double Quantity(int r, int h) {
        return 0.33 * M_PI * r * r * h;
    }
};

int main() {
    int choice, r, h;
        std::cin >> choice;
    
    if (choice == 1) { 
        std::cin >> r;
        std::cout << std::fixed << std::setprecision(2) << Icecream::Quantity(r) << std::endl;
    } else if (choice == 2) {  
        std::cin >> r >> h;
        std::cout << std::fixed << std::setprecision(2) << Icecream::Quantity(r, h) << std::endl;
    }

    return 0;
}
