#include <iostream>

class Vehicle {
protected:
    int numOfWheels;
    float maxSpeed;
public:
    Vehicle(): numOfWheels(0), maxSpeed(0.0) {}

    virtual void setNumOfWheels(int wheels) {
        numOfWheels = wheels;
    }

    virtual void setMaxSpeed(float speed) {
        maxSpeed = speed;
    }

    virtual int getNumOfWheels() const {
        return numOfWheels;
    }

    virtual float getMaxSpeed() const {
        return maxSpeed;
    }

    virtual float timeToTravel(float distance) const {
        return distance / maxSpeed;
    }
};

class Car: public Vehicle {};

class Bicycle: public Vehicle {};

class Boat: public Vehicle {
public:
    void setMaxSpeed(float speedInKnots) override {
        maxSpeed = speedInKnots * 1.151;
    }

    float getMaxSpeed() const override {
        return maxSpeed / 1.151;
    }

    int getNumOfWheels() const override {
        return 0; // Boats don't have wheels
    }
};

int main() {
    Car car;
    Bicycle bicycle;
    Boat boat;

    float wheels, speed, distance;

    std::cin >> wheels >> speed;
    car.setNumOfWheels(static_cast<int>(wheels));
    car.setMaxSpeed(speed);

    std::cin >> wheels >> speed;
    bicycle.setNumOfWheels(static_cast<int>(wheels));
    bicycle.setMaxSpeed(speed);

    std::cin >> speed;
    boat.setMaxSpeed(speed);

    std::cin >> distance;

    std::cout << "Vehicle Details:" << std::endl;
    std::cout << "Car has " << car.getNumOfWheels() << " wheels and can go up to " << car.getMaxSpeed() << " mph. It would take " << car.timeToTravel(distance) << " hours to travel " << distance << " miles at maximum speed." << std::endl;
    std::cout << "Bicycle has " << bicycle.getNumOfWheels() << " wheels and can go up to " << bicycle.getMaxSpeed() << " mph. It would take " << bicycle.timeToTravel(distance) << " hours to travel " << distance << " miles at maximum speed." << std::endl;
    std::cout << "Boat has " << boat.getNumOfWheels() << " wheels and can go up to " << boat.getMaxSpeed() << " knots. It would take " << boat.timeToTravel(distance) << " hours to travel " << distance << " miles at maximum speed." << std::endl;

    return 0;
}
