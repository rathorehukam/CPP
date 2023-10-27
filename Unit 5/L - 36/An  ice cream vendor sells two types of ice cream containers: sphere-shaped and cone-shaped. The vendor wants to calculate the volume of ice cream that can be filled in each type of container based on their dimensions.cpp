









#include <iostream>
#include <iomanip>

class Icecream {
public:
    virtual double Quantity() const = 0;  
    virtual ~Icecream() {}  
};

class Sphere : public Icecream {
public:
    Sphere(double r) : radius(r) {}
    
    double Quantity() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;  
    }

private:
    double radius;
};

class Cone : public Icecream {
public:
    Cone(double r, double h) : radius(r), height(h) {}

    double Quantity() const override {
        return 0.33 * 3.141592653589793 * radius * radius * height;  
    }

private:
    double radius, height;
};

int main() {
    int choice;
    std::cin >> choice;

    Icecream* icecream = nullptr;
    if (choice == 1) {
        double radius;
        std::cin >> radius;
        icecream = new Sphere(radius);
    } else if (choice == 2) {
        double radius, height;
        std::cin >> radius >> height;
        icecream = new Cone(radius, height);
    }

    if (icecream) {
        std::cout << std::fixed << std::setprecision(2) << icecream->Quantity() << std::endl;
        delete icecream;  
    }

    return 0;
}
