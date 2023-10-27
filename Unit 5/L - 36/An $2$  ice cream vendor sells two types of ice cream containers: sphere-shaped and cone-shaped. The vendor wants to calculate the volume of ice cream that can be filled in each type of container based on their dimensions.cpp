





#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Icecream {
public:
    virtual double Quantity(int r) {
        return (4.0/3) * M_PI * r * r * r;
    }

    virtual double Quantity(int r, int h) {
        return (M_PI * r * r * h) / 3.0;
    }
};

int main() {
    int choice, r, h;
    cin >> choice;

    Icecream container;
    double volume = 0.0;

    if (choice == 1) {
        cin >> r;
        volume = container.Quantity(r);
    } else if (choice == 2) {
        cin >> r >> h;
        volume = container.Quantity(r, h);
    }

    if (volume != 0.0) {
        cout << fixed << setprecision(2) << volume << endl;
    }

    return 0;
}
