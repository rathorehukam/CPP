












#include <iostream>
#include <vector>

class Shop {
protected:
    std::vector<std::pair<int, int>> items;
public:
    virtual void setPrice(int id, int price) = 0;
};

class ConcreteShop : public Shop {
public:
    void setPrice(int id, int price) override {
        for (auto& item : items) {
            if (item.first == id) {
                item.second = price;  
                return;
            }
        }
        items.push_back({id, price});
    }

    void displayPrices() const {
        for (const auto& item : items) {
            std::cout << "The Price of item with Id " << item.first << " is " << item.second << std::endl;
        }
    }
};

int main() {
    int n, id, price;
    ConcreteShop dukaan;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> id >> price;
        dukaan.setPrice(id, price);
    }

    dukaan.displayPrices();

    return 0;
}
