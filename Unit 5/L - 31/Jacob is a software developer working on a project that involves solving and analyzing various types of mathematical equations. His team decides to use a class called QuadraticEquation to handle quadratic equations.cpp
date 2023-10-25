




#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
private:
    float a, b, c;
    
public:
    QuadraticEquation(float a, float b, float c) : a(a), b(b), c(c) {}

    void solveAndDisplayRoots() {
        float discriminant = b*b - 4*a*c;

        if (discriminant > 0) {
            float root1 = (-b + sqrt(discriminant)) / (2*a);
            float root2 = (-b - sqrt(discriminant)) / (2*a);
            cout << "Root 1: " << root1 << endl;
            cout << "Root 2: " << root2 << endl;
        } else if (discriminant == 0) {
            float root = -b / (2*a);
            cout << "Root: " << root << endl;
        } else {
            float realPart = -b / (2*a);
            float imaginaryPart = sqrt(-discriminant) / (2*a);
            cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    
    QuadraticEquation equation(a, b, c);
    equation.solveAndDisplayRoots();
    
    return 0;
}
