






#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    string productName;
    float productPrice;
    vector<Product*> relatedProducts;

public:
    Product(string name, float price) : productName(name), productPrice(price) {}

    void addRelatedProduct(Product* product) {
        relatedProducts.push_back(product);
    }

    void displayRelatedProducts() {
        cout << "Products frequently bought together with " << productName << ":" << endl;
        if(relatedProducts.empty()) {
            cout << endl; 
            return;
        }
        for(auto& product: relatedProducts) {
            cout << "- " << product->getName() << endl;
        }
    }

    string getName() const {
        return productName;
    }

    float getPrice() const {
        return productPrice;
    }
};

int main() {
    int numProducts;
    cin >> numProducts;

    vector<Product*> mainProducts;
    vector<Product*> allProducts;

    for(int i = 0; i < numProducts; i++) {
        string name;
        float price;
        cin >> ws; 
        getline(cin, name);
        cin >> price;

        Product* product = new Product(name, price);
        mainProducts.push_back(product);
        allProducts.push_back(product);

        char choice;
        cin >> choice;
        while(choice == 'y') {
            string relatedName;
            float relatedPrice;
            cin >> ws;
            getline(cin, relatedName);
            cin >> relatedPrice;

            Product* relatedProduct = new Product(relatedName, relatedPrice);
            allProducts.push_back(relatedProduct);
            product->addRelatedProduct(relatedProduct);

            cin >> choice;
        }
    }

    for(auto& product: mainProducts) {
        product->displayRelatedProducts();
    }

    for(auto& product: allProducts) {
        delete product;
    }

    return 0;
}
