





#include <iostream>
#include <iomanip>

class currentBill {
protected:
    float watts;
    float hours;
public:
    currentBill(float w, float h) : watts(w), hours(h) {}
    virtual float billAmount() = 0;
};

class Fan : public currentBill {
public:
    Fan(float w, float h) : currentBill(w, h) {}
    float billAmount() override {
        return (watts * hours / 1000) * 1.5;
    }
};

class Light : public currentBill {
public:
    Light(float w, float h) : currentBill(w, h) {}
    float billAmount() override {
        return (watts * hours / 1000) * 1.5;
    }
};

class TV : public currentBill {
public:
    TV(float w, float h) : currentBill(w, h) {}
    float billAmount() override {
        return (watts * hours / 1000) * 1.5;
    }
};

int main() {
    float w, h;
    float totalBill = 0.0;
    
    std::cin >> w >> h;
    Fan fan(w, h);
    totalBill += fan.billAmount();

    std::cin >> w >> h;
    Light light(w, h);
    totalBill += light.billAmount();

    std::cin >> w >> h;
    TV tv(w, h);
    totalBill += tv.billAmount();
    
    std::cout << std::fixed << std::setprecision(2) << totalBill << std::endl;
    return 0;
}
