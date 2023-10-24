





#include <iostream>
#include <vector>

class Device {
protected:
    int powerRating; 
    int hoursUsed; 
public:
    Device(int p, int h) : powerRating(p), hoursUsed(h) {}
    virtual ~Device() {}
    
    virtual int energyConsumption() const = 0;
    virtual void displayType() const = 0;
};

class Refrigerator : public Device {
public:
    Refrigerator(int p, int h) : Device(p, h) {}
    
    int energyConsumption() const override {
        return powerRating * hoursUsed;
    }

    void displayType() const override {
        std::cout << "Device Type: Refrigerator" << std::endl;
    }
};

class AirConditioner : public Device {
public:
    AirConditioner(int p, int h) : Device(p, h) {}

    int energyConsumption() const override {
        return powerRating * hoursUsed;
    }

    void displayType() const override {
        std::cout << "Device Type: Air Conditioner" << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Device*> devices;
    int totalEnergyConsumption = 0;

    for (int i = 0; i < n; i++) {
        int type, power, hours;
        std::cin >> type >> power >> hours;

        if (type == 1) {
            devices.push_back(new Refrigerator(power, hours));
        } else if (type == 2) {
            devices.push_back(new AirConditioner(power, hours));
        }
    }

    for (Device* device : devices) {
        device->displayType();
        totalEnergyConsumption += device->energyConsumption();
        delete device;
    }

    std::cout << "Total Energy Consumption: " << totalEnergyConsumption << " watt-hours" << std::endl;

    return 0;
}
