






#include <iostream>
#include <string>
using namespace std;

class DecimalToBinaryConverter {
public:
    string convertToBinary(int n) {
        if (n == 0) return "0";
        
        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n /= 2;
        }
        return binary;
    }
};

int main() {
    int n;
    cin >> n;

    DecimalToBinaryConverter converter;
    cout << converter.convertToBinary(n) << endl;

    return 0;
}
