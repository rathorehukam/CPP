#include <iostream>
#include <map>
using namespace std;

// Base class
class Shop {
protected:
    map<int, int> inventory; // Using a map to store item IDs and their corresponding prices
public:
    virtual void setPrice(int id, int price) = 0; // pure virtual function
};

// Derived class
class ConcreteShop : public Shop {
public:
    void setPrice(int id, int price) override {
        inventory[id] = price; // Adds a new item or updates the price if the item already exists
    }

    int getPrice(int id) {
        return inventory[id]; // Returns the price of the item with the given ID
    }

    // Method to display the items
    void displayItems() {
        for(const auto& item : inventory) {
            cout << "The Price of item with Id " << item.first << " is " << item.second << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    ConcreteShop dukaan;

    for(int i = 0; i < n; i++) {
        int id, price;
        cin >> id >> price;
        dukaan.setPrice(id, price);
    }

    dukaan.displayItems();  // Using the method to display the items

    return 0;
}
