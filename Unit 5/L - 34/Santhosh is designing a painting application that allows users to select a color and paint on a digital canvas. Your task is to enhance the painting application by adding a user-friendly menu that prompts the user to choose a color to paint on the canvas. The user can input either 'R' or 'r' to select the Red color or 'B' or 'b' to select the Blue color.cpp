







#include <iostream>
using namespace std;

class Color {
public:
    virtual void paint() = 0; 
};

class RedPaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Red color." << endl;
    }
};

class BluePaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Blue color." << endl;
    }
};

int main() {
    char choice;
    cin >> choice;

    Color* colorObj = nullptr; 

    switch(choice) {
        case 'R':
        case 'r':
            colorObj = new RedPaint();
            break;
        case 'B':
        case 'b':
            colorObj = new BluePaint();
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    colorObj->paint(); 

    delete colorObj; 

    return 0;
}
