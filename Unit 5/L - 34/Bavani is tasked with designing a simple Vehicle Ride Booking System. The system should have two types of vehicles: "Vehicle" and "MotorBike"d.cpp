








#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual void move(string str) { 
        cout << str << endl; 
    }
};

class MotorBike : public Vehicle {
public:
    void move(string str) override { 
        cout << str << endl; 
    }
};

int main() {
    string str1, str2;
    getline(cin, str1);  
    getline(cin, str2);  

    Vehicle* v = new Vehicle();
    MotorBike* m = new MotorBike();

    v->move(str1); 
    m->move(str2); 

    delete v;
    delete m;

    return 0;
}
