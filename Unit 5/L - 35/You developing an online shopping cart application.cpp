





#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    float pricePerItem;
    int quantity;

public:
  
    Product(const std::string& name, float price, int qty) 
        : name(name), pricePerItem(price), quantity(qty) {}


    void addQuantity(int qty) {
        quantity += qty;
    }


    float calculateBill() {
        return pricePerItem * quantity;
    }


    void displayCart() {
        std::cout << "Product Name: " << name << std::endl;
        std::cout << "Price per item: $" << pricePerItem << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total Bill: $" << calculateBill() << std::endl;
    }
};

int main() {
    std::string productName;
    float price;
    int initialQuantity, addQty;

    std::getline(std::cin, productName);
    std::cin >> price;
    std::cin >> initialQuantity;
    std::cin >> addQty;

    Product cart(productName, price, initialQuantity);

    cart.addQuantity(addQty);
    cart.displayCart();

    return 0;
}
