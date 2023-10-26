













#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    virtual string getTaste() const = 0;  
};

class Apple : public Fruit {
public:
    string getTaste() const override {
        return "Sweet";
    }
};

class Banana : public Fruit {
public:
    string getTaste() const override {
        return "Creamy";
    }
};

class Orange : public Fruit {
public:
    string getTaste() const override {
        return "Tangy";
    }
};

class Grape : public Fruit {
public:
    string getTaste() const override {
        return "Juicy";
    }
};

class Pineapple : public Fruit {
public:
    string getTaste() const override {
        return "Sweet and Sour";
    }
};

int main() {
    int choice;
    cin >> choice;

    Fruit* selectedFruit = nullptr;
    bool valid = true;

    switch (choice) {
        case 1:
            selectedFruit = new Apple();
            break;
        case 2:
            selectedFruit = new Banana();
            break;
        case 3:
            selectedFruit = new Orange();
            break;
        case 4:
            selectedFruit = new Grape();
            break;
        case 5:
            selectedFruit = new Pineapple();
            break;
        default:
            cout << "Invalid choice, defaulting to generic fruit." << endl;
            valid = false;
            break;
    }

    if (valid) {
        cout << "The taste of the fruit is: " << selectedFruit->getTaste() << endl;
        delete selectedFruit;
    } else {
        cout << "The taste of the fruit is: Generic fruit taste" << endl;
    }

    return 0;
}
